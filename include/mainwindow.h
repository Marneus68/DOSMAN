#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/uimanager.h>

namespace dosman {
    class MainWindow : public Gtk::Window
    {
        public:
            MainWindow();
            virtual ~MainWindow();

        protected:
            void on_install_new_program();
            void on_appmenu();
            void on_quit();

            // Child Widgets
            Gtk::Box        m_box;
            Glib::RefPtr<Gtk::UIManager> m_refUIManager;
            Glib::RefPtr<Gtk::ActionGroup> m_refActionGroup;
    }; /* MainWindow */
} /* dosman */

#endif // __MAINWINDOW_H__

