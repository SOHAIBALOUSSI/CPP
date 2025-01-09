#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat hamid("hamid", 11);
        Form form1("A", 10, 100);
        Form form2("B", 20, 100);

        hamid.signForm(form1);
        hamid.signForm(form2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    Form form1("A", 10, 100);
    std::cout << "\n";
    std::cout << form1;
}