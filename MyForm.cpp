#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
#include <iostream>

[STAThread]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	heardleGUI::MyForm form;
	Application::Run(% form);
}

void heardleGUI::MyForm::actualitzarPistes()
{
	auto managed = gcnew String("Pistes: ");
	managed += gcnew String(this->play->getPistes().ToString());
	managed += gcnew String("/");
	managed += gcnew String(this->play->getMaxPistes().ToString());
	managed += gcnew String("\n");
	managed += gcnew String("Disposes de ");
	managed += gcnew String(this->play->getSegons().ToString());
	managed += gcnew String(" segons");
	this->label_pistes->Text = managed;
}

void heardleGUI::MyForm::playSong()
{
	//assignem al timer el temps disponible. convertir de segons a millis
	this->timer->Interval = this->play->getSegons() * 1000;
	this->timer->Enabled = true;
	auto managed = toSystemString(play->getPathSong());
	SongPlayer = gcnew SoundPlayer(managed);
	SongPlayer->Play();
}

std::string heardleGUI::MyForm::toStandarString(System::String^ string)
{
	System::String^ managed = string;
	std::string unmanaged = msclr::interop::marshal_as<std::string>(managed);
	return unmanaged;
}

System::String^ heardleGUI::MyForm::toSystemString(std::string string)
{
	return gcnew String(string.c_str());
}
