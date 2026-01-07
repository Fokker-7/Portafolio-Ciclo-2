#pragma once
#include "Entidad.h"


class Bala : public Entidad
{
private:
public:

	Bala(int x, int y, int dx, int dy){
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
		ancho = alto = 30;
	}

	void Mostrar(BufferedGraphics ^buffer, Bitmap^ bmp) {
		ancho = bmp->Width;
		alto = bmp->Height;
		Rectangle sprite = Rectangle(ancho * iteraX, alto * iteraY, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho, alto);
		buffer->Graphics->DrawImage(bmp, zoom, sprite, GraphicsUnit::Pixel);
	/*	buffer->Graphics->DrawRectangle(Pens::White, getArea());*/
	}
	~Bala(){}
};

class Balas
{

private:
	std::vector<Bala* > balas;
public:
	Balas(){
	
	}
	~Balas(){}

	Bala* Get(int pos) {
		return balas[pos];
	}
	void Agregar(Bala * bala) {
		balas.push_back(bala);
	}

	void Mover(BufferedGraphics^ buffer) {
		for (int z = 0; z < balas.size(); z++) {
			balas[z]->Mover(buffer);
		}
	}
	void Mostrar(BufferedGraphics^ buffer, Bitmap^ bmp) {
		for (int z = 0; z < balas.size(); z++) {
			balas[z]->Mostrar(buffer, bmp);
		}
	}

	bool colision(Rectangle obj) {
		for (int z = 0; z < balas.size(); z++) {
			if (balas[z]->getArea().IntersectsWith(obj)) return true;
		}
		return false;
	}

	void Eliminar(int pos) {
		delete balas[pos]; //
		balas.erase(balas.begin() + pos);
	}
	Rectangle colisionB() {
		for (int z = 0; z < balas.size(); z++) {
			return balas[z]->getArea();
		}

	}
	int cantidad() {
		return balas.size();
	}
};
