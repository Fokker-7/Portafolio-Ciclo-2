#pragma once
#include "Entidad.h"
#include "Piedra.h"
class Npc : public Entidad
{
private:
    std::vector<Piedra*> piedras;
public:
    // Constructor 1: Para NPCs normales (usarán el tamaño de la imagen original)
    Npc(int px, int py) {
        x = px;
        y = py;
        dx = 0;
        dy = 0;
        ancho = 0;
        alto = 0;
    }

	// Constructor 2: Para tamaños específicos 
    Npc(int px, int py, int w, int h) {
        x = px;
        y = py;
        dx = 0;
        dy = 0; 
        ancho = w;
        alto = h;
    }

    ~Npc() {}
    void CrearPiedra() {
        piedras.push_back(new Piedra(x +ancho/5, y + alto/2));
    }
    void TirarPiedras(BufferedGraphics^ buffer, Bitmap^ bmp,int dir) {
        for (int z = 0; z < piedras.size(); z++) {
            piedras[z]->Mover(buffer,bmp,dir);
        }
    }
    void Mostrar(BufferedGraphics^ buffer, Bitmap^ bmp) {
        if (ancho == 0 || alto == 0) {
            ancho = bmp->Width;
            alto = bmp->Height;
        }

        // Dibujamos una sola vez con el tamaño correcto
        buffer->Graphics->DrawImage(bmp, x, y, ancho, alto);
        //buffer->Graphics->DrawRectangle(Pens::Green, Area());
        //buffer->Graphics->DrawRectangle(Pens::Red, Hitbox());
    }
    void Mostrar2(BufferedGraphics ^ buffer, Bitmap ^bmp) {
        ancho = bmp->Width / 4;
        alto = bmp->Height / 1;
        Rectangle sprite = Rectangle(ancho * iteraX, alto * iteraY, ancho, alto);
        Rectangle zoom = Rectangle(x, y, ancho * 0.5, alto * 0.5);
        buffer->Graphics->DrawImage(bmp, zoom, sprite, GraphicsUnit::Pixel);
        if (iteraX >= 0 && iteraX < 3) {
            iteraX++;
        }
        else {
            iteraX = 0;
        }
    }
    bool colisionConPiedra(Rectangle obj) {
        for (int z = 0; z < piedras.size(); z++) {
            if (piedras[z]->getHitbox().IntersectsWith(obj)) return true;
        }
        return false;
    }
   
    Rectangle Area() { return Rectangle(x, y, ancho, alto); }
    Rectangle Hitbox() { return Rectangle(x+ancho/5, y+alto/10, ancho*0.6, alto*0.8); }

   };




class NpcAnimado : public Npc {
private:
    int columnas;
    bool animando;

public:
    NpcAnimado(int px, int py, int w, int h, int nColumnas) : Npc(px, py, w, h) {
        this->columnas = nColumnas;
        this->animando = false;
        this->iteraX = 0;
    }



    void setAnimando(bool v) { animando = v; }

    void setFrame(int f) {
        if (f < columnas) iteraX = f;
    }

    void Mostrar(BufferedGraphics^ buffer, Bitmap^ bmp) override {
        int wFrame = bmp->Width / columnas;
        int hFrame = bmp->Height;

        Rectangle origen = Rectangle(iteraX * wFrame, 0, wFrame, hFrame);

        Rectangle destino = Rectangle(x, y, ancho, alto);

        buffer->Graphics->DrawImage(bmp, destino, origen, GraphicsUnit::Pixel);
        //buffer->Graphics->DrawRectangle(Pens::Green, Area());
        //buffer->Graphics->DrawRectangle(Pens::Red, Hitbox());

        if (animando) {
            iteraX++;
            if (iteraX >= columnas) {
                iteraX = 0;
            }
        }
    }
};