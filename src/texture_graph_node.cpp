#include "texture_graph_node.hpp"


TextureGraphNode::TextureGraphNode(wxWindow* parent, wxWindowID winid, const wxString& typeName, const wxPoint& pos):
    wxPanel(parent, winid, pos, wxSize(NODE_WIDTH, NODE_HEIGHT), wxBORDER_NONE),
    m_typeName(typeName),
    m_circleFont(wxFontInfo(10).Bold())
{
    Connect(wxEVT_PAINT, wxPaintEventHandler(TextureGraphNode::PaintEvent));

    image = new wxImage("perlin.png", wxBITMAP_TYPE_PNG);
    bitmap = new wxBitmap(*image);

    m_backgroundBrush = wxBrush(wxColour("#d4d4d4"));
    m_unselectedOutlinePen = wxPen(wxColour("#ffffff"));
}

void TextureGraphNode::Render(wxDC&  dc)
{
    dc.SetBrush(m_backgroundBrush);
    dc.SetPen(m_unselectedOutlinePen);

    dc.DrawRoundedRectangle(0, 0, NODE_WIDTH, NODE_HEIGHT, 10);

   dc.DrawText( wxT("eric"), 5, 5 );

   dc.DrawBitmap(*bitmap,5,30, false);


   DrawTextCircle(dc, NODE_WIDTH/2, NODE_HEIGHT-CIRCLE_RADIUS, "T");

}

void TextureGraphNode::PaintEvent(wxPaintEvent & evt)
{
    // depending on your system you may need to look at double-buffered dcs
    wxPaintDC dc(this);
    Render(dc);
}


void TextureGraphNode::DrawTextCircle(wxDC& dc, const wxCoord x, const wxCoord y, const wxString& str) {
   dc.DrawCircle(x, y, CIRCLE_RADIUS);
   dc.SetFont(m_circleFont);

   wxSize sz = dc.GetTextExtent(str);

   dc.DrawText( str, x - sz.GetWidth() + CIRCLE_RADIUS/2, y - sz.GetHeight() + 6);
}
