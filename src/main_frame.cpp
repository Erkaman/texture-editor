#include "main_frame.hpp"

#include "texture_graph_panel.hpp"
#include "editor_panel.hpp"

MainFrame::MainFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxPoint(100,300) /*wxDefaultPosition*/, wxSize(890, 650)) {

    /*
      Make menu bar.
     */
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuHelp, "&Help" );
    SetMenuBar( menuBar );

    /*
      connect events to menubar.
     */
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnAbout, this, wxID_ABOUT);

    /*
      Make panels
     */

    m_parent = new wxPanel(this, wxID_ANY);

    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

    m_lp = new TextureGraphPanel(m_parent, this);
    m_editorPanel = new EditorPanel(m_parent);

    hbox->Add(m_lp, 3, wxEXPAND | wxALL, 0);
    hbox->Add(m_editorPanel, 1, wxEXPAND | wxALL, 0);

    m_parent->SetSizer(hbox);

//    this->Centre();
}

void MainFrame::OnExit(wxCommandEvent& event) {
    Close( true );
}

void MainFrame::OnAbout(wxCommandEvent& event) {
    wxMessageBox( "This is an awesome app",
                  "About Hello World", wxOK | wxICON_INFORMATION );
}
