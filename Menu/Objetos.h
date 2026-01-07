#pragma once
#include "Entidad.h"
class Objeto : public Entidad
{
private:

public:

	Objeto(int startX,int startY) {
		x = startX;
		y = startY;
	}
	void Mostrar(BufferedGraphics^ buffer, Bitmap^ bmp) {
		ancho = bmp->Width;
		alto = bmp->Height;
		Rectangle sprite = Rectangle(ancho * iteraX, alto * iteraY, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho*0.5, alto*0.5);
		buffer->Graphics->DrawImage(bmp, zoom, sprite, GraphicsUnit::Pixel);
		//buffer->Graphics->DrawRectangle(Pens::White, areaObjeto());
		//buffer->Graphics->DrawRectangle(Pens::Blue, HitBoxObjeto());
	}
	void Mostrar2(BufferedGraphics^ buffer, Bitmap^ bmp) {
		ancho = bmp->Width/5;
		alto = bmp->Height;
		Rectangle sprite = Rectangle(ancho * iteraX, alto * iteraY, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 0.9, alto * 0.9);
		buffer->Graphics->DrawImage(bmp, zoom, sprite, GraphicsUnit::Pixel);
	/*	buffer->Graphics->DrawRectangle(Pens::White, areaObjeto());
		buffer->Graphics->DrawRectangle(Pens::Blue, HitBoxObjeto());*/
		if (iteraX >= 0 && iteraX < 4) {
			iteraX++;
		}
		else {
			iteraX = 0;
		}
	}
	void Mover(BufferedGraphics^ buffer) {};

	Rectangle HitBoxObjeto(){
		return Rectangle(x + ancho/13,y + alto/14,ancho*0.4,alto*0.4);
	}
	Rectangle areaObjeto() {
		return Rectangle(x,y,ancho*0.6,alto*0.6);
	}
	~Objeto() {};
	

};

class Objetos
{
private:
	std :: vector<Objeto*> objetos;
	int n;	
public:
	Objetos() {
		//int pos_x[] = { 200, 350, 400, 240, 550, 700 };
		//int pos_y[] = { 210, 100, 150, 150, 250, 280 };
		int pos_x[] = { 1+rand()%800 , 1 + rand() % 800, 1 + rand() % 800, 1 + rand() % 800, 1 + rand() % 800, 1 + rand() % 800 };
		int pos_y[] = { 1 + rand() % 300, 1 + rand() % 300, 1 + rand() % 300, 1 + rand() % 300, 1 + rand() % 300, 1 + rand() % 300 };
		n = 6;

		for (int z = 0; z < n; z++) {
			objetos.push_back(new Objeto(pos_x[z], pos_y[z]));
		}

	}

	void Mostrar(BufferedGraphics^ buffer, Bitmap^ bmp) {
		for (int z = 0; z < objetos.size(); z++) { 
			objetos[z]->Mostrar(buffer, bmp);
		}
	}


	bool colisionRecoger(Rectangle rec) {
		for (int z = 0; z < objetos.size(); z++) { 
			if (objetos[z]->getArea().IntersectsWith(rec))return true;
		}
		return false;
	}


	bool colisionMovimiento(Rectangle rec) {
		for (int z = 0; z < objetos.size(); z++) { 
			if (objetos[z]->HitBoxObjeto().IntersectsWith(rec))return true;
		}
		return false;
	}


	bool eliminarObjeto(Rectangle area) {
		for (int z = 0; z < objetos.size(); z++) {
			if (objetos[z]->HitBoxObjeto().IntersectsWith(area)) {
		
				delete objetos[z];

			
				objetos.erase(objetos.begin() + z--);
				return true;
			}
		}
		return false;
	}


	int cantidadObjetos() {
		return objetos.size();
	}
	~Objetos() {};



};
