#include "texture_graph_node.hpp"


TextureGraphNode::TextureGraphNode(wxWindow* parent, wxWindowID winid, const wxString& typeName, const wxPoint& pos):
    wxPanel(parent, winid, pos, wxSize(NODE_WIDTH, NODE_HEIGHT), wxBORDER_NONE), m_typeName(typeName) {
    Connect(wxEVT_PAINT, wxPaintEventHandler(TextureGraphNode::PaintEvent));

    image = new wxImage("perlin.png", wxBITMAP_TYPE_PNG);
    bitmap = new wxBitmap(*image);
}

void TextureGraphNode::Render(wxDC&  dc)
{

    wxColour gray;
    gray.Set(wxT("#d4d4d4"));

    wxColour white;
    white.Set(wxT("#ffffff"));

    dc.SetBrush(wxBrush(gray));
    dc.SetPen(wxPen(white));

    dc.DrawRoundedRectangle(0, 0, NODE_WIDTH, NODE_HEIGHT, 10);

   dc.DrawText( wxT("eric"), 5, 5 );

   dc.DrawBitmap(*bitmap,5,30, false);



   dc.DrawCircle(5, 100, 20);

}

void TextureGraphNode::PaintEvent(wxPaintEvent & evt)
{
    // depending on your system you may need to look at double-buffered dcs
    wxPaintDC dc(this);
    Render(dc);
}
