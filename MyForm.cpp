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
	managed += gcnew String(this->play->obtenirPistesDis().ToString());
	managed += gcnew String("/");
	managed += gcnew String(this->play->obtenirMaxPistes().ToString());
	managed += gcnew String("\n");
	managed += gcnew String("Disposes de ");
	managed += gcnew String(this->play->segonsDisponibles().ToString());
	managed += gcnew String(" segons");
	this->label_pistes->Text = managed;
}
