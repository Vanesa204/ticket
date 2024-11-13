#pragma once
#include "DataAccess.h"
#include "Usuario.h"


namespace Ticket {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Carga
	/// </summary>
	public ref class Carga : public System::Windows::Forms::Form
	{
	public:
		Carga(void)
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
		~Carga()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;

	private: System::Windows::Forms::TextBox^ textTitulo;
	private: System::Windows::Forms::TextBox^ textDetalle;





	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ buttonCargarTicket;
	private: System::Windows::Forms::Button^ buttonModTicket;
	private: System::Windows::Forms::Button^ buttonEliminarTicket;
	private: System::Windows::Forms::Label^ labNTicket;
	private: System::Windows::Forms::Label^ labIdTrabajador;









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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textTitulo = (gcnew System::Windows::Forms::TextBox());
			this->textDetalle = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->buttonCargarTicket = (gcnew System::Windows::Forms::Button());
			this->buttonModTicket = (gcnew System::Windows::Forms::Button());
			this->buttonEliminarTicket = (gcnew System::Windows::Forms::Button());
			this->labNTicket = (gcnew System::Windows::Forms::Label());
			this->labIdTrabajador = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(25, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(67, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Nº de Ticket";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(25, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Título";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(25, 87);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(40, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Detalle";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(25, 139);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(70, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Id Trabajador";
			// 
			// textTitulo
			// 
			this->textTitulo->Location = System::Drawing::Point(120, 50);
			this->textTitulo->Name = L"textTitulo";
			this->textTitulo->Size = System::Drawing::Size(100, 20);
			this->textTitulo->TabIndex = 5;
			// 
			// textDetalle
			// 
			this->textDetalle->Location = System::Drawing::Point(120, 87);
			this->textDetalle->Multiline = true;
			this->textDetalle->Name = L"textDetalle";
			this->textDetalle->Size = System::Drawing::Size(244, 49);
			this->textDetalle->TabIndex = 6;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(28, 165);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(545, 150);
			this->dataGridView1->TabIndex = 8;
			// 
			// buttonCargarTicket
			// 
			this->buttonCargarTicket->Location = System::Drawing::Point(418, 26);
			this->buttonCargarTicket->Name = L"buttonCargarTicket";
			this->buttonCargarTicket->Size = System::Drawing::Size(75, 23);
			this->buttonCargarTicket->TabIndex = 9;
			this->buttonCargarTicket->Text = L"Cargar ";
			this->buttonCargarTicket->UseVisualStyleBackColor = true;
			this->buttonCargarTicket->Click += gcnew System::EventHandler(this, &Carga::button1_Click);
			// 
			// buttonModTicket
			// 
			this->buttonModTicket->Location = System::Drawing::Point(418, 57);
			this->buttonModTicket->Name = L"buttonModTicket";
			this->buttonModTicket->Size = System::Drawing::Size(75, 23);
			this->buttonModTicket->TabIndex = 10;
			this->buttonModTicket->Text = L"Modificar";
			this->buttonModTicket->UseVisualStyleBackColor = true;
			// 
			// buttonEliminarTicket
			// 
			this->buttonEliminarTicket->Location = System::Drawing::Point(418, 87);
			this->buttonEliminarTicket->Name = L"buttonEliminarTicket";
			this->buttonEliminarTicket->Size = System::Drawing::Size(75, 23);
			this->buttonEliminarTicket->TabIndex = 11;
			this->buttonEliminarTicket->Text = L"Eliminar";
			this->buttonEliminarTicket->UseVisualStyleBackColor = true;
			// 
			// labNTicket
			// 
			this->labNTicket->AutoSize = true;
			this->labNTicket->Location = System::Drawing::Point(129, 29);
			this->labNTicket->Name = L"labNTicket";
			this->labNTicket->Size = System::Drawing::Size(0, 13);
			this->labNTicket->TabIndex = 12;
			// 
			// labIdTrabajador
			// 
			this->labIdTrabajador->AutoSize = true;
			this->labIdTrabajador->Location = System::Drawing::Point(129, 139);
			this->labIdTrabajador->Name = L"labIdTrabajador";
			this->labIdTrabajador->Size = System::Drawing::Size(0, 13);
			this->labIdTrabajador->TabIndex = 13;
			// 
			// Carga
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(612, 321);
			this->Controls->Add(this->labIdTrabajador);
			this->Controls->Add(this->labNTicket);
			this->Controls->Add(this->buttonEliminarTicket);
			this->Controls->Add(this->buttonModTicket);
			this->Controls->Add(this->buttonCargarTicket);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->textDetalle);
			this->Controls->Add(this->textTitulo);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Carga";
			this->Text = L"Carga";
			this->Load += gcnew System::EventHandler(this, &Carga::Carga_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void Carga_Load(System::Object^ sender, System::EventArgs^ e) {
			this->labIdTrabajador->Text = "" + DataAccess::UserDao::currentUser;
		}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		DataAccess::UserDao^ userDao = gcnew DataAccess::UserDao();

		
		String^ titulo = this->textTitulo->Text;
		String^ detalle = this->textDetalle->Text;
		int dniTrabajador = DataAccess::UserDao::currentUser;
		int N_Ticket = 0; // Variable la creo  para almacenar el N_Ticket generado

		bool resultado = userDao->carga_ticket(titulo, detalle, dniTrabajador, N_Ticket);

		if (resultado)
		{
			this->labNTicket->Text = " " + N_Ticket;

			// Actualiza el label con el N_Ticket generado
			MessageBox::Show("Ticket insertado exitosamente. Número de Ticket: " + N_Ticket);
		
	    }
		else
		{
			MessageBox::Show("Error al guardar el Ticket.");
         }
	}

};
}
