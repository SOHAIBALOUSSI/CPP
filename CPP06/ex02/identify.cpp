#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

typedef Base* (*instance)();

Base* createA() { return new A(); }

Base* createB() { return new B(); }

Base* createC() { return new C(); }

Base * generate(void) {
    srand(time(0));
    instance Instances[3] = { &createA, &createB, &createC };
    return Instances[rand() % 3]();
}

void identify(Base* p) {

    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    }
    else {
        std::cout << "C" << std::endl;
    }
}

void identify(Base& p) {

    bool isA = true;
    bool isB = true;
    bool isC = true;

    try {
        (void)dynamic_cast<A&>(p);
    }
    catch(const std::bad_cast& e) {
        isA = false;
    }
    if (isA) {
        std::cout << "A" << std::endl; 
        return ;
    }
        
    try {
        (void)dynamic_cast<B&>(p);
    }
    catch(const std::exception& e) {
        isB = false;
    }
    if (isB) {
        std::cout << "B" << std::endl;
        return ;
    }

    try { 
        (void)dynamic_cast<C&>(p);
    }
    catch(const std::exception& e) {
        isC = false;
    }
    if (isC) {
        std::cout << "C" << std::endl;
        return ;
    }
}

int main() {
    Base* ptr = generate();
    Base& ptr2 = *ptr;
    identify(ptr);
    identify(ptr2);
}