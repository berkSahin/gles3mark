
#pragma once

class RenderContext {

public:
    RenderContext(): mWidth(0), mHeight(0) {};
    virtual ~RenderContext() = default;
    
    virtual bool Create(void* osWnd) = 0;
    virtual void Destroy() = 0;
    virtual void Resize(int w, int h, bool vsync) = 0;
    virtual void Swap() = 0;

    int GetWidth()  const { return mWidth;  }
    int GetHeight() const { return mHeight; }

protected:
    int mWidth;
    int mHeight;
};
