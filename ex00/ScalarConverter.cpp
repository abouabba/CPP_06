#include "ScalarConverter.hpp"

#include <iostream>
#include <cstdlib>   // std::strtod
#include <cctype>    // std::isdigit, std::isprint
#include <cmath>     // std::isnan, std::isinf
#include <climits>   // INT_MIN, INT_MAX

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::printAll(double d)
{
    // char
    std::cout << "char: ";
    if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
    {
        std::cout << "impossible" << std::endl;
    }
    else if (!std::isprint(static_cast<int>(d)))
    {
        std::cout << "Non displayable" << std::endl;
    }
    else
    {
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
    }

    // int
    std::cout << "int: ";
    if (std::isnan(d) || std::isinf(d) ||
        d < INT_MIN || d > INT_MAX)
    {
        std::cout << "impossible" << std::endl;
    }
    else
    {
        std::cout << static_cast<int>(d) << std::endl;
    }

    // float / double
    float f = static_cast<float>(d);

    // If the value is an integer, force ".0"
    if (!std::isnan(d) && !std::isinf(d) &&
        d == static_cast<int>(d))
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

void ScalarConverter::convert(const std::string& literal)
{
    // Special pseudo-literals
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

    // Single printable character
    if (literal.length() == 1 &&
        !std::isdigit(static_cast<unsigned char>(literal[0])))
    {
        printAll(static_cast<double>(literal[0]));
        return;
    }

    // Parse numeric literal
    char* end;
    double d = std::strtod(literal.c_str(), &end);

    // Nothing was parsed
    if (end == literal.c_str())
    {
        std::cout << "invalid literal" << std::endl;
        return;
    }

    // Check suffix
    std::string remainder(end);

    if (remainder.empty())
    {
        // Valid int or double
        printAll(d);
        return;
    }

    // Accept only a single 'f' or 'F'
    if ((remainder == "f" || remainder == "F"))
    {
        // Reject forms like "3f" or "42F"
        // Float literal should contain a decimal point.
        if (literal.find('.') == std::string::npos)
        {
            std::cout << "invalid literal" << std::endl;
            return;
        }

        printAll(d);
        return;
    }

    // Anything else is invalid
    std::cout << "invalid literal" << std::endl;
}