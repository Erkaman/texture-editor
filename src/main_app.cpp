#include "main_frame.hpp"

class MainApp : public wxApp
{
  public:
    virtual bool OnInit();
};

IMPLEMENT_APP(MainApp)

bool MainApp::OnInit()
{
    ::wxInitAllImageHandlers();


    MainFrame *mainFrame = new MainFrame(wxT("An Awesome app!"));
    mainFrame->Show(true);



    return true;
}
