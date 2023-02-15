// Move.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <conio.h>
#include <locale.h>
#include "Screen.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");
	Screen* screen = new Screen();
		    screen->Run(55,15); // Install pos X and Y cooords for show
}


