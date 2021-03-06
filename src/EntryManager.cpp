#include "EntryManager.h"

#include <iostream>
#include <fstream>
#include <string>

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
            std::cout << m_dosman_path << " is NOT present ! "  << m_dosman_path << " has been created." << std::endl;
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

    std::ostream& operator<<( std::ostream& out , const EntryManager& e_entry_manager ) {
        for (EntryMap::const_iterator i = e_entry_manager.m_entries.begin(); i != e_entry_manager.m_entries.end(); ++i) {
            out << i->second;
        }
    }

    void EntryManager::printEntriesNames() {
        for (EntryMap::const_iterator i = m_entries.begin(); i != m_entries.end(); ++i) {
            std::cout << i->second << std::endl;
        }
    }

    void EntryManager::createEntry(const char * e_name, const char * e_source_path, const char * e_source_folder_name, const char * e_exe_path) {
        if (!isNameFree(e_name)) {
            throw InvalidConfigFileException();
        }
        // Create the entry folder structure
        std::string line = "mkdir ~/" + std::string(e_name);
        std::cout << (line) << std::endl;
        system((line).c_str());
        line += "/drive_c";
        system((line).c_str());
        std::cout << (line) << std::endl;
        std::string newline("cp `dosbox -printconf` ~/" + std::string(e_name) + "/dosbox.conf");
        std::cout << newline << std::endl;
        system(newline.c_str());
        std::string yetnewline("cp -rf \"" + std::string(e_source_path) + "\" ~/" + std::string(e_name) + "/drive_c/");
        system(yetnewline.c_str());
        //
        // reate the basic run.conf
        std::string runconf_path(std::string(getenv("HOME")) + "/" + 
                std::string(e_name) + "/run.conf");
        std::cout << runconf_path << std::endl;
        std::ofstream runconf;
        runconf.open(runconf_path.c_str());
        runconf << "[autoexec]" << std::endl << "mount e ~/" << e_name << 
                "/drive_c/" << e_source_folder_name << std::endl << "e:" << std::endl << 
                e_exe_path << std::endl << "exit";
        runconf.close();

        // Create a new Entry from that and add it to the map
        std::pair<std::string, Entry > p = 
            make_pair(std::string(e_name), Entry(std::string(getenv("HOME"))+"/"+e_name));
        m_entries.insert(p);
    }

    bool EntryManager::isNameFree(const char * e_name) {
        for (EntryMap::const_iterator i = m_entries.begin(); i != m_entries.end(); ++i) {
            if (i->first.compare(e_name) == 0) {
                return false;
            }
        }
        return true;
    }

    unsigned int EntryManager::getEntriesCount() {
        return m_entries.size();
    }

    EntryMap * EntryManager::getEntryMap() {
        return &m_entries;
    }

} /* dosman */

