#include "MyForm.h"
#include "Edit_Form.h"
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
		std::string old_name = *iterator_rename;
		std::string txt = ".txt";
		if (new_name != *iterator_rename)
		{
			int result = rename((*iterator_rename + txt).c_str(), (new_name + txt).c_str());
			if (result != 0)
			{
				MessageBox::Show("Ошибка переименования\nError code: " + System::Convert::ToString(result), "Ошибка", 
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else
			{
				*iterator_rename = new_name;
				MyForm::Main_Form->update_combo_box();
				MyForm::Main_Form->label_current_list->Text = MyForm::toSystemString(new_name);
				MyForm::Main_Form->comboBox_of_files->Text = MyForm::toSystemString(new_name);
			}
			if (result == 0)
			{
				old_name += ".txt";
				result = std::remove(old_name.c_str());
				if (result != 0)
				{
					MessageBox::Show("Ошибка удаления\nError code: " + System::Convert::ToString(result), "Ошибка",
						MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
		}
		this->Close();
	}
}

