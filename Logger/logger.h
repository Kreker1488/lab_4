#ifndef LOGGER_H
#define LOGGER_H

#include "Logger_global.h"

class LOGGER_EXPORT Logger
{
public:
    Logger();

    static void set_x(int arg);
    static void set_y(int arg);
    static int get_div();
    static int get_x();
    static int get_y();

    static void division();


    static void Trace(const char* message);
    static void Debug(const char* message);
    static void Info(const char* message);

    static void Error(const char* message);
    static void Warning(const char* message);
    static void Fatal(const char* message);
private:
    static int x_;
    static int y_;
    static int div_;
};

#endif // LOGGER_H
