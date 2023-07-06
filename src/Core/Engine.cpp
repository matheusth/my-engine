#include "Engine.h"
#include <iostream>
#include "Time.h"
#include <stdexcept>


namespace MyEngine {
    Engine::Engine() {
        m_Window = MyWindow::Create();
        m_StartTime = 0.0f;
    }

    void Engine::Run() {
        if (!Init()) throw std::runtime_error("Failed to Initialize engine!");
        Renderloop();
    }

    bool Engine::Init() {
        std::cout << "Engine initialized!" << std::endl;
        m_StartTime = std::chrono::time_point_cast<std::chrono::microseconds>(
                std::chrono::high_resolution_clock::now()).time_since_epoch().count() / 1000000.0f;
        return true;
    }

    void Engine::Renderloop() {
        while (m_running) {
            auto startTime = std::chrono::high_resolution_clock::now();
            if (!m_running) {
                Cleanup();
                break;
            }
            m_Window->OnUpdate();
            auto endTime = std::chrono::high_resolution_clock::now();
            auto start = std::chrono::time_point_cast<std::chrono::microseconds>(startTime).time_since_epoch().count();
            auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTime).time_since_epoch().count();

            Time::_unscaledDeltaTime = (float) (end - start) / 1000.0f;
            Time::_deltaTime = Time::_unscaledDeltaTime * Time::timeScale;

            Time::_realTimeSinceStartup = (end / 1000000.0f) - m_StartTime;
            Time::_time = Time::_realTimeSinceStartup * Time::timeScale;
            Time::_frameCount++;

            printf("Time Format: %s\tDelta Time: %f\tUnscaled Delta Time: %f\tTime Scale: %f\tTime: %f\tReal Time Since Startup: %f\tFrame Count: %d\n",
                   Time::GetLocalTimeFormat().c_str(), Time::deltaTime(), Time::unscaledDeltaTime(), Time::timeScale,
                   Time::time(), Time::realTimeSinceStartup(),
                   Time::frameCount());
        }
    }

    void Engine::Cleanup() {
        std::cout << "Cleaning up!" << std::endl;
    }
}
