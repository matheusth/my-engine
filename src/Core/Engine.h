#ifndef ENGINE_H
#define ENGINE_H
#include <memory>
#ifdef PLATFORM_WINDOWS
#include "../Platforms/Windows/WindowsWindow.h"
#else
#include "../Platforms/Linux/LinuxWindow.h"
#endif
#include "../Core/MyWindow.h"
namespace MyEngine {
    class Engine {
        public:
            Engine();
            void Run();
        private:
            bool Init();
            void Renderloop();
            void Cleanup();
        private:
            bool m_running = true;
            std::unique_ptr<MyWindow> m_Window;
    };
}
#endif
