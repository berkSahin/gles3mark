
#pragma once

#include <SDKDDKVer.h>        // Defines the highest available Windows platform.
#define WIN32_LEAN_AND_MEAN   // Exclude rarely-used stuff from Windows headers
#include <windows.h>

#include <string>

class BaseApp {
    HWND            hWnd;
    HINSTANCE       hInstance;
    int             exitCode;
    bool            quit;

    HCURSOR         hCursor;
    POINT           windowCenter;
    std::string     windowTitle;
    std::string     className;

    static LRESULT CALLBACK     SystemWindowProc(HWND windows, UINT msg, WPARAM wp, LPARAM lp);
    LRESULT                     WindowProc(UINT msg, WPARAM wp, LPARAM lp);

protected:
    int         width, height;

    bool        SetupWindow(int w, int h);
    void        DestroyWindow();
    void        ShowWindow(bool visible);
    void        SetWindowTitle(const std::string& title);
    void        Exit(int exitCode);
    void        ShowMsg(const std::string& msg, UINT type = MB_ICONINFORMATION);
    HWND        GetHWND() { return hWnd; }
    
    // HANDLERS
    virtual void    OnStartup()             { SetupWindow(1280, 720);   }
    virtual void    OnQuit()                { DestroyWindow(); Exit(0); }
    virtual void    OnIdle()                {                           }
    virtual void    OnResize(int w, int h)  { width = w, height = h;    }

public:
    BaseApp(HINSTANCE hInstance, LPSTR cmdLine);
    virtual ~BaseApp();

    int Run();
};