#include "Entry.h"

#include <iostream>

extern "C" {
    #include <dirent.h>
    #include <string.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/stat.h>

    #include <spawn.h>
    #include <unistd.h>
}

#include "constants.h"

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

const char * dosman::Entry::getConfPath(void)
{
    std::string tmp(path + "/" + DOSMAN_ENTRY_CONF);
    return tmp.c_str();
}

const char * dosman::Entry::getRunConfPath(void)
{
    std::string tmp(path + "/" + DOSMAN_ENTRY_RUNC);
    return tmp.c_str();
}

dosman::Entry::Entry(const Entry& e_entry) :
    name(e_entry.name),
    path(e_entry.path),
    imagePath(e_entry.imagePath),
    config(e_entry.config),
    hasConf(e_entry.hasConf),
    hasImage(e_entry.hasImage) {}

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
    config = e_entry.config;

    hasImage = e_entry.hasImage;
    hasConf = e_entry.hasConf;
    return *this;
}

std::ostream& dosman::operator<<( std::ostream& out , const dosman::Entry& e_entry )
{
    return out << std::endl << "> Entry name : " << ((dosman::Entry&) e_entry).getName() << std::endl 
            << "> path : " << ((dosman::Entry&) e_entry).getPath() << std::endl 
            << "> image : " << ((dosman::Entry&) e_entry).getImagePath() << std::endl;
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
            std::string imagefile(DOSMAN_ENTRY_COVER);
            std::string dosboxconf(DOSMAN_ENTRY_CONF);

            if (filename.compare(0, imagefile.length(), imagefile) == 0) {
                hasImage = true;
                imagePath = path + "/" + filename;
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
            config = new KeyValueParser(path + "/" + DOSMAN_ENTRY_CONF);
        } catch (...) {
            throw InvalidConfigFileException(path);
        }
    }
}

bool dosman::Entry::containsImage()
{
    return hasImage;
}

void dosman::Entry::run()
{
    pid_t processID;
    char *argV[] = {"dosbox", "-conf", (char*)getConfPath(), "-conf", (char*)getRunConfPath(), (char *) 0};
    int status = -1;

    std::cout << getConfPath() << std::endl;
    std::cout << getRunConfPath() << std::endl;
    status = posix_spawn(&processID,"dosbox",NULL,NULL,argV,environ);

    if(status == 0)
        std::cout << "Dosbox launched." << std::endl;
    else
        std::cout << "Something went wrong somewhere." << std::endl;
}

