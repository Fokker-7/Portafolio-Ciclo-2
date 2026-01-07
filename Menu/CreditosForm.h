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
	/// Resumen de CreditosForm
	/// </summary>
	public ref class CreditosForm : public System::Windows::Forms::Form
	{
	public:
		CreditosForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			controlador = gcnew Controlador();
			g = this->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, this->ClientRectangle);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~CreditosForm()
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
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &CreditosForm::timer1_Tick);
			// 
			// CreditosForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(841, 463);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"CreditosForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"CreditosForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &CreditosForm::CreditosForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &CreditosForm::CreditosForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &CreditosForm::CreditosForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(Color::Transparent);
		controlador->mostrarCredi(buffer);
		buffer->Render(g);
	}
	private: System::Void CreditosForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		this->timer1->Stop();

	}
	private: System::Void CreditosForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Escape) {
			this->Close();
		}
	}
	private: System::Void CreditosForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	};
}