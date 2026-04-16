#ifndef USER_H
#define USER_H

#include <QString>

class User
{
public:
    User(const QString& login);
    QString getLogin() const;
private:
    QString _login;
};

#endif // USER_H
