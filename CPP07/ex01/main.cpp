#include "iter.hpp"
#include "template.hpp"

void    Functolower(char& c){
    c = tolower(c);
}

void    toUpper(char& c) {
    c = toupper(c);
}

int main() {

    std::cout << "iter for array of ints and using an instantiated function template\n";
    {
        int  arr[5] = {5, 4, 3, 2, 1};

        iter(arr, 5, print<int>);
    }
    
    std::cout << std::endl;

    std::cout << "iter for array of chars\n";
    {
        char arr[6] = "abcde";
        iter(arr, 6, toUpper);
        iter(arr, 6, print<char>);
    }
}