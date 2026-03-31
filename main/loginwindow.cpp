#include "registerwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QCoreApplication>
#include "logger.h"
#include <QCryptographicHash>
#include "profile.h"
#include "changer.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWindow)
    , _login("")
    , _password("")
{
    ui->setupUi(this);
}



/*QString LoginWindow::getLogin(){
    return _login;
}*/



LoginWindow::~LoginWindow()
{
    delete ui;
}
void LoginWindow::setMainWindow(MainWindow *mw)
{
    mainWindow = mw;
}

void LoginWindow::on_pushButton_back_clicked()
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


void LoginWindow::on_pushButton_login_clicked()
{
    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();

    if (login.isEmpty() || password.isEmpty()) {
        Logger::Warning("Login or Password can not be empty");
        return;
    }

    // Хешируем введённый пароль
    QString hashedInput = hashPassword(password);

    QString filePath = QCoreApplication::applicationDirPath() + "/users.csv";
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        Logger::Error("Can not open users.csv");
        return;
    }

    QTextStream in(&file);
    bool loginSuccess = false;

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(",");
        if (parts.size() >= 2 && parts[0] == login) {
            // Сравниваем хеши
            if (parts[1] == hashedInput) {
                loginSuccess = true;
            }
            break;  // нашли нужный логин, дальше не ищем
        }
    }
    file.close();

    if (loginSuccess) {
        login = ui->lineEdit_login->text();
        password = ui->lineEdit_password->text();


        Logger::Info("Success login");
        Profile *profileWin = new Profile(login);
        profileWin->show();
        this->hide();
    } else {
        Logger::Warning("Wrong login or password");
    }
}

