#pragma once
#include "Dependencias.h"

class Entidad
{
protected:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int iteraX, iteraY;

public:
	Entidad() {
		x = y = 0;
		ancho = alto = 0;
		iteraX = iteraY = 0;
		dx = dy = 0;
	};

	void setDx(int value) {
		this->dx = value;
	}

	void setDy(int value) {
		this->dy = value;
	}

	int getX() { return this->x; }
	int getY() { return this->y; }

	virtual void Mover(BufferedGraphics^ buffer) {
		x += dx;
		y += dy;
	}

	virtual void Mostrar(BufferedGraphics^ buffer, Bitmap^ bmp) {
		buffer->Graphics->FillRectangle(Brushes::Black, x, y, ancho, alto);
	}

	virtual Rectangle getArea() {
		return Rectangle(x, y, ancho, alto);
	}
	virtual Rectangle getNextArea() {
		return Rectangle(x + dx, y + dy, ancho, alto);
	}

	int getAncho() {
		return ancho;
	}

	int getAlto() {
		return alto;
	}
	~Entidad() {};
};