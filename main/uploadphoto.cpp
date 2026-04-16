#include "uploadphoto.h"
#include "user.h"
#include "uploader.h"
#include "logger.h"
#include <QFileDialog>
#include <QPixmap>
#include <QWidget>

void UploadPhoto::execute(User *user, const QString&, std::function<void()> onSuccess) {
    // Создаём uploader для пользователя
    Uploader uploader(user->getLogin());

    if (!uploader.hasFreeSlot()) {
        Logger::Warning("Limit count of photo!");
        return;
    }

    QWidget* parent = nullptr;

    QString fileName = QFileDialog::getOpenFileName(parent,
                                                    "Choose the photo",
                                                    QString(),
                                                    "Images (*.jpg *.jpeg *.png)");

    if (fileName.isEmpty()) return;

    QPixmap pix(fileName);
    if (pix.isNull()) {
        Logger::Warning("Photo was not load");
        return;
    }

    if (uploader.uploadNewPhoto(pix)) {
        Logger::Info("Photo saved");
        if (onSuccess) onSuccess();
    } else {
        Logger::Error("Photo Save Error");
    }
}
