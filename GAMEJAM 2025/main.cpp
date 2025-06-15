#include "MibibliotecaGameJam.h"


const int ALTO = 50;
const int ANCHO = 160;
int opcionMenu = 0;
Celda** pantalla;


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

	// Se hizo uso de la IA para generar las matrices de los carros

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

	// Animaciond de carga
	void AnimarCarro() {
		ReproducirAudio("audios/Carrera.wav");
		int i = 0;
		int inicioX = ANCHO / 2;
		while (i < 10)
		{
			Carros::RedibujarCarros();
			Console::SetCursorPosition(inicioX, ALTO - 10);
			Console::ForegroundColor = ConsoleColor::White;
			Console::Write("{0}%", (i + 1) * 100 / 10); 
			i++;
		}
		LimpiarPantalla();
		InicializarPantalla();
		CambiarDePantalla();
		mostrarPantalla();
	}
	void EliminarOpcion() {
		for (int i = 0; i < 10; i++) {
			int posx = 39;
			int posY = 15 + i;

			Console::SetCursorPosition(posx, posY);
			Console::Write("    ");
			
		}
	}
	
	void ImprimirOpcion(int x, int y, int fila, int columna) {
		for (int i = 0; i < fila; i++) {
			Console::SetCursorPosition(x, y + i);
			for (int j = 0; j < columna; j++) {
				Console::ForegroundColor = pantalla[y + i][x + j].color;
				Console::Write(pantalla[y + i][x + j].simbolo);
			}
		}
	}
	void OpcionAnimacion() {
		const wchar_t* opcionAnimacion[] = {
			L"██╗",
			L"██║",
			L"██║",
			L"██║",
		};

		int longitud = wcslen(opcionAnimacion[0]);
		Figura opcion = {
			opcionAnimacion,
			39,
			15 + 5*opcionMenu,
			4,
			longitud,
			ConsoleColor::Blue,
			nullptr,
		};
		DibujarFigura(opcion);
		ImprimirOpcion(39, 15 + 5*opcionMenu, 4, longitud);
	}
	void Menu() {
		Menu::DibujarMenu(); 
		Menu::DibujarJugar();
		Menu::DibujarSalir();
		OpcionAnimacion();
		mostrarPantalla();
	}
	void SeleccionarOpcion(int opcionMenu) {
		switch (opcionMenu) {
		case 0:
			LimpiarPantalla();
			AnimarCarro();
			Simulacion::DibujarSimulacion();
			break;
		case 1:
			LimpiarPantalla();
			exit(0);
		default:
			break;
		}
	}
	void ElejirOpcion() {
		LimpiarPantalla();
		InicializarPantalla();
		ReproducirAudio("audios/MenuMusica.wav");
		Menu();
		while (true) {
			if (_kbhit()) {
				int tecla = getch();

				switch (tecla)
				{
				case w:
					if (opcionMenu > 0) {
						opcionMenu--;
						EliminarOpcion();
						OpcionAnimacion();
					}
					break;
				case s:
					if (opcionMenu < 1) {
						opcionMenu++;
						EliminarOpcion();
						OpcionAnimacion();
					}
					break;
				case enter:
					SeleccionarOpcion(opcionMenu);
					break;
				}
			}
		}
	}

}



int main() {
	funcionesMenu::ConfigurarPantalla();

	funcionesMenu::AnimarCarro();
	_sleep(1000);

	funcionesMenu::ElejirOpcion();
	return getch();
}
