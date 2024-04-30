/**
 * ArtemisUtility.hpp
*/

#pragma once

#include <sstream>
#include <stdio.h>

namespace ArtemisUtility {
    namespace Conversion {
        char * floatToStr(float myFloat);
        char * intToStr(int myInt);
    }

    namespace DataStructures {
    }

    class String {
    private:
        char* string;
        int length;
        bool isInit;
    protected:
    public:
        // Constructors
        String();
        String(const char * s);
        String(const String& s);
        String(const int i);
        String(const float f);
        ~String();

        // Accessors
        int getLength() { return length; }
        char operator[](int n);
        const char operator[](int n) const;
        char * raw();

        // Assignment
        String& operator=(const String &rhs);
        String& operator=(const char* rhs);

        // Concatenation
        String operator+=(const String &rhs);
        const String operator+(const String &rhs);

        // Comparison
        bool operator==(const String &rhs) const;
        bool operator!=(const String &rhs) const;
    };    
}
