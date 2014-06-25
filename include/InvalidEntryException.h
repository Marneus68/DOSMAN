#ifndef __INVALIDENTRYEXCEPTION_H__
#define __INVALIDENTRYEXCEPTION_H__

#include <string>

namespace dosman {
    class InvalidEntryException {
        protected:
            std::string message;

        public:
            InvalidEntryException(const std::string & e_message = "");

            std::string * getMessage(void);
    };
} /* dosman */

#endif /* __INVALIDENTRYEXCEPTION_H__ */

