#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

int main()
{
	setlocale(LC_ALL, "RU");
	std::vector<int> v1 = { 4,7,9,14,12 };
	std::cout << "Входные данные: ";
	for (const auto &el : v1)
	{
		std::cout << el << " ";
	}
	
	std::function<void(int)> oddMulti = [&](int i)
	{
		if (i == v1.size() - 1) { return; }
		if (v1.at(i) % 2 == 1) { v1.at(i) *= 3; }
		++i;
		oddMulti(i);
	};

	oddMulti(0);

	//вариант 2
	//std::for_each(v1.begin(), v1.end(), [](int &i) {if (i % 2 == 1) { i *= 2; }});	

	std::cout << "\nВыходные данные: ";
	for (const auto &el : v1)
	{
		std::cout << el << " ";
	}
}
