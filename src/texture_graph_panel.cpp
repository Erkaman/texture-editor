#include "texture_graph_panel.hpp"
#include "texture_graph_node.hpp"


static constexpr int PERLIN_ITEM_ID = 101;

TextureGraphPanel::TextureGraphPanel(wxPanel * parent):
    wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SIMPLE) {
    m_parent = parent;



    /*
      Setup the context menu
    */

    m_contextMenu = new wxMenu();

    m_contextMenu->Append(PERLIN_ITEM_ID, wxT("&Perlin Noise"));
    Bind(wxEVT_COMMAND_MENU_SELECTED, &TextureGraphPanel::OnCreatePerlin, this, PERLIN_ITEM_ID);


    Bind(wxEVT_CONTEXT_MENU, &TextureGraphPanel::OnRightClick, this);
}

void TextureGraphPanel::OnRightClick(wxContextMenuEvent& event) {
    contextMenuPosition = ScreenToClient(event.GetPosition());
    PopupMenu(m_contextMenu, contextMenuPosition);
}

void TextureGraphPanel::OnCreatePerlin(wxCommandEvent& event) {
    nodes.push_back(new TextureGraphNode(this, wxID_ANY, wxT("Perlin"),contextMenuPosition));
}
