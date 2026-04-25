#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { *this = other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::printAll(double d) {

    std::cout << "char: ";
    if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127) {
        std::cout << "impossible" << std::endl;
    } else if (!std::isprint(static_cast<int>(d))) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
    }


    std::cout << "int: ";
    if (std::isnan(d) || std::isinf(d) || d < INT_MIN || d > INT_MAX) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << static_cast<int>(d) << std::endl;
    }


    float f = static_cast<float>(d);

    // std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    // std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;

    if (d == static_cast<int>(d))
    {
        std::cout << "float: " << f << ".0f" << std::endl;
        std::cout << "double: " << d << ".0" << std::endl;
    }
    else
    {
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
}

void ScalarConverter::convert(const std::string& literal) {

    if (literal == "nan" || literal == "nanf") {
        std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan" << std::endl;
        return;
    }
    if (literal == "+inf" || literal == "+inff") {
        std::cout << "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf" << std::endl;
        return;
    }
    if (literal == "-inf" || literal == "-inff") {
        std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf" << std::endl;
        return;
    }

    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        printAll(static_cast<double>(literal[0]));
        return;
    }

    char* end;
    double d = std::strtod(literal.c_str(), &end);

    std::string remainder = end;
    if (remainder != "" && remainder != "f") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    printAll(d);
}
