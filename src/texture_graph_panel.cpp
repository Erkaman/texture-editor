#include "texture_graph_panel.hpp"
#include "texture_graph_node.hpp"


static constexpr int PERLIN_ITEM_ID = 101;

void TextureGraphPanel::CreateTestNode(const wxPoint& point) {
    int index = m_nodes.size();
    m_nodes.push_back(new TextureGraphNode(this, wxID_ANY, wxT("Perlin"),point, index));
}

TextureGraphPanel::TextureGraphPanel(wxPanel * parent):
    wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SIMPLE),m_selectedNodeIndex(-1) {
    m_parent = parent;

    CreateTestNode(wxPoint(100,100));

    CreateTestNode(wxPoint(250,100));


    /*
      Setup the context menu
    */

    m_contextMenu = new wxMenu();

    m_contextMenu->Append(PERLIN_ITEM_ID, wxT("&Perlin Noise"));
    Bind(wxEVT_COMMAND_MENU_SELECTED, &TextureGraphPanel::OnCreatePerlin, this, PERLIN_ITEM_ID);


    Bind(wxEVT_CONTEXT_MENU, &TextureGraphPanel::OnRightClick, this);
}

void TextureGraphPanel::OnRightClick(wxContextMenuEvent& event) {
    m_contextMenuPosition = ScreenToClient(event.GetPosition());
    PopupMenu(m_contextMenu, m_contextMenuPosition);
}

void TextureGraphPanel::OnCreatePerlin(wxCommandEvent& event) {
    CreateTestNode(m_contextMenuPosition);
}

void TextureGraphPanel::SelectNode(int nodeIndex) {

    // unselect the old node.
    if(m_selectedNodeIndex != -1) {
	m_nodes[m_selectedNodeIndex]->Select(false);
    }

    // select the new node.
    if(nodeIndex != m_selectedNodeIndex)
	m_nodes[nodeIndex]->Select(true);

    m_selectedNodeIndex = nodeIndex;
}
