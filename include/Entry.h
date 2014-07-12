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

            friend std::ostream& operator<<( std::ostream& out , const Entry& e_entry );

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
            * @brief returns the path to c drive of the entry
            */
            const char * getDriveCPath(void);
            /**
            * @brief returns the path to the configuration file
            */
            const char * getConfPath(void);
            /**
            * @brief returns the path to the autorun configuration path
            */
            const char * getRunConfPath(void);
            /**
            * @brief Returns true if the entry has a cover image
            */
            bool containsImage(void);
            /**
            * @brief Returns a pointer to the KeyValueParse that holds the configuration of the Entry
            */
            KeyValueParser* getConfig(void);
            /**
            * @brief Run the entru with DOSBox
            */
            void run(void);
            /**
            * @brief Writes the updated configuration file to disk
            */
            void writeConfig(void);

    };
} /* dosman */

#endif /* __ENTRY_H__ */

