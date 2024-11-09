#pragma once
using namespace System;
using namespace MySql::Data::MySqlClient;

namespace DataAccess {
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
	};
}