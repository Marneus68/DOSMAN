#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <gtkmm/window.h>
#include <gtkmm/headerbar.h>
#include <gtkmm/stack.h>
#include <gtkmm/stackswitcher.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/label.h>

#include "EntryManager.h"

namespace dosman {
    class MainWindow : public Gtk::Window
    {
        public:
            MainWindow();
            virtual ~MainWindow();

        protected:
            // Signal Handlers
            void on_install_new_program();
            void on_open_pref_window();
            void on_quit();

            // Child Widgets
            Gtk::HeaderBar                  m_header_bar;
            Gtk::Box                        m_header_box,
                                            m_content_box;
            Gtk::StackSwitcher              m_stack_switcher;
            Gtk::Stack                      m_stack;

            /* temporary content for switched by the stackswitcher */
            Gtk::Label                      m_label_foo,
                                            m_label_bar;
    }; /* MainWindow */
} /* dosman */

#endif // __MAINWINDOW_H__

