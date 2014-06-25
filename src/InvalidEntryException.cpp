#include "InvalidEntryException.h"

std::string * dosman::InvalidEntryException::getMessage(void)
{
    return &message;
}

dosman::InvalidEntryException::InvalidEntryException(const std::string & e_message) :
    message(e_message)
{
    if (e_message == "") {
        message = "Attempting to create an Entry from an invalid directory. \
Does that folder ontain a config file ?";
    }
}

