#include <iostream>
#include <iomanip>
#include <vector>
#include <functional>
#include <cmath>
#include <numbers>

using std::numbers::pi;//c++20

int main()
{
	setlocale(LC_ALL, "RU");
	std::vector<double>angles{ 30, 60, 90 };

	std::function<void(double)> mySin = [](double arg) ->void
	{
		std::cout << std::setprecision(3) <<  "sin: " << std::sin(arg * pi / 180) << " " << std::setprecision(1);
	};
	std::function<void(double)> myCos = [](double arg) ->void
	{
		std::cout << std::setprecision(3) << "cos: " << std::cos(arg * pi / 180) << " " << std::setprecision(1);
	};
	
	std::vector<std::function<void(double)>> functions { mySin, myCos };
	
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "[Входные данные]: ";
	for (const auto &angle : angles)
	{
		std::cout << angle << " ";
	}

	std::cout << std::endl;
	std::cout << "[Выходные данные]:\n";
	for (const auto &angle : angles) {
		std::cout << angle << ": ";
		for (const auto &function : functions)
			function(angle);
		std::cout << std::endl;
	}
}

