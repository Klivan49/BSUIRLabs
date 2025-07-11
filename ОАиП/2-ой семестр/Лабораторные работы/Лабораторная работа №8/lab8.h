#pragma once

namespace Лабораторнаяработа8 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	static String^ InfixToPostfix(String^ infix);
	static String^ PostfixToInfix(String^ postfix);
	static double EvalPostfix(String^ postfix, array<double>^ vars);

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ infixTextBox;
	private: System::Windows::Forms::TextBox^ postfixTextBox;
	protected:

	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ resultTextBox;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ NormToKurwa;
	private: System::Windows::Forms::Button^ KurwaToNorm;


	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ result;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Variables;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Values;














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
			this->infixTextBox = (gcnew System::Windows::Forms::TextBox());
			this->postfixTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->resultTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->NormToKurwa = (gcnew System::Windows::Forms::Button());
			this->KurwaToNorm = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->result = (gcnew System::Windows::Forms::Button());
			this->Variables = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Values = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// infixTextBox
			// 
			this->infixTextBox->Location = System::Drawing::Point(505, 136);
			this->infixTextBox->Name = L"infixTextBox";
			this->infixTextBox->Size = System::Drawing::Size(469, 31);
			this->infixTextBox->TabIndex = 0;
			// 
			// postfixTextBox
			// 
			this->postfixTextBox->Location = System::Drawing::Point(505, 275);
			this->postfixTextBox->Name = L"postfixTextBox";
			this->postfixTextBox->Size = System::Drawing::Size(469, 31);
			this->postfixTextBox->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(500, 108);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(256, 25);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Нормальное выражение";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(500, 247);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(145, 25);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Bobra-запись";
			// 
			// resultTextBox
			// 
			this->resultTextBox->Location = System::Drawing::Point(505, 415);
			this->resultTextBox->Name = L"resultTextBox";
			this->resultTextBox->Size = System::Drawing::Size(469, 31);
			this->resultTextBox->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(500, 387);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(115, 25);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Результат";
			// 
			// NormToKurwa
			// 
			this->NormToKurwa->Location = System::Drawing::Point(1088, 112);
			this->NormToKurwa->Name = L"NormToKurwa";
			this->NormToKurwa->Size = System::Drawing::Size(230, 79);
			this->NormToKurwa->TabIndex = 6;
			this->NormToKurwa->Text = L"Перевод в ОПЗ";
			this->NormToKurwa->UseVisualStyleBackColor = true;
			this->NormToKurwa->Click += gcnew System::EventHandler(this, &MyForm::NormToKurwa_Click);
			// 
			// KurwaToNorm
			// 
			this->KurwaToNorm->Location = System::Drawing::Point(1088, 251);
			this->KurwaToNorm->Name = L"KurwaToNorm";
			this->KurwaToNorm->Size = System::Drawing::Size(230, 79);
			this->KurwaToNorm->TabIndex = 7;
			this->KurwaToNorm->Text = L"Перевод в обычную";
			this->KurwaToNorm->UseVisualStyleBackColor = true;
			this->KurwaToNorm->Click += gcnew System::EventHandler(this, &MyForm::KurwaToNorm_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToOrderColumns = true;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->Variables,
					this->Values
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 36);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 82;
			this->dataGridView1->RowTemplate->Height = 33;
			this->dataGridView1->Size = System::Drawing::Size(411, 548);
			this->dataGridView1->TabIndex = 8;
			// 
			// result
			// 
			this->result->Location = System::Drawing::Point(1088, 391);
			this->result->Name = L"result";
			this->result->Size = System::Drawing::Size(230, 79);
			this->result->TabIndex = 9;
			this->result->Text = L"Результат";
			this->result->UseVisualStyleBackColor = true;
			this->result->Click += gcnew System::EventHandler(this, &MyForm::result_Click);
			// 
			// Variables
			// 
			this->Variables->FillWeight = 10;
			this->Variables->HeaderText = L"Переменные";
			this->Variables->MinimumWidth = 10;
			this->Variables->Name = L"Variables";
			this->Variables->ReadOnly = true;
			// 
			// Values
			// 
			this->Values->HeaderText = L"Значения";
			this->Values->MinimumWidth = 10;
			this->Values->Name = L"Values";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1359, 621);
			this->Controls->Add(this->result);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->KurwaToNorm);
			this->Controls->Add(this->NormToKurwa);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->resultTextBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->postfixTextBox);
			this->Controls->Add(this->infixTextBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Bober Konverter";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion
	private: System::Void NormToKurwa_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		//Читаем инфикс-строку
		String^ expr = this->infixTextBox->Text;

		//Собираем множество уникальных букв a–z
		auto varsSet = gcnew System::Collections::Generic::SortedSet<Char>();
		for each (Char c in expr) {
			if (Char::IsLetter(c)) {
				varsSet->Add(Char::ToLower(c));
			}
		}
		//Перестраиваем таблицу: очищаем и добавляем ровно эти переменные
		dataGridView1->Rows->Clear();
		for each (Char v in varsSet) {
			//в столбце «Значения» оставляем пустое поле
			dataGridView1->Rows->Add(v.ToString(), String::Empty);
		}
		String^ infix = this->infixTextBox->Text;
		String^ postfix = InfixToPostfix(infix);
		this->postfixTextBox->Text = postfix;
	}
	private: System::Void KurwaToNorm_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		String^ postfix = this->postfixTextBox->Text;
		String^ infix = PostfixToInfix(postfix);
		this->infixTextBox->Text = infix;
	}
	private: System::Void result_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		// 1) Берём постфикс-выражение
		String^ postfix = postfixTextBox->Text;
		if (String::IsNullOrWhiteSpace(postfix)) {
			MessageBox::Show("Сначала переведите выражение в ОПЗ");
			return;
		}

		// 2) Инициализируем массив значений для a..z
		array<double>^ varsManaged = gcnew array<double>(26);
		for (int i = 0; i < 26; ++i)
			varsManaged[i] = 0.0;

		// 3) Считываем из таблицы
		for each (DataGridViewRow ^ row in dataGridView1->Rows) {
			if (row->IsNewRow) continue;  // на всякий случай
			// Переменная (буква) из первой колонки
			String^ varName = Convert::ToString(row->Cells["Variables"]->Value);
			if (String::IsNullOrEmpty(varName)) continue;
			wchar_t c = varName[0];
			int idx = Char::ToLower(c) - 'a';
			if (idx < 0 || idx >= 26) {
				MessageBox::Show("Некорректная переменная: " + varName);
				return;
			}

			// Значение из второй колонки
			Object^ cell = row->Cells["Values"]->Value;
			if (cell == nullptr || String::IsNullOrWhiteSpace(cell->ToString())) {
				MessageBox::Show("Не задано значение для переменной " + varName);
				return;
			}
			double d;
			if (!Double::TryParse(cell->ToString()->Replace('.', ','), d)) {
				MessageBox::Show("Неверный формат числа для переменной " + varName);
				return;
			}
			varsManaged[idx] = d;
		}

		// 4) Собираем нативный массив и вызываем EvalPostfix
		//    (или можно напрямую передать varsManaged, если ваша функция так принимает)
		try {
			double result = EvalPostfix(postfix, varsManaged);
			resultTextBox->Text = result.ToString("G");
		}
		catch (Exception^ ex) {
			MessageBox::Show("Ошибка при вычислении:\n" + ex->Message);
		}
	}
};
}
