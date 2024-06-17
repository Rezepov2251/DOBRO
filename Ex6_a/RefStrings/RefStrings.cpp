#include <iostream>
#include "Str.h"

// Функция для тестирования метода reverse
void testReverse(const char* str) {
    Str s(str);
    std::cout << "Original: " << s << std::endl;
    s.reverse();
    std::cout << "Reversed: " << s << std::endl;
}

int main() {
    // Тест оператора +=
    Str s1("Hello, ");
    Str s2("World!");

    s1 += s2;

    std::cout << "Concatenated string: " << s1 << std::endl;
    std::cout << "Length of concatenated string: " << s1.len() << std::endl;

    // Тесты для метода reverse
    testReverse("abcdefg");
    testReverse("racecar");
    testReverse("madam");
    testReverse("a");

    return 0;
}
