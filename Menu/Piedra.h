#pragma once
#include "Dependencias.h"
class Piedra
{
private:
	int x, y, ancho, alto;
	int dy;
public:
	Piedra(int x,int y) {
		this->x = x;
		this->y = y;
		dy = rand() % 20+10;
	}
	void Dibujar(BufferedGraphics^ buffer, Bitmap^ bmp) {
		ancho = bmp->Width;
		alto = bmp->Height;
		Rectangle sprite = Rectangle(0, 0, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 0.2, alto * 0.2);
		buffer->Graphics->DrawImage(bmp, zoom, sprite, GraphicsUnit::Pixel);
		//buffer->Graphics->DrawRectangle(Pens::Blue,getHitbox());
	}

	void Mover(BufferedGraphics^ buffer, Bitmap^ bmp, int dir) {

		if (dir == 1) {
			y += dy;
		}
		else {
			y -= dy;
		}
		Dibujar(buffer, bmp);
	}

	Rectangle getHitbox() {
		return Rectangle(x,y,ancho*0.2,alto*0.2);
	}
	~Piedra() {};



};

