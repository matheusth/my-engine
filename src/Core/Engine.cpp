#include "Engine.h"
#include <iostream>
#include <stdexcept>


namespace MyEngine {
    Engine::Engine(){
        m_Window = MyWindow::Create();
    }
    void Engine::Run(){
        if(!Init()) throw std::runtime_error("Failed to Initialize engine!");
        Renderloop();
    }
    bool Engine::Init(){
        return true;
    }

    void Engine::Renderloop(){
        while (m_running) {
            if(!m_running){
                Cleanup();
                break;
            }
            m_Window->OnUpdate();
        }
    }
    void Engine::Cleanup(){
        std::cout << "Cleaning up!" << std::endl;
    }
}
