#pragma once
#include "_str.h"
#include <algorithm> // для std::reverse

class Str {
    _str* m_pStr; // Указатель на ресурс строки

public:
    // Конструктор по умолчанию
    Str() : m_pStr(new _str) {}

    // Конструктор, принимающий C-строку
    Str(const char* p) : m_pStr(new _str(p)) {}

    // Деструктор
    ~Str() {
        m_pStr->Release();
    }

    // Возвращает длину строки
    int len() const {
        return strlen(m_pStr->m_pszData);
    }

    // Конструктор копирования
    Str(const Str& s) {
        m_pStr = s.m_pStr;
        m_pStr->AddRef();
    }

    // Оператор присваивания
    Str& operator=(const Str& s) {
        if (this != &s) {
            s.m_pStr->AddRef();
            m_pStr->Release();
            m_pStr = s.m_pStr;
        }
        return *this;
    }

    // Оператор добавления строки
    Str& operator+=(const Str& s) {
        int length = len() + s.len();
        if (s.len() != 0) {
            _str* pstrTmp = new _str;
            delete[] pstrTmp->m_pszData;
            pstrTmp->m_pszData = new char[length + 1];
            strcpy_s(pstrTmp->m_pszData, length + 1, m_pStr->m_pszData);
            strcat_s(pstrTmp->m_pszData, length + 1, s.m_pStr->m_pszData);
            m_pStr->Release();
            m_pStr = pstrTmp;
        }
        return *this;
    }

    // Оператор преобразования к типу const char*
    operator const char* () const {
        return m_pStr->m_pszData;
    }

    // Метод для реверса строки
    void reverse() {
        int length = len();
        if (length <= 1) return; // Если длина строки 0 или 1, ничего не делаем

        // Проверка на палиндром
        bool isPalindrome = true;
        for (int i = 0; i < length / 2; ++i) {
            if (m_pStr->m_pszData[i] != m_pStr->m_pszData[length - 1 - i]) {
                isPalindrome = false;
                break;
            }
        }

        if (isPalindrome) return; // Если строка палиндром, ничего не делаем

        // Копируем данные, чтобы избежать изменения других копий
        _str* pstrTmp = new _str(m_pStr->m_pszData);
        std::reverse(pstrTmp->m_pszData, pstrTmp->m_pszData + length);
        m_pStr->Release();
        m_pStr = pstrTmp;
    }
};
