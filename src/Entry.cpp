#include "Entry.h"

#include <iostream>

extern "C" {
    #include <dirent.h>
    #include <string.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/stat.h>
}

#include "Exceptions.h"

const std::string * dosman::Entry::getDriveCPath(void)
{
    return &path;
}

const std::string * dosman::Entry::getImagePath(void)
{
    return &imagePath; 
}

const std::string * dosman::Entry::getName(void)
{
    return &name; 
}

const std::string * dosman::Entry::getPath(void)
{
    return &path;
}

dosman::Entry::Entry(const Entry& e_entry) :
    name(e_entry.name),
    path(e_entry.path),
    imagePath(e_entry.imagePath)
{
    construct();
}

dosman::Entry::Entry(const std::string & e_path) :
    path(e_path)
{
    construct();
}

dosman::Entry::~Entry() {}

dosman::Entry & dosman::Entry::operator=(Entry& e_entry)
{
    path = e_entry.path;
    name = e_entry.name;
    return *this;
}

void dosman::Entry::construct(void)
{
    DIR *dir;
    struct dirent *ent;
    int score;

    hasImage = false;
    hasConf = false;

    if ((dir = opendir (path.c_str())) != NULL) { 
        while ((ent = readdir (dir)) != NULL) {
            if (ent->d_name[0] == '.') continue;

            std::string filename(ent->d_name);
            std::string imagefile("image.");
            std::string dosboxconf("dosbox.conf");

            std::cout << path << " : " << ent->d_name <<  " " 
                    << filename.compare(0, imagefile.length(), imagefile) 
                    << std::endl;

            if (filename.compare(0, imagefile.length(), imagefile) == -6) {
                hasImage = true;
                continue;
            }

            if (filename.compare(0, dosboxconf.length(), dosboxconf) == 0) {
                hasConf = true;
                continue;
            }
        }
        closedir (dir);

        if (!hasConf) throw InvalidEntryException();

        try {
            std::string tmpPath(path + "/" + "dosbox.conf");
            std::cout << tmpPath << std::endl;
            config = new KeyValueParser(path + "/" + "dosbox.conf");
        } catch (...) {
            throw InvalidEntryException();
        }
    }
}

