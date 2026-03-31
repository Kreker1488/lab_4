#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QCoreApplication>
#include "logger.h"
#include <QCryptographicHash>
#include <filesystem>

RegisterWindow::RegisterWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RegisterWindow)
    , login("")
    , password("")
{
    ui->setupUi(this);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::setMainWindow(MainWindow *mw)
{
    mainWindow = mw;
}

void RegisterWindow::on_pushButton_back_clicked()
{
    this->hide();
    if (mainWindow) {
        mainWindow->show();
    }
}

inline QString hashPassword(const QString &password) // функция для хеширования
{
    QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return hash.toHex();
}


void RegisterWindow::on_pushButton_register_clicked()
{
    //Берём логин и пароль из полей ввода


    login = ui->lineEdit_login->text();
    password = ui->lineEdit_password->text();
    password = hashPassword(password);

    if (login.isEmpty() || password.isEmpty()) {
        Logger::Warning("Login or Password can not be empty");
        return;  // останавливаем выполнение
    }

    QString filePath = QCoreApplication::applicationDirPath() + "/users.csv";

    QFile file(filePath);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        Logger::Error("Can not open users.csv");
        return;
    }

    QTextStream in(&file);
    bool loginExists = false;
    bool passwordExists = false;

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(",");
        if (parts.size() >= 2) {
            if (parts[0] == login)
                loginExists = true;
            if (parts[1] == password)   // пока пароль открыто, потом заменим на хеш
                passwordExists = true;
        }
    }


    if (loginExists) {
        Logger::Warning("User with this login already exist");
        return;
    }

    if (passwordExists) {
        Logger::Warning("This password already exist");
        return;
    }

    QTextStream out(&file);
    out << login << "," << password << "\n";
    file.close();

    Logger::Info("New user have appended: ");

    QString user_path = QCoreApplication::applicationDirPath() + "/photos/" + login;
    std::filesystem::create_directory(user_path.toStdString());


}

