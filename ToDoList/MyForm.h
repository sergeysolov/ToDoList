#pragma once
#include <list>
#include <string>
#include <fstream>
#include <vector>
#include <msclr\marshal_cppstd.h>
#include <algorithm>
#include <stdio.h>
#include "Edit_Form.h"


std::vector<std::string> files;
std::fstream header_file;
std::string name_header_file = "Head.txt";

std::list<std::string> data;
std::fstream file;
std::string current_filename = "Список.txt";
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

	Size initial_size;
	
	public ref class MyForm : public System::Windows::Forms::Form
	{

	public: static MyForm^ Main_Form;
	
		MyForm()
		{
			InitializeComponent();
			Main_Form = this;
			initial_size = this->Size;
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

	public: System::Windows::Forms::ComboBox^ comboBox_of_files;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button_Remove;
	public: System::Windows::Forms::Label^ label_current_list;
	private: System::Windows::Forms::Button^ button_delete;
	private: System::Windows::Forms::Button^ button_Edit_2;
	private: System::Windows::Forms::Button^ button_list_box_delete;

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
			this->comboBox_of_files = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button_Remove = (gcnew System::Windows::Forms::Button());
			this->label_current_list = (gcnew System::Windows::Forms::Label());
			this->button_delete = (gcnew System::Windows::Forms::Button());
			this->button_Edit_2 = (gcnew System::Windows::Forms::Button());
			this->button_list_box_delete = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Calibri", 13.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 27;
			this->listBox1->Location = System::Drawing::Point(24, 181);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(364, 459);
			this->listBox1->TabIndex = 0;
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(24, 114);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(273, 32);
			this->textBox1->TabIndex = 1;
			this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox1_KeyDown);
			// 
			// AddButton
			// 
			this->AddButton->BackColor = System::Drawing::SystemColors::Window;
			this->AddButton->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->AddButton->Location = System::Drawing::Point(331, 113);
			this->AddButton->Name = L"AddButton";
			this->AddButton->Size = System::Drawing::Size(113, 35);
			this->AddButton->TabIndex = 2;
			this->AddButton->Text = L"Добавить";
			this->AddButton->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->AddButton->UseVisualStyleBackColor = false;
			this->AddButton->Click += gcnew System::EventHandler(this, &MyForm::AddButton_Click);
			// 
			// Up_Button
			// 
			this->Up_Button->BackColor = System::Drawing::SystemColors::Window;
			this->Up_Button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Up_Button.BackgroundImage")));
			this->Up_Button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Up_Button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Up_Button->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Up_Button->Location = System::Drawing::Point(394, 181);
			this->Up_Button->Name = L"Up_Button";
			this->Up_Button->Size = System::Drawing::Size(50, 46);
			this->Up_Button->TabIndex = 3;
			this->Up_Button->UseVisualStyleBackColor = false;
			this->Up_Button->Click += gcnew System::EventHandler(this, &MyForm::Up_Button_Click);
			// 
			// Down_Button
			// 
			this->Down_Button->BackColor = System::Drawing::SystemColors::Window;
			this->Down_Button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Down_Button.BackgroundImage")));
			this->Down_Button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Down_Button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Down_Button->Location = System::Drawing::Point(394, 233);
			this->Down_Button->Name = L"Down_Button";
			this->Down_Button->Size = System::Drawing::Size(50, 44);
			this->Down_Button->TabIndex = 4;
			this->Down_Button->UseVisualStyleBackColor = false;
			this->Down_Button->Click += gcnew System::EventHandler(this, &MyForm::Down_Button_Click);
			// 
			// button_plus
			// 
			this->button_plus->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_plus.BackgroundImage")));
			this->button_plus->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button_plus->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_plus->Location = System::Drawing::Point(245, 45);
			this->button_plus->Name = L"button_plus";
			this->button_plus->Size = System::Drawing::Size(43, 36);
			this->button_plus->TabIndex = 6;
			this->button_plus->UseVisualStyleBackColor = true;
			this->button_plus->Click += gcnew System::EventHandler(this, &MyForm::button_plus_Click);
			// 
			// comboBox_of_files
			// 
			this->comboBox_of_files->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox_of_files->FormattingEnabled = true;
			this->comboBox_of_files->Location = System::Drawing::Point(24, 47);
			this->comboBox_of_files->Name = L"comboBox_of_files";
			this->comboBox_of_files->Size = System::Drawing::Size(215, 32);
			this->comboBox_of_files->TabIndex = 7;
			this->comboBox_of_files->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox_of_files_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(20, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(150, 24);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Текущий список:";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::Window;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button1->Location = System::Drawing::Point(394, 395);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(50, 49);
			this->button1->TabIndex = 9;
			this->button1->UseMnemonic = false;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button_Edit);
			// 
			// button_Remove
			// 
			this->button_Remove->BackColor = System::Drawing::SystemColors::Window;
			this->button_Remove->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_Remove.BackgroundImage")));
			this->button_Remove->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button_Remove->Location = System::Drawing::Point(294, 113);
			this->button_Remove->Name = L"button_Remove";
			this->button_Remove->Size = System::Drawing::Size(41, 35);
			this->button_Remove->TabIndex = 10;
			this->button_Remove->UseVisualStyleBackColor = false;
			this->button_Remove->Click += gcnew System::EventHandler(this, &MyForm::button_Remove_Click);
			// 
			// label_current_list
			// 
			this->label_current_list->AutoSize = true;
			this->label_current_list->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_current_list->Location = System::Drawing::Point(176, 9);
			this->label_current_list->Name = L"label_current_list";
			this->label_current_list->Size = System::Drawing::Size(157, 24);
			this->label_current_list->TabIndex = 11;
			this->label_current_list->Text = L"label_current_list";
			// 
			// button_delete
			// 
			this->button_delete->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_delete.BackgroundImage")));
			this->button_delete->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button_delete->Location = System::Drawing::Point(292, 45);
			this->button_delete->Name = L"button_delete";
			this->button_delete->Size = System::Drawing::Size(36, 36);
			this->button_delete->TabIndex = 12;
			this->button_delete->UseVisualStyleBackColor = true;
			this->button_delete->Click += gcnew System::EventHandler(this, &MyForm::button_delete_Click);
			// 
			// button_Edit_2
			// 
			this->button_Edit_2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_Edit_2.BackgroundImage")));
			this->button_Edit_2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button_Edit_2->Location = System::Drawing::Point(334, 45);
			this->button_Edit_2->Name = L"button_Edit_2";
			this->button_Edit_2->Size = System::Drawing::Size(40, 36);
			this->button_Edit_2->TabIndex = 13;
			this->button_Edit_2->UseVisualStyleBackColor = false;
			this->button_Edit_2->Click += gcnew System::EventHandler(this, &MyForm::button_Edit_2_Click_1);
			// 
			// button_list_box_delete
			// 
			this->button_list_box_delete->BackColor = System::Drawing::SystemColors::HighlightText;
			this->button_list_box_delete->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_list_box_delete.BackgroundImage")));
			this->button_list_box_delete->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button_list_box_delete->Location = System::Drawing::Point(394, 304);
			this->button_list_box_delete->Name = L"button_list_box_delete";
			this->button_list_box_delete->Size = System::Drawing::Size(50, 49);
			this->button_list_box_delete->TabIndex = 14;
			this->button_list_box_delete->UseMnemonic = false;
			this->button_list_box_delete->UseVisualStyleBackColor = false;
			this->button_list_box_delete->Click += gcnew System::EventHandler(this, &MyForm::button_list_box_delete_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(451, 659);
			this->Controls->Add(this->button_list_box_delete);
			this->Controls->Add(this->button_Edit_2);
			this->Controls->Add(this->button_delete);
			this->Controls->Add(this->label_current_list);
			this->Controls->Add(this->button_Remove);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox_of_files);
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

		void save_data_to_list()
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
						AddButton->Text = "Добавить";
					}
				}
				else
				{
					data.push_back(temp);
				}
				textBox1->Clear();
			}
		}

		void save_data_to_file()
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

		void load_data_from_file_to_list()
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

		public: void update_combo_box()
		{
			comboBox_of_files->Items->Clear();
			for (const auto& i : files)
			{
				comboBox_of_files->Items->Add(toSystemString(i));
			}
		}

	private: System::Void AddButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		save_data_to_list();
		show_data_at_the_listbox();
	}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
		header_file.open(name_header_file, std::fstream::in | std::fstream::out | std::fstream::app);
		while (header_file)
		{
			std::string temp;
			std::getline(header_file, temp);
			if (temp != "")
			{
				files.push_back(temp);
				comboBox_of_files->Items->Add(toSystemString(temp));
			}
		}
		header_file.close();
		if (!files.empty())
		{
			current_filename = files.front();
		}
		else
			files.push_back("Список");

		label_current_list->Text = toSystemString(current_filename);

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
		AddButton->Text = "Добавить";
		comboBox_of_files->Text = "";
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
			AddButton->Text = "Изменить";
		}
	}

	private: System::Void button_Remove_Click(System::Object^ sender, System::EventArgs^ e)
	{
		textBox1->Text = "";
		EditMode = false;
		AddButton->Text = "Добавить";
	}

	private: System::Void button_plus_Click(System::Object^ sender, System::EventArgs^ e)
	{
		header_file.open(name_header_file, std::fstream::app);
		if (comboBox_of_files->Text != "")
		{
			std::string temp = toStandardString(comboBox_of_files->Text);
			auto result = find(begin(files), end(files), temp);
			if (result != files.end())
			{
				MessageBox::Show("Список с таким именем уже существует!", "Предупреждение", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
			}
			else
			{
				save_data_to_file();

				files.push_back(temp);
				comboBox_of_files->Items->Add(toSystemString(files.back()));

				current_filename = temp;
				label_current_list->Text = toSystemString(temp);
				data.clear();
				show_data_at_the_listbox();
			}
			comboBox_of_files->Text = "";
		}
		header_file.close();
	}

	private: System::Void comboBox_of_files_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		save_data_to_file();

		size_t n = comboBox_of_files->SelectedIndex;
		current_filename = files.at(n);
		label_current_list->Text = toSystemString(files.at(n));

		data.clear();
		load_data_from_file_to_list();
		show_data_at_the_listbox();

	}

	private: System::Void button_delete_Click(System::Object^ sender, System::EventArgs^ e)
	{
		std::string text_in_combo_box = toStandardString(comboBox_of_files->Text);
		auto it = find(begin(files), end(files), text_in_combo_box);
		if (it != files.end())
		{
			auto result = MessageBox::Show("Вы действительно хотите удалить этот список?", "Подтверждение", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
			if (result == System::Windows::Forms::DialogResult::Yes)
			{
				std::string temp = *it + ".txt";

				if (remove(temp.c_str()) < 0)
				{
					MessageBox::Show("Ошибка удаления", "Инфо", MessageBoxButtons::OK);
				}
				files.erase(it);
				comboBox_of_files->Items->Clear();
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
				for (const auto& i : files)
				{
					comboBox_of_files->Items->Add(toSystemString(i));
				}
				data.clear();
				load_data_from_file_to_list();
				show_data_at_the_listbox();
			}
		}
		comboBox_of_files->Text = "";
	}

	private: System::Void button_Edit_2_Click_1(System::Object^ sender, System::EventArgs^ e) 
	{
		if (comboBox_of_files->Text != "")
		{
			std::string list_name = toStandardString(comboBox_of_files->Text);
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
	int const inital_location = 294;
private: System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) 
{
	auto size_form = this->Size;
	if (initialization)
	{
		if (size_form.Width > initial_size.Width)
		{
			int change = size_form.Width - initial_size.Width;
			Point a;
			a.X = inital_location + change;
			a.Y = Up_Button->Location.Y;
			Up_Button->Location = a;

			a.Y = Down_Button->Location.Y;
			Down_Button->Location = a;

			a.Y = button_list_box_delete->Location.Y;
			button_list_box_delete->Location = a;

			a.Y = button1->Location.Y;
			button1->Location = a;

			a.X = 248 + change;
			a.Y = AddButton->Location.Y;
			AddButton->Location = a;

			a.X = 220 + change;
			a.Y = button_Remove->Location.Y;
			button_Remove->Location = a;
			

			System::Drawing::Size List_Box_size;
			List_Box_size.Width = 273 + change;
			List_Box_size.Height = 352 + size_form.Height - initial_size.Height;
			listBox1->Size = List_Box_size;

			System::Drawing::Size text_box1_size;
			text_box1_size.Height = 26;
			text_box1_size.Width = 205 + change;
			textBox1->Size = text_box1_size;
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

};
}