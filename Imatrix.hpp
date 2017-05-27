#ifndef IMATRIX_HPP
#define IMATRIX_HPP


#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>

#include "Ivector.hpp"



class Imatrix : public Fl_Group {

  static const int TH = 30;	// title's height

  static const int BW = 20;	// button's width
  static const int BH = 20;	// button's height

  static const int RS = 20;	// space between rows
  static const int SS = 20;	// space between scalars

  static const int SW = 50;	// width of scalar
  static const int SH = 50;	// height of scalar


public:
  Imatrix(int x, int y, int w, int h, const char *l = 0);

  void add_col();
  void add_row();
  void del_col();
  void del_row();

  static void cb_add_col(Fl_Widget *pw, void *me)  {  ((Imatrix *)me)->add_col();  }
  static void cb_add_row(Fl_Widget *pw, void *me)  {  ((Imatrix *)me)->add_row();  }
  static void cb_del_col(Fl_Widget *pw, void *me)  {  ((Imatrix *)me)->del_col();  }
  static void cb_del_row(Fl_Widget *pw, void *me)  {  ((Imatrix *)me)->del_row();  }


  void set_scalar(unsigned int irow, unsigned int icol, std::string val);
  std::string get_scalar(unsigned int irow, unsigned int icol) const;


  unsigned int count_rows() const;
  unsigned int count_cols() const;

  void redraw_matrix();

private:
  Fl_Box *mybox;
  std::string m_label;

  Fl_Button *b_add_col;
  Fl_Button *b_add_row;
  Fl_Button *b_del_col;
  Fl_Button *b_del_row;

  std::vector<Ivector *> _ivectors;

};


#endif
