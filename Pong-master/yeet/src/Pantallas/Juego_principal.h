#ifndef JUEGO_PRINCIPAL_H
#define JUEGO_PRINCIPAL_H
#include "Juego.h"
#include "logo.h"
#include "menu.h"

using namespace Pong::Juego;
struct Jugador
{
	Vector2 Posicion;
	Vector2 Tama�o;
};

struct Pelota
{
	Vector2 Posicion;
	Vector2 Velocidad;
	int radio;
	bool seMueve;
};

Jugador crear_jugador(int x, int y, float tama�oJug[]);

using namespace Pong::pantalla;


void juego_principal();

#endif