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


    std::vector<TextureGraphNode*> nodes;

    wxPoint contextMenuPosition;

public:
    TextureGraphPanel(wxPanel *parent);

    void OnRightClick(wxContextMenuEvent& event);
    void OnCreatePerlin(wxCommandEvent& event);


};
