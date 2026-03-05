#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H


#include <QWidget>

class MainWindow;

namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = nullptr);
    void setMainWindow(MainWindow *mw);
    ~RegisterWindow();

private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_register_clicked();

private:
    Ui::RegisterWindow *ui;
    MainWindow *mainWindow;
};

#endif // REGISTERWINDOW_H
