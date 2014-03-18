#ifndef __ENTRYMANAGER_H__
#define __ENTRYMANAGER_H__

#include <stdio.h>
#include <string>
#include <vector>

#include "Entry.h"

namespace dosman {
    /**
    * @brief Singleton class managing the entries.
    *
    */
    class EntryManager {
        private:
            /* private construtor */
            EntryManager ();
            /* private destructor */
            virtual ~EntryManager ();
            
            static EntryManager *_singleton;

            /**
            * @brief Vector of Entry.
            */
            std::vector<Entry> m_entries;
            /**
            * @brief String containing the full absolute path to the .dosman directory
            */
            std::string m_dosmanPath;
        public:
            /**
            * @brief Initializer of the singleton class.
            *
            * @return a pointer to the instance of EntryManager.
            */
            static EntryManager *Initialize();
            /**stdio
            * @brief Destroys the current instance of the singleton class.
            */
            static void kill(void);

            /**
            * @brief Updates the entries contained in the manager.
            */
            void updateEntries(void);
            /**
            * @brief Add an Entry to entries contained in the manager.
            *
            * @param e_entry
            */
            void addEntry(const Entry & e_entry);
            /**
            * @brief
            *
            * @return a vector of entries contained in the manager.
            */
            std::vector<Entry> getEntries(void);
            /**
            * @brief Gets the Entry which name matches e_name.
            *
            * @param e_name
            *
            * @return a pointer to the Entry or NULL.
            */
            Entry * getEntryWithName(const std::string & e_name);

            /**
            * @brief Check if a name is free.
            *
            * @param e_name
            *
            * @return true if the name is free, false otherwise.
            */
            bool isNameFree(const std::string & e_name);

            static bool endsWith (std::string const &fullString, std::string const &ending);
    };
} /* dosman */

#endif /* __ENTRYMANAGER_H__ */
