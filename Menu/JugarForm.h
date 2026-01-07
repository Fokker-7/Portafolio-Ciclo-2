#pragma once
#include "Mundo.h"
namespace Menu {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de JugarForm
	/// </summary>
	public ref class JugarForm : public System::Windows::Forms::Form
	{
	public:
		JugarForm(System::String^ nombre)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//

			this->nombreJugador = nombre;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~JugarForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnMundo1;
	private: System::Windows::Forms::Button^ btnMundo2;
	private: System::Windows::Forms::Button^ btnMundo3;
	protected:

	protected:



	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

		System::String^ nombreJugador;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(JugarForm::typeid));
			this->btnMundo1 = (gcnew System::Windows::Forms::Button());
			this->btnMundo2 = (gcnew System::Windows::Forms::Button());
			this->btnMundo3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnMundo1
			// 
			this->btnMundo1->BackColor = System::Drawing::Color::Transparent;
			this->btnMundo1->FlatAppearance->BorderSize = 0;
			this->btnMundo1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnMundo1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnMundo1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnMundo1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btnMundo1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnMundo1.Image")));
			this->btnMundo1->Location = System::Drawing::Point(19, 72);
			this->btnMundo1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnMundo1->Name = L"btnMundo1";
			this->btnMundo1->Size = System::Drawing::Size(220, 146);
			this->btnMundo1->TabIndex = 0;
			this->btnMundo1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->btnMundo1->UseVisualStyleBackColor = false;
			this->btnMundo1->Click += gcnew System::EventHandler(this, &JugarForm::btnMundo1_Click);
			// 
			// btnMundo2
			// 
			this->btnMundo2->BackColor = System::Drawing::Color::Transparent;
			this->btnMundo2->FlatAppearance->BorderSize = 0;
			this->btnMundo2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnMundo2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnMundo2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnMundo2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnMundo2.Image")));
			this->btnMundo2->Location = System::Drawing::Point(262, 256);
			this->btnMundo2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnMundo2->Name = L"btnMundo2";
			this->btnMundo2->Size = System::Drawing::Size(226, 132);
			this->btnMundo2->TabIndex = 1;
			this->btnMundo2->UseVisualStyleBackColor = false;
			this->btnMundo2->Click += gcnew System::EventHandler(this, &JugarForm::btnMundo2_Click);
			// 
			// btnMundo3
			// 
			this->btnMundo3->BackColor = System::Drawing::Color::Transparent;
			this->btnMundo3->FlatAppearance->BorderSize = 0;
			this->btnMundo3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnMundo3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnMundo3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnMundo3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnMundo3.Image")));
			this->btnMundo3->Location = System::Drawing::Point(478, 72);
			this->btnMundo3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnMundo3->Name = L"btnMundo3";
			this->btnMundo3->Size = System::Drawing::Size(226, 146);
			this->btnMundo3->TabIndex = 2;
			this->btnMundo3->UseVisualStyleBackColor = false;
			this->btnMundo3->Click += gcnew System::EventHandler(this, &JugarForm::button3_Click);
			// 
			// JugarForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(733, 413);
			this->Controls->Add(this->btnMundo3);
			this->Controls->Add(this->btnMundo2);
			this->Controls->Add(this->btnMundo1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->KeyPreview = true;
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"JugarForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"JugarForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &JugarForm::JugarForm_KeyDown);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &JugarForm::JugarForm_KeyPress);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		Mundo^ mundo3 = gcnew Mundo(8, 2, this->nombreJugador);
		mundo3->ShowDialog();
		this->Show();
	}
	private: System::Void JugarForm_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	}
private: System::Void JugarForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode==Keys::Escape) {
			this->Close();
		}
}
private: System::Void btnMundo1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	Mundo^ mundo1 = gcnew Mundo(1, 1, this->nombreJugador);
	mundo1->ShowDialog();
	this->Show();
}
private: System::Void btnMundo2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	Mundo^ mundo2 = gcnew Mundo(5, 2, this->nombreJugador);
	mundo2->ShowDialog();
	this->Show();
}
};
}
