#pragma once
#include"GestorArchivos.h"
#include"Dependencias.h"

namespace Menu {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormRanking
	/// </summary>
	public ref class FormRanking : public System::Windows::Forms::Form
	{
	public:
		FormRanking(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			
			Archivos = new GestorArchivos();
			fondoRanking = gcnew Bitmap("imagenes/arcade.png");
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FormRanking()
		{
			if (components)
			{
				delete components;
				if (Archivos) delete Archivos;
			}
		}

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Panel^ panel1;

		GestorArchivos* Archivos;
		Bitmap^ fondoRanking;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormRanking::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(567, 595);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FormRanking::panel1_Paint);
			// 
			// FormRanking
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(591, 619);
			this->ControlBox = false;
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"FormRanking";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"RANKING";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FormRanking::FormRanking_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {


		BufferedGraphicsContext^ espacioGrafico = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacioGrafico->Allocate(e->Graphics, panel1->ClientRectangle);

		int ancho = buffer->Graphics->VisibleClipBounds.Width;
		int alto = buffer->Graphics->VisibleClipBounds.Height;

		buffer->Graphics->DrawImage(fondoRanking, 0, 0, ancho, alto);



		int y_titulo = 170;

		buffer->Graphics->DrawString("MEJORES PUNTAJES",
			gcnew System::Drawing::Font("Ravie", 18, System::Drawing::FontStyle::Bold),
			System::Drawing::Brushes::Gold, 110, y_titulo);



		int y_ranking_inicio = y_titulo + 70;
		int y = y_ranking_inicio;


		vector<Registro> records = Archivos->ObtenerRecords();

		System::Drawing::Font^ fuente = gcnew System::Drawing::Font("Ravie", 14);

		for (int i = 0; i < records.size(); i++) {
			// CAMBIO: Quitamos .c_str()
			// Como 'nombre' ahora es char[50], se pasa directo al constructor de String^
			String^ nombre = gcnew String(records[i].nombre);

			String^ linea = (i + 1) + ". " + nombre + " - " + records[i].puntaje;

			buffer->Graphics->DrawString(linea, fuente, System::Drawing::Brushes::Aquamarine, 130, y);
			y += 40;
		} 

		buffer->Render(e->Graphics);
		delete buffer;

	}
	private: System::Void FormRanking_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

		if (e->KeyCode == Keys::Escape) {
			this->Close();
		}
	}
};
}
