#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
    // std::string fileName = av[0];
    std::string str1 = "Batman";
    std::string str2 = "Hello";
    std::ifstream file1("test.txt");
    if (!file1) {
        std::cerr << "Error opening file";
        return 1;
    }
    std::string buff;
    std::string tmp;
    std::string valid;
    while (std::getline(file1, tmp))
    {
        size_t pos = tmp.find(str2);
        if (pos != std::string::npos)
        {
            valid = tmp.substr(0, pos);
            valid += str2;
            valid += tmp.substr(pos + str2.size(), tmp.size());
        }
        buff +='\n';
        buff += valid;
    }
    std::cout << buff;
    return 0;
}