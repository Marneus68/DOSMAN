#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <gtkmm/window.h>
#include <gtkmm/headerbar.h>
#include <gtkmm/stack.h>
#include <gtkmm/stackswitcher.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/buttonbox.h>
#include <gtkmm/label.h>

#include <gtkmm/scrolledwindow.h>
#include <gtkmm/flowbox.h>
#include <gtkmm/paned.h>
#include <gtkmm/image.h>
#include <gtkmm/treeview.h>
#include <gtkmm/liststore.h>

#include <map>

#include "EntryManager.h"

namespace dosman {
    class MainWindow : public Gtk::Window
    {
        public:
            MainWindow();
            virtual ~MainWindow();

        protected:
            // Signal Handlers
            void on_open_new_program_dialog();
            void on_open_pref_window();
            void on_quit();

            void update_collection_widget();
            void update_edition_widget();

            unsigned int                    m_entries_num;

            /* EntryManager */
            EntryManager *                  m_entry_manager;

            /* Child Widgets */
            Gtk::HeaderBar                  m_header_bar;
            Gtk::Box                        m_header_box,
                                            m_content_box,
                                            m_collection_box,
                                            m_edition_box;
            Gtk::ButtonBox                  m_edit_buttons_box;
            Gtk::StackSwitcher              m_stack_switcher;
            Gtk::Stack                      m_stack;
            Gtk::Button                     m_edit_add,
                                            m_edit_remove;
            Gtk::ScrolledWindow             m_scrolled_window;
            Gtk::FlowBox                    m_flow_box;
            Gtk::Image                      m_default_image;

            std::map<std::string, Gtk::Button*> m_buttons;
            std::map<std::string, Gtk::Image*>  m_images;


            class ModelColumns : public Gtk::TreeModelColumnRecord {
                public:
                    ModelColumns () { 
                        add(m_col_name);
                    }

                    Gtk::TreeModelColumn<Glib::ustring> m_col_name;
            };

            ModelColumns m_columns;

            Gtk::TreeView                   m_treeview;
            //Gtk::ListStore*                 m_treemodel;
            Glib::RefPtr<Gtk::ListStore> m_reftreemodel;

    }; /* MainWindow */
} /* dosman */

#endif // __MAINWINDOW_H__

