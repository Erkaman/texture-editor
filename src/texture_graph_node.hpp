#pragma once

#include <wx/wx.h>

class TextureGraphNode : public wxControl{


private:

    wxPanel *m_parent;

    wxString m_typeName;

public:
    TextureGraphNode(wxWindow* parent, wxWindowID winid, const wxString& typeName, const wxPoint& pos);


//    void OnPaint(wxPaintEvent& event);

    void paintEvent(wxPaintEvent & evt);



    void paintNow();


    void render(wxDC&  dc);



    /*
      CONSTANTS
    */
    constexpr static int NODE_WIDTH = 200;
    constexpr static int NODE_HEIGHT = 50;
};
