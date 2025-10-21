#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <cctype>
#include <limits>
#include <cfloat>
#include <cstdlib>
#include <string>

enum type {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    NAN,
    POS_INF,
    NEG_INF,
};

class ScalarConverter {
private:
	static char _char;
	static int _int;
	static float _float;
	static double _double;
public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();

	static bool isChar(const std::string &literal);
	static bool isInt(const std::string &literal);
	static bool isFloat(const std::string &literal);
	static bool isDouble(const std::string &literal);
    
    static void convertToChar(const std::string &literal);
    static void convertToInt(const std::string &literal);
    static void convertToFloat(const std::string &literal);
    static void convertToDouble(const std::string &literal);
	static void convert(const std::string &literal);
};

#endif