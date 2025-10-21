#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	(void)other;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return *this;
}
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string &literal) {
	return (literal.length() == 1 && !std::isdigit(literal[0]));
}

bool ScalarConverter::isInt(const std::string &literal) {
	int x;
	std::stringstream ss(literal);
	return (ss >> x && ss.eof());
}
bool ScalarConverter::isDouble(const std::string &literal) {
	double x;
	std::stringstream ss(literal);
	return (ss >> x && ss.eof());
}

bool ScalarConverter::isFloat(const std::string &literal) {
	if(literal[literal.length() - 1] != 'f'){
		std::string temp = literal.substr(0, literal.length() - 1);
		return isDouble(temp);
	}
	return true;
}

void ScalarConverter::convertToChar(const std::string &literal) {
	char value = literal[0];
	
	if (std::isprint(value))
		std::cout << "char: '" << value << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout.precision(1);
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << std::fixed  << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << std::fixed << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convertToInt(const std::string &literal) {
	int value = std::atoi(literal.c_str());
	if (std::isprint(static_cast<char>(value)))
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else if (value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << value << std::endl;
	std::cout.precision(1);
	std::cout << "float: " << std::fixed << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << std::fixed << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convertToFloat(const std::string &literal) {
	float value = std::strtof(literal.c_str(), NULL);
	if (std::isprint(static_cast<char>(value)))
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else if (value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout.precision(1);
	std::cout << "float: " << std::fixed << value << "f" << std::endl;
	std::cout << "double: " << std::fixed << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convertToDouble(const std::string &literal) {
	double value = std::strtod(literal.c_str(), NULL);
	if (std::isprint(static_cast<char>(value)))
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else if (value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	if(value < -FLT_MAX || value > FLT_MAX)
		std::cout << "float: impossible" << std::endl;
	else{
		std::cout.precision(1);
		std::cout << "float: " << std::fixed << static_cast<float>(value) << "f" << std::endl;
	}
	std::cout << "double: " << std::fixed << value << std::endl;
}

void ScalarConverter::convert(const std::string &literal) {
	if (literal == "nan" || literal == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (literal == "-inf" || literal == "-inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (isChar(literal))
		convertToChar(literal);
	else if (isInt(literal))
		convertToInt(literal);
	else if (isFloat(literal))
		convertToFloat(literal);
	else if (isDouble(literal))
		convertToDouble(literal);
	else
		std::cerr << "Error: invalid literal" << std::endl;
}