#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_draw.H>

class MyWindow : public Fl_Window {
public:
    MyWindow(int w, int h) : Fl_Window(w, h) {
        // Add any initialization code here
        end(); // End window setup
    }

    void draw() override {
        Fl_Window::draw(); // Draw the window’s background

        // Draw a red square using FLTK functions
        fl_draw_box(FL_FLAT_BOX, 350, 250, 100, 100, FL_RED);
    }
};

int main() {
    MyWindow window(800, 600);
    window.show();
    return Fl::run();
}

