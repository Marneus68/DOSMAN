#ifndef __ENTRYMANAGER_H__
#define __ENTRYMANAGER_H__

#include <stdio.h>
#include <string>
#include <map>

extern "C" {
    #include <ftw.h>
}

#include "Entry.h"

namespace dosman {
    /**
    * @brief Singleton class managing the entries.
    *
    */
    class EntryManager {
        private:
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

            static int walk(const char *fpath, const struct stat *sb, int typeflag);
        public:
            static EntryManager *Initialize();
            static void kill(void);

            void addEntry(const Entry & e_entry);
            Entry * getEntryWithName(const std::string & e_name);
            bool isNameFree(const std::string & e_name);
            unsigned int getEntriesCount();
    };
} /* dosman */

#endif /* __ENTRYMANAGER_H__ */
