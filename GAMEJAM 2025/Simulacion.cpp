#include "MiBibliotecaGameJam.h"


namespace Simulacion {
    void DibujarNecesario(Figura& figura) {
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

						Console::SetCursorPosition(x, y);
						Console::ForegroundColor = color;
						Console::Write(c);
					}
				}
            }
        }
    }
    void DibujarAutopista() {
        const wchar_t* autopista[] = {
            L"          /─────────────────────────────────────────────────────────────────────────────────────────────────────────\\            ",
            L"         /                                                                                                           \\           ",
            L"        /                                                                                                             \\          ",
            L"       /                                                                                                               \\         ",
            L"      /                                                                                                                 \\        ",
            L"     /                              ===========================================================                          \\       ",
            L"    /                                                                                                                     \\      ",
            L"    │                                                                                                                       │     ",
            L"    │                                                                                                                       │     ",
            L"    │                                                                                                                       │     ",
            L"    │                                     /───────────────────────────────────────────\\                                    │     ",
            L"    │                                    /                                             \\                                   │     ",
            L"    │                                   /                                               \\                                  │     ",
            L"    │                                  /                                                 \\                                 │     ",
            L"    │              ||                 /                                                   \\                ||              │     ",
            L"    │              ||                /                                                     \\               ||              │     ",
            L"    │              ||               /                                                       \\              ||              │     ",
            L"    │              ||              │                                                         │              ||              │     ",
            L"    │              ||              │                                                         │              ||              │     ",
            L"    │              ||              │                                                         │              ||              │     ",
            L"    │              ||              │                                                         │              ||              │     ",
            L"    │              ||              │                                                         │              ||              │     ",
            L"    │              ||              │                                                         │              ||              │     ",
            L"    │              ||              │                                                         │              ||              │     ",
            L"    │              ||              │                                                         │              ||              │     ",
            L"    │              ||              │                                                         │              ||              │     ",
            L"    │              ||              │                                                         |              ||              │     ",
            L"    │              ||              |                                                         │              ||              │     ",
            L"    │              ||              \\                                                       /               ||              │     ",
            L"    │              ||               \\                                                     /                ||              │     ",
            L"    │              ||                \\                                                   /                 ||              │     ",
            L"    │                                 \\                                                 /                                  │     ",
            L"    │                                  \\                                               /                                   │     ",
            L"    │                                   \\                                             /                                    │     ",
            L"    │                                    \\───────────────────────────────────────────/                                     │     ",
            L"    \\                                                                                                                     /      ",
            L"     \\                                                                                                                   /       ",
            L"      \\                                                                                                                 /        ",
            L"       \\                                                                                                               /         ",
            L"        \\                         ===========================================================                         /          ",
            L"         \\                                                                                                           /           ",
            L"          \\                                                                                                         /            ",
            L"           \\                                                                                                       /             ",
            L"            \\                                                                                                     /              ",
            L"             \\───────────────────────────────────────────────────────────────────────────────────────────────────/               ",
        };
        int longitud = wcslen(autopista[0]);
        Figura autopistaRef = {
            autopista,
            10,
            0,
            45,
            longitud,
            ConsoleColor::DarkGray,
            nullptr,
        };
        funcionesMenu::DibujarFigura(autopistaRef);
    }
    void MovInicial() {
        int posY[6] = { 35, 35, 35, 39, 40, 41 };
        int posX[6] = { 15, 17, 19, 21, 23, 25 };
		int limiteX[6] = { 30, 25, 18, 30, 25, 18 };
		ConsoleColor colores[6] = {
			ConsoleColor::DarkRed,
			ConsoleColor::DarkBlue,
			ConsoleColor::DarkGreen,
			ConsoleColor::DarkYellow,
			ConsoleColor::DarkRed,
			ConsoleColor::DarkCyan
		};
        const wchar_t* CarroS[] = {
            L" |\\_/|..[]__\\__.._",
            L" '-( )------( )--=='"
        };

        const wchar_t* CarroS2[] = {
            L"      ._____.        ",
            L"  -._*-|## b|-*---¬_ ",
            L"  '( )'----'( )--'   ",   
        };

        const wchar_t* CarroS3[] = {
            L"     _______        ",
            L" ___//_||__\\\\____ ",
            L"|_   ___    ___  `| ",
            L"'-(_)------(_)--'-' "
        };

        const wchar_t* CarroDeportivo4[] = {
            L" ___--¬____|\\___ ",
            L"|°_    ___    __\\",
            L"'-( )|≡≡≡≡≡|( )--' "
        };

        const wchar_t* CarroDeportivo5[] = {
            L"  _    _           ",
            L"  \`../ |o_..__    ",
            L"  (_)______(_).>   "
        };

        const wchar_t* Lamborghini[] = {
            L" ______--...\\____   ",
            L"\\____.______..`._\\ ",
            L" `=(_)'-----'(_)--=' ",
        };

		Figura carros[6] = {
			{ CarroS, posX[0], posY[0], 2, wcslen(CarroS[0]), colores[0], nullptr },
			{ CarroS2, posX[1], posY[1], 3, wcslen(CarroS2[0]), colores[1], nullptr },
			{ CarroS3, posX[2], posY[2], 4, wcslen(CarroS3[0]), colores[2], nullptr },
			{ CarroDeportivo4, posX[3], posY[3], 3, wcslen(CarroDeportivo4[0]), colores[3], nullptr },
			{ CarroDeportivo5, posX[4], posY[4], 3, wcslen(CarroDeportivo5[0]), colores[4], nullptr },
			{ Lamborghini, posX[5], posY[5], 3, wcslen(Lamborghini[0]), colores[5], nullptr }
		};

        for (int i = 0; i < 6; i++) {
            funcionesMenu::ReproducirAudio("audios/Motores.wav");
			for (int j = 0; j < limiteX[i]; j++) {
				Figura borrar = {
					carros[i].dato,
					carros[i].x,
					carros[i].y,
					carros[i].altura,
					carros[i].ancho,
					ConsoleColor::Black,
					nullptr
				};
				DibujarNecesario(borrar);

				carros[i].x++;

				Figura Dibujar = {
					carros[i].dato,
					carros[i].x,
					carros[i].y,
					carros[i].altura,
					carros[i].ancho,
					carros[i].color,
					nullptr
				};
				DibujarNecesario(Dibujar);
				_sleep(100);
			}
        }

    }
    void MovCarro1() {
        const wchar_t* CarroS5[] = {
            L"                  ",
            L" |\\_/|..[]_\\_.._",
            L" '-( )-----( )-=='"
        };

        int altura = 3;
        int longitud = wcslen(CarroS5[0]);

        int posX = 20;
        int posY = 35;

        while (posX < ANCHO - longitud) {
            Figura protagonista = {
                CarroS5,
                posX,
                posY,
                altura,
                longitud,
                ConsoleColor::DarkRed,
                nullptr,
            };
            DibujarNecesario(protagonista);
            _sleep(100);

            Figura borrar = {
                CarroS5,
                posX,
                posY,
                altura,
                longitud,
                ConsoleColor::Black,
                nullptr,
            };
            DibujarNecesario(borrar);

            posX++;
            _sleep(100);

            if (posX == 100) {
                const wchar_t* Carros5Arriba[] = {
                    L"  __  ",
                    L" /..\\",
                    L"( -- )",
                    L" |  | ",
                    L" |__| ",
                    L"(----)",
                    L" <__> "
                };

                int alturaArriba = 7;
                int anchoArriba = wcslen(Carros5Arriba[0]);

                int posCarroX = posX + 5;
                int posCarroY = posY - alturaArriba;

                while (posCarroY > 10) {
                    Figura subida = {
                        Carros5Arriba,
                        posCarroX,
                        posCarroY,
                        alturaArriba,
                        anchoArriba,
                        ConsoleColor::DarkRed, // MANTENER color rojo
                        nullptr
                    };

                    DibujarNecesario(subida);
                    _sleep(100);

                    // Borrar la figura anterior
                    Figura borrarArb = {
                        Carros5Arriba,
                        posCarroX,
                        posCarroY,
                        alturaArriba,
                        anchoArriba,
                        ConsoleColor::Black,
                        nullptr
                    };
                    DibujarNecesario(borrarArb);

                    posCarroY--; // Sube
					_sleep(100);
                }

                break;
            }
        }
    }

    void DibujarSimulacion() {
        funcionesMenu::LimpiarPantalla();
        funcionesMenu::InicializarPantalla();
        DibujarAutopista();
        funcionesMenu::mostrarPantalla();
        MovInicial();
    }
}