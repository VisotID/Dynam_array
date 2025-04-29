// Высоцкая И.Д.
#include "Templ_d_arr.h"


int main()
{
    test();

    // заполнение массива по умолчанию
    dynamic_array<int> arr(8);
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    arr[0] = 9; // меняем первый элемент на 9
    arr.push_back(5); // добавляем 5 в конец массива
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    arr.pop_front(); // удаляем элемент из начала массива
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    arr.push_front(8); // добавляем в начало массива элемент 8
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    dynamic_array<int> arr2(arr);
    for (size_t i = 0; i < arr2.size(); i++)
    {
        cout << arr2[i] << " ";
    }
    cout << "\n";

    arr.push_front(7);
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    arr.push_index(1, 10); // добавляем 1 на 5 место в массиве
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    arr.pop_index(4);
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}