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



