#pragma once
#include <list>
#include <string>
#include <fstream>
#include <vector>
#include <msclr\marshal_cppstd.h>
#include <algorithm>
#include <stdio.h>
#include "Edit_Form.h"
#include "Rename_Form.h"


std::vector<std::string> files;
std::fstream header_file;
const std::string name_header_file = "Head.txt";

std::list<std::string> data;
std::fstream file;
std::string current_filename = "Список";
bool EditMode = false;

std::vector<std::string>::iterator iterator_rename;
namespace ToDoList
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	Size initial_size_form;
	Size initial_size_list_box;
	Size initial_size_text_box;
	Size initial_size_title_list_box;
	Point UpButton_location;
	Point DownButton_location;
	Point DeleteButton_location;
	Point AddButton_location;
	Point EditButton_location;
	Point RemoveButton_location;
	Point ModeLabel_location;
	
	public ref class MyForm : public System::Windows::Forms::Form
	{

	public: static MyForm^ Main_Form;
	
		MyForm()
		{
			InitializeComponent();
			Main_Form = this;

			//Инициализация начальных размеров и позиций элементов
			initial_size_form = this->Size;
			initial_size_list_box = listBox1->Size;
			initial_size_text_box = textBox1->Size;
			initial_size_title_list_box = TitleListBox->Size;
			UpButton_location = Up_Button->Location;
			DownButton_location = Down_Button->Location;
			DeleteButton_location = button_list_box_delete->Location;
			AddButton_location = AddButton->Location;
			EditButton_location = button1->Location;
			RemoveButton_location = button_Remove->Location;
			ModeLabel_location = ModeLabel->Location;
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}	
		}
	private: System::Windows::Forms::ListBox^ listBox1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ AddButton;
	private: System::Windows::Forms::Button^ Up_Button;
	private: System::Windows::Forms::Button^ Down_Button;

	private: System::Windows::Forms::Button^ button_plus;



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button_Remove;
	public: System::Windows::Forms::Label^ label_current_list;
	private: System::Windows::Forms::Button^ button_delete;
	private: System::Windows::Forms::Button^ button_Edit_2;
	private: System::Windows::Forms::Button^ button_list_box_delete;
	public: System::Windows::Forms::ListBox^ TitleListBox;
	private: System::Windows::Forms::Button^ UpButton_forTitleBox;
	public:
	private: System::Windows::Forms::Button^ DownButton_forTitleBox;
	public: System::Windows::Forms::Label^ ModeLabel;
	private:


	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->AddButton = (gcnew System::Windows::Forms::Button());
			this->Up_Button = (gcnew System::Windows::Forms::Button());
			this->Down_Button = (gcnew System::Windows::Forms::Button());
			this->button_plus = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button_Remove = (gcnew System::Windows::Forms::Button());
			this->label_current_list = (gcnew System::Windows::Forms::Label());
			this->button_delete = (gcnew System::Windows::Forms::Button());
			this->button_Edit_2 = (gcnew System::Windows::Forms::Button());
			this->button_list_box_delete = (gcnew System::Windows::Forms::Button());
			this->TitleListBox = (gcnew System::Windows::Forms::ListBox());
			this->UpButton_forTitleBox = (gcnew System::Windows::Forms::Button());
			this->DownButton_forTitleBox = (gcnew System::Windows::Forms::Button());
			this->ModeLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Calibri", 13.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 27;
			this->listBox1->Location = System::Drawing::Point(258, 100);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(364, 486);
			this->listBox1->TabIndex = 0;
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(258, 45);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(380, 32);
			this->textBox1->TabIndex = 1;
			this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox1_KeyDown);
			// 
			// AddButton
			// 
			this->AddButton->BackColor = System::Drawing::SystemColors::Window;
			this->AddButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"AddButton.BackgroundImage")));
			this->AddButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->AddButton->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->AddButton->Location = System::Drawing::Point(638, 100);
			this->AddButton->Name = L"AddButton";
			this->AddButton->Size = System::Drawing::Size(50, 46);
			this->AddButton->TabIndex = 2;
			this->AddButton->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->AddButton->UseVisualStyleBackColor = false;
			this->AddButton->Click += gcnew System::EventHandler(this, &MyForm::AddButton_Click);
			this->AddButton->MouseHover += gcnew System::EventHandler(this, &MyForm::AddButton_MouseHover);
			// 
			// Up_Button
			// 
			this->Up_Button->AutoSize = true;
			this->Up_Button->BackColor = System::Drawing::SystemColors::Window;
			this->Up_Button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Up_Button.BackgroundImage")));
			this->Up_Button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Up_Button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Up_Button->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Up_Button->Location = System::Drawing::Point(638, 156);
			this->Up_Button->Name = L"Up_Button";
			this->Up_Button->Size = System::Drawing::Size(50, 46);
			this->Up_Button->TabIndex = 3;
			this->Up_Button->UseVisualStyleBackColor = false;
			this->Up_Button->Click += gcnew System::EventHandler(this, &MyForm::Up_Button_Click);
			this->Up_Button->MouseHover += gcnew System::EventHandler(this, &MyForm::Up_Button_MouseHover);
			// 
			// Down_Button
			// 
			this->Down_Button->BackColor = System::Drawing::SystemColors::Window;
			this->Down_Button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Down_Button.BackgroundImage")));
			this->Down_Button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Down_Button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Down_Button->Location = System::Drawing::Point(638, 212);
			this->Down_Button->Name = L"Down_Button";
			this->Down_Button->Size = System::Drawing::Size(50, 46);
			this->Down_Button->TabIndex = 4;
			this->Down_Button->UseVisualStyleBackColor = false;
			this->Down_Button->Click += gcnew System::EventHandler(this, &MyForm::Down_Button_Click);
			this->Down_Button->MouseHover += gcnew System::EventHandler(this, &MyForm::Down_Button_MouseHover);
			// 
			// button_plus
			// 
			this->button_plus->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button_plus->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_plus.BackgroundImage")));
			this->button_plus->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button_plus->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_plus->Location = System::Drawing::Point(12, 45);
			this->button_plus->Name = L"button_plus";
			this->button_plus->Size = System::Drawing::Size(40, 37);
			this->button_plus->TabIndex = 6;
			this->button_plus->UseVisualStyleBackColor = false;
			this->button_plus->Click += gcnew System::EventHandler(this, &MyForm::button_plus_Click);
			this->button_plus->MouseHover += gcnew System::EventHandler(this, &MyForm::button_plus_MouseHover);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Tahoma", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(20, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(158, 23);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Текущий список:";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::Window;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button1->Location = System::Drawing::Point(638, 268);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(50, 46);
			this->button1->TabIndex = 9;
			this->button1->UseMnemonic = false;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button_Edit);
			this->button1->MouseHover += gcnew System::EventHandler(this, &MyForm::button1_MouseHover);
			// 
			// button_Remove
			// 
			this->button_Remove->BackColor = System::Drawing::SystemColors::Window;
			this->button_Remove->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_Remove.BackgroundImage")));
			this->button_Remove->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button_Remove->Location = System::Drawing::Point(638, 44);
			this->button_Remove->Name = L"button_Remove";
			this->button_Remove->Size = System::Drawing::Size(41, 35);
			this->button_Remove->TabIndex = 10;
			this->button_Remove->UseVisualStyleBackColor = false;
			this->button_Remove->Click += gcnew System::EventHandler(this, &MyForm::button_Remove_Click);
			// 
			// label_current_list
			// 
			this->label_current_list->AutoSize = true;
			this->label_current_list->Font = (gcnew System::Drawing::Font(L"Tahoma", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_current_list->Location = System::Drawing::Point(184, 9);
			this->label_current_list->Name = L"label_current_list";
			this->label_current_list->Size = System::Drawing::Size(152, 23);
			this->label_current_list->TabIndex = 11;
			this->label_current_list->Text = L"label_current_list";
			// 
			// button_delete
			// 
			this->button_delete->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button_delete->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_delete.BackgroundImage")));
			this->button_delete->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button_delete->Location = System::Drawing::Point(58, 45);
			this->button_delete->Name = L"button_delete";
			this->button_delete->Size = System::Drawing::Size(40, 37);
			this->button_delete->TabIndex = 12;
			this->button_delete->UseVisualStyleBackColor = false;
			this->button_delete->Click += gcnew System::EventHandler(this, &MyForm::button_delete_Click);
			this->button_delete->MouseHover += gcnew System::EventHandler(this, &MyForm::button_delete_MouseHover);
			// 
			// button_Edit_2
			// 
			this->button_Edit_2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button_Edit_2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_Edit_2.BackgroundImage")));
			this->button_Edit_2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button_Edit_2->Location = System::Drawing::Point(104, 45);
			this->button_Edit_2->Name = L"button_Edit_2";
			this->button_Edit_2->Size = System::Drawing::Size(40, 37);
			this->button_Edit_2->TabIndex = 13;
			this->button_Edit_2->UseVisualStyleBackColor = false;
			this->button_Edit_2->Click += gcnew System::EventHandler(this, &MyForm::button_Edit_2_Click_1);
			this->button_Edit_2->MouseHover += gcnew System::EventHandler(this, &MyForm::button_Edit_2_MouseHover);
			// 
			// button_list_box_delete
			// 
			this->button_list_box_delete->BackColor = System::Drawing::SystemColors::HighlightText;
			this->button_list_box_delete->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_list_box_delete.BackgroundImage")));
			this->button_list_box_delete->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button_list_box_delete->Location = System::Drawing::Point(638, 363);
			this->button_list_box_delete->Name = L"button_list_box_delete";
			this->button_list_box_delete->Size = System::Drawing::Size(50, 46);
			this->button_list_box_delete->TabIndex = 14;
			this->button_list_box_delete->UseMnemonic = false;
			this->button_list_box_delete->UseVisualStyleBackColor = false;
			this->button_list_box_delete->Click += gcnew System::EventHandler(this, &MyForm::button_list_box_delete_Click);
			this->button_list_box_delete->MouseHover += gcnew System::EventHandler(this, &MyForm::button_list_box_delete_MouseHover);
			// 
			// TitleListBox
			// 
			this->TitleListBox->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TitleListBox->FormattingEnabled = true;
			this->TitleListBox->ItemHeight = 24;
			this->TitleListBox->Location = System::Drawing::Point(12, 100);
			this->TitleListBox->Name = L"TitleListBox";
			this->TitleListBox->Size = System::Drawing::Size(227, 28);
			this->TitleListBox->TabIndex = 15;
			this->TitleListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::TitleListBox_SelectedIndexChanged);
			// 
			// UpButton_forTitleBox
			// 
			this->UpButton_forTitleBox->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->UpButton_forTitleBox->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"UpButton_forTitleBox.BackgroundImage")));
			this->UpButton_forTitleBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->UpButton_forTitleBox->Location = System::Drawing::Point(150, 45);
			this->UpButton_forTitleBox->Name = L"UpButton_forTitleBox";
			this->UpButton_forTitleBox->Size = System::Drawing::Size(40, 37);
			this->UpButton_forTitleBox->TabIndex = 16;
			this->UpButton_forTitleBox->UseVisualStyleBackColor = false;
			this->UpButton_forTitleBox->Click += gcnew System::EventHandler(this, &MyForm::UpButton_forTitleBox_Click);
			this->UpButton_forTitleBox->MouseHover += gcnew System::EventHandler(this, &MyForm::UpButton_forTitleBox_MouseHover);
			// 
			// DownButton_forTitleBox
			// 
			this->DownButton_forTitleBox->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->DownButton_forTitleBox->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"DownButton_forTitleBox.BackgroundImage")));
			this->DownButton_forTitleBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->DownButton_forTitleBox->Location = System::Drawing::Point(196, 45);
			this->DownButton_forTitleBox->Name = L"DownButton_forTitleBox";
			this->DownButton_forTitleBox->Size = System::Drawing::Size(40, 37);
			this->DownButton_forTitleBox->TabIndex = 17;
			this->DownButton_forTitleBox->UseVisualStyleBackColor = false;
			this->DownButton_forTitleBox->Click += gcnew System::EventHandler(this, &MyForm::DownButton_forTitleBox_Click);
			this->DownButton_forTitleBox->MouseHover += gcnew System::EventHandler(this, &MyForm::DownButton_forTitleBox_MouseHover);
			// 
			// ModeLabel
			// 
			this->ModeLabel->AutoSize = true;
			this->ModeLabel->Font = (gcnew System::Drawing::Font(L"Tahoma", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ModeLabel->Location = System::Drawing::Point(563, 9);
			this->ModeLabel->Name = L"ModeLabel";
			this->ModeLabel->Size = System::Drawing::Size(116, 23);
			this->ModeLabel->TabIndex = 18;
			this->ModeLabel->Text = L"Добавление";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(699, 604);
			this->Controls->Add(this->ModeLabel);
			this->Controls->Add(this->DownButton_forTitleBox);
			this->Controls->Add(this->UpButton_forTitleBox);
			this->Controls->Add(this->TitleListBox);
			this->Controls->Add(this->button_list_box_delete);
			this->Controls->Add(this->button_Edit_2);
			this->Controls->Add(this->button_delete);
			this->Controls->Add(this->label_current_list);
			this->Controls->Add(this->button_Remove);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button_plus);
			this->Controls->Add(this->Down_Button);
			this->Controls->Add(this->Up_Button);
			this->Controls->Add(this->AddButton);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->listBox1);
			this->Name = L"MyForm";
			this->Text = L"ToDoList";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::MyForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Click += gcnew System::EventHandler(this, &MyForm::MyForm_Click);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		public: static std::string toStandardString(System::String^ string)
		{
			using System::Runtime::InteropServices::Marshal;
			System::IntPtr pointer = Marshal::StringToHGlobalAnsi(string);
			char* charPointer = reinterpret_cast<char*>(pointer.ToPointer());
			std::string returnString(charPointer, string->Length);
			Marshal::FreeHGlobal(pointer);

			return returnString;
		}

		public: static String^ toSystemString(std::string str)
		{
			return gcnew String(str.c_str());
		}

		public: void save_data_to_list()
		{
			if (textBox1->Text != "")
			{
				std::string temp = toStandardString(textBox1->Text);
				int n = listBox1->SelectedIndex;
				if (n >= 0)
				{
					auto it = data.begin();
					for (int i = 0; i <= n; i++)
						it++;
					data.insert(it, temp);
					if (EditMode)
					{
						it--; it--;
						data.erase(it);
						EditMode = false;
						ModeLabel->Text = "Добавление";
					}
				}
				else
				{
					data.push_back(temp);
				}
				textBox1->Clear();
			}
		}

		public: void save_data_to_file()
		{
			file.open(current_filename + ".txt", std::fstream::out);

			for (auto it = data.begin(); it != data.end(); it++)
			{
				file << *it << '\n';
			}
			file.close();
		}

		void show_data_at_the_listbox()
		{
			listBox1->Items->Clear();

			for (auto it = data.begin(); it != data.end(); it++)
			{
				listBox1->Items->Add(toSystemString(*it));
			}
		}

		public: void load_data_from_file_to_list()
		{
			file.open(current_filename + ".txt", std::fstream::out | std::fstream::in | std::fstream::app);
			while (file)
			{
				std::string temp;
				std::getline(file, temp);
				if (temp != "")
				{
					data.push_back(temp);
				}
			}
			file.close();
		}

		public: void update_TitleListBox()
		{
			TitleListBox->Items->Clear();
			for (const auto& i : files)
			{
				TitleListBox->Items->Add(toSystemString(i));
			}
			if (initial_size_title_list_box.Height * TitleListBox->Items->Count < Main_Form->Size.Height)
			{
				TitleListBox->Size = System::Drawing::Size(initial_size_title_list_box.Width, initial_size_title_list_box.Height * TitleListBox->Items->Count);
			}
		}

	private: System::Void AddButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		save_data_to_list();
		show_data_at_the_listbox();
	}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
		header_file.open(name_header_file, std::fstream::in);
		while (header_file)
		{
			std::string temp;
			std::getline(header_file, temp);
			if (temp != "")
			{
				files.push_back(temp);
				TitleListBox->Items->Add(toSystemString(temp));
			}
		}
		header_file.close();
		if (!files.empty())
		{
			current_filename = files.front();
		}
		else
		{
			files.push_back(current_filename);
			update_TitleListBox();
		}

		label_current_list->Text = toSystemString(current_filename);
		TitleListBox->Size = System::Drawing::Size(initial_size_title_list_box.Width, initial_size_title_list_box.Height * TitleListBox->Items->Count);
		load_data_from_file_to_list();
		show_data_at_the_listbox();
	}

	private: System::Void MyForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
	{
		save_data_to_file();

		header_file.open(name_header_file, std::fstream::out);
		for (auto& i : files)
		{
			header_file << i << '\n';
		}
		header_file.close();
	}

	private: System::Void Up_Button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		int n = listBox1->SelectedIndex;
		std::string temp1, temp2;
		if (n <= data.size() && n > 0)
		{
			auto it = data.begin();
			for (int i = 0; i < n; i++)
				it++;
			temp1 = *it;
			it--;
			temp2 = *it;
			it++;
			*it = temp2;
			it--;
			*it = temp1;
			show_data_at_the_listbox();
			listBox1->SelectedIndex = n - 1;
		}
	}

	private: System::Void Down_Button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		int n = listBox1->SelectedIndex;
		std::string temp1, temp2;
		if ((n < data.size() - 1) && n >= 0)
		{
			auto it = data.begin();
			for (int i = 0; i < n; i++)
				it++;
			temp1 = *it;
			it++;
			temp2 = *it;
			it--;
			*it = temp2;
			it++;
			*it = temp1;
			show_data_at_the_listbox();
			listBox1->SelectedIndex = n + 1;
		}
	}

	private: System::Void MyForm_Click(System::Object^ sender, System::EventArgs^ e)
	{
		listBox1->SelectedIndex = -1;
		EditMode = false;
		ModeLabel->Text = "Добавление";
	}

	private: System::Void button_Edit(System::Object^ sender, System::EventArgs^ e)
	{
		int n = listBox1->SelectedIndex;
		auto it = data.begin();
		if (n >= 0)
		{
			for (int i = 0; i < n; i++)
			{
				it++;
			}
			textBox1->Text = "";
			textBox1->Text = toSystemString(*it);
			EditMode = true;
			ModeLabel->Text = "Изменение";
		}
	}

	private: System::Void button_Remove_Click(System::Object^ sender, System::EventArgs^ e)
	{
		textBox1->Text = "";
		EditMode = false;
		ModeLabel->Text = "Добавление";
	}

	private: System::Void button_plus_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Rename_Form^ form = gcnew Rename_Form();
		this->Enabled = false;
		form->Show();
	}

	private: System::Void button_delete_Click(System::Object^ sender, System::EventArgs^ e)
	{
		std::string name_deleted_list = toStandardString(label_current_list->Text);
		auto it = find(begin(files), end(files), name_deleted_list);
		if (it != files.end())
		{
			auto result = MessageBox::Show("Вы действительно хотите удалить список:\n" + toSystemString(name_deleted_list) + "?",
				"Подтверждение", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
			if (result == System::Windows::Forms::DialogResult::Yes)
			{
				std::string temp = *it + ".txt";

				if (remove(temp.c_str()) != 0)
				{
					MessageBox::Show("Ошибка удаления", "Инфо", MessageBoxButtons::OK);
				}
				else
				{
					files.erase(it);
					TitleListBox->Items->Clear();
					if (!files.empty())
					{
						current_filename = files.front();
						label_current_list->Text = toSystemString(files.front());
					}
					else
					{
						current_filename = "Список";
						label_current_list->Text = "Список";
						files.push_back("Список");

					}
					update_TitleListBox();
					data.clear();
					load_data_from_file_to_list();
					show_data_at_the_listbox();
				}
			}
		}
	}

	private: System::Void button_Edit_2_Click_1(System::Object^ sender, System::EventArgs^ e) 
	{
		if (label_current_list->Text != "")
		{
			std::string list_name = toStandardString(label_current_list->Text);
			auto result = find(begin(files), end(files), list_name);
			if (result != files.end())
			{
				Edit_Form^ edit_form = gcnew Edit_Form();
				edit_form->Show();
				iterator_rename = result;
				edit_form->Current_Name_label->Text = toSystemString(list_name);
				edit_form->textBox1->Text = toSystemString(list_name);
				this->Enabled = false;
			}
		}	
	}

	private: System::Void textBox1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) 
	{
		if (e->KeyCode == Keys::Enter)
		{
			if (textBox1->Text != "")
			{
				std::string temp = toStandardString(textBox1->Text);
				temp.erase(std::remove(temp.begin(), temp.end(), '\n'), temp.end());
				textBox1->Text = toSystemString(temp);
				save_data_to_list();
				show_data_at_the_listbox();
			}
		}
	}

	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {	}

	bool initialization = false;
private: System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) 
{
	auto size_form = this->Size;
	if (initialization)
	{
		if (size_form.Width > initial_size_form.Width)
		{
			int changeX = size_form.Width - initial_size_form.Width;
			int changeY = size_form.Height - initial_size_form.Height;
			Point a;

			a.X = UpButton_location.X + changeX;
			a.Y = UpButton_location.Y;
			Up_Button->Location = a;

			a.X = DownButton_location.X + changeX;
			a.Y = DownButton_location.Y;
			Down_Button->Location = a;

			a.X = DeleteButton_location.X + changeX;
			a.Y = DeleteButton_location.Y;
			button_list_box_delete->Location = a;

			a.X = EditButton_location.X + changeX;
			a.Y = EditButton_location.Y;
			button1->Location = a;

			a.X = AddButton_location.X + changeX;
			a.Y = AddButton_location.Y;
			AddButton->Location = a;

			a.X = RemoveButton_location.X + changeX;
			a.Y = RemoveButton_location.Y;
			button_Remove->Location = a;

			a.X = ModeLabel_location.X + changeX;
			a.Y = ModeLabel_location.Y;
			ModeLabel->Location = a;
			
			System::Drawing::Size new_size;

			new_size.Width = initial_size_text_box.Width + changeX;
			new_size.Height = initial_size_text_box.Height;
			textBox1->Size = new_size;

			new_size.Width = initial_size_list_box.Width + changeX;
			new_size.Height = initial_size_list_box.Height + changeY;
			listBox1->Size = new_size;

			new_size.Width = initial_size_title_list_box.Width;
			if (new_size.Height < initial_size_title_list_box.Height * TitleListBox->Items->Count)
			{
				TitleListBox->Size = new_size;
			}
		}
	}
	else
	{
		initialization = true;
	}
}

private: System::Void MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) 
{
	//MessageBox::Show("Сохранить изменения?", "ToDoList", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Warning);

}
private: System::Void button_list_box_delete_Click(System::Object^ sender, System::EventArgs^ e) 
{
	size_t n = listBox1->SelectedIndex;
	size_t k = listBox1->Items->Count;
	if (n >= 0 && data.size() > 0 && n <= k)
	{
		auto iter = data.begin();
		for (int i = 0; iter != data.end() && i < n; i++)
		{
			iter++;
		}
		data.erase(iter);
		listBox1->Items->RemoveAt(n);
	}
}

private: System::Void button_list_box_delete_MouseHover(System::Object^ sender, System::EventArgs^ e) 
{
	ToolTip^ tip = gcnew ToolTip();
	tip->SetToolTip(button_list_box_delete, "Удалить выбранную строку");
}

private: System::Void button1_MouseHover(System::Object^ sender, System::EventArgs^ e) 
{
	ToolTip^ tip = gcnew ToolTip();
	tip->SetToolTip(button1, "Изменить выбранную строку");
}

private: System::Void button_Edit_2_MouseHover(System::Object^ sender, System::EventArgs^ e) 
{
	ToolTip^ tip = gcnew ToolTip();
	tip->SetToolTip(button_Edit_2, "Изменить имя текущего списка");
}

private: System::Void button_delete_MouseHover(System::Object^ sender, System::EventArgs^ e) 
{
	ToolTip^ tip = gcnew ToolTip();
	tip->SetToolTip(button_delete, "Удалить текущий список");
}
private: System::Void button_plus_MouseHover(System::Object^ sender, System::EventArgs^ e) 
{
	ToolTip^ tip = gcnew ToolTip();
	tip->SetToolTip(button_plus, "Добавить новый список");
}
private: System::Void TitleListBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
{
	save_data_to_file();

	size_t n = TitleListBox->SelectedIndex;
	if (n <= files.size())
	{
		current_filename = files.at(n);
		label_current_list->Text = toSystemString(files.at(n));

		data.clear();
		load_data_from_file_to_list();
		show_data_at_the_listbox();
		EditMode = false;
		ModeLabel->Text = "Добавление";
	}
}

private: System::Void UpButton_forTitleBox_Click(System::Object^ sender, System::EventArgs^ e) 
{
	int n = TitleListBox->SelectedIndex;	
	if (n >= 1 && n < files.size())
	{
		std::string temp;
		temp = files.at(n);
		files.at(n) = files.at(n - 1);
		files.at(n - 1) = temp;
		update_TitleListBox();
		TitleListBox->SelectedIndex = n - 1;
	}
}

private: System::Void DownButton_forTitleBox_Click(System::Object^ sender, System::EventArgs^ e) 
{
	int n = TitleListBox->SelectedIndex;
	if (n >= 0 && n < files.size() - 1)
	{
		std::string temp;
		temp = files.at(n);
		files.at(n) = files.at(n + 1);
		files.at(n + 1) = temp;
		update_TitleListBox();
		TitleListBox->SelectedIndex = n + 1;
	}
}

private: System::Void Up_Button_MouseHover(System::Object^ sender, System::EventArgs^ e) 
{
	ToolTip^ tip = gcnew ToolTip();
	tip->SetToolTip(Up_Button, "Поднять выбранную строку");
}

private: System::Void Down_Button_MouseHover(System::Object^ sender, System::EventArgs^ e) 
{
	ToolTip^ tip = gcnew ToolTip();
	tip->SetToolTip(Down_Button, "Опустить выбранную строку");
}

private: System::Void AddButton_MouseHover(System::Object^ sender, System::EventArgs^ e) 
{
	ToolTip^ tip = gcnew ToolTip();
	if (EditMode)
	{
		tip->SetToolTip(AddButton, "Изменить");
	}
	else
	{
		tip->SetToolTip(AddButton, "Добавить в список");
	}
}

private: System::Void UpButton_forTitleBox_MouseHover(System::Object^ sender, System::EventArgs^ e) 
{
	ToolTip^ tip = gcnew ToolTip();
	tip->SetToolTip(UpButton_forTitleBox, "Поднять выбранный список");
}

private: System::Void DownButton_forTitleBox_MouseHover(System::Object^ sender, System::EventArgs^ e) 
{
	ToolTip^ tip = gcnew ToolTip();
	tip->SetToolTip(DownButton_forTitleBox, "Опустить выбранный список");
}

};
}