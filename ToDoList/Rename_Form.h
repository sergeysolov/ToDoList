#pragma once

namespace ToDoList {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Rename_Form
	/// </summary>
	public ref class Rename_Form : public System::Windows::Forms::Form
	{
	public:
		Rename_Form(void)
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
		~Rename_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_Remove;
	protected:
	private: System::Windows::Forms::Button^ Cancel_button;
	private: System::Windows::Forms::Button^ OK_button;
	public: System::Windows::Forms::TextBox^ textBox1;
	private:
	private: System::Windows::Forms::Label^ label2;
	public:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Rename_Form::typeid));
			this->button_Remove = (gcnew System::Windows::Forms::Button());
			this->Cancel_button = (gcnew System::Windows::Forms::Button());
			this->OK_button = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button_Remove
			// 
			this->button_Remove->BackColor = System::Drawing::SystemColors::Window;
			this->button_Remove->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_Remove.BackgroundImage")));
			this->button_Remove->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button_Remove->Location = System::Drawing::Point(263, 102);
			this->button_Remove->Name = L"button_Remove";
			this->button_Remove->Size = System::Drawing::Size(41, 34);
			this->button_Remove->TabIndex = 16;
			this->button_Remove->UseVisualStyleBackColor = false;
			this->button_Remove->Click += gcnew System::EventHandler(this, &Rename_Form::button_Remove_Click);
			// 
			// Cancel_button
			// 
			this->Cancel_button->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Cancel_button->Location = System::Drawing::Point(154, 178);
			this->Cancel_button->Name = L"Cancel_button";
			this->Cancel_button->Size = System::Drawing::Size(119, 41);
			this->Cancel_button->TabIndex = 15;
			this->Cancel_button->Text = L"Отмена";
			this->Cancel_button->UseVisualStyleBackColor = true;
			this->Cancel_button->Click += gcnew System::EventHandler(this, &Rename_Form::Cancel_button_Click);
			// 
			// OK_button
			// 
			this->OK_button->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->OK_button->Location = System::Drawing::Point(16, 178);
			this->OK_button->Name = L"OK_button";
			this->OK_button->Size = System::Drawing::Size(119, 41);
			this->OK_button->TabIndex = 14;
			this->OK_button->Text = L"OK";
			this->OK_button->UseVisualStyleBackColor = true;
			this->OK_button->Click += gcnew System::EventHandler(this, &Rename_Form::OK_button_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(16, 104);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(248, 30);
			this->textBox1->TabIndex = 13;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft New Tai Lue", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 48);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(158, 22);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Название списка:";
			// 
			// Rename_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(315, 255);
			this->Controls->Add(this->button_Remove);
			this->Controls->Add(this->Cancel_button);
			this->Controls->Add(this->OK_button);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->Name = L"Rename_Form";
			this->ShowIcon = false;
			this->Text = L"Создание списка";
			this->TransparencyKey = System::Drawing::Color::Yellow;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Rename_Form::Rename_Form_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_Remove_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		textBox1->Clear();
	}
private: System::Void OK_button_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void Cancel_button_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void Rename_Form_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
};
}
