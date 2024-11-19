#include "replace.hpp"

void Replace::setInFilename(std::string filename)
{
    this->_infileName = filename;
}
void Replace::setToFind(std::string tofind)
{
    this->_toFind = tofind;
}
void Replace::setReplace(std::string replace)
{
    this->_replace = replace;
}

void    Replace::setOutFilename(std::string filename)
{
    this->_outfileName = filename;
}
std::string Replace::getInFilename()
{
    return this->_infileName;
}
std::string Replace::getToFind()
{
    return this->_toFind;
}
std::string Replace::getReplace()
{
    return this->_replace;
}
std::string Replace::getOutFilemame()
{
    return this->_outfileName;
}