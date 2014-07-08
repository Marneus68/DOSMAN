#ifndef __ENTRY_H__
#define __ENTRY_H__

#include <string>
#include <vector>

#include "KeyValueParser.h"

namespace dosman {
    /**
    * @brief Class representing a program present in the DOSMAN folder.
    * Thes programs are actually named folders. Each of these folder can contain an image
    * and always contains a config file and a drive folder that olds the files for this
    * installation.
    */
    class Entry {
        protected:
            std::string name;
            std::string path;
            std::string imagePath;

            KeyValueParser* config;

            bool hasImage;
            bool hasConf;

            void construct(void);
        public:
            Entry (const std::string & e_path);
            Entry (const Entry& e_entry);
            virtual ~Entry ();
    
            Entry & operator=(Entry& e_entry);

            /**
            * @brief Returns the name of the Entry
            */
            const char * getName(void);
            /**
            * @brief Returns the path to the Entry
            */
            const char * getPath(void);
            /**
            * @brief Returns a path to the associated image if it exist. Returns null otherwise.
            */
            const char * getImagePath(void);
            /**
            * @brief Returns the path to C drive of the Entry
            */
            const char * getDriveCPath(void);
    };
} /* dosman */

#endif /* __ENTRY_H__ */

