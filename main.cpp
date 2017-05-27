#include <FL/Fl.H>
#include <FL/Fl_Window.H>

#include "Imatrix.hpp"


int main() {

  Fl_Window *win1 = new Fl_Window(1500, 800, "my window");

  Imatrix *ig = new Imatrix(0, 0, 500, 500, "grid");

  win1->end();
  win1->show();

  return Fl::run();
}




//position(200, 250);

//   //in->position(200, 200);
//   ((Fl_Window *)win)->redraw();
// }
// b_del->callback(b_del_callback, win1);
// Fl_Input *in1 = new Fl_Input(100, 200, 80, 20, "Scalar");
// in1->value("31/5");



// static void in_callback(Fl_Widget *b_add, void *win) {
//   //in->position(200, 200);
//   ((Fl_Window *)win)->redraw();
// }
// group->resize(x, y, width, height);
