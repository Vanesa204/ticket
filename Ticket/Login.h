#pragma once
#include "pch.h"
#include "ModifLogin.h"
#include "VistaPanel.h"
#include "Login.h"
#include "Ticket1.h"
#include "Usuario.h"
#include "DataAccess.h"



 namespace Ticket {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Login
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		Login(void)
		{
			InitializeComponent();

			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ contrasena;
	private: System::Windows::Forms::TextBox^ nIdentificacion;
	protected:



	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->contrasena = (gcnew System::Windows::Forms::TextBox());
			this->nIdentificacion = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(98, 182);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Ingresar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Login::button1_Click);
			// 
			// contrasena
			// 
			this->contrasena->Location = System::Drawing::Point(138, 116);
			this->contrasena->Name = L"contrasena";
			this->contrasena->Size = System::Drawing::Size(100, 20);
			this->contrasena->TabIndex = 8;
			// 
			// nIdentificacion
			// 
			this->nIdentificacion->Location = System::Drawing::Point(138, 56);
			this->nIdentificacion->Name = L"nIdentificacion";
			this->nIdentificacion->Size = System::Drawing::Size(100, 20);
			this->nIdentificacion->TabIndex = 7;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(23, 123);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(61, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Contraseña";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(23, 59);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(85, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Nº Identificación";
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->contrasena);
			this->Controls->Add(this->nIdentificacion);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Login";
			this->Text = L"Inicio";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ usuarioStr = this->nIdentificacion->Text;
		String^ passwordStr = this->contrasena->Text;
		String^ rol = nullptr;
		if (String::IsNullOrEmpty(usuarioStr)) {
			MessageBox::Show("El campo de identificación no puede estar vacío.");
			return;
		}
		if (String::IsNullOrEmpty(passwordStr)) {
			MessageBox::Show("El campo de contraseña no puede estar vacío.");
			return;
		}
		int dni;
		int password;
		try

		{
			dni = Int32::Parse(usuarioStr);

		}
		catch (FormatException^) {
			MessageBox::Show("El formato de la identificación no es válido. Asegúrate de que sea un número entero.");
			return;
		}

		try { 
			password = Int32::Parse(passwordStr);

		}
		catch(FormatException^){
			MessageBox::Show("El formato de la contraseña no es válido. Asegúrate de que sea un número entero.");
		return;
		}

		/*int dni = Int32::Parse(this->nIdentificacion->Text);
		int password = Int32::Parse(this->contrasena->Text);*/
	

		Console::WriteLine("Usuario ingresado: " + dni.ToString());
		Console::WriteLine("Contraseña ingresada: " + password.ToString());
		System::Diagnostics::Debug::WriteLine("Valor de usuario: " + dni.ToString());   // Línea de depuración para verificar el valor de usuario


		try {
			/*MessageBox::Show("ingreso al try");*/


			DataAccess::UserDao^ userDao = gcnew DataAccess::UserDao();
			Console::WriteLine("Llamando a Login con dni: " + dni + " y password: " + password);

			bool resultado = userDao->Login(dni, password, rol);


			if (resultado) {
				MessageBox::Show("existe en la base de datos");

				DataAccess::UserDao::currentUser = dni;
			
				/*userDao->currentUser = dni;*/

				if (dni == password)
				{
					//Ticket::ModifLogin^ modifLogin = gcnew Ticket::ModifLogin(userDao->currentUser);remplazo por la de abajo
					Ticket::ModifLogin^ modifLogin = gcnew Ticket::ModifLogin(DataAccess::UserDao::currentUser);
					
					modifLogin->Show();

				}
			
				else {

					MessageBox::Show("vista panel");
				
					Ticket::VistaPanel^ vistaPanel = gcnew Ticket::VistaPanel(rol); 
					vistaPanel->Show();
					 
				}
				
			}
			else
			{
				MessageBox::Show("Usuario o contraseña incorrectos.");

			}
			/* }
			catch (FormatException^ ex) {
				MessageBox::Show("El formato de la identificación o la contraseña no es válido.");
			}*/
		}
		catch (Exception^ ex) {
			MessageBox::Show("Ocurrió un error " );
		}

	};

	};
}





