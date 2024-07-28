#include "Logger.h"

std::shared_ptr<spdlog::logger> Arche::Logger::s_logger = nullptr;

void Arche::Logger::init()
{
    if (!s_logger)
    {
        s_logger = spdlog::stdout_color_mt("console");
        spdlog::set_level(spdlog::level::trace); // Set global log level to trace
        spdlog::set_pattern("[%Y-%m-%d %H:%M:%S] [%^%l%$] %v"); // Set log pattern with color
    }
}

std::shared_ptr<spdlog::logger>& Arche::Logger::getLogger()
{
    return s_logger;
}



