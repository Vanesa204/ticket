#include "pch.h"
#include "DataAccess.h"
#include "Usuario.h"

using namespace System::Windows::Forms;

DataAccess::ConnectionToSql::ConnectionToSql()
{
	this->connectionString = "datasource=localhost; username=root; password=vanesa; database=ticket;";

}

	MySqlConnection^ DataAccess::ConnectionToSql::GetConnection()
 
	{
		return gcnew MySqlConnection(this->connectionString);
	}

	



bool DataAccess::UserDao::Login( int dni, int password, String^% rol)
{
		MySqlConnection^ connection = GetConnection();
		try
		
		{
			connection->Open();
			MySqlCommand^ cursor = gcnew MySqlCommand();


			cursor->Connection = connection;

			// Paso 1: Verificar Usuario y Contraseña
			cursor->CommandText = "SELECT Id, dni, password FROM login WHERE dni = @dni AND password = @password";
			cursor->Parameters->AddWithValue("@dni", dni);
			cursor->Parameters->AddWithValue("@password", password);

			Console::WriteLine("Ejecutando consulta: " + cursor->CommandText);//para ver si funciona

			MySqlDataReader^ reader = cursor->ExecuteReader();

			if (reader->HasRows) {
				
				MessageBox::Show("ingrese a if");

				reader->Read();
				int userId = reader->GetInt32(reader->GetOrdinal("Id"));
				int dbUsuario = reader->GetInt32(reader->GetOrdinal("dni"));
				int dbPassword = reader->GetInt32(reader->GetOrdinal("password"));

				if (password == dbPassword) {

					
				DataAccess::UserDao::currentUser = dbUsuario; 
				Console::WriteLine("Usuario y contraseña correctos: " + dbUsuario);
				/*DataAccess::UserDao::currentUser = dbUsuario;*/
				reader->Close(); // Cerrar el reader antes de ejecutar otra consulta 

			
				MessageBox::Show("user" + userId);
				// Paso 2: Obtener el Rol del Usuario
				cursor->CommandText = "SELECT r.nombreRol FROM usuariosroles ur "
					"JOIN roles r ON ur.rolId = r.id "
					"WHERE ur.usuarioId = @usuarioId";
				cursor->Parameters->Clear(); // Limpiar parámetros anteriores
				cursor->Parameters->AddWithValue("@usuarioId", userId);

				Console::WriteLine("Ejecutando consulta para rol: " + cursor->CommandText);//para ver si funciona
				reader = cursor->ExecuteReader();
				if (reader->HasRows) {
					MessageBox::Show("reader");
					reader->Read();
					rol = reader["nombreRol"]->ToString();
					Console::WriteLine("Rol encontrado: " + rol);//para ver si funciona
					return true;
				}
				else{
					Console::WriteLine("No se encontraron roles para el usuario.");
				}
				}
				else { Console::WriteLine("Contraseña incorrecta."); }
			}
			else {
				Console::WriteLine("No se encontraron filas con ese usuario y contraseña.");
			}
			return false;
			/*Console::WriteLine("Usuario o contraseña incorrectos.");//para ver si funciona
			return false;*/
		}
		catch (Exception^ ex)
		{
			Console::WriteLine("Error en Login: " + ex->Message);
			//throw;
			 return false;
		}

		finally
		{
			connection->Close();
		}

	}

	

	bool DataAccess::UserDao::cambiarContrasenia(int dni, int nuevaContrasenia)
	{
		if (nuevaContrasenia<=0) {
			throw gcnew ArgumentException("La nueva contrasenia no puede ser nula.");
		}
	
		MySqlConnection^ connection = GetConnection();
		try{
		connection->Open();
		MySqlCommand^ cursor = gcnew MySqlCommand();

		cursor->Connection = connection;
		cursor->CommandText = "UPDATE login SET password = @password WHERE dni = @dni";


		cursor->Parameters->AddWithValue("@dni", dni);
		cursor->Parameters->AddWithValue("@password", nuevaContrasenia);

		int resultado = cursor->ExecuteNonQuery();
		return resultado > 0;
		}
		finally {
			connection->Close();
		}
	}
	bool DataAccess::UserDao::IngresarUsuario(int dni, String^ nombre, String^ apellido, bool habilitado, int fallas, int password, int rolId)
	{
	
		
		MySqlConnection^ connection = GetConnection();

		String^ queryUsuarios = "INSERT INTO usuarios (dni, nombre, apellido, habilitado,  fallas, password) VALUES (@dni, @nombre, @apellido, @habilitado, @fallas,  @password)";
		MySqlCommand^ commandUsuarios = gcnew MySqlCommand(queryUsuarios, connection);

		// Agregar los parámetros
		commandUsuarios->Parameters->AddWithValue("@dni", dni);
		commandUsuarios->Parameters->AddWithValue("@nombre", nombre);
		commandUsuarios->Parameters->AddWithValue("@apellido", apellido);
		commandUsuarios->Parameters->AddWithValue("@habilitado", habilitado ? 1 : 0); // Convertir a 1 o 0
		commandUsuarios->Parameters->AddWithValue("@password", password);
		commandUsuarios->Parameters->AddWithValue("@fallas", fallas);

		try {
			connection->Open();
			commandUsuarios->ExecuteNonQuery();

			// Obtener el ID del usuario recién insertado 
			int usuarioId = (int)commandUsuarios->LastInsertedId;
			
			// Inserta en la tabla usuariosroles 
			
			String^ queryUsuariosRoles = "INSERT INTO usuariosroles (usuarioId, rolId) VALUES (@usuarioId, @rolId)";
			MySqlCommand^ commandUsuariosRoles = gcnew MySqlCommand(queryUsuariosRoles, connection);

			commandUsuariosRoles->Parameters->AddWithValue("@usuarioId", usuarioId);
			commandUsuariosRoles->Parameters->AddWithValue("@rolId", rolId);

			commandUsuariosRoles->ExecuteNonQuery();

		
			connection->Close(); 
			return true;
		} catch (Exception^ ex) { 
			connection->Close();
		return false; 
		}
}