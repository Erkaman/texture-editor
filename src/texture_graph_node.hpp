#pragma once

#include <wx/wx.h>

class TextureGraphNode : public wxPanel{


private:

    wxPanel *m_parent;

    wxString m_typeName;

    wxImage* image;
    wxBitmap* bitmap;

public:
    TextureGraphNode(wxWindow* parent, wxWindowID winid, const wxString& typeName, const wxPoint& pos);

    void PaintEvent(wxPaintEvent & evt);
    void Render(wxDC&  dc);

    /*
      CONSTANTS
    */
    constexpr static int NODE_WIDTH = 80;
    constexpr static int NODE_HEIGHT = 110;
};
