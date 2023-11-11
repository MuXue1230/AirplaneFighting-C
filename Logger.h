#pragma once
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <tuple>
#include <utility>
#include <string>
#include <filesystem>
#include <fstream>

#include "LoggerType.h"

class Logger
{
public:
	Logger(std::string log_dir);
	template<typename... Args>
    void output(LoggerType type, Args... args);
    template<typename... Args>
    void debug(Args... args);
    template<typename... Args>
    void log(Args... args);
    template<typename... Args>
    void error(Args... args);
private:
	std::ofstream file;
    std::string LoggerTypeToString(LoggerType _type) {
        switch (_type) {
        case LoggerType::DEBUG: return "DEBUG";
        case LoggerType::LOG: return "LOG";
        case LoggerType::ERROR: return "ERROR";
        default: return "UNKNOWN";
        }
    }
};
