DOSMAN
======

DOSMAN is a graphical [DosBox](http://www.dosbox.com/) front-end written in C++ for modern GNU/Linux desktop environements.

Dependencies
------------

DOSMAN requires [gtkmm 3.0](http://www.gtkmm.org/en/).

On debian based systems, gtkmm 3.0 and its developement headers can be installed by running the following command as root:    

    apt-get install libgtkmm-3.0 libgtkmm-3.0-dev


Builing
-------

DOSMAN uses Make and g++. To build it, move to the project's directory and run:    

    make


Installing and Uninstalling
---------------------------

Installing and uninstalling can be done from the project's Makefile:

    sudo make install



    sudo make uninstall


