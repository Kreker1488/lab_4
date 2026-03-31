#include "uploader.h"
#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QDebug>

Uploader::Uploader(const QString &login)
    : _login(login)
{
    //путь к папке пользователя
    _user_path = QCoreApplication::applicationDirPath() + "/photos/" + login + "/";

}

QPixmap Uploader::loadPhoto(int index) const
{
    QString filePath = _user_path + QString::number(index) + ".jpg";
    QPixmap pix(filePath); //пикс объект с загружаемой фотографией
    return pix;
}

bool Uploader::savePhoto(int index, const QPixmap &photo)
{
    QString filePath = _user_path + QString::number(index) + ".jpg";

    bool success = photo.save(filePath, "JPG", 80);
    return success;
}

bool Uploader::photoExists(int index) const
{
    QString filePath = _user_path + QString::number(index) + ".jpg";
    return QFile::exists(filePath);
}

QString Uploader::getUserFolder() const
{
    return _user_path;
}

int Uploader::getNextFreeIndex() const
{
    for (int i = 1; i<=4; i++){
        if (!photoExists(i)){
            return i;
        }
    }
    return -1;
}

bool Uploader::hasFreeSlot() const
{
    return getNextFreeIndex() != -1;
}

bool Uploader::uploadNewPhoto(const QPixmap &photo)
{
    int index = getNextFreeIndex();
    if (index == -1) {
        return false;
    }

    return savePhoto(index, photo);
}
