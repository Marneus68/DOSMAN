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

const char * dosman::Entry::getDriveCPath(void)
{
    return path.c_str();
}

const char * dosman::Entry::getImagePath(void)
{
    return imagePath.c_str(); 
}

const char * dosman::Entry::getName(void)
{
    return name.c_str(); 
}

const char * dosman::Entry::getPath(void)
{
    return path.c_str();
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
    name = path.substr(path.find_last_of("\\/")+1, path.size());
    imagePath = "";
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

            if (filename.compare(0, imagefile.length(), imagefile) == -6) {
                hasImage = true;
                imagePath = filename;
                continue;
            }

            if (filename.compare(0, dosboxconf.length(), dosboxconf) == 0) {
                hasConf = true;
                continue;
            }
        }
        closedir (dir);

        if (!hasConf) throw InvalidEntryException(path);

        try {
            config = new KeyValueParser(path + "/" + "dosbox.conf");
        } catch (...) {
            throw InvalidConfigFileException(path);
        }

    }
}

