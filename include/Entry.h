#ifndef __ENTRY_H__
#define __ENTRY_H__

#include <string>
#include <vector>

namespace dosman {
    /**
    * @brief Class representing a program present in the DOSMAN folder.
    * Thes programs are actually named folders. Each of these folder can contain an image
    * and always contains a config file and a drive folder that olds the files for this
    * installation.
    */
    class Entry {
        protected:
            /* data */
            std::string name;
            std::string path;
            std::string imagePath;

            bool hasImage;
            bool hasConf;

            void construct(void);
    
        public:
            Entry (const std::string & e_path);
            Entry (const Entry& e_entry);
            virtual ~Entry ();
    
            Entry operator=(Entry& e_entry);

            const std::string * getName(void);
            const std::string * getPath(void);
            const std::string * getImagePath(void);
            const std::string * getDriveCPath(void);
    };
} /* dosman */

#endif /* __ENTRY_H__ */

