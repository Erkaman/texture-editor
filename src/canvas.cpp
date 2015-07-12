#include "canvas.hpp"

#include <wx/frame.h>
#include <wx/dcclient.h>

#define OPENGL_ALREADY_INCLUDED
#include <ewa/gl/fbo.hpp>
#include <ewa/gl/vao.hpp>


Canvas::Canvas(wxWindow *parent) :wxGLCanvas(parent, wxID_ANY,


					    args,
					     wxPoint(100,100), wxSize(100,100), 0, wxT("GLCanvas")), m_initialized(false){

    m_context = new wxGLContext(this);

    Bind(wxEVT_PAINT, &Canvas::OnPaint, this);



    Paint();
}


Canvas::~Canvas()  { wxDELETE(m_context); }

void Canvas::OnPaint(wxPaintEvent&) {
    Paint();
}

void Canvas::Paint() {

    wxGLCanvas::SetCurrent(*m_context);
    wxPaintDC(this); // only to be used in paint events. use wxClientDC to paint outside the paint event

    if(!m_initialized) {

	glewExperimental = GL_TRUE;
	glewInit();


	new FBO(10,100,100);


	m_initialized = true;
    }


//    new FBO(10, 100,100);

    glViewport(0,0,100, 100);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 1.0f, 0.0f, 1.0f); // Black Background

    glFlush();
    SwapBuffers();
}
