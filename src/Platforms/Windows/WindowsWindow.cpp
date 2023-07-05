#include "WindowsWindow.h"
#include <iostream>
#include <memory>

namespace MyEngine {
    std::unique_ptr<MyWindow> MyWindow::Create(const WindowProperties& props){
        return std::make_unique<WindowsWindow>(props);
    }

    WindowsWindow::WindowsWindow(const WindowProperties& windowProps){
       Init(windowProps); 
    }
    void WindowsWindow::OnUpdate(){
        std::cout<< "Windows Window OnUpdate." << std::endl;
    }
    void WindowsWindow::OnDraw(){
    }
    void WindowsWindow::OnClose(){
    }

    bool WindowsWindow::Init(const WindowProperties& props){
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;
        m_Data.Title = props.Title;
        return true;
    }
}
