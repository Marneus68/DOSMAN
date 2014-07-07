#include "EntryManager.h"

#include <iostream>

extern "C" {
    #include <dirent.h>
    #include <string.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/stat.h>
}

#include "constants.h"

#include "Exceptions.h"

namespace dosman {
    /* methods for singleton class EntryManager */

    /* singleton initialisation */
    EntryManager *EntryManager::_singleton = NULL;

    /* constructor */
    EntryManager::EntryManager() {
        char* home_path = (char*) getenv("HOME"); 
        char* dosman_path = strcat(home_path, DOSMAN_DIR);
        m_dosman_path = std::string(dosman_path);

        struct stat st;
        if(stat(m_dosman_path.c_str(),&st) == 0) {
            if(st.st_mode & S_IFDIR != 0) {
                std::cout << m_dosman_path << " is present" << std::endl;

                DIR *dir, *subdir;
                struct dirent *ent, *subent;
                bool    hasConf = false, 
                        hasDrive = false;

                if ((dir = opendir (m_dosman_path.c_str())) != NULL) { 
                    while ((ent = readdir (dir)) != NULL) {
                        if (ent->d_name[0] == '.') continue;
                        std::string tmpPath = m_dosman_path + "/" + ent->d_name;
                        if ((subdir = opendir(tmpPath.c_str())) != NULL) {
                            std::cout << ent->d_name << std::endl;

                            bool    hasConf     = false;
                            while ((subent = readdir (subdir)) != NULL) {

                                std::string filename(subent->d_name);
                                std::string dosboxconf("dosbox.conf");
                                
                                if (filename.compare(0, dosboxconf.length(), dosboxconf) == 0) {
                                    hasConf = true;
                                    continue;
                                }
                            }

                            if (hasConf) {
                                try {
                                    Entry tmpEntry(tmpPath);
                                    std::string tmpName(ent->d_name);

                                    std::pair<std::string, Entry > p = 
                                            make_pair(tmpName, tmpEntry);
                                    m_entries.insert(p);
                                } catch (std::exception e) {
                                    std::cerr << e.what() << std::endl;
                                    std::cerr << "Something went wrong..." << std::endl;
                                }
                            }
                            closedir (subdir);
                        }
                    }
                    closedir (dir);
                }
            }
        } else  {
            std::cout << m_dosman_path << " is NOT present" << std::endl;
            std::cout << m_dosman_path << " has been created" << std::endl;
        }
    }

    /* destructor */
    EntryManager::~EntryManager(void) {}

    /* method to initialize the singleton class */
    EntryManager* EntryManager::Initialize(void) {
        std::cout << "EntryManager::Initialize()" << std::endl;
        if (_singleton == NULL) {
            _singleton =  new EntryManager();
        }
        return _singleton;
    }

    /* kill the singleton */
    void EntryManager::kill(void) {
        if (_singleton != NULL) {
            delete _singleton;
            _singleton = NULL;
        }
    }

    void EntryManager::addEntry(const Entry &e_entry) {
    }

    bool EntryManager::isNameFree(const std::string &e_name) {
    }

    unsigned int EntryManager::getEntriesCount() {
        //return m_entries.size();
        return 0;
    }
} /* dosman */

