#pragma once

#include <wx/frame.h>

class TextureGraphPanel;
class EditorPanel;
class wxPanel;
class Node;

class MainFrame : public wxFrame
{
public:
    MainFrame(const wxString& title);

    void ShowNodeInEditor(Node* node);

    void UpdateNode(int index);

    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);


    TextureGraphPanel *m_textureGraphPanel;
    EditorPanel *m_editorPanel;
    wxPanel *m_parent;

};
