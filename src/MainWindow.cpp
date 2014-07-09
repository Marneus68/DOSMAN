#include "MainWindow.h"
#include <iostream>

#include <gtkmm/enums.h>

dosman::MainWindow::MainWindow() :
    m_header_box(Gtk::ORIENTATION_HORIZONTAL),
    m_content_box(Gtk::ORIENTATION_VERTICAL),
    m_collection_box(Gtk::ORIENTATION_VERTICAL),
    m_edition_box(Gtk::ORIENTATION_HORIZONTAL),
    m_label_col_empty_title("Nothing to see here !"),
    m_label_col_empty_body("Click here to add your first DOS application to your collection."),
    m_entries_num(0)
{
    set_title("DOSMAN");
    set_border_width(10);
    set_default_size(800,600);

    m_header_bar.set_show_close_button(true);
    m_header_bar.set_title("DOSMAN");

    set_titlebar(m_header_bar);

    m_entry_manager = EntryManager::Initialize();

    // Collection page
    //m_flow_box.set_vexpand(false);
    //m_flow_box.set_hexpand(true);
    m_flow_box.set_homogeneous(true);
    m_flow_box.set_selection_mode(Gtk::SELECTION_NONE);
    m_flow_box.set_resize_mode(Gtk::RESIZE_PARENT);
    m_flow_box.set_halign(Gtk::ALIGN_START);
    m_flow_box.set_valign(Gtk::ALIGN_START);

    m_scrolled_window.add(m_flow_box);

    //m_collection_box.add(m_flow_box);
    m_collection_box.pack_start(m_scrolled_window, true, true);

    update_collection_widget();

    // Edition page
    //m_edition_box.add(m_label_bar);
    m_label_col_empty_title.set_use_markup(true);
    m_label_col_empty_title.set_markup("<big>Nothing to see here !</big>");
    m_edition_box.add(m_label_col_empty_title);

    m_stack.set_transition_type(Gtk::STACK_TRANSITION_TYPE_SLIDE_LEFT_RIGHT);
    m_stack.set_transition_duration(500);

    m_stack.add(m_collection_box, "m_collection_foo", "Collection"); 
    m_stack.add(m_edition_box, "m_edition_bar", "Edition"); // SHOULD BE USING A PANED CONTAINER

    m_stack_switcher.set_stack(m_stack);

    m_header_box.pack_start(m_stack_switcher, true, true, 0);
    m_content_box.pack_start(m_stack, true, true, 0);

    m_header_bar.pack_start(m_header_box);

    add(m_content_box);

    show_all_children(true);
}

dosman::MainWindow::~MainWindow() {}

void dosman::MainWindow::on_open_new_program_dialog() {
    std::cout << "Open the \"New Entry\" wizard" << std::endl;
}

void dosman::MainWindow::on_open_pref_window() {
    std::cout << "Open the preferences window" << std::endl;
}

void dosman::MainWindow::on_quit() {
    hide(); // Quit the app by hiding the main window
}

void dosman::MainWindow::update_collection_widget() {
    if (m_entry_manager->getEntriesCount()) {
        for (EntryMap::const_iterator i = m_entry_manager->getEntryMap()->begin(); i != m_entry_manager->getEntryMap()->end(); ++i) {
            std::cout << i->first << ": " << i->second << std::endl;
            Entry tmp_entry = (Entry) i->second;

            Gtk::Button*    tmp_button = new Gtk::Button();
            Gtk::Image*     tmp_image;
            tmp_button->set_vexpand(false);
            tmp_button->set_hexpand(false);
            if (tmp_entry.containsImage()) {
                tmp_image = new Gtk::Image(tmp_entry.getImagePath());
            } else {
                tmp_image = new Gtk::Image("./img/diskicon.png");
            }
            //tmp_button->set_label(tmp_entry.getName());
            tmp_button->add(*tmp_image);
            tmp_button->set_size_request(128,128);
            m_buttons[tmp_entry.getName()] = tmp_button;
            m_flow_box.add(*m_buttons[tmp_entry.getName()]);
        }
    } else {
        // No entries to show
    }
}

void dosman::MainWindow::update_edition_widget()
{
    if (m_entry_manager->getEntriesCount()) {
        // Entries to show
    } else {
        // No entries to show
    }
}

