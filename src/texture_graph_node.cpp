#include "texture_graph_node.hpp"
#include "texture_graph_panel.hpp"

TextureGraphNode::TextureGraphNode(TextureGraphPanel* parent, wxWindowID winid, const wxString& typeName, const wxPoint& pos, const int index):

    wxPanel(parent, winid, pos, wxSize(NODE_WIDTH, NODE_HEIGHT), wxBORDER_NONE),
    m_circleFont(wxFontInfo(10).Bold()),
    m_typeName(typeName),
    m_index(index),
    m_parent(parent),
    m_isSelected(false),
    m_isMouseDown(false)
{
    Bind(wxEVT_PAINT, &TextureGraphNode::OnPaint, this);
    Bind(wxEVT_LEFT_DOWN, &TextureGraphNode::MouseDown, this);
    Bind(wxEVT_LEFT_UP, &TextureGraphNode::MouseUp, this);
    Bind(wxEVT_MOTION, &TextureGraphNode::MouseMoved, this);

    image = new wxImage("perlin.png", wxBITMAP_TYPE_PNG);
    bitmap = new wxBitmap(*image);

    m_backgroundBrush = wxBrush(wxColour("#d4d4d4"));
    m_unselectedOutlinePen = wxPen(wxColour("#ffffff"),3);
    m_selectedOutlinePen = wxPen(wxColour("#ffff00"),3);

    m_outputCircleOutlinePen = wxPen(wxColour("#009f00"));
    m_inputCircleOutlinePen = wxPen(wxColour("#9f0000"));


}

void TextureGraphNode::Render(wxDC&  dc)
{
    dc.SetBrush(m_backgroundBrush);

    printf("redraw: %d", m_isSelected);
    dc.SetPen(m_isSelected ? m_selectedOutlinePen : m_unselectedOutlinePen);

    dc.DrawRoundedRectangle(0,
			    0, BOX_WIDTH, BOX_HEIGHT, 10);

   dc.DrawText( wxT("eric"), 5, 5 );

   dc.DrawBitmap(*bitmap,5,30, false);

   DrawTextCircle(dc, m_outputCircleOutlinePen, NODE_WIDTH/2, BOX_HEIGHT-CIRCLE_RADIUS + 6, "T");
}

void TextureGraphNode::OnPaint(wxPaintEvent & evt)
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

void TextureGraphNode::MouseDown(wxMouseEvent& event) {
    // make sure that it becomes selected if necessary
    if(!m_isSelected)
	m_parent->SelectNode(m_index);

    printf("mouse down\n");
    m_isMouseDown = true;
    mousePrevX = event.GetX();
    mousePrevY = event.GetY();


}

void TextureGraphNode::MouseUp(wxMouseEvent& event) {
    printf("mouse up\n");

    m_isMouseDown = false;
}

void TextureGraphNode::Select(bool flag) {
    m_isSelected = flag;
    Refresh();
}

void TextureGraphNode::MouseMoved(wxMouseEvent& event) {
    if(m_isMouseDown) {

	wxCoord mouseCurX = event.GetX();
	wxCoord mouseCurY = event.GetY();

	wxCoord mouseDx = mouseCurX  - mousePrevX;
	wxCoord mouseDy = mouseCurY - mousePrevY;

	SetPosition(GetPosition() + wxPoint(mouseDx, mouseDy));

	printf("moved: %d, %d\n", mouseDx, mouseDy );

	mousePrevX = mouseCurX;
	mousePrevY = mouseCurY;

    }
}
