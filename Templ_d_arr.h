// Высоцкая И.Д.
#pragma once // директива в С++, для предотвращения многократного включения одного и того же заголовочного файла
#include <iostream>
#include <algorithm> // библиотека С++ для определения функции для различных целей(нужна для работы с функцией max)

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
        m_data = nullptr;
    }

    /// Конструктор копирования
    /// Создает копию существующего массива. Он нужен для того, чтобы при создании 
    /// копии массива выделить новую память для хранения данных копии массива и скопировать туда все элементы
    /// const dynamic_array<T>& a - массив
    dynamic_array(const dynamic_array<T>& a)
    {
        m_size = a.m_size;
        m_capacity = m_size;
        m_data = nullptr;
        if (m_size != 0) // если фактический размер массива не равен 0
            m_data = new T[m_size];
        else
            m_data = 0;
        copy(a.m_data, a.m_data+m_size, m_data);
    }

    /// Оператор присваивания копированием
    /// const dynamic_array<T>& a - массив
    dynamic_array<T>& operator =(const dynamic_array<T>& a)
    {
        if (this != &a) // проверка на самокопирование
        {
            return dynamic_array(a);
        }
        return *this;
    }

    /// Конструктор перемещения
    /// Перемещает элементы со старого массива в новый, удаляя старый
    /// dynamic_array<T>&& a - массив
    dynamic_array(dynamic_array<T>&& a)
    {
        m_size = a.m_size;
        m_capacity = m_size;
        m_data = nullptr;
        if (m_size != 0) // если фактический размер массива не равен 0
            m_data = new T[m_size];
        else
            m_data = 0;
        copy(a.m_data, a.m_data + m_size, m_data);
        a.del();
    }

    /// Оператор присваивания перемещением
    dynamic_array<T>& operator =(dynamic_array<T>&& a)
    {
        if (this != &a) // проверка на самокопирование
        {
            return dynamic_array(a);
        }
        return *this;
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
            m_data = nullptr;
    }

    /// Деструктор
    /// Необходим для того, чтобы освободить выделенную память при удалении объекта
    ~dynamic_array()
    {
        if (m_data)
            delete[] m_data;
    }

    /// Изменение размера массива
    /// сравниваем новый размер массива с удвоенным фактическим размером, чтобы память не выделялась слишком часто
    /// size_t size - новый размер массива
    void resize(size_t size)
    {
        if (size > m_capacity) // если новый размер больше зарезервиравванной памяти под массив
        {
            size_t new_capacity = max(size, m_size * 2); // сравниваем новый размер массива с удвоенным фактическим размером
            T* new_data = new T[new_capacity](); // выделяется новая область памяти
            copy(m_data, m_data + m_size, new_data); // элементы массива копируются из старой области памяти в новую(m_data - начало старого массива, m_data + m_size - конец старого массива, new_data - ссылка куда копируем)
            delete[] m_data;
            m_data = new_data;
            m_capacity = new_capacity;
        }
        m_size = size;
    }

    /// Добавление одного нового элемента в конец массива
    /// T val - элемент, который нужно добавить в массив
    void push_back(T val)
    {
        resize(m_size + 1);
        m_data[m_size - 1] = val;
    }

    /// Добавление одного нового элемента в начало массива
    /// T val - элемент, который нужно добавить в маассив 
    void push_front(T val)
    {
        // переписываем массив во временный
        size_t tsize = size();
        T* temp = new T[tsize];
        copy(m_data, m_data + tsize, temp);

        // изменяем размер массива и переписываем элементы
        resize(m_size + 1);
        copy(temp, temp + tsize, m_data + 1);
        m_data[0] = val;
        delete[] temp;
    }

    /// Добавление одного нового элемента по позиции
    /// T val - элемент, который нужно добавить в маассив, size_t pos - позиция элемента в массиве
    void push_index(T val, size_t pos)
    {
        if (pos - 1 >= size())
        {
            push_back(val);
            return;
        }
        // переписываем массив правее позиции во временный
        size_t tsize = size()-pos+1;
        T* temp = new T[tsize];
        copy(m_data+pos-1, m_data + size(), temp);

        // изменяем размер массива и переписываем элементы
        resize(m_size + 1);
        copy(temp, temp + tsize, m_data + pos);
        m_data[pos-1] = val;
        delete[] temp;
    }

    /// Удаление одного элемента из конца массива  
    void pop_back()
    {
        if (m_size > 0)
        {
            resize(m_size - 1);
        }
    }

    /// Удаление одного элемента из начала массива
    T pop_front()
    {
        T elem = m_data[0];
        if (m_size > 0)
        {
            if (m_size > 1)
            {
                size_t tsize = size();
                T* temp = new T[tsize];
                copy(m_data, m_data + tsize, temp);
                copy(temp + 1, temp + tsize, m_data); // смещение массива на один элемент влево
                delete[] temp;
            }
            resize(m_size - 1);
        }
        return elem;
    }

    /// Удаление одного элемента из массива по индексу
    /// size_t ind - индекс элемента в массиве
    void pop_index(size_t ind)
    {
        if (m_size > 0)
        {
            if (m_size > 1)
            {
                size_t tsize = size()- ind;
                T* temp = new T[tsize];
                copy(m_data+ ind +1, m_data + size(), temp);
                copy(temp, temp + tsize, m_data+ ind); // смещение массива на один элемент влево
                delete[] temp;
            }
            resize(m_size - 1);
        }
    }

    /// Очищение данных массива с сохранением массива
    void del()
    {
        if (m_data)
        {
            delete[] m_data;
            m_data = nullptr;
        }
        m_size = 0;
        m_capacity = 1;
        m_data = new T[m_capacity];
    }

    /// Возвращение размера массива
    size_t size() const
    {
        return m_size;
    }

    /// Перегрузка оператора [] для доступа к элементам массива для чтения, изменения
    /// проверка индекса
    /// size_t i - индекс
    T& operator[] (size_t i) const
    {
        if (i >= size())
        {
            throw out_of_range("Индекс за пределами массива");
        }
        return m_data[i];
    }
};

/// Тесты
void test();