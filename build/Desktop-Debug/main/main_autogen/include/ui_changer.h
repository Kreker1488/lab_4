/********************************************************************************
** Form generated from reading UI file 'changer.ui'
**
** Created by: Qt User Interface Compiler version 6.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGER_H
#define UI_CHANGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Changer
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *photo_1;
    QLabel *photo_2;
    QLabel *photo_3;
    QLabel *photo_4;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *Changer)
    {
        if (Changer->objectName().isEmpty())
            Changer->setObjectName("Changer");
        Changer->resize(400, 300);
        buttonBox = new QDialogButtonBox(Changer);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(290, 20, 81, 241));
        buttonBox->setOrientation(Qt::Orientation::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        photo_1 = new QLabel(Changer);
        photo_1->setObjectName("photo_1");
        photo_1->setGeometry(QRect(20, 10, 111, 101));
        photo_1->setScaledContents(true);
        photo_2 = new QLabel(Changer);
        photo_2->setObjectName("photo_2");
        photo_2->setGeometry(QRect(160, 10, 111, 101));
        photo_2->setScaledContents(true);
        photo_3 = new QLabel(Changer);
        photo_3->setObjectName("photo_3");
        photo_3->setGeometry(QRect(20, 160, 111, 101));
        photo_3->setScaledContents(true);
        photo_4 = new QLabel(Changer);
        photo_4->setObjectName("photo_4");
        photo_4->setGeometry(QRect(160, 150, 111, 101));
        photo_4->setScaledContents(true);
        pushButton_1 = new QPushButton(Changer);
        pushButton_1->setObjectName("pushButton_1");
        pushButton_1->setGeometry(QRect(20, 110, 80, 24));
        pushButton_2 = new QPushButton(Changer);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(150, 110, 80, 24));
        pushButton_3 = new QPushButton(Changer);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(10, 260, 80, 24));
        pushButton_4 = new QPushButton(Changer);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(150, 260, 80, 24));

        retranslateUi(Changer);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Changer, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Changer, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Changer);
    } // setupUi

    void retranslateUi(QDialog *Changer)
    {
        Changer->setWindowTitle(QCoreApplication::translate("Changer", "Dialog", nullptr));
        photo_1->setText(QCoreApplication::translate("Changer", "TextLabel", nullptr));
        photo_2->setText(QCoreApplication::translate("Changer", "TextLabel", nullptr));
        photo_3->setText(QCoreApplication::translate("Changer", "TextLabel", nullptr));
        photo_4->setText(QCoreApplication::translate("Changer", "TextLabel", nullptr));
        pushButton_1->setText(QCoreApplication::translate("Changer", "Photo 1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Changer", "Photo 2", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Changer", "Photo 3", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Changer", "Photo 4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Changer: public Ui_Changer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGER_H
