#pragma once
using namespace System::Drawing;
class BolasFuego
{
private:
	bool activa;
	int x, y, ancho, alto, dx, dy;
	
public:
	BolasFuego(int x,int y){ 
		dx = rand() % 10+25;
		this->x = x;
		this->y = y;
		activa = true;
	}
	void DibujarBolas(BufferedGraphics ^ buffer, Bitmap ^ bmp) {
		ancho = bmp->Width;
		alto = bmp->Height;
		Rectangle sprite = Rectangle(0, 0, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho*0.5 , alto*0.5 );
		buffer->Graphics->DrawImage(bmp, zoom, sprite, GraphicsUnit::Pixel);
		//buffer->Graphics->DrawRectangle(Pens::Yellow, x,y,ancho,alto);
		//buffer->Graphics->DrawRectangle(Pens::White, hitBoxFuego());
	}
	void MoverBolas(BufferedGraphics^ buffer, Bitmap^ bmp) {
		if (activa == true) {
			x+=dx*-1;
			DibujarBolas(buffer, bmp);
		}

	}
	Rectangle hitBoxFuego() {
		return Rectangle(x, y, ancho * 0.5, alto * 0.5);
	}

	void BolasActivas(bool n) {
		this->activa = n;
	}


	~BolasFuego() {};



};


