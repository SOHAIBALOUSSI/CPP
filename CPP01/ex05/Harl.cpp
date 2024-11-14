#include "Harl.hpp"

void Harl::debug( void ){
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}
void Harl::info( void ){
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}
void Harl::warning( void ){
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}
void Harl::error( void ){
    std::cout << "This is unacceptable! I want to speak to the manager now.";
}

e_Level convertLeveltoEnum(std::string strLevel)
{
    if (strLevel == "DEBUG") return DEBUG;
    else if (strLevel == "INFO") return INFO;
    else if (strLevel == "WARNING") return WARNING;
    else if (strLevel == "ERROR") return ERROR;
    else return UNKNOWN;
}

void Harl::complain( std::string level ){
    
    Harl Obj;
    void (Harl::*pDebug)(void) = &Harl::debug;
    void (Harl::*pInfo)(void) = &Harl::info;
    void (Harl::*pWarning)(void) = &Harl::warning;
    void (Harl::*pError)(void) = &Harl::error;
    e_Level check = convertLeveltoEnum(level);
    switch (check)
    {
        case DEBUG:
        {
            (Obj.*pDebug)();
            break;
        }
        case INFO:
        {
            (Obj.*pInfo)();
            break;
        }
        case WARNING:
        {
            (Obj.*pWarning)();
            break;
        }
        case ERROR:
        {
            (Obj.*pError)();
            break;  
        }
        default:
            std::cout << "Unknow Level\n";
            break;
    }
}