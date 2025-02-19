#pragma once

double power(double x, int n);

namespace Form1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::Button^ mainBtn;
	private: System::Windows::Forms::Label^ xLabel;
	private: System::Windows::Forms::Label^ nLabel;
	private: System::Windows::Forms::TextBox^ xTextBox;
	private: System::Windows::Forms::TextBox^ nTextBox;
	protected:

	protected:





	private: System::Windows::Forms::Label^ resultLabel;


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
			this->mainBtn = (gcnew System::Windows::Forms::Button());
			this->xLabel = (gcnew System::Windows::Forms::Label());
			this->nLabel = (gcnew System::Windows::Forms::Label());
			this->xTextBox = (gcnew System::Windows::Forms::TextBox());
			this->nTextBox = (gcnew System::Windows::Forms::TextBox());
			this->resultLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// mainBtn
			// 
			this->mainBtn->Location = System::Drawing::Point(236, 368);
			this->mainBtn->Name = L"mainBtn";
			this->mainBtn->Size = System::Drawing::Size(289, 107);
			this->mainBtn->TabIndex = 0;
			this->mainBtn->Text = L"Рассчитать Y";
			this->mainBtn->UseVisualStyleBackColor = true;
			this->mainBtn->Click += gcnew System::EventHandler(this, &MyForm::mainBtn_Click);
			// 
			// xLabel
			// 
			this->xLabel->AutoSize = true;
			this->xLabel->Location = System::Drawing::Point(49, 68);
			this->xLabel->Name = L"xLabel";
			this->xLabel->Size = System::Drawing::Size(115, 25);
			this->xLabel->TabIndex = 1;
			this->xLabel->Text = L"Введите X";
			// 
			// nLabel
			// 
			this->nLabel->AutoSize = true;
			this->nLabel->Location = System::Drawing::Point(49, 145);
			this->nLabel->Name = L"nLabel";
			this->nLabel->Size = System::Drawing::Size(113, 25);
			this->nLabel->TabIndex = 2;
			this->nLabel->Text = L"Введите n";
			// 
			// xTextBox
			// 
			this->xTextBox->Location = System::Drawing::Point(454, 68);
			this->xTextBox->Name = L"xTextBox";
			this->xTextBox->Size = System::Drawing::Size(180, 31);
			this->xTextBox->TabIndex = 3;
			this->xTextBox->TextChanged += gcnew System::EventHandler(this, &MyForm::xTextBox_TextChanged);
			// 
			// nTextBox
			// 
			this->nTextBox->Location = System::Drawing::Point(454, 139);
			this->nTextBox->Name = L"nTextBox";
			this->nTextBox->Size = System::Drawing::Size(180, 31);
			this->nTextBox->TabIndex = 4;
			this->nTextBox->TextChanged += gcnew System::EventHandler(this, &MyForm::nTextBox_TextChanged);
			// 
			// resultLabel
			// 
			this->resultLabel->AutoSize = true;
			this->resultLabel->Location = System::Drawing::Point(49, 289);
			this->resultLabel->Name = L"resultLabel";
			this->resultLabel->Size = System::Drawing::Size(73, 25);
			this->resultLabel->TabIndex = 6;
			this->resultLabel->Text = L"Result";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(817, 533);
			this->Controls->Add(this->resultLabel);
			this->Controls->Add(this->nTextBox);
			this->Controls->Add(this->xTextBox);
			this->Controls->Add(this->nLabel);
			this->Controls->Add(this->xLabel);
			this->Controls->Add(this->mainBtn);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		#pragma endregion
		

		double x = 0, y = 0; 
		int n = 0;
		private: System::Void mainBtn_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (n > 0 && x > 0)
			{
				y = power(x, n);                
				this->resultLabel->Text = "Result: " + y;
			}
			else this->resultLabel->Text = "Вы чего-то не так ввели(или не ввели)";
			
		}
		private: System::Void xTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
		{
			TextBox^ textbox = safe_cast<TextBox^>(sender);
			if (xTextBox->Text->Trim() != "")
			{
				String^ input = textbox->Text->Replace('.', ',');
				try
				{
					x = Convert::ToDouble(input);
				}
				catch (FormatException^)
				{
					x = -1;
					this->resultLabel->Text = "Некорректный ввод";
				}
			}
		}

		private: System::Void nTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
		{
			TextBox^ textbox = safe_cast<TextBox^>(sender);
			if (nTextBox->Text->Trim() != "")
			{
				String^ input = textbox->Text->Replace('.', ',');
				try
				{
					n = Convert::ToDouble(input);
				}
				catch (FormatException^)
				{
					n = -1;
					this->resultLabel->Text = "Некорректный ввод";
				}
			}
		}
	};
}
