#ifndef __DOSBOXCALLER_H__
#define __DOSBOXCALLER_H__

#include "Entry.h"

namespace dosman {
    class DOSBoxCaller {
        public:
            static void run(const Entry & e_entry);
    };    
} /* dosman */

#endif /* __DOSBOXCALLER_H__ */
