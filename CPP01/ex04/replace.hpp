#ifndef REPLACE_HPP
#define REPLACE_HPP

# include <iostream>
# include <fstream>


#define USAGE_ERR "USAGE: ./replace <input-file> <string-to-replace> <replacement-string>\n"
#define FILE_ERR "Can't open File!\n"
#define EMPTY_ERR "Empty args\n"

class Replace
{
    private:
        std::string _infileName;
        std::string _outfileName;
        std::string _toFind;
        std::string _replace;
    public:

        bool    parseInput(char **av);
        void    setOutFilename(std::string filename);
        void    setInFilename(std::string filename);
        void    setToFind(std::string tofind);
        void    setReplace(std::string replace);
        std::string getInFilename();
        std::string getToFind();
        std::string getReplace();
        std::string getOutFilemame();
};

#endif