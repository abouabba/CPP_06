# include "ScalarConverter.hpp"

int main(int ac, char **av) {

    ScalarConverter conv;
    if (ac != 2) {
        std::cout << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }
    conv.convert(av[1]);
}