#pragma once
#include <iostream>
#include <conio.h>
#using <System.dll>

#define w 119
#define s 115
#define enter 13
#define esc 27

using namespace std;
using namespace System;
using namespace System::Media;
using namespace System::Threading;

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

extern const int ANCHO;

namespace Carros {
	void RedibujarCarros();
}

namespace Menu {
	void DibujarMenu();
	void DibujarJugar();
	void DibujarSalir();
}

namespace funcionesMenu {
	void DibujarFigura(Figura& figura);
	void InicializarPantalla();
	void mostrarPantalla();
	void LimpiarPantalla();
}
namespace Simulacion {
	void DibujarSimulacion();
}




