#pragma once

#include <wx/wx.h>
#include <wx/panel.h>

class TextureGraphNode;

class TextureGraphPanel : public wxPanel
{
public:
    TextureGraphPanel(wxPanel *parent);



    wxPanel *m_parent;
    TextureGraphNode* node;
};
