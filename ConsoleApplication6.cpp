#include <iostream>
#include <Unknwn.h>
#include <atlcomcli.h>
using namespace std; 

// {D16ACAA2-0C01-4673-97CB-FB941C1D48A1}
static const IID IID_IX =
{ 0xd16acaa2, 0xc01, 0x4673,{ 0x97, 0xcb, 0xfb, 0x94, 0x1c, 0x1d, 0x48, 0xa1 } };

// {A5802CE5-C507-44C5-8CB6-5F5D8BC78CFC}
static const IID IID_IY =
{ 0xa5802ce5, 0xc507, 0x44c5,{ 0x8c, 0xb6, 0x5f, 0x5d, 0x8b, 0xc7, 0x8c, 0xfc } };

// 接口 IX
interface IX : public IUnknown
{
    virtual void Fx1() = 0;
    virtual void Fx2() = 0;
};

// 接口 IY
interface IY : public IUnknown
{
    virtual void Fy1() = 0;
    virtual void Fy2() = 0;
};

// 组件 CCom
class CCom : public IX, public IY
{
public:
    CCom()
    {
        m_ulCount = 0;
        //AddRef();
    }
    ~CCom()
    {
        cout << "CCom 析构函数被调用" << endl;
    }

    virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppvObject)
    {
        if (riid == IID_IUnknown)
        {
            *ppvObject = static_cast<IX*>(this);
        }
        else if (riid == IID_IX)
        {
            *ppvObject = static_cast<IX*>(this);
        }
        else if (riid == IID_IY)
        {
            *ppvObject = static_cast<IY*>(this);
        }
        else
        {
            *ppvObject = NULL;
            return E_NOINTERFACE;
        }

        AddRef();// 进行引用计数加一

        return S_OK;
    }

    virtual ULONG STDMETHODCALLTYPE AddRef(void)
    {
        return InterlockedIncrement(&m_ulCount);
    }

    virtual ULONG STDMETHODCALLTYPE Release(void)
    {
        if (InterlockedDecrement(&m_ulCount) == 0)
        {
            delete this;
            return 0;
        }
        return m_ulCount;
    }

    virtual void Fx1() override
    {
        cout << "This is Fx1()" << endl;
    }

    virtual void Fx2() override
    {
        cout << "This is Fx2()" << endl;
    }

    virtual void Fy1() override
    {
        cout << "This is Fy1()" << endl;
    }

    virtual void Fy2() override
    {
        cout << "This is Fy2()" << endl;
    }

private:
    ULONG m_ulCount;
};

template <class T>
class NoAddRelease :public T
{
    virtual ULONG STDMETHODCALLTYPE AddRef(void) = 0;
    virtual ULONG STDMETHODCALLTYPE Release(void) = 0;
};

void Test_CComPtr()
{
    HRESULT hr = 0;
    //CCom*p = new CCom;
    //((NoAddRelease<CCom>*)p)->Release();

    // 创建组件
    //CComPtr<CCom> pComPtr = CComPtr<CCom>(new CCom);
    //CComPtr<CCom> pComPtr = new CCom;
    CComPtr<CCom> pComPtr(new CCom);

    // 从组件查找接口，然后再调用接口实现的功能
    CComPtr<IUnknown> pIUnknownPtr = NULL;
    hr = pComPtr->QueryInterface(IID_IUnknown, (void**)&pIUnknownPtr);// 查询 IUnknown 接口
    if (SUCCEEDED(hr))
    {
        CComPtr<IX> pIXPtr = NULL;
        hr = pComPtr->QueryInterface(IID_IX, (void**)&pIXPtr);// 查询 IX 接口
        if (SUCCEEDED(hr))
        {
            pIXPtr->Fx1();
            pIXPtr->Fx2();
        }

        // 查询 IY 接口
        CComPtr<IY> pIYPtr = NULL;
        hr = pComPtr->QueryInterface(IID_IY, (void**)&pIYPtr);
        if (SUCCEEDED(hr))
        {
            pIYPtr->Fy1();
            pIYPtr->Fy2();
        }
    }
}

int main()
{
    Test_CComPtr();

    return 0;
}

