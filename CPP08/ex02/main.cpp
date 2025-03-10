#include "MutantStack.hpp"
#include <ctime>

int main()
{   
    srand(time(0));
    MutantStack<int> mutan;
    for (int i = 0; i < 10; i++) {
        mutan.push(rand() % 100);
    }
    mutan.pop();
    mutan.pop();
    mutan.pop();
    mutan.pop();
    mutan.pop();


    MutantStack<int> copy(mutan);
    
    MutantStack<int> copy2;
    copy2 = copy;

    
    for (MutantStack<int>::iterator it = copy2.begin(); it != copy2.end(); it++) {
        std::cout << "val it = " << *it << std::endl;
    }
}