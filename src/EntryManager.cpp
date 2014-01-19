#include "EntryManager.h"

#include <dirent.h>
#include <iostream>

#include "constants.h"

namespace dosman {
    /* methods for singleton class EntryManager */

    /* singleton initialisation */
    EntryManager *EntryManager::_singleton = NULL;

    /* constructor */
    EntryManager::EntryManager() {
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
        if ((dir = opendir (DM_DIR)) != NULL) {
            while ((ent = readdir (dir)) != NULL) {
                printf ("%s\n", ent->d_name);
                if (ent->d_type == DT_DIR) {
                    // This is a directory, this could be a valid entry
                    std::cout << ent->d_name << std::endl;
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

