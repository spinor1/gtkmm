/* MyArea.cpp */

#include "MyArea.h"
#include <complex>
#include <iostream>
using namespace std;

MyArea::MyArea() : x_min {-1.5}, x_max { 0.5}, y_min {-1.0}, y_max { 1.0},
				   x_press {0.0}, y_press {0.0}, x_release {0.0}, y_release {0.0}
{
	add_events( Gdk::BUTTON_PRESS_MASK | Gdk::BUTTON_RELEASE_MASK );
}

MyArea::~MyArea() {
}

void MyArea::area_reset() {
	x_min = -1.5;
	x_max =  0.5;
	y_min = -1.0;
	y_max =  1.0;
	get_window()->invalidate(true);
}

void MyArea::area_shrink() {
	double xc = (x_min + x_max) / 2.0;
	double yc = (y_min + y_max) / 2.0;
	double xs = (x_max - xc) / 0.67;
	double ys = (y_max - yc) / 0.67;
	x_min = xc - xs;
	x_max = xc + xs;
	y_min = yc - ys;
	y_max = yc + ys;
	get_window()->invalidate(true);
}

void MyArea::area_left() {
	double xc = (x_min + x_max) / 2.0;
	double xs = (x_max - xc) * 0.67;
	x_min += xs;
	x_max += xs;
	get_window()->invalidate(true);
}

void MyArea::area_right() {
	double xc = (x_min + x_max) / 2.0;
	double xs = (x_max - xc) * 0.67;
	x_min -= xs;
	x_max -= xs;
	get_window()->invalidate(true);
}

void MyArea::area_up() {
	double yc = (y_min + y_max) / 2.0;
	double ys = (y_max - yc) * 0.67;
	y_min += ys;
	y_max += ys;
	get_window()->invalidate(true);
}

void MyArea::area_down() {
	double yc = (y_min + y_max) / 2.0;
	double ys = (y_max - yc) * 0.67;
	y_min -= ys;
	y_max -= ys;
	get_window()->invalidate(true);
}

bool MyArea::on_button_press_event( GdkEventButton* event )
{
    std::cout << "pressed:  " << event->x << " : " << event->y << std::endl;
    x_press = event->x;
    y_press = event->y;
    return true;
}

bool MyArea::on_button_release_event( GdkEventButton* event )
{
    std::cout << "released: " << event->x << " : " << event->y << std::endl;
    x_release = event->x;
    y_release = event->y;
	get_window()->invalidate(true);
    return true;
}

bool MyArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
  Gtk::Allocation allocation = get_allocation();
  const int width  = allocation.get_width();
  const int height = allocation.get_height();
  if(x_press != x_release && y_press != y_release) {
	  double x_min_new = x_min + (x_max - x_min) * ( x_press   / (double) width );
	  double x_max_new = x_min + (x_max - x_min) * ( x_release / (double) width );
	  x_min = x_min_new;
	  x_max = x_max_new;
	  double y_min_new = y_min + (y_max - y_min) * ( y_press   / (double) height );
	  double y_max_new = y_min + (y_max - y_min) * ( y_release / (double) height );
	  y_min = y_min_new;
	  y_max = y_max_new;
	  x_press = y_press = x_release = y_release = 0.0;
  }
  cout << "MyArea: width = " << width << ", height = " << height
       << ", (" << x_min << ", " << y_min << ") ----> (" << x_max << ", " << y_max << ") \n";

  cr->set_line_width(1.0);

  double large = 100.0;
  int    kmax  =  50;

  for(int i=0;i<width;i++) {
	  for(int j=0;j<height;j++) {
		  double x=x_min+(x_max-x_min)*(double)i/(double)width;
		  double y=y_min+(y_max-y_min)*(double)j/(double)height;
		  complex<double> z=0.0;
		  complex<double> w=complex<double>(x,y);
		  int count=0;
		  for(int k=0;k<kmax;k++) {
			  z=z*z+w;
			  if(abs(z)>large) {
				  count = k;
				  break;
			  }
		  }
		  if(count) {
			  cr->set_source_rgba(0.3,(count%10)/10.0,0.8,1.0);
		  } else {
			  cr->set_source_rgba(0.0,0.2,0.7,1.0);
		  }
		  cr->rectangle((double)i, (double)j, 1.0, 1.0);
		  cr->stroke();
	  }
  }
  return true;
}
