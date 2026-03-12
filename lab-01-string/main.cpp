// rewrote tests from lab

#include <iostream>
#include <cassert>
#include <sstream>
#include "string.hpp"

void testConstructAssign() {
    std::cout << "=== Test: ConstructAssign ===" << std::endl;

    const char* data = "some string";

    String s0(data);
    s0[0] = 'S';
    String s1(s0);
    s1[5] = 'S';

    String s2;
    s2 = s1;
    s2[0] = 's';

    assert(s0 == String("Some string") && "s0 should be 'Some string'");
    assert(s1 == String("Some String") && "s1 should be 'Some String'");
    assert(s2 == String("some String") && "s2 should be 'some String'");
    assert(String(data) == String("some string") && "String(data) should be 'some string'");

    std::cout << "OK ConstructAssign passed" << std::endl;
}

void testGetByIndex() {
    std::cout << "=== Test: GetByIndex ===" << std::endl;

    const char* data = "some string";

    const String s1(data);
    assert(s1[0] == 's' && "s1[0] should be 's'");
    assert(s1[2] == 'm' && "s1[2] should be 'm'");
    assert(s1[5] == 's' && "s1[5] should be 's'");

    String s(data);
    s[2] = 'M';
    s[5] = s[0] = 'S';

    assert(s[0] == 'S' && "s[0] should be 'S'");
    assert(s[2] == 'M' && "s[2] should be 'M'");
    assert(s[5] == 'S' && "s[5] should be 'S'");

    std::cout << "OK GetByIndex passed" << std::endl;
}

void testAppend() {
    std::cout << "=== Test: Append ===" << std::endl;

    String s1("some");
    s1 += " ";
    s1 += String("string");

    String s2 = String("some ") + String("string");

    assert(s1 == s2 && "s1 should equal s2 ('some string')");

    std::cout << "OK Append passed" << std::endl;
}

void testReplace() {
    std::cout << "=== Test: Replace ===" << std::endl;

    String s1("some string");
    s1.Replace('s', 'S');

    assert(s1 == String("Some String") && "s1 should be 'Some String'");

    std::cout << "OK Replace passed" << std::endl;
}

void testSize() {
    std::cout << "=== Test: Size ===" << std::endl;

    String s1("some");
    assert(s1.Size() == 4 && "s1 size should be 4");
    assert(String{}.Empty() && "Empty string should be empty");
    assert(!s1.Empty() && "s1 should not be empty");

    std::cout << "OK Size passed" << std::endl;
}

void testMult() {
    std::cout << "=== Test: Mult ===" << std::endl;

    String s1("ABC");
    s1 *= 2;
    assert(s1 == String("ABCABC") && "s1 should be 'ABCABC' (not 'ABCABCABC')");

    // Исправлено: 3 * 2 = 6 повторений, не 9
    String s2 = s1 * 3;
    assert(s2 == String("ABCABCABCABCABCABC") && "s2 should be 'ABCABC' * 3 = 18 chars");

    std::cout << "OK Mult passed" << std::endl;
}

void testTrim() {
    std::cout << "=== Test: Trim ===" << std::endl;

    String s("  abc   ____");
    s.RTrim('_');
    assert(s == String("  abc   ") && "after RTrim should be '  abc   '");

    s.LTrim(' ');
    assert(s == String("abc   ") && "after LTrim should be 'abc   '");

    s.RTrim(' ');
    assert(s == String("abc") && "after second RTrim should be 'abc'");

    std::cout << "OK Trim passed" << std::endl;
}

void testFind() {
    std::cout << "=== Test: Find ===" << std::endl;

    String s1("some string");
    assert(s1.Find(" ") == 4 && "find space should return 4");
    assert(s1.Find("str") == 5 && "find 'str' should return 5");
    assert(s1.Find("some") == 0 && "find 'some' should return 0");

    assert(String("str stri string").Find(String("string")) == 9 &&
           "find 'string' in 'str stri string' should return 9");
    assert(String("strinsstring").Find(String("string")) == 6 &&
           "find 'string' in 'strinsstring' should return 6");

    assert(s1.Find("not found") == static_cast<size_t>(-1) &&
           "find non-existent should return -1");

    std::cout << "OK Find passed" << std::endl;
}

void testStream() {
    std::cout << "=== Test: Stream ===" << std::endl;

    std::stringstream stream;
    String s1("some string");
    stream << s1 << " and " << String("stream");

    assert(stream.str() == "some string and stream" &&
           "stream output should match");

    std::cout << "OK Stream passed" << std::endl;
}

void testSwap() {
    std::cout << "=== Test: Swap ===" << std::endl;

    String s0("some string");
    String s1("other string");

    assert(s0 == String("some string") && "s0 initial value wrong");
    assert(s1 == String("other string") && "s1 initial value wrong");

    s0.swap(s1);

    assert(s0 == String("other string") && "s0 after swap wrong");
    assert(s1 == String("some string") && "s1 after swap wrong");

    std::cout << "OK Swap passed" << std::endl;
}

int main() {
    std::cout << "\n=== Running String Tests ===\n" << std::endl;

    testConstructAssign();
    testGetByIndex();
    testAppend();
    testReplace();
    testSize();
    testMult();
    testTrim();
    testFind();
    testStream();
    testSwap();

    std::cout << "\n=== All tests passed! ===\n" << std::endl;
    return 0;
}