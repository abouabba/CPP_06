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
 
void printchar(double d) {
    if (d < 0 || d > 127)
        std::cout << "char : impossible" << std::endl;
    else if (!isprint((char)d))
        std::cout << "char : Non displayable" << std::endl;
    else
        std::cout << "char : '" << (char)d << "'" << std::endl;
}

void printint(double d) {
    if(d < INT_MIN || d > INT_MAX)
        std::cout << "int : impossible" << std::endl;
    else
        std::cout << "int :" << (int)d << std::endl;
}

void printfloat(double d) {
    float f = (float)d;
    std::cout << "float :" << f;
    if (f == (int)f)
        std::cout << ".0";
    std::cout << "f" << std::endl;
}

void printdouble(double d) {
    std::cout << "double :" << d;
    if (d == (int)d)
        std::cout << ".0";
    std::cout << std::endl;
}

void ScalarConverter::convert(std::string value) { // "fgfsdvf"  "534" "3++4"

    if (isSpecial(value)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (value.size() - 1 == 'f') {
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

        std::cout << "char   :'" << value[0] << "'" << std::endl;
        std::cout << "int    :" << static_cast<int>(value[0]) << std::endl;
        std::cout << "float  :" << static_cast<float>(value[0]) << ".0f" << std::endl;
        std::cout << "double :" << static_cast<double>(value[0]) << ".0" << std::endl;
        return ;
    }
    try {
        std::stringstream dd(value);
        if (dd)
            throw std::invalid_argument("invalid literal");
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return ;
    }
    double ch = strtod(value.c_str(), NULL);

    printchar(ch);
    printint(ch);
    printfloat(ch);
    printdouble(ch);

    return;
}