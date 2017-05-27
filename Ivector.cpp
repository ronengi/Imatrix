#include "Ivector.hpp"



Ivector::Ivector(int x, int y, int w, int h, int SW, int SH, int SS)
  : Fl_Group(x, y, w, h, NULL),
    _SW(SW), _SH(SH), _SS(SS) {}



int Ivector::count_scalars() const {
  return _iscalars.size();
}


std::string Ivector::get_scalar(unsigned int icol) const {
  if (_iscalars.size() <= icol)
    throw std::runtime_error("there is no such column");

  std::stringstream ss;
  ss << _iscalars[icol]->value();
  //ss << "(" << _iscalars[icol]->value() << ")";

  return ss.str();
}

void Ivector::set_scalar(unsigned int icol, std::string val) {
  if (_iscalars.size() <= icol)
    throw std::runtime_error("there is no such column");

  // std::stringstream ss;
  // ss << val;
  // _iscalars[icol]->value(ss.str().c_str());

  _iscalars[icol]->value(val.c_str());
}


void Ivector::add_scalar() {
  int x1 = x() + _iscalars.size() * ( _SW + _SS );
  int y1 = y();

  Fl_Input *ps = new Fl_Input(x1, y1, _SW, _SH, NULL);
  ps->value("0");
  ps->when(FL_WHEN_CHANGED);
  ps->callback(cb_scalar_changed, (void *)this);
  add(ps);
  _iscalars.push_back(ps);

  current(this->parent());
}

void Ivector::del_scalar() {
  if (_iscalars.size() == 0)
    return;

  remove(_iscalars.back());
  Fl::delete_widget(_iscalars.back());

  _iscalars.pop_back();

  current(this->parent());
}

