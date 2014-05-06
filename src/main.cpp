#include <gtkmm.h>
#include <iostream>

#include "MainWindow.h"

int main (int argc, char *argv[])
{
    Glib::RefPtr<Gtk::Application> app =
        Gtk::Application::create(argc, argv,
        "fr.iridia.dosman");
    dosman::MainWindow window;
    return app->run(window);
}

