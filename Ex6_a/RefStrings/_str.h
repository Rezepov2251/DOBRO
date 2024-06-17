#pragma once
#include <string.h>

class Str; // Предварительная декларация

class _str {
    char* m_pszData; // Данные строки
    int m_nCount; // Счетчик ссылок

    friend class Str; // Дружественный класс

    // Конструктор по умолчанию
    _str() : m_pszData(new char[1] {0}), m_nCount(1) {}

    // Конструктор, принимающий C-строку
    _str(const char* p) : m_nCount(1) {
        m_pszData = new char[strlen(p) + 1];
        strcpy_s(m_pszData, strlen(p) + 1, p);
    }

    // Деструктор
    ~_str() {
        delete[] m_pszData;
    }

    // Увеличение счетчика ссылок
    void AddRef() {
        m_nCount++;
    }

    // Уменьшение счетчика ссылок и удаление объекта при необходимости
    void Release() {
        m_nCount--;
        if (m_nCount == 0) {
            delete this;
        }
    }
};
