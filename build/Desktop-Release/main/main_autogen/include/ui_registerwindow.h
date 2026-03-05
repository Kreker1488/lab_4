/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterWindow
{
public:
    QPushButton *pushButton_back;
    QPushButton *pushButton_register;
    QLineEdit *lineEdit_login;
    QLineEdit *lineEdit_password;

    void setupUi(QWidget *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName("RegisterWindow");
        RegisterWindow->resize(400, 300);
        pushButton_back = new QPushButton(RegisterWindow);
        pushButton_back->setObjectName("pushButton_back");
        pushButton_back->setGeometry(QRect(170, 260, 80, 24));
        pushButton_register = new QPushButton(RegisterWindow);
        pushButton_register->setObjectName("pushButton_register");
        pushButton_register->setGeometry(QRect(170, 150, 80, 24));
        lineEdit_login = new QLineEdit(RegisterWindow);
        lineEdit_login->setObjectName("lineEdit_login");
        lineEdit_login->setGeometry(QRect(150, 70, 113, 24));
        lineEdit_password = new QLineEdit(RegisterWindow);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setGeometry(QRect(150, 110, 113, 24));

        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QWidget *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "Form", nullptr));
        pushButton_back->setText(QCoreApplication::translate("RegisterWindow", "Back", nullptr));
        pushButton_register->setText(QCoreApplication::translate("RegisterWindow", "Register", nullptr));
        lineEdit_login->setText(QCoreApplication::translate("RegisterWindow", "Login", nullptr));
        lineEdit_password->setText(QCoreApplication::translate("RegisterWindow", "Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
