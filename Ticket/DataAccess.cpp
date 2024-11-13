#include "pch.h"
#include "DataAccess.h"
#include "Usuario.h"
#include "Ticket1.h"
#include "Listado.h"


using namespace System::Windows::Forms;
using namespace System::Data;
using namespace DataAccess;


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
			cursor->CommandText = "SELECT `Id`, `dni`, `password` FROM `usuarios` WHERE `dni` = @dni AND `password` = @password";
			/*cursor->CommandText = "SELECT Id, dni, password FROM login WHERE dni = @dni AND password = @password";*/
			cursor->Parameters->AddWithValue("@dni", dni);
			cursor->Parameters->AddWithValue("@password", password);

			Console::WriteLine("Ejecutando consulta: " + cursor->CommandText);//para ver si funciona

			MySqlDataReader^ reader = cursor->ExecuteReader();

			if (reader->HasRows) {
				
				/*MessageBox::Show("ingrese a if");*/

				reader->Read();
				int userId = reader->GetInt32(reader->GetOrdinal("Id"));
				int dbUsuario = reader->GetInt32(reader->GetOrdinal("dni"));
				int dbPassword = reader->GetInt32(reader->GetOrdinal("password"));

				if (password == dbPassword) {

					
				DataAccess::UserDao::currentUser = dbUsuario;

				Console::WriteLine("Usuario y contraseña correctos: " + dbUsuario);

				
				reader->Close(); // Cerrar el reader antes de ejecutar otra consulta 

			
				MessageBox::Show("user" + userId);
				
				// Paso 2: Obtener el Rol del Usuario
				cursor->CommandText = "SELECT rol FROM usuarios WHERE id = @usuarioId";
				cursor->Parameters->Clear(); // Limpiar parámetros anteriores
				cursor->Parameters->AddWithValue("@usuarioId", userId);

				Console::WriteLine("Ejecutando consulta para rol: " + cursor->CommandText);//para ver si funciona
				
				reader = cursor->ExecuteReader();

				if (reader->HasRows) 
				{

					MessageBox::Show("reader");

					reader->Read();
					rol = reader["rol"]->ToString();

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
		cursor->CommandText = "UPDATE `usuarios` SET `password` = @password WHERE `dni` = @dni";



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

		String^ queryUsuarios = "INSERT INTO usuarios (dni, nombre, apellido, habilitado,  fallas, password, rol) VALUES (@dni, @nombre, @apellido, @habilitado, @fallas,  @password, @rol)";
		MySqlCommand^ commandUsuarios = gcnew MySqlCommand(queryUsuarios, connection);

		// Agregar los parámetros
		commandUsuarios->Parameters->AddWithValue("@dni", dni);
		commandUsuarios->Parameters->AddWithValue("@nombre", nombre);
		commandUsuarios->Parameters->AddWithValue("@apellido", apellido);
		commandUsuarios->Parameters->AddWithValue("@habilitado", habilitado ? 1 : 0); // Convertir a 1 o 0
		commandUsuarios->Parameters->AddWithValue("@password", password);
		commandUsuarios->Parameters->AddWithValue("@fallas", fallas);
		commandUsuarios->Parameters->AddWithValue("@rol", rolId);

		try {
			connection->Open();
			commandUsuarios->ExecuteNonQuery();


			connection->Close();
			return true;
		}
		catch (Exception^ ex) {
			connection->Close();
			return false;
		}
	}
	
	    DataTable^ DataAccess::UserDao::GetAllUsuarios()
		
		{

		DataTable^ dataTable = gcnew DataTable();
		MySqlConnection^ connection = GetConnection();
		
		connection->Open();

		MySqlCommand^ cursor = gcnew MySqlCommand("SELECT * FROM usuarios", connection);
		MySqlDataReader^ reader = cursor->ExecuteReader();

		dataTable->Load(reader); // Carga los datos directamente en el DataTable 
		reader->Close();
		connection->Close();
		return dataTable;
	}

		bool DataAccess::UserDao::carga_ticket(String^ titulo, String^ detalle, int trabajador_id, int% N_Ticket)
		{

			MySqlConnection^ connection = GetConnection();
			try

			{
				connection->Open();
				MySqlCommand^ cursor = gcnew MySqlCommand();
				cursor->Connection = connection;
				cursor->CommandText = "INSERT INTO tickets (titulo, detalle, trabajador_id) VALUES (@titulo, @detalle, @trabajador_id)";
				cursor->Parameters->AddWithValue("@titulo", titulo);
				cursor->Parameters->AddWithValue("@detalle", detalle);
				cursor->Parameters->AddWithValue("@trabajador_id", trabajador_id);
				cursor->ExecuteNonQuery();
				// Recupera el N_Ticket generado
				cursor->CommandText = "SELECT LAST_INSERT_ID()";
				N_Ticket = Convert::ToInt32(cursor->ExecuteScalar());

				connection->Close();
				return true;
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Error al insertar el ticket: " + ex->Message);
				return false;

			}
			finally
			{
				if (connection->State == ConnectionState::Open)
				{
					connection->Close();
				}
			}

		}


		DataTable^ DataAccess::UserDao::GetAllTickets()

		{

			DataTable^ dataTable = gcnew DataTable();
			MySqlConnection^ connection = GetConnection();

			connection->Open();

			MySqlCommand^ cursor = gcnew MySqlCommand("SELECT * FROM tickets", connection);
			MySqlDataReader^ reader = cursor->ExecuteReader();

			dataTable->Load(reader); // Carga los datos directamente en el DataTable 
			reader->Close();
			connection->Close();
			return dataTable;
		}

		bool DataAccess::UserDao::buttonVerTickets_Click()

		{
			return false;
		}

		

		bool  DataAccess::UserDao::CanAtenderTicket()
		{
			MySqlConnection^ connection = GetConnection();
	
			// Aquí `tecnico_id` debe ser el id del técnico actual (esto lo puedes obtener de la sesión o desde el formulario)
			int tecnicoDni = DataAccess::UserDao::currentUser;  // Sustituye con el id real del técnico

			// Ejecutar la consulta SQL

			try
			{
				connection->Open();

				// Crear el comando SQL con la consulta y el parámetro del técnico
				MySqlCommand^ cursor= gcnew MySqlCommand();
				cursor->Connection = connection;
				cursor->CommandText = "SELECT COUNT(*) FROM tickets WHERE tecnico_id = @tecnico_id AND estado = 'Atendido'";

				cursor->Parameters->AddWithValue("@tecnico_id", tecnicoDni);

				// Ejecutar la consulta y obtener el resultado
				int count = Convert::ToInt32(cursor->ExecuteScalar());


			// Si ya tiene 3 tickets atendidos, no permitirá atender más
			return count < 3;
		}
			catch (Exception^ ex)
			{
				// Si hay algún error, mostramos el mensaje de error (se puede registrar o manejar más específicamente)
				MessageBox::Show("Error al verificar los tickets atendidos: " + ex->Message);
				return false;
			}
			finally
			{
				if (connection->State == ConnectionState::Open)
				{
					connection->Close();
				}
			}
		 }

		bool DataAccess::UserDao::UpdateTicketStatus(int ticketId, String^ estado, int tecnicoId) //(int ticketId, String^ newStatus) use para 1 solo parametro
		{
			MySqlConnection^ connection = GetConnection();

			try
			{
				connection->Open();

				MySqlCommand^ cursor = gcnew MySqlCommand();
				cursor->Connection = connection;
				// Primero verificar si el ticket ya está en estado "Atendido"
				cursor->CommandText = "SELECT estado FROM tickets WHERE N_Ticket = @ticketId";
				cursor->Parameters->AddWithValue("@ticketId", ticketId);

				MySqlDataReader^ reader = cursor->ExecuteReader();
				if (reader->HasRows)
				{
					reader->Read();
					String^ currentState = reader["estado"]->ToString();
					reader->Close();


					// Si el ticket ya está atendido, no permitimos actualizarlo
					if (currentState == "Atendido" && estado == "Atendido")
					{
						MessageBox::Show("Este ticket ya ha sido atendido.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
						return false;  // No permitimos que se marque como atendido
					}
					// Verificar si el ticket está en estado "Resuelto" para cambiarlo a "Finalizado"
					if (currentState == "Resuelto" && estado == "Finalizado")
					{
						// Si ya está en "Resuelto", entonces permitimos pasar a "Finalizado"
						cursor->CommandText = "UPDATE tickets SET estado = @estado, tecnico_id = @tecnico_id WHERE N_Ticket = @N_Ticket";
						cursor->Parameters->AddWithValue("@estado", estado);
						cursor->Parameters->AddWithValue("@tecnico_id", tecnicoId);
						cursor->Parameters->AddWithValue("@N_Ticket", ticketId);
						int resultado = cursor->ExecuteNonQuery();

						// Si se actualizó al menos una fila, se considera exitoso
						return resultado > 0;
					}
				}
				else
				{
					reader->Close();
					MessageBox::Show("No se encontró el ticket.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return false;
				}

				// Si no está en estado "Atendido", actualizamos el ticket
				//


				// Comando SQL para actualizar el estado de un ticket
				cursor->CommandText = "UPDATE tickets SET estado = @estado, tecnico_id = @tecnico_id WHERE N_Ticket = @N_Ticket";

				// Agregar los parámetros para evitar inyecciones SQL
				cursor->Parameters->AddWithValue("@estado", estado);
				cursor->Parameters->AddWithValue("@tecnico_id", tecnicoId);
				cursor->Parameters->AddWithValue("@N_Ticket", ticketId);

				// Ejecutar la consulta SQL
				int resultado = cursor->ExecuteNonQuery();

				// Si se actualizó al menos una fila, se considera exitoso
				return resultado > 0;
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Error al actualizar el estado del ticket: " + ex->Message);
				return false;
			}
			finally
			{
				if (connection->State == ConnectionState::Open)
				{
					connection->Close();
				}
			}
		}


		bool DataAccess::UserDao::ReabrirTicket(int ticketId, int tecnicoId)
		{
			MySqlConnection^ connection = GetConnection();

			try
			{
				connection->Open();

				MySqlCommand^ cursor = gcnew MySqlCommand();
				cursor->Connection = connection;

				// Limpiar los parámetros antes de agregar nuevos
				cursor->Parameters->Clear();
				// Primero, obtener el ID del técnico que marcó el ticket como Resuelto
				cursor->CommandText = "SELECT tecnico_id FROM tickets WHERE N_Ticket = @ticketId";
				cursor->Parameters->AddWithValue("@ticketId", ticketId);

				MySqlDataReader^ reader = cursor->ExecuteReader();
				if (reader->HasRows)
				{
					reader->Read();
					int tecnicoAnteriorId = Convert::ToInt32(reader["tecnico_id"]);
					reader->Close();

					// Cambiar el estado del ticket a "No atendido y Reabierto"
					cursor->CommandText = "UPDATE tickets SET estado = 'No atendido', reabierto = 1, tecnico_id = NULL, tecnico_anterior_id = @tecnicoId WHERE N_Ticket = @ticketIdUpdate";
					cursor->Parameters->AddWithValue("@ticketIdUpdate", ticketId);
					cursor->Parameters->AddWithValue("@tecnicoId", tecnicoId);
					int rowsAffectedTicket = cursor->ExecuteNonQuery();

					if (rowsAffectedTicket > 0)
					{
						// Registrar la falla del técnico que marcó el ticket como resuelto
						cursor->CommandText = "UPDATE usuarios SET fallas = fallas + 1 WHERE dni = @dni";
						cursor->Parameters->AddWithValue("@dni", tecnicoAnteriorId);
						int rowsAffectedFalla = cursor->ExecuteNonQuery();
						 

						if (rowsAffectedFalla > 0)
						{
							return true; // Ambas operaciones fueron exitosas
						}
						else
						{
							// Si no se pudo registrar la falla, revertimos el estado del ticket
							MessageBox::Show("Error al registrar la falla en el técnico.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
						/*	cursor->CommandText = "UPDATE tickets SET estado = 'Resuelto', reabierto = 0, tecnico_id = @tecnicoAnteriorId WHERE N_Ticket = @ticketId";
							cursor->Parameters->Clear();
							cursor->Parameters->AddWithValue("@ticketId", ticketId);
							cursor->Parameters->AddWithValue("@tecnicoAnteriorId", tecnicoAnteriorId);
							cursor->ExecuteNonQuery();
							return false;*/
						}
					}
					else
					{
						MessageBox::Show("Error al actualizar el estado del ticket.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
						return false;
					}
				}
				else
				{
					MessageBox::Show("No se encontró el ticket.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return false;
				}
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Error al reabrir el ticket: " + ex->Message);
				return false;
			}
			finally
			{
				if (connection->State == ConnectionState::Open)
				{
					connection->Close();
				}
			}
		}

			
		
		
