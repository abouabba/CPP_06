# include "ScalarConverter.hpp"

int main() {

    ScalarConverter conv;
    std::string type;
    std::cout << "type your string :";
    if (!getline(std::cin, type)) {
        std::cout << "^D" << std::endl;
        return 1;
    }
    // if (!type.empty()) {
    //     std::cout << "you should type string" << std::endl;
    //     return 1;
    // }
    conv.convert(type);
    // std::cout << "char :" << type << std::endl;
}