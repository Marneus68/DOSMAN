#include "mainwindow.h"
#include <iostream>

#include <gtkmm/stock.h>

namespace dosman {
    MainWindow::MainWindow() :
        m_box(Gtk::ORIENTATION_VERTICAL)
    {
        set_title("DOSMAN");
        set_default_size(800,600);
        add(m_box); 

        m_refActionGroup = Gtk::ActionGroup::create();

        // Information on the stock Gtk items cen be found here :
        // https://developer.gnome.org/gtk3/stable/gtk3-Stock-Items.html#GTK-STOCK-EXECUTE:CAPS

        // Install new program action
        m_refActionGroup->add(Gtk::Action::create("InstallNewProgram",
                Gtk::Stock::ADD, "_New", "Install New Program"),
                sigc::mem_fun(*this, &MainWindow::on_install_new_program));
        // Quit Action
        m_refActionGroup->add(Gtk::Action::create("Quit",
                Gtk::Stock::QUIT, "_Quit", "Quit"),
                sigc::mem_fun(*this, &MainWindow::on_quit));
        // Open AppMenu action
        m_refActionGroup->add(Gtk::Action::create("Preferences",
                Gtk::Stock::PREFERENCES, "_Preferences", "Preferences"),
                sigc::mem_fun(*this, &MainWindow::on_appmenu));

        m_refUIManager = Gtk::UIManager::create();
        m_refUIManager->insert_action_group(m_refActionGroup);

        add_accel_group(m_refUIManager->get_accel_group());

        Glib::ustring ui_info = 
            "<ui>"
            "  <toolbar  name='ToolBar'>"
            "    <toolitem action='InstallNewProgram'/>"
            "    <toolitem action='Quit'/>"
            "    <separator expand='true'/>"
            //"    <toolitem placeholder='Search'/>"
            "    <toolitem action='Preferences' />"
            "  </toolbar>"
            "</ui>";

        try
        {
            m_refUIManager->add_ui_from_string(ui_info);
        }
        catch(const Glib::Error& ex)
        {
            std::cerr << "building menus failed: " <<  ex.what();
        }
        
        // Show the toolbar widgets (?)
        Gtk::Widget* pToolbar = m_refUIManager->get_widget("/ToolBar") ;
        if(pToolbar)
            m_box.pack_start(*pToolbar, Gtk::PACK_SHRINK);

        show_all_children();
    }

    MainWindow::~MainWindow() {}

    void MainWindow::on_install_new_program()
    {
        std::cout << "Install new Application" << std::endl;
    }

    void MainWindow::on_appmenu()
    {
        std::cout << "Open AppMenu" << std::endl;
    }

    void MainWindow::on_quit()
    {
        hide(); // Quit the app by hiding the main window
    }
} /* dosman */

