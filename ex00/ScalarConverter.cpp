# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter&) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) {return *this;}

ScalarConverter::~ScalarConverter() {}


bool isSpecial(std::string &s) {
    return (s == "nan" || s == "nanf" ||
            s == "+inff" || s == "-inff" ||
            s == "+inf" || s == "-inf");
}

void ScalarConverter::convert(std::string value) {

    if (isSpecial(value)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (value.back() == 'f') {
            std::cout << "float: " << value << std::endl;
            std::cout << "double: " << value.substr(0, value.size() - 1) << std::endl;
        }
        else {
            std::cout << "float: " << value + 'f' << std::endl;
            std::cout << "double: " << value << std::endl;
        }
        return ;
    }
    if (value.length() == 1 && !isdigit(value[0])) {

        std::cout << "char   :" << value[0] << std::endl;
        std::cout << "int    :" << static_cast<int>(value[0]) << std::endl;
        std::cout << "float  :" << static_cast<float>(value[0]) << ".0f" << std::endl;
        std::cout << "double :" << static_cast<double>(value[0]) << ".0" << std::endl;
        return ;
    }
    
}