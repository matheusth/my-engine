#ifndef LINUXWINDOW_H
#define LINUXWINDOW_H
#include "../../Core/MyWindow.h"

namespace MyEngine {
    class LinuxWindow : public MyWindow {
        public:
            LinuxWindow(const WindowProperties& windowProps);
            LinuxWindow(const LinuxWindow&) = delete;
            LinuxWindow& operator= (const LinuxWindow&) = delete;
            virtual ~LinuxWindow(){}
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
