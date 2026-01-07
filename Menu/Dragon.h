#pragma once
#include "Entidad.h"
#include "BolasFuego.h"

using namespace std;
class Dragon : public Entidad
{
protected:
	vector<BolasFuego*> bolas;
public:
	Dragon()
	{
		x = 750;
		y = 60;
		dx = 0;
		dy = 30;
		iteraX = iteraY = 0;

	}
	void Mostrar(BufferedGraphics^ buffer, Bitmap^ bmp) {
		ancho = bmp->Width / 4;
		alto = bmp->Height;
		Rectangle sprite = Rectangle(iteraX * ancho, 0, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 1.3, alto * 1.3);
		buffer->Graphics->DrawImage(bmp, zoom, sprite, GraphicsUnit::Pixel);

	}

	void Mover(BufferedGraphics^ buffer) {

		iteraX++;
		if (iteraX == 4) iteraX = 0;

		if (y < 0 || y + alto >= buffer->Graphics->VisibleClipBounds.Height) {
			dy *= -1;
		}
		y += dy;

	}

	void dispararBolas() {
		bolas.push_back(new BolasFuego(x + (ancho / 2), y + 40));
	}
	void ejecutarDisparo(BufferedGraphics^ buffer, Bitmap^ bmp) {
		for (int z = 0; z < bolas.size(); z++) {
			bolas[z]->MoverBolas(buffer, bmp);
		}


	}

	void activarBolasDefuego(bool b) {
		for (int z = 0; z < bolas.size(); z++) {
			bolas[z]->BolasActivas(b);
		}
	}
	bool colisionConFuego(Rectangle obj) {
		for (int z = 0; z < bolas.size(); z++) {
			if (bolas[z]->hitBoxFuego().IntersectsWith(obj)) return true;
		}
		return false;
	}
	void eliminarBolas(Rectangle area) {
		for (int z = 0; z < bolas.size(); z++) {
			if (bolas[z]->hitBoxFuego().IntersectsWith(area)) {
				bolas.erase(bolas.begin() + z--);
			}
		}
	}

	int posXenemy() { return this->x; }
	int posYenemy() { return this->y; }
	~Dragon() {};

};
