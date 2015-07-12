#include "canvas.hpp"

#include <wx/frame.h>
#include <wx/dcclient.h>

Canvas::Canvas(wxWindow *parent) :wxGLCanvas(parent, wxID_ANY,


					    args,
					    wxPoint(100,100), wxSize(100,100), 0, wxT("GLCanvas")){

    m_context = new wxGLContext(this);

    Bind(wxEVT_PAINT, &Canvas::OnPaint, this);

}


Canvas::~Canvas()  { wxDELETE(m_context); }

void Canvas::OnPaint(wxPaintEvent& event) {

    wxGLCanvas::SetCurrent(*m_context);
    wxPaintDC(this); // only to be used in paint events. use wxClientDC to paint outside the paint event


    glViewport(0,0,100, 100);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 1.0f, 0.0f, 1.0f); // Black Background

    glFlush();
    SwapBuffers();
}
