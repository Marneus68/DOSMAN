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
                std::cout << m_dosman_path << " is present." << std::endl;

                DIR *dir, *subdir;
                struct dirent *ent, *subent;

                if ((dir = opendir (m_dosman_path.c_str())) != NULL) { 
                    while ((ent = readdir (dir)) != NULL) {
                        if (ent->d_name[0] == '.') continue;
                        std::string tmpPath = m_dosman_path + "/" + ent->d_name;
                        if ((subdir = opendir(tmpPath.c_str())) != NULL) {

                            bool    hasConf     = false;
                            while ((subent = readdir (subdir)) != NULL) {
                                if (subent->d_name[0] == '.') continue;
                                std::string filename(subent->d_name);
                                std::string dosboxconf(DOSMAN_ENTRY_CONF);
                                
                                if (filename.compare(0, dosboxconf.length(), dosboxconf) == 0) {
                                    try {
                                        std::pair<std::string, Entry > p = 
                                            make_pair(std::string(ent->d_name), Entry(tmpPath));
                                        m_entries.insert(p);
                                    } catch (InvalidEntryException e) {
                                        std::cerr << e.what() << std::endl;
                                    } catch (InvalidConfigFileException e) {
                                        std::cerr << e.what() << std::endl;
                                    } 
                                    break;
                                }
                            }
                            closedir (subdir);
                        }
                    }
                    closedir (dir);
                }
            }
        } else  {
            std::cout << m_dosman_path << " is NOT present ! " 
                    << m_dosman_path << " has been created." << std::endl;
        }
    }

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
        return m_entries.size();
    }

    EntryMap * EntryManager::getEntryMap() {
        return &m_entries;
    }

} /* dosman */

