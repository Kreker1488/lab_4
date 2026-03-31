#ifndef UPLOADER_H
#define UPLOADER_H
#include <QDialog>
#include <QFileDialog>

class Uploader
{
public:
    explicit Uploader(const QString &login);

    QPixmap loadPhoto(int index) const;

    bool savePhoto(int index, const QPixmap &photo);

    bool photoExists(int index) const;

    QString getUserFolder() const;

    int getNextFreeIndex() const; // Найти первый свободный индекс

    bool uploadNewPhoto(const QPixmap &photo); // Загрузить новое фото на первый свободный слот

    bool hasFreeSlot() const; // Проверить, можно ли загрузить ещё фото


private:
    QString _login;
    QString _user_path;
};

#endif // UPLOADER_H
