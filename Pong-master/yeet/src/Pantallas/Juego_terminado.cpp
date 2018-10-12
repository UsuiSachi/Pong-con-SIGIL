#include "Juego_terminado.h"


void fin_juego()
{
	if (Pong::logo::sin_repeticion)
	{
		Pong::logo::imagen_logo = LoadImage("resources/images/SAD_WALUIGI.png");
		Pong::logo::textura_logo = LoadTextureFromImage(Pong::logo::imagen_logo);
		Pong::logo::sin_repeticion = false;
	}
	DrawTexture(Pong::logo::textura_logo, Pong::pantalla::largo_pantalla / 2,Pong::pantalla::ancho_pantalla / 5, WHITE);
	DrawText("GAME DONG", Pong::pantalla::largo_pantalla / 2.0f, Pong::pantalla::ancho_pantalla / 2.0f, tamanio_letras * 3, Color YELLOW);
}