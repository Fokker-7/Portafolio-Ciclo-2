#pragma once
#include "Entidad.h"

class Androide : public Entidad
{
protected:
public:
	Androide() {
		x = rand() % 600+300;
		y = rand() % 300+50;

		if (rand() % 2 == 0) {
			dx = rand() % 20 - 15;
			if (dx == 0) dx = 15;

		}
		else {
			dy = rand() % 20 - 15;
			if (dy == 0) dy = 15;
		}


	}
	void Mostrar(BufferedGraphics ^ buffer, Bitmap^bmp) {
		ancho = bmp->Width/4;
		alto = bmp->Height/4;
		Rectangle sprite = Rectangle(ancho * iteraX, alto * iteraY, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho, alto);
		buffer->Graphics->DrawImage(bmp,zoom,sprite,GraphicsUnit::Pixel);
		//buffer->Graphics->DrawRectangle(Pens::White,getArea());
		//buffer->Graphics->DrawRectangle(Pens::Blue, hitBoxDroide());
		if (iteraX >= 0 && iteraX < 3) {
			iteraX++;
		}
		else {
			iteraX = 0;
		}
	}
	void Mover(BufferedGraphics^ buffer) {
		if (!(x + dx >= 0 && x + ancho + dx < buffer->Graphics->VisibleClipBounds.Width))dx *= -1;
		if (!(y + dy >= 0 && y + alto + dy < buffer->Graphics->VisibleClipBounds.Height))dy *= -1;
		// 1. Prioridad: Movimiento Vertical (dy != 0)
		if (dy < 0) {
			iteraY = 3;
		}
		else if (dy > 0) {
			iteraY = 2; 
		}
		
		else if (dx < 0) {
			iteraY = 0; 
		}
		else if (dx > 0) {
			iteraY = 1; 
		}

		x += dx;
		y += dy;
	}
	Rectangle hitBoxDroide() {
		return Rectangle(x + ancho / 4, y + 8, ancho / 2, alto * 0.80);
	}

	Rectangle nextHitBoxDroide() {
		return Rectangle(x + dx + ancho / 4, y + dy, ancho / 2, alto);
	}

	~Androide() {};
};

class Androides
{
private:
	std::vector<Androide*> androides;
	int n;
public:

	Androides() {
		n = 8;
		for (int z = 0; z < n; z++) {
			androides.push_back(new Androide);
		}
	}

	void Mover(BufferedGraphics ^buffer) {
		for (int z = 0; z < androides.size(); z++) {
			androides[z]->Mover(buffer);
		}
	}
	void Mostrar(BufferedGraphics^ buffer, Bitmap ^ bmp) {
		for (int z = 0; z < androides.size(); z++) {
			androides[z]->Mostrar(buffer, bmp);
		}
	}

	bool colisionConAndroide(Rectangle obj) {
		for (int z = 0; z < androides.size(); z++) {
			if (androides[z]->hitBoxDroide().IntersectsWith(obj)) return true;
		}
		return false;
	}

	bool eliminarDroide(Rectangle area) {
		for (int z = 0; z < androides.size(); z++) {
			if (androides[z]->getArea().IntersectsWith(area)) {
				androides.erase(androides.begin() + z--);
				return true;
			}
		}
		return false;
	}

	int cantidadDroides() {
		return androides.size();
	}


	~Androides() {};



};


