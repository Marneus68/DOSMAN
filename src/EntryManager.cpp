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
        char* dosman_path = strcat(home_path, DOSMAN_DIR);
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
    }

    void EntryManager::addEntry(const Entry &e_entry) {
    }

    std::vector<Entry> EntryManager::getEntries(void) {
    }

    Entry * EntryManager::getEntryWithName(const std::string &e_name) {
    }

    bool EntryManager::isNameFree(const std::string &e_name) {
    }

    bool EntryManager::endsWith(std::string const &fullString, 
            std::string const &ending)
    {
    }

} /* dosman */

