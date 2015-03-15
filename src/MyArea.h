/* MyArea.h */

#ifndef MYAREA_H_
#define MYAREA_H_

#include <gtkmm/drawingarea.h>

class MyArea : public Gtk::DrawingArea
{
public:
  MyArea();
  virtual ~MyArea();
  void area_reset();
  void area_shrink();
  void area_left();
  void area_right();
  void area_up();
  void area_down();
protected:
  virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);
  virtual bool on_button_press_event  ( GdkEventButton* event );
  virtual bool on_button_release_event( GdkEventButton* event );
private:
  double x_min;
  double x_max;
  double y_min;
  double y_max;
  double x_press;
  double y_press;
  double x_release;
  double y_release;
};

#endif /* MYAREA_H_ */
