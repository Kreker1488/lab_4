#include "profile.h"
#include "ui_profile.h"
#include <QDir>
#include <QPixmap>
#include <QRandomGenerator>
#include <QCoreApplication>

Profile::Profile(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Profile)
{
    ui->setupUi(this);


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

void Profile::on_pushButton_change_clicked()
{
    QString folder = QCoreApplication::applicationDirPath() + "/photos/"; //путь к папке с фотками
    QDir dir(folder);

    QStringList files = dir.entryList({"croco.jpg", "misha.jpg", "jane.jpg", "jeffry.jpg", "mokasini.jpg", "lilith.jpg", "neferpitu.jpg", "momo.jpg", "clown.jpg", "rei.jpg"}, QDir::Files); //тут все фотки

    int index = QRandomGenerator::global()->bounded(files.size());//random index
    QString randomFile = folder + files[index];//absolute path to photo (eto ne ii, mne prosto len menyat rascladku)
    QPixmap pix(randomFile);
    ui->label_photo->setPixmap(pix.scaled(200, 200, Qt::KeepAspectRatio));


}

