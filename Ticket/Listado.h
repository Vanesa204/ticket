#pragma once
#include "DataAccess.h"

namespace Ticket {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Listado
	/// </summary>
	public ref class Listado : public System::Windows::Forms::Form
	{
	public:
		Listado(void)
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
		~Listado()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ tableListado;
	private: System::Windows::Forms::Button^ buttonConfirmar;
	private: System::Windows::Forms::Button^ buttonReabrir;
	protected:


	private: System::Windows::Forms::Button^ buttonAtender;
	private: System::Windows::Forms::Button^ buttonResuelto;




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
			this->tableListado = (gcnew System::Windows::Forms::DataGridView());
			this->buttonConfirmar = (gcnew System::Windows::Forms::Button());
			this->buttonReabrir = (gcnew System::Windows::Forms::Button());
			this->buttonAtender = (gcnew System::Windows::Forms::Button());
			this->buttonResuelto = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tableListado))->BeginInit();
			this->SuspendLayout();
			// 
			// tableListado
			// 
			this->tableListado->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tableListado->Location = System::Drawing::Point(25, 48);
			this->tableListado->MultiSelect = false;
			this->tableListado->Name = L"tableListado";
			this->tableListado->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->tableListado->Size = System::Drawing::Size(662, 150);
			this->tableListado->TabIndex = 0;
			// 
			// buttonConfirmar
			// 
			this->buttonConfirmar->Location = System::Drawing::Point(25, 220);
			this->buttonConfirmar->Name = L"buttonConfirmar";
			this->buttonConfirmar->Size = System::Drawing::Size(75, 23);
			this->buttonConfirmar->TabIndex = 1;
			this->buttonConfirmar->Text = L"Confirmar";
			this->buttonConfirmar->UseVisualStyleBackColor = true;
			this->buttonConfirmar->Click += gcnew System::EventHandler(this, &Listado::buttonConfirmar_Click);
			// 
			// buttonReabrir
			// 
			this->buttonReabrir->Location = System::Drawing::Point(25, 264);
			this->buttonReabrir->Name = L"buttonReabrir";
			this->buttonReabrir->Size = System::Drawing::Size(75, 23);
			this->buttonReabrir->TabIndex = 2;
			this->buttonReabrir->Text = L"Reabrir";
			this->buttonReabrir->UseVisualStyleBackColor = true;
			this->buttonReabrir->Click += gcnew System::EventHandler(this, &Listado::buttonReabrir_Click);
			// 
			// buttonAtender
			// 
			this->buttonAtender->Location = System::Drawing::Point(612, 220);
			this->buttonAtender->Name = L"buttonAtender";
			this->buttonAtender->Size = System::Drawing::Size(75, 23);
			this->buttonAtender->TabIndex = 3;
			this->buttonAtender->Text = L"Atender";
			this->buttonAtender->UseVisualStyleBackColor = true;
			this->buttonAtender->Click += gcnew System::EventHandler(this, &Listado::buttonAtender_Click);
			// 
			// buttonResuelto
			// 
			this->buttonResuelto->Location = System::Drawing::Point(612, 264);
			this->buttonResuelto->Name = L"buttonResuelto";
			this->buttonResuelto->Size = System::Drawing::Size(75, 23);
			this->buttonResuelto->TabIndex = 4;
			this->buttonResuelto->Text = L"Resuelto";
			this->buttonResuelto->UseVisualStyleBackColor = true;
			this->buttonResuelto->Click += gcnew System::EventHandler(this, &Listado::buttonResuelto_Click);
			// 
			// Listado
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(739, 314);
			this->Controls->Add(this->buttonResuelto);
			this->Controls->Add(this->buttonAtender);
			this->Controls->Add(this->buttonReabrir);
			this->Controls->Add(this->buttonConfirmar);
			this->Controls->Add(this->tableListado);
			this->Name = L"Listado";
			this->Text = L"Listado";
			this->Load += gcnew System::EventHandler(this, &Listado::Listado_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tableListado))->EndInit();
			this->ResumeLayout(false);

		}

#pragma endregion
	private: System::Void Listado_Load(System::Object^ sender, System::EventArgs^ e) {
		LoadDataTListado();
	}


		   void LoadDataTListado()
		   {
			   DataAccess::UserDao^ userDao = gcnew DataAccess::UserDao();
			   DataTable^ dataTable = userDao->GetAllTickets(); // Llama al método para obtener el DataTable
			   tableListado->DataSource = dataTable; // Asigna el DataTable al DataGridView
		   }

private: System::Void buttonAtender_Click(System::Object^ sender, System::EventArgs^ e) {
	DataAccess::UserDao^ userDao = gcnew DataAccess::UserDao();
	// Verifica si hay alguna fila seleccionada
	if (this->tableListado->SelectedRows->Count > 0)

	{
		// Obtener el N_Ticket de la fila seleccionada
		int selectedTicketId = Convert::ToInt32(this->tableListado->SelectedRows[0]->Cells["N_Ticket"]->Value);
		// Verificar el número de tickets atendidos
		
		bool resultado = userDao->CanAtenderTicket();

		if ((resultado))

		{
			int tecnicoId = DataAccess::UserDao::currentUser;
			// Actualizar el estado del ticket a "Atendido"

			bool updateAtendido = userDao->UpdateTicketStatus(selectedTicketId, "Atendido", tecnicoId);

			if (updateAtendido)
			{
				MessageBox::Show("Ticket atendido correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
				LoadDataTListado();
			}
			else
			{
				MessageBox::Show("No se pudo actualizar el estado del ticket.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}

			//MessageBox::Show("Ticket atendido correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else
		{
			MessageBox::Show("No se pueden atender más de 3 tickets.", "Límite alcanzado", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
	else
	{
		MessageBox::Show("Por favor, selecciona un ticket para atender.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

}
private: System::Void buttonResuelto_Click(System::Object^ sender, System::EventArgs^ e) {
	    DataAccess::UserDao^ userDao = gcnew DataAccess::UserDao();

	     if (this->tableListado->SelectedRows->Count > 0)
		 {
		    int selectedRowIndex = this->tableListado->SelectedRows[0]->Index;

	        int nTicket = Convert::ToInt32(this->tableListado->Rows[selectedRowIndex]->Cells["N_Ticket"]->Value);
			String^ estadoTicket = this->tableListado->Rows[selectedRowIndex]->Cells["estado"]->Value->ToString();

			if (estadoTicket == "Atendido")
			{
				int tecnicoId = DataAccess::UserDao::currentUser; 
				// Actualizar el estado del ticket a "Finalizado"
				bool updateResuelto = userDao->UpdateTicketStatus(nTicket, "Resuelto", tecnicoId);

				if (updateResuelto)
				{
					MessageBox::Show("Ticket marcado como Resuelto correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);

					// Recarga los datos del DataGridView para reflejar los cambios
					LoadDataTListado();  // Recarga la tabla de tickets
				}
		
				else
				{
					MessageBox::Show("No se pudo actualizar el estado del ticket.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
			else
			{
				// Si el ticket no está en estado "Atendido", muestra un mensaje de error
				MessageBox::Show("El ticket debe estar en estado 'Atendido' para marcarlo como 'Resuelto'.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		 }
		 else
		 {
			 MessageBox::Show("Por favor, selecciona un ticket para marcar como Resuelto.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		 }
}

	private: System::Void buttonConfirmar_Click(System::Object^ sender, System::EventArgs^ e) {
		DataAccess::UserDao^ userDao = gcnew DataAccess::UserDao();
		// Verificar si se ha seleccionado un ticket
		if (this->tableListado->SelectedRows->Count > 0)
		{
			int selectedTicketId = Convert::ToInt32(this->tableListado->SelectedRows[0]->Cells["N_Ticket"]->Value);
			int trabajadorId = DataAccess::UserDao::currentUser;

			bool resultado = userDao->UpdateTicketStatus(selectedTicketId, "Finalizado", trabajadorId);

			if (resultado)
			{

				MessageBox::Show("Ticket finalizado correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
				// Actualizar el DataGridView después de finalizar
				LoadDataTListado();
			}
			else
			{
				MessageBox::Show("Error al finalizar el ticket. Asegúrate de que esté en estado 'Resuelto'.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		else
		{
			MessageBox::Show("Por favor, selecciona un ticket para confirmar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
private: System::Void buttonReabrir_Click(System::Object^ sender, System::EventArgs^ e) {

	DataAccess::UserDao^ userDao = gcnew DataAccess::UserDao();
	// Verificar si hay alguna fila seleccionada
	if (this->tableListado->SelectedRows->Count > 0)
	{
		// Obtener el N_Ticket de la fila seleccionada
		int selectedTicketId = Convert::ToInt32(this->tableListado->SelectedRows[0]->Cells["N_Ticket"]->Value);
		String^ estadoActual = this->tableListado->SelectedRows[0]->Cells["estado"]->Value->ToString();

		// Verificar si el estado actual es "Resuelto"
		if (estadoActual == "Resuelto")
		{
			int tecnicoId = Convert::ToInt32(this->tableListado->SelectedRows[0]->Cells["tecnico_id"]->Value);

			// Llamar a la función para reabrir el ticket y registrar la falla al técnico
			bool reabrirTicket = userDao->ReabrirTicket(selectedTicketId, tecnicoId);

			if (reabrirTicket)
			{
				MessageBox::Show("Ticket reabierto correctamente. Otro técnico puede tomarlo.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
				LoadDataTListado();  // Recargar los datos de la tabla para mostrar el cambio
			}
			else
			{
				MessageBox::Show("Error al reabrir el ticket.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		else
		{
			MessageBox::Show("Solo los tickets en estado 'Resuelto' pueden ser reabiertos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else
	{
		MessageBox::Show("Por favor, selecciona un ticket para reabrir.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

        
}
};
}
