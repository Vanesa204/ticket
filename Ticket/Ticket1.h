#pragma once
#include "DataAccess.h"
#include "VistaPanel.h"  // Asegúrate de que este archivo exista
#include "Ticket1.h"  // Asegúrate de que este archivo exista

namespace Ticket
{

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Resumen de Ticket1
    /// </summary>
   
    public ref class Ticket1 : public System::Windows::Forms::Form
    {
       private:
       DataTable^ dataTable;
       // String^ rol;  // Declaramos rol como miembro de la clase

    public:
        Ticket1(String^ rol)
        {
            InitializeComponent();
            //this->rol = rol;  // Guardamos el rol al inicializar la clase
            AjustarVisibilidadBotonesTicket(rol);
        }

    protected:
        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        ~Ticket1()
        {
            if (components)
            {
                delete components;
            }
        }

    private: DataAccess::UserDao^ userDao;
    private: System::Windows::Forms::DataGridView^ tableTickets;
    private: System::Windows::Forms::Button^ buttonConfirmar;
    private: System::Windows::Forms::Button^ buttonReabrir;
    private: System::Windows::Forms::Button^ buttonAtender;
    private: System::Windows::Forms::Button^ buttonResuelto;

    protected:
    private:
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code








        void InitializeComponent(void)

        {
            this->tableTickets = (gcnew System::Windows::Forms::DataGridView());
            this->buttonConfirmar = (gcnew System::Windows::Forms::Button());
            this->buttonReabrir = (gcnew System::Windows::Forms::Button());
            this->buttonAtender = (gcnew System::Windows::Forms::Button());
            this->buttonResuelto = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tableTickets))->BeginInit();
            this->SuspendLayout();

            // tableTickets
            this->tableTickets->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->tableTickets->Location = System::Drawing::Point(12, 40);
            this->tableTickets->Name = L"tableTickets";
            this->tableTickets->Size = System::Drawing::Size(710, 150);
            this->tableTickets->TabIndex = 9;

            // buttonConfirmar
            this->buttonConfirmar->Location = System::Drawing::Point(53, 219);
            this->buttonConfirmar->Name = L"buttonConfirmar";
            this->buttonConfirmar->Size = System::Drawing::Size(75, 23);
            this->buttonConfirmar->TabIndex = 10;
            this->buttonConfirmar->Text = L"Confirmar";
            this->buttonConfirmar->UseVisualStyleBackColor = true;

            // buttonReabrir
            this->buttonReabrir->Location = System::Drawing::Point(53, 261);
            this->buttonReabrir->Name = L"buttonReabrir";
            this->buttonReabrir->Size = System::Drawing::Size(75, 23);
            this->buttonReabrir->TabIndex = 11;
            this->buttonReabrir->Text = L"Reabrir";
            this->buttonReabrir->UseVisualStyleBackColor = true;

            // buttonAtender
            this->buttonAtender->Location = System::Drawing::Point(688, 219);
            this->buttonAtender->Name = L"buttonAtender";
            this->buttonAtender->Size = System::Drawing::Size(75, 23);
            this->buttonAtender->TabIndex = 12;
            this->buttonAtender->Text = L"Atender";
            this->buttonAtender->UseVisualStyleBackColor = true;
            this->buttonAtender->Click += gcnew System::EventHandler(this, &Ticket1::buttonAtender_Click);

            // buttonResuelto
            this->buttonResuelto->Location = System::Drawing::Point(688, 261);
            this->buttonResuelto->Name = L"buttonResuelto";
            this->buttonResuelto->Size = System::Drawing::Size(75, 23);
            this->buttonResuelto->TabIndex = 13;
            this->buttonResuelto->Text = L"Resuelto";
            this->buttonResuelto->UseVisualStyleBackColor = true;

            // Ticket1
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(788, 322);
            this->Controls->Add(this->buttonResuelto);
            this->Controls->Add(this->buttonAtender);
            this->Controls->Add(this->buttonReabrir);
            this->Controls->Add(this->buttonConfirmar);
            this->Controls->Add(this->tableTickets);
            this->Name = L"Ticket1";
            this->Text = L"Ticket1";
            this->Load += gcnew System::EventHandler(this, &Ticket1::Ticket_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tableTickets))->EndInit();
            this->ResumeLayout(false);
        }
#pragma endregion

    private: System::Void buttonAtender_Click(System::Object^ sender, System::EventArgs^ e)
    {
        // Lógica para el evento de atender ticket
    }

    private: System::Void Ticket_Load(System::Object^ sender, System::EventArgs^ e){
        //AjustarVisibilidadBotonesTicket(rol);
        LoadDataTickets();
    }

           void LoadDataTickets()
           {
               DataAccess::UserDao^ userDao = gcnew DataAccess::UserDao();
               DataTable^ dataTable = userDao->GetAllTickets(); // Llama al método para obtener el DataTable
               tableTickets->DataSource = dataTable; // Asigna el DataTable al DataGridView
           }

           void AjustarVisibilidadBotonesTicket(String^ rol)
           {
               int rolInt = 0;
               if (rol == "1") // Administrador
                   rolInt = 1;
               else if (rol == "2") // Técnico
                   rolInt = 2;
               else if (rol == "3") // Trabajador
                   rolInt = 3;

               if (rolInt == 1)
               {  // Administrador
                   this->buttonConfirmar->Visible = true;
                   this->buttonReabrir->Visible = true;
                   this->buttonAtender->Visible = true;
                   this->buttonResuelto->Visible = true;
               }
               else if (rolInt == 2)
               
               {  // Técnico
                   this->buttonConfirmar->Visible = false;
                   this->buttonReabrir->Visible = false;
                   this->buttonAtender->Visible = true;
                   this->buttonResuelto->Visible = true;
               }
               else if (rolInt == 3)
               
               {  // Trabajador
                   this->buttonConfirmar->Visible = true;
                   this->buttonReabrir->Visible = true;
                   this->buttonAtender->Visible = false;
                   this->buttonResuelto->Visible = false;
               }
           }
    };

}
