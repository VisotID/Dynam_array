// Высоцкая И.Д.
#pragma once // директива в С++, для предотвращения многократного включения одного и того же заголовочного файла
#include <iostream>
#include <algorithm>

using namespace std; // используем пространство имен std для того, чтобы не писать перед функциями cin, cout "std"

/// Шаблонный класс для работы с динамическим массивом
template <typename T>
class dynamic_array
{
private:
    size_t m_size; // фактический размер массива
    size_t m_capacity; // память выделенная под возможное количество элементов массива
    T* m_data; // указатель на область памяти, где хранятся сами элементы массива 
public:

    /// Конструктор по умолчанию
    /// Создает пустой массив, не содержащий элементов
    dynamic_array()
    {
        m_size = 0;
        m_capacity = 0;
        m_data = NULL;
    }

    /// Конструктор копирования
    /// Создает копию существующего массива. Он нужен для того, чтобы при создании 
    /// копии массива выделить новую память для хранения данных копии массива и скопировать туда все элементы
    /// const dynamic_array<T>& a - массив
    dynamic_array(const dynamic_array<T>& a)
    {
        m_size = a.m_size;
        m_capacity = m_size;
        m_data = NULL;
        if (m_size != 0)
            m_data = new T[m_size];
        else
            m_data = 0;
        for (size_t i = 0; i < m_size; ++i)
            m_data[i] = a.m_data[i];
    }

    /// Конструктор с параметрами, который создает массив заданного размера
    /// size_t size - размер массива
    dynamic_array(size_t size)
    {
        m_size = size;
        m_capacity = size;
        if (size != 0)
            m_data = new T[size]();
        else
            m_data = 0;
    }

    /// Деструктор
    /// Необходим для того, чтобы освободить выделенную память при удалении объекта
    ~dynamic_array()
    {
        if (m_data)
            delete[] m_data;
    }

    /// Изменение размера массива
    /// size_t size - новый размер массива
    void resize(size_t size)
    {
        if (size > m_capacity) // если новый размер больше зарезервиравванной памяти под массив
        {
            size_t new_capacity = max(size, m_size * 2);
            T* new_data = new T[new_capacity](); // выделяется новая область памяти
            for (size_t i = 0; i < m_size; ++i) // элементы массива копируются из старой области памяти в новую
                new_data[i] = m_data[i];
            delete[] m_data;
            m_data = new_data;
            m_capacity = new_capacity;
        }
        m_size = size;
    }

    /// Добавление одного нового элемента в конец массива
    /// T val - 
    void push_back(T val)
    {
        resize(m_size + 1);
        m_data[m_size - 1] = val;
    }

    /// 
    void push_front(T val)
    {
        size_t tsize = size();
        T* temp = new T[tsize];
        for (size_t i = 0; i < tsize; i++)
        {
            temp[i] = m_data[i];
        }

        resize(m_size + 1);
        for (size_t i = 0; i < tsize; i++)
        {
            m_data[i + 1] = temp[i];
        }
        m_data[0] = val;
        delete[] temp;
    }

    /// 
    void pop_back()
    {
        if (m_size > 0)
        {
            resize(m_size - 1);
        }
    }

    /// 
    void pop_front()
    {
        if (m_size > 0)
        {
            if (m_size > 1)
            {
                size_t tsize = size();
                T* temp = new T[tsize];
                for (size_t i = 0; i < tsize; i++)
                {
                    temp[i] = m_data[i];
                }
                for (size_t i = 1; i < tsize; i++)
                {
                    m_data[i - 1] = temp[i];
                }
                delete[] temp;
            }
            resize(m_size - 1);
        }
    }

    /// Возвращение размера массива
    size_t size() const
    {
        return m_size;
    }

    /// Перегрузка оператора [] для доступа к элементам массива
    /// Это позволит обращаться к элементам класса dynamic_array так же, как к элементам обычного массива: a[i]
    T& operator[] (size_t i)
    {
        return m_data[i];
    }
};

void test();