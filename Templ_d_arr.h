// �������� �.�.
#pragma once // ��������� � �++, ��� �������������� ������������� ��������� ������ � ���� �� ������������� �����
#include <iostream>
#include <algorithm>

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
        m_data = NULL;
    }

    /// ����������� �����������
    /// ������� ����� ������������� �������. �� ����� ��� ����, ����� ��� �������� 
    /// ����� ������� �������� ����� ������ ��� �������� ������ ����� ������� � ����������� ���� ��� ��������
    /// const dynamic_array<T>& a - ������
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

    /// ����������� � �����������, ������� ������� ������ ��������� �������
    /// size_t size - ������ �������
    dynamic_array(size_t size)
    {
        m_size = size;
        m_capacity = size;
        if (size != 0)
            m_data = new T[size]();
        else
            m_data = 0;
    }

    /// ����������
    /// ��������� ��� ����, ����� ���������� ���������� ������ ��� �������� �������
    ~dynamic_array()
    {
        if (m_data)
            delete[] m_data;
    }

    /// ��������� ������� �������
    /// size_t size - ����� ������ �������
    void resize(size_t size)
    {
        if (size > m_capacity) // ���� ����� ������ ������ ������������������ ������ ��� ������
        {
            size_t new_capacity = max(size, m_size * 2);
            T* new_data = new T[new_capacity](); // ���������� ����� ������� ������
            for (size_t i = 0; i < m_size; ++i) // �������� ������� ���������� �� ������ ������� ������ � �����
                new_data[i] = m_data[i];
            delete[] m_data;
            m_data = new_data;
            m_capacity = new_capacity;
        }
        m_size = size;
    }

    /// ���������� ������ ������ �������� � ����� �������
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

    /// ����������� ������� �������
    size_t size() const
    {
        return m_size;
    }

    /// ���������� ��������� [] ��� ������� � ��������� �������
    /// ��� �������� ���������� � ��������� ������ dynamic_array ��� ��, ��� � ��������� �������� �������: a[i]
    T& operator[] (size_t i)
    {
        return m_data[i];
    }
};

void test();