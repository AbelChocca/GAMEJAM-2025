#pragma once
#include <iostream>
#include <conio.h>
#using <System.dll>

using namespace std;
using namespace System;
using namespace System::Media;

struct Posiciones {
	int x, y;
};
struct Celda {
	wchar_t simbolo;
	ConsoleColor color;
};
using FuncionColor = ConsoleColor(*)(int, int, wchar_t);
struct Figura {
	const wchar_t** dato;
	int x, y;
	int altura, ancho;
	ConsoleColor color;
	FuncionColor funcionColor;
};


namespace funcionesMenu {
	void DibujarMenu();

}




