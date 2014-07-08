#include "DOSBoxCaller.h"

#include <string>

extern "C" {
    #include <spawn.h>
    #include <unistd.h>
}

void dosman::DOSBoxCaller::run(const Entry & e_entry)
{
    pid_t processID;
    std::string fullConfigPath(((char*)((Entry)e_entry).getPath()));
    fullConfigPath += "/";
    fullConfigPath += "dosbox.conf";
    char *argV[] = {"dosbox", "-conf", (char*)fullConfigPath.c_str() ,(char *) 0};
    int status = -1;

    std::cout << fullConfigPath << std::endl;
    status = posix_spawn(&processID,"dosbox",NULL,NULL,argV,environ);

    if(status == 0)
        std::cout << "Dosbox launched." << std::endl;
    else
        std::cout << "Something went wrong somewhere." << std::endl;
}

