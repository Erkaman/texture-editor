#include "texture_graph_panel.hpp"
#include "texture_graph_node.hpp"
#include "main_frame.hpp"

#include "node/constant_color.hpp"


static constexpr int PERLIN_ITEM_ID = 101;
static constexpr int CONSTANT_COLOR_ITEM_ID = 102;

void TextureGraphPanel::CreateConstantColorNode(const wxPoint& point) {
    int index = m_nodes.size();
    m_nodes.push_back(new TextureGraphNode(this,point, index, new ConstantColor()));
}

TextureGraphPanel::TextureGraphPanel(wxPanel * parent, MainFrame* mainFrame):
    wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SIMPLE),
    m_selectedNodeIndex(-1), m_mainFrame(mainFrame){

    CreateConstantColorNode(wxPoint(100,100));

    CreateConstantColorNode(wxPoint(250,100));


    /*
      Setup the context menu
    */

    m_contextMenu = new wxMenu();

    m_contextMenu->Append(CONSTANT_COLOR_ITEM_ID, wxT("&Constant Color"));
    Bind(wxEVT_COMMAND_MENU_SELECTED, &TextureGraphPanel::OnCreateConstantColor, this, CONSTANT_COLOR_ITEM_ID);

    m_contextMenu->Append(PERLIN_ITEM_ID, wxT("&Perlin Noise"));
    Bind(wxEVT_COMMAND_MENU_SELECTED, &TextureGraphPanel::OnCreatePerlin, this, PERLIN_ITEM_ID);



    Bind(wxEVT_CONTEXT_MENU, &TextureGraphPanel::OnRightClick, this);
}

void TextureGraphPanel::OnRightClick(wxContextMenuEvent& event) {
    m_contextMenuPosition = ScreenToClient(event.GetPosition());
    PopupMenu(m_contextMenu, m_contextMenuPosition);
}

void TextureGraphPanel::OnCreatePerlin(wxCommandEvent&) {
    CreateConstantColorNode(m_contextMenuPosition);
}

void TextureGraphPanel::OnCreateConstantColor(wxCommandEvent&) {
    CreateConstantColorNode(m_contextMenuPosition);
}

void TextureGraphPanel::SelectNode(int nodeIndex) {

    // unselect the old node.
    if(m_selectedNodeIndex != -1) {
	m_nodes[m_selectedNodeIndex]->Select(false);
    }

    // select the new node.
    if(nodeIndex != m_selectedNodeIndex) {
	m_nodes[nodeIndex]->Select(true);


	// here we populate controls.

    }

    m_selectedNodeIndex = nodeIndex;
}
