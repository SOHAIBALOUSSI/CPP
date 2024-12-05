#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain's constructor called\n";
    for (size_t i = 0; i < 100; i++) {
        ideas[i] = "NONE";
    }
}

Brain::Brain(const Brain &copy)
{
    std::cout << "Brain's copy constructor called\n";
    for (int i = 0; i < 100 ; i++) {
        ideas[i] = copy.ideas[i];
    }
}

Brain& Brain::operator=(const Brain &assign)
{
    std::cout << "Brain's copy assignment called\n";
    if (this != &assign)
    {
        for (int i = 0; i < 100 ; i++) {
            ideas[i] = assign.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain's destructor called\n";
}


void	Brain::setBrainIdeas(std::string idea, size_t count)
{
	if (count > 100) { return ; }

	for (size_t i = 0; i < count; i++) {
		ideas[i] = idea; 
	}
}

void    Brain::printIdeas(size_t count)
{
    if (count > 100) { return ; }

	for (size_t i = 0; i < count; i++) {
		std::cout << ideas[i] << std::endl;
	}
}
