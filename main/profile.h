#ifndef PROFILE_H
#define PROFILE_H

#include <QWidget>
#include "uploader.h"

class LoginWindow;
class Changer;

namespace Ui {
class Profile;
}

class Profile : public QWidget
{
    Q_OBJECT

public:
    explicit Profile(const QString &login, QWidget *parent = nullptr);
    ~Profile();

    void changePhoto(const QString &path);

private slots:
    void on_pushButton_change_clicked();

    void on_pushButton_upload_clicked();

    void updatePhoto(int index); //загрузка и показ фото

    void on_pushButton_delete_clicked();

    int getNextExistingPhotoIndex() const;

private:
    Ui::Profile *ui;
    Changer *changer;
    Uploader *uploader;
    int _currentIndex;

    QString _login;
    QString _path;

};

#endif // PROFILE_H
