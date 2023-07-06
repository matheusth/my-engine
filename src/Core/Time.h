//
// Created by matheus on 06/07/23.
//

#ifndef MYENGINE_TIME_H
#define MYENGINE_TIME_H

#include <cstdint>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>

namespace MyEngine {
    class Time {
    public:
        Time() = delete;
        Time(const Time&) = delete;
        Time& operator=(const Time&) = delete;
        static float timeScale;
        static inline float deltaTime() { return _deltaTime; }
        static inline float unscaledDeltaTime() {return _unscaledDeltaTime;}
        static inline float realTimeSinceStartup (){return _realTimeSinceStartup;}
        static inline float time(){return _time;}
        static inline uint32_t frameCount(){return _frameCount;}
        static inline std::string GetLocalTimeFormat(){
            auto t = std::time(nullptr);
            auto tm = *std::localtime(&t);

            std::ostringstream os;
            os << std::put_time(&tm, "%H:%M:%S %d-%m-%Y") << std::endl;

            return os.str();
        }
        friend class Engine;
    private:
        static float _deltaTime;
        static float _unscaledDeltaTime;
        static float _realTimeSinceStartup;
        static float _time;
        static uint32_t _frameCount;
    };
    float Time::_deltaTime = 0.0f;
    float Time::_unscaledDeltaTime = 0.0f;
    float Time::timeScale = 1.0f;
    float Time::_time = 0.0f;
    float Time::_realTimeSinceStartup = 0.0f;
    uint32_t Time::_frameCount = 0;
}
#endif //MYENGINE_TIME_H
