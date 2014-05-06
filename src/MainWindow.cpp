#include "MainWindow.h"
#include <iostream>

#include <gtkmm.h>
#include <gtkmm/stock.h>
#include <gtkmm/enums.h>
#include <gtkmm/icontheme.h>

namespace dosman {
    MainWindow::MainWindow() :
        m_header_box(Gtk::ORIENTATION_HORIZONTAL),
        m_content_box(Gtk::ORIENTATION_VERTICAL),
        m_label_foo("collection"),
        m_label_bar("edition")
    {
        set_title("DOSMAN");
        set_border_width(10);
        set_default_size(800,600);

        m_header_bar.set_show_close_button(true);
        m_header_bar.set_title("DOSMAN");

        set_titlebar(m_header_bar);

        m_stack.set_transition_type(Gtk::STACK_TRANSITION_TYPE_SLIDE_LEFT_RIGHT);
        m_stack.set_transition_duration(1000);

        m_stack.add(m_label_foo, "m_label_foo", "Collection");
        m_stack.add(m_label_bar, "m_label_bar", "Edition");

        m_stack_switcher.set_stack(m_stack);

        m_header_box.pack_start(m_stack_switcher, true, true, 0);
        m_content_box.pack_start(m_stack, true, true, 0);

        m_header_bar.pack_start(m_header_box);

        add(m_content_box);

        show_all_children(true);
    }

    MainWindow::~MainWindow() {}

    void MainWindow::on_install_new_program() {
        std::cerr << "Open the \"New Entry\" Wizarp" << std::endl;
    }

    void MainWindow::on_open_pref_window() {
        std::cerr << "Open the preferences window" << std::endl;
    }

    void MainWindow::on_quit() {
        hide(); // Quit the app by hiding the main window
    }
} /* dosman */

