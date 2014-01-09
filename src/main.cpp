#include "../include/helloworld.h"
#include <gtkmm/main.h>
#include <iostream>

int main (int argc, char *argv[])
{
    Gtk::Main kit(argc, argv);

    dosman::HelloWorld helloworld;
    Gtk::Main::run(helloworld);

     return 0;
}

