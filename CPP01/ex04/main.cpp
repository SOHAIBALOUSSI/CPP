#include <iostream>
#include <fstream>
#include "replace.hpp"



int main(int ac, char **av)
{
    if (ac != 4) { std::cout << USAGE_ERR; return 1; }

    std::string infileName = av[1];
    std::string toFind = av[2];
    std::string replace = av[3];
    if (infileName.empty() || toFind.empty() || replace.empty()) {
        std::cout << EMPTY_ERR;
        return 1;
    }
    std::string outfileName = infileName + ".replace";
    std::ifstream infile(infileName.c_str());
    if (infile.good() == false) { std::cout << INFILE_ERR; return 1;}
    std::ofstream outfile(outfileName.c_str());
    std::string line;
    while (std::getline(infile, line))
    {
        size_t pos = 0;
        while ((pos = line.find(toFind))!= std::string::npos)
        {
            std::string newLine = "";
            for (size_t i = 0; i < line.length(); i++) {
                if (i == pos) {
                    newLine += replace;
                    i += toFind.length() - 1;
                } else {
                    newLine += line[i];
                }
            }
            line = newLine;
            pos = line.find(toFind, pos + replace.length());
        }
        outfile << line << "\n";
    }
    outfile.close();
    infile.close();
    return 0;
}