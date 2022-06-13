#pragma once

using namespace System::Data;
using namespace System::Data::SqlClient;

ref class DataBase
{
public:
	// Data Source=D4SUCE;Initial Catalog=Hotel;Integrated Security=True
	SqlConnection^ connection = gcnew SqlConnection("Data Source=D4SUCE;Initial Catalog=Hotel;Integrated Security=true");

	void openConnection() {
		if (connection->State == ConnectionState::Closed)
			connection->Open();
	}

	void closeConnection() {
		if (connection->State == ConnectionState::Open)
			connection->Close();
	}

	SqlConnection^ getConnection() {
		return connection;
	}
};

