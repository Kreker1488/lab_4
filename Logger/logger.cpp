#include "logger.h"
#include <chrono>
#include <ctime>
#include <iostream>

Logger::Logger() {}

int Logger::x_ = 0;
int Logger::y_ = 0;
int Logger::div_ = 0;

void Logger::set_x(int arg){
    x_ = arg;
}
void Logger::set_y(int arg){
    y_ = arg;
}
int Logger::get_div(){
    return div_;
}
int Logger::get_x(){
    return x_;
}
int Logger::get_y(){
    return y_;
}

void Logger::division(){
    div_ = x_ / y_;
}

void Logger::Trace(const char* message){
    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);
    std::cout << std::ctime(&time) << "[TRACE] file: " <<  __FILE__  << " line " << __LINE__ << " " << message << std::endl;
    std::cout << std::endl;
}

void Logger::Debug(const char* message){
    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);
    std::cout << std::ctime(&time) << "[DEBUG] " << message << " x=" << x_ << " y=" << y_ << " x/y=" << div_ << std::endl;
    std::cout << std::endl;
}

void Logger::Info(const char* message){
    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);
    std::cout << std::ctime(&time) << "[INFO] " << message << std::endl;
    std::cout << std::endl;
}

void Logger::Error(const char* message){
    std::cout << "[ERROR] " << message << " " << __FILE__ << " " << __LINE__ << std::endl;
}

void Logger::Warning(const char* message){
    std::cout << "[WARNING] " << message << std::endl;
}

void Logger::Fatal(const char* message){
    std::cout << "[FATAL] " << message << std::endl;
}
