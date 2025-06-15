#include "MibibliotecaGameJam.h"


// Posiciones de los carros en el eje X y Y
int posX[] = { 0, 2, 1, 2, 0, 2 };
int posY[] = { 28, 24, 20, 17, 12, 9 };

namespace Carros {
	void ActualizarCarro() {
		Random f;
		int velocidades[6];
		for (int i = 0; i < 6; i++) {
			velocidades[i] = f.Next(1, 40);
			if (posX[i] <= ANCHO) {
				posX[i] += velocidades[i];
			}
			else {
				posX[i] = 0;
			}
		}
	}
	void Carro1() {
		const wchar_t* CarroS5[] = {
			L"                    ",
			L" |\\_/|..[]__\\__.._",
			L" '-( )------( )--=='"
		};
		int longitud = wcslen(CarroS5[0]);
		Figura protagonista = {
			CarroS5,
			posX[0],
			posY[0],
			3,
			longitud,
			ConsoleColor::DarkRed,
			nullptr,
		};
		funcionesMenu::DibujarFigura(protagonista);
	}
	void Carro2() {
		const wchar_t* CarroS[] = {
			L"      ._____.      ",
			L"  -._*-|## b|-*---¬_ ",
			L"  '( )'----'( )--'"
		};
		int longitud = wcslen(CarroS[0]);
		Figura protagonista = {
			CarroS,
			posX[1],
			posY[1],
			3,
			longitud,
			ConsoleColor::DarkBlue,
			nullptr
		};
		funcionesMenu::DibujarFigura(protagonista);
	}
	void Carro3() {
		const wchar_t* CarroS5[] = {
			L"     _______       ",
			L" ___//_||__\\\\_____ ",
			L"|_   ___    ___  `|",
			L"'-(_)------(_)--'-'"
		};

		int longitud = wcslen(CarroS5[0]);
		Figura protagonista = {
			CarroS5,
			posX[2],
			posY[2],
			4,
			longitud,
			ConsoleColor::DarkGreen,
			nullptr,
		};
		funcionesMenu::DibujarFigura(protagonista);
	}
	void Carro4() {
		const wchar_t* CarroDeportivo4[] = {
			L"    ____________    ",
			L" __/|_||___||_|\\___",
			L"|___    ___     ___|",
			L"'--(o)-------(o)--' "
		};

		int longitud = wcslen(CarroDeportivo4[0]);
		Figura protagonista = {
			CarroDeportivo4,
			posX[3],
			posY[3],
			4,
			longitud,
			ConsoleColor::DarkYellow,
			nullptr,
		};
		funcionesMenu::DibujarFigura(protagonista);
	}
	void Carro5() {
		const wchar_t* CarroDeportivo5[] = {
			L"                   ",
			L"  _    _           ",
			L"  \`../ |o_..__    ",
			L"  (_)______(_).>   "
		};

		int longitud = wcslen(CarroDeportivo5[0]);
		Figura protagonista = {
			CarroDeportivo5,
			posX[4],
			posY[4],
			4,
			longitud,
			ConsoleColor::DarkRed,
			nullptr,
		};
		funcionesMenu::DibujarFigura(protagonista);
	}
	void Carro6() {
		const wchar_t* Lamborghini[] = {
			L" ______--...\\____   ",
			L"\\____.______..`._\\ ",
			L" `=(_)'-----'(_)--=' ",
			L"                     "
		};

		int longitud = wcslen(Lamborghini[0]);
		Figura protagonista = {
			Lamborghini,
			posX[5],
			posY[5],
			4,
			longitud,
			ConsoleColor::DarkCyan,
			nullptr,
		};
		funcionesMenu::DibujarFigura(protagonista);
	}
	void RedibujarCarros() {
		ActualizarCarro();
		funcionesMenu::InicializarPantalla();
		Carro1();
		Carro2();
		Carro3();
		Carro4();
		Carro5();
		Carro6();
		funcionesMenu::mostrarPantalla();
	}
}