#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Gl_Window.H>
#include <GL/gl.h>




class MyGLWindow : public Fl_Gl_Window {
public:
    MyGLWindow(int w, int h) : Fl_Gl_Window(w, h) {
        // Initialize your OpenGL settings here
        mode(FL_RGB | FL_DOUBLE); // Ensure double buffering is enabled
    }

    void draw() override {
        if (!valid()) {
            // Set up your OpenGL context here
            glLoadIdentity();
            // ... other setup code ...
        }

        // Draw your OpenGL scene here
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // ... your drawing code ...
    }
};

int main() {
    MyGLWindow window(800, 600);
    window.show();
    return Fl::run();
}

