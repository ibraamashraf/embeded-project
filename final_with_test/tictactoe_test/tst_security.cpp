#include <QtTest>
#include "../TicTacToe_design/security.h"

class SecurityTest : public QObject {
    Q_OBJECT

private slots:
    void test_same_password_gives_same_hash();
    void test_different_passwords_give_different_hashes();
    void test_hash_not_empty();
};

void SecurityTest::test_same_password_gives_same_hash() {
    QString password = "mypassword123";
    QString hash1 = Security::hashPassword(password);
    QString hash2 = Security::hashPassword(password);

    qDebug() << "Hash1:" << hash1;
    qDebug() << "Hash2:" << hash2;

    QCOMPARE(hash1, hash2);
    qDebug() << "✅ test_same_password_gives_same_hash passed!";
}

void SecurityTest::test_different_passwords_give_different_hashes() {
    QString hash1 = Security::hashPassword("password1");
    QString hash2 = Security::hashPassword("password2");

    QVERIFY(hash1 != hash2);
    qDebug() << "✅ test_different_passwords_give_different_hashes passed!";
}

void SecurityTest::test_hash_not_empty() {
    QString hash = Security::hashPassword("test");
    QVERIFY(!hash.isEmpty());
    qDebug() << "✅ test_hash_not_empty passed!";
}

#include "tst_security.moc"
