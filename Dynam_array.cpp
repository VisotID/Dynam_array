// Высоцкая И.Д.
#include "Templ_d_arr.h"


int main()
{
    test();
    dynamic_array<int> arr(8);
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    arr[0] = 9;
    arr.push_back(5);
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    arr.pop_front();
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    arr.push_front(8);
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}