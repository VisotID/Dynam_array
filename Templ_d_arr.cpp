// Высоцкая И.Д.
#include "Templ_d_arr.h"
#include <cassert>

void test()
{
	dynamic_array<int> arr_1;
	assert(arr_1.size() == 0);

	dynamic_array<int> arr_2(5);
	assert(arr_2.size() == 5);
	assert(arr_2[4] == 0);

	dynamic_array<int> arr_3(4);
	dynamic_array<int> arr_4(arr_3);
	assert(arr_3.size() == 4);
	assert(arr_4.size() == 4);

	dynamic_array<int> arr_5(3);
	arr_5.push_back(2);
	assert(arr_5.size() == 4);
	assert(arr_5[3] == 2);

	dynamic_array<int> arr_6(4);
	arr_6.push_front(3);
	assert(arr_6.size() == 5);
	assert(arr_6[0] == 3);

	dynamic_array<int> arr_7(5);
	arr_7[2] = 5;
	assert(arr_7[2] == 5);

	dynamic_array<int> arr_8(5);
	for (size_t i = 0; i < arr_8.size(); i++)
	{
		arr_8[i] = i;
	}
	arr_8.pop_front();
	assert(arr_8.size() == 4);
	assert(arr_8[0] == 1);

	dynamic_array<int> arr_9(5);
	for (size_t i = 0; i < arr_9.size(); i++)
	{
		arr_9[i] = i;
	}
	arr_9.pop_back();
	assert(arr_9.size() == 4);
	assert(arr_9[3] == 3);

	dynamic_array<int> arr_10(5);
	assert(arr_10.size() == 5);
	arr_10.resize(11);
	assert(arr_10.size() == 11);
	arr_10.resize(4);
	assert(arr_10.size() == 4);
}