#ifndef JUEGO_H
#define JUEGO_H
#include <iostream>
#include <stdio.h>
#include <time.h>
#include "raylib.h"
#include "Juego_terminado.h"
const int PAREDABAJO = 550;
const int PAREDARRIBA = 0;
const int PAREDIZQ = 0;
const int PAREDDER = 800;
const int puntaje_limite = 3;
const int posY_letras[] = { 15, 40 };
const int tamanio_letras = 20;

namespace Pong
{
	namespace Juego
	{
		//Variables a usar
		extern float pos_jugX[2];
		extern float pos_jugY[2];
		extern float pos_pelX;
		extern float pos_pelY;
		extern float velocidad_pelota;
		extern bool mov_vert_pelota;
		extern bool mov_hor_pelota;
		extern int radio_pelota;
		extern int limite_pantalla;
		extern float tamaño_jug[];
		extern float velocidad_jug;
		extern int puntuacion[];
		extern int contador_frames;
		extern int frames;
		extern bool primer_juego;
		extern bool auxiliar;
		extern enum Pantallas { LOGO = 1, MENUINICIO, JUEGO, GAMEOVER, SALIDA, CREDITOS, ASSHOLE };
		extern bool alguien_gano;
		extern Pantallas pantalla_actual;

	};
	namespace pantalla
	{
		extern int ancho_pantalla;
		extern int largo_pantalla;
	}
}



void empezarJuego();

#endif