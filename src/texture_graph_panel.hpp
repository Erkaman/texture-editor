#pragma once

#include <wx/panel.h>

#include <wx/vector.h>

class TextureGraphNode;
class MainFrame;

class TextureGraphPanel : public wxPanel
{

private:

    /*
      INSTANCE VARIABLES:
     */
    wxMenu *m_contextMenu;
    MainFrame* m_mainFrame;

    wxVector<TextureGraphNode*> m_nodes;

    wxPoint m_contextMenuPosition;
    int m_selectedNodeIndex;

    void CreateConstantColorNode(const wxPoint& point);

public:
    TextureGraphPanel(wxPanel *parent, MainFrame* mainFrame);

    void SelectNode(int nodeIndex);

    void UpdateNode(int index);

    /*
      LISTENERS
     */
    void OnRightClick(wxContextMenuEvent& event);

    void OnCreatePerlin(wxCommandEvent&);
    void OnCreateConstantColor(wxCommandEvent&);

};
