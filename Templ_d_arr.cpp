// �������� �.�.
#include "Templ_d_arr.h"
#include <cassert>

void test()
{
	// ����� ��� ������������ �� ���������
	dynamic_array<int> arr_1;
	assert(arr_1.size() == 0);

	// ����� ��� ������������ � �����������
	dynamic_array<int> arr_2(5);
	assert(arr_2.size() == 5);
	assert(arr_2[4] == 0);

	// ����� ��� ������������ �����������
	dynamic_array<int> arr_3(4);
	dynamic_array<int> arr_4(arr_3);
	assert(arr_3.size() == 4);
	assert(arr_4.size() == 4);

	// ����� ��� ��������� ������������ ������������
	dynamic_array<int> arr_13(4);
	dynamic_array<int> arr_14 = arr_13;
	assert(arr_13.size() == 4);
	assert(arr_14.size() == 4);

	dynamic_array<int> arr_431 = arr_431; // �������� �� ���������������
	assert(arr_431.size() == 0);


	// ����� ��� ������������ �����������
	dynamic_array<int> arr_31(4);
	dynamic_array<int> arr_41(move(arr_31));
	assert(arr_31.size() == 0);
	assert(arr_41.size() == 4);

	// ����� ��� ��������� ������������ ������������
	dynamic_array<int> arr_32(4);
	dynamic_array<int> arr_42 = move(arr_32);
	assert(arr_31.size() == 0);
	assert(arr_41.size() == 4);
	dynamic_array<int> arr_44 = move(arr_44);
	assert(arr_44.size() == 0);


	// ����� ��� �������� �� ���������� �������� � ����� �������
	dynamic_array<int> arr_5(3);
	arr_5.push_back(2); // � ����������� ������
	assert(arr_5.size() == 4);
	assert(arr_5[3] == 2);

	arr_5.push_back(3); // ��� ���������� ������
	assert(arr_5.size() == 5);
	assert(arr_5[4] == 3);

	// ����� ��� �������� �� ���������� �������� � ������ �������
	dynamic_array<int> arr_6(4);
	arr_6.push_front(3); // � ����������� ������
	assert(arr_6.size() == 5);
	assert(arr_6[0] == 3);

	arr_6.push_front(5); // ��� ���������� ������
	assert(arr_6.size() == 6);
	assert(arr_6[0] == 5);

	// ����� ��� �������� �� ���������� �������� � ������ �� �������
	dynamic_array<int> arr_11(5);
	arr_11.push_index(1, 3); // � ����������� ������
	assert(arr_11.size() == 6);
	assert(arr_11[2] == 1);

	arr_11.push_index(1, 5); // ��� ���������� ������
	assert(arr_11.size() == 7);
	assert(arr_11[4] == 1);

	// ����� ��� �������� ������� �� �������
	dynamic_array<int> arr_7(5);
	arr_7[2] = 5;
	assert(arr_7[2] == 5);

	// ����� ��� �������� �� �������� �������� �� ������ �������
	dynamic_array<int> arr_8(5);
	for (size_t i = 0; i < arr_8.size(); i++)
	{
		arr_8[i] = i;
	}
	arr_8.pop_front();
	assert(arr_8.size() == 4);
	assert(arr_8[0] == 1);

	// ����� ��� �������� �� �������� �������� �� ����� �������
	dynamic_array<int> arr_9(5);
	for (size_t i = 0; i < arr_9.size(); i++)
	{
		arr_9[i] = i;
	}
	arr_9.pop_back();
	assert(arr_9.size() == 4);
	assert(arr_9[3] == 3);

	// ����� ��� �������� �� �������� �������� �� �������
	dynamic_array<int> arr_12(5);
	for (size_t i = 0; i < arr_12.size(); i++)
	{
		arr_12[i] = i;
	}
	arr_12.pop_index(3);
	assert(arr_12.size() == 4);
	assert(arr_12[3] == 4);

	// ����� ��� �������� ��������� ������� �������
	dynamic_array<int> arr_10(5);
	assert(arr_10.size() == 5);
	arr_10.resize(11);
	assert(arr_10.size() == 11);
	arr_10.resize(4);
	assert(arr_10.size() == 4);

	// ���� �� �������� �������� ���������� ��� ��������� []
	dynamic_array<int> arr_45(5);
	try // �������� ��������� �������� � ������� �����
	{
		arr_45[6];
		assert(false);
	}
	catch (const out_of_range&)
	{

	}
}