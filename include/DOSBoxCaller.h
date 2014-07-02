#ifndef __DOSBOXCALLER_H__
#define __DOSBOXCALLER_H__

#include <string>
#include <cstdlib>

#include "Entry.h"

namespace dosman {
    class DOSBoxCaller {
        private:
            DOSBoxCaller (const std::string & e_dosman_dir_path);
            virtual ~DOSBoxCaller ();
            
            static DOSBoxCaller *_singleton;
            
            std::string dosman_dir_path;
        public:
            static DOSBoxCaller *Initialize(const std::string & e_dosman_dir_path);
            static void kill(void);

            void run(const Entry & e_entry);
    };    
} /* dosman */

#endif /* __DOSBOXCALLER_H__ */
