#pragma once
#include "Entidad.h"

enum SpriteEnemigo {
	eCaminarIzquierda, 
	eCaminarDerecha
};

class Enemigo : public Entidad
{
private:
	SpriteEnemigo accion;
public:
	Enemigo(int startX, int startY) {
		x = startX;
		y = startY;
		dx = rand() % 10 + 20;
		accion = eCaminarDerecha;
	}

	void Mostrar(BufferedGraphics ^ buffer, Bitmap ^bmp) {
		ancho = bmp->Width/3;
		alto = bmp->Height/2;
		Rectangle sprite = Rectangle(ancho * iteraX, alto * accion, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho, alto );
		buffer->Graphics->DrawImage(bmp, zoom, sprite, GraphicsUnit::Pixel);
		//buffer->Graphics->DrawRectangle(Pens::White, getArea());
		//buffer->Graphics->DrawRectangle(Pens::White, hitBoxEnemigo());
		iteraX++;
		if (iteraX == 3) iteraX = 0;
	}

	void Mover(BufferedGraphics ^ buffer) {
		if (!(x + dx >= 0 && x + ancho + dx < buffer->Graphics->VisibleClipBounds.Width))dx *= -1;
		if (!(y + dy >= 0 && y + alto + dy < buffer->Graphics->VisibleClipBounds.Height))dy *= -1;

		if (dx > 0) { 
			accion = eCaminarDerecha;
		}
		else if (dx < 0) {
			accion = eCaminarIzquierda;
		}
		x += dx;
		y += dy;

	}
	Rectangle hitBoxEnemigo() {
		return Rectangle(x+ancho*0.2, y+alto*0.2, ancho*0.8, alto*0.8);
	}
	~Enemigo() {};

};

class Enemigos
{
private:
	std::vector<Enemigo*> enemigos;
	int n;
public:
	Enemigos(){
		int pos_x[] = { 0, 250, 400};
		int pos_y[] = { 50, 150, 300};
		n = 3;
		for (int z = 0; z < n; z++) {
			enemigos.push_back(new Enemigo(pos_x[z], pos_y[z]));
		}
	}

	void Mostrar(BufferedGraphics^ buffer, Bitmap^ bmp) {
		for (int z = 0; z < enemigos.size(); z++) {
			enemigos[z]->Mostrar(buffer, bmp);
		}
	}

	void Mover(BufferedGraphics ^ buffer) {
		for (int z = 0; z < enemigos.size(); z++) {
			enemigos[z]->Mover(buffer);
		}
	}

	bool colisionRecoger(Rectangle rec) {
		for (int z = 0; z < enemigos.size(); z++) {
			if (enemigos[z]->getArea().IntersectsWith(rec))return true;
		}
		return false;
	}





	~Enemigos(){}


};
