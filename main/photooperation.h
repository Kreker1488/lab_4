#ifndef PHOTOOPERATION_H
#define PHOTOOPERATION_H

#include <QString>

class User;

class PhotoOperation{
public:
    virtual ~PhotoOperation() = default;
    virtual void execute(User *user, const QString& photoPath = "", std::function<void()> onSuccess = nullptr) = 0; //последний аргумент нужен чтобы функция нормально работала, так как она не знает про UI
};


#endif // PHOTOOPERATION_H
