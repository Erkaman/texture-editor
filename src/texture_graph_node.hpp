#pragma once

#include <wx/wx.h>

class TextureGraphPanel;
class Node;

class TextureGraphNode : public wxPanel{


private:

    /*
      INSTANCE VARIABLES
     */

    Node* m_node;

    /*
      VARIABLES USED FOR DRAWING:
     */

    wxImage* image;
    wxBitmap* bitmap;

    wxFont m_circleFont;
    wxFont m_nameLabelFont;

    wxBrush m_backgroundBrush;
    wxPen m_unselectedOutlinePen;
    wxPen m_selectedOutlinePen;

    wxPen m_outputCircleOutlinePen;
    wxPen m_inputCircleOutlinePen;

    /*
      MISC VARIABLES
     */

    // the index of this node in the list of TextureGraphNodes in TextureGraphPanel.
    int m_index;
    TextureGraphPanel* m_parent;
    bool m_isSelected;
    bool m_isMouseDown;

    wxCoord mouseX;
    wxCoord mouseY;

    /*
      INSTANCE METHODS:
     */

    void DrawTextCircle(wxDC& dc, const wxPen& pen, const wxCoord x, const wxCoord y, const wxString& str);


public:
    TextureGraphNode(TextureGraphPanel* parent, const wxPoint& pos, const int index, Node* node);
    virtual ~TextureGraphNode();

    void OnPaint(wxPaintEvent & evt);
    void MouseDown(wxMouseEvent& event);
    void MouseUp(wxMouseEvent& event);
    void MouseMoved(wxMouseEvent& event);



    void Render(wxDC&  dc);

    void Select(bool flag);


    /*
      CONSTANTS
    */
    constexpr static int NODE_WIDTH = 80;
    constexpr static int NODE_HEIGHT = 120;

    constexpr static int BOX_WIDTH = 80;
    constexpr static int BOX_HEIGHT = NODE_HEIGHT-10;

    constexpr static int CIRCLE_RADIUS = 7;

};
