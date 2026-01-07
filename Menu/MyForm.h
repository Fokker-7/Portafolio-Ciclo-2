#pragma once
#include "InstrucForm.h"
#include "NameForm.h"
#include"FormRanking.h"
#include "CreditosForm.h"
namespace Menu {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnJugar;
	private: System::Windows::Forms::Button^ btnSalir;
	private: System::Windows::Forms::Button^ btnCreditos;
	private: System::Windows::Forms::Button^ btnInstrucciones;
	private: System::Windows::Forms::Button^ btnRanking;
	private: System::Windows::Forms::PictureBox^ pictureBox1;


	protected:


	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->btnJugar = (gcnew System::Windows::Forms::Button());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->btnCreditos = (gcnew System::Windows::Forms::Button());
			this->btnInstrucciones = (gcnew System::Windows::Forms::Button());
			this->btnRanking = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// btnJugar
			// 
			this->btnJugar->BackColor = System::Drawing::Color::Transparent;
			this->btnJugar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnJugar.Image")));
			this->btnJugar->Location = System::Drawing::Point(140, 276);
			this->btnJugar->Margin = System::Windows::Forms::Padding(2);
			this->btnJugar->Name = L"btnJugar";
			this->btnJugar->Size = System::Drawing::Size(158, 72);
			this->btnJugar->TabIndex = 0;
			this->btnJugar->UseVisualStyleBackColor = false;
			this->btnJugar->Click += gcnew System::EventHandler(this, &MyForm::btnJugar_Click);
			// 
			// btnSalir
			// 
			this->btnSalir->BackColor = System::Drawing::Color::Transparent;
			this->btnSalir->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSalir.Image")));
			this->btnSalir->Location = System::Drawing::Point(461, 370);
			this->btnSalir->Margin = System::Windows::Forms::Padding(2);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(171, 70);
			this->btnSalir->TabIndex = 1;
			this->btnSalir->UseVisualStyleBackColor = false;
			this->btnSalir->Click += gcnew System::EventHandler(this, &MyForm::btnSalir_Click);
			// 
			// btnCreditos
			// 
			this->btnCreditos->BackColor = System::Drawing::Color::Transparent;
			this->btnCreditos->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCreditos.Image")));
			this->btnCreditos->Location = System::Drawing::Point(227, 368);
			this->btnCreditos->Margin = System::Windows::Forms::Padding(2);
			this->btnCreditos->Name = L"btnCreditos";
			this->btnCreditos->Size = System::Drawing::Size(171, 72);
			this->btnCreditos->TabIndex = 2;
			this->btnCreditos->UseVisualStyleBackColor = false;
			this->btnCreditos->Click += gcnew System::EventHandler(this, &MyForm::btnCreditos_Click);
			// 
			// btnInstrucciones
			// 
			this->btnInstrucciones->BackColor = System::Drawing::Color::Transparent;
			this->btnInstrucciones->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnInstrucciones.Image")));
			this->btnInstrucciones->Location = System::Drawing::Point(332, 277);
			this->btnInstrucciones->Margin = System::Windows::Forms::Padding(2);
			this->btnInstrucciones->Name = L"btnInstrucciones";
			this->btnInstrucciones->Size = System::Drawing::Size(171, 70);
			this->btnInstrucciones->TabIndex = 3;
			this->btnInstrucciones->UseVisualStyleBackColor = false;
			this->btnInstrucciones->Click += gcnew System::EventHandler(this, &MyForm::btnInstrucciones_Click);
			// 
			// btnRanking
			// 
			this->btnRanking->BackColor = System::Drawing::Color::Transparent;
			this->btnRanking->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnRanking.Image")));
			this->btnRanking->Location = System::Drawing::Point(534, 277);
			this->btnRanking->Margin = System::Windows::Forms::Padding(2);
			this->btnRanking->Name = L"btnRanking";
			this->btnRanking->Size = System::Drawing::Size(158, 70);
			this->btnRanking->TabIndex = 4;
			this->btnRanking->UseVisualStyleBackColor = false;
			this->btnRanking->Click += gcnew System::EventHandler(this, &MyForm::btnRanking_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(53, 89);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(725, 142);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(847, 482);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btnRanking);
			this->Controls->Add(this->btnInstrucciones);
			this->Controls->Add(this->btnCreditos);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->btnJugar);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"LostWorld";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnCreditos_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		CreditosForm^ credi = gcnew CreditosForm();
		credi->ShowDialog();
		this->Show();

	}
private: System::Void btnJugar_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	NameForm^ jugar = gcnew NameForm();
	jugar->ShowDialog();
	this->Show();
}
private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
}
private: System::Void btnInstrucciones_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	InstrucForm^ instruc = gcnew InstrucForm();
	instruc->ShowDialog();
	this->Show();
}
private: System::Void btnRanking_Click(System::Object^ sender, System::EventArgs^ e) {
	
	this->Hide();
	FormRanking^ ranking = gcnew FormRanking();
	ranking->ShowDialog();
	this->Show();

}
};
}
