#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <memory>

#include "Core.h"

namespace Arche
{
    class LIB_API Logger
    {
    public:
        static void init();
        static std::shared_ptr<spdlog::logger>& getLogger();

    private:
        static std::shared_ptr<spdlog::logger> s_logger;
    };


}

