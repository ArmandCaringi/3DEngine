#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Gl_Window.H>
#include <GL/gl.h>
#include <GL/glu.h>

class MyGLWindow : public Fl_Gl_Window {
public:
    MyGLWindow(int x, int y, int w, int h, const char* l = 0) 
        : Fl_Gl_Window(x, y, w, h, l) 
    {
        double_buffer(true);
    }

    void draw() override {
        if (!valid()) {
            glLoadIdentity();
            gluPerspective(45.0, (double)w() / (double)h(), 1.0, 100.0);
            glClearColor(0.0, 0.0, 0.0, 1.0);
            glEnable(GL_DEPTH_TEST);
        }
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Render your scene here

        swap_buffers();
    }
};

int main() {
    Fl_Window window(800, 600, "3D Engine with FLTK");
    MyGLWindow glWindow(0, 0, 800, 600);
    window.end();
    window.show();
    return Fl::run();
}

