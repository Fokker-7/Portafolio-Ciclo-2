#pragma once
#include "Entidad.h"

class Portal: public Entidad
{
private:

public:
	Portal(int x, int y, int iteray) {
		this->x = x;
		this->y = y;
		this->iteraY = iteray;

	}

	void Mostrar(BufferedGraphics^ buffer, Bitmap ^bmp) {
		ancho = bmp->Width /5;
		alto = bmp->Height / 3;
		Rectangle sprite = Rectangle(ancho * iteraX, alto * iteraY, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho, alto);
		/*buffer->Graphics->DrawRectangle(Pens::Black,getArea());*/
		buffer->Graphics->DrawImage(bmp, zoom, sprite, GraphicsUnit::Pixel);
		if (iteraX >= 0 && iteraX < 4) {
			iteraX++;
		}
		else {
			iteraX = 0;
		}

	}

	void Mostrar2(BufferedGraphics^ buffer, Bitmap^ bmp) {
		ancho = bmp->Width / 5;
		alto = bmp->Height / 3;
		Rectangle sprite = Rectangle(ancho * iteraX, alto * iteraY, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho*0.7, alto*0.7);
		buffer->Graphics->DrawImage(bmp, zoom, sprite, GraphicsUnit::Pixel);
	/*	buffer->Graphics->DrawRectangle(Pens::White,hitBox());*/
		if (iteraX >= 0 && iteraX < 4) {
			iteraX++;
		}
		else {
			iteraX = 0;
		}
	}
	Rectangle hitBox() {
		return Rectangle(x+ancho/2,y+alto /4,ancho*0.2,alto*0.2);
	}
	void Mover() {}
	~Portal() {

	}


};

