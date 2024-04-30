/*
 * conversion.cpp
 */

#include "ArtemisUtility.hpp"

char* ArtemisUtility::Conversion::floatToStr(float myFloat) {
	// Note: Only use this function once per stream call, or the output will be duplicated
	std::stringstream output;
	output << myFloat;
	std::string s = output.str();
	return (char*)s.c_str();
}

char* ArtemisUtility::Conversion::intToStr(int myInt) {
	// Note: Only use this function once per stream call, or the output will be duplicated
	std::stringstream output;
	output << myInt;
	std::string s = output.str();
	return (char*)s.c_str();
}
