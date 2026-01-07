#pragma once
#include "Entidad.h"

class Aliado : public Entidad
{

private:
	double velocidadSeguimiento = 18.0; // Velocidad con la que el aliado sigue al jugador
	double margenDetencion = 150.0;
	std::vector<Objeto*> corazones;

public:
	Aliado(int startX, int startY) {
		this->x = startX;
		this->y = startY;

		dx = dy = 0;
	}
	void CrearCorazon(int x, int y) {
		corazones.push_back(new Objeto(x,y));
	}

	void DibujarCorazon(BufferedGraphics ^ buffer, Bitmap ^bmp) {
		for (int z = 0; z < corazones.size(); z++) {
			corazones[z]->Mostrar(buffer,bmp);
		}
	}
	void eliminarCorazones(Rectangle area) {
		for (int z = 0; z < corazones.size(); z++) {
			if (corazones[z]->HitBoxObjeto().IntersectsWith(area)) {
				corazones.erase(corazones.begin() + z--);
			}
		}
	}
	bool colisionCorazon(Rectangle area) {
		for (int z = 0; z < corazones.size(); z++) {
			if (corazones[z]->HitBoxObjeto().IntersectsWith(area)) {
				return true;
			}
		}
		return false;
	}
	void Mostrar(BufferedGraphics^ buffer, Bitmap^ bmp) {
		ancho = bmp->Width;
		alto = bmp->Height;
		Rectangle sprite = Rectangle(ancho * iteraX, alto * iteraY, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho*0.2, alto*0.2);
		buffer->Graphics->DrawImage(bmp, zoom, sprite, GraphicsUnit::Pixel);
	/*	buffer->Graphics->DrawRectangle(Pens::Black,getArea());*/
	}
	Rectangle getArea() {
		return Rectangle(x,y,ancho*0.2,alto*0.2);
	}

	void posicionar(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void seguirJugador(int jugadorX, int jugadorY, int jugadorAncho, int jugadorAlto) {
		int aliadoCentroX = this->x + this->ancho*0.2;
		int aliadoCentroY = this->y + this->alto *0.2;
		int jugadorCentroX = jugadorX + jugadorAncho / 2;
		int jugadorCentroY = jugadorY + jugadorAlto / 2;

		// 1. Calcular la diferencia (dirección)
		int dx_diff = jugadorCentroX - aliadoCentroX;
		int dy_diff = jugadorCentroY - aliadoCentroY;

		double distancia = sqrt(pow(dx_diff, 2) + pow(dy_diff, 2));

		if (distancia > margenDetencion) {

			this->dx = (int)(velocidadSeguimiento * (dx_diff / distancia));
			this->dy = (int)(velocidadSeguimiento * (dy_diff / distancia));

			// 4. Mover la posición
			this->x += this->dx;
			this->y += this->dy;
		}
		else {
			// 5. Detener el movimiento si está lo suficientemente cerca
			this->dx = 0;
			this->dy = 0;
		}

	}


	~Aliado() {}

};
