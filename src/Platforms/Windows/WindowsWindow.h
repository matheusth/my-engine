#ifndef WINDOWSWINDOW_H
#define WINDOWSWINDOW_H
#include "../../Core/MyWindow.h"

namespace MyEngine {
    class WindowsWindow : public MyWindow {
        public:
            WindowsWindow(const WindowProperties& windowProps);
            WindowsWindow(const WindowsWindow&) = delete;
            WindowsWindow& operator= (const WindowsWindow&) = delete;
            virtual ~WindowsWindow(){}
            virtual void OnUpdate() override;
            virtual void OnDraw() override;
            virtual void OnClose() override;
            virtual uint32_t GetWidth() const override {return m_Data.Width;};
            virtual uint32_t GetHeight() const override {return m_Data.Height;};

            static std::unique_ptr<MyWindow> Create(const WindowProperties props = WindowProperties());
        private:
            bool Init(const WindowProperties&);
        private:
            struct WindowData
            {
                const char * Title;
                uint32_t Width, Height;
            }m_Data;
    };
}
#endif
