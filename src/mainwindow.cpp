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

        // Install new program action
        m_refActionGroup->add(Gtk::Action::create("InstallNewProgram",
                Gtk::Stock::NEW, "_New", "Install New Program"),
                sigc::mem_fun(*this, &MainWindow::on_install_new_program));
        // Open AppMenu action
        m_refActionGroup->add(Gtk::Action::create("Preferences",
                Gtk::Stock::NEW, "_Preferences", "Preferences"),
                sigc::mem_fun(*this, &MainWindow::on_appmenu));
        // Quit Action
        m_refActionGroup->add(Gtk::Action::create("Quit",
                Gtk::Stock::QUIT, "_Quit", "Quit"),
                sigc::mem_fun(*this, &MainWindow::on_quit));

        m_refUIManager = Gtk::UIManager::create();
        m_refUIManager->insert_action_group(m_refActionGroup);

        add_accel_group(m_refUIManager->get_accel_group());

        Glib::ustring ui_info = 
            "<ui>"
            "  <toolbar  name='ToolBar'>"
            "    <toolitem action='InstallNewProgram'/>"
            "    <toolitem action='Quit'/>"
            "    <toolitem action='Preferences'/>"
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
        std::cout << "Quit" << std::endl;
    }
} /* dosman */

