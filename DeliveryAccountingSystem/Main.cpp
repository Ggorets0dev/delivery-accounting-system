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

	String^ connection_specs = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=C:\\Users\\gores\\Desktop\\lera_data\\DeliveryAccounting.mdb";
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
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("Строка не выбрана!", "Ошибка");
		return;
	}

	int index = dataGridView1->SelectedRows[0]->Index;

	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[2]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[3]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[4]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[5]->Value == nullptr) {
		MessageBox::Show("Не все данные были введены!", "Ошибка");
		return;
	}

	Int32 code = Int32::Parse(dataGridView1->Rows[index]->Cells[0]->Value->ToString());
	String^ title = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ category = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ transport = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
	String^ early_delivery_date = dataGridView1->Rows[index]->Cells[4]->Value->ToString();
	String^ late_delivery_date = dataGridView1->Rows[index]->Cells[5]->Value->ToString();
	bool delivered = dataGridView1->Rows[index]->Cells[6]->Value != nullptr;

	String^ connection_specs = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=C:\\Users\\gores\\Desktop\\lera_data\\DeliveryAccounting.mdb";
	OleDbConnection^ db_connection = gcnew OleDbConnection(connection_specs);

	db_connection->Open();
	String^ query = "INSERT INTO [Товары] VALUES (" + code + ",'" + title + "','" + category + "','" + transport + "',#" + early_delivery_date + "#,#" + late_delivery_date +"#," + delivered.ToString() + ")";
	OleDbCommand^ db_comand = gcnew OleDbCommand(query, db_connection);

	if (db_comand->ExecuteNonQuery() == 1)
		MessageBox::Show("Данные успешно внесены!", "Успех");
	else
		MessageBox::Show("Не удалось внести данные!", "Ошибка");
	
	db_connection->Close();

	return System::Void();
}
