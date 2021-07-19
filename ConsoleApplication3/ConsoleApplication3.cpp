#include <iostream>
#include <tuple>

/*
	Реализация паттерна "Пара"
	Конструирование пары объектов с инициализацией.
*/
template<class T, class S>
struct my_pair
{
	my_pair(T a, S b) : first(a), second(b) {};
	my_pair& operator= (my_pair& obj) { return *this; };
	T first;
	S second;
};

my_pair<int, int> func_my_pair(int dividend, int divider)
{
	my_pair<int, int> answer(dividend / divider, dividend % divider);
	return answer;
}

/* Использование "pair" из библиотеки STD */
std::pair<int, int> func_pair(int dividend, int divider)
{
	std::pair<int, int> answer(dividend / divider, dividend % divider);
	return answer;
}

int main()
{
	auto answer = func_my_pair(10, 4);
	std::cout << answer.first << " " << answer.second << std::endl;

	auto divide = func_pair(10, 4);
	std::cout << divide.first << " " << answer.second << std::endl;

	/*
	Истользование кортежа для коструирования неограниченного количества объектов.
	Необходимо подключать библиотеку #include <tuple>
	*/
	std::tuple<int, char, std::string> tup(3, 't', "My String");
	std::cout << std::get<0>(tup);
	std::cout << " " << std::get<1>(tup);
	std::cout << " " << std::get<2>(tup).c_str();

	return 0;
}