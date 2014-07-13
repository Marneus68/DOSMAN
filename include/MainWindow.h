#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <gtkmm/window.h>
#include <gtkmm/headerbar.h>
#include <gtkmm/stack.h>
#include <gtkmm/stackswitcher.h>
#include <gtkmm/box.h>
#include <gtkmm/bin.h>
#include <gtkmm/frame.h>
#include <gtkmm/button.h>
#include <gtkmm/entry.h>
#include <gtkmm/radiobutton.h>
#include <gtkmm/filechooserdialog.h>
#include <gtkmm/checkbutton.h>
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
            void on_add_new_entry();
            void on_remove_selected_entry();
            void on_quit();
            void on_row_selected();

            void on_save_edited_entry();
            void on_run_edited_entry();

            void on_create_button_clicked();

            void on_select_folder();

            void update_collection_widget();
            void update_edition_widget();

            unsigned int                    m_entries_num;

            bool    editwindowvisited,
                    new_entry_is_valid;
            std::string new_entry_name,
                        new_entry_path;

            /* EntryManager */
            EntryManager *                  m_entry_manager;

            /* Child Widgets */
            Gtk::HeaderBar                  m_header_bar;
            Gtk::Box                        m_header_box,
                                            m_content_box,
                                            m_collection_box,
                                            m_edition_box,
                                            m_edition_entry_box,
                                            m_entry_frame_box;
            Gtk::HPaned                     m_edition_panned;
            Gtk::ButtonBox                  m_edit_buttons_box,
                                            m_edit_save_run_box;
            Gtk::StackSwitcher              m_stack_switcher;
            Gtk::Stack                      m_stack;
            Gtk::Button                     m_edit_add,
                                            m_edit_remove,
                                            m_edit_save,
                                            m_edit_run;
            Gtk::ScrolledWindow             m_scrolled_window,
                                            m_edit_entry;
            Gtk::FlowBox                    m_flow_box;

            /* content of the edition wndow */
            Gtk::Label                      m_entry_title;

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
            Glib::RefPtr<Gtk::ListStore> m_reftreemodel;

            // Widgets for the entry configuration 
            Gtk::Frame                      m_entry_frame,
                                            m_sdl_frame,
                                            m_dosbox_frame,
                                            m_render_frame,
                                            m_cpu_frame,
                                            m_mixer_frame,
                                            m_midi_frame,
                                            m_sblaster_frame,
                                            m_gus_frame,
                                            m_speaker_frame;
            Gtk::ButtonBox                  m_entry_button_box;
            Gtk::Button                     m_entry_select_executable,
                                            m_entry_select_setup;
            Gtk::Image                      m_entry_image;
            Gtk::HBox                       m_entry_box;
            Gtk::VBox                       m_sdl_box,
                                            m_render_box;
            Gtk::FlowBox                    m_rb_machine_box,
                                            m_rb_scaler_box,
                                            m_rb_output_box;
            Gtk::RadioButton::Group         m_rb_machine_group,
                                            m_rb_scaler_group,
                                            m_rb_output_group;

            Gtk::RadioButton                m_rb_machine_hercules,
                                            m_rb_machine_cga,
                                            m_rb_machine_tandy,
                                            m_rb_machine_pcjr,
                                            m_rb_machine_ega,
                                            m_rb_machine_vgaonly,
                                            m_rb_machine_svga_s3,

                                            m_rb_scaler_none,
                                            m_rb_scaler_normal2x,
                                            m_rb_scaler_normal3x,
                                            m_rb_scaler_tv2x,
                                            m_rb_scaler_tv3x,
                                            m_rb_scaler_rgb2x,
                                            m_rb_scaler_rgb3x,
                                            m_rb_scaler_scan2x,
                                            m_rb_scaler_scan3x,

                                            m_rb_output_surface,
                                            m_rb_output_overlay,
                                            m_rb_output_opengl,
                                            m_rb_output_openglnb;

            Gtk::CheckButton                m_cb_sdl_fullscreen,
                                            m_cb_autolock,
                                            m_cb_render_aspect,
                                            m_cb_nosound;

            Gtk::Window *                   new_window;
            Gtk::Entry *                    entry;

    }; /* MainWindow */
} /* dosman */

#endif // __MAINWINDOW_H__

