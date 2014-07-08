#include "Exceptions.h"

dosman::DosmanException::DosmanException(const dosman::DosmanException & e_dosmanexception) : 
    DosmanException(e_dosmanexception.message, e_dosmanexception.predef_message) {}

dosman::DosmanException::DosmanException(const std::string & e_message, const std::string & e_predef_message) :
    message(e_message),
    predef_message(e_predef_message) {}

dosman::DosmanException dosman::DosmanException::operator=(dosman::DosmanException & e_dosmanexception)
{
    message = e_dosmanexception.message;
    predef_message = e_dosmanexception.predef_message;
    return e_dosmanexception;
}

dosman::DosmanException::~DosmanException() throw() {}

const char* dosman::DosmanException::what() const throw()
{
    std::string tmp = predef_message + " [" + message + "]";
    return tmp.c_str();
}

dosman::InvalidPathException::InvalidPathException(const std::string & e_message) :
    DosmanException(e_message, "Attempting to create an Entry from an invalid directory. \nDoes that folder contain a config file ?") {}

dosman::InvalidEntryException::InvalidEntryException(const std::string & e_message) :
    DosmanException(e_message, "Invalid path provided to the class constructor. Aborting.\nDoes the config file contains the right path to the proper folder ?") {}

dosman::InvalidConfigFileException::InvalidConfigFileException(const std::string & e_message) :
    DosmanException(e_message, "Invalid configuration file. Aborting.\nIs the config file accessible for reading and/or writing, is it properly formated ?... does it contain anything at all ?") {}

dosman::DOSBoxSpawnException::DOSBoxSpawnException(const std::string & e_message) :
    DosmanException(e_message, "There was an error while attempting to spawn DOSBox.\nAre you sure DOSBox is installed on the system and available from your PATH ?") {}

