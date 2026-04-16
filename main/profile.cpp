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
    , _currentIndex(1)
    , _user(new User(login))
{
    ui->setupUi(this);
    _login = login;


    _uploadOp = std::make_unique<UploadPhoto>();

    uploader->savePhoto(-1, QCoreApplication::applicationDirPath() + "/photos/" + "-1.jpg");
    updatePhoto(-1); //загрузка первого фото при открытии
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

    for (int i = 1; i <= 4; ++i) {
        QString expectedPath = uploader->getUserFolder() + QString::number(i) + ".jpg";
        if (expectedPath == path) {
            _currentIndex = i;
            break;
        }
    }
}


void Profile::on_pushButton_change_clicked()
{
    Changer *changer = new Changer(_login);
    changer->setProfile(this);
}

void Profile::updatePhoto(int index){
    if (index == -1 || !uploader->photoExists(index)) {
        QPixmap pix = uploader->loadPhoto(-1);
        ui->label_photo->setPixmap(pix.scaled(200, 200, Qt::KeepAspectRatio));
        _currentIndex = -1;
        return;
    }

    QPixmap pix = uploader->loadPhoto(index);
    ui->label_photo->setPixmap(pix.scaled(200, 200, Qt::KeepAspectRatio));
    _currentIndex = index;
}

void Profile::on_pushButton_upload_clicked()
{
    _uploadOp->execute(_user, "", [this](){
        updatePhoto(getNextExistingPhotoIndex());
    });
}

int Profile::getNextExistingPhotoIndex() const
{
    for (int i = 1; i <= 4; ++i) {
        if (uploader->photoExists(i)) {
            return i;
        }
    }
    return -1;
}


void Profile::on_pushButton_delete_clicked()
{
    if (_currentIndex == -1) {
        Logger::Warning("Нет фото для удаления");
        return;
    }

    uploader->deletePhoto(_currentIndex);
    Logger::Info("Фото удалено");

    int nextIndex = getNextExistingPhotoIndex();
    updatePhoto(nextIndex);
}
