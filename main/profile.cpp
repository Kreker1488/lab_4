#include "profile.h"
#include "ui_profile.h"
#include <QDir>
#include <QPixmap>
#include <QRandomGenerator>
#include <QCoreApplication>
#include "changer.h"
#include <iostream>


class LoginWindow;
Profile::Profile(const QString &login, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Profile)
{
    ui->setupUi(this);
    _login = login;


    QString folder = QCoreApplication::applicationDirPath() + "/photos/"; //путь к папке с фотками
    QDir dir(folder);

    QStringList files = dir.entryList({"croco.jpg", "misha.jpg", "jane.jpg", "jeffry.jpg"}, QDir::Files); //тут все фотки

    if (!files.isEmpty()) {
        QString firstFile = folder + files.first();
        QPixmap pix(firstFile);
        if (!pix.isNull()) {
            ui->label_photo->setPixmap(pix.scaled(200, 200, Qt::KeepAspectRatio));
        }
    }
}

Profile::~Profile()
{
    delete ui;
}

void Profile::changePhoto(const QString &path){
    QPixmap pix(path);
    ui->label_photo->setPixmap(pix.scaled(200, 200, Qt::KeepAspectRatio));
    std::cout <<"path: " << path.toStdString() << std::endl;
}


void Profile::on_pushButton_change_clicked()
{
    Changer *changer = new Changer(_login);
    changer->setProfile(this);
    //changer.show();
}

