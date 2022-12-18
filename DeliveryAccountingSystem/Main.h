#pragma once

namespace DeliveryAccountingSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView_Database;
	protected:

	protected:

	private: System::Windows::Forms::GroupBox^ group_operations;

	private: System::Windows::Forms::Button^ button_load;
	private: System::Windows::Forms::Button^ button_add;
	private: System::Windows::Forms::Button^ button_edit;
	private: System::Windows::Forms::Button^ button_delete;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Code;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Title;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Category;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Transport;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ EarlyDeliveryDate;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ LateDeliveryDate;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^ Delivered;
	private: System::Windows::Forms::TextBox^ textBox_db_path;

	private: System::Windows::Forms::Label^ label_db_path;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox_transport_search;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox_category_search;

	private: System::Windows::Forms::Button^ button_find_transport;
	private: System::Windows::Forms::Button^ button_find_category;



















	protected:


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView_Database = (gcnew System::Windows::Forms::DataGridView());
			this->Code = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Title = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Category = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Transport = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->EarlyDeliveryDate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->LateDeliveryDate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Delivered = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->group_operations = (gcnew System::Windows::Forms::GroupBox());
			this->button_delete = (gcnew System::Windows::Forms::Button());
			this->button_add = (gcnew System::Windows::Forms::Button());
			this->button_edit = (gcnew System::Windows::Forms::Button());
			this->button_load = (gcnew System::Windows::Forms::Button());
			this->textBox_db_path = (gcnew System::Windows::Forms::TextBox());
			this->label_db_path = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox_transport_search = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox_category_search = (gcnew System::Windows::Forms::TextBox());
			this->button_find_transport = (gcnew System::Windows::Forms::Button());
			this->button_find_category = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Database))->BeginInit();
			this->group_operations->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView_Database
			// 
			this->dataGridView_Database->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_Database->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->Code,
					this->Title, this->Category, this->Transport, this->EarlyDeliveryDate, this->LateDeliveryDate, this->Delivered
			});
			this->dataGridView_Database->Location = System::Drawing::Point(24, 155);
			this->dataGridView_Database->Name = L"dataGridView_Database";
			this->dataGridView_Database->Size = System::Drawing::Size(743, 313);
			this->dataGridView_Database->TabIndex = 0;
			// 
			// Code
			// 
			this->Code->HeaderText = L"Код";
			this->Code->Name = L"Code";
			// 
			// Title
			// 
			this->Title->HeaderText = L"Наименование";
			this->Title->Name = L"Title";
			// 
			// Category
			// 
			this->Category->HeaderText = L"Категория";
			this->Category->Name = L"Category";
			// 
			// Transport
			// 
			this->Transport->HeaderText = L"Транспортное средство";
			this->Transport->Name = L"Transport";
			// 
			// EarlyDeliveryDate
			// 
			this->EarlyDeliveryDate->HeaderText = L"Ранняя дата доставки";
			this->EarlyDeliveryDate->Name = L"EarlyDeliveryDate";
			// 
			// LateDeliveryDate
			// 
			this->LateDeliveryDate->HeaderText = L"Поздняя дата доставки";
			this->LateDeliveryDate->Name = L"LateDeliveryDate";
			// 
			// Delivered
			// 
			this->Delivered->HeaderText = L"Доставлен";
			this->Delivered->Name = L"Delivered";
			// 
			// group_operations
			// 
			this->group_operations->Controls->Add(this->button_delete);
			this->group_operations->Controls->Add(this->button_add);
			this->group_operations->Controls->Add(this->button_edit);
			this->group_operations->Controls->Add(this->button_load);
			this->group_operations->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->group_operations->Location = System::Drawing::Point(801, 155);
			this->group_operations->Name = L"group_operations";
			this->group_operations->Size = System::Drawing::Size(200, 313);
			this->group_operations->TabIndex = 1;
			this->group_operations->TabStop = false;
			this->group_operations->Text = L"Операции";
			// 
			// button_delete
			// 
			this->button_delete->Location = System::Drawing::Point(46, 220);
			this->button_delete->Name = L"button_delete";
			this->button_delete->Size = System::Drawing::Size(123, 43);
			this->button_delete->TabIndex = 3;
			this->button_delete->Text = L"Удалить";
			this->button_delete->UseVisualStyleBackColor = true;
			this->button_delete->Click += gcnew System::EventHandler(this, &Main::button_delete_Click);
			// 
			// button_add
			// 
			this->button_add->Location = System::Drawing::Point(46, 109);
			this->button_add->Name = L"button_add";
			this->button_add->Size = System::Drawing::Size(123, 43);
			this->button_add->TabIndex = 1;
			this->button_add->Text = L"Добавить";
			this->button_add->UseVisualStyleBackColor = true;
			this->button_add->Click += gcnew System::EventHandler(this, &Main::button_add_Click);
			// 
			// button_edit
			// 
			this->button_edit->Location = System::Drawing::Point(46, 164);
			this->button_edit->Name = L"button_edit";
			this->button_edit->Size = System::Drawing::Size(123, 43);
			this->button_edit->TabIndex = 2;
			this->button_edit->Text = L"Изменить";
			this->button_edit->UseVisualStyleBackColor = true;
			this->button_edit->Click += gcnew System::EventHandler(this, &Main::button_edit_Click);
			// 
			// button_load
			// 
			this->button_load->Location = System::Drawing::Point(46, 53);
			this->button_load->Name = L"button_load";
			this->button_load->Size = System::Drawing::Size(123, 43);
			this->button_load->TabIndex = 0;
			this->button_load->Text = L"Загрузить";
			this->button_load->UseVisualStyleBackColor = true;
			this->button_load->Click += gcnew System::EventHandler(this, &Main::button_load_Click);
			// 
			// textBox_db_path
			// 
			this->textBox_db_path->Location = System::Drawing::Point(110, 25);
			this->textBox_db_path->Name = L"textBox_db_path";
			this->textBox_db_path->Size = System::Drawing::Size(294, 20);
			this->textBox_db_path->TabIndex = 2;
			// 
			// label_db_path
			// 
			this->label_db_path->AutoSize = true;
			this->label_db_path->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_db_path->Location = System::Drawing::Point(21, 25);
			this->label_db_path->Name = L"label_db_path";
			this->label_db_path->Size = System::Drawing::Size(83, 18);
			this->label_db_path->TabIndex = 3;
			this->label_db_path->Text = L"Путь к БД:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(21, 72);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(254, 18);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Поиск по транспортному средству:";
			// 
			// textBox_transport_search
			// 
			this->textBox_transport_search->Location = System::Drawing::Point(281, 72);
			this->textBox_transport_search->Name = L"textBox_transport_search";
			this->textBox_transport_search->Size = System::Drawing::Size(123, 20);
			this->textBox_transport_search->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(21, 104);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(151, 18);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Поиск по категории:";
			// 
			// textBox_category_search
			// 
			this->textBox_category_search->Location = System::Drawing::Point(178, 105);
			this->textBox_category_search->Name = L"textBox_category_search";
			this->textBox_category_search->Size = System::Drawing::Size(123, 20);
			this->textBox_category_search->TabIndex = 7;
			// 
			// button_find_transport
			// 
			this->button_find_transport->Location = System::Drawing::Point(410, 72);
			this->button_find_transport->Name = L"button_find_transport";
			this->button_find_transport->Size = System::Drawing::Size(77, 20);
			this->button_find_transport->TabIndex = 4;
			this->button_find_transport->Text = L"Найти";
			this->button_find_transport->UseVisualStyleBackColor = true;
			this->button_find_transport->Click += gcnew System::EventHandler(this, &Main::button_find_transport_Click);
			// 
			// button_find_category
			// 
			this->button_find_category->Location = System::Drawing::Point(307, 105);
			this->button_find_category->Name = L"button_find_category";
			this->button_find_category->Size = System::Drawing::Size(77, 20);
			this->button_find_category->TabIndex = 8;
			this->button_find_category->Text = L"Найти";
			this->button_find_category->UseVisualStyleBackColor = true;
			this->button_find_category->Click += gcnew System::EventHandler(this, &Main::button_find_category_Click);
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1013, 486);
			this->Controls->Add(this->button_find_category);
			this->Controls->Add(this->button_find_transport);
			this->Controls->Add(this->textBox_category_search);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox_transport_search);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label_db_path);
			this->Controls->Add(this->textBox_db_path);
			this->Controls->Add(this->group_operations);
			this->Controls->Add(this->dataGridView_Database);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1029, 525);
			this->MinimumSize = System::Drawing::Size(1029, 525);
			this->Name = L"Main";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Информационно-справочная система учета доставки грузов";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Database))->EndInit();
			this->group_operations->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_load_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_add_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_delete_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_edit_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_find_transport_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_find_category_Click(System::Object^ sender, System::EventArgs^ e);
};
}

