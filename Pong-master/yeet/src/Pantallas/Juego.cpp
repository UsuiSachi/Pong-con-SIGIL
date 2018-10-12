#include "Juego.h"
#include "juego_principal.h"
#include "creditos.h"



namespace Pong
{
	namespace Juego
	{
		//Variables a usar
		float pos_jugX[2] = { 30.0f,750.0f };
		float pos_jugY[2] = { 250.0f, 250.0f };
		float pos_pelX = Pong::pantalla::largo_pantalla / 2 + 120;
		float pos_pelY = Pong::pantalla::ancho_pantalla / 3;
		float velocidad_pelota = 6.5f;
		float tamaño_jug[] = { 15.0f,100.0f };
		float velocidad_jug = 5.0f;
		int radio_pelota = 20;
		int contador_frames = 0;
		int puntuacion[] = { 0,0 };
		int frames = 120;
		bool mov_vert_pelota = false;
		bool mov_hor_pelota = false;
		bool primer_juego = true;
		bool alguien_gano = false;
		Pantallas pantalla_actual;


	}
	namespace pantalla
	{
		int ancho_pantalla = 800;
		int largo_pantalla = 550;
	}
	namespace logo
	{
		Image imagen_logo;
		Image imagen_final;
		Texture2D textura_logo;
		bool sin_repeticion = true;
		int posX = 45;
		int posY = 5;
	}
}
using namespace Pong::Juego;
using namespace Pong::pantalla;
using namespace Pong::logo;

void empezarJuego()
{
	pantalla_actual = LOGO;
	//Inicio del Audio
	//InitAudioDevice();

	//Creacion de la ventana
	InitWindow(ancho_pantalla, largo_pantalla, "Juego de un anivia main");

	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		SetExitKey(0);
		ClearBackground(Color BLACK);
		BeginDrawing();
		if (pantalla_actual != NULL)
		{
			switch (pantalla_actual)
			{
			case LOGO:
			{
				if (contador_frames >= frames)
				{
					pantalla_actual = MENUINICIO;
					UnloadTexture(logo::textura_logo);
					contador_frames = 0;
				}
				logoJuego();
				contador_frames++;
			}break;
			case MENUINICIO:
			{
				sin_repeticion = true;
				dibujar_menu();
			}break;
			case JUEGO:
			{
				juego_principal();
			}break;
			case GAMEOVER:
			{
				fin_juego();
				contador_frames++;
				if (contador_frames > frames)
				{
					puntuacion[0] = 0;
					puntuacion[1] = 0;
					alguien_gano = false;
					pantalla_actual = MENUINICIO;
					contador_frames = 0;
				}
			}break;
			case CREDITOS:
			{
				pantalla_creditos();
			}break;
			case ASSHOLE:
			{

			}break;
			default:
			{

			}break;
			}
		}
		EndDrawing();
	}
	CloseWindow();

}