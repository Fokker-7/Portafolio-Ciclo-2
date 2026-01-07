#pragma once
#include "Controlador.h"
#include "Perdiste.h"

namespace Menu {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Mundo
	/// </summary>
	public ref class Mundo : public System::Windows::Forms::Form
	{
	private:
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
	private: System::Windows::Forms::Panel^ panelDialogo;
	private: System::Windows::Forms::Label^ lblDialogo;
		   Controlador^ controlador;
	public:
		Mundo(int mapaInicial, int skinjuga, System::String^ nombreJugador)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			controlador = gcnew Controlador();
			controlador->SetNumMapaAc(mapaInicial);
			controlador->setSkinJuga(skinjuga);
			g = panelJuego->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panelJuego->ClientRectangle);


			controlador->asignarNombre(nombreJugador);
		}

		void FinDelJuego(int puntaje) {
			controlador->GuardarPuntajeFinal(puntaje);
		}



	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Mundo()
		{
			if (buffer != nullptr) {
				delete buffer;
				buffer = nullptr;
			}
			this->Clock->Stop();

			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ Clock;
	private: System::Windows::Forms::Panel^ panelJuego;
	protected:

	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->Clock = (gcnew System::Windows::Forms::Timer(this->components));
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Mundo::Mundo_FormClosing);
			this->panelJuego = (gcnew System::Windows::Forms::Panel());
			this->panelDialogo = (gcnew System::Windows::Forms::Panel());
			this->lblDialogo = (gcnew System::Windows::Forms::Label());
			this->panelDialogo->SuspendLayout();
			this->SuspendLayout();
			// 
			// Clock
			// 
			this->Clock->Enabled = true;
			this->Clock->Tick += gcnew System::EventHandler(this, &Mundo::Clock_Tick);
			// 
			// panelJuego
			// 
			this->panelJuego->Location = System::Drawing::Point(40, 26);
			this->panelJuego->Name = L"panelJuego";
			this->panelJuego->Size = System::Drawing::Size(1023, 474);
			this->panelJuego->TabIndex = 0;
			// 
			// panelDialogo
			// 
			this->panelDialogo->BackColor = System::Drawing::SystemColors::ControlText;
			this->panelDialogo->Controls->Add(this->lblDialogo);
			this->panelDialogo->Location = System::Drawing::Point(51, 506);
			this->panelDialogo->Name = L"panelDialogo";
			this->panelDialogo->Size = System::Drawing::Size(1012, 113);
			this->panelDialogo->TabIndex = 1;
			// 
			// lblDialogo
			// 
			this->lblDialogo->AutoSize = true;
			this->lblDialogo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblDialogo->ForeColor = System::Drawing::SystemColors::Control;
			this->lblDialogo->Location = System::Drawing::Point(26, 25);
			this->lblDialogo->Name = L"lblDialogo";
			this->lblDialogo->Size = System::Drawing::Size(0, 24);
			this->lblDialogo->TabIndex = 0;
			// 
			// Mundo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1093, 627);
			this->Controls->Add(this->panelDialogo);
			this->Controls->Add(this->panelJuego);
			this->Name = L"Mundo";
			this->Text = L"Mundo";
			this->Load += gcnew System::EventHandler(this, &Mundo::Mundo_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Mundo::Mundo_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Mundo::Mundo_KeyUp);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Mundo::Mundo_MouseDown);
			this->panelDialogo->ResumeLayout(false);
			this->panelDialogo->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Clock_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(Color::Black);

		// === Lógica Central: Selector de Mundo ===
		if (controlador->getNumMapa() == 13) {
			controlador->EjecutarCinematicaCohete(buffer);
		}
		// Luego el resto de tus condiciones normales
		else if (controlador->getNumMapa() < 5) {
			controlador->EjecutarMundo1(buffer);
		}
		else if (controlador->getNumMapa() >= 5 && controlador->getNumMapa() < 8) {
			controlador->EjecutarMundo2(buffer);
		}
		else {
			controlador->ejecutarMundo3(buffer);
		}

		// =======================================}


		controlador->ActualizarVistaDialogo(lblDialogo, panelDialogo);
		buffer->Render(g);



		if (controlador->getVidasJuga() <= 0) {

			Perdiste^ per = gcnew Perdiste();
			this->Clock->Stop();

			this->Hide();
			per->ShowDialog();
			this->Close();
		}
	}
	private: System::Void Mundo_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

		controlador->ProcesarEntrada(e->KeyCode, true);
		if (e->KeyCode == Keys::Escape) {
			this->Close();
		}
	}

	private: System::Void Mundo_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		controlador->MovimientoJugador(false, e->KeyCode);
		controlador->ProcesarEntrada(e->KeyCode, false);
		controlador->ActualizarVistaDialogo(lblDialogo, panelDialogo);
	}
	private: System::Void Mundo_Load(System::Object^ sender, System::EventArgs^ e) {
	}
		   private: System::Void Mundo_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
			   this->Clock->Enabled = false;
			   this->Clock->Stop();

			   // Opcional: Liberar el buffer explícitamente si aún existe
			   if (buffer != nullptr) {
				   delete buffer;
				   buffer = nullptr;
			   }
		   }
	private: System::Void Mundo_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	

	}
};
}
