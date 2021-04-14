#include <iostream>
#include <cstring>
#include <unistd.h>
#include <cerrno>
#include <thread>

using namespace std;

void does_not(string* s)
{
	int i = 0;
	for(i = 0; i < 5; i++)
	{
		sleep(1);
		cout << *s;
	}
}

void does_too(string* s)
{
	int i = 0;
	for(i = 0; i < 5; i++)
	{
		sleep(1);
		cout << *s;
	}
}

int main ()
{
	string str_no = "А вот и нет!\n";
	string str_yes = "А вот и да!\n";
	thread t0(does_not, &str_no);
	thread t1(does_too, &str_yes);
	t0.join();
	t1.join();
	return 0;
}
