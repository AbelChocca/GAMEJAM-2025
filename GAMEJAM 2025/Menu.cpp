#include "MibibliotecaGameJam.h"

namespace Menu {
	void DibujarMenu() {
		const wchar_t* menu[] = {
			L"    ██████            █████       █████  █████████████     █████████        ████████      ",
			L"    ████████        ███████      ██████  █████████████    █████   ███      ███    ████    ",
			L"    █████████       ████▒▒       █████     ███████       █████     ███    ███      ████   ",
			L"   ██████████      ██▒▒▒▒       ███▒▒▒    ▒█████        ██████    ████   ██          ▒▒   ",
			L"   ████▒▒▒▒▒▒▒     ▒▒▒▒▒▒       ▒▒▒▒▒    ▒▒▒▒██        ██████████████    ▒▒          ▒▒   ",
			L"  ██▒▒▒   ▒▒▒▒▒    ▒▒▒▒▒▒     ▒▒▒▒▒     ▒▒▒▒▒▒        ███████████▒▒      ▒▒▒        ▒▒▒   ",
			L" ▒▒▒▒▒     ▒▒▒▒▒  ▒▒▒▒▒     ▒▒▒▒▒▒▒    ▒▒▒▒▒▒        ▒▒▒███    ▒▒▒▒▒     ▒▒▒▒▒     ▒▒▒    ",
			L" ▒▒▒▒▒     ▒▒▒▒▒▒▒▒▒▒▒      ▒▒▒▒▒▒    ▒▒▒▒▒▒        ▒▒▒▒▒       ▒▒▒▒▒     ▒▒▒▒▒▒▒▒▒▒      ",
		};
		int longitud = wcslen(menu[0]);
		Figura Titulo = {
			menu,
			ANCHO / 2 - (longitud / 2),
			5,
			8,
			longitud,
			ConsoleColor::Blue,
			nullptr
		};
		funcionesMenu::DibujarFigura(Titulo);
	}

	void DibujarJugar() {
		const wchar_t* jugar[] = {
			L"    █ █  █   ███    ██    ████ ",
			L"    █  █  █ █      █  █   █   █",
			L" ▒ ▒   ▒  ▒  ▒  ▒  ▒▒▒▒  ▒▒▒▒▒ ",
			L"  ▒     ▒▒    ▒▒   ▒  ▒ ▒    ▒ ",
		};
		int longitud = wcslen(jugar[0]);
		Figura jugarBtn = {
			jugar,
			ANCHO / 2 - (longitud / 2),
			15,
			4,
			longitud,
			ConsoleColor::Blue
		};
		funcionesMenu::DibujarFigura(jugarBtn);
	}
	void DibujarSalir() {
		const wchar_t* salir[] = {
			L"   ███   █    █    ███    ███  ",
			L"  █     █ ▒   █     █    █   █ ",
			L"   ███  ▒▒▒   ▒     ▒   ▒▒▒▒▒  ",
			L"  ▒▒▒▒ ▒   ▒  ▒▒▒  ▒▒▒ ▒    ▒  ",
		};
		int longitud = wcslen(salir[0]);
		Figura salirBtn = {
			salir,
			ANCHO / 2 - (longitud / 2),
			20,
			4,
			longitud,
			ConsoleColor::Red
		};
		funcionesMenu::DibujarFigura(salirBtn);
	}
}