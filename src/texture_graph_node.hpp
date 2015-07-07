#pragma once

#include <wx/wx.h>

class TextureGraphNode : public wxPanel{


private:

    /*
      INSTANCE VARIABLES
     */

    wxPanel *m_parent;

    wxString m_typeName;

    wxImage* image;
    wxBitmap* bitmap;


    wxFont m_circleFont;

    wxBrush m_backgroundBrush;
    wxPen m_unselectedOutlinePen;

    /*
      INSTANCE METHODS:
     */

    void DrawTextCircle(wxDC& dc, const wxCoord x, const wxCoord y, const wxString& str);


public:
    TextureGraphNode(wxWindow* parent, wxWindowID winid, const wxString& typeName, const wxPoint& pos);

    void PaintEvent(wxPaintEvent & evt);
    void Render(wxDC&  dc);

    /*
      CONSTANTS
    */
    constexpr static int NODE_WIDTH = 80;
    constexpr static int NODE_HEIGHT = 110;
    constexpr static int CIRCLE_RADIUS = 7;

};
