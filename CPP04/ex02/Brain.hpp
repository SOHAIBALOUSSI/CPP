#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain &copy);
		Brain& operator=(const Brain &assign);
		~Brain();

		void	setBrainIdeas(std::string idea, size_t count);
		void	printIdeas(size_t count);


};

#endif