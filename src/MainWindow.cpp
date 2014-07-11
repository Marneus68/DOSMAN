#include "MainWindow.h"
#include <iostream>

#include <gtkmm/stock.h>
#include <gtkmm/enums.h>

dosman::MainWindow::MainWindow() :
    m_header_box(Gtk::ORIENTATION_HORIZONTAL),
    m_content_box(Gtk::ORIENTATION_VERTICAL),
    m_collection_box(Gtk::ORIENTATION_VERTICAL),
    m_edition_box(Gtk::ORIENTATION_VERTICAL),
    m_edition_entry_box(Gtk::ORIENTATION_VERTICAL),
    m_edit_buttons_box(Gtk::ORIENTATION_HORIZONTAL),
    m_edit_save_run_box(Gtk::ORIENTATION_HORIZONTAL),
    m_entries_num(0),
    m_edit_add(Gtk::Stock::ADD),
    m_edit_remove(Gtk::Stock::REMOVE),
    m_edit_save("Save"),
    m_edit_run("Run")
{
    set_title("DOSMAN");
    set_border_width(10);
    set_default_size(800,600);

    m_header_bar.set_show_close_button(true);
    m_header_bar.set_title("DOSMAN");

    set_titlebar(m_header_bar);

    m_entry_manager = EntryManager::Initialize();

    /* Collection page */
    m_flow_box.set_homogeneous(true);
    m_flow_box.set_selection_mode(Gtk::SELECTION_NONE);
    m_flow_box.set_resize_mode(Gtk::RESIZE_PARENT);
    m_flow_box.set_halign(Gtk::ALIGN_START);
    m_flow_box.set_valign(Gtk::ALIGN_START);

    m_scrolled_window.add(m_flow_box);
    
    m_collection_box.pack_start(m_scrolled_window, true, true);

    update_collection_widget();

    /* end of Collection page */

    /* Edition page */
    m_reftreemodel = Gtk::ListStore::create(m_columns);
    m_treeview.set_model(m_reftreemodel);
    m_treeview.append_column("Name", m_columns.m_col_name);

    m_treeview.signal_cursor_changed().connect(sigc::mem_fun(*this,
              &MainWindow::on_row_selected) );

    m_edit_buttons_box.pack_start(m_edit_remove);
    m_edit_buttons_box.pack_start(m_edit_add);

    m_edit_add.signal_clicked().connect( sigc::mem_fun(*this, 
            &MainWindow::on_add_new_entry));
    m_edit_remove.signal_clicked().connect( sigc::mem_fun(*this, 
            &MainWindow::on_remove_selected_entry));
    m_edit_run.signal_clicked().connect( sigc::mem_fun(*this, 
            &MainWindow::on_run_edited_entry));
    m_edit_save.signal_clicked().connect( sigc::mem_fun(*this, 
            &MainWindow::on_save_edited_entry));

    m_edit_buttons_box.set_layout(Gtk::BUTTONBOX_EXPAND);

    m_edition_box.pack_start(m_treeview);
    m_edition_box.pack_start(m_edit_buttons_box, Gtk::PACK_SHRINK);

    m_edition_panned.pack1(m_edition_box, Gtk::SHRINK);
    m_edition_panned.add2(m_edition_entry_box);

    m_edit_save_run_box.pack_end(m_edit_run, Gtk::PACK_SHRINK, 10);
    m_edit_save_run_box.pack_end(m_edit_save, Gtk::PACK_SHRINK, 10);

    m_edit_save_run_box.set_layout(Gtk::BUTTONBOX_END);

    m_edition_entry_box.pack_start(m_edit_entry, Gtk::PACK_EXPAND_WIDGET);
    m_edition_entry_box.pack_end(m_edit_save_run_box, Gtk::PACK_SHRINK);

    m_edit_entry.add(m_entry_title);

    update_edition_widget();

    /* end of edition page */

    m_stack.set_transition_type(Gtk::STACK_TRANSITION_TYPE_SLIDE_LEFT_RIGHT);
    m_stack.set_transition_duration(500);

    m_stack.add(m_collection_box, "m_collection_foo", "Collection"); 
    m_stack.add(m_edition_panned, "m_edition_bar", "Edition");

    m_stack_switcher.set_stack(m_stack);

    m_header_box.pack_start(m_stack_switcher, true, true, 0);
    m_content_box.pack_start(m_stack, true, true, 0);

    m_header_bar.pack_start(m_header_box);

    add(m_content_box);

    show_all_children(true);
}

dosman::MainWindow::~MainWindow() {}

void dosman::MainWindow::on_add_new_entry() {
    std::cout << "Create a new Entry" << std::endl;
    Gtk::Button* useless = new Gtk::Button("lol");
    useless->set_vexpand(true);
    useless->set_hexpand(true);
    useless->set_size_request(128,128);
    m_flow_box.add(*useless);
    m_flow_box.show_all();
}

void dosman::MainWindow::on_remove_selected_entry() {
    Glib::RefPtr<Gtk::TreeSelection> selection = m_treeview.get_selection();
    Gtk::TreeModel::iterator selectedRow = selection->get_selected();
    Gtk::TreeModel::Row row = *selectedRow;
    Glib::ustring port = row.get_value(m_columns.m_col_name);
    std::cout << "Deleting " << port.data() << std::endl;

    std::string tmp_key(port.data());
    if (tmp_key.compare("") == 0)  return;
    m_flow_box.remove(*m_buttons[tmp_key.c_str()]);
    m_flow_box.show_all();
}

void dosman::MainWindow::on_quit() {
    hide(); // Quit the app by hiding the main window
}

void dosman::MainWindow::on_row_selected()
{
    Glib::RefPtr<Gtk::TreeSelection> selection = m_treeview.get_selection();
    Gtk::TreeModel::iterator selectedRow = selection->get_selected();
    Gtk::TreeModel::Row row = *selectedRow;
    Glib::ustring port = row.get_value(m_columns.m_col_name);

    std::string tmp_key(port.data());
    if (tmp_key.compare("") == 0)  return;
    m_entry_title.set_text(tmp_key);
}

void dosman::MainWindow::on_run_edited_entry()
{
    Glib::RefPtr<Gtk::TreeSelection> selection = m_treeview.get_selection();
    Gtk::TreeModel::iterator selectedRow = selection->get_selected();
    Gtk::TreeModel::Row row = *selectedRow;
    Glib::ustring port = row.get_value(m_columns.m_col_name);

    std::string tmp_key(port.data());
    if (tmp_key.compare("") == 0)  return;
    m_entry_manager->getEntryMap()->at(tmp_key.c_str()).run();
}

void dosman::MainWindow::on_save_edited_entry()
{
    std::cout << "Let's save" << std::endl;
}

void dosman::MainWindow::update_collection_widget() {
    
    // clear the content of the m_flow_box, m_buttons, m_images and repopulate it
    // according to the content of the EntryManager

    for (std::map<std::string, Gtk::Button*>::const_iterator i = m_buttons.begin(); i != m_buttons.end(); ++i) {
        delete i->second; 
    }
    m_buttons.clear();

    for (std::map<std::string, Gtk::Image*>::const_iterator i = m_images.begin(); i != m_images.end(); ++i) {
        delete i->second; 
    }

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
                tmp_button->add(*tmp_image);
            } else {
                //tmp_image = new Gtk::Image("./img/diskicon.png");
                tmp_button->set_label(tmp_entry.getName());
            }

            tmp_button->set_size_request(128,128);

            tmp_button->signal_clicked().connect( sigc::mem_fun(m_entry_manager->getEntryMap()->at(tmp_entry.getName()), &Entry::run));

            m_buttons[tmp_entry.getName()] = tmp_button;

            m_flow_box.add(*m_buttons[tmp_entry.getName()]);
        }
    }
}

void dosman::MainWindow::update_edition_widget()
{
    if (m_entry_manager->getEntriesCount()) {
        Gtk::TreeModel::Row row;
        for (EntryMap::const_iterator i = m_entry_manager->getEntryMap()->begin(); i != m_entry_manager->getEntryMap()->end(); ++i) {
            row = *(m_reftreemodel->append());
            Entry tmp_entry = (Entry) i->second;
            row[m_columns.m_col_name] = tmp_entry.getName();
        }
    }
}

