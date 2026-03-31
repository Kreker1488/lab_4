#ifndef CHANGER_H
#define CHANGER_H

#include <QDialog>

class Profile;

namespace Ui {
class Changer;
}

class Changer : public QDialog
{
    Q_OBJECT

public:
    explicit Changer(QWidget *parent = nullptr);
    explicit Changer(const QString &login, QWidget *parent = nullptr);
    ~Changer();

    void setProfile(Profile *profile);

private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_buttonBox_accepted();

private:
    Ui::Changer *ui;
    Profile *m_profile;

    QString _login;
    QString _password;

    QString _pix_1;
    QString _pix_2;
    QString _pix_3;
    QString _pix_4;
    QString _current_pix;
    //LoginWindow *m_loginWindow;
};

#endif // CHANGER_H
