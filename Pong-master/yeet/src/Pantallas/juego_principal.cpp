
#include "Juego_principal.h"
Jugador jugador[2];
Pelota pelota;


void juego_principal()
{
	//Archivos de audio
	/*
	Sound golpeoPared = LoadSound("resources/sound effects/Hit_PARED.wav");
	Sound golpeoJugador = LoadSound("resources/sound effects/Hit_Jugador.wav");
	Sound puntajeOponente = LoadSound("resources/sound effects/Puntuacion_Oponente.wav");
	*/
	if(alguien_gano == false)
	{
		for (int i = 0; i < 2; i++)
		{
			if (primer_juego)
			{
				jugador[i] = crear_jugador(pos_jugX[i], pos_jugY[i], tamaño_jug);

				//Definicion de la Pelota
				pelota.Velocidad = { NULL,NULL };
				pelota.radio = radio_pelota;
				pelota.seMueve = false;
				pelota.Posicion = { pos_pelX, pos_pelY };
				if (i == 1)
					primer_juego = false;
			}
		}

		//Comienzo del juego
		if (IsKeyPressed(KEY_E)) pelota.seMueve = true;
		//Reset del juego
		if (IsKeyPressed(KEY_R))
		{
			pelota.Posicion.x = pos_pelX;
			pelota.Posicion.y = pos_pelY;
			pelota.seMueve = false;

		}


		//Movimiento j1
		if (IsKeyDown(KEY_W)) jugador[0].Posicion.y -= velocidad_jug;
		if (IsKeyDown(KEY_S)) jugador[0].Posicion.y += velocidad_jug;

		if (jugador[0].Posicion.y > PAREDABAJO - 100) {
			jugador[0].Posicion.y = PAREDABAJO - 100;
		}
		if (jugador[0].Posicion.y < PAREDARRIBA)
		{
			jugador[0].Posicion.y = PAREDARRIBA;
		}
		//Movimiento j2
		if (IsKeyDown(KEY_UP)) jugador[1].Posicion.y -= velocidad_jug;
		if (IsKeyDown(KEY_DOWN)) jugador[1].Posicion.y += velocidad_jug;

		if (jugador[1].Posicion.y > PAREDABAJO - 100)
		{
			jugador[1].Posicion.y = PAREDABAJO - 100;
		}

		if (jugador[1].Posicion.y < PAREDARRIBA)
		{
			jugador[1].Posicion.y = PAREDARRIBA;
		}

		//Movimiento Pelota

		if (pelota.seMueve)
		{
			//Puntuacion de los jugadores + Reset de la Pelota
			if (pelota.Posicion.x <PAREDIZQ || pelota.Posicion.x > PAREDDER)
			{
				if (pelota.Posicion.x < PAREDIZQ)
					puntuacion[0]++;
				if (pelota.Posicion.x > PAREDDER)
					puntuacion[1]++;
				//PlaySound(puntajeOponente);
				pelota.Posicion.x = pos_pelX;
				pelota.Posicion.y = pos_pelY;
				pelota.seMueve = false;

			}

			//Movimiento de la pelota en las paredes superiores
			if (pelota.Posicion.y <= PAREDARRIBA)
			{
				//PlaySound(golpeoPared);
				mov_vert_pelota = true;
			}
			if (pelota.Posicion.y >= PAREDABAJO)
			{
				//PlaySound(golpeoPared);
				mov_vert_pelota = false;
			}

			//Booleanos de las direcciones de la pelota

			if (mov_vert_pelota)
			{
				pelota.Posicion.y += velocidad_pelota;
			}
			else
			{
				pelota.Posicion.y -= velocidad_pelota;
			}

			if (mov_hor_pelota)
			{
				pelota.Posicion.x += velocidad_pelota;
			}
			else
			{
				pelota.Posicion.x -= velocidad_pelota;
			}
		}

		//Colisiones de la pelota con los jugadores
		//Jugador 1
		if (CheckCollisionCircleRec(pelota.Posicion, pelota.radio,
			Rectangle{ jugador[0].Posicion.x ,jugador[0].Posicion.y
			,jugador[0].Tamaño.x, jugador[0].Tamaño.y }))
		{
			//PlaySound(golpeoJugador);
			velocidad_pelota += 0.5f;
			mov_hor_pelota = true;
		}
		//jugador 2
		if (CheckCollisionCircleRec(pelota.Posicion, pelota.radio,
			Rectangle{ jugador[1].Posicion.x,jugador[1].Posicion.y
			,jugador[1].Tamaño.x,  jugador[1].Tamaño.y }))
		{
			//PlaySound(golpeoJugador);
			mov_hor_pelota = false;
			velocidad_pelota += 0.5f;
		}


		//Dibujos de Texto, jugadores y pelota

		//Dibujo Jugador 1
		DrawRectangleV(jugador[0].Posicion, jugador[0].Tamaño, Color RED);

		//Dibujo Jugador 2
		DrawRectangleV(jugador[1].Posicion, jugador[1].Tamaño, Color DARKBLUE);

		//Dibujo Pelota
		DrawCircleV(pelota.Posicion, pelota.radio, Color SKYBLUE);

		//Dibujo Texto
		DrawText("SHACO", largo_pantalla / 2 + 30, posY_letras[0], tamanio_letras, Color RED);
		DrawText("VS", largo_pantalla / 2 + 110, posY_letras[0], tamanio_letras, Color GREEN);
		DrawText("LEE SIN", largo_pantalla / 2 + 150, posY_letras[0], tamanio_letras, Color DARKBLUE);
		DrawText(FormatText("%4i", puntuacion[1]), largo_pantalla / 2 + 30, posY_letras[1], tamanio_letras, Color WHITE), puntuacion[0];
		DrawText(FormatText("%4i", puntuacion[0]), largo_pantalla / 2 + 160, posY_letras[1], tamanio_letras, Color WHITE), puntuacion[1];

		if (puntuacion[0] == puntaje_limite || puntuacion[1] == puntaje_limite)
		{
			alguien_gano = true;
			pelota.Velocidad = {0, 0};
			pantalla_actual = GAMEOVER;
		}
	};
	/*
	UnloadSound(golpeoPared);
	UnloadSound(golpeoJugador);
	UnloadSound(puntajeOponente);
	*/
}

Jugador crear_jugador(int x, int y, float tamañoJug[])
{
	Jugador p;
	p.Posicion.x = x;
	p.Posicion.y = y;
	p.Tamaño.x = tamañoJug[0];
	p.Tamaño.y = tamañoJug[1];
	return p;
}