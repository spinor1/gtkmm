/* MyWindow.cpp */

#include "MyWindow.h"
#include "MyArea.h"

MyWindow::MyWindow() : m_box(Gtk::ORIENTATION_VERTICAL), m_buttons(Gtk::ORIENTATION_HORIZONTAL),
		m_button1("reset"), m_button2("shrink"), m_button3("left"), m_button4("right"), m_button5("up"), m_button6("down") {
	set_title("Not comfortable...");
	set_default_size(300, 329);
	add(m_box);
	m_box.pack_start(m_buttons, false, true);
	m_buttons.pack_start(m_button1, true, true);
	m_buttons.pack_start(m_button2, true, true);
	m_buttons.pack_start(m_button3, true, true);
	m_buttons.pack_start(m_button4, true, true);
	m_buttons.pack_start(m_button5, true, true);
	m_buttons.pack_start(m_button6, true, true);
	m_button1.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_button1_clicked));
	m_button1.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_button1_clicked));
	m_button1.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_button1_clicked));
	m_button2.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_button2_clicked));
	m_button3.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_button3_clicked));
	m_button4.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_button4_clicked));
	m_button5.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_button5_clicked));
	m_button6.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_button6_clicked));
	m_box.pack_start(m_area);
	show_all_children();
}

MyWindow::~MyWindow() {
}

void MyWindow::on_button1_clicked() {
	m_area.area_reset();
}

void MyWindow::on_button2_clicked() {
	m_area.area_shrink();
}

void MyWindow::on_button3_clicked() {
	m_area.area_left();
}

void MyWindow::on_button4_clicked() {
	m_area.area_right();
}

void MyWindow::on_button5_clicked() {
	m_area.area_up();
}

void MyWindow::on_button6_clicked() {
	m_area.area_down();
}
