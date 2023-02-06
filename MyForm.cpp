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

void heardleGUI::MyForm::reiniciar()
{
	//parem la reproduccio de la musica
	this->SongPlayer->Stop();
	this->timer->Enabled = false;
	//reinicialitzem la instacia 'play' per poder generar una nova partida (nova song)
	play = gcnew song();
	this->actualitzarPistes();
	panelPartida->Show();
	//per no mostrar l'ultima resposta introduida
	this->CBox_list_songs->ResetText();

}

void heardleGUI::MyForm::mostrar_final(bool win)
{
	//reproduim tota la song. si ja s'estava reproduint segueix desde aquell punt
	label_res_correcta->Text = toSystemString(play->getTitleSong());
	if (timer->Enabled == true)
		timer->Enabled = false;
	else
		playSong();
	if (win)
	{
		label_res_partida->Text = "HAS GUANYAT!!!";
	}
	else
	{
		label_res_partida->Text = "HAS PERDUT...";
	}
	panelPartida->Hide();
}
