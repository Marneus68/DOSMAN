#include "mainwindow.h"
#include <gtkmm/main.h>
#include <iostream>

int main (int argc, char *argv[])
{
    Gtk::Main kit(argc, argv);

    dosman::MainWindow mainwindow;
    Gtk::Main::run(mainwindow);

     return 0;
}

