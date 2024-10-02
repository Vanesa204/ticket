#pragma once
#include "Login.h"
#include "DataAccess.h"

namespace Ticket {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de ModifLogin
	/// </summary>
	public ref class ModifLogin : public System::Windows::Forms::Form
	{
	public:
		ModifLogin(void)
		{
			InitializeComponent();
		
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~ModifLogin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ nuevaContrase�a;
	private: System::Windows::Forms::TextBox^ contraseniaActual;
	private: System::Windows::Forms::TextBox^ nuevaContrasenia;
	private: System::Windows::Forms::Button^ btnCambiarContrasena;
	





	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ confContrasenia;


	protected:

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->nuevaContrase�a = (gcnew System::Windows::Forms::Label());
			this->contraseniaActual = (gcnew System::Windows::Forms::TextBox());
			this->nuevaContrasenia = (gcnew System::Windows::Forms::TextBox());
			this->btnCambiarContrasena = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->confContrasenia = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 59);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(93, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Contrase�a actual";
			// 
			// nuevaContrase�a
			// 
			this->nuevaContrase�a->AutoSize = true;
			this->nuevaContrase�a->Location = System::Drawing::Point(12, 108);
			this->nuevaContrase�a->Name = L"nuevaContrase�a";
			this->nuevaContrase�a->Size = System::Drawing::Size(96, 13);
			this->nuevaContrase�a->TabIndex = 1;
			this->nuevaContrase�a->Text = L"Nueva Contrase�a";
			// 
			// contraseniaActual
			// 
			this->contraseniaActual->Location = System::Drawing::Point(158, 52);
			this->contraseniaActual->Name = L"contraseniaActual";
			this->contraseniaActual->Size = System::Drawing::Size(100, 20);
			this->contraseniaActual->TabIndex = 2;
			// 
			// nuevaContrasenia
			// 
			this->nuevaContrasenia->Location = System::Drawing::Point(158, 101);
			this->nuevaContrasenia->Name = L"nuevaContrasenia";
			this->nuevaContrasenia->Size = System::Drawing::Size(100, 20);
			this->nuevaContrasenia->TabIndex = 3;
			// 
			// btnCambiarContrasena
			// 
			this->btnCambiarContrasena->Location = System::Drawing::Point(100, 203);
			this->btnCambiarContrasena->Name = L"btnCambiarContrasena";
			this->btnCambiarContrasena->Size = System::Drawing::Size(75, 23);
			this->btnCambiarContrasena->TabIndex = 4;
			this->btnCambiarContrasena->Text = L"Ingresar";
			this->btnCambiarContrasena->UseVisualStyleBackColor = true;
			this->btnCambiarContrasena->Click += gcnew System::EventHandler(this, &ModifLogin::btnCambiarContrasena_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 152);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(140, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Confirma Nueva Contrase�a";

			// 
			// confContrasenia
			// 
			this->confContrasenia->Location = System::Drawing::Point(158, 145);
			this->confContrasenia->Name = L"confContrasenia";
			this->confContrasenia->Size = System::Drawing::Size(100, 20);
			this->confContrasenia->TabIndex = 6;
			// 
			// ModifLogin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->confContrasenia);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->btnCambiarContrasena);
			this->Controls->Add(this->nuevaContrasenia);
			this->Controls->Add(this->contraseniaActual);
			this->Controls->Add(this->nuevaContrase�a);
			this->Controls->Add(this->label1);
			this->Name = L"ModifLogin";
			this->Text = L"ModifLogin";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnCambiarContrasena_Click(System::Object^ sender, System::EventArgs^ e) {
		DataAccess::UserDao^ userDao = gcnew DataAccess::UserDao();
		String^ usuario = userDao->currentUser;
		String^ password = this->contraseniaActual->Text;
		String^ nuevaContrasenia = this->nuevaContrasenia->Text;
		String^ confirmarContrasenia = this->confContrasenia->Text;
		
		
		
		if (String::IsNullOrEmpty(nuevaContrasenia)) {
			MessageBox::Show("El campo de la nueva contrase�a no puede estar vac�o.");
			return;
		}

		if (nuevaContrasenia != confirmarContrasenia)
		{
			MessageBox::Show("La nueva contrase�a y la confirmaci�n no coinciden.");
			return;
		}

		
		bool resultado = userDao->Login(usuario, password);

		if (!resultado)
		{
			MessageBox::Show("La contrase�a actual es incorrecta");
			return;
		}

		//actualizo la contrase�a
	     resultado = userDao->cambiarContrasenia(usuario, nuevaContrasenia); 
		 if (resultado)
		{
			MessageBox::Show("Contrase�a cambiada exitosamente");
		}
		else
		{
			MessageBox::Show("Error al cambiar la contrase�a");
		}

		this->Close();


	}
};
}
