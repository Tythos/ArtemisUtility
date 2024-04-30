/**
 * String.cpp
 */

#include "ArtemisUtility.hpp"

ArtemisUtility::String::String() {
	isInit = false;
	string = NULL;
}

ArtemisUtility::String::String(const char* s) {
	// Track initialization
	isInit = false;

	// Determine length (assume null-terminated)
	int n = 0;
	while (s[n] != NULL) {
		n++;
	}

	// Create new string
	length = n;
	string = new char[length];

	// Copy string
	for (int i = 0; i < length; i++) {
		string[i] = s[i];
	}
	isInit = true;
}

ArtemisUtility::String::String(const String& s) {
	// Check
	isInit = false;
	if (!s.isInit) { return; }

	// Intialize
	length = s.length;
	string = new char[length];

	// Copy
	for (int i = 0; i < length; i++) {
		string[i] = s[i];
	}
	isInit = true;
}

ArtemisUtility::String::String(const int i) {
	// Create string from int
	char b[64];
	int l = sprintf_s(b, 64, "%d", i);
	length = l;

	// Copy chars to buffer
	string = new char[length];
	for (int i = 0; i < l; i++) {
		string[i] = b[i];
	}
	isInit = true;
}

ArtemisUtility::String::String(const float f) {
	// Create string from float, using 3 point precision and scientific notation
	char b[64];
	int l = sprintf_s(b, 64, "%.2f", f);
	length = l;

	// Copy chars to buffer
	string = new char[length];
	for (int i = 0; i < l; i++) {
		string[i] = b[i];
	}
	isInit = true;
}

ArtemisUtility::String::~String() {
	if (isInit) {
		delete[] string;
	}
	isInit = false;
}

char ArtemisUtility::String::operator[](int n) {
	char toReturn;
	if (n < length) {
		toReturn = string[n];
	} else {
		toReturn = string[length-1];
	}
	return toReturn;
}

const char ArtemisUtility::String::operator[](int n) const {
	char toReturn;
	if (n < length) {
		toReturn = string[n];
	} else {
		toReturn = string[length-1];
	}
	return toReturn;
}

char * ArtemisUtility::String::raw() {
	// Returns a pointer to a raw null-terminated char array; WILL CAUSE MEMORY LEAKS IF NOT USED CORRECTLY
	if (!isInit) { return NULL; }
	char * copy = new char[length+1];
	for (int i = 0; i < length; i++) {
		copy[i] = string[i];
	}
	copy[length] = NULL;
	return copy;
}

ArtemisUtility::String& ArtemisUtility::String::operator=(const ArtemisUtility::String &rhs) {
	// Check for self-assignment
	if (this == &rhs) {
		return *this;
	}
	isInit = false;

	// Delete old string
	if (isInit) {
		delete[] string;
	}

	// Copy length and characters
	length = rhs.length;
	string = new char[length];
	for (int i = 0; i < length; i++ ) {
		string[i] = rhs[i];
	}

	// Declare initialized, return
	isInit = true;
	return *this;
}

ArtemisUtility::String& ArtemisUtility::String::operator=(const char* rhs) {
	// Delete old string
	if (isInit) {
		delete[] string;
	}
	isInit = false;

	// Determine length (assume null-terminated)
	int n = 0;
	while (rhs[n] != NULL) { n++; }

	// Create new string
	length = n;
	string = new char[length];

	// Copy string
	for (int i = 0; i < length; i++) {
		string[i] = rhs[i];
	}

	// Declare initialized
	isInit = true;
	return *this;
}

ArtemisUtility::String ArtemisUtility::String::operator+=(const ArtemisUtility::String &rhs) {
	// Check initialization
	if (!isInit || !rhs.isInit) { return ArtemisUtility::String(""); }

	// Copy current string (and rhs, in case of self-assignment)
	ArtemisUtility::String newLhs = *this;
	ArtemisUtility::String newRhs = rhs;

	// Destroy current string
	delete[] string;

	// Create new string from newLhs + newRhs
	length = newLhs.getLength() + newRhs.getLength();
	string = new char[length];

	// Copy char from LHS, then RHS
	int i;
	for (i = 0; i < newLhs.getLength(); i++) {
		string[i] = newLhs[i];
	}
	for (i = newLhs.getLength(); i < length; i++) {
		string[i] = newRhs[i - newLhs.getLength()];
	}

	// Initialize and return
	isInit = true;
	return *this;
}

const ArtemisUtility::String ArtemisUtility::String::operator+(const ArtemisUtility::String &rhs) {
	ArtemisUtility::String toReturn = (*this);
	toReturn += rhs;
	return toReturn;
}

bool ArtemisUtility::String::operator==(const ArtemisUtility::String &rhs) const {
	if (!isInit || !rhs.isInit) { return false; }
	if (length != rhs.length) { return false; }
	for (int i = 0; i < length; i++) {
		if (string[i] != rhs[i]) { return false; }
	}
	return true;
}

bool ArtemisUtility::String::operator!=(const ArtemisUtility::String &rhs) const {
	return !((*this) == rhs);
}
