#include "LinuxWindow.h"
#include <iostream>

namespace MyEngine {
    std::unique_ptr<MyWindow> MyWindow::Create(const WindowProperties& props){
        return std::make_unique<LinuxWindow>(props);
    }

    LinuxWindow::LinuxWindow(const WindowProperties& windowProps){
       Init(windowProps); 
    }
    void LinuxWindow::OnUpdate(){
        std::cout<< "Linux Window OnUpdate." << std::endl;
    }
    void LinuxWindow::OnDraw(){
    }
    void LinuxWindow::OnClose(){
    }

    bool LinuxWindow::Init(const WindowProperties& props){
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;
        m_Data.Title = props.Title;
        return true;
    }
}
