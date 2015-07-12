#pragma once

#include <GL/glew.h>
#include <wx/glcanvas.h>

class wxGLContext;

class Canvas: public wxGLCanvas {


private:

    int args[5] = {WX_GL_RGBA, WX_GL_DOUBLEBUFFER, WX_GL_DEPTH_SIZE, 16, 0};

     wxGLContext*	m_context;

    void OnPaint(wxPaintEvent&);
    void Paint();

    bool m_initialized;

public:

    Canvas(wxWindow* parent);
    ~Canvas();



};
