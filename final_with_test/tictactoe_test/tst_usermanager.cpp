#include <QtTest>
#include <QTemporaryFile>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "usermanager.h"


class UserManagerTest : public QObject {
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();

    void test_register_success();
    void test_register_duplicate();
    void test_login_success();
    void test_login_wrong_password();
    void test_login_nonexistent();
    void test_saveGame();
    void test_logout_and_getCurrentUser();
    void test_recordGameResult_fileCheck();
     void test_registration_and_login_end_to_end();

private:
    QString tempFilePath;
    UserManager* userManager = nullptr;
};

void UserManagerTest::initTestCase() {
    // Create temp file path
    QTemporaryFile tempFile;
    tempFile.setAutoRemove(false); // Don't remove immediately
    tempFile.open();
    tempFilePath = tempFile.fileName();
    tempFile.close();

    // Write empty JSON structure
    QFile file(tempFilePath);
    if (file.open(QIODevice::WriteOnly)) {
        QJsonObject root;
        root["users"] = QJsonArray();
        file.write(QJsonDocument(root).toJson());
        file.close();
    }

    // Create testable UserManager
    userManager = new UserManager(tempFilePath);
}

void UserManagerTest::cleanupTestCase() {
    delete userManager;
    QFile::remove(tempFilePath);
}

void UserManagerTest::test_register_success() {
    bool result = userManager->registerUser("test1", "1234");
    QVERIFY(result);
}

void UserManagerTest::test_register_duplicate() {
    userManager->registerUser("duplicate", "pass1");
    bool result = userManager->registerUser("duplicate", "pass2");
    QVERIFY(!result);
}

void UserManagerTest::test_login_success() {
    userManager->registerUser("loginuser", "mypass");
    bool result = userManager->loginUser("loginuser", "mypass");
    QVERIFY(result);
}

void UserManagerTest::test_login_wrong_password() {
    userManager->registerUser("wrongpassuser", "rightpass");
    bool result = userManager->loginUser("wrongpassuser", "wrongpass");
    QVERIFY(!result);
}

void UserManagerTest::test_login_nonexistent() {
    bool result = userManager->loginUser("ghost", "anything");
    QVERIFY(!result);
}

void UserManagerTest::test_saveGame() {
    qDebug() << "➡️  Starting test_saveGame()";

    QString username = "saveUser";
    QString password = "savePass";
    QVERIFY(userManager->registerUser(username, password));
    QVERIFY(userManager->loginUser(username, password));
    qDebug() << "   ✔️  Registered and logged in as" << username;

    // Prepare fake game data
    QJsonObject gameData;
    gameData["date"] = "2025-06-20";
    gameData["result"] = "win";
    gameData["opponent"] = "bot";

    // Save game
    QVERIFY(userManager->saveGame(gameData));
    qDebug() << "   ✔️  Game data saved using saveGame()";

    // 🧠 Read the JSON file back manually
    QFile file(tempFilePath);  // this is your test file
    QVERIFY(file.open(QIODevice::ReadOnly));
    QByteArray fileData = file.readAll();
    file.close();

    // Parse JSON
    QJsonDocument doc = QJsonDocument::fromJson(fileData);
    QVERIFY(doc.isObject());
    QJsonArray users = doc.object()["users"].toArray();

    // Find the user in the file
    QJsonObject foundUser;
    for (const QJsonValue &val : users) {
        QJsonObject obj = val.toObject();
        if (obj["username"].toString() == username) {
            foundUser = obj;
            break;
        }
    }

    QVERIFY(!foundUser.isEmpty());
    QJsonArray games = foundUser["games"].toArray();
    QVERIFY(games.size() > 0);

    QJsonObject savedGame = games.last().toObject();
    QCOMPARE(savedGame["date"].toString(), QString("2025-06-20"));
    QCOMPARE(savedGame["result"].toString(), QString("win"));
    QCOMPARE(savedGame["opponent"].toString(), QString("bot"));

    qDebug() << "   ✔️  Verified game is saved correctly in file";
    qDebug() << "✅ test_saveGame() passed with file validation!";
}



void UserManagerTest::test_logout_and_getCurrentUser() {
    qDebug() << "➡️  Starting test_logout_and_getCurrentUser()";

    QString username = "logoutUser";
    QString password = "logoutPass";
    QVERIFY(userManager->registerUser(username, password));
    QVERIFY(userManager->loginUser(username, password));
    qDebug() << "   ✔️  Logged in as" << userManager->getCurrentUser();

    QCOMPARE(userManager->getCurrentUser(), username);

    userManager->logout();
    QCOMPARE(userManager->getCurrentUser(), QString(""));

    qDebug() << "   ✔️  Logout successful and current user cleared";
    qDebug() << "✅ test_logout_and_getCurrentUser() passed!";
}
void UserManagerTest::test_recordGameResult_fileCheck() {
    qDebug() << "➡️  Starting test_recordGameResult_fileCheck()";

    QString username = "recordUser";
    QString password = "recordPass";
    QVERIFY(userManager->registerUser(username, password));
    QVERIFY(userManager->loginUser(username, password));
    qDebug() << "   ✔️  Registered and logged in as" << username;

    // Record 3 results
    QVERIFY(userManager->recordGameResult("win"));
    QVERIFY(userManager->recordGameResult("loss"));
    QVERIFY(userManager->recordGameResult("draw"));
    qDebug() << "   ✔️  Saved win, loss, draw";

    // 🔍 Open JSON file and verify saved results
    QFile file(tempFilePath);
    QVERIFY(file.open(QIODevice::ReadOnly));
    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QVERIFY(doc.isObject());
    QJsonArray users = doc.object()["users"].toArray();

    QJsonObject foundUser;
    for (const QJsonValue &val : users) {
        QJsonObject obj = val.toObject();
        if (obj["username"].toString() == username) {
            foundUser = obj;
            break;
        }
    }

    QVERIFY(!foundUser.isEmpty());
    QJsonArray history = foundUser["history"].toArray();
    QCOMPARE(history.size(), 3);
    QCOMPARE(history[0].toString(), QString("win"));
    QCOMPARE(history[1].toString(), QString("loss"));
    QCOMPARE(history[2].toString(), QString("draw"));

    qDebug() << "   ✔️  File contains correct history:" << history;
    qDebug() << "✅ test_recordGameResult_fileCheck() passed!";
}

void UserManagerTest::test_registration_and_login_end_to_end() {
    qDebug() << "➡️  Starting test_registration_and_login_end_to_end()";

    QString username = "endUser";
    QString correctPassword = "secure123";
    QString wrongPassword = "wrong456";

    // Step 1: Register user
    QVERIFY(userManager->registerUser(username, correctPassword));
    qDebug() << "   ✔️  Registered user:" << username;

    // Step 2: Try logging in with wrong password (should fail)
    QVERIFY(!userManager->loginUser(username, wrongPassword));
    qDebug() << "   ✔️  Login failed as expected with wrong password";

    // Step 3: Log in with correct password (should succeed)
    QVERIFY(userManager->loginUser(username, correctPassword));
    qDebug() << "   ✔️  Login succeeded with correct password";

    // Step 4: Verify current user is set correctly
    QCOMPARE(userManager->getCurrentUser(), username);
    qDebug() << "   ✔️  Current user is correct:" << userManager->getCurrentUser();

    qDebug() << "✅ test_registration_and_login_end_to_end passed!";
}


#include "tst_usermanager.moc"
