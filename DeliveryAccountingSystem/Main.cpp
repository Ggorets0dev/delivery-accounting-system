#include "Main.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::OleDb;

[STAThread]
int main(array<String^>^ arg)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	DeliveryAccountingSystem::Main main_form;
	Application::Run(% main_form);
}

System::Void DeliveryAccountingSystem::Main::button_load_Click(System::Object^ sender, System::EventArgs^ e)
{
	dataGridView1->Rows->Clear();

	String^ connection_specs = "provider=Microsoft.Jet.OLEDB.4.0;Data Source = C:\\Users\\gores\\Desktop\\lera_data\\DeliveryAccounting.mdb";
	OleDbConnection^ db_connection = gcnew OleDbConnection(connection_specs);

	db_connection->Open();
	String^ query = "SELECT * FROM [Товары]";
	OleDbCommand^ db_command = gcnew OleDbCommand(query, db_connection);
	OleDbDataReader^ db_reader = db_command->ExecuteReader();

	if (db_reader->HasRows)
	{
		while (db_reader->Read())
			dataGridView1->Rows->Add(db_reader["Код"], db_reader["Наименование"], db_reader["Категория"], db_reader["Транспортное средство"], db_reader["Ранняя дата доставки"], db_reader["Поздняя дата доставки"], db_reader["Доставлен"]);
	}
	else
	{
		MessageBox::Show("Не удалось прочитать данные!", "Ошибка");
	}

	db_reader->Close();
	db_connection->Close();

	return System::Void();
}

System::Void DeliveryAccountingSystem::Main::button_add_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
