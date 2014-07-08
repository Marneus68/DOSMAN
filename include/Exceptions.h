#ifndef __EXCEPTIONS_H__
#define __EXCEPTIONS_H__

#include <exception>
#include <string>

namespace dosman {
    class DosmanException : public std::exception {
        protected:
            std::string predef_message;
            std::string message;

            DosmanException(const std::string & e_message, const std::string & e_predef_message);
        public:
            DosmanException(const DosmanException & e_dosmanexception);
            ~DosmanException() throw();

            virtual DosmanException operator=(DosmanException & e_dosmanexception);

            virtual const char* what() const throw();
    };

    class InvalidEntryException : public DosmanException {
        public:
            InvalidEntryException(const std::string & e_message = "");
    };

    class InvalidPathException : public DosmanException {
        public:
            InvalidPathException(const std::string & e_message = "");
    };

    class InvalidConfigFileException : public DosmanException {
        public:
            InvalidConfigFileException(const std::string & e_message = "");
    };

    class DOSBoxSpawnException : public DosmanException {
        public:
            DOSBoxSpawnException(const std::string & e_message = "");
    };
} /* dosman */

#endif /* __EXCEPTIONS_H__ */
