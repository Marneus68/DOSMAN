![Icon](https://raw.githubusercontent.com/Marneus68/DOSMAN/master/img/diskicon.png)

DOSMAN
======

DOSMAN is a graphical [DOSBox](http://www.dosbox.com/) front-end written in C++ for modern GNU/Linux desktop environements.

With DOSMAN you can manage games, attribute cover artworks and tweaks the paramaters DOSBox will use to launch them.

You can find the sources on GitHub [here](https://github.com/Marneus68/DOSMAN). 

Screenshots
-----------

### Main Menu
![Main menu](https://raw.githubusercontent.com/Marneus68/DOSMAN/master/img/cap1.png)

###  Configuration Screen
![Configuration screen](https://raw.githubusercontent.com/Marneus68/DOSMAN/master/img/cap2.png)

Dependencies
------------

DOSMAN requires [gtkmm 3.0](http://www.gtkmm.org/en/). Since DOSMAN is a DOSBox front-end, it requires the `dosbox` executable to be in the path. Most packages provided by the major GNU/Linux distributions will install DOSBox correctly.

On debian based systems, gtkmm 3.0 and its developement headers can be installed by running the following command as root:    

    apt-get install libgtkmm-3.0 libgtkmm-3.0-dev


Builing
-------

DOSMAN uses Make and g++. To build it, move to the project's directory and run:    

    make


Installing and Uninstalling
---------------------------

Installing and uninstalling can be done from the project's Makefile with

    sudo make install

and

    sudo make uninstall

Running
-------

Once installed, run `dosman` to start the program. A directory will be created a `~/.dosman` to hold you programs and default configurations.  
Since DOSMAN is designed to be a simple and clean front-end, you can actually modify every file in every sub-directory. There is no database involved, DOSMAN works on flat files and directory structure.



