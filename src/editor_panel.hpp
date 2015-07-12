#pragma once

#include <wx/panel.h>

class Node;
class MainFrame;
class wxBoxSizer;

/*
we should probably use a ewxScrolledWindow  to contain the controls  here.


 */

class EditorPanel : public wxPanel{

private:

    wxButton* oldButton1;
    wxButton* oldButton2;

    MainFrame* m_mainFrame;

    Node* m_currentNode;

    wxBoxSizer* m_content;

public:
    EditorPanel(wxPanel *parent, MainFrame* mainFrame);

    void ShowNode(Node* node);

    void OnEvent(wxEvent & evt);

    void OnArgUpdate();
};
