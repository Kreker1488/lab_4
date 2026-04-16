#include "user.h"

User::User(const QString& login) : _login(login) {}
QString User::getLogin() const { return _login; }
