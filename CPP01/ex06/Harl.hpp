#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

#define USAGE_ERR "USAGE: ./harlFilter <logLevel>\n"

enum e_Level {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    UNKNOWN
};

class Harl
{
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
    public:
        static e_Level convertLeveltoEnum(std::string strLevel);
        void complain(e_Level logLevel);
};

#endif