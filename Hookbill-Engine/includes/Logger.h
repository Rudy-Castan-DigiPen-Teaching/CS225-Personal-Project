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
            MyLogger_ = spdlog::stderr_color_mt("stdout");
            spdlog::set_level(spdlog::level::trace);
            spdlog::set_pattern("%^[%T]: [#%t] %v%$");
        }

        static SPDLog& Ref()
        {
            static Logger logger;
            return logger.MyLogger_;
        }


    
       SPDLog MyLogger_;
    };

}

#define HOOKBILL_TRACE(...) HookBill::Logger::Ref()->trace(__VA_ARGS__) 
#define HOOKBILL_DEBUG(...) HookBill::Logger::Ref()->debug(__VA_ARGS__) 
#define HOOKBILL_INFO(...)  HookBill::Logger::Ref()->info(__VA_ARGS__) 
#define HOOKBILL_WARN(...)  HookBill::Logger::Ref()->warn(__VA_ARGS__) 
#define HOOKBILL_ERROR(...) HookBill::Logger::Ref()->error(__VA_ARGS__) 
#define HOOKBILL_FATAL(...) HookBill::Logger::Ref()->critical(__VA_ARGS__)


