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
	/// Resumen de Usuario
	/// </summary>
	public ref class Usuario : public System::Windows::Forms::Form
	{
	public:
		Usuario(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//

			this->texDni->TextChanged += gcnew EventHandler(this, &Usuario::texDni_TextChanged);//para que se autocimplete la contraseña
			this->checkedRol->Items->AddRange(gcnew array<System::Object^> {
				"Administrador", "Empleado", "Técnico"
			});
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Usuario()
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
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ texDni;

	private: System::Windows::Forms::TextBox^ texNombre;
	private: System::Windows::Forms::TextBox^ texApellido;
	private: System::Windows::Forms::TextBox^ texContrasenia;
	private: System::Windows::Forms::Button^ butAgregarUsuario;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ rolId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column7;

	private: System::Windows::Forms::Button^ butModificarUsuario;

		   // Método manejador de eventos para el cambio de texto en texDni 
		   
	private: System::Void texDni_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		// // Completa el campo de contraseña con el valor del DNI 

		this->texContrasenia->Text = this->texDni->Text;
	}

	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;








	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ butEliminarUsuario;

	private: System::Windows::Forms::CheckedListBox^ checkedRol;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ texFallas;

	private: System::Windows::Forms::RadioButton^ radioButSi;
	private: System::Windows::Forms::RadioButton^ radioButNo;
	private: System::Windows::Forms::DataGridView^ tablaUsuarios;











	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

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
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->texDni = (gcnew System::Windows::Forms::TextBox());
			this->texNombre = (gcnew System::Windows::Forms::TextBox());
			this->texApellido = (gcnew System::Windows::Forms::TextBox());
			this->texContrasenia = (gcnew System::Windows::Forms::TextBox());
			this->butAgregarUsuario = (gcnew System::Windows::Forms::Button());
			this->butModificarUsuario = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->butEliminarUsuario = (gcnew System::Windows::Forms::Button());
			this->checkedRol = (gcnew System::Windows::Forms::CheckedListBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->texFallas = (gcnew System::Windows::Forms::TextBox());
			this->radioButSi = (gcnew System::Windows::Forms::RadioButton());
			this->radioButNo = (gcnew System::Windows::Forms::RadioButton());
			this->tablaUsuarios = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->rolId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tablaUsuarios))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(25, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(83, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Id Usuario (DNI)";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(25, 54);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Nombre";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(25, 91);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(44, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Apellido";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(543, 47);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(23, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Rol";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(25, 147);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(54, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Habilitado";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(25, 193);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(61, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Contraseña";
			// 
			// texDni
			// 
			this->texDni->Location = System::Drawing::Point(151, 22);
			this->texDni->Name = L"texDni";
			this->texDni->Size = System::Drawing::Size(100, 20);
			this->texDni->TabIndex = 6;
			// 
			// texNombre
			// 
			this->texNombre->Location = System::Drawing::Point(151, 54);
			this->texNombre->Name = L"texNombre";
			this->texNombre->Size = System::Drawing::Size(100, 20);
			this->texNombre->TabIndex = 7;
			// 
			// texApellido
			// 
			this->texApellido->Location = System::Drawing::Point(151, 91);
			this->texApellido->Name = L"texApellido";
			this->texApellido->Size = System::Drawing::Size(100, 20);
			this->texApellido->TabIndex = 8;
			// 
			// texContrasenia
			// 
			this->texContrasenia->Location = System::Drawing::Point(151, 193);
			this->texContrasenia->Name = L"texContrasenia";
			this->texContrasenia->Size = System::Drawing::Size(100, 20);
			this->texContrasenia->TabIndex = 11;
			// 
			// butAgregarUsuario
			// 
			this->butAgregarUsuario->Location = System::Drawing::Point(339, 34);
			this->butAgregarUsuario->Name = L"butAgregarUsuario";
			this->butAgregarUsuario->Size = System::Drawing::Size(75, 23);
			this->butAgregarUsuario->TabIndex = 12;
			this->butAgregarUsuario->Text = L"Agregar";
			this->butAgregarUsuario->UseVisualStyleBackColor = true;
			this->butAgregarUsuario->Click += gcnew System::EventHandler(this, &Usuario::butAgregarUsuario_Click);
			// 
			// butModificarUsuario
			// 
			this->butModificarUsuario->Location = System::Drawing::Point(339, 63);
			this->butModificarUsuario->Name = L"butModificarUsuario";
			this->butModificarUsuario->Size = System::Drawing::Size(75, 23);
			this->butModificarUsuario->TabIndex = 13;
			this->butModificarUsuario->Text = L"Modificar";
			this->butModificarUsuario->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(270, 193);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(101, 23);
			this->button4->TabIndex = 15;
			this->button4->Text = L"Blanquear clave";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// butEliminarUsuario
			// 
			this->butEliminarUsuario->Location = System::Drawing::Point(339, 92);
			this->butEliminarUsuario->Name = L"butEliminarUsuario";
			this->butEliminarUsuario->Size = System::Drawing::Size(75, 23);
			this->butEliminarUsuario->TabIndex = 16;
			this->butEliminarUsuario->Text = L"Eliminar";
			this->butEliminarUsuario->UseVisualStyleBackColor = true;
			// 
			// checkedRol
			// 
			this->checkedRol->FormattingEnabled = true;
			this->checkedRol->Location = System::Drawing::Point(652, 47);
			this->checkedRol->Name = L"checkedRol";
			this->checkedRol->Size = System::Drawing::Size(100, 64);
			this->checkedRol->TabIndex = 17;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(285, 125);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(34, 13);
			this->label7->TabIndex = 18;
			this->label7->Text = L"Fallas";
			// 
			// texFallas
			// 
			this->texFallas->Location = System::Drawing::Point(339, 125);
			this->texFallas->Name = L"texFallas";
			this->texFallas->Size = System::Drawing::Size(32, 20);
			this->texFallas->TabIndex = 19;
			// 
			// radioButSi
			// 
			this->radioButSi->AutoSize = true;
			this->radioButSi->Location = System::Drawing::Point(151, 143);
			this->radioButSi->Name = L"radioButSi";
			this->radioButSi->Size = System::Drawing::Size(34, 17);
			this->radioButSi->TabIndex = 20;
			this->radioButSi->TabStop = true;
			this->radioButSi->Text = L"Si";
			this->radioButSi->UseVisualStyleBackColor = true;
			// 
			// radioButNo
			// 
			this->radioButNo->AutoSize = true;
			this->radioButNo->Location = System::Drawing::Point(212, 145);
			this->radioButNo->Name = L"radioButNo";
			this->radioButNo->Size = System::Drawing::Size(39, 17);
			this->radioButNo->TabIndex = 21;
			this->radioButNo->TabStop = true;
			this->radioButNo->Text = L"No";
			this->radioButNo->UseVisualStyleBackColor = true;
			// 
			// tablaUsuarios
			// 
			this->tablaUsuarios->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tablaUsuarios->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->Column1,
					this->rolId, this->Column2, this->Column3, this->Column4, this->Column5, this->Column6, this->Column7
			});
			this->tablaUsuarios->Location = System::Drawing::Point(28, 250);
			this->tablaUsuarios->Name = L"tablaUsuarios";
			this->tablaUsuarios->Size = System::Drawing::Size(743, 150);
			this->tablaUsuarios->TabIndex = 22;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Usuario";
			this->Column1->Name = L"Column1";
			// 
			// rolId
			// 
			this->rolId->HeaderText = L"rolId";
			this->rolId->Name = L"rolId";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Nombre";
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Apellido";
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Rol";
			this->Column4->Name = L"Column4";
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Habilitado";
			this->Column5->Name = L"Column5";
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Contraseña";
			this->Column6->Name = L"Column6";
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Fallas";
			this->Column7->Name = L"Column7";
			// 
			// Usuario
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(874, 430);
			this->Controls->Add(this->tablaUsuarios);
			this->Controls->Add(this->radioButNo);
			this->Controls->Add(this->radioButSi);
			this->Controls->Add(this->texFallas);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->checkedRol);
			this->Controls->Add(this->butEliminarUsuario);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->butModificarUsuario);
			this->Controls->Add(this->butAgregarUsuario);
			this->Controls->Add(this->texContrasenia);
			this->Controls->Add(this->texApellido);
			this->Controls->Add(this->texNombre);
			this->Controls->Add(this->texDni);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Usuario";
			this->Text = L"Usuario";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tablaUsuarios))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void butAgregarUsuario_Click(System::Object^ sender, System::EventArgs^ e) {
		
		DataAccess::UserDao^ userDao = gcnew DataAccess::UserDao();
		int dni = Int32::Parse(this->texDni->Text);
		String^ nombre = this->texNombre->Text;
		String^ apellido = this->texApellido->Text;
		
		int fallas = 0; // this->texFallas->Text;
		
		this->texFallas->Text = fallas.ToString();
		
		// para obtener el rol que se selecciona del CheckedListBox

		/*String^ rol = this->checkedRol->CheckedItems->Count > 0 ? this->checkedRol->CheckedItems[0]->ToString() : "";*/
		int idRol = this->checkedRol->CheckedItems->Count > 0 ? this->checkedRol->SelectedIndex:-1;

		//obtener el estado habilitado

		bool habilitado = this->radioButSi->Checked;
		/*bool habilitado = this->radioButSi->Checked ? "Sí" : "No";
		if (this->radioButSi->Checked) {

			MessageBox::Show("Seleccionaste Sí");
		}
		else if (this->radioButNo->Checked) {

			MessageBox::Show("Seleccionaste No");
		}
		else {

			MessageBox::Show("No seleccionaste ninguna opción, por favor selecciona una opcíon");
		}*/

		//confi del checkedListBox//

		

		int password = Int32::Parse(this->texDni->Text);// this->texContrasenia->Text;
		this->texContrasenia->Text = password.ToString();
		

		// Llamar al método IngresarUsuario
	
		 bool resultado = userDao->IngresarUsuario(dni, nombre, apellido,  habilitado, fallas, password, idRol);
		
		// Verificar la selección del RadioButton
	
		if (resultado) { 
			MessageBox::Show("Usuario agregado correctamente");
		}
		else { 
			MessageBox::Show("Error al agregar el usuario"); 
		}

	};
	};

}
