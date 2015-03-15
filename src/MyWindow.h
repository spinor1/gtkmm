/* MyWindow.h */

#ifndef MYWINDOW_H_
#define MYWINDOW_H_

#include "MyArea.h"
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>

class MyWindow : public Gtk::Window {
public:
	MyWindow();
	virtual ~MyWindow();
protected:
	void on_button1_clicked();
	void on_button2_clicked();
	void on_button3_clicked();
	void on_button4_clicked();
	void on_button5_clicked();
	void on_button6_clicked();
private:
	Gtk::Box    m_box;
	Gtk::Box    m_buttons;
	Gtk::Button m_button1;
	Gtk::Button m_button2;
	Gtk::Button m_button3;
	Gtk::Button m_button4;
	Gtk::Button m_button5;
	Gtk::Button m_button6;
	MyArea      m_area;
};

#endif /* MYWINDOW_H_ */
