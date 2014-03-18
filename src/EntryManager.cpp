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
        m_entries.clear();

        DIR *dir;
        struct dirent *ent;

        std::cout << m_dosmanPath << std::endl;

        if ((dir = opendir(m_dosmanPath.c_str())) != NULL) {
            while ((ent = readdir (dir)) != NULL) {
                if (ent->d_name[0] == '.') continue;
                if (ent->d_type == DT_DIR) {
                    // This is a directory, this could be a valid entry
                    DIR *sub_dir;
                    struct dirent *sub_ent;

                    std::string tmp_path(m_dosmanPath);
                    tmp_path+="/";
                    tmp_path.append(ent->d_name);

                    if ((sub_dir = opendir(tmp_path.c_str())) != NULL) {
                        int isValidEntry = 0; 
                        // a valid entry contains at least a dosbox.conf
                        while ((sub_ent = readdir (sub_dir)) != NULL) {
                            if (sub_ent->d_name[0] == '.') continue;
                            std::string tmp_str(sub_ent->d_name);
                            if (!endsWith(tmp_str, std::string(DOSMAN_CONF_EXT))) 
                                isValidEntry++;
                            //if (sub_ent->d_type == DT_DIR) score++;
                            //else if (!tmp_str.compare(DOSMAN_COVP) && !tmp_str.compare(DOSMAN_COVJ)) score++;
                        }
                        std::cout << ent->d_name << " : " << isValidEntry << std::endl;
                        if (isValidEntry > 1)
                            std::cerr << "   Warnig: More than one config files were found when traveling the " << ent->d_name << " directory." << std::endl;

                        if (isValidEntry) {
                            // We create a new entry and add it to the entry vector

                            // Path 
                            // .conf path
                            // vector of sub_folder path
                            // image
                        }
                    } else {
                        std::cerr << "Could not open " << ent->d_name << std::endl;
                    }
                }
            }
            closedir (dir);
        } else {
            std::cerr << "Could not open " << DOSMAN_DIR << std::endl;
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

    bool EntryManager::endsWith(std::string const &fullString, 
            std::string const &ending)
    {
        if (fullString.length() >= ending.length()) {
            return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
        } else {
            return false;
        }
    }

} /* dosman */

