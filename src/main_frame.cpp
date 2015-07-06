#include "main_frame.hpp"

#include "texture_graph_panel.hpp"
#include "right_panel.hpp"

MainFrame::MainFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(890, 650)) {

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
    Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED,
	    wxCommandEventHandler(MainFrame::OnExit));

    Connect(wxID_ABOUT, wxEVT_COMMAND_MENU_SELECTED,
	    wxCommandEventHandler(MainFrame::OnAbout));


    /*
      Make panels
     */

    m_parent = new wxPanel(this, wxID_ANY);

    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

    m_lp = new TextureGraphPanel(m_parent);
    m_rp = new RightPanel(m_parent);

    hbox->Add(m_lp, 3, wxEXPAND | wxALL, 0);
    hbox->Add(m_rp, 1, wxEXPAND | wxALL, 0);

    m_parent->SetSizer(hbox);

    this->Centre();
}

void MainFrame::OnExit(wxCommandEvent& event) {
    Close( true );
}

void MainFrame::OnAbout(wxCommandEvent& event) {
    wxMessageBox( "This is an awesome app",
                  "About Hello World", wxOK | wxICON_INFORMATION );
}
