#pragma once
#include "Jugador.h"
#include "Objetos.h"
#include "Androide.h"
#include "GestorDialogos.h"
#include "Npc.h"
#include "Entradas.h"
#include "Enemigos.h"
#include "Dragon.h"
#include "Bala.h"
#include "Alien.h"
#include "Portal.h"
#include "Aliado.h"
#include"GestorArchivos.h"
ref class Controlador
{

private:
	Jugador* jugador;  Bitmap^ spriteJugador; Bitmap^ sinTraje; Bitmap^ conTraje; Bitmap^ conJetPack; int numSkin;
	bool conversacionIniciada;

	//MundoHumano
	Bitmap^ MapaActual;
	Bitmap^ mapa1; Bitmap^ mapa2; Bitmap^ mapaEngaño; Bitmap^ mapaTrabajo; int numMapa;
	Enemigos* toros; Bitmap^ spriteToro;
	Npc* npc1; Bitmap^ spriteNpc;
	Npc* npcCambioSkin;
	Npc* npcLier; Bitmap^ spriteLier;
	NpcAnimado* npcVillager; Bitmap^ spriteVillager;
	Npc* npcAliado; Bitmap^ spriteNpcAliado;

	//objetos
	Objeto* cohete; Bitmap^ spriteCohete; Objeto* casa; Bitmap^ spriteCasa;
	Objetos* perlas; Bitmap^ spritePerlas;
	Objetos* troncos; Bitmap^ spriteTronco; Objeto* jardin; Bitmap^ spriteJardin;
	

	//entradas
	//MUNDO1
	Entradas* entrada1; Entradas* entrada2; Entradas* entrada3;
	//MUNDO2
	Portal* entradaDragon;
	/*Entradas* entradaDragon;*/
	Portal* entradaSemilla;

	//MUNDO2
	Androides* android; Bitmap^ spriteAndroid;
	Dragon* dragon; Bitmap^ spriteDragon; Bitmap^ spriteFuego;
	Bitmap^ mapaIA;
	Bitmap^ mapaIA2;
	Bitmap^ mapaIA3;
	Objeto* semilla; Bitmap^ spriteSemilla;
	int TIEMPODRAGON;
	bool dragonActivo;
	Bitmap^ spritePortales;
	const int tiempoAparicion = 10;
	int time;

	GestorDialogos* gestorD;
	GestorArchivos* Archivos;

	Aliado* aliado; Bitmap^ spriteAliado;
	bool seguirAjugador;

	Npc* npcAliadoMundo2; Bitmap^ spriteNpcAliadoMundo2;



	//Animacion
	Bitmap^ spriteCoheteAnimado;
	int animacion;
	int faseCinematica;
	int tiempoEsperaCinematica;

	int estadoMisionVillager; // 0=Nada, 1=Buscando, 2=Terminado, 3=Preguntando, 4=Fin
	bool LiberarToros;
	int cooldownEnemigo;

	bool dialogoMundo3;

	bool juegoFinalizado;
	bool dialogoAliadoRealizado;

	//MUNDO3
	Bitmap^ MapaColaborativo1;
	Bitmap^ MapaColaborativo2;
	Bitmap^ MapaColaborativo3;
	Bitmap^ MapaFinal;
	Entradas* entradaColaborativa1;
	Entradas* entradaColaborativa2;
	Balas* balas;
	bool ejercutarDiparo = false;
	Aliens* aliens; Bitmap^ spriteAliens;
	int tiempoAlien;
	const int tiempoAparicionAliens = 10;
	bool aliensActivos;
	Npc* npcJetPack;
	Bitmap^ spriteNpcJetPack;
	Bitmap^ spriteBala;
	int estadoAliado;

	bool colisionConNpcJetPack;

	int tiempoDuracionAlien;

	Npc* npcRobot; Bitmap^ spriteNpcRobot;
	Npc* npcRobot2;
	Npc* npcRobot3;
	Npc* npcRobot4;

	Npc* npcT; Bitmap^ spriteNpcT;
	Npc* npcT1;
	Npc* npcT2;
	Npc* npcT3;
	Portal* portalRobot;
	Portal* portalRobot2;
	const int TiempoParaTirarPiedra = 10;
	int tirarPiedra;
	Bitmap^ spritePiedra;
	const int tiempoRegenarCorazon = 100;
	int corazon;
	Bitmap^ spriteVida;
	Portal* portalFinal;

	Objeto* fin; Bitmap^ spriteFinal;

	Bitmap^ mapaInstruc;
	Bitmap^ mapaCredi;



	bool dialogoFinRealizado;
	bool eventoJetpackIniciado;
	bool DialogoAliadoMundo2;
	bool respondioPreguntaFinal;

public:
	Controlador() {
		numMapa = 1;
		numSkin = 1;
		jugador = new Jugador(); /*spriteJugador = gcnew Bitmap("Imagenes/Personaje1.png");*/
		conTraje= gcnew Bitmap("Imagenes/Personaje2.png"); 
		sinTraje = gcnew Bitmap("Imagenes/Personaje1.png");
		conJetPack = gcnew Bitmap("Imagenes/Personaje3.png");
		actualizarSkin();
		perlas = new Objetos(); spritePerlas = gcnew Bitmap("Imagenes/Perla.png");
		cohete = new Objeto(800, 100); spriteCohete = gcnew Bitmap("Imagenes/Cohete.png");
		npc1 = new Npc(200,400, 50, 70); spriteNpc = gcnew Bitmap("Imagenes/Npc1.png");
		npcCambioSkin = new Npc(700,300);
		toros = new Enemigos(); spriteToro = gcnew Bitmap("Imagenes/Bestia.png");
		//MUNDO1
		entrada1 = new Entradas(800, 0, 80, 20);
		entrada2 = new Entradas(1000, 150, 20, 80);
		entrada3 = new Entradas(590,450,80,20);
		mapa1 = gcnew Bitmap("Imagenes/mapaInicio.jpg");
		mapa2 = gcnew Bitmap("Imagenes/mapa2.png");
		mapaEngaño = gcnew Bitmap("Imagenes/mapaEngaño2.png");
		mapaTrabajo = gcnew Bitmap("Imagenes/mapaTrabajo.jpg");
		troncos = new Objetos(); spriteTronco = gcnew Bitmap("Imagenes/tronco.png");
		casa = new Objeto(300, 100); spriteCasa = gcnew Bitmap("Imagenes/Casa.png");
		jardin = new Objeto(420, 220); spriteJardin = gcnew Bitmap("Imagenes/jardin.png");
		npcLier = new Npc(720, 30, 80, 80); spriteLier = gcnew Bitmap("Imagenes/NpcLier.png");
		npcVillager = new NpcAnimado(150, 100, 60, 80, 5); spriteVillager = gcnew Bitmap("Imagenes/Villager.png");
		npcAliado = new Npc(500, 250, 50, 70); spriteNpcAliado = gcnew Bitmap("Imagenes/npc1.png");
		estadoMisionVillager = 0;


		//animacion
		spriteCoheteAnimado = gcnew Bitmap("Imagenes/naveEspacialani2.png");
		animacion = 0;
		faseCinematica = 0;
		tiempoEsperaCinematica = 0;


		//MUNDO 2
		android = new Androides(); spriteAndroid = gcnew Bitmap("Imagenes/droide.png");
		dragon = new Dragon(); spriteDragon = gcnew Bitmap("Imagenes/dragon.png"); spriteFuego = gcnew Bitmap("Imagenes/Fueguito.png");
		mapaIA = gcnew Bitmap("Imagenes/MundoIA.jpg");
		mapaIA2 = gcnew Bitmap("Imagenes/MUNDOIA2.JPG");
		mapaIA3 = gcnew Bitmap("Imagenes/MUNDOIA3.jpg");
		entradaDragon = new Portal(900, 100,0); spritePortales = gcnew Bitmap("Imagenes/portales.png");
		entradaSemilla = new Portal(900, 100,1);	
		semilla = new Objeto(900, 300); spriteSemilla = gcnew Bitmap("Imagenes/semilla.png");

		aliado = new Aliado(300, 250); spriteAliado = gcnew Bitmap("Imagenes/botsito.png");
		npcAliadoMundo2 = new Npc(600, 200, 100, 120); spriteNpcAliadoMundo2 = gcnew Bitmap("Imagenes/npcRobot.png");

		//dialog 
		gestorD = new GestorDialogos(); 
		LiberarToros = false;
		cooldownEnemigo = 0;
		seguirAjugador = false;
		Archivos = new GestorArchivos();

		dialogoAliadoRealizado = false;
		


		//MUNDO3 
		npcRobot = new Npc(310, 25); spriteNpcRobot = gcnew Bitmap("Imagenes/NpcIA.png");
		npcRobot2 = new Npc(410, 25);
		npcRobot3 = new Npc(510, 25);
		npcRobot4 = new Npc(610, 25);
		portalRobot = nullptr;
		portalRobot2 = nullptr;
		npcT  = new Npc(310,300); spriteNpcT = gcnew Bitmap("Imagenes/NpcTiraPiedra.png");
		npcT1 = new Npc(410,300);
		npcT2 = new Npc(510,300);
		npcT3 = new Npc(610,300);

		spritePiedra = gcnew Bitmap("Imagenes/piedra.png");
		tirarPiedra = 0;


		mapaInstruc = gcnew Bitmap("img/instruc.png");
		mapaCredi = gcnew Bitmap("img/CreditosAlgoritmos.png");


		MapaColaborativo1 = gcnew Bitmap("Imagenes/MUNDOCO1.png");
		balas = new Balas(); spriteBala = gcnew Bitmap("Imagenes/balita.png");
		TIEMPODRAGON = 0;
		dragonActivo = true;
		aliens = new Aliens(); spriteAliens = gcnew Bitmap("Imagenes/ovni.png");
		tiempoAlien = 0;
		corazon = 0;
		MapaColaborativo2 = gcnew Bitmap("Imagenes/MUNDOCO2.jpg");
		MapaColaborativo3 = gcnew Bitmap("Imagenes/MUNDOCO3.PNG");
		MapaFinal = gcnew Bitmap("Imagenes/mapaFinal.png");
		entradaColaborativa1 = new Entradas(1000,200,30,100);
		entradaColaborativa2 = new Entradas(1000, 185, 30, 100);
		npcJetPack = new Npc(10, 300); spriteNpcJetPack = gcnew Bitmap("Imagenes/droideAliado.png");
		colisionConNpcJetPack = false;
		tiempoDuracionAlien = 300;
		aliensActivos = false;
		spriteVida = gcnew Bitmap("Imagenes/corazon.png");
		portalFinal = nullptr;
		fin = new Objeto(850, 100); spriteFinal = gcnew Bitmap("Imagenes/FIN.png");

		estadoAliado = 0;
		dialogoMundo3 = false;
		juegoFinalizado = false;
		dialogoFinRealizado = false;
		eventoJetpackIniciado = false;
		DialogoAliadoMundo2 = false;
		respondioPreguntaFinal = false;
	}
	void MovimientoJugador(bool accion, Keys tecla) {

		int v = 20;

		if (accion == true) {

			if (colisionConNpcJetPack == false) {

				if (tecla == Keys::W) {

					jugador->setDy(-v);

					jugador->setAccion(CaminarArriba);



				}

				else if (tecla == Keys::S) {

					jugador->setDy(v);

					jugador->setAccion(CaminarAbajo);

				}

				else if (tecla == Keys::D) {

					jugador->setDx(v);

					jugador->setAccion(CaminarDerecha);

				}

				else if (tecla == Keys::A) {

					jugador->setDx(-v);

					jugador->setAccion(CaminarIzquierda);

				}

				else if (tecla == Keys::E) {

					if (numMapa == 4)

					{

						if (troncos->eliminarObjeto(jugador->getArea()))

						{

							jugador->agregarPuntaje(20);

						}

					}

					if (numMapa == 2)

					{

						if (perlas->eliminarObjeto(jugador->getArea()))

						{

							jugador->agregarPuntaje(20);

						}

					}




				}

				else if (tecla == Keys::Space && numMapa == 5) {


					if (android->eliminarDroide(jugador->getArea()))

					{

					
						jugador->setAccion(Atacar);

						jugador->agregarPuntaje(50);



					}



				}

				else if (tecla == Keys::R && numMapa == 8) {

					if (portalRobot == nullptr) {

						portalRobot = new Portal(200, 20, 0);

					}

				}

			}

			else {

				if (tecla == Keys::W) {



					if (jugador->getAccion() == CaminarIzquierda) {

						jugador->setAccion(CaminarIzquierda);

					}

					else

					{

						jugador->setAccion(CaminarAbajo);

					}

					jugador->setDy(-v);


				}

				else if (tecla == Keys::S) {

					jugador->setDy(v);

					if (jugador->getAccion() == CaminarIzquierda) {

						jugador->setAccion(CaminarIzquierda);

					}

					else

					{

						jugador->setAccion(CaminarAbajo);

					}


				}

				else if (tecla == Keys::D) {

					jugador->setDx(v);

					jugador->setAccion(CaminarIzquierda);

				}

				else if (tecla == Keys::A) {

					jugador->setDx(-v);

					jugador->setAccion(CaminarAbajo);

				}

				if (tecla == Keys::F) {

					if (ejercutarDiparo == true) {

						int d = 20;

						if (jugador->getAccion() == CaminarIzquierda) {

							balas->Agregar(new Bala(jugador->getX() + jugador->getAncho() / 4 + 50, jugador->getY() + jugador->getAlto() / 2 - 10, d, 0));

						}

						else if (jugador->getAccion() == CaminarAbajo) {

							balas->Agregar(new Bala(jugador->getX() + jugador->getAncho() / 4 - 35, jugador->getY() + jugador->getAlto() / 2 - 10, -d, 0));

						}


					}

				}

			}

		}



		else {

			if (tecla == Keys::W) jugador->setDy(0);

			else if (tecla == Keys::S) jugador->setDy(0);

			else if (tecla == Keys::D) jugador->setDx(0);

			else if (tecla == Keys::A) jugador->setDx(0);

		}



	}








	void ActualizarMapa(BufferedGraphics^ buffer) {

		switch (numMapa)

		{

		case 1:

			MapaActual = mapa1;

			break;

		case 2:

			MapaActual = mapa2;

			break;

		case 3:

			MapaActual = mapaEngaño;

			break;

		case 4:

			MapaActual = mapaTrabajo;

			break;

		case 5:

			MapaActual = mapaIA;

			break;

		case 6:

			MapaActual = mapaIA2;

			break;

		case 7:

			MapaActual = mapaIA3;

			break;

		case 8:

			MapaActual = MapaColaborativo1;

			break;

		case 9:

			MapaActual = MapaColaborativo2;

			break;

		case 10:

			MapaActual = MapaColaborativo3;

			break;

		case 11:

			MapaActual = MapaFinal;

			break;

		case 12:

			MapaActual = mapaInstruc;

			break;
		case 13:
			MapaActual = mapaCredi;

			break;

		}


	}

	void actualizarSkin() {

		switch (numSkin)

		{

		case 1:

			spriteJugador = sinTraje;

			break;

		case 2:

			spriteJugador = conTraje;

			break;

		case 3:

			spriteJugador = conJetPack;

		}

	}

	void DibujarMapa(BufferedGraphics^ buffer) {

		int ancho = buffer->Graphics->VisibleClipBounds.Width;

		int alto = buffer->Graphics->VisibleClipBounds.Height;



		buffer->Graphics->DrawImage(MapaActual, 0, 0, ancho, alto);

	}




	//=========================DIALOGOS============================



	String^ getTextoDialogo() {

		return gestorD->procesarTexto();

	}



	void apagarDialogo() {

		gestorD->limpiar();

	}



	void IniciarHistoriaIntro() {

		if (!gestorD->hayDialogoPendiente()) {



			gestorD->cargarEscena(1);



			gestorD->siguienteFrase();

		}

	}



	void AvanzarHistoria() {

		if (gestorD->hayDialogoPendiente()) {



			if (gestorD->fraseTerminada()) {

				gestorD->siguienteFrase();

			}

			else {

				gestorD->mostrarFraseCompleta();

			}

		}

	}



	bool hayHistoriaActiva() {

		return gestorD->hayDialogoPendiente();

	}



	void ActualizarVistaDialogo(System::Windows::Forms::Label^ lbl, System::Windows::Forms::Panel^ panel) {

		if (hayHistoriaActiva()) {

			lbl->Text = getTextoDialogo();

			panel->Visible = true;

		}

		else {

			lbl->Text = "";

			panel->Visible = false;

			apagarDialogo();

		}

	}



	void ProcesarEntrada(System::Windows::Forms::Keys tecla, bool presionar) {

		if (!presionar) {

			MovimientoJugador(false, tecla);

			return;

		}




		if (tecla == System::Windows::Forms::Keys::Enter && hayHistoriaActiva()) {



			if (numMapa == 3 && gestorD->esUltimoMensaje()) {

				LiberarToros = true;

			}



			if (estadoMisionVillager == 3 && gestorD->esUltimoMensaje()) {

				return;

			}



			if (numMapa == 13 && faseCinematica == 1 && gestorD->esUltimoMensaje()) {
				return;
			}
			if (numMapa == 7 && estadoAliado == 1 && gestorD->esUltimoMensaje()) {
				return;
			}
			if (numMapa == 11 && gestorD->esUltimoMensaje() && !respondioPreguntaFinal) {
				return;
			}


			AvanzarHistoria();

			return;

		}





		if (estadoMisionVillager == 3 && hayHistoriaActiva()) {

			if (tecla == Keys::A) {

				gestorD->cargarEscena(6);

				gestorD->siguienteFrase();

				estadoMisionVillager = 4;

				jugador->agregarPuntaje(-30);

			}

			else if (tecla == Keys::B) {

				gestorD->cargarEscena(5);

				gestorD->siguienteFrase();

				jugador->setVidas(1);

				estadoMisionVillager = 4;

				jugador->agregarPuntaje(100);

			}

			return;

		}

		if (numMapa == 11 && hayHistoriaActiva() && !respondioPreguntaFinal) {

			if (gestorD->esUltimoMensaje()) {

				if (tecla == Keys::A) {
					gestorD->cargarEscena(20);
					gestorD->siguienteFrase();
					jugador->agregarPuntaje(50);
					respondioPreguntaFinal = true;
				}
				else if (tecla == Keys::B) {
					gestorD->cargarEscena(21);
					gestorD->siguienteFrase();
					respondioPreguntaFinal = true;
				}
				return;
			}
		}

		if (tecla == System::Windows::Forms::Keys::Enter) {



			if (numMapa == 1 && colisionJugadorNpc1()) {

				gestorD->cargarEscena(1);

				gestorD->siguienteFrase();

			}

			else if (numMapa == 1 && colisionJugadorNpcLier()) {

				gestorD->cargarEscena(2);

				gestorD->siguienteFrase();

			}

			else if (numMapa == 4 && colisionJugadorVillager()) {

				if (estadoMisionVillager == 0) {

					gestorD->cargarEscena(3);

					gestorD->siguienteFrase();

					estadoMisionVillager = 1;

				}

				else if (estadoMisionVillager == 2) {

					gestorD->cargarEscena(4);

					gestorD->siguienteFrase();

					estadoMisionVillager = 3;

				}

			}

			else if (numMapa == 2 && colisionJugadorCambioSkin())

			{

				if (perlas->cantidadObjetos() == 0) {

					gestorD->cargarEscena(7);

					gestorD->siguienteFrase();



					numSkin = 2;

					actualizarSkin();

				}

			}

		}



		if (numMapa == 13 && faseCinematica == 1 && hayHistoriaActiva()) {
			if (tecla == Keys::A) {
				gestorD->cargarEscena(10);
				gestorD->siguienteFrase();
				faseCinematica = 2;
				jugador->agregarPuntaje(50);
				jugador->setVidas(1);

			}
			else if (tecla == Keys::B) {
			
				gestorD->cargarEscena(11);
				gestorD->siguienteFrase();
				faseCinematica = 2;
			}
			return;
		}

		if (numMapa == 7 && estadoAliado == 1 && hayHistoriaActiva()) {
			if (gestorD->esUltimoMensaje()) {
				if (tecla == Keys::A) {
					gestorD->cargarEscena(13);
					gestorD->siguienteFrase();
					estadoAliado = 2;
					jugador->agregarPuntaje(50);
				}
				else if (tecla == Keys::B) {
					gestorD->cargarEscena(14);
					gestorD->siguienteFrase();
					estadoAliado = 2;
				}
				return;
			}
		}



		if (!hayHistoriaActiva()) {

			MovimientoJugador(true, tecla);

		}

	}







	bool colisionJugadorNpcLier() {

		return jugador->getNextArea().IntersectsWith(npcLier->getArea());

	}

	bool colisionJugadorVillager() {

		return jugador->getNextArea().IntersectsWith(npcVillager->getArea());

	}

	bool colisionJugadorCambioSkin() {

		return jugador->getNextArea().IntersectsWith(npcCambioSkin->getArea());

	}



	//===========================================================================



	bool colisionJugadorNpc1() {



		return jugador->getNextArea().IntersectsWith(npc1->getArea());

	}





	bool EjecutarMundo1(BufferedGraphics^ buffer) {


		ActualizarMapa(buffer);

		DibujarMapa(buffer);

		ejercutarDiparo = false;

		bool puedeMoverse = true;





		jugador->Mostrar(buffer, spriteJugador);



		//TODO DEL MAPA 1



		if (numMapa == 1) {



			npc1->Mostrar(buffer, spriteNpc);

			npcLier->Mostrar(buffer, spriteLier);

			if (jugador->nextHitBoxJugador().IntersectsWith(npc1->Hitbox()) || jugador->nextHitBoxJugador().IntersectsWith(npcLier->Hitbox())) puedeMoverse = false;

			entrada1->Mostrar(buffer);



			if (jugador->getX() >= buffer->Graphics->VisibleClipBounds.Width && numMapa == 1) {

				numMapa = 2;

				jugador->posicionar(0, jugador->getY());

			}



			if (jugador->getArea().IntersectsWith(entrada1->getArea())) {



				numMapa = 3;

				LiberarToros = false;



				jugador->posicionar(600, 300);



				gestorD->cargarEscena(8);

				gestorD->siguienteFrase();

			}



		}


		if (numMapa == 2) {

			perlas->Mostrar(buffer, spritePerlas);

			npcCambioSkin->Mostrar(buffer, spriteNpc);

			if (perlas->colisionMovimiento(jugador->nextHitBoxJugador())) {

				//puedeMoverse = false;

			}

			if (perlas->cantidadObjetos() == 0) {

				cohete->Mostrar(buffer, spriteCohete);

				if (cohete->HitBoxObjeto().IntersectsWith(jugador->hitBoxJugador())) {

					SetNumMapaAc(13);

					animacion = 0;
					faseCinematica = 0;
					tiempoEsperaCinematica = 0;

					jugador->setDx(0);
					jugador->setDy(0);
					jugador->setAccion(CaminarAbajo);
					jugador->agregarPuntaje(100);
				}



			}

		}




		if (numMapa == 3) {

			entrada2->Mostrar(buffer);

			if (LiberarToros == true) {

				toros->Mostrar(buffer, spriteToro);

				toros->Mover(buffer);



				if (toros->colisionRecoger(jugador->hitBoxJugador()) && clock() - cooldownEnemigo >= 2000) {

					jugador->setVidas(-1);

					cooldownEnemigo = clock();

					jugador->agregarPuntaje(-20);

				}

			}



			if (jugador->getArea().IntersectsWith(entrada2->getArea())) {

				numMapa = 4;

				jugador->posicionar(0, jugador->getY());

			}



		}



		if (numMapa == 4) {

			npcVillager->Mostrar(buffer, spriteVillager);

			if (jugador->nextHitBoxJugador().IntersectsWith(npcVillager->Hitbox())) puedeMoverse = false;

			if (estadoMisionVillager >= 2) {

				casa->Mostrar(buffer, spriteCasa);
				
				if (jugador->nextHitBoxJugador().IntersectsWith(casa->HitBoxObjeto())) puedeMoverse = false;


				npcVillager->setAnimando(true);

			}

			else

			{

				npcVillager->setAnimando(false);

				npcVillager->setFrame(1);

			}




			entrada3->Mostrar(buffer);



			// LOGICA DE LA MISION



			if (estadoMisionVillager == 1) {

				troncos->Mostrar(buffer, spriteTronco);





				if (troncos->cantidadObjetos() == 0) {

					estadoMisionVillager = 2;

				}

			}



			if (estadoMisionVillager >= 2) {

				casa->Mostrar(buffer, spriteCasa);

				npcVillager->setAnimando(true);

			}

			else

			{

				npcVillager->setAnimando(false);

			}



			if (jugador->getArea().IntersectsWith(entrada3->getArea())) {

				numMapa = 2;

				jugador->posicionar(100, 50);

			}

		}



		if (puedeMoverse) {

			jugador->Mover(buffer);


		}



		return true;

	}







	int getNumMapa() {

		return numMapa;

	}







	bool EjecutarMundo2(BufferedGraphics^ buffer) {

		bool puedeMoverse = true;

		ActualizarMapa(buffer);

		DibujarMapa(buffer);



		jugador->Mostrar(buffer, spriteJugador);

		if (numMapa == 5) {

			android->Mostrar(buffer, spriteAndroid);

			android->Mover(buffer);

			if (android->colisionConAndroide(jugador->hitBoxJugador()) && clock() - cooldownEnemigo >= 2000) {

				jugador->setVidas(-1);

				cooldownEnemigo = clock();

				jugador->agregarPuntaje(-20);

			}


			if (android->cantidadDroides() == 0)
			{
				npcAliadoMundo2->Mostrar(buffer, spriteNpcAliadoMundo2);

				if (jugador->getArea().IntersectsWith(npcAliadoMundo2->getArea()))
				{
					if (!gestorD->hayDialogoPendiente()&& !DialogoAliadoMundo2)
					{
						gestorD->cargarEscena(19);
						gestorD->siguienteFrase();
						DialogoAliadoMundo2 = true;
					}
					

				}

			}

			if (DialogoAliadoMundo2)
			{
				entradaDragon->Mostrar(buffer, spritePortales);

			}

			if (jugador->hitBoxJugador().IntersectsWith(entradaDragon->getArea())) {

				numMapa = 6;

				jugador->posicionar(100, 100);

			}

		}

		else if (numMapa == 6) {

			TIEMPODRAGON++;

			time++;

			if (time >= tiempoAparicion) {

				dragon->dispararBolas();

				time = 0;





			}

			if (dragonActivo == true) {

				dragon->Mover(buffer);

				dragon->Mostrar(buffer, spriteDragon);

				dragon->ejecutarDisparo(buffer, spriteFuego);

				if (dragon->colisionConFuego(jugador->hitBoxJugador()) == true && clock() - cooldownEnemigo >= 2000) {

					dragon->eliminarBolas(jugador->hitBoxJugador());

					jugador->setVidas(-1);

					jugador->agregarPuntaje(-20);



					cooldownEnemigo = clock();

				}

			}

			buffer->Graphics->DrawString("TIEMPO " + TIEMPODRAGON / 10, gcnew Font("Arial", 20), Brushes::White, 10, 50);

			if (TIEMPODRAGON >= 200) {

				buffer->Graphics->DrawString(" PASASTE LA PRUEBA ", gcnew Font("Arial", 20), Brushes::White, 200, 50);

				dragonActivo = false;

				entradaSemilla->Mostrar(buffer, spritePortales);

				if (jugador->hitBoxJugador().IntersectsWith(entradaSemilla->getArea())) {

					numMapa = 7;

					jugador->posicionar(10, 250);

					jugador->agregarPuntaje(50);



				}

			}



		}

		else if (numMapa == 7) {


			aliado->Mostrar(buffer, spriteAliado);



			if (jugador->hitBoxJugador().IntersectsWith(aliado->getArea())) {

				if (estadoAliado == 0) {
					gestorD->cargarEscena(12);
					gestorD->siguienteFrase();
					estadoAliado = 1;
				}

				seguirAjugador = true; // El aliado empieza a seguir
			}

			if (seguirAjugador == true) {

				aliado->seguirJugador(

					jugador->getX(),

					jugador->getY(),

					jugador->getAncho(),

					jugador->getAlto()

				);

			}


			semilla->Mostrar(buffer, spriteSemilla);

			if (jugador->hitBoxJugador().IntersectsWith(semilla->HitBoxObjeto())) {

				numMapa = 8;

				jugador->posicionar(10, 250);
				aliado->posicionar(0, aliado->getY());

				jugador->agregarPuntaje(100);

			}

		}









		if (puedeMoverse) {

			jugador->Mover(buffer);

		}

		return true;

	}



	bool ejecutarMundo3(BufferedGraphics^ buffer) {

		bool puedeMoverse = true;

		ActualizarMapa(buffer);

		DibujarMapa(buffer);





		if (aliado) {



			aliado->seguirJugador(

				jugador->getX(),

				jugador->getY(),

				jugador->getAncho(),

				jugador->getAlto()

			);

			aliado->Mostrar(buffer, spriteAliado);


			//if (jugador->getNextArea().IntersectsWith(aliado->getArea())) {

			// puedeMoverse = false;

			//}

		}

		if (numMapa == 8) {

			if (!dialogoMundo3) {
				gestorD->cargarEscena(15);
				gestorD->siguienteFrase();
				dialogoMundo3 = true;
			}

			tirarPiedra++;

			if (portalRobot != nullptr) {

				portalRobot->Mostrar2(buffer, spritePortales);

			}

			if (portalRobot != nullptr && jugador->hitBoxJugador().IntersectsWith(portalRobot->hitBox())) {

				if (portalRobot2 == nullptr) {

					portalRobot2 = new Portal(770, 100, 2);

					jugador->posicionar(740, 100);



				}

			}

			if (portalRobot2 != nullptr) {

				portalRobot2->Mostrar2(buffer, spritePortales);

			}



			if (tirarPiedra >= TiempoParaTirarPiedra) {

				npcRobot->CrearPiedra();

				npcRobot2->CrearPiedra();

				npcRobot3->CrearPiedra();

				npcRobot4->CrearPiedra();

				npcT->CrearPiedra();

				npcT1->CrearPiedra();

				npcT2->CrearPiedra();

				npcT3->CrearPiedra();

				tirarPiedra = 0;

			}

			npcRobot->TirarPiedras(buffer, spritePiedra, 1);

			npcRobot2->TirarPiedras(buffer, spritePiedra, 1);

			npcRobot3->TirarPiedras(buffer, spritePiedra, 1);

			npcRobot4->TirarPiedras(buffer, spritePiedra, 1);

			npcT->TirarPiedras(buffer, spritePiedra, 2);

			npcT1->TirarPiedras(buffer, spritePiedra, 2);

			npcT2->TirarPiedras(buffer, spritePiedra, 2);

			npcT3->TirarPiedras(buffer, spritePiedra, 2);



			npcRobot->Mostrar2(buffer, spriteNpcRobot);

			npcRobot2->Mostrar2(buffer, spriteNpcRobot);

			npcRobot3->Mostrar2(buffer, spriteNpcRobot);

			npcRobot4->Mostrar2(buffer, spriteNpcRobot);



			npcT->Mostrar2(buffer, spriteNpcT);

			npcT2->Mostrar2(buffer, spriteNpcT);

			npcT3->Mostrar2(buffer, spriteNpcT);

			npcT1->Mostrar2(buffer, spriteNpcT);





			if (npcRobot->colisionConPiedra(jugador->hitBoxJugador()) == true && clock() - cooldownEnemigo >= 1500) {

				jugador->setVidas(-1);

				cooldownEnemigo = clock();

				jugador->agregarPuntaje(-20);

			}

			else if (npcRobot2->colisionConPiedra(jugador->hitBoxJugador()) == true && clock() - cooldownEnemigo >= 1500) {

				jugador->setVidas(-1);

				cooldownEnemigo = clock();

				jugador->agregarPuntaje(-20);



			}

			else if (npcRobot3->colisionConPiedra(jugador->hitBoxJugador()) == true && clock() - cooldownEnemigo >= 1000) {

				jugador->setVidas(-1);

				cooldownEnemigo = clock();

				jugador->agregarPuntaje(-20);



			}

			else if (npcRobot4->colisionConPiedra(jugador->hitBoxJugador()) == true && clock() - cooldownEnemigo >= 1000) {

				jugador->setVidas(-1);

				cooldownEnemigo = clock();

				jugador->agregarPuntaje(-20);



			}

			else if (npcT->colisionConPiedra(jugador->hitBoxJugador()) == true && clock() - cooldownEnemigo >= 1000) {

				jugador->setVidas(-1);

				cooldownEnemigo = clock();

				jugador->agregarPuntaje(-20);



			}

			else if (npcT1->colisionConPiedra(jugador->hitBoxJugador()) == true && clock() - cooldownEnemigo >= 1000) {

				jugador->setVidas(-1);

				cooldownEnemigo = clock();

				jugador->agregarPuntaje(-20);



			}

			else if (npcT2->colisionConPiedra(jugador->hitBoxJugador()) == true && clock() - cooldownEnemigo >= 1000) {

				jugador->setVidas(-1);

				cooldownEnemigo = clock();

				jugador->agregarPuntaje(-20);



			}

			else if (npcT3->colisionConPiedra(jugador->hitBoxJugador()) == true && clock() - cooldownEnemigo >= 1000) {

				jugador->setVidas(-1);

				cooldownEnemigo = clock();

				jugador->agregarPuntaje(-20);



			}


			entradaColaborativa1->Mostrar(buffer);

			if (jugador->hitBoxJugador().IntersectsWith(entradaColaborativa1->getArea())) {

				jugador->posicionar(10, jugador->getY());

				aliado->posicionar(0, aliado->getY());

				numMapa = 9;

			}



		}

		else if (numMapa == 9) {

			entradaColaborativa2->Mostrar(buffer);

			npcAliado->Mostrar(buffer, spriteNpcAliado);


			if (jugador->nextHitBoxJugador().IntersectsWith(npcAliado->Hitbox())) {

				puedeMoverse = false;

				if (!dialogoAliadoRealizado)
				{
					gestorD->cargarEscena(17);
					gestorD->siguienteFrase();
					dialogoAliadoRealizado = true;
				}
			}

			if (jugador->hitBoxJugador().IntersectsWith(entradaColaborativa2->getArea())) {
				jugador->posicionar(250, 300);
				aliado->posicionar(0, aliado->getY());
				numMapa = 10;
			}

		}


	



		

		else if (numMapa == 10) {

			npcJetPack->Mostrar(buffer, spriteNpcJetPack);

			if (jugador->hitBoxJugador().IntersectsWith(npcJetPack->Hitbox())) {

				if (numSkin != 3 && !eventoJetpackIniciado) {
					gestorD->cargarEscena(16);
					gestorD->siguienteFrase();

					eventoJetpackIniciado = true;
				}
			}

			if (eventoJetpackIniciado && !hayHistoriaActiva()) {

				numSkin = 3;
				actualizarSkin();

				colisionConNpcJetPack = true;
				ejercutarDiparo = true;

				aliensActivos = true; 

				jugador->agregarPuntaje(150);

				eventoJetpackIniciado = false; 
			}








		buffer->Graphics->DrawString("TIEMPO " + tiempoDuracionAlien / 10, gcnew Font("alegrian", 20), Brushes::Black, 400, 50);

		if (aliensActivos == true) {

			corazon++;

			if (tiempoDuracionAlien >= 0) {

				tiempoDuracionAlien--;

			}

			else {

				tiempoDuracionAlien = 0;

				aliensActivos = false;



			}

			tiempoAlien++;

			if (tiempoAlien >= tiempoAparicionAliens && tiempoDuracionAlien != 0) {

				aliens->Agregar(new Alien);

				tiempoAlien = 0;



			}



			if (aliens->colision(jugador->hitBoxJugador()) == true && clock() - cooldownEnemigo >= 2000) {

				jugador->setVidas(-1);

				jugador->agregarPuntaje(-20);

				cooldownEnemigo = clock();

			}

			if (corazon >= tiempoRegenarCorazon) {

				aliado->CrearCorazon(aliado->getX(), aliado->getY());

				corazon = 0;

			}



		}


		if (tiempoDuracionAlien == 0 && portalFinal == nullptr) {

			portalFinal = new Portal(900, 100, 2);



		}



		if (aliado->colisionCorazon(jugador->hitBoxJugador())) {

			jugador->setVidas(1);

			aliado->eliminarCorazones(jugador->hitBoxJugador());

		}

		if (portalFinal != nullptr) {

			portalFinal->Mostrar(buffer, spritePortales);

			if (jugador->hitBoxJugador().IntersectsWith(portalFinal->getArea())) {

				numMapa = 11;

				jugador->posicionar(10, jugador->getY());

				aliado->posicionar(0, aliado->getY());

			}

		}




		balas->Mover(buffer);

		balas->Mostrar(buffer, spriteBala);

		aliens->Mover(buffer);

		aliens->Mostrar(buffer, spriteAliens);



		aliado->DibujarCorazon(buffer, spriteVida);

		for (int i = 0; i < balas->cantidad(); i++) {

			Bala* balaActual = balas->Get(i);

			int aliensImpactados = aliens->Eliminar(balaActual->getArea());

			if (aliensImpactados > 0) {

				jugador->agregarPuntaje(aliensImpactados * 20);
				balas->Eliminar(i);



				i--;

			}

		}



		/*if (jugador->getArea().IntersectsWith(npcJetPack->Hitbox())) {

			numSkin = 3;

			actualizarSkin();

		}*/

	}

		



	if (numMapa == 11) {

		fin->Mostrar2(buffer, spriteFinal);

		if (jugador->hitBoxJugador().IntersectsWith(fin->areaObjeto()))
		{
			puedeMoverse = false;

			if (!dialogoFinRealizado) {
				gestorD->cargarEscena(18);
				gestorD->siguienteFrase();
				dialogoFinRealizado = true;
			}

			if (dialogoFinRealizado && !hayHistoriaActiva()) {
				FinDelJuego();
			}
		}
	}



		if (puedeMoverse) {

			jugador->Mover(buffer);

		}

		jugador->Mostrar(buffer, spriteJugador);

		return true;

	}
	
	void SetNumMapaAc(int nuevoMapa) {

		this->numMapa = nuevoMapa;

	}



	void setSkinJuga(int skinjuga) {

		this->numSkin = skinjuga;

		actualizarSkin();

	}

	int getSkinJuga() {

		return numSkin;

	}



	int getVidasJuga() {

		return jugador->getVidas();

	}

	void mostrarIntruc(BufferedGraphics^ buffer) {

		SetNumMapaAc(12);

		ActualizarMapa(buffer);

		DibujarMapa(buffer);

		jugador->posicionar(230, 140);

		jugador->Mostrar(buffer, conTraje);



	}

	void mostrarCredi(BufferedGraphics^ buffer) {
		SetNumMapaAc(13);
		ActualizarMapa(buffer);
		DibujarMapa(buffer);
	}




	//Archivos



	void GuardarPuntajeFinal(int puntajeFinal) {

		std::string nombreStd = jugador->getNombre();
		GestorArchivos gestor;
		gestor.ActualizarRanking(nombreStd, puntajeFinal);

	}





	//Uso de IA para convertir String^ a std::string con Marshal

	void asignarNombre(System::String^ nombreNet) {


		const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(nombreNet)).ToPointer();
		std::string nombreStd = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));

		jugador->setNombre(nombreStd);

	}







	void FinDelJuego() {

		if (!juegoFinalizado) {

			Archivos->ActualizarRanking(jugador->getNombre(), jugador->getPuntaje());

			juegoFinalizado = true;

		}

	}









	void DibujarCoheteAnimacion(BufferedGraphics^ buffer, Bitmap^ bmp, int anchoPanel, int altoPanel) {

		int anchoSpriteTotal = bmp->Width;
		int altoSprite = bmp->Height;
		int anchoFrame = anchoSpriteTotal / 11;

		int frameIndex = animacion % 11;

		Rectangle sprite = Rectangle(anchoFrame * frameIndex, 0, anchoFrame, altoSprite);
		Rectangle zoom = Rectangle(0, 0, anchoPanel, altoPanel);

		buffer->Graphics->DrawImage(bmp, zoom, sprite, GraphicsUnit::Pixel);

		animacion++;
		if (animacion > 3300) animacion = 0;
	}

	void EjecutarCinematicaCohete(BufferedGraphics^ buffer) {

		int ancho = buffer->Graphics->VisibleClipBounds.Width;
		int alto = buffer->Graphics->VisibleClipBounds.Height;

		DibujarCoheteAnimacion(buffer, spriteCoheteAnimado, ancho, alto);

		if (faseCinematica == 0) {
			tiempoEsperaCinematica++;

			if (tiempoEsperaCinematica >= 20) {
				faseCinematica = 1;

				gestorD->cargarEscena(9);
				gestorD->siguienteFrase();
			}
		}

		else if (faseCinematica == 1) {
		}

		else if (faseCinematica == 2) {

			if (!hayHistoriaActiva()) {
				numMapa = 5;
				jugador->posicionar(50, 250);

				faseCinematica = 0;
				tiempoEsperaCinematica = 0;
				animacion = 0;
			}
		}
	}



	~Controlador() {

	}


};

