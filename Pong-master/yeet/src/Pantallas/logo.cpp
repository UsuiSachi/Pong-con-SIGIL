#include "logo.h"


void logoJuego()
{
	if (Pong::logo::sin_repeticion)
	{
		Pong::logo::imagen_logo = LoadImage("resources/images/SAD_DONG.png");
		Pong::logo::textura_logo = LoadTextureFromImage(Pong::logo::imagen_logo);
		Pong::logo::sin_repeticion = false;
	}
	DrawTexture(Pong::logo::textura_logo, Pong::logo::posX, Pong::logo::posY, WHITE);
	DrawText("EXPAND PONG", Pong::pantalla::largo_pantalla / 2.5f, Pong::pantalla::ancho_pantalla / 3.5f, tamanio_letras*3, Color BLUE);

}