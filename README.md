# LOST WORLD
> Proyecto final de Ingeniería de Software (2º Ciclo) enfocado en la aplicación de POO y ética profesional.

<img width="1023" height="478" alt="image" src="https://github.com/user-attachments/assets/8ec866fc-1e1a-470b-921b-0f1f2a134dc9" />

## Descripción del Proyecto
Este proyecto es una solución de software desarrollada en C++ utilizando Windows Forms. El objetivo no fue solo crear un juego, sino abordar una problemática social contemporánea: el impacto de la Inteligencia Artificial en el empleo y la necesidad del pensamiento crítico.

A través de una narrativa interactiva, el jugador se enfrenta a dilemas éticos y experimenta las consecuencias de la automatización, cumpliendo con las competencias de Diseño de Ingeniería y Responsabilidad Ética y Profesional (ABET).

## Tecnologías y Arquitectura
El sistema se construyó bajo los principios estrictos de la Programación Orientada a Objetos (POO):

* **Lenguaje:** C++ (CLR / Windows Forms).
* **Patrones de Diseño:** Uso intensivo de Herencia y Polimorfismo para gestionar entidades (NPCs, Jugador, Enemigos) reduciendo la redundancia de código.
* **Diseño:** Modelado previo mediante Diagramas de Clases UML para definir relaciones de composición y agregación.
* **Lógica:** Manejo de eventos (Timers, KeyEvents) y bucle de juego (Game Loop).

## Características Principales
* **Sistema de Narrativa Ética:** Interfaz de animación con movimiento bloqueado y cuadros de texto que presentan dilemas morales al usuario.
* **Múltiples Mundos:** Transición fluida entre 3 escenarios distintos que representan diferentes etapas del impacto tecnológico.
* **NPCs Interactivos:** Sistema de diálogos dinámico gestionado con estructuras de datos; la historia evoluciona, no es estática.

## Aprendizajes y Conclusiones Técnicas
Durante el desarrollo de este proyecto se validaron los siguientes puntos de ingeniería:

1.  **Escalabilidad:** Se demostró que un buen diseño UML previo es clave. Crear una "Clase Padre" permitió gestionar decenas de mecánicas desde un solo bloque de código.
2.  **Interfaz vs. Lógica:** Se integró la lógica abstracta de C++ con la experiencia visual de Windows Forms, aprendiendo a controlar la "ToolBox" y los eventos en tiempo real.
3.  **Ingeniería de Requisitos:** Se logró traducir una necesidad abstracta (concientización sobre la IA) en requerimientos funcionales técnicos (mecánicas de juego).
4.  **Trabajo en Equipo:** Se aplicó una división de tareas por áreas (diseño visual, lógica, funciones) para minimizar conflictos en el control de versiones.
