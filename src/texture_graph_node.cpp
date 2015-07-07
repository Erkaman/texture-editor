#include "texture_graph_node.hpp"


TextureGraphNode::TextureGraphNode(wxWindow* parent, wxWindowID winid, const wxString& typeName, const wxPoint& pos):
    wxPanel(parent, winid, pos, wxSize(NODE_WIDTH, NODE_HEIGHT), wxBORDER_NONE),
    m_typeName(typeName),
    m_circleFont(wxFontInfo(10).Bold())
{
    Bind(wxEVT_PAINT, &TextureGraphNode::PaintEvent, this);

    image = new wxImage("perlin.png", wxBITMAP_TYPE_PNG);
    bitmap = new wxBitmap(*image);

    m_backgroundBrush = wxBrush(wxColour("#d4d4d4"));
    m_unselectedOutlinePen = wxPen(wxColour("#ffffff"));

    m_outputCircleOutlinePen = wxPen(wxColour("#009f00"));
    m_inputCircleOutlinePen = wxPen(wxColour("#9f0000"));


}

void TextureGraphNode::Render(wxDC&  dc)
{
    dc.SetBrush(m_backgroundBrush);
    dc.SetPen(m_unselectedOutlinePen);

    dc.DrawRoundedRectangle(0,
			    0, BOX_WIDTH, BOX_HEIGHT, 10);

   dc.DrawText( wxT("eric"), 5, 5 );

   dc.DrawBitmap(*bitmap,5,30, false);

   DrawTextCircle(dc, m_outputCircleOutlinePen, NODE_WIDTH/2, BOX_HEIGHT-CIRCLE_RADIUS + 6, "T");
}

void TextureGraphNode::PaintEvent(wxPaintEvent & evt)
{
    // depending on your system you may need to look at double-buffered dcs
    wxPaintDC dc(this);
    Render(dc);
}

void TextureGraphNode::DrawTextCircle(wxDC& dc, const wxPen& pen, const wxCoord x, const wxCoord y, const wxString& str) {
   dc.SetPen(pen);
   dc.DrawCircle(x, y, CIRCLE_RADIUS);

   dc.SetFont(m_circleFont);

   wxSize sz = dc.GetTextExtent(str);

   dc.DrawText( str, x - sz.GetWidth() + CIRCLE_RADIUS/2, y - sz.GetHeight() + 6);
}
