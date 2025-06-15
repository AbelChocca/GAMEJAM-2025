#include "MiBibliotecaGameJam.h"

namespace Simulacion {
    void DibujarAutopista() {
        const wchar_t* autopista[] = {
            L"          /─────────────────────────────────────────────────────────────────────────────────────────────────────────\\            ",
            L"         /                                                                                                           \\           ",
            L"        /                                                                                                             \\          ",
            L"       /                                                                                                               \\         ",
            L"      /                                                                                                                 \\        ",
            L"     /                              ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬                          \\       ",
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
            L"        \\                         ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬                         /          ",
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
            49,
            longitud,
            ConsoleColor::DarkGray,
            nullptr,
        };
        funcionesMenu::DibujarFigura(autopistaRef);
    }

    void DibujarSimulacion() {
        funcionesMenu::LimpiarPantalla();
        funcionesMenu::InicializarPantalla();
        DibujarAutopista();
        funcionesMenu::mostrarPantalla();
    }
}