#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFile>
#include <QTextStream>
#include <QCoreApplication>
#include <QDebug>
#include <logger.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    loginWindow = new LoginWindow();
    loginWindow->setMainWindow(this);

    registerWindow = new RegisterWindow();
    registerWindow->setMainWindow(this);


    QString filePath = QCoreApplication::applicationDirPath() + "/users.csv";
    QFile file(filePath);

    if (!file.exists()) {
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << "login,hash\n";
            file.close();
            Logger::Warning("File users.csv already created:");
        } else {
            Logger::Error("File was not created");
        }
    } else {
        Logger::Warning("File users.csv already exist:");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_login_clicked()
{
    this->hide();
    loginWindow->show();
}


void MainWindow::on_pushButton_register_clicked()
{
    this->hide();
    registerWindow->show();
}

