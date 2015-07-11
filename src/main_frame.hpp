#pragma once

#include <wx/wx.h>

class TextureGraphPanel;
class EditorPanel;
class wxPanel;

class MainFrame : public wxFrame
{
public:
    MainFrame(const wxString& title);

    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    TextureGraphPanel *m_lp;
    EditorPanel *m_editorPanel;
    wxPanel *m_parent;

};
