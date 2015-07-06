#include "texture_graph_node.hpp"


TextureGraphNode::TextureGraphNode(wxWindow* parent, wxWindowID winid, const wxString& typeName, const wxPoint& pos): wxControl(parent, winid, pos), m_typeName(typeName) {

    SetMinSize( wxSize(NODE_WIDTH, NODE_HEIGHT) );

    Connect(wxEVT_PAINT, wxPaintEventHandler(TextureGraphNode::paintEvent));

    Centre();
}

void TextureGraphNode::render(wxDC&  dc)
{
    int x;
    int y;
    GetPosition(&x,&y);
/*    wxString str;
    str.Printf(wxT("pos %d %d\n."), x,y);
    wxPuts(str);
*/
    wxColour gray;
    gray.Set(wxT("#d4d4d4"));

    //dc.DrawEllipse(20, 20, 90, 60);

    dc.SetBrush(wxBrush(gray));

//    dc.DrawRectangle( x, y, 80, 30 );

    dc.DrawRectangle( 10, 10, 210, 60 );

    dc.DrawText( wxT("eric"), 20, 15 );


//  dc.DrawRoundedRectangle(130, 20, 90, 60, 10);

}


void TextureGraphNode::paintEvent(wxPaintEvent & evt)
{
    // depending on your system you may need to look at double-buffered dcs
    wxPaintDC dc(this);
    render(dc);
}

void TextureGraphNode::paintNow(){
    wxClientDC dc(this);
    render(dc);
}
