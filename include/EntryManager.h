#ifndef __ENTRYMANAGER_H__
#define __ENTRYMANAGER_H__

#include <stdio.h>
#include <string>
#include <map>

#include "Entry.h"

typedef std::map<std::string, dosman::Entry> EntryMap;

namespace dosman {
    /**
    * @brief Singleton class managing the entries.
    *
    */
    class EntryManager {
        protected:
            EntryManager ();
            virtual ~EntryManager ();
            
            static EntryManager *_singleton;

            /**
            * @brief Map of Entry.
            */
            std::map<std::string, Entry> m_entries;
            /**
            * @brief String containing the full absolute path to the .dosman directory
            */
            std::string m_dosman_path;
        public:
            static EntryManager *Initialize();
            static void kill(void);

            friend std::ostream& operator<<( std::ostream& out , const EntryManager& e_entry_manager );
            /**
            * @brief Creates a new Entry but creating its folder and required configuration. Once this is done, the Entry is instanciated and added to the map.
            */
            void createEntry(const char * e_name, const char * e_source_path, const char * e_source_folder_name, const char * e_exe_path);
            /**
            * @brief Returns false is the name of the Entry is already taked, true otherwise.
            */
            bool isNameFree(const char * e_name);
            /**
            * @brief Returns the number of entries currently loaded in the manager.
            */
            unsigned int getEntriesCount();

            Entry * getEntryWithName(const char * e_name);
            EntryMap * getEntryMap(void);


    };
} /* dosman */

#endif /* __ENTRYMANAGER_H__ */

