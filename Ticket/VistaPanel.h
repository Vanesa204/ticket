#pragma once
#include "Usuario.h"
#include "Ticket1.h"
#include "Listado.h"
#include "Carga.h"

namespace Ticket {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de VistaPanel
	/// </summary>
	public ref class VistaPanel : public System::Windows::Forms::Form
	{
	private: String^ rol;

	public:
		VistaPanel(String^ rol)
		{
			this->rol = rol;
			InitializeComponent();
			AjustarVisibilidadBotones(rol);
		}

	protected:
		~VistaPanel()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::Button^ button2;
		System::Windows::Forms::Button^ button3;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(40, 44);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Cargar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &VistaPanel::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(40, 93);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Tickets";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &VistaPanel::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(40, 144);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Usuarios";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &VistaPanel::button3_Click);
			// 
			// VistaPanel
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"VistaPanel";
			this->Text = L"VistaPanel";
			this->ResumeLayout(false);

		}
#pragma endregion

	public:
		void AjustarVisibilidadBotones(String^ rol) {
			if (rol == "1") {
				this->button1->Visible = true;
				this->button2->Visible = true;
				this->button3->Visible = true;
			}
			else if (rol == "2") {
				this->button1->Visible = true;
				this->button2->Visible = true;
				this->button3->Visible = false;
			}
			else if (rol == "3") {
				this->button1->Visible = true;
				this->button2->Visible = false;
				this->button3->Visible = true;
			}
		}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		Ticket::Usuario^ vistaUsuario = gcnew Ticket::Usuario();
		vistaUsuario->Show();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		
			//Ticket::Ticket1^ vistaListado = gcnew Ticket::Ticket1(rol);
		Ticket::Listado^ vistaListado = gcnew  Ticket::Listado();
			vistaListado->Show();
		
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Ticket::Carga^ vistaCarga = gcnew Ticket::Carga();
		vistaCarga->Show();

	}
};
}