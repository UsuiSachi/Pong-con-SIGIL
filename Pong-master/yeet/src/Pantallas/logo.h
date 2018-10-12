#ifndef LOGO_H
#include <iostream>
#include <stdio.h>
#include <time.h>
#include "raylib.h"
#include "Juego.h"
#define LOGO_H
namespace Pong 
{
	namespace pantalla {};
	namespace logo 
	{
		extern Image imagen_logo;
		extern Image imagen_final;
		extern bool sin_repeticion;
		extern Texture2D textura_logo;
		extern int posX;
		extern int posY;
	};
};

void logoJuego();
#endif