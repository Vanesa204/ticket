#include "pch.h"
#include "DataAccess.h"


DataAccess::ConnectionToSql::ConnectionToSql()
{
	this->connectionString = "datasource=localhost; username=root; password=vanesa; database=ticket;";
}
	MySqlConnection^ DataAccess::ConnectionToSql::GetConnection()
	{
		return gcnew MySqlConnection(this->connectionString);
	}


	bool DataAccess::UserDao::Login(String^ usuario, String^ password)
	{
		//if (String::IsNullOrEmpty(usuario) || String::IsNullOrEmpty(password)) {
		//	throw gcnew ArgumentException("Usuario y contraseña no pueden ser nulos.");
		//}
		MySqlConnection^ connection = GetConnection();
		try
		{
			connection->Open();
			MySqlCommand^ cursor = gcnew MySqlCommand();
			cursor->Connection = connection;
			cursor->CommandText = "SELECT * FROM login WHERE usuario = @usuario AND password = @password";
			int usuarioInt = Int32::Parse(usuario);
			int passwordInt = Int32::Parse(password);
			cursor->Parameters->AddWithValue("@usuario", usuarioInt);
			cursor->Parameters->AddWithValue("@password", passwordInt);

			MySqlDataReader^ reader = cursor->ExecuteReader();
			if (reader->HasRows) {
				reader->Read();
				int dbPassword = Convert::ToInt32(reader["password"]);
				if (passwordInt == dbPassword)
				{
					this->currentUser = usuario; //guarda el nombre de usuario en una variable global


					return true;
				}
			}

			return false;


		}
		finally
		{
			connection->Close();
		}
	}

	bool DataAccess::UserDao::cambiarContrasenia(String^ usuario, String^ nuevaContrasenia)
	{
		if (String::IsNullOrEmpty(nuevaContrasenia)) {
			throw gcnew ArgumentException("La nueva contrasenia no puede ser nula.");
		}
	
		MySqlConnection^ connection = GetConnection();
		try{
		connection->Open();
		MySqlCommand^ cursor = gcnew MySqlCommand();

		cursor->Connection = connection;
		cursor->CommandText = "UPDATE login SET password = @password WHERE usuario = @usuario";

		int usuarioInt = Int32::Parse(usuario);
		int nuevaContraseniaInt = Int32::Parse(nuevaContrasenia);

		cursor->Parameters->AddWithValue("@usuario", usuarioInt);
		cursor->Parameters->AddWithValue("@password", nuevaContraseniaInt);

		int resultado = cursor->ExecuteNonQuery();
		return resultado > 0;
		}
		finally {
			connection->Close();
		}
	}