#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <limits>
#include <iomanip>
#include <cmath>   
#include <cctype>

class ScalarConverter
{
    private:
    
        ScalarConverter();
        ScalarConverter(const ScalarConverter&);
        ScalarConverter& operator=(const ScalarConverter&);
        ~ScalarConverter();
    
        static void printFromChar(char c);
        static void printFromInt(int i);
        static void printFromFloat(float f);
        static void printFromDouble(double d);
    
    public:
    
        static void convert(const std::string& literal);
};

#endif
