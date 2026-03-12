#pragma once

#include <iostream>

class String {
private:
    char* Data;

    static size_t strlen(const char* s);
    static void strcpy(char* to, const char* from);
    static void strcat(char* to, const char* from);
    static int strcmp(const char* s1, const char* s2);
public:
  /// DN Деструктор
  ~String();

  /// DN Конструктор по умолчанию
  String();

  /// DN Конструктор копирования
  /// DN <param name="rhs">Объект, который копируем </param>
  String(const String& rhs);

  /// DN Пользовательский конструктор
  /// DN <param name="data">Данные, которые требуется поместить в создаваемый
  /// DN объект </param>
  String(const char* data);

  /// DN Оператор присваивания
  /// DN <param name="data">Объект, который копируем </param>
  /// DN <returns>Возвращаем ссылку на себя</returns>
  String& operator=(const String& rhs);

  /// DN Оператор +=
  /// DN <param name="rhs">Объект, который стоит после знака '+=' </param>
  /// DN <returns>Возвращаем ссылку на себя</returns>
  String& operator+=(const String& rhs);

  /// DN Оператор *=
  /// DN <returns>Возвращаем ссылку на себя</returns>
  String& operator*=(unsigned int m);

  /// DN Оператор ==
  /// DN <param name="rhs">Объект, который стоит после знака '==' </param>
  /// DN <returns>Возвращаем значения равенства двух строк</returns>
  bool operator==(const String& rhs) const;

  /// DN Оператор &lt;
  /// DN <param name="rhs">Объект, который стоит после знака "&lt;" </param>
  /// DN <returns>Возвращаем значения сравнения двух строк</returns>
  bool operator<(const String& rhs) const;

  /// DN Функция поиска подстроки
  /// <param name="substr">Подстрока, которую необходимо найти </param>
  /// <returns>Возвращаем позицию substr. Если подстрока не найдена, то
  /// возвратить -1</returns>
  size_t Find(const String& substr) const;

  /// DN Функция замены символов, заменяет все символы oldSymbol на newSymbol.
  /// <param name="oldSymbol">Символ, который требуется заменить </param>
  /// <param name="newSymbol">Символ, на который требуется заменить </param>
  void Replace(char oldSymbol, char newSymbol);

  /// DN Функция возвращает длину строки
  /// <returns>Возвращаем длину строки</returns>
  size_t Size() const;

  /// DN Функция для определения пуста ли строка
  bool Empty() const;

  /// DN Оператор []
  /// <example>
  /// <code>
  /// String str = "some string";
  /// char symbol = str[2]; // symbol == 'm'
  /// </code>
  /// </example>
  /// <param name="index"> Индекс символа </param>
  /// <returns> Значение символа в строке с индексом index</returns>
  char operator[](size_t index) const;

  /// DN Оператор []
  /// <example>
  /// <code>
  /// String str = "some string";
  /// str[0] = 'S'; // теперь переменная str равна "Some string"
  /// </code>
  /// </example>
  /// <param name="index"> Индекс символа </param>
  /// <returns> Ссылка на символ в строке с индексом index</returns>
  char& operator[](size_t index);

  /// N Смотри пример
  /// <example>
  /// <code>
  /// String str = "___some string___";
  /// str.RTrim('_'); // теперь переменная str равна "___some string"
  /// </code>
  /// </example>
  /// <param name="symbol"> Значение символов, которе отрезаем </param>
  void RTrim(char symbol);

  /// N Смотри пример
  /// <example>
  /// <code>
  /// String str = "___some string___";
  /// str.LTrim('_'); // теперь переменная str равна "some string___"
  /// </code>
  /// </example>
  /// <param name="symbol"> Значение символов, которе отрезаем </param>
  void LTrim(char symbol);

    /// N swap
  void swap(String& oth);
  /// N
  friend std::ostream& operator<<(std::ostream&, const String&);
};

/// Оператор +
/// <example>
/// <code>
/// String a = "Hello";
/// String b = "World";
/// String c = a + b; // c равна "HelloWorld"
/// </code>
/// </example>
/// <returns>Возвращаем строку равную a + b</returns>
String operator+(const String& a, const String& b);

/// Оператор +
/// <example>
/// <code>
/// String a = "A";
/// String c = a * 5; // c равна "AAAAA"
/// </code>
/// </example>
String operator*(const String& a, unsigned int b);

/// Оператор !=
bool operator!=(const String& a, const String& b);

/// Оператор >
bool operator>(const String& a, const String& b);
