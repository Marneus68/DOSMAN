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
                ftw(m_dosman_path.c_str(), walk, 0);
            }
        } else  {
            std::cout << m_dosman_path << " is NOT present" << std::endl;
            std::cout << m_dosman_path << " has been created" << std::endl;
        }
    }

    /* destructor */
    EntryManager::~EntryManager(void) {}

    int EntryManager::walk(const char *fpath, const struct stat *sb, int typeflag) {
        if (typeflag != FTW_D) return 0;
        DIR *dir;
        struct dirent *ent;
        int score;

        //std::cout << fpath << std::endl;

        std::string path(fpath);
        
        try {
            Entry ent(path);
        } catch (InvalidEntryException e) {
            std::cerr << e.what() << std::endl;
        }

        return 0;
    }

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

