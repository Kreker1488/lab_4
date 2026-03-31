#include "profile.h"
#include "ui_profile.h"
#include <QDir>
#include <QPixmap>
#include <QRandomGenerator>
#include <QCoreApplication>
#include "changer.h"
#include <iostream>
#include "uploader.h"
#include "logger.h"


class LoginWindow;
Profile::Profile(const QString &login, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Profile)
    , uploader(new Uploader(login)) //создание фасада
{
    ui->setupUi(this);
    _login = login;

    updatePhoto(1); //загрузка первого фото при открытии
}

Profile::~Profile()
{
    delete ui;
    delete uploader;
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
}

void Profile::updatePhoto(int index){
    QPixmap pix = uploader->loadPhoto(index);
    ui->label_photo->setPixmap(pix.scaled(200, 200, Qt::KeepAspectRatio));
}

void Profile::on_pushButton_upload_clicked()
{
    if (!uploader->hasFreeSlot()) {
        Logger::Warning("Limit count of photo!");
        return;
    }


    // Диалог выбора файла
    QString fileName = QFileDialog::getOpenFileName(this,
    "Choose the photo",
    QString(),
    "Images (*.jpg *.jpeg *.png)");

    if (fileName.isEmpty()) return;

    // Загружаем фото
    QPixmap pix(fileName);
    if (pix.isNull()) {
        Logger::Warning("Photo was not load");
        return;
    }

    // Сохраняем через аплоадер
    if (uploader->uploadNewPhoto(pix)) {
        Logger::Info("Photo saved");
        updatePhoto(1);   // обновляем отображение
    } else {
        Logger::Error("Photo Save Error");
    }
}

