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
	/// Resumen de Usuario
	/// </summary>
	public ref class Usuario : public System::Windows::Forms::Form
	{

	private: DataTable^ dataTable;
	public:
		Usuario(void)
		{
			InitializeComponent();
			
			//
			//TODO: agregar código de constructor aquí
			//

			this->texDni->TextChanged += gcnew EventHandler(this, &Usuario::texDni_TextChanged);//para que se autocimplete la contraseña
			/*this->checkedRol->Items->AddRange(gcnew array<System::Object^> {
				"Administrador", "Empleado", "Técnico"
			});*/
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
	private:DataAccess::UserDao^ userDao;
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
	private: System::Windows::Forms::RadioButton^ radioButHabSi;
	private: System::Windows::Forms::RadioButton^ radioButAdm;
	private: System::Windows::Forms::RadioButton^ radioButTrab;
	private: System::Windows::Forms::RadioButton^ radioButTec;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;












	private: System::Windows::Forms::Button^ butModificarUsuario;

		   // Método manejador de eventos para el cambio de texto en texDni 
		   
	private: System::Void texDni_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		// // Completa el campo de contraseña con el valor del DNI 

		this->texContrasenia->Text = this->texDni->Text;
	}
		  /* void CargarDatosUsuarios(); // Declaración del método CargarDatosUsuarios*/
		  

	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;








	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ butEliminarUsuario;



	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ texFallas;

	/*private: System::Windows::Forms::RadioButton^ radioButSi;*/
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
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->texFallas = (gcnew System::Windows::Forms::TextBox());
			this->radioButNo = (gcnew System::Windows::Forms::RadioButton());
			this->tablaUsuarios = (gcnew System::Windows::Forms::DataGridView());
			this->radioButHabSi = (gcnew System::Windows::Forms::RadioButton());
			this->radioButAdm = (gcnew System::Windows::Forms::RadioButton());
			this->radioButTrab = (gcnew System::Windows::Forms::RadioButton());
			this->radioButTec = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tablaUsuarios))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
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
			this->label2->Location = System::Drawing::Point(25, 86);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Nombre";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(25, 113);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(44, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Apellido";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(34, 202);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(23, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Rol";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(25, 157);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(54, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Habilitado";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(25, 58);
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
			this->texNombre->Location = System::Drawing::Point(151, 79);
			this->texNombre->Name = L"texNombre";
			this->texNombre->Size = System::Drawing::Size(100, 20);
			this->texNombre->TabIndex = 7;
			// 
			// texApellido
			// 
			this->texApellido->Location = System::Drawing::Point(151, 110);
			this->texApellido->Name = L"texApellido";
			this->texApellido->Size = System::Drawing::Size(100, 20);
			this->texApellido->TabIndex = 8;
			// 
			// texContrasenia
			// 
			this->texContrasenia->Location = System::Drawing::Point(151, 51);
			this->texContrasenia->Name = L"texContrasenia";
			this->texContrasenia->Size = System::Drawing::Size(100, 20);
			this->texContrasenia->TabIndex = 11;
			// 
			// butAgregarUsuario
			// 
			this->butAgregarUsuario->Location = System::Drawing::Point(696, 22);
			this->butAgregarUsuario->Name = L"butAgregarUsuario";
			this->butAgregarUsuario->Size = System::Drawing::Size(75, 23);
			this->butAgregarUsuario->TabIndex = 12;
			this->butAgregarUsuario->Text = L"Agregar";
			this->butAgregarUsuario->UseVisualStyleBackColor = true;
			this->butAgregarUsuario->Click += gcnew System::EventHandler(this, &Usuario::butAgregarUsuario_Click);
			// 
			// butModificarUsuario
			// 
			this->butModificarUsuario->Location = System::Drawing::Point(696, 86);
			this->butModificarUsuario->Name = L"butModificarUsuario";
			this->butModificarUsuario->Size = System::Drawing::Size(75, 23);
			this->butModificarUsuario->TabIndex = 13;
			this->butModificarUsuario->Text = L"Modificar";
			this->butModificarUsuario->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(257, 51);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(101, 23);
			this->button4->TabIndex = 15;
			this->button4->Text = L"Blanquear clave";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// butEliminarUsuario
			// 
			this->butEliminarUsuario->Location = System::Drawing::Point(696, 157);
			this->butEliminarUsuario->Name = L"butEliminarUsuario";
			this->butEliminarUsuario->Size = System::Drawing::Size(75, 23);
			this->butEliminarUsuario->TabIndex = 16;
			this->butEliminarUsuario->Text = L"Eliminar";
			this->butEliminarUsuario->UseVisualStyleBackColor = true;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(511, 204);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(34, 13);
			this->label7->TabIndex = 18;
			this->label7->Text = L"Fallas";
			// 
			// texFallas
			// 
			this->texFallas->Location = System::Drawing::Point(579, 199);
			this->texFallas->Name = L"texFallas";
			this->texFallas->ReadOnly = true;
			this->texFallas->Size = System::Drawing::Size(32, 20);
			this->texFallas->TabIndex = 19;
			// 
			// radioButNo
			// 
			this->radioButNo->AutoSize = true;
			this->radioButNo->Location = System::Drawing::Point(131, 17);
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
			this->tablaUsuarios->Location = System::Drawing::Point(28, 250);
			this->tablaUsuarios->Name = L"tablaUsuarios";
			this->tablaUsuarios->Size = System::Drawing::Size(743, 246);
			this->tablaUsuarios->TabIndex = 22;
			// 
			// radioButHabSi
			// 
			this->radioButHabSi->AutoSize = true;
			this->radioButHabSi->Location = System::Drawing::Point(21, 17);
			this->radioButHabSi->Name = L"radioButHabSi";
			this->radioButHabSi->Size = System::Drawing::Size(34, 17);
			this->radioButHabSi->TabIndex = 23;
			this->radioButHabSi->TabStop = true;
			this->radioButHabSi->Text = L"Si";
			this->radioButHabSi->UseVisualStyleBackColor = true;
			// 
			// radioButAdm
			// 
			this->radioButAdm->AutoSize = true;
			this->radioButAdm->Location = System::Drawing::Point(6, 19);
			this->radioButAdm->Name = L"radioButAdm";
			this->radioButAdm->Size = System::Drawing::Size(88, 17);
			this->radioButAdm->TabIndex = 24;
			this->radioButAdm->TabStop = true;
			this->radioButAdm->Text = L"Administrador";
			this->radioButAdm->UseVisualStyleBackColor = true;
			// 
			// radioButTrab
			// 
			this->radioButTrab->AutoSize = true;
			this->radioButTrab->Location = System::Drawing::Point(100, 19);
			this->radioButTrab->Name = L"radioButTrab";
			this->radioButTrab->Size = System::Drawing::Size(76, 17);
			this->radioButTrab->TabIndex = 25;
			this->radioButTrab->TabStop = true;
			this->radioButTrab->Text = L"Trabajador";
			this->radioButTrab->UseVisualStyleBackColor = true;
			// 
			// radioButTec
			// 
			this->radioButTec->AutoSize = true;
			this->radioButTec->Location = System::Drawing::Point(202, 19);
			this->radioButTec->Name = L"radioButTec";
			this->radioButTec->Size = System::Drawing::Size(64, 17);
			this->radioButTec->TabIndex = 26;
			this->radioButTec->TabStop = true;
			this->radioButTec->Text = L"Técnico";
			this->radioButTec->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButNo);
			this->groupBox1->Controls->Add(this->radioButHabSi);
			this->groupBox1->Location = System::Drawing::Point(114, 140);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 40);
			this->groupBox1->TabIndex = 27;
			this->groupBox1->TabStop = false;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->radioButAdm);
			this->groupBox2->Controls->Add(this->radioButTrab);
			this->groupBox2->Controls->Add(this->radioButTec);
			this->groupBox2->Location = System::Drawing::Point(87, 194);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(303, 50);
			this->groupBox2->TabIndex = 28;
			this->groupBox2->TabStop = false;
			// 
			// Usuario
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(874, 508);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->tablaUsuarios);
			this->Controls->Add(this->texFallas);
			this->Controls->Add(this->label7);
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
			this->Location = System::Drawing::Point(151, 143);
			this->Name = L"Usuario";
			this->Text = L"Usuario";
			this->Load += gcnew System::EventHandler(this, &Usuario::Usuario_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tablaUsuarios))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void butAgregarUsuario_Click(System::Object^ sender, System::EventArgs^ e) {
		
		DataAccess::UserDao^ userDao = gcnew DataAccess::UserDao();
		int dni = Int32::Parse(this->texDni->Text);

		int password = Int32::Parse(this->texDni->Text);// this->texContrasenia->Text;
		this->texContrasenia->Text = password.ToString();

		String^ nombre = this->texNombre->Text;
		String^ apellido = this->texApellido->Text;

		bool habilitado = this->radioButHabSi->Checked;
		
		int rolId=0; 
		
		if (radioButAdm->Checked) 
		{
			rolId = 1; // Administrador
		}
		else if (radioButTrab->Checked) 
		{ 
			rolId = 2; // Trabajador 
		}
		else if (radioButTec->Checked)
		{
			rolId = 3; // Técnico }

		}
		int fallas = 0; // this->texFallas->Text;

		this->texFallas->Text = fallas.ToString();

		/*UserDao^ userDao = gcnew UserDao();*/

		bool resultado = userDao->IngresarUsuario(dni, nombre, apellido, habilitado, fallas, password, rolId);

		if (resultado)
		{
			MessageBox::Show("Usuario guardado exitosamente."); 
			LoadData();
		}
		else 
		{
			MessageBox::Show("Error al guardar el usuario."); }
		

	};




	private: System::Void Usuario_Load(System::Object^ sender, System::EventArgs^ e) {
		          LoadData();
	}

		 void LoadData()
		   {
			   DataAccess::UserDao^ userDao = gcnew DataAccess::UserDao();
			   DataTable^ dataTable = userDao->GetAllUsuarios(); // Llama al método para obtener el DataTable
			   tablaUsuarios->DataSource = dataTable; // Asigna el DataTable al DataGridView

		   }


	
};

}
