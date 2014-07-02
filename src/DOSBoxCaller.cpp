#include "DOSBoxCaller.h"

/* methods for singleton class DOSBoxCaller */

/* singleton initialisation */
dosman::DOSBoxCaller *dosman::DOSBoxCaller::_singleton = NULL;

/* constructor */
dosman::DOSBoxCaller::DOSBoxCaller(const std::string & e_dosman_dir_path) :
    dosman_dir_path(e_dosman_dir_path) {}

/* method to initialize the singleton class */
dosman::DOSBoxCaller* dosman::DOSBoxCaller::Initialize(const std::string & e_dosman_dir_path) {
    if (_singleton == NULL) {
        _singleton =  new DOSBoxCaller(e_dosman_dir_path);
    }
    return _singleton;
}

/* kill the singleton */
void dosman::DOSBoxCaller::kill(void) {
    if (_singleton != NULL) {
        delete _singleton;
        _singleton = NULL;
    }
}

dosman::DOSBoxCaller::~DOSBoxCaller() {}

void dosman::DOSBoxCaller::run(const Entry & e_entry)
{

}

