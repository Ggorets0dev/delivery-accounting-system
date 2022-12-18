#include "Main.h"
#include "Models.h"

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

bool areFieldsFilled(DataGridView^ grid_view, int index)
{
	return grid_view->Rows[index]->Cells[0]->Value != nullptr &&
		grid_view->Rows[index]->Cells[1]->Value != nullptr &&
		grid_view->Rows[index]->Cells[2]->Value != nullptr &&
		grid_view->Rows[index]->Cells[3]->Value != nullptr &&
		grid_view->Rows[index]->Cells[4]->Value != nullptr &&
		grid_view->Rows[index]->Cells[5]->Value != nullptr;
}

OleDbConnection^ createConnection(String^ path)
{
	String^ connection_specs = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=" + path;
	OleDbConnection^ db_connection = gcnew OleDbConnection(connection_specs);
	return db_connection;
}

bool findInDb(String^ db_path, String^ search, String^ column, DataGridView^ grid_view)
{
	bool status;

	if (db_path == "" || !IO::File::Exists(db_path))
	{
		MessageBox::Show("Не удалось найти базу данных!", "Ошибка");
		grid_view->Rows->Clear();
		return false;
	}

	if (search == "")
	{
		MessageBox::Show("Поле поиска не заполнено!", "Ошибка");
		return false;
	}

	OleDbConnection^ db_connection = createConnection(db_path);

	db_connection->Open();
	String^ query = "SELECT * FROM Товары WHERE [" + column + "]= '" + search + "'";
	OleDbCommand^ db_command = gcnew OleDbCommand(query, db_connection);
	OleDbDataReader^ db_reader = db_command->ExecuteReader();

	if (db_reader->HasRows)
	{
		while (db_reader->Read())
			grid_view->Rows->Add(db_reader["Код"], db_reader["Наименование"], db_reader["Категория"], db_reader["Транспортное средство"], db_reader["Ранняя дата доставки"], db_reader["Поздняя дата доставки"], db_reader["Доставлен"]);
		
		status = true;
	}
	else
	{
		status = false;
	}

	db_reader->Close();
	db_connection->Close();

	return status;
}

System::Void DeliveryAccountingSystem::Main::button_load_Click(System::Object^ sender, System::EventArgs^ e)
{
	dataGridView_Database->Rows->Clear();

	String^ db_path = textBox_db_path->Text;

	if (textBox_db_path->Text == "" || !IO::File::Exists(db_path))
	{
		MessageBox::Show("Не удалось найти базу данных!", "Ошибка");
		dataGridView_Database->Rows->Clear();
		return;
	}

	OleDbConnection^ db_connection = createConnection(db_path);

	db_connection->Open();
	String^ query = "SELECT * FROM Товары";
	OleDbCommand^ db_command = gcnew OleDbCommand(query, db_connection);
	OleDbDataReader^ db_reader = db_command->ExecuteReader();

	if (db_reader->HasRows)
	{
		while (db_reader->Read())
			dataGridView_Database->Rows->Add(db_reader["Код"], db_reader["Наименование"], db_reader["Категория"], db_reader["Транспортное средство"], db_reader["Ранняя дата доставки"], db_reader["Поздняя дата доставки"], db_reader["Доставлен"]);
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
	String^ db_path = textBox_db_path->Text;

	if (textBox_db_path->Text == "" || !IO::File::Exists(db_path))
	{
		MessageBox::Show("Не удалось найти базу данных!", "Ошибка");
		dataGridView_Database->Rows->Clear();
		return;
	}

	if (dataGridView_Database->SelectedRows->Count != 1) 
	{
		MessageBox::Show("Строка не выбрана!", "Ошибка");
		return;
	}

	int index = dataGridView_Database->SelectedRows[0]->Index;

	if (!areFieldsFilled(dataGridView_Database, index)) 
	{
		MessageBox::Show("Не все данные были введены!", "Ошибка");
		return;
	}

	Record record;

	record.code = Int32::Parse(dataGridView_Database->Rows[index]->Cells[0]->Value->ToString());
	record.title = dataGridView_Database->Rows[index]->Cells[1]->Value->ToString();
	record.category = dataGridView_Database->Rows[index]->Cells[2]->Value->ToString();
	record.transport = dataGridView_Database->Rows[index]->Cells[3]->Value->ToString();
	record.early_delivery_date = dataGridView_Database->Rows[index]->Cells[4]->Value->ToString()->Replace(".", "-");
	record.late_delivery_date = dataGridView_Database->Rows[index]->Cells[5]->Value->ToString()->Replace(".", "-");
	record.delivered = dataGridView_Database->Rows[index]->Cells[6]->Value != nullptr;

	OleDbConnection^ db_connection = createConnection(db_path);

	db_connection->Open();
	String^ query = "INSERT INTO Товары VALUES (" + record.code + ",'" + record.title + "','" + record.category + "','" + record.transport + "',#" + record.early_delivery_date + "#,#" + record.late_delivery_date +"#," + record.delivered->ToString() + ")";
	OleDbCommand^ db_command = gcnew OleDbCommand(query, db_connection);

	if (db_command->ExecuteNonQuery() == 1)
		MessageBox::Show("Данные успешно внесены!", "Успех");
	else
		MessageBox::Show("Не удалось внести данные!", "Ошибка");
	
	db_connection->Close();

	return System::Void();
}

System::Void DeliveryAccountingSystem::Main::button_edit_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ db_path = textBox_db_path->Text;

	if (textBox_db_path->Text == "" || !IO::File::Exists(db_path))
	{
		MessageBox::Show("Не удалось найти базу данных!", "Ошибка");
		dataGridView_Database->Rows->Clear();
		return;
	}

	if (dataGridView_Database->SelectedRows->Count != 1) 
	{
		MessageBox::Show("Строка не выбрана!", "Ошибка");
		return;
	}

	int index = dataGridView_Database->SelectedRows[0]->Index;

	if (!areFieldsFilled(dataGridView_Database, index))
	{
		MessageBox::Show("Не все данные были введены!", "Ошибка");
		return;
	}

	Record record;

	record.code = Int32::Parse(dataGridView_Database->Rows[index]->Cells[0]->Value->ToString());
	record.title = dataGridView_Database->Rows[index]->Cells[1]->Value->ToString();
	record.category = dataGridView_Database->Rows[index]->Cells[2]->Value->ToString();
	record.transport = dataGridView_Database->Rows[index]->Cells[3]->Value->ToString();
	record.early_delivery_date = dataGridView_Database->Rows[index]->Cells[4]->Value->ToString()->Replace(".", "-");
	record.late_delivery_date = dataGridView_Database->Rows[index]->Cells[5]->Value->ToString()->Replace(".", "-");
	record.delivered = safe_cast<Boolean^>(dataGridView_Database->Rows[index]->Cells[6]->Value);

	OleDbConnection^ db_connection = createConnection(db_path);

	db_connection->Open();
	String^ query = "UPDATE Товары SET Наименование='" + record.title + "', Категория='" + record.category + "', [Транспортное средство]='" + record.transport + "', [Ранняя дата доставки]=#" + record.early_delivery_date + "#, [Поздняя дата доставки]=#" + record.late_delivery_date + "#, Доставлен=" + record.delivered->ToString() + " WHERE Код= " + record.code;
	OleDbCommand^ db_command = gcnew OleDbCommand(query, db_connection);

	if (db_command->ExecuteNonQuery() == 1)
		MessageBox::Show("Данные успешно внесены!", "Успех");
	else
		MessageBox::Show("Не удалось внести данные!", "Ошибка");

	db_connection->Close();

	return System::Void();
}

System::Void DeliveryAccountingSystem::Main::button_delete_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ db_path = textBox_db_path->Text;

	if (textBox_db_path->Text == "" || !IO::File::Exists(db_path))
	{
		MessageBox::Show("Не удалось найти базу данных!", "Ошибка");
		dataGridView_Database->Rows->Clear();
		return;
	}

	if (dataGridView_Database->SelectedRows->Count != 1) 
	{
		MessageBox::Show("Строка не выбрана!", "Ошибка");
		return;
	}

	int index = dataGridView_Database->SelectedRows[0]->Index;

	if (dataGridView_Database->Rows[index]->Cells[0]->Value == nullptr)
	{
		MessageBox::Show("Код недоступен!", "Ошибка");
		return;
	}

	int code = Int32::Parse(dataGridView_Database->Rows[index]->Cells[0]->Value->ToString());

	OleDbConnection^ db_connection = createConnection(db_path);

	db_connection->Open();
	String^ query = "DELETE FROM Товары WHERE Код= " + code.ToString();
	OleDbCommand^ db_command = gcnew OleDbCommand(query, db_connection);

	if (db_command->ExecuteNonQuery() == 1)
	{
		dataGridView_Database->Rows->RemoveAt(index);
		MessageBox::Show("Запись успешно удалена!", "Успех");
	}
	else 
	{
		MessageBox::Show("Не удалось удалить запись!", "Ошибка");
		dataGridView_Database->Rows->RemoveAt(index);
	}

	db_connection->Close();

	return System::Void();
}

System::Void DeliveryAccountingSystem::Main::button_find_transport_Click(System::Object^ sender, System::EventArgs^ e)
{
	dataGridView_Database->Rows->Clear();
	
	if (findInDb(textBox_db_path->Text, textBox_transport_search->Text, "Транспортное средство", dataGridView_Database))
		MessageBox::Show("Запрос выполнен!", "Успех");
	else
		MessageBox::Show("Не удалось найти данные!", "Ошибка");

	return System::Void();
}

System::Void DeliveryAccountingSystem::Main::button_find_category_Click(System::Object^ sender, System::EventArgs^ e)
{
	dataGridView_Database->Rows->Clear();

	if (findInDb(textBox_db_path->Text, textBox_category_search->Text, "Категория", dataGridView_Database))
		MessageBox::Show("Запрос выполнен!", "Успех");
	else
		MessageBox::Show("Не удалось найти данные!", "Ошибка");

	return System::Void();
}