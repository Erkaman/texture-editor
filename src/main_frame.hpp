#pragma once

#include <wx/wx.h>

class TextureGraphPanel;
class RightPanel;
class wxPanel;

class MainFrame : public wxFrame
{
public:
    MainFrame(const wxString& title);

    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    TextureGraphPanel *m_lp;
    RightPanel *m_rp;
    wxPanel *m_parent;

};
