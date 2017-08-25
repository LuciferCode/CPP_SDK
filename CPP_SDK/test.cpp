#include "test.h"
#include <Windows.h>
#include <iostream>
#include "stopwatch.hpp"
#include "datetime.h"

void TestStopwatch()
{
	Stopwatch<> watch;
	watch.Start();
	Sleep(2000);
	std::cout << watch.Restart() << std::endl;
	Sleep(3000);
	std::cout << watch.Restart() << std::endl;
	std::cout << watch.Elapsed() << std::endl;
}

void TestDateTime()
{

	DateTime d2(1000000);
	d2 += 89389;
	std::cout << d2 - 111 << std::endl;
}