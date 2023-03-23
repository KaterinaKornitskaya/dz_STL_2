// dz_STL_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <vector>

/*
 В контейнере типа vector хранится набор целых чисел. Создайте функторы
 для решения следующих задач:
 1) Увеличение значений всех элементов контейнера на заданную константу;
 2) Удаление из контейнера элементов, равных искомому значению.
*/

// задание 2
class Del_elem
{
	int val;
public:
	Del_elem(int valP) : val(valP) {}

	// оператор () используется для сравнения элеменов контейнера
	// со значением, сохраненным в классе
	bool operator()(int a)
	{
		return a == val;
	}
};
int main1()
{
	// объявление и инициализация массива
	int arr[] = { 2,2,2,5,8,6,2,9,2,0 };
	// список заполняется значениями из массива ar
	std::list<int> a(arr, arr + 10);

	// вывод начального состояния списка
	std::cout << "Start list: " << '\n';
	for (int val : a)
	{
		std::cout << val << ' ';
	}
	std::cout << '\n';

	
	// удаление элементов со значениями 2 с использованием функтора:
	Del_elem f(2);   // создали объект (значение поля внутри объекта равно 2)
	a.remove_if(f);  // объект f вызывает метод перегрузка() для каждого 
	                 // эл-та контейнера
	// вывод итогового состояния списка
	std::cout << "Final list (after remove): \n";
	for (auto val : a)
	{
		std::cout << val << ' ';
	}
	std::cout << '\n';

	return 0;
}



// задание 1 - не получается
class Increase
{
	int val;
public:
	//Increase(int valP) : val(valP) {}
	
	int operator()( int a)  // перегрузка оператора ()
	{
		return  val+a;  // вернуть значение плюс число а
	}
	
	Increase operator+(const Increase& N)  // перегрузка +
	{
		Increase temp;
		temp.val = val + N.val;
		return temp;
	}
	
	// перегрузка <<
	friend std::ostream& operator<<(std::ostream&, const Increase&);
};
std::ostream& operator<<(std::ostream& out, const Increase& p)
{
	out << p.val << '\n';
	return out;
}

int main()
{
	// объявление и инициализация массива
	int arr[] = { 2,2,2,5,8,6,2,9,2,0 };
	// список заполняется значениями из массива ar
	std::vector<int> a(arr, arr + 10);

	// вывод начального состояния списка
	std::cout << "Start list: " << '\n';
	for (int val : a)
	{
		std::cout << val << ' ';
	}
	std::cout << '\n';

	
	Increase obj;  // создание объекта класса Увеличение	
	std::cout << "Finish list: " << '\n';
	for (int val : a)
	{
		// здесь я пыталась по разному написать, чтобы вывести увеличенное 
		// число, для этого думала и нужны будут перегрузки << и +
		// и никак не принимает
		std::cout << obj(2) << ' ';
	}
	std::cout << '\n';

	return 0;
}
