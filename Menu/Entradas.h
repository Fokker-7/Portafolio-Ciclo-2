#pragma once
#include "Entidad.h"

class Entradas : public Entidad
{
private:

public:
	Entradas(int x, int y, int ancho, int alto) {
		this->x = x;
		this->y = y;
		this->ancho = ancho;
		this->alto = alto;

	}

	void Mostrar(BufferedGraphics ^buffer) {

		buffer->Graphics->FillRectangle(Brushes::Red,x,y,ancho,alto);
	}


	void Mover(){}
	~Entradas() {

	}


};

