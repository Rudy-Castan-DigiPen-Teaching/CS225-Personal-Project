#pragma once
#include <core.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include<utility>
#include<memory>
namespace HookBill
{
    class HOOKBILL_API Logger
    {
        using SPDLog = std::shared_ptr<spdlog::logger>;

    public:
        Logger()
        {
            m_SPD = spdlog::stderr_color_mt("stdout");
            spdlog::set_level(spdlog::level::trace);
            spdlog::set_pattern("%^[%T]: [#%t] %v%$");
        }
    private:
        SPDLog m_SPD;
    };

}