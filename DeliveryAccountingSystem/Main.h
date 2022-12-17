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
	private: System::Windows::Forms::DataGridView^ dataGridView1;
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
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label_db_path;

















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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label_db_path = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->group_operations->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->Code, this->Title,
					this->Category, this->Transport, this->EarlyDeliveryDate, this->LateDeliveryDate, this->Delivered
			});
			this->dataGridView1->Location = System::Drawing::Point(24, 104);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(743, 274);
			this->dataGridView1->TabIndex = 0;
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
			this->group_operations->Location = System::Drawing::Point(797, 104);
			this->group_operations->Name = L"group_operations";
			this->group_operations->Size = System::Drawing::Size(200, 274);
			this->group_operations->TabIndex = 1;
			this->group_operations->TabStop = false;
			this->group_operations->Text = L"Операции";
			// 
			// button_delete
			// 
			this->button_delete->Location = System::Drawing::Point(37, 209);
			this->button_delete->Name = L"button_delete";
			this->button_delete->Size = System::Drawing::Size(123, 43);
			this->button_delete->TabIndex = 3;
			this->button_delete->Text = L"Удалить";
			this->button_delete->UseVisualStyleBackColor = true;
			this->button_delete->Click += gcnew System::EventHandler(this, &Main::button_delete_Click);
			// 
			// button_add
			// 
			this->button_add->Location = System::Drawing::Point(37, 92);
			this->button_add->Name = L"button_add";
			this->button_add->Size = System::Drawing::Size(123, 43);
			this->button_add->TabIndex = 1;
			this->button_add->Text = L"Добавить";
			this->button_add->UseVisualStyleBackColor = true;
			this->button_add->Click += gcnew System::EventHandler(this, &Main::button_add_Click);
			// 
			// button_edit
			// 
			this->button_edit->Location = System::Drawing::Point(37, 151);
			this->button_edit->Name = L"button_edit";
			this->button_edit->Size = System::Drawing::Size(123, 43);
			this->button_edit->TabIndex = 2;
			this->button_edit->Text = L"Изменить";
			this->button_edit->UseVisualStyleBackColor = true;
			this->button_edit->Click += gcnew System::EventHandler(this, &Main::button_edit_Click);
			// 
			// button_load
			// 
			this->button_load->Location = System::Drawing::Point(37, 31);
			this->button_load->Name = L"button_load";
			this->button_load->Size = System::Drawing::Size(123, 43);
			this->button_load->TabIndex = 0;
			this->button_load->Text = L"Загрузить";
			this->button_load->UseVisualStyleBackColor = true;
			this->button_load->Click += gcnew System::EventHandler(this, &Main::button_load_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(110, 26);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(247, 20);
			this->textBox1->TabIndex = 2;
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
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1013, 400);
			this->Controls->Add(this->label_db_path);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->group_operations);
			this->Controls->Add(this->dataGridView1);
			this->MaximizeBox = false;
			this->Name = L"Main";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Информационно-справочная система учета доставки грузов";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->group_operations->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_load_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_add_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_delete_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_edit_Click(System::Object^ sender, System::EventArgs^ e);
};
}

