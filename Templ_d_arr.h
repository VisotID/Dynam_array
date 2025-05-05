// �������� �.�.
#pragma once // ��������� � �++, ��� �������������� ������������� ��������� ������ � ���� �� ������������� �����
#include <iostream>
#include <algorithm> // ���������� �++ ��� ����������� ������� ��� ��������� �����(����� ��� ������ � �������� max)

using namespace std; // ���������� ������������ ���� std ��� ����, ����� �� ������ ����� ��������� cin, cout "std"

/// ��������� ����� ��� ������ � ������������ ��������
template <typename T>
class dynamic_array
{
private:
    size_t m_size; // ����������� ������ �������
    size_t m_capacity; // ������ ���������� ��� ��������� ���������� ��������� �������
    T* m_data; // ��������� �� ������� ������, ��� �������� ���� �������� �������

public:

    /// ����������� �� ���������
    /// ������� ������ ������, �� ���������� ���������
    dynamic_array()
    {
        m_size = 0;
        m_capacity = 0;
        m_data = nullptr;
    }

    /// ����������� �����������
    /// ������� ����� ������������� �������. �� ����� ��� ����, ����� ��� �������� 
    /// ����� ������� �������� ����� ������ ��� �������� ������ ����� ������� � ����������� ���� ��� ��������
    /// const dynamic_array<T>& a - ������
    dynamic_array(const dynamic_array<T>& a)
    {
        m_size = a.m_size;
        m_capacity = m_size;
        m_data = nullptr;
        if (m_size != 0) // ���� ����������� ������ ������� �� ����� 0
            m_data = new T[m_size];
        else
            m_data = 0;
        copy(a.m_data, a.m_data+m_size, m_data);
    }

    /// �������� ������������ ������������
    /// const dynamic_array<T>& a - ������
    dynamic_array<T>& operator =(const dynamic_array<T>& a)
    {
        if (this != &a) // �������� �� ���������������
        {
            return dynamic_array(a);
        }
        return *this;
    }

    /// ����������� �����������
    /// ���������� �������� �� ������� ������� � �����, ������ ������
    /// dynamic_array<T>&& a - ������
    dynamic_array(dynamic_array<T>&& a)
    {
        m_size = a.m_size;
        m_capacity = m_size;
        m_data = nullptr;
        if (m_size != 0) // ���� ����������� ������ ������� �� ����� 0
            m_data = new T[m_size];
        else
            m_data = 0;
        copy(a.m_data, a.m_data + m_size, m_data);
        a.del();
    }

    /// �������� ������������ ������������
    dynamic_array<T>& operator =(dynamic_array<T>&& a)
    {
        if (this != &a) // �������� �� ���������������
        {
            return dynamic_array(a);
        }
        return *this;
    }

    /// ����������� � �����������, ������� ������� ������ ��������� �������
    /// size_t size - ������ �������
    dynamic_array(size_t size)
    {
        m_size = size;
        m_capacity = size;
        if (size != 0)
            m_data = new T[size]();
        else
            m_data = nullptr;
    }

    /// ����������
    /// ��������� ��� ����, ����� ���������� ���������� ������ ��� �������� �������
    ~dynamic_array()
    {
        if (m_data)
            delete[] m_data;
    }

    /// ��������� ������� �������
    /// ���������� ����� ������ ������� � ��������� ����������� ��������, ����� ������ �� ���������� ������� �����
    /// size_t size - ����� ������ �������
    void resize(size_t size)
    {
        if (size > m_capacity) // ���� ����� ������ ������ ������������������ ������ ��� ������
        {
            size_t new_capacity = max(size, m_size * 2); // ���������� ����� ������ ������� � ��������� ����������� ��������
            T* new_data = new T[new_capacity](); // ���������� ����� ������� ������
            copy(m_data, m_data + m_size, new_data); // �������� ������� ���������� �� ������ ������� ������ � �����(m_data - ������ ������� �������, m_data + m_size - ����� ������� �������, new_data - ������ ���� ��������)
            delete[] m_data;
            m_data = new_data;
            m_capacity = new_capacity;
        }
        m_size = size;
    }

    /// ���������� ������ ������ �������� � ����� �������
    /// T val - �������, ������� ����� �������� � ������
    void push_back(T val)
    {
        resize(m_size + 1);
        m_data[m_size - 1] = val;
    }

    /// ���������� ������ ������ �������� � ������ �������
    /// T val - �������, ������� ����� �������� � ������� 
    void push_front(T val)
    {
        // ������������ ������ �� ���������
        size_t tsize = size();
        T* temp = new T[tsize];
        copy(m_data, m_data + tsize, temp);

        // �������� ������ ������� � ������������ ��������
        resize(m_size + 1);
        copy(temp, temp + tsize, m_data + 1);
        m_data[0] = val;
        delete[] temp;
    }

    /// ���������� ������ ������ �������� �� �������
    /// T val - �������, ������� ����� �������� � �������, size_t pos - ������� �������� � �������
    void push_index(T val, size_t pos)
    {
        if (pos - 1 >= size())
        {
            push_back(val);
            return;
        }
        // ������������ ������ ������ ������� �� ���������
        size_t tsize = size()-pos+1;
        T* temp = new T[tsize];
        copy(m_data+pos-1, m_data + size(), temp);

        // �������� ������ ������� � ������������ ��������
        resize(m_size + 1);
        copy(temp, temp + tsize, m_data + pos);
        m_data[pos-1] = val;
        delete[] temp;
    }

    /// �������� ������ �������� �� ����� �������  
    void pop_back()
    {
        if (m_size > 0)
        {
            resize(m_size - 1);
        }
    }

    /// �������� ������ �������� �� ������ �������
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
                copy(temp + 1, temp + tsize, m_data); // �������� ������� �� ���� ������� �����
                delete[] temp;
            }
            resize(m_size - 1);
        }
        return elem;
    }

    /// �������� ������ �������� �� ������� �� �������
    /// size_t ind - ������ �������� � �������
    void pop_index(size_t ind)
    {
        if (m_size > 0)
        {
            if (m_size > 1)
            {
                size_t tsize = size()- ind;
                T* temp = new T[tsize];
                copy(m_data+ ind +1, m_data + size(), temp);
                copy(temp, temp + tsize, m_data+ ind); // �������� ������� �� ���� ������� �����
                delete[] temp;
            }
            resize(m_size - 1);
        }
    }

    /// �������� ������ ������� � ����������� �������
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

    /// ����������� ������� �������
    size_t size() const
    {
        return m_size;
    }

    /// ���������� ��������� [] ��� ������� � ��������� ������� ��� ������, ���������
    /// �������� �������
    /// size_t i - ������
    T& operator[] (size_t i) const
    {
        if (i >= size())
        {
            throw out_of_range("������ �� ��������� �������");
        }
        return m_data[i];
    }
};

/// �����
void test();