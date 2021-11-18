#include "MyForm.h"
#include "Edit_Form.h"
#include "Rename_Form.h"
#include <Windows.h>
#include <cstdio>

using namespace ToDoList; // Название проекта
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm());
	return 0;
}

System::Void Edit_Form::Cancel_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	MyForm::Main_Form->Enabled = true;
	this->Close();
}

System::Void Edit_Form::Edit_Form_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
	MyForm::Main_Form->Enabled = true;
}

System::Void Edit_Form::OK_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (textBox1->Text != "")
	{
		std::string new_name = MyForm::toStandardString(textBox1->Text);
		std::string txt = ".txt";
		auto res = find(begin(files), end(files), new_name);
		if (res != files.end() || new_name == *iterator_rename)
		{
			MessageBox::Show("Список с таким именем уже существует!", "Предупреждение", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		}
		else
		{
			int result = rename((*iterator_rename + txt).c_str(), (new_name + txt).c_str());
			if (result != 0)
			{
				MessageBox::Show("Ошибка переименования\nError code: " + System::Convert::ToString(result), "Ошибка", 
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else
			{
				current_filename = *iterator_rename = new_name;
				MyForm::Main_Form->update_TitleListBox();			
				MyForm::Main_Form->label_current_list->Text = MyForm::toSystemString(new_name);
			}
			this->Close();
		}	
	}
}

System::Void Rename_Form::OK_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ new_list_name = textBox1->Text;

	header_file.open(name_header_file, std::fstream::app);
	if (new_list_name != "")
	{
		auto result = find(begin(files), end(files), MyForm::toStandardString(new_list_name));
		if (result != files.end())
		{
			MessageBox::Show("Список с таким именем уже существует!", "Предупреждение", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		}
		else
		{
			MyForm::Main_Form->save_data_to_file();

			files.push_back(MyForm::toStandardString(new_list_name));
			MyForm::Main_Form->update_TitleListBox();

			current_filename = MyForm::toStandardString(new_list_name);
			MyForm::Main_Form->label_current_list->Text = new_list_name;
			data.clear();
			MyForm::Main_Form->show_data_at_the_listbox();
		}
		MyForm::Main_Form->Enabled = true;
		this->Close();
	}
	header_file.close();	
}

System::Void ToDoList::Rename_Form::Cancel_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	MyForm::Main_Form->Enabled = true;
	this->Close();
}

System::Void ToDoList::Rename_Form::Rename_Form_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
	MyForm::Main_Form->Enabled = true;
}


