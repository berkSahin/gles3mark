

#include "app.h"
#include "console.h"
#include <sstream>

void App::OnStartup() {
//#ifdef _DEBUG
    DebugConsole::RedirectIOToConsole();
//#endif

    try {
        dll.Init(DLLPATH);
    }
    catch (std::exception e) {
        ShowMsg(e.what(), MB_ICONERROR);
        Exit(1);
        return;
    }
    
    // Create window
    BaseApp::OnStartup();
    
    dll.DllInit(GetHWND());
    dll.DllResize(width, height);
}

void App::OnQuit() {
    BaseApp::OnQuit();
    dll.Free();
}

bool App::OnIdle() {
    return dll.DllStep();
}

void App::OnResize(int w, int h) {
    BaseApp::OnResize(w, h);
    dll.DllResize(w, h);
}

void App::OnKeyDown(int key) {
    dll.DllKeyDown(key);
}

void App::OnKeyUp(int key) {
    dll.DllKeyUp(key);
}

void App::OnMouseMove(int x, int y, int dx, int dy) {
    dll.DllMouseMove(x, y, dx, dy);
}

void App::DLL::Init(const std::string& path) {
    dllHandle = LoadLibrary(path.c_str());

    if (!dllHandle) {
        std::stringstream ss;
        ss << GetLastError();
        throw std::runtime_error("LoadLibrary failed : " + path + "\nCode: " + ss.str());
    }        

    DllInit      = reinterpret_cast<DLLInitT     >(GetProcAddress(dllHandle, "DLL_init"     ));
    DllResize    = reinterpret_cast<DLLResizeT   >(GetProcAddress(dllHandle, "DLL_resize"   ));
    DllStep      = reinterpret_cast<DLLStepT     >(GetProcAddress(dllHandle, "DLL_step"     ));
    DllKeyDown   = reinterpret_cast<DLLKeyDownT  >(GetProcAddress(dllHandle, "DLL_keyDown"  ));
    DllKeyUp     = reinterpret_cast<DLLKeyUpT    >(GetProcAddress(dllHandle, "DLL_keyUp"    ));
    DllMouseMove = reinterpret_cast<DLLMouseMoveT>(GetProcAddress(dllHandle, "DLL_mouseMove"));

    if (!DllInit || !DllResize || !DllStep || !DllKeyDown || !DllKeyUp || !DllMouseMove) {
        FreeLibrary(dllHandle);
        throw std::runtime_error("GetProcAddress failed!");
    }
}

void App::DLL::Free() {
    if (dllHandle)
        FreeLibrary(dllHandle);
}
