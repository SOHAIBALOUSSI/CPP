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
    
    while (std::getline(file1, tmp))
    {
        size_t pos = tmp.find(str2);
        if (pos)
        {
            //
        }
        buff +='\n';
        buff += tmp;
    }
    std::cout << buff;
    return 0;
}