#ifndef UPLOADPHOTO_H
#define UPLOADPHOTO_H

#include "photooperation.h"

class UploadPhoto : public PhotoOperation
{
public:
    void execute(User *user, const QString& photoPath = "", std::function<void()> onSuccess = nullptr) override;
};

#endif // UPLOADPHOTO_H
