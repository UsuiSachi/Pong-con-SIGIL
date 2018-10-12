#include "menu.h"


void dibujar_menu()
{
	SetExitKey(KEY_ESCAPE);
	DrawText("Presione ENTER para Jugar", Pong::pantalla::largo_pantalla / 6, Pong::pantalla::ancho_pantalla / 8, tamanio_letras*2, Color RED);
	DrawText("Presione ESC para Salir", Pong::pantalla::largo_pantalla / 6, Pong::pantalla::ancho_pantalla / 6, tamanio_letras*2, Color RED);
	DrawText("Presione C para ver los creditos", Pong::pantalla::largo_pantalla / 6, Pong::pantalla::ancho_pantalla / 4, tamanio_letras * 2, Color RED);
	DrawText("Presione A para el modo especial", Pong::pantalla::largo_pantalla / 6, Pong::pantalla::ancho_pantalla / 2, tamanio_letras * 2, Color RED);
	if (IsKeyPressed(KEY_ENTER))
		Juego::pantalla_actual = Juego::JUEGO;
	if (IsKeyPressed(KEY_ESCAPE))
		Juego::pantalla_actual = Juego::GAMEOVER;
	if (IsKeyPressed(KEY_C))
		Juego::pantalla_actual = Juego::CREDITOS;
	if (IsKeyPressed(KEY_A))
		Juego::pantalla_actual = Juego::ASSHOLE;
}