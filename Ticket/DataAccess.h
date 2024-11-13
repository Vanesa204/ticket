#pragma once
using namespace System;
using namespace MySql::Data::MySqlClient;
using namespace std;

namespace DataAccess {
	using namespace System::Data;
	public ref class ConnectionToSql
	{
	public:
	    static String^ connectionString;
		ConnectionToSql();
		MySqlConnection^ GetConnection();
		
	};
	public ref class  UserDao :ConnectionToSql {


	public:
		static int currentUser = 0;//aca habia solucionado con Static cuando me salia nulo usuario
		bool Login(int dni, int password, String^% rol);
		bool cambiarContrasenia(int dni, int nuevaContrasenia);
		bool IngresarUsuario(int dni, String^ nombre, String^ apellido, bool habilitado, int fallas, int password, int rolId);
		DataTable^ GetAllUsuarios();
		bool carga_ticket(String^ titulo, String^ detalle, int trabajador_id, int% N_Ticket);
		DataTable^ GetAllTickets();
		bool buttonVerTickets_Click();
		bool CanAtenderTicket();
		bool UpdateTicketStatus(int ticketId, String^ estado, int tecnicoId);
		bool ReabrirTicket(int ticketId, int tecnicoId);

	};
}