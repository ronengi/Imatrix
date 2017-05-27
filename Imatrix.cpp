#include "Imatrix.hpp"

//#include <sstream>


Imatrix::Imatrix(int x, int y, int w, int h, const char *l)
  : Fl_Group(x, y, w, h, NULL),
    mybox(new Fl_Box(x, y, w, h, NULL)),

    b_del_col(new Fl_Button(x + BW, y + TH, BW, BH, "-")),
    b_add_col(new Fl_Button(x + BW + SS + SW + SS, y + TH, BW, BH, "+")),

    b_del_row(new Fl_Button(x, y + TH + BH, BW, BH, "-")),
    b_add_row(new Fl_Button(x, y + TH + BH + RS, BW, BH, "+"))

{

  clip_children(1);

  mybox->box(FL_BORDER_BOX);
  mybox->align(FL_ALIGN_INSIDE + FL_ALIGN_TOP);
  // mybox->labeltype(FL_SHADOW_LABEL);
  // mybox->labelfont(FL_BOLD+FL_ITALIC);
  // mybox->labelsize(36);

  // b_add_col->shortcut(FL_ALT + FL_Right);
  // b_add_row->shortcut(FL_Down);
  // b_del_col->shortcut(FL_Left);
  // b_del_row->shortcut(FL_Up);
  b_add_col->shortcut('d');
  b_add_row->shortcut('s');
  b_del_col->shortcut('a');
  b_del_row->shortcut('w');


  // b_add_col->clear_visible_focus();
  // b_add_row->clear_visible_focus();
  // b_del_col->clear_visible_focus();
  // b_del_row->clear_visible_focus();


  b_add_col->callback(cb_add_col, (void *)this);
  b_add_row->callback(cb_add_row, (void *)this);
  b_del_col->callback(cb_del_col, (void *)this);
  b_del_row->callback(cb_del_row, (void *)this);



  add_row();

}



void Imatrix::add_col() {
  if (_ivectors.size() == 0)
    return;

  for (int i = 0; i < _ivectors.size(); ++i)
    _ivectors[i]->add_scalar();

  b_add_col->position(b_add_col->x() + SW + SS, b_add_col->y());

  redraw_matrix();
}

void Imatrix::add_row() {
  int x1 = x() + BW + SS;
  int y1 = y() + TH + BH + RS + _ivectors.size() * ( SH + RS );

  Ivector *iv = new Ivector(x1, y1, w() - x1, h() - y1, SW, SH, SS);
  add(iv);
  _ivectors.push_back(iv);

  if (_ivectors.size() > 1) {
    for (int cols = 0; cols < _ivectors[0]->count_scalars(); ++cols)
      iv->add_scalar();
  }
  else
    iv->add_scalar();


  b_add_row->position(b_add_row->x(), b_add_row->y() + SH + RS);

  redraw_matrix();
}

void Imatrix::del_col() {
  if ( (_ivectors.size() == 0)  ||  (_ivectors[0]->count_scalars() < 2) )
    return;

  for (int row = 0; row < _ivectors.size(); ++row)
    _ivectors[row]->del_scalar();

  b_add_col->position(b_add_col->x() - SW - SS, b_add_col->y());

  redraw_matrix();
}

void Imatrix::del_row() {
  if (_ivectors.size() < 2)
    return;

  Ivector *pv = _ivectors.back();

  int cols = pv->count_scalars();
  for (int i = 0; i < cols; ++i)
      pv->del_scalar();

  remove(pv);
  Fl::delete_widget(pv);

  _ivectors.pop_back();


  b_add_row->position(b_add_row->x(), b_add_row->y() - SH - RS);

  redraw_matrix();
}


void Imatrix::set_scalar(unsigned int irow, unsigned int icol, std::string val) {
  if (_ivectors.size() <= irow)
    throw std::runtime_error("there is no such row");

  _ivectors[irow]->set_scalar(icol, val.c_str());
}

std::string Imatrix::get_scalar(unsigned int irow, unsigned int icol) const {
  if (_ivectors.size() <= irow)
    throw std::runtime_error("there is no such row");

  std::stringstream ss;
  ss << _ivectors[irow]->get_scalar(icol);
  //ss << "(" << _ivectors[irow]->get_scalar(icol) << ")";

  return ss.str();
}


unsigned int Imatrix::count_rows() const {
  return _ivectors.size();
}
unsigned int Imatrix::count_cols() const {
  return (_ivectors.size() > 0) ? _ivectors[0]->count_scalars() : 0;
}

void Imatrix::redraw_matrix() {

  std::stringstream ss;
  ss << "A (" << count_rows() << ", " << count_cols() << ")";
  m_label = ss.str();
  mybox->label(m_label.c_str());

  redraw();

  current(this->parent());
}



//current(this);
// current(this->parent());
// clip children(1);
// draw_children();
// redraw();
//Fl_Widget::window()->redraw();
