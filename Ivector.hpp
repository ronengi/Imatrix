#ifndef IVECTOR_HPP
#define IVECTOR_HPP


#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <vector>
#include <sstream>
#include <stdexcept>


class Ivector : public Fl_Group {

public:
  Ivector(int x, int y, int w, int h, int SW, int SH, int SS);

  int count_scalars() const;

  std::string get_scalar(unsigned int icol) const;

  void set_scalar(unsigned int icol, std::string val);

  void add_scalar();
  void del_scalar();

  void scalar_changed(Fl_Widget *pw) {  ((Fl_Input *)pw)->value("changed!");  }
  static void cb_scalar_changed(Fl_Widget *pw, void *me)  {  ((Ivector *)me)->scalar_changed(pw);  }


private:
  std::vector<Fl_Input *> _iscalars;

  int _SW;			// width of Scalar input
  int _SH;			// height of Scalar input
  int _SS;			// space between Scalar inputs
};




#endif
