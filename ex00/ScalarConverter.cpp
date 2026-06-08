#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) {*this = other;}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}
ScalarConverter::~ScalarConverter() {}

static bool isNan(double d) {
    return (d != d);
}

static bool isInf(double d) {
    return (d > std::numeric_limits<double>::max() ||
            d < std::numeric_limits<double>::min());
}

void ScalarConverter::printFromChar(char c) {
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::printFromInt(int i) {
    std::cout << "char: ";
    if (i < 0 || i > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(i))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(i) << "'" << std::endl;

    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void ScalarConverter::printFromFloat(float f) {
    std::cout << "char: ";
    if (f < 0 || f > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(f)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(f) << "'" << std::endl;

    std::cout << "int: ";
    if (static_cast<int>(f) > INT_MAX || static_cast<int>(f) < INT_MIN || f != f)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(f) << std::endl;

    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
}

void ScalarConverter::printFromDouble(double d) {
    std::cout << "char: ";
    if (isNan(d) || isInf(d) || d < 0 || d > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(d)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;

    std::cout << "int: ";
    if (d > INT_MAX || d < INT_MIN || d != d)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;

    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::convert(const std::string& literal) {

	if (literal == "nan" || literal == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl; 
		std::cout << "float: nanf" << std::endl; 
		std::cout << "double: nan" << std::endl; 
		return; 
	}
	else if (literal == "+inf" || literal == "+inff") { 
		std::cout << "char: impossible" << std::endl; 
		std::cout << "int: impossible" << std::endl; 
		std::cout << "float: +inff" << std::endl; 
		std::cout << "double: +inf" << std::endl; 
		return; 
	} 
	else if (literal == "-inf" || literal == "-inff") { 
		std::cout << "char: impossible" << std::endl; 
		std::cout << "int: impossible" << std::endl; 
		std::cout << "float: -inff" << std::endl; 
		std::cout << "double: -inf" << std::endl; 
		return; 
	}
    else if (literal.length() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0]))) {
        printFromChar(literal[0]);
        return;
    }
    else if (literal.find('.') != std::string::npos && (literal[literal.length() - 1] == 'f' ||
         literal[literal.length() - 1] == 'F')) {
        char* end;

        float f = std::strtof(literal.c_str(), &end);

        std::cout << "ggggggggggggggg" << f << std::endl;
        if ((*end == 'f' || *end == 'F') && *(end + 1) == '\0') {

            printFromFloat(f);
            return;
        }
        std::cout << "invalid literal" << std::endl;
        return;
    }
    else if (literal.find('.') != std::string::npos) {
        char* end;

        double d = std::strtod(literal.c_str(), &end);

        if (*end == '\0')
        {
            printFromDouble(d);
            return;
        }

        std::cout << "invalid literal" << std::endl;
        return;
    }
    else {
        char* end;

        long l = std::strtol(literal.c_str(), &end, 10);

        if (*end == '\0')
        {
            if (l < INT_MIN || l > INT_MAX)
            {
                std::cout << "char: ";
                if (l < 0 || l > 127)
                    std::cout << "impossible" << std::endl;
                else if (!std::isprint(l))
                    std::cout << "Non displayable" << std::endl;
                else
                    std::cout << "'" << static_cast<char>(l) << "'" << std::endl;

                std::cout << "int: impossible" << std::endl;
                std::cout << "float: " << static_cast<float>(l) << ".0f" << std::endl;
                std::cout << "double: " << static_cast<double>(l) << ".0" << std::endl;
                return;
            }
            int i = atoi(literal.c_str());

            printFromInt(i);
            return;
        }
    }
    std::cout << "invalid literal" << std::endl;
}