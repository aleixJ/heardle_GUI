#pragma once
#include <iostream>
#include <Windows.h>
#include "song.h"
#include <msclr\marshal_cppstd.h> //unmanage

namespace heardleGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		song ^ play;
		MyForm(void)
		{
			play = gcnew song();
			InitializeComponent();
		}
	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_play;
	private: System::Windows::Forms::ComboBox^ CBox_list_songs;
	private: System::Windows::Forms::Button^ btn_comprovar;
	private: System::Windows::Forms::Button^ btn_pista;


	private: System::Windows::Forms::Label^ label_pistes;


	//per actualitzar les pistes cada cop que es falla o es demana una
	private: void actualitzarPistes();

	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:

	private:


#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->btn_play = (gcnew System::Windows::Forms::Button());
			this->CBox_list_songs = (gcnew System::Windows::Forms::ComboBox());
			this->label_pistes = (gcnew System::Windows::Forms::Label());
			this->btn_comprovar = (gcnew System::Windows::Forms::Button());
			this->btn_pista = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btn_play
			// 
			this->btn_play->Location = System::Drawing::Point(128, 201);
			this->btn_play->Name = L"btn_play";
			this->btn_play->Size = System::Drawing::Size(100, 31);
			this->btn_play->TabIndex = 0;
			this->btn_play->Text = L"play";
			this->btn_play->UseVisualStyleBackColor = true;
			this->btn_play->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// CBox_list_songs
			// 
			this->CBox_list_songs->FormattingEnabled = true;
			this->CBox_list_songs->Location = System::Drawing::Point(128, 154);
			this->CBox_list_songs->Name = L"CBox_list_songs";
			this->CBox_list_songs->Size = System::Drawing::Size(257, 24);
			this->CBox_list_songs->Sorted = true;
			this->CBox_list_songs->TabIndex = 1;
			// 
			// label_pistes
			// 
			this->label_pistes->AutoSize = true;
			this->label_pistes->Location = System::Drawing::Point(220, 68);
			this->label_pistes->Name = L"label_pistes";
			this->label_pistes->Size = System::Drawing::Size(45, 17);
			this->label_pistes->TabIndex = 2;
			this->label_pistes->Text = L"pistes";
			// 
			// btn_comprovar
			// 
			this->btn_comprovar->Location = System::Drawing::Point(283, 201);
			this->btn_comprovar->Name = L"btn_comprovar";
			this->btn_comprovar->Size = System::Drawing::Size(102, 31);
			this->btn_comprovar->TabIndex = 3;
			this->btn_comprovar->Text = L"Comprovar";
			this->btn_comprovar->UseVisualStyleBackColor = true;
			this->btn_comprovar->Click += gcnew System::EventHandler(this, &MyForm::btn_comprovar_Click);
			// 
			// btn_pista
			// 
			this->btn_pista->Location = System::Drawing::Point(128, 252);
			this->btn_pista->Name = L"btn_pista";
			this->btn_pista->Size = System::Drawing::Size(100, 31);
			this->btn_pista->TabIndex = 4;
			this->btn_pista->Text = L"Pista";
			this->btn_pista->UseVisualStyleBackColor = true;
			this->btn_pista->Click += gcnew System::EventHandler(this, &MyForm::btn_pista_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(500, 500);
			this->Controls->Add(this->btn_pista);
			this->Controls->Add(this->btn_comprovar);
			this->Controls->Add(this->label_pistes);
			this->Controls->Add(this->CBox_list_songs);
			this->Controls->Add(this->btn_play);
			this->Name = L"MyForm";
			this->Text = L"Heardle";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
		for (int i = 0; i < this->play->songsList->size(); i++)
		{
			//No es pot fer directament perque items->Add nomes accepta System::Object
			std::string temp = this->play->songsList->at(i);
			auto managed = gcnew String(temp.c_str());
			this->CBox_list_songs->Items->Add(managed);
		}
		this->actualitzarPistes();

	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->play->playSong();
	}
	private: System::Void btn_comprovar_Click(System::Object^ sender, System::EventArgs^ e)
	{
		//comprovem que hi ha algun item seleccionat
		if (this->CBox_list_songs->SelectedItem != nullptr)
		{
			System::String^ managed = this->CBox_list_songs->SelectedItem->ToString();
			std::string unmanaged = msclr::interop::marshal_as<std::string>(managed);
			bool temp = this->play->guanyador(unmanaged);
		}
	}
	private: System::Void btn_pista_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->play->mesSegons();
		this->actualitzarPistes();
	}
};

}
