#pragma once
#include "Controlador.h"
namespace Menu {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de InstrucForm
	/// </summary>
	public ref class InstrucForm : public System::Windows::Forms::Form
	{
	public:
		InstrucForm(void)
		{
			InitializeComponent();
			controlador = gcnew Controlador();
			g = this->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, this->ClientRectangle);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~InstrucForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		Controlador^ controlador;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(InstrucForm::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &InstrucForm::timer1_Tick);
			// 
			// InstrucForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(762, 578);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"InstrucForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"InstrucForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &InstrucForm::InstrucForm_FormClosing);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &InstrucForm::InstrucForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &InstrucForm::InstrucForm_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void InstrucForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		this->timer1->Stop();
	}
	private: System::Void InstrucForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		controlador->MovimientoJugador(true, e->KeyCode);
		if (e->KeyCode == Keys::Escape) {
			this->Close();
		}
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(Color::Transparent);
		controlador->mostrarIntruc(buffer);
		buffer->Render(g);
	}
	private: System::Void InstrucForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		controlador->ProcesarEntrada(e->KeyCode, false);
		controlador->MovimientoJugador(false, e->KeyCode);
	}
	};
}
