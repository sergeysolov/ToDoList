#pragma once
#include "MyForm.h"
#include <cstdio>
namespace ToDoList {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	
	public ref class Edit_Form : public System::Windows::Forms::Form
	{		
	public:
	
		Edit_Form()
		{
			InitializeComponent();
		}
		
	protected:
		
		~Edit_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ OK_button;
	private: System::Windows::Forms::Button^ Cancel_button;
	public: System::Windows::Forms::Label^ Current_Name_label;
	private: System::Windows::Forms::Button^ button_Remove;
	public:
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Edit_Form::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->OK_button = (gcnew System::Windows::Forms::Button());
			this->Cancel_button = (gcnew System::Windows::Forms::Button());
			this->Current_Name_label = (gcnew System::Windows::Forms::Label());
			this->button_Remove = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft New Tai Lue", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(25, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(235, 22);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Текущее название списка:";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(30, 152);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(230, 30);
			this->textBox1->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft New Tai Lue", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(25, 123);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(151, 22);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Новое название:";
			// 
			// OK_button
			// 
			this->OK_button->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->OK_button->Location = System::Drawing::Point(30, 239);
			this->OK_button->Name = L"OK_button";
			this->OK_button->Size = System::Drawing::Size(119, 41);
			this->OK_button->TabIndex = 3;
			this->OK_button->Text = L"OK";
			this->OK_button->UseVisualStyleBackColor = true;
			this->OK_button->Click += gcnew System::EventHandler(this, &Edit_Form::OK_button_Click);
			// 
			// Cancel_button
			// 
			this->Cancel_button->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Cancel_button->Location = System::Drawing::Point(173, 239);
			this->Cancel_button->Name = L"Cancel_button";
			this->Cancel_button->Size = System::Drawing::Size(119, 41);
			this->Cancel_button->TabIndex = 4;
			this->Cancel_button->Text = L"Отмена";
			this->Cancel_button->UseVisualStyleBackColor = true;
			this->Cancel_button->Click += gcnew System::EventHandler(this, &Edit_Form::Cancel_button_Click);
			// 
			// Current_Name_label
			// 
			this->Current_Name_label->AutoSize = true;
			this->Current_Name_label->Font = (gcnew System::Drawing::Font(L"Microsoft New Tai Lue", 11.5F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Current_Name_label->Location = System::Drawing::Point(25, 66);
			this->Current_Name_label->Name = L"Current_Name_label";
			this->Current_Name_label->Size = System::Drawing::Size(67, 26);
			this->Current_Name_label->TabIndex = 5;
			this->Current_Name_label->Text = L"Метка:";
			// 
			// button_Remove
			// 
			this->button_Remove->BackColor = System::Drawing::SystemColors::Window;
			this->button_Remove->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_Remove.BackgroundImage")));
			this->button_Remove->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button_Remove->Location = System::Drawing::Point(259, 151);
			this->button_Remove->Name = L"button_Remove";
			this->button_Remove->Size = System::Drawing::Size(41, 34);
			this->button_Remove->TabIndex = 11;
			this->button_Remove->UseVisualStyleBackColor = false;
			this->button_Remove->Click += gcnew System::EventHandler(this, &Edit_Form::button_Remove_Click);
			// 
			// Edit_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(337, 316);
			this->Controls->Add(this->button_Remove);
			this->Controls->Add(this->Current_Name_label);
			this->Controls->Add(this->Cancel_button);
			this->Controls->Add(this->OK_button);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->Name = L"Edit_Form";
			this->Text = L"Переименование";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Edit_Form::Edit_Form_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		
#pragma endregion
		
	private: System::Void Cancel_button_Click(System::Object^ sender, System::EventArgs^ e);
	
	private: System::Void Edit_Form_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);

	private: System::Void OK_button_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void button_Remove_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		textBox1->Clear();
	}
};
}
