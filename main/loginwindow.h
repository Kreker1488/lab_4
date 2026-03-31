#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H


#include <QWidget>

class MainWindow;

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    void setMainWindow(MainWindow *mw);
    ~LoginWindow();

    //QString getLogin();

private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_login_clicked();

private:
    Ui::LoginWindow *ui;
    MainWindow *mainWindow;
    QString _login;
    QString _password;
};

#endif // LOGINWINDOW_H
