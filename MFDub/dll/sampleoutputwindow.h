#pragma once

#include "sampleresizer.h"

class CWindowEventListener
{
public:
    virtual void HandleResize() = 0;
};

class CSampleOutputWindow
    : public CWindowImpl<CSampleOutputWindow>
{
public:
    CSampleOutputWindow();
    ~CSampleOutputWindow();

    HRESULT SetSampleSize(UINT32 unSampleWidth, UINT32 unSampleHeight);
    HRESULT SetOutputSample(IMFSample* pSample);
    HRESULT GetCurrentSample(IMFSample** ppSample);
    void SetEventListener(CWindowEventListener* pEventListener);
    void Reset();
    
    void SetSelection(UINT32 unSelectionLeft, UINT32 unSelectionTop, UINT32 unSelectionRight, UINT32 unSelectionBottom);

protected:
    LRESULT OnPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnEraseBkgnd(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnWindowPosChanging(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnWindowPosChanged(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

    BEGIN_MSG_MAP(CSampleOutputWindow)
        MESSAGE_HANDLER(WM_PAINT, OnPaint)
        MESSAGE_HANDLER(WM_ERASEBKGND, OnEraseBkgnd)
        MESSAGE_HANDLER(WM_WINDOWPOSCHANGED, OnWindowPosChanged)
        MESSAGE_HANDLER(WM_WINDOWPOSCHANGING, OnWindowPosChanging)
        MESSAGE_HANDLER(WM_SIZE, OnSize)
        MESSAGE_HANDLER(WM_MOVE, OnSize)
    END_MSG_MAP();

    HRESULT DrawSelection(IMFSample* pSample, UINT32 unWidth, UINT32 unHeight);
    
private:
    UINT32 m_unSampleWidth;
    UINT32 m_unSampleHeight;
    CComPtr<IMFSample> m_spSample;
    CComPtr<IMFSample> m_spResizedSample;
    CSampleResizer* m_pResizer;
    CWindowEventListener* m_pEventListener;
    UINT32 m_unSelectionLeft;
    UINT32 m_unSelectionTop;
    UINT32 m_unSelectionRight;
    UINT32 m_unSelectionBottom;
};