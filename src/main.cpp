#include <FL/Fl.H>
#include <FL/Fl_Gl_Window.H>
#include <GL/gl.h>
#include <GL/glu.h>

class My3DWindow : public Fl_Gl_Window {
public:
    My3DWindow(int w, int h) : Fl_Gl_Window(w, h), rotation(0.0f) {
        mode(FL_RGB | FL_DOUBLE | FL_DEPTH); // Enable RGB color, double buffering, and depth buffering
        Fl::add_timeout(1.0 / 100.0, TimerCallback, this); // Set up a timer callback
    }

    void draw() override {
        if (!valid()) {
            // Initialize OpenGL settings
            glEnable(GL_DEPTH_TEST);
            glShadeModel(GL_FLAT);
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black
            glMatrixMode(GL_PROJECTION);
            gluPerspective(45.0f, (float)w() / (float)h(), 0.1f, 100.0f); // Set perspective projection
            glMatrixMode(GL_MODELVIEW);
            valid(1);
        }

        // Clear the color and depth buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Set up the camera
        glLoadIdentity();
        glTranslatef(0.0f, 0.0f, -5.0f); // Move back along the z-axis

        // Rotate the cube
        glRotatef(rotation, 1.0f, 1.0f, 0.0f);

        // Draw the cube
        glBegin(GL_QUADS);
            // Front face
            glColor3f(1.0f, 0.0f, 0.0f); // Red
            glVertex3f(-1.0f, -1.0f,  1.0f);
            glVertex3f( 1.0f, -1.0f,  1.0f);
            glVertex3f( 1.0f,  1.0f,  1.0f);
            glVertex3f(-1.0f,  1.0f,  1.0f);

            // Back face
            glColor3f(0.0f, 1.0f, 0.0f); // Green
            glVertex3f(-1.0f, -1.0f, -1.0f);
            glVertex3f(-1.0f,  1.0f, -1.0f);
            glVertex3f( 1.0f,  1.0f, -1.0f);
            glVertex3f( 1.0f, -1.0f, -1.0f);

            // Top face
            glColor3f(0.0f, 0.0f, 1.0f); // Blue
            glVertex3f(-1.0f,  1.0f, -1.0f);
            glVertex3f(-1.0f,  1.0f,  1.0f);
            glVertex3f( 1.0f,  1.0f,  1.0f);
            glVertex3f( 1.0f,  1.0f, -1.0f);

            // Bottom face
            glColor3f(1.0f, 1.0f, 0.0f); // Yellow
            glVertex3f(-1.0f, -1.0f, -1.0f);
            glVertex3f( 1.0f, -1.0f, -1.0f);
            glVertex3f( 1.0f, -1.0f,  1.0f);
            glVertex3f(-1.0f, -1.0f,  1.0f);

            // Right face
            glColor3f(1.0f, 0.0f, 1.0f); // Magenta
            glVertex3f( 1.0f, -1.0f, -1.0f);
            glVertex3f( 1.0f,  1.0f, -1.0f);
            glVertex3f( 1.0f,  1.0f,  1.0f);
            glVertex3f( 1.0f, -1.0f,  1.0f);

            // Left face
            glColor3f(0.0f, 1.0f, 1.0f); // Cyan
            glVertex3f(-1.0f, -1.0f, -1.0f);
            glVertex3f(-1.0f, -1.0f,  1.0f);
            glVertex3f(-1.0f,  1.0f,  1.0f);
            glVertex3f(-1.0f,  1.0f, -1.0f);
        glEnd();

        // Swap buffers
        swap_buffers();
    }

    void update() {
        rotation += 0.5f; // Update rotation angle
        if (rotation > 360.0f) rotation -= 360.0f;
        redraw(); // Request a redraw to update the window
    }

private:
    float rotation; // Rotation angle of the cube

    static void TimerCallback(void* userdata) {
        My3DWindow* win = static_cast<My3DWindow*>(userdata);
        win->update();
        Fl::repeat_timeout(1.0 / 60.0, TimerCallback, userdata); // Set up the next timer callback
    }
};

int main() {
    My3DWindow window(800, 600);
    window.show();
    return Fl::run();
}

