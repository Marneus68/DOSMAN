#include "Entry.h"
const std::string * dosman::Entry::getImagePath(void)
{
    return 0;
}

const std::string * dosman::Entry::getName(void)
{
    return 0;
}

const std::string * dosman::Entry::getPath(void)
{
    return 0;
}

const std::string * dosman::Entry::getPrimarySubFolderPath(void)
{
    return 0;
}

dosman::Entry::Entry( const std::string & e_name, 
        const std::string & e_path, 
        const std::string & e_imagePath)
{
}

dosman::Entry::Entry( const std::string & e_name, 
        const std::string & e_path, 
        const std::string & e_imagePath,
        std::vector<std::string> e_vector)
{
}

dosman::Entry::~Entry()
{
}

