#include "string.hpp"

#include <iostream>


size_t String::strlen(const char* s) {
    size_t len = 0;
    while (s && s[len] != '\0') ++len;

    return len;
}

void String::strcpy(char *to, const char *from) {
    if (!to || !from) return;
    while (*from != '\0') {
        *to = *from;
        to++;
        from++;
    }
    *to='\0';
}

void String::strcat(char* to, const char* from) {
    if (!to || !from) return;
    while (*to != '\0') {
        ++to;
    }
    while (*from != '\0') {
        *to = *from;
        to++;
        from++;
    }
    *to='\0';
}

/// like in cpp: <0 => s1<s2;   >0 => s1>s2
int String::strcmp(const char* s1, const char* s2) {
    if (!s1 && !s2) return true;
    if (!s1) return -1;
    if (!s2) return 1;

    while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
        ++s1;
        ++s2;
    }
    return static_cast<int>(*s1) - static_cast<int>(*s2);
}


String::String() : Data(nullptr) {}

String::String(const String& rhs) {
    if (rhs.Data) {
        Data = new char[strlen(rhs.Data) + 1];
        strcpy(Data, rhs.Data);
    } else {
        Data = nullptr;
    }
}

String::String(const char* data) {
    if (data) {
        Data = new char[strlen(data) + 1];
        strcpy(Data, data);
    } else {
        Data = nullptr;
    }
}

String::~String() {
    delete[] Data;
}

String& String::operator=(const String& rhs) {
    if (&rhs != this) {
        delete[] Data;

        if (rhs.Data) {
            Data = new char[strlen(rhs.Data) + 1];
            strcpy(Data, rhs.Data);
        } else {
            Data = nullptr;
        }
    }
    return *this;
}

String& String::operator+=(const String& rhs) {
    if (!rhs.Data) return *this;

    size_t len = strlen(rhs.Data);
    if (Data) len += strlen(Data);

    char* new_data = new char[len + 1];

    if (Data) strcpy(new_data, Data);
    strcat(new_data, rhs.Data);

    delete[] Data;
    Data = new_data;
    return *this;
}

String& String::operator*=(unsigned int m) {
    if (!Data || m == 0) {
        delete[] Data;
        Data = nullptr;
        return *this;
    }

    size_t len = strlen(Data) * m;
    char* new_data = new char[len + 1];

    for (unsigned int i = 0; i < m; ++i) {
        strcat(new_data, Data);
    }

    delete[] Data;
    Data = new_data;
    return *this;
}

bool String::operator==(const String& rhs) const {
    return strcmp(Data, rhs.Data) == 0;
}

bool String::operator<(const String& rhs) const {
    return strcmp(Data, rhs.Data) < 0;
}

size_t String::Find(const String& substr) const {
    if (!Data || !substr.Data) return -1;

    if (*substr.Data == '\0') return 0;

    char* temp_it = Data;
    while (*temp_it != '\0') {
        const char* base = temp_it;
        const char* newie = substr.Data;
        while (*base != '\0' && *newie != '\0' && *base == *newie) {
            ++base;
            ++newie;
        }
        if (*newie == '\0') {
            return temp_it-Data;
        }
        ++temp_it;
    }
    return -1;
}

void String::Replace(char oldSymbol, char newSymbol) {
    if (!Data) return;

    for (size_t i = 0; Data[i] != '\0'; ++i) {
        if (Data[i] == oldSymbol) Data[i] = newSymbol;
    }
}

size_t String::Size() const {
    return strlen(Data);
}

bool String::Empty() const {
    return !Data || Data[0] == '\0';
}

char String::operator[](size_t index) const {
    if (!Data || index > Size()) {
        throw std::out_of_range("wrong index");
    }
    return Data[index];
}

char& String::operator[](size_t index) {
    if (!Data || index > Size()) {
        throw std::out_of_range("wrong index");
    }
    return Data[index];
}

void String::RTrim(char symbol) {
    if (!Data) return;

    size_t new_len = strlen(Data);

    while (new_len > 0 && Data[new_len - 1] == symbol) {
        --new_len;
    }
    Data[new_len] = '\0';
}

void String::LTrim(char symbol) {
    if (!Data) return;

    size_t start = 0;
    while (Data[start] == symbol) ++start;

    if (start > 0) {
        for (size_t i = 0; i <= strlen(Data) - start; ++i) {
            Data[i] = Data[i + start];
        }
    }
}

void String::swap(String& oth) {
    char* temp = Data;
    Data = oth.Data;
    oth.Data = temp;
}

std::ostream& operator<<(std::ostream& out, const String& str) {
    if (str.Data) out << str.Data;

    return out;
}

String operator+(const String& a, const String& b) {
    String result = a;
    result += b;
    return result;
}

String operator*(const String& a, unsigned int b) {
    String result = a;
    result *= b;
    return result;
}

bool operator!=(const String& a, const String& b) {
    return !(a == b);
}

bool operator>(const String& a, const String& b) {
    return b < a;
}