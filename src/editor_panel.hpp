#pragma once

#include <wx/panel.h>

class Node;

/*
we should probably use a ewxScrolledWindow  to contain the controls  here.


 */

class EditorPanel : public wxPanel{

private:

    wxButton* oldButton1;
    wxButton* oldButton2;

public:
    EditorPanel(wxPanel *parent);

    void ShowNode(Node* node);

    void OnEvent(wxEvent & evt);
};
