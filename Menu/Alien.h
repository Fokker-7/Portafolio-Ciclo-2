#pragma once
#include "Entidad.h"
class Alien : public Entidad
{
private:
	
public:
	Alien() {
		x = rand() %  + 950;
		y = rand() % 100 + 100;

		dy = 10;
		dx = 10;
	}
	void Mover(BufferedGraphics^ buffer) {
		int numeroRandom = rand() % 100 + 1;
		if (numeroRandom >= 95) {
			dx *= -1;
		}
		numeroRandom = rand() % 100 + 1;
		if (numeroRandom >= 95) {
			dy *= -1;
		}
		if (x + dx >= 0 && x + ancho + dx < buffer->Graphics->VisibleClipBounds.Width) x += dx;
		if (y + dy >= 0 && y + alto + dy < buffer->Graphics->VisibleClipBounds.Height) y += dy;

	}


	void Mostrar(BufferedGraphics^buffer, Bitmap ^bmp) {
		ancho = bmp->Width / 20;
		alto = bmp->Height/1;
		Rectangle sprite = Rectangle(ancho * iteraX, alto*iteraY, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho*0.7, alto*0.7);
		buffer->Graphics->DrawImage(bmp, zoom, sprite, GraphicsUnit::Pixel);
		//buffer->Graphics->DrawRectangle(Pens::White, getArea());
		//buffer->Graphics->DrawRectangle(Pens::Blue, getHitBox());
		if (iteraX >= 0 && iteraX < 19) {
			iteraX++;
		}
		else {
			iteraX = 0;
		}

	}
	Rectangle getArea() {
		return Rectangle(x, y, ancho, alto);
	}
	Rectangle getHitBox() {
		return Rectangle(x+ancho/10, y+alto/10, ancho*0.5, alto*0.5);
	}
	~Alien(){}
};

class Aliens
{

private:
	std::vector<Alien*> aliens;

public:
	Aliens() {

	}
	~Aliens() {

	}

	void Agregar(Alien* a) {
		aliens.push_back(a);
	}
	//void Eliminar(int pos) {
	//	aliens.erase(aliens.begin() + pos);
	//}
	void Mover(BufferedGraphics^buffer) {
		for (int z = 0; z < aliens.size(); z++) {
			aliens[z]->Mover(buffer);
		}
	}
	void Mostrar(BufferedGraphics^ buffer, Bitmap^ bmp) {
		for (int z = 0; z < aliens.size(); z++) {
			aliens[z]->Mostrar(buffer, bmp);
		}
	}

	bool colision(Rectangle obj) {
		for (int z = 0; z < aliens.size(); z++) {
			if (aliens[z]->getHitBox().IntersectsWith(obj)) return true;
		}
		return false;
	}

	//void Eliminar() {
	//	for (int z = 0; z < aliens.size(); z++) {		
	//		aliens.erase(aliens.begin() + z--);
	//	} 
	//}
	int Eliminar(Rectangle rect) {
		int cant = 0;
		for (int z = 0; z < aliens.size(); z++) {
			if (aliens[z]->getHitBox().IntersectsWith(rect)) {
				delete aliens[z];
				aliens.erase(aliens.begin() + z--);
				cant++;
			}
		}
		return cant;
	}
	Alien* get(int pos) {
		return aliens[pos];
	}
	int cantidad() {
		return aliens.size();
	}
};