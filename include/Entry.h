#ifndef __ENTRY_H__
#define __ENTRY_H__

#include <string>
#include <vector>

namespace dosman {
    /**
    * @brief Class representing a program present in the DOSMAN folder.
    */
    class Entry {
        private:
            /* data */
            std::string name;
            std::string path;
            std::string imagePath;
            std::vector<std::string> subFoldersPath;
    
        public:
            Entry ( const std::string & e_name = "", 
                    const std::string & e_path = "", 
                    const std::string & e_imagePath = "");
            Entry ( const std::string & e_name = "", 
                    const std::string & e_path = "", 
                    const std::string & e_imagePath = "",
                    std::vector<std::string> e_vector = std::vector<std::string>());
            virtual ~Entry ();

            /**
            * @brief 
            *
            * @return the std::string pointer to the Entry name.
            */
            const std::string * getName(void);
            /**
            * @brief 
            *
            * @return the std::string pointer to the Entry path.
            */
            const std::string * getPath(void);
            /**
            * @brief 
            *
            * @return the std::string pointer to the Entry image path.
            */
            const std::string * getImagePath(void);
            /**
            * @brief 
            *
            * @return the std::string pointer to the first sub-folder in the Entry.
            */
            const std::string * getPrimarySubFolderPath(void);
            /**
            * @brief 
            *
            * @return the std::vector<std::string> pointer containing all sub-folders.
            */
            const std::vector<std::string> & getSubFoldersPath(void);
    };
} /* dosman */

#endif /* __ENTRY_H__ */
