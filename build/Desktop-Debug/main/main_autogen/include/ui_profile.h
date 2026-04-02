/********************************************************************************
** Form generated from reading UI file 'profile.ui'
**
** Created by: Qt User Interface Compiler version 6.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILE_H
#define UI_PROFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Profile
{
public:
    QLabel *label_photo;
    QPushButton *pushButton_change;
    QPushButton *pushButton_upload;
    QPushButton *pushButton_delete;

    void setupUi(QWidget *Profile)
    {
        if (Profile->objectName().isEmpty())
            Profile->setObjectName("Profile");
        Profile->resize(400, 300);
        label_photo = new QLabel(Profile);
        label_photo->setObjectName("label_photo");
        label_photo->setGeometry(QRect(90, 20, 221, 211));
        pushButton_change = new QPushButton(Profile);
        pushButton_change->setObjectName("pushButton_change");
        pushButton_change->setGeometry(QRect(270, 250, 101, 24));
        pushButton_upload = new QPushButton(Profile);
        pushButton_upload->setObjectName("pushButton_upload");
        pushButton_upload->setGeometry(QRect(30, 250, 91, 24));
        pushButton_delete = new QPushButton(Profile);
        pushButton_delete->setObjectName("pushButton_delete");
        pushButton_delete->setGeometry(QRect(140, 250, 111, 24));

        retranslateUi(Profile);

        QMetaObject::connectSlotsByName(Profile);
    } // setupUi

    void retranslateUi(QWidget *Profile)
    {
        Profile->setWindowTitle(QCoreApplication::translate("Profile", "Form", nullptr));
        label_photo->setText(QCoreApplication::translate("Profile", "TextLabel", nullptr));
        pushButton_change->setText(QCoreApplication::translate("Profile", "Change photo", nullptr));
        pushButton_upload->setText(QCoreApplication::translate("Profile", "Upload photo", nullptr));
        pushButton_delete->setText(QCoreApplication::translate("Profile", "Delete photo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Profile: public Ui_Profile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILE_H
