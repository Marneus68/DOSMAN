#include "EntryManager.h"

extern "C" {
    #include <dirent.h>
    #include <string.h>
    #include <stdlib.h>
}
#include <iostream>

#include "constants.h"

namespace dosman {
    /* methods for singleton class EntryManager */

    /* singleton initialisation */
    EntryManager *EntryManager::_singleton = NULL;

    /* constructor */
    EntryManager::EntryManager() {
        char* home_path = (char*) getenv("HOME"); 
        char* dosman_path = strcat(home_path, DM_DIR);
        m_dosmanPath = std::string(dosman_path);
    }

    /* destructor */
    EntryManager::~EntryManager(void) {}

    /* method to initialize the singleton class */
    EntryManager* EntryManager::Initialize(void) {
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

    void EntryManager::updateEntries(void) {
        m_entries.clear();

        DIR *dir;
        struct dirent *ent;

        std::cout << m_dosmanPath << std::endl;

        if ((dir = opendir(m_dosmanPath.c_str())) != NULL) {
            while ((ent = readdir (dir)) != NULL) {
                if (ent->d_name[0] == '.') continue;
                if (ent->d_type == DT_DIR) {
                    // This is a directory, this could be a valid entry
                    std::cout << ent->d_name << std::endl;

                    DIR *sub_dir;
                    struct dirent *sub_ent;

                    if ((sub_dir = opendir(m_dosmanPath.c_str())) != NULL) {
                        int score = 0;
                        while ((sub_ent = readdir (sub_dir)) != NULL) {
                            if (sub_ent->d_name[0] == '.') continue;
                            // If the directory contains a directory contains a subfolder OR a <entry_name>.conf file
                            // This should become a tmp_entry
                            if (sub_ent->d_type == DT_DIR) score++;
                            else if (strcmp(sub_ent->d_name, DM_CONF)) score++;
                            else if (strcmp(sub_ent->d_name, DM_COVP)) score++;
                            else if (strcmp(sub_ent->d_name, DM_COVJ)) score++;
                            
                            // If the directory contains a cover.jpg or cover.png this should be added to the tmp_entry

                            // Add the tmp_entry to the m_entries vector
                        }
                        std::cout << "   Score of the entry : " << score << std::endl;
                    } else {
                        std::cerr << "Could not open " << ent->d_name << std::endl;
                    }
                }
            }
            closedir (dir);
        } else {
            std::cerr << "Could not open " << DM_DIR << std::endl;
        }
    }

    void EntryManager::addEntry(const Entry &e_entry) {
    }

    std::vector<Entry> EntryManager::getEntries(void) {
    }

    Entry * EntryManager::getEntryWithName(const std::string &e_name) {
    }

    bool EntryManager::isNameFree(const std::string &e_name) {
    }
} /* dosman */

