#include "MibibliotecaGameJam.h"


const int ALTO = 40;
const int ANCHO = 120;
Celda** pantalla;

// Posiciones de los carros en el eje X y Y
int posX[] = { 0, 2, 1, 2, 0, 2 };
int posY[] = { 21, 14, 18, 24, 10, 7 };	

namespace funcionesMenu {
	void ConfigurarPantalla() {
		Console::SetWindowSize(ANCHO, ALTO);
		Console::SetBufferSize(ANCHO, ALTO);
		Console::SetCursorPosition(0, 0);
		Console::CursorVisible = false;
		Console::Title = "GAME JAM 2025";
		Console::ForegroundColor = ConsoleColor::White;
	}
	// Se uso IA para generar ReproducirAudio
	void ReproducirAudio(String^ ruta) {
		SoundPlayer^ player = gcnew SoundPlayer(ruta);
		try
		{
			player->Load();
			player->Play();
		}
		catch (Exception^ e)
		{
			Console::WriteLine("Error al reproducir el audio: " + e->Message);
		}
	}
	void InicializarPantalla() {
		pantalla = new Celda * [ALTO];
		for (int i = 0; i < ALTO; i++) {
			pantalla[i] = new Celda[ANCHO];
			for (int j = 0; j < ANCHO; j++) {
				pantalla[i][j].simbolo = L' ';
				pantalla[i][j].color = ConsoleColor::Black;
			}
		}
	}
	void LimpiarPantalla() {
		for (int i = 0; i < ALTO; i++) {
			delete[] pantalla[i];
		}
		delete[] pantalla;
	}
	void mostrarPantalla() {
		for (int i = 0; i < ALTO; i++) {
			for (int j = 0; j < ANCHO; j++) {
				Console::ForegroundColor = pantalla[i][j].color;
				Console::SetCursorPosition(j, i);
				Console::Write(pantalla[i][j].simbolo);
			}
		}
	}
	void DibujarFigura(Figura& figura) {
		for (int i = 0; i < figura.altura; i++) {
			for (int j = 0; j < figura.ancho; j++) {
				wchar_t c = figura.dato[i][j];
				if (c != L' ') {
					int x = figura.x + j;
					int y = figura.y + i;

					if (y >= 0 && y < ALTO && x >= 0 && x < ANCHO) {
						pantalla[y][x].simbolo = c;
						ConsoleColor color = figura.funcionColor ? figura.funcionColor(i, j, c) : figura.color;

						pantalla[y][x].color = color;
					}
				}
			}
		}
	}
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
		DibujarFigura(Titulo);
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
		DibujarFigura(jugarBtn);
	}

	ConsoleColor PistaCondicion(int fila, int columna, wchar_t c) {
		if (c == L'▓' || c == L'≡') return ConsoleColor::DarkGray;
		if (c == L'*' || c == L'▓') return ConsoleColor::Gray;
	}
	void Pista() {
		const wchar_t* pista[] = {
			L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
			L"▓▓*******************************************************************************************************************▓▓",
			L"▓▓*******************************************************************************************************************▓▓",
			L"▓▓*******************************************************************************************************************▓▓",
			L"▓▓*******************************************************************************************************************▓▓",
			L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
			L"≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡",
			L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
			L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
			L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
			L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
			L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
			L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
			L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
			L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
			L"▓▓▓▓▓▓▓▓▓█████████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓███████████▓▓▓",
			L"▓▓▓▓▓▓▓▓▓█████████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓███████████▓▓▓",
			L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
			L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
			L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
			L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
			L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
			L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
			L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
			L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
			L"≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡",
		};
		int longitud = wcslen(pista[0]);
		Figura pistaFigura = {
			pista,
			0,
			5,
			26,
			longitud,
			ConsoleColor::DarkGray,
			nullptr
		};
	}
	// Se hizo uso de la IA para generar las matrices de los carros
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
		DibujarFigura(protagonista);
	}
	void Carro2() {
		const wchar_t* CarroS[] = {
			L"      ._____.      ",
			L"  -._*-|≡≡ b|-*---¬_ ",
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
		DibujarFigura(protagonista);
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
		DibujarFigura(protagonista);
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
		DibujarFigura(protagonista);
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
		DibujarFigura(protagonista);
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
		DibujarFigura(protagonista);
	}
	void ActualizarCarro() {
		Random f;
		int velocidades[6];
		for (int i = 0; i < 6; i++) {
			velocidades[i] = f.Next(1, 110);
			if (posX[i] <= ANCHO) {
				posX[i] += velocidades[i];
			}
		}
	}
	void CambiarDePantalla() {
		const wchar_t* upc[] = {
			L"                                            ",
			L"                      █                     ",
			L"                     ██                     ",
			L"     █              ██               █      ",
			L"    ███            ████             ███     ",
			L"    ███           ██████            ███     ",
			L"   ████          ████████          ████     ",
			L"   ████           ████████          ████    ",
			L"   █████           ██████          █████    ",
			L"   ██████           █████         ██████    ",
			L"    █████            ███          █████     ",
			L"    ███████         ███         ███████     ",
			L"     ████████       █         ████████      ",
			L"     █████████████████████████████████      ",
			L"      ███████████████████████████████       ",
			L"        ████████████████████████████        ",
			L"           ██████████████████████           ",
			L"                                            ",
			L"                 ╦ ╦╔═╗╔═╗                  ",
			L"                 ║ ║╠═╝║                    ",
			L"                 ╚═╝╩  ╚═╝                  ",
			L"                                            ",
			L"                                            ",
		};
		int longitud = wcslen(upc[0]);
		Figura pantallaFinal = {
			upc,
			ANCHO / 2 - (longitud / 2),
			ALTO / 2 - 15,
			23,
			longitud,
			ConsoleColor::DarkRed,
			nullptr
		};
		DibujarFigura(pantallaFinal);
	}
	void RedibujarCarros() {
		ActualizarCarro();
		InicializarPantalla();
		Carro1();
		Carro2();
		Carro3();
		Carro4();
		Carro5();
		Carro6();
		mostrarPantalla();
	}

	void AnimarCarro() {
		ReproducirAudio("audios/Carrera.wav");
		while (true)
		{
			RedibujarCarros();

			bool terminar = true;
			for (int i = 0; i < 6; i++) {
				if (posX[i] < ANCHO) {
					terminar = false;
					break;
				}
			}
			if (terminar) {
				break;
			}

			_sleep(20);
		}
		CambiarDePantalla();
		mostrarPantalla();
	}
	void Menu() {
		LimpiarPantalla();
		InicializarPantalla();
		DibujarMenu();
		ReproducirAudio("audios/MenuMusica.wav");
		DibujarJugar();
		mostrarPantalla();
	}
}

int main() {
	funcionesMenu::ConfigurarPantalla();

	funcionesMenu::AnimarCarro();
	_sleep(1000);
	funcionesMenu::Menu();
	return getch();
}
