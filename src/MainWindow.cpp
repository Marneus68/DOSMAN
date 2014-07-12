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
    m_entry_frame_box(Gtk::ORIENTATION_VERTICAL),
    m_edit_buttons_box(Gtk::ORIENTATION_HORIZONTAL),
    m_edit_save_run_box(Gtk::ORIENTATION_HORIZONTAL),
    m_entries_num(0),
    m_edit_add(Gtk::Stock::ADD),
    m_edit_remove(Gtk::Stock::REMOVE),
    m_edit_save("Save"),
    m_edit_run("Run"),

    m_entry_button_box(Gtk::ORIENTATION_VERTICAL),

    m_entry_select_executable("Select executable"),
    m_entry_select_setup("Run configuration program"),

    m_cb_sdl_fullscreen("Fullscreen"),

    m_rb_machine_hercules("Hercules"),
    m_rb_machine_cga("CGA"),
    m_rb_machine_tandy("Tandy compatible"),
    m_rb_machine_pcjr("PCjr"),
    m_rb_machine_ega("EGA"),
    m_rb_machine_vgaonly("VGA"),
    m_rb_machine_svga_s3("SVGA"),

    m_rb_scaler_none("None"),
    m_rb_scaler_normal2x("2x"),
    m_rb_scaler_normal3x("3x"),
    m_rb_scaler_tv2x("TV 2x"),
    m_rb_scaler_tv3x("TV 3x"),
    m_rb_scaler_rgb2x("RGB 2x"),
    m_rb_scaler_rgb3x("RGV 3x"),
    m_rb_scaler_scan2x("Scanlines 2x"),
    m_rb_scaler_scan3x("Scanlines 3x"),

    m_rb_output_surface("Surface"),
    m_rb_output_overlay("Overlay"),
    m_rb_output_opengl("OpenGL"),
    m_rb_output_openglnb("OpenGL nb"),

    m_cb_autolock("Automatically lock the mouse"),

    m_cb_render_aspect("Aspect correction"),

    m_cb_nosound("Silent mode")

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

    update_edition_widget();

    editwindowvisited = false;
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
    /*Gtk::Button* useless = new Gtk::Button("lol");
    useless->set_vexpand(true);
    useless->set_hexpand(true);
    useless->set_size_request(128,128);
    m_flow_box.add(*useless); */

    m_entry_manager->createEntry("foo", "bar", "boo");

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

    m_entry_frame.set_label(tmp_key);
    if (!editwindowvisited) {
        
        m_entry_button_box.set_layout(Gtk::BUTTONBOX_EXPAND);
        m_entry_button_box.pack_start(m_entry_select_executable);
        m_entry_button_box.pack_start(m_entry_select_setup);

        m_entry_box.pack_start(m_entry_button_box, Gtk::PACK_SHRINK);

        m_entry_box.pack_end(m_entry_image, Gtk::PACK_SHRINK);

        m_entry_box.set_border_width(10);

        m_entry_frame.add(m_entry_box);

        m_sdl_frame.set_label("SDL");

        m_rb_output_group = m_rb_output_surface.get_group();
        m_rb_output_overlay.set_group(m_rb_output_group);
        m_rb_output_opengl.set_group(m_rb_output_group);
        m_rb_output_openglnb.set_group(m_rb_output_group);

        m_rb_output_box.add(m_rb_output_surface);
        m_rb_output_box.add(m_rb_output_overlay);
        m_rb_output_box.add(m_rb_output_opengl);
        m_rb_output_box.add(m_rb_output_openglnb);

        m_sdl_box.add(m_cb_sdl_fullscreen);
        m_sdl_box.add(m_rb_output_box);
        m_sdl_box.add(m_cb_autolock);

        m_sdl_box.set_border_width(10);

        m_sdl_frame.add(m_sdl_box); 

        m_dosbox_frame.set_label("Machine type");
        
        m_rb_machine_group = m_rb_machine_hercules.get_group();
        m_rb_machine_cga.set_group(m_rb_machine_group);
        m_rb_machine_tandy.set_group(m_rb_machine_group);
        m_rb_machine_pcjr.set_group(m_rb_machine_group);
        m_rb_machine_ega.set_group(m_rb_machine_group);
        m_rb_machine_vgaonly.set_group(m_rb_machine_group);
        m_rb_machine_svga_s3.set_group(m_rb_machine_group);

        m_rb_machine_box.add(m_rb_machine_cga);
        m_rb_machine_box.add(m_rb_machine_tandy);
        m_rb_machine_box.add(m_rb_machine_pcjr);
        m_rb_machine_box.add(m_rb_machine_ega);
        m_rb_machine_box.add(m_rb_machine_vgaonly);
        m_rb_machine_box.add(m_rb_machine_svga_s3);
       
        m_rb_machine_box.set_border_width(10);

        m_dosbox_frame.add(m_rb_machine_box);

        m_render_frame.set_label("Rendering");

        m_rb_scaler_group = m_rb_scaler_none.get_group();
        m_rb_scaler_normal2x.set_group(m_rb_scaler_group);
        m_rb_scaler_normal3x.set_group(m_rb_scaler_group);
        m_rb_scaler_tv2x.set_group(m_rb_scaler_group);
        m_rb_scaler_tv3x.set_group(m_rb_scaler_group);
        m_rb_scaler_rgb2x.set_group(m_rb_scaler_group);
        m_rb_scaler_rgb3x.set_group(m_rb_scaler_group);
        m_rb_scaler_scan2x.set_group(m_rb_scaler_group);
        m_rb_scaler_scan3x.set_group(m_rb_scaler_group);

        m_rb_scaler_box.add(m_rb_scaler_none);
        m_rb_scaler_box.add(m_rb_scaler_normal2x);
        m_rb_scaler_box.add(m_rb_scaler_normal3x);
        m_rb_scaler_box.add(m_rb_scaler_tv2x);
        m_rb_scaler_box.add(m_rb_scaler_tv3x);
        m_rb_scaler_box.add(m_rb_scaler_rgb2x);
        m_rb_scaler_box.add(m_rb_scaler_rgb3x);
        m_rb_scaler_box.add(m_rb_scaler_scan2x);
        m_rb_scaler_box.add(m_rb_scaler_scan3x);

        m_render_box.add(m_rb_scaler_box);
        m_render_box.add(m_cb_render_aspect);

        m_render_box.set_border_width(10);

        m_render_frame.add(m_render_box);

        //m_cpu_frame.set_label("CPU");
        m_mixer_frame.set_label("Sound emulation");

        m_mixer_frame.add(m_cb_nosound);

        //m_midi_frame.set_label("MIDI");
        //m_sblaster_frame.set_label("Sound Blaster emulation");
        //m_gus_frame.set_label("Gravis UltraSound emulation");
        //m_speaker_frame.set_label("PC speaker emulation");

        m_entry_frame.set_shadow_type(Gtk::SHADOW_ETCHED_OUT);
        m_sdl_frame.set_shadow_type(Gtk::SHADOW_ETCHED_OUT);
        m_dosbox_frame.set_shadow_type(Gtk::SHADOW_ETCHED_OUT);
        m_render_frame.set_shadow_type(Gtk::SHADOW_ETCHED_OUT);
        //m_cpu_frame.set_shadow_type(Gtk::SHADOW_ETCHED_OUT);
        m_mixer_frame.set_shadow_type(Gtk::SHADOW_ETCHED_OUT);
        //m_midi_frame.set_shadow_type(Gtk::SHADOW_ETCHED_OUT);
        //m_sblaster_frame.set_shadow_type(Gtk::SHADOW_ETCHED_OUT);
        //m_gus_frame.set_shadow_type(Gtk::SHADOW_ETCHED_OUT);
        //m_speaker_frame.set_shadow_type(Gtk::SHADOW_ETCHED_OUT);

        m_entry_frame_box.add(m_entry_frame);
        m_entry_frame_box.add(m_sdl_frame);
        m_entry_frame_box.add(m_dosbox_frame);
        m_entry_frame_box.add(m_render_frame);
        //m_entry_frame_box.add(m_cpu_frame);
        m_entry_frame_box.add(m_mixer_frame);
        //m_entry_frame_box.add(m_midi_frame);
        //m_entry_frame_box.add(m_sblaster_frame);
        //m_entry_frame_box.add(m_gus_frame);
        //m_entry_frame_box.add(m_speaker_frame);

        m_edit_entry.add(m_entry_frame_box);

        editwindowvisited = true;
    }
    m_entry_frame_box.show_all();

    Entry tmp_entry =  m_entry_manager->getEntryMap()->at(tmp_key);
    m_entry_image.set(tmp_entry.getImagePath());

    if (std::string(tmp_entry.getConfig()->getKeyValueFromGroup("sdl", "fullscreen")).compare("true") == 0) {
        m_cb_sdl_fullscreen.set_active(true);
    } else {
        m_cb_sdl_fullscreen.set_active(false);
    }

    if (std::string(tmp_entry.getConfig()->getKeyValueFromGroup("sdl", "autolock")).compare("true") == 0) {
        m_cb_autolock.set_active(true);
    } else {
        m_cb_autolock.set_active(false);
    }

    if (std::string(tmp_entry.getConfig()->getKeyValueFromGroup("render", "aspect")).compare("true") == 0) {
        m_cb_render_aspect.set_active(true);
    } else {
        m_cb_render_aspect.set_active(false);
    }

    if (std::string(tmp_entry.getConfig()->getKeyValueFromGroup("mixer", "nosound")).compare("true") == 0) {
        m_cb_nosound.set_active(true);
    } else {
        m_cb_nosound.set_active(false);
    }

    std::string output = tmp_entry.getConfig()->getKeyValueFromGroup("sdl", "output"); 
    if (output.compare("surface") == 0) {
        m_rb_output_surface.set_active(true);
    } else if (output.compare("overlay") == 0) {
        m_rb_output_overlay.set_active(true);
    } else if (output.compare("opengl") == 0) {
        m_rb_output_opengl.set_active(true);
    } else if (output.compare("openglnb") == 0) {
        m_rb_output_openglnb.set_active(true);
    }

    std::string machine_type = tmp_entry.getConfig()->getKeyValueFromGroup("dosbox", "machine");
    if (machine_type.compare("hercules") == 0) {
        m_rb_machine_hercules.set_active(true);
    } else if (machine_type.compare("cga") == 0) {
        m_rb_machine_cga.set_active(true);
    } else if (machine_type.compare("tandy") == 0) {
        m_rb_machine_tandy.set_active(true);
    } else if (machine_type.compare("pcjr") == 0) {
        m_rb_machine_pcjr.set_active(true);
    } else if (machine_type.compare("ega") == 0) {
        m_rb_machine_ega.set_active(true);
    } else if (machine_type.compare("vgaonly") == 0) {
        m_rb_machine_vgaonly.set_active(true);
    } else if (machine_type.compare("svga_s3") == 0) {
        m_rb_machine_svga_s3.set_active(true);
    }

    std::string scaler = tmp_entry.getConfig()->getKeyValueFromGroup("render", "scaler");
    if (scaler.compare("none") == 0 ) {
        m_rb_scaler_none.set_active(true);
    } else if (scaler.compare("normal2x") == 0 ) {
        m_rb_scaler_normal2x.set_active(true);
    } else if (scaler.compare("normal3x") == 0 ) {
        m_rb_scaler_normal3x.set_active(true);
    } else if (scaler.compare("tv2x") == 0 ) {
        m_rb_scaler_tv2x.set_active(true);
    } else if (scaler.compare("tv3x") == 0 ) {
        m_rb_scaler_tv3x.set_active(true);
    } else if (scaler.compare("rgb2x") == 0 ) {
        m_rb_scaler_rgb2x.set_active(true);
    } else if (scaler.compare("rgb3x") == 0 ) {
        m_rb_scaler_rgb3x.set_active(true);
    } else if (scaler.compare("scan2x") == 0 ) {
        m_rb_scaler_scan2x.set_active(true);
    } else if (scaler.compare("scan3x") == 0 ) {
        m_rb_scaler_scan3x.set_active(true);
    }

    m_entry_frame_box.show_all();
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
    Glib::RefPtr<Gtk::TreeSelection> selection = m_treeview.get_selection();
    Gtk::TreeModel::iterator selectedRow = selection->get_selected();
    Gtk::TreeModel::Row row = *selectedRow;
    Glib::ustring port = row.get_value(m_columns.m_col_name);

    std::string tmp_key(port.data());
    if (tmp_key.compare("") == 0)  return;
    Entry tmp_entry = m_entry_manager->getEntryMap()->at(tmp_key);

    std::string fullscreen = "false",
                autolock = "true",
                aspect = "true",
                nosound = "false",
                machine = "svga_s3",
                output = "surface",
                scaler = "none";

    fullscreen = m_cb_sdl_fullscreen.get_active() ? "true" : "false"; 
    autolock = m_cb_autolock.get_active() ? "true" : "false"; 
    aspect = m_cb_render_aspect.get_active() ? "true" : "false"; 
    nosound = m_cb_nosound.get_active() ? "true" : "false"; 

    if (m_rb_output_surface.get_active()) {
        output = "surface";
    } else if (m_rb_output_overlay.get_active()) {
        output = "overlay";
    } else if (m_rb_output_opengl.get_active()) {
        output = "opengl";
    } else if (m_rb_output_openglnb.get_active()) {
        output = "openglnb";
    }

    if (m_rb_machine_hercules.get_active()) {
        machine = "hercules";
    } else if (m_rb_machine_cga.get_active()) {
        machine = "cga";
    } else if (m_rb_machine_tandy.get_active()) {
        machine = "tandy";
    } else if (m_rb_machine_pcjr.get_active()) {
        machine = "pcjr";
    } else if (m_rb_machine_ega.get_active()) {
        machine = "ega";
    } else if (m_rb_machine_vgaonly.get_active()) {
        machine = "vgaonly";
    } else if (m_rb_machine_svga_s3.get_active()) {
        machine = "svga_s3";
    }

    if (m_rb_scaler_none.get_active()) {
        scaler = "none";
    } else if (m_rb_scaler_normal2x.get_active()) {
        scaler = "normal2x";
    } else if (m_rb_scaler_normal3x.get_active()) {
        scaler = "normal3x";
    } else if (m_rb_scaler_tv2x.get_active()) {
        scaler = "tv2x";
    } else if (m_rb_scaler_tv3x.get_active()) {
        scaler = "tv3x";
    } else if (m_rb_scaler_rgb2x.get_active()) {
        scaler = "rgb2x";
    } else if (m_rb_scaler_rgb3x.get_active()) {
        scaler = "rgb3x";
    } else if (m_rb_scaler_scan2x.get_active())  {
        scaler = "scan2x";
    } else if (m_rb_scaler_scan3x.get_active()) {
        scaler = "scan3x";
    }

    tmp_entry.getConfig()->setKeyValue("sdl", "fullscreen", fullscreen);
    tmp_entry.getConfig()->setKeyValue("sdl", "output", output);
    tmp_entry.getConfig()->setKeyValue("sdl", "autolock", autolock);
    tmp_entry.getConfig()->setKeyValue("dosbox", "machine", machine);
    tmp_entry.getConfig()->setKeyValue("render", "scaler", scaler);
    tmp_entry.getConfig()->setKeyValue("render", "aspect", aspect);
    tmp_entry.getConfig()->setKeyValue("mixer", "nosound", aspect);

    tmp_entry.writeConfig();
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

