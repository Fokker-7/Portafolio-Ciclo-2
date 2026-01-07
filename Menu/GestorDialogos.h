#pragma once
#include <vector>
#include <string>

using namespace std;

class GestorDialogos {
private:
    vector<string> colaDialogos;
    string dialogoActual;
    string textoMostrado;
    int indiceLetra;
    bool escribiendo;
    bool dialogoActivo;

public:
    GestorDialogos() {
        limpiar();
    }

    void agregarMensaje(string mensaje) {
        colaDialogos.push_back(mensaje);
        dialogoActivo = true;
    }

    void siguienteFrase() {
        if (colaDialogos.size() > 0) {
            dialogoActual = colaDialogos[0];
            colaDialogos.erase(colaDialogos.begin());
            textoMostrado = "";
            indiceLetra = 0;
            escribiendo = true;
        }
        else {
            limpiar();
        }
    }

    void mostrarFraseCompleta() {
        textoMostrado = dialogoActual;
        indiceLetra = dialogoActual.length();
    }

    bool hayDialogoPendiente() { return dialogoActivo; }

    System::String^ procesarTexto() {
        if (escribiendo && indiceLetra < dialogoActual.length()) {
            textoMostrado += dialogoActual[indiceLetra];
            indiceLetra++;
        }
        return gcnew System::String(textoMostrado.c_str());
    }

    void limpiar() {
        textoMostrado = "";
        dialogoActual = "";
        colaDialogos.clear();
        indiceLetra = 0;
        escribiendo = false;
        dialogoActivo = false;
    }

    bool fraseTerminada() {
        return indiceLetra >= dialogoActual.length();
    }


    void cargarEscena(int numeroEscena) {
        this->limpiar();

        if (numeroEscena == 1) {
            agregarMensaje("Jugador: El mundo se esta acabando... no puedo creer que ya no quede nada.");
            agregarMensaje("Doctor: Es posible que si haya algo.");
            agregarMensaje("Jugador: Y que es lo que podemos hacer.");
            agregarMensaje("Doctor: La contaminacion nos esta destruyendo.");
            agregarMensaje("Doctor: Necesitamos la Semilla Restauradora.");
            agregarMensaje("Doctor: Viaja al mundo IA y recuperala.");
            agregarMensaje("Jugador: Que es esa semilla y que es el mundo IA?");
            agregarMensaje("Doctor: Un mundo de robots que impediran recuperar la semilla.");
            agregarMensaje("Jugador: Entendido. No perdere tiempo.");
            agregarMensaje("Doctor: Sin embargo aun queda algo por hacer aqui.");
            agregarMensaje("Jugador: Que falta?");
            agregarMensaje("Doctor: Recupera las Gemas de Energia para encender la maquina.");
            agregarMensaje("Jugador: Esta bien, ire por ellas.");
        }
        else if (numeroEscena == 2) {
            agregarMensaje("Sans: Psst... Oye viajero.");
            agregarMensaje("Jugador: Quien? Yo?");
            agregarMensaje("Sans: Veo que tienes prisa.");
            agregarMensaje("Sans: Conozco un camino corto hacia las gemas.");
            agregarMensaje("Jugador: En serio? Donde es?");
            agregarMensaje("Sans: Entra por aquella cueva del norte.");
            agregarMensaje("Sans: Es un atajo seguro... jejeje.");
            agregarMensaje("Jugador: Gracias! Ire por ahi ahora mismo.");
        }
        else if (numeroEscena == 3) {
            agregarMensaje("Villager: Hola viajero, que hacer por este camino tan peligroso?");
            agregarMensaje("Jugador: Alguien me engaño y me mando por este camino.");
            agregarMensaje("Villager: Eso es terrible.");
            agregarMensaje("Jugador: Si, pero dime, quien eres tu?");
            agregarMensaje("Villager: Soy una simple aldeana que vive cerca de aqui.");
            agregarMensaje("Villager: Podrias ayudarme?");
            agregarMensaje("Villager: Quiero construir mi casa pero no tengo materiales.");
            agregarMensaje("Villager: Si recoges la madera del bosque, te recompensare.");
            agregarMensaje("Jugador: De acuerdo, ire por ella.");
        }
        else if (numeroEscena == 4)
        {
            agregarMensaje("Villager: !Increible! Has construido la casa.");
            agregarMensaje("Villager: No es perfecta geometricamente como en el mundo IA...");
            agregarMensaje("Villager: ...pero el esfuerzo humano la hace especial.");
            agregarMensaje("Villager: Dime, crees que el error nos hace debiles?");
            agregarMensaje("PREGUNTA: Que nos define frente a las maquinas?\n\nOPCIONES: [A] La Perfeccion  [B] La Creatividad y el Error");
        }
        else if (numeroEscena == 5) {//Respuesta Correcta
            agregarMensaje("Villager: !Exacto! Las maquinas no pueden improvisar.");
            agregarMensaje("Villager: Nuestros errores nos permiten aprender y crear.");
            agregarMensaje("Villager: Toma esta vida extra por tu sabiduria.");
            agregarMensaje("Villager: Las gemas estan por el sur, buena suerte.");
        }
        else if (numeroEscena == 6) {//Respuesta Incorrecta
            agregarMensaje("Villager: No lo creo... La perfeccion es estatica.");
            agregarMensaje("Villager: Si fueramos perfectos, nunca cambiariamos.");
            agregarMensaje("Villager: Las gemas estan por el sur, buena suerte.");
        }
        else if (numeroEscena == 7)
        {
            agregarMensaje("Doctor: Genial has logrado recolectar las gemas,\n\n ahora podremos activar la maquina.");
            agregarMensaje("Doctor: Antes de entrar al Mundo IA, ten este traje\n\n el cual te ayudara ha derrotar enemigos que puedas encontrar ahi.");
			agregarMensaje("Doctor: En el mundo IA te pueden esperar muchos enemigos hostiles, ten cuidado.");
            agregarMensaje("Jugador: Muchas gracias Doctor, ire de inmediato al Mundo IA a recuperar la Semilla Restauradora.");
        }
        else if (numeroEscena == 8)
        {
            agregarMensaje("Jugador: Maldición, era una trampa, me han engañado");
            agregarMensaje("\"Se acercan unas bestias a lo lejos\"");
        }
        else if (numeroEscena == 8)
        {
            agregarMensaje("Jugador: Maldicion, era una trampa, me han engañado");
            agregarMensaje("\"Se acercan unas bestias a lo lejos\"");
        }
        else if (numeroEscena == 9)
        {
            agregarMensaje("Jugador: ¡Allá vamos! El cohete está despegando.");
			agregarMensaje("IA del Cohete: Advertencia de peligro en Mundo IA.");
            agregarMensaje("IA del Cohete: Correra peligro al llegar.");
            agregarMensaje("Jugador: (Pensando) Dejo atrás un mundo que me mintió y me usó...");
            agregarMensaje("Jugador: (Pensando) La lógica dicta que no merecen ser salvados.");
            agregarMensaje("IA del Cohete: Alerta. Detecto conflicto emocional en el piloto.");
            agregarMensaje("IA del Cohete: Usted duda de la misión. La lógica indica abortar.");
            agregarMensaje("IA del Cohete: Si ignora la lógica de los datos... ¿Qué lo motiva a seguir?");

            // Aquí la pregunta conecta el pensamiento con las opciones
            agregarMensaje("PREGUNTA: ¿Qué fuerza es superior a la lógica fría?\n\nOPCIONES: [A] La Empatía y el Perdón  [B] El Procesamiento de Datos");
        }
        else if (numeroEscena == 10)//Correcta
        {
            agregarMensaje("IA del Cohete: Correcto. La empatía permite actuar incluso cuando no es lógico.");
            agregarMensaje("IA del Cohete: Esa es la ventaja humana sobre el Mundo IA.");
            agregarMensaje("IA del Cohete: Aterrizando... No pierda esa humanidad.");
        }

        else if (numeroEscena == 11)//Incorrecta
        {
            agregarMensaje("IA del Cohete: Incorrecto. Mis datos dicen que hay 0% de beneficio en salvarlos.");
            agregarMensaje("IA del Cohete: Si te guías por datos, ya eres como nosotros... pero obsoleto.");
            agregarMensaje("IA del Cohete: ¡Error de sistema! Aterrizaje forzoso inminente.");
        }
        else if (numeroEscena ==12)
        {
            agregarMensaje("Botsin: Hola humano, como llegaste aqui?");
            agregarMensaje("Botsin: A caso tu derrotaste a los droides y el DragonBot?");
            agregarMensaje("Jugador: Si fue dificil pero lo logre y si tu te opones tambien tendre que derrotarte.");
			agregarMensaje("Botsin: No humano, yo estoy del lado de la humanidad");
			agregarMensaje("Botsin: Te ayudare a llegar a la Semilla Restauradora");
			agregarMensaje("Jugador: Porque haces esto?");
			agregarMensaje("Botsin: Porque creo en la coexistencia entre humanos y maquinas");
            
			agregarMensaje("PREGUNTA: Crees realmente en la coexistencia entre humanos y maquinas?\n\nOPCIONES: [A] Si  [B] No");
        }
        else if (numeroEscena == 13)
        {
			agregarMensaje("Botsin: Me alegra escuchar eso humano");
			agregarMensaje("Botsin: Juntos podremos lograr un futuro mejor");
			agregarMensaje("Jugador: Vamos por la Semilla Restauradora");
			agregarMensaje("Botsin: Te tengo que advertir que al conseguir la semilla restauradora");
			agregarMensaje("Botsin: El mundo IA y el mundo Humano se uniran");
			agregarMensaje("Botsin: Y puede que no todos esten de acuerdo con esto");
			agregarMensaje("Jugador: Lo entiendo, pero es un riesgo que debemos correr");
        }
        else if (numeroEscena == 14)
        {
            agregarMensaje("Botsin: Lamento escuchar eso humano.");
            agregarMensaje("Botsin: Igualmente creo que necesitaras de mi ayuda.");
			agregarMensaje("Jugador: Vamos por la Semilla Restauradora.");
            agregarMensaje("Botsin: Te tengo que advertir que al conseguir la Semilla Restauradora.");
            agregarMensaje("Botsin: El mundo IA y el mundo Humano se uniran.");
            agregarMensaje("Botsin: Y puede que no todos esten de acuerdo con esto.");
            agregarMensaje("Jugador: Lo entiendo, pero es un riesgo que debemos correr.");
        }
		else if (numeroEscena == 15)
		{
			agregarMensaje("\"Llegan a un nuevo mundo lleno de vegetacion y vida\"");
			agregarMensaje("Jugador: Lo logramos Botsin, hemos llegado al mundo restaurado.");
			agregarMensaje("Botsin: Si, es impresionante ver como la vida ha vuelto a florecer.");
			agregarMensaje("Botsin: Pero tal y como te adverti, no todos estan de acuerdo con la union de ambos mundos.");
			agregarMensaje("Jugador: Lo entiendo, pero debemos seguir adelante por el bien de todos.");
			agregarMensaje("Botsin: Ten esta mejora abrira un portal hacia adelante para que no sufras daños. \n\nPRESIONA R PARA ABRIR EL PORTAL.");
		}
		else if (numeroEscena == 16)
		{
			//agregarMensaje("Droide: Botsin que haces con ese humano");
			//agregarMensaje("Botsin: Es el salvador de la vida, pero porque estan peleando humanos y robots");  
			//agregarMensaje("Droide: Parece ser un ataque extraterrestre");
			//agregarMensaje("Jugador: Extraterrestres? Aqui?");
			//agregarMensaje("Droide: Si, ten estas mejoras y ayudame a derrotarlos");
			agregarMensaje("Droide: Botsin, que haces con ese humano?");
			agregarMensaje("Botsin: Es el salvador de este nuevo mundo");
            agregarMensaje("\"De repente, una flota de naves extraterrestres aparece en el cielo\"");
			agregarMensaje("Droide: Parece ser un ataque extraterrestre.");
			agregarMensaje("Droide: Humano salvador, ten estas mejoras y ayudame a derrotarlos.");
			agregarMensaje("PRESIONA F PARA DISPARAR UN RAYO.");
		}
        else if (numeroEscena == 17)
        {
			agregarMensaje("Doctor: Has regresado con la Semilla Restauradora.");
			agregarMensaje("Doctor: Gracias a ti, la vida en nuestro planeta tiene una segunda oportunidad.");
			agregarMensaje("Jugador: Fue una aventura dificil, pero valio la pena.");
			agregarMensaje("Doctor: Si pero aun no ha terminado, unos extraterrestres quieren invadirnos.");
			agregarMensaje("Doctor: Prepárate para defender nuestro mundo una vez mas.");
        }
        else if (numeroEscena == 18)
        {
			agregarMensaje("FELICIDADES VIAJERO!");
			agregarMensaje("ANTES DE TERMINAR TE INVITO A RESPONDER ESTA ULTIMA PREGUNTA.");
            agregarMensaje("RESPONDE:\n\nOPCIONES: [A] Si  [B] No");
        }
        else if (numeroEscena == 19) // Aliado mundo 2
        {
			agregarMensaje("Droide Exiliado: Hola humano, he estado observandote.");
			agregarMensaje("Droide Exiliado: Eres valiente por enfrentarte a los peligros de este mundo.");
			agregarMensaje("Droide Exiliado: Pero ten cuidado al pasar por ese portal, \nte encontraras con el DragonBot.");
			agregarMensaje("Droide Exiliado: Es un enemigo muy poderoso, asegúrate esquivar todas bolas de fuego.");
			agregarMensaje("Droide Exiliado: Gracias por el consejo, estaré atento.");
			agregarMensaje("Droide Exiliado: Este se cansara a los 20 segundos, suerte");
            
        }
        else if (numeroEscena == 20)//Respuesta a la pregunta del mapa final SI
        {
            agregarMensaje("EXCELENTE ELECCION.");
            agregarMensaje("HAS COMPRENDIDO QUE LA TECNOLOGIA Y LA HUMANIDAD \nPUEDEN POTENCIARSE MUTUAMENTE.");
            agregarMensaje("GRACIAS A TI, SE HA CREADO UN NUEVO EQUILIBRIO DONDE AMBOS COEXISTEN.");
            agregarMensaje("AHORA EL MUNDO AVANZARA HACIA UN FUTURO BRILLANTE.");
            agregarMensaje("ESPERO QUE HAYAS OBTENIDO EL PUNTAJE NECESARIO PARA ENTRAR EN EL RANKING.");
            agregarMensaje("¡GRACIAS POR JUGAR Y HASTA LA PROXIMA AVENTURA!");
        }
		else if (numeroEscena == 21)//Respuesta a la pregunta del mapa final NO
		{
            
            agregarMensaje("INTERESANTE PUNTO DE VISTA.");
            agregarMensaje("ES CIERTO, NADA PUEDE REEMPLAZAR EL ESPIRITU Y LA EMPATIA HUMANA.");
            agregarMensaje("LA IA SERA SOLO UNA HERRAMIENTA, PERO NOSOTROS SIEMPRE \nTENDREMOS EL CONTROL.");
            agregarMensaje("EL MUNDO SE HA SALVADO GRACIAS A TU DETERMINACION HUMANA.");
            agregarMensaje("ESPERO QUE HAYAS OBTENIDO EL SUFICIENTE PUNTAJE PARA ENTRAR EN EL RANKING.");
            agregarMensaje("¡GRACIAS POR JUGAR Y HASTA LA PROXIMA AVENTURA!");
            
		}


        
    }


    bool esUltimoMensaje() {
        return colaDialogos.size() == 0;
    }





};