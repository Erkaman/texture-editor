#pragma once

#include <wx/wx.h>
#include <wx/panel.h>

#include <vector>

class TextureGraphNode;

class TextureGraphPanel : public wxPanel
{

private:

    /*
      INSTANCE VARIABLES:
     */
    wxPanel *m_parent;
    wxMenu *m_contextMenu;

    std::vector<TextureGraphNode*> m_nodes;

    wxPoint m_contextMenuPosition;
    int m_selectedNodeIndex;

    void CreateTestNode(const wxPoint& point);

public:
    TextureGraphPanel(wxPanel *parent);

    void SelectNode(int nodeIndex);

    /*
      LISTENERS
     */
    void OnRightClick(wxContextMenuEvent& event);
    void OnCreatePerlin(wxCommandEvent& event);

};
