#include "Entry.h"
#include <iostream>

extern "C" {
    #include <dirent.h>
    #include <string.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/stat.h>
}

//#include "Exceptions.h"

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
  if(hasConf){
    dosboxParser = e_entry.dosboxParser;
  }

}

dosman::Entry::Entry(const std::string & e_path) :
    path(e_path)
{
    construct();
}

dosman::Entry::~Entry() {
  delete dosboxParser;
}

dosman::Entry dosman::Entry::operator=(Entry& e_entry)
{
  name = e_entry.name;
  path = e_entry.path;
  imagePath = e_entry.imagePath;
  construct();
  if(hasConf){
    delete dosboxParser;  
    dosboxParser = e_entry.dosboxParser;
  }
    return *this;
}

void dosman::Entry::construct(void)
{
    DIR *dir;
    struct dirent *ent;
    //int score;

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

        //if (!hasConf) throw InvalidEntryException();
    }
}


    bool dosman::Entry::loadConfigurationFile(){
      if(hasConf){
        dosboxParser = new KeyValueParser("dosbox.conf");
        return 1;
      }
      else{
        return 0;
      }
    }
        


