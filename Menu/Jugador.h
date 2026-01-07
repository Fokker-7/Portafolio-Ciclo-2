#pragma once
#include "Entidad.h"
enum spriteJugador {
	CaminarIzquierda,
	CaminarAbajo,
	CaminarArriba,
	CaminarDerecha,
	Atacar
};
class Jugador :public Entidad
{
private:
	int vidas;
	int invulneravilidad;
	spriteJugador accion;
	string nombre;
	int puntaje;

public:
	Jugador() {
		x = y = 50;
		dx = dy = 0;
		vidas = 5;
		accion = CaminarAbajo;
		puntaje = 0;

	}
	void setAccion(spriteJugador value) {
		this->accion = value;
	}
	void setVidas(int value) {
		this->vidas += value;
	}

	int getVidas() {

		return vidas;
	}

	spriteJugador getAccion() {
		return accion;
	}

	void Mover(BufferedGraphics^ buffer) {
		if (x + dx >= 0 && x + ancho + dx < buffer->Graphics->VisibleClipBounds.Width+50) x += dx;
		if (y + dy >= 0 && y + alto + dy < buffer->Graphics->VisibleClipBounds.Height) y += dy;

	}
	void Mostrar(BufferedGraphics^ buffer, Bitmap^ bmp) {

		if (dx != 0 || dy != 0) {
			iteraX++;
			if (iteraX == 4) iteraX = 0;
		}

		ancho = bmp->Width / 4;
		alto = bmp->Height / 5;
		Rectangle sprite = Rectangle(ancho * iteraX, alto * accion, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho, alto);
		buffer->Graphics->DrawImage(bmp, zoom, sprite, GraphicsUnit::Pixel);
		//buffer->Graphics->DrawRectangle(Pens::White, getArea());
		//buffer->Graphics->DrawRectangle(Pens::Blue, hitBoxJugador());
		buffer->Graphics->DrawString("VIDAS: " + vidas, gcnew Font("Arial Black", 12), Brushes::Red, 10, 10);
		buffer->Graphics->DrawString("PUNTAJE: " + puntaje, gcnew Font("Arial Black", 12), Brushes::Yellow, 100, 10);

	}
	Rectangle getArea() {
		return Rectangle(x + ancho/9, y + alto/25, ancho*0.8, alto);
	}

	Rectangle hitBoxJugador() {
		return Rectangle(x + ancho / 4, y + alto / 10, ancho / 2, alto * 0.8);
	}

	Rectangle nextHitBoxJugador() {
		return Rectangle(x + dx + ancho / 4, y + dy, ancho / 2, alto);
	}

	void setIteraX(int n) {
		this->iteraX = n;
	}

	void setIteraY(int n) {
		this->iteraY = n;
	}


	void posicionar(int x,int y) {
		this->x = x;
		this->y = y;
	}

	//Archivos
	void setNombre(string nombre) {
		this->nombre = nombre;
	}
	string getNombre() {
		return nombre;
	}
	int getPuntaje()
	{
		return puntaje;
	}
	void agregarPuntaje(int puntos)
	{
		puntaje += puntos;
	}

	~Jugador() {};



};