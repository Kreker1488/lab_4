#include "changer.h"
#include "ui_changer.h"
#include <QPixmap>
#include <QCoreApplication>
#include <logger.h>
#include "profile.h"

class Profile;

Changer::Changer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Changer)
{
    ui->setupUi(this);


    QString user_path = QCoreApplication::applicationDirPath() + "/photos/";
    _pix_1 = user_path + _login + "/1.jpg";
    _pix_2 = user_path + _login + "/2.jpg";
    _pix_3 = user_path + _login + "/3.jpg";
    _pix_4 = user_path + _login + "/4.jpg";
    QPixmap pix_1(_pix_1);
    QPixmap pix_2(_pix_2);
    QPixmap pix_3(_pix_3);
    QPixmap pix_4(_pix_4);
    ui->photo_1->setPixmap(pix_1.scaled(100, 100, Qt::KeepAspectRatio));
    ui->photo_1->setScaledContents(true);
    ui->photo_2->setPixmap(pix_2.scaled(100, 100, Qt::KeepAspectRatio));
    ui->photo_3->setPixmap(pix_3.scaled(100, 100, Qt::KeepAspectRatio));
    ui->photo_4->setPixmap(pix_4.scaled(100, 100, Qt::KeepAspectRatio));
}

Changer::Changer(const QString &login, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Changer)
{
    ui->setupUi(this);
    this->show();
    _login = login;   // сохраняем логин

    QString user_path = QCoreApplication::applicationDirPath() + "/photos/";

    _pix_1 = user_path + _login + "/1.jpg";
    _pix_2 = user_path + _login + "/2.jpg";
    _pix_3 = user_path + _login + "/3.jpg";
    _pix_4 = user_path + _login + "/4.jpg";
    QPixmap pix_1(_pix_1);
    QPixmap pix_2(_pix_2);
    QPixmap pix_3(_pix_3);
    QPixmap pix_4(_pix_4);
    ui->photo_1->setPixmap(pix_1.scaled(100, 100, Qt::KeepAspectRatio));
    ui->photo_1->setScaledContents(true);
    ui->photo_2->setPixmap(pix_2.scaled(100, 100, Qt::KeepAspectRatio));
    ui->photo_3->setPixmap(pix_3.scaled(100, 100, Qt::KeepAspectRatio));
    ui->photo_4->setPixmap(pix_4.scaled(100, 100, Qt::KeepAspectRatio));
}

void Changer::setProfile(Profile *profile)
{
    m_profile = profile;
}




Changer::~Changer()
{
    delete ui;
}

void Changer::on_pushButton_1_clicked()
{
    _current_pix = _pix_1;
}


void Changer::on_pushButton_2_clicked()
{
    _current_pix = _pix_2;
}


void Changer::on_pushButton_3_clicked()
{
    _current_pix = _pix_3;
}


void Changer::on_pushButton_4_clicked()
{
    _current_pix = _pix_4;
}


void Changer::on_buttonBox_accepted()
{
    m_profile->changePhoto(_current_pix);
}

