#include "texture_graph_panel.hpp"
#include "texture_graph_node.hpp"

TextureGraphPanel::TextureGraphPanel(wxPanel * parent)
    :
    wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SIMPLE)

{
  m_parent = parent;
  node = new TextureGraphNode(this, wxID_ANY, wxT("Perlin"), wxPoint(30,30));
}
