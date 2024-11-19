
#include "replace.hpp"

bool    Replace::parseInput(char **av)
{
    setInFilename(av[1]);
    setToFind(av[2]);
    setReplace(av[3]);
    if (getInFilename().empty() || getToFind().empty()) {
        std::cout << EMPTY_ERR;
        return false;
    }
    setOutFilename(getInFilename() + ".replace");
    return true;
}

int main(int ac, char **av)
{
    if (ac != 4) { std::cout << USAGE_ERR; return 1; }
    
    Replace RepTool;
    if (RepTool.parseInput(av) == false) { return 1; }

    std::ifstream Infile(RepTool.getInFilename().c_str());
    if (Infile.fail() == true) {
        std::cout << FILE_ERR;
        return 1;
    }
    std::ofstream Outfile(RepTool.getOutFilemame().c_str());
    if (Outfile.fail() == true) {
        std::cout << FILE_ERR;
        return 1;
    }
    
    std::string line;
    while (std::getline(Infile, line))
    {
        size_t pos = 0;
        while ((pos = line.find(RepTool.getToFind(), pos)) != std::string::npos)
        {
            line = line.substr(0, pos) + RepTool.getReplace() + line.substr(pos + RepTool.getToFind().length());
            pos += RepTool.getReplace().length();
        }
        Outfile << line << "\n";
    }
    Infile.close();
    Outfile.close();
    return 0;
}