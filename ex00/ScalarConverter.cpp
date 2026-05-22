#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) {*this = other;}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}
ScalarConverter::~ScalarConverter() {}

// static bool isNan(double d) {
//     return (d != d);
// }

// static bool isInf(double d) {
//     return (d > std::numeric_limits<double>::max() ||
//             d < -std::numeric_limits<double>::max());
// }

void ScalarConverter::printAll(double d) {
    std::cout << "char: ";
    if (d < 0 || d > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(d)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;

    std::cout << "int: ";
    if (d < INT_MIN || d > INT_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;

    float f = static_cast<float>(d);

    std::cout << "float: " << std::fixed << std::setprecision(2) << f << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(2) << d << std::endl;
}

void ScalarConverter::convert(const std::string& literal) {
    if (literal == "nan" || literal == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }

    if (literal == "+inf" || literal == "+inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        return;
    }

    if (literal == "-inf" || literal == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return;
    }

    if (literal.length() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0])))
    {
        printAll(static_cast<double>(literal[0]));
        return;
    }
    
    char* end;
    double d = std::strtod(literal.c_str(), &end);

    if (end == literal.c_str())
    {
        std::cout << "invalid literal" << std::endl;
        return;
    }

    std::string remainder(end);

    if (remainder.empty())
    {
        printAll(d);
        return;
    }

    if ((remainder == "f" || remainder == "F"))
    {
        if (literal.find('.') == std::string::npos)
        {
            std::cout << "invalid literal" << std::endl;
            return;
        }

        printAll(d);
        return;
    }
    std::cout << "invalid literal" << std::endl;
}