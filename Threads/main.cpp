#include<iostream>
#include<thread>
#include<chrono>
#include<Windows.h>
//using namespace std;
using namespace std::literals::chrono_literals;

bool finish = false;
bool flag = true;

void plus()
{
	while (!finish)
	{
		std::cout << "+ ";
		//Sleep(100);
		std::this_thread::sleep_for(1s);
	}
}
void minus()
{
	while (!finish)
	{
		std::cout << "- ";
		//Sleep(100);
		std::this_thread::sleep_for(1s);
	}
}
void main()
{
	//plus();
	//minus();

	std::thread plus_thread(plus);
	std::thread minus_thread(minus);

	std::cin.get();
	finish = true;

	minus_thread.join();
	plus_thread.join();
}