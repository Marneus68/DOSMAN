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

            void createEntry(const char * e_name, const char * e_source_path, const char * e_source_folder_name, const char * e_exe_path);
            bool isNameFree(const char * e_name);

            unsigned int getEntriesCount();

            Entry * getEntryWithName(const char * e_name);
            EntryMap * getEntryMap(void);


    };
} /* dosman */

#endif /* __ENTRYMANAGER_H__ */

