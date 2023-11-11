#include "Logger.h"

Logger::Logger(std::string log_dir) {
	for (int i = 0;i <= 99;i++) {
        std::string filename = "log" + std::to_string(i) + ".log";
        if (std::filesystem::exists(std::filesystem::path("log") / filename)) {
            continue;
        }
        file.open("log/log" + std::to_string(i) + ".log", std::ios::out);
        if (file.is_open())
            this->debug("Logger is ready, output file: log/log", std::to_string(i), ".log");
        else {
            this->debug("Logger is ready, but can't open file.");
            this->error("Can't open file: log/log", std::to_string(i), ".log");
        }
        break;
	}
}

template<typename... Args>
void Logger::output(LoggerType type, Args... args) {
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm;
    localtime_s(&now_tm, &now_c);
    std::stringstream time_ss;
    time_ss << std::put_time(&now_tm, "[%H:%M:%S");
    std::cout << time_ss.str() << "|" << LoggerTypeToString(type) << "] ";
    this->file << time_ss.str() << "|" << LoggerTypeToString(type) << "] ";
    auto tuple = std::make_tuple(args...);
    std::apply([this](auto&&... args) {
        ((std::cout << args), ...);
        std::cout << std::endl;
        ((this->file << args), ...);
        this->file << std::endl;
    }, tuple);
}

template<typename... Args>
void Logger::debug(Args... args) {
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm;
    localtime_s(&now_tm, &now_c);
    std::stringstream time_ss;
    time_ss << std::put_time(&now_tm, "[%H:%M:%S");
    std::cout << time_ss.str() << "|" << LoggerTypeToString(LoggerType::DEBUG) << "] ";
    this->file << time_ss.str() << "|" << LoggerTypeToString(LoggerType::DEBUG) << "] ";
    auto tuple = std::make_tuple(args...);
    std::apply([this](auto&&... args) {
        ((std::cout << args), ...);
        std::cout << std::endl;
        ((this->file << args), ...);
        this->file << std::endl;
    }, tuple);
}

template<typename... Args>
void Logger::log(Args... args) {
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm;
    localtime_s(&now_tm, &now_c);
    std::stringstream time_ss;
    time_ss << std::put_time(&now_tm, "[%H:%M:%S");
    std::cout << time_ss.str() << "|" << LoggerTypeToString(LoggerType::LOG) << "] ";
    this->file << time_ss.str() << "|" << LoggerTypeToString(LoggerType::LOG) << "] ";
    auto tuple = std::make_tuple(args...);
    std::apply([this](auto&&... args) {
        ((std::cout << args), ...);
        std::cout << std::endl;
        ((this->file << args), ...);
        this->file << std::endl;
    }, tuple);
}

template<typename... Args>
void Logger::error(Args... args) {
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm;
    localtime_s(&now_tm, &now_c);
    std::stringstream time_ss;
    time_ss << std::put_time(&now_tm, "[%H:%M:%S");
    std::cout << time_ss.str() << "|" << LoggerTypeToString(LoggerType::ERROR) << "] ";
    this->file << time_ss.str() << "|" << LoggerTypeToString(LoggerType::ERROR) << "] ";
    auto tuple = std::make_tuple(args...);
    std::apply([this](auto&&... args) {
        ((std::cout << args), ...);
        std::cout << std::endl;
        ((this->file << args), ...);
        this->file << std::endl;
    }, tuple);
}
