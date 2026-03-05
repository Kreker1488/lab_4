/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QPushButton *pushButton_back;
    QLineEdit *lineEdit_login;
    QLineEdit *lineEdit_password;
    QPushButton *pushButton_login;

    void setupUi(QWidget *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(400, 300);
        pushButton_back = new QPushButton(LoginWindow);
        pushButton_back->setObjectName("pushButton_back");
        pushButton_back->setGeometry(QRect(170, 260, 80, 24));
        lineEdit_login = new QLineEdit(LoginWindow);
        lineEdit_login->setObjectName("lineEdit_login");
        lineEdit_login->setGeometry(QRect(150, 60, 113, 24));
        lineEdit_password = new QLineEdit(LoginWindow);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setGeometry(QRect(150, 100, 113, 24));
        pushButton_login = new QPushButton(LoginWindow);
        pushButton_login->setObjectName("pushButton_login");
        pushButton_login->setGeometry(QRect(160, 140, 80, 24));

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QWidget *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Form", nullptr));
        pushButton_back->setText(QCoreApplication::translate("LoginWindow", "Back", nullptr));
        lineEdit_login->setText(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        lineEdit_password->setText(QCoreApplication::translate("LoginWindow", "Password", nullptr));
        pushButton_login->setText(QCoreApplication::translate("LoginWindow", "Log in", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
