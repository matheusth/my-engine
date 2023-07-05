#include <memory>
#ifndef MYWINDOW_H
#define MYWINDOW_H
namespace MyEngine {
    struct WindowProperties{
        const char* Title;
        uint32_t Width;
        uint32_t Height;
        WindowProperties(const char* title = "My Window", uint32_t width = 800, uint32_t height = 600)
            : Title(title), Width(width), Height(height){}
    };
    class MyWindow{
        public:
            virtual ~MyWindow(){}
            virtual void OnUpdate() = 0;
            virtual void OnDraw() = 0;
            virtual void OnClose() = 0;
            virtual uint32_t GetWidth() const = 0;
            virtual uint32_t GetHeight() const = 0;

            static std::unique_ptr<MyWindow> Create(const WindowProperties& props = WindowProperties());
    };
}
#endif
