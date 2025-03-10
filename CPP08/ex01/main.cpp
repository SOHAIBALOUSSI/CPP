#include "Span.hpp"

int main() {
    srand(time(0));

    try {
        Span span(10);
        for (int i = 0; i < 10; i++) {
            span.addNumber(i + 1);
        }
        int shortest, longest;
        shortest = span.shortestSpan();
        longest = span.longestSpan();
        
        std::cout << "shortest span = " << shortest << std::endl;
        std::cout << "longest span = " << longest << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << std::endl;
    
    try {
        Span spanobj(10000);
        spanobj.fillRange();
        int shortest, longest;
        shortest = spanobj.shortestSpan();
        longest = spanobj.longestSpan();

        std::cout << "shortest span = " << shortest << std::endl;
        std::cout << "longest span = " << longest << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}