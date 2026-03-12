// deepseek rewrote gtests to casserts

#include <iostream>
#include <cassert>
#include <stdexcept>
#include "vector.cpp"

// Вспомогательная функция для вывода результатов
void printTestResult(const char* testName, bool passed) {
    std::cout << (passed ? "[✓] " : "[✗] ") << testName << std::endl;
}

// Тест конструкторов
void testConstructors() {
    std::cout << "\n=== Testing Constructors ===" << std::endl;
    
    // Конструктор по умолчанию
    vector<int> v1;
    assert(v1.empty());
    assert(v1.size() == 0);
    assert(v1.capacity() == 0);
    printTestResult("Default constructor", true);
    
    // Конструктор с размером и значением
    vector<int> v2(5, 42);
    assert(v2.size() == 5);
    assert(v2.capacity() >= 5);
    for (size_t i = 0; i < v2.size(); ++i) {
        assert(v2[i] == 42);
    }
    printTestResult("Size-value constructor", true);
    
    // Конструктор копирования
    vector<int> v3(v2);
    assert(v3.size() == v2.size());
    assert(v3.capacity() >= v3.size());
    for (size_t i = 0; i < v3.size(); ++i) {
        assert(v3[i] == v2[i]);
    }
    
    // Проверка глубокого копирования
    v3[0] = 100;
    assert(v2[0] == 42);  // оригинал не изменился
    printTestResult("Copy constructor", true);
}

// Тест оператора присваивания
void testAssignment() {
    std::cout << "\n=== Testing Assignment Operator ===" << std::endl;
    
    vector<int> v1(3, 10);
    vector<int> v2;
    
    v2 = v1;
    assert(v2.size() == v1.size());
    assert(v2[0] == 10);
    assert(v2[1] == 10);
    assert(v2[2] == 10);
    
    // Проверка самоприсваивания
    v2 = v2;
    assert(v2.size() == 3);
    assert(v2[0] == 10);
    
    // Проверка глубокого копирования
    v2[0] = 20;
    assert(v1[0] == 10);
    
    printTestResult("Assignment operator", true);
}

// Тест доступа к элементам
void testAccess() {
    std::cout << "\n=== Testing Element Access ===" << std::endl;
    
    vector<int> v(3, 5);
    
    // operator[]
    v[0] = 10;
    v[1] = 20;
    v[2] = 30;
    assert(v[0] == 10);
    assert(v[1] == 20);
    assert(v[2] == 30);
    printTestResult("operator[]", true);
    
    // at() с проверкой
    try {
        v.at(0) = 15;
        assert(v.at(0) == 15);
        v.at(5);  // должно бросить исключение
        assert(false);  // не должны сюда попасть
    } catch (const std::out_of_range&) {
        // OK, ожидаемое исключение
        printTestResult("at() with bounds check", true);
    } catch (...) {
        assert(false);  // не то исключение
    }
    
    // front()
    assert(v.front() == 15);
    v.front() = 25;
    assert(v[0] == 25);
    
    // back()
    assert(v.back() == 30);
    v.back() = 35;
    assert(v[2] == 35);
    
    // data()
    int* dataPtr = v.data();
    assert(dataPtr[0] == 25);
    assert(dataPtr[1] == 20);
    assert(dataPtr[2] == 35);
    
    printTestResult("front/back/data", true);
    
    // Тесты для пустого вектора
    vector<int> empty;
    try {
        empty.front();
        assert(false);
    } catch (const std::out_of_range&) {
        printTestResult("front() on empty throws", true);
    }
    
    try {
        empty.back();
        assert(false);
    } catch (const std::out_of_range&) {
        printTestResult("back() on empty throws", true);
    }
}

// Тест capacity методов
void testCapacity() {
    std::cout << "\n=== Testing Capacity ===" << std::endl;
    
    vector<int> v;
    assert(v.empty());
    assert(v.size() == 0);
    assert(v.capacity() == 0);
    
    // reserve
    v.reserve(10);
    assert(v.capacity() == 10);
    assert(v.size() == 0);
    assert(v.empty());
    
    v.reserve(5);  // меньше текущей capacity
    assert(v.capacity() == 10);  // не должна уменьшаться
    
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    
    assert(v.size() == 3);
    assert(v.capacity() >= 3);
    assert(!v.empty());
    
    printTestResult("capacity/empty/size/reserve", true);
}

// Тест push_back и pop_back
void testPushPop() {
    std::cout << "\n=== Testing Push and Pop ===" << std::endl;
    
    vector<int> v;
    
    // push_back
    for (int i = 0; i < 10; ++i) {
        v.push_back(i * 10);
    }
    
    assert(v.size() == 10);
    for (int i = 0; i < 10; ++i) {
        assert(v[i] == i * 10);
    }
    
    // Проверка роста capacity
    size_t prevCapacity = v.capacity();
    v.push_back(100);
    assert(v.size() == 11);
    if (v.capacity() > prevCapacity) {
        std::cout << "  Capacity grew from " << prevCapacity 
                  << " to " << v.capacity() << std::endl;
    }
    
    // pop_back
    int last = v.back();
    v.pop_back();
    assert(v.size() == 10);
    assert(v.back() != last);
    
    // pop_back на пустом векторе
    vector<int> empty;
    try {
        empty.pop_back();
        assert(false);
    } catch (const std::out_of_range&) {
        printTestResult("pop_back on empty throws", true);
    }
    
    printTestResult("push_back/pop_back", true);
}

// Тест insert
void testInsert() {
    std::cout << "\n=== Testing Insert ===" << std::endl;
    
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    
    // Вставка в середину
    v.insert(2, 3);
    assert(v.size() == 4);
    assert(v[0] == 1);
    assert(v[1] == 2);
    assert(v[2] == 3);
    assert(v[3] == 4);
    
    // Вставка в начало
    v.insert(0, 0);
    assert(v.size() == 5);
    assert(v[0] == 0);
    assert(v[1] == 1);
    
    // Вставка в конец
    v.insert(v.size(), 5);
    assert(v.size() == 6);
    assert(v[5] == 5);
    
    // Проверка исключений
    try {
        v.insert(10, 100);  // индекс вне диапазона
        assert(false);
    } catch (const std::out_of_range&) {
        printTestResult("insert with invalid index throws", true);
    }
    
    printTestResult("insert", true);
}

// Тест clear
void testClear() {
    std::cout << "\n=== Testing Clear ===" << std::endl;
    
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    
    size_t oldCapacity = v.capacity();
    assert(v.size() == 10);
    
    v.clear();
    assert(v.size() == 0);
    assert(v.capacity() == oldCapacity);  // capacity не меняется
    assert(v.empty());
    
    // Можно добавлять после clear
    v.push_back(42);
    assert(v.size() == 1);
    assert(v[0] == 42);
    
    printTestResult("clear", true);
}

// Тест swap
void testSwap() {
    std::cout << "\n=== Testing Swap ===" << std::endl;
    
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    
    vector<int> v2;
    v2.push_back(10);
    v2.push_back(20);
    
    size_t v1Size = v1.size();
    size_t v2Size = v2.size();
    size_t v1Cap = v1.capacity();
    size_t v2Cap = v2.capacity();
    
    v1.swap(v2);
    
    assert(v1.size() == v2Size);
    assert(v2.size() == v1Size);
    assert(v1.capacity() == v2Cap);
    assert(v2.capacity() == v1Cap);
    
    assert(v1[0] == 10);
    assert(v1[1] == 20);
    assert(v2[0] == 1);
    assert(v2[1] == 2);
    assert(v2[2] == 3);
    
    printTestResult("swap", true);
}

// Тест с пользовательским типом
struct TestStruct {
    int a;
    double b;
    
    TestStruct(int x = 0, double y = 0.0) : a(x), b(y) {}
    bool operator==(const TestStruct& other) const {
        return a == other.a && b == other.b;
    }
};

void testCustomType() {
    std::cout << "\n=== Testing with Custom Type ===" << std::endl;
    
    vector<TestStruct> v(3, TestStruct(42, 3.14));
    
    assert(v.size() == 3);
    assert(v[0].a == 42);
    assert(v[0].b == 3.14);
    
    v[1].a = 100;
    v[1].b = 2.71;
    
    assert(v[1].a == 100);
    assert(v[1].b == 2.71);
    
    v.push_back(TestStruct(5, 1.23));
    assert(v.size() == 4);
    assert(v[3].a == 5);
    assert(v[3].b == 1.23);
    
    printTestResult("custom type", true);
}


int main() {
    std::cout << "==================================" << std::endl;
    std::cout << "   Vector Class Tests" << std::endl;
    std::cout << "==================================" << std::endl;
    
    try {
        testConstructors();
        testAssignment();
        testAccess();
        testCapacity();
        testPushPop();
        testInsert();
        testClear();
        testSwap();
        testCustomType();
        
        std::cout << "\n==================================" << std::endl;
        std::cout << "   ✅ ALL TESTS PASSED!" << std::endl;
        std::cout << "==================================" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "\n❌ Test failed with exception: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "\n❌ Test failed with unknown exception" << std::endl;
        return 1;
    }
    
    return 0;
}