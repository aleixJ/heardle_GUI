#pragma once
#include <iostream>
#include "song.h"
#include <msclr\marshal_cppstd.h> //unmanage


namespace heardleGUI
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
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
	private: System::Windows::Forms::Timer^ timer;
	private: System::Windows::Forms::Panel^ panelPartida;
	private: System::Windows::Forms::Label^ label_res_partida;
	private: System::Windows::Forms::Label^ label_res_correcta;
	private: System::Windows::Forms::Button^ btn_repetir;
	private: System::Windows::Forms::Button^ btn_exit;

	private: System::Windows::Forms::Label^ label_pistes;

	private : song^ play;

	//per actualitzar les pistes cada cop que es falla o es demana una
	private: void actualitzarPistes();
	private: SoundPlayer^ SongPlayer;
	private: void playSong(bool timer);
	private: System::ComponentModel::IContainer^ components;

	private: std::string static toStandarString(System::String^ string);
	private: System::String^ toSystemString(std::string);

	private: void reiniciar();
	private: void mostrar_final(bool win);

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->btn_play = (gcnew System::Windows::Forms::Button());
			this->CBox_list_songs = (gcnew System::Windows::Forms::ComboBox());
			this->label_pistes = (gcnew System::Windows::Forms::Label());
			this->btn_comprovar = (gcnew System::Windows::Forms::Button());
			this->btn_pista = (gcnew System::Windows::Forms::Button());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->panelPartida = (gcnew System::Windows::Forms::Panel());
			this->label_res_partida = (gcnew System::Windows::Forms::Label());
			this->label_res_correcta = (gcnew System::Windows::Forms::Label());
			this->btn_repetir = (gcnew System::Windows::Forms::Button());
			this->btn_exit = (gcnew System::Windows::Forms::Button());
			this->panelPartida->SuspendLayout();
			this->SuspendLayout();
			// 
			// btn_play
			// 
			this->btn_play->Location = System::Drawing::Point(110, 230);
			this->btn_play->Name = L"btn_play";
			this->btn_play->Size = System::Drawing::Size(100, 32);
			this->btn_play->TabIndex = 0;
			this->btn_play->Text = L"Play";
			this->btn_play->UseVisualStyleBackColor = true;
			this->btn_play->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// CBox_list_songs
			// 
			this->CBox_list_songs->DropDownHeight = 250;
			this->CBox_list_songs->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CBox_list_songs->FormattingEnabled = true;
			this->CBox_list_songs->IntegralHeight = false;
			this->CBox_list_songs->Location = System::Drawing::Point(100, 160);
			this->CBox_list_songs->Name = L"CBox_list_songs";
			this->CBox_list_songs->Size = System::Drawing::Size(396, 26);
			this->CBox_list_songs->Sorted = true;
			this->CBox_list_songs->TabIndex = 1;
			// 
			// label_pistes
			// 
			this->label_pistes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_pistes->Location = System::Drawing::Point(22, 50);
			this->label_pistes->Name = L"label_pistes";
			this->label_pistes->Size = System::Drawing::Size(548, 68);
			this->label_pistes->TabIndex = 2;
			this->label_pistes->Text = L"pistes";
			this->label_pistes->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btn_comprovar
			// 
			this->btn_comprovar->Location = System::Drawing::Point(386, 230);
			this->btn_comprovar->Name = L"btn_comprovar";
			this->btn_comprovar->Size = System::Drawing::Size(100, 32);
			this->btn_comprovar->TabIndex = 3;
			this->btn_comprovar->Text = L"Comprovar";
			this->btn_comprovar->UseVisualStyleBackColor = true;
			this->btn_comprovar->Click += gcnew System::EventHandler(this, &MyForm::btn_comprovar_Click);
			// 
			// btn_pista
			// 
			this->btn_pista->Location = System::Drawing::Point(248, 230);
			this->btn_pista->Name = L"btn_pista";
			this->btn_pista->Size = System::Drawing::Size(100, 32);
			this->btn_pista->TabIndex = 4;
			this->btn_pista->Text = L"Pista";
			this->btn_pista->UseVisualStyleBackColor = true;
			this->btn_pista->Click += gcnew System::EventHandler(this, &MyForm::btn_pista_Click);
			// 
			// timer
			// 
			this->timer->Interval = 1000;
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);
			// 
			// panelPartida
			// 
			this->panelPartida->Controls->Add(this->CBox_list_songs);
			this->panelPartida->Controls->Add(this->btn_pista);
			this->panelPartida->Controls->Add(this->btn_comprovar);
			this->panelPartida->Controls->Add(this->btn_play);
			this->panelPartida->Controls->Add(this->label_pistes);
			this->panelPartida->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelPartida->Location = System::Drawing::Point(0, 0);
			this->panelPartida->Name = L"panelPartida";
			this->panelPartida->Size = System::Drawing::Size(582, 603);
			this->panelPartida->TabIndex = 5;
			// 
			// label_res_partida
			// 
			this->label_res_partida->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_res_partida->Location = System::Drawing::Point(12, 50);
			this->label_res_partida->Name = L"label_res_partida";
			this->label_res_partida->Size = System::Drawing::Size(558, 57);
			this->label_res_partida->TabIndex = 6;
			this->label_res_partida->Text = L"resultat";
			this->label_res_partida->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label_res_correcta
			// 
			this->label_res_correcta->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label_res_correcta->Location = System::Drawing::Point(18, 118);
			this->label_res_correcta->Name = L"label_res_correcta";
			this->label_res_correcta->Size = System::Drawing::Size(552, 23);
			this->label_res_correcta->TabIndex = 7;
			this->label_res_correcta->Text = L"resposta correcta";
			this->label_res_correcta->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btn_repetir
			// 
			this->btn_repetir->Location = System::Drawing::Point(22, 471);
			this->btn_repetir->Name = L"btn_repetir";
			this->btn_repetir->Size = System::Drawing::Size(548, 34);
			this->btn_repetir->TabIndex = 9;
			this->btn_repetir->Text = L"REPETIR";
			this->btn_repetir->UseVisualStyleBackColor = true;
			this->btn_repetir->Click += gcnew System::EventHandler(this, &MyForm::btn_repetir_Click);
			// 
			// btn_exit
			// 
			this->btn_exit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_exit->Location = System::Drawing::Point(22, 526);
			this->btn_exit->Name = L"btn_exit";
			this->btn_exit->Size = System::Drawing::Size(548, 24);
			this->btn_exit->TabIndex = 10;
			this->btn_exit->Text = L"EXIT";
			this->btn_exit->UseVisualStyleBackColor = true;
			this->btn_exit->Click += gcnew System::EventHandler(this, &MyForm::btn_exit_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(582, 603);
			this->Controls->Add(this->btn_exit);
			this->Controls->Add(this->panelPartida);
			this->Controls->Add(this->btn_repetir);
			this->Controls->Add(this->label_res_correcta);
			this->Controls->Add(this->label_res_partida);
			this->Name = L"MyForm";
			this->Text = L"Heardle";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panelPartida->ResumeLayout(false);
			this->ResumeLayout(false);
		}

#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
		for (int i = 0; i < this->play->songsList->size(); i++)
		{
			//No es pot fer directament perque items->Add nomes accepta System::Object
			auto managed = toSystemString(this->play->songsList->at(i));
			this->CBox_list_songs->Items->Add(managed);
		}
		this->actualitzarPistes();
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		playSong(true);
	}

	private: System::Void btn_comprovar_Click(System::Object^ sender, System::EventArgs^ e)
	{
		//comprovem que hi ha algun item seleccionat
		if (this->CBox_list_songs->SelectedItem != nullptr)
		{
			std::string resposta;
			resposta = toStandarString(CBox_list_songs->SelectedItem->ToString());
			bool correcte = this->play->comprovar(resposta);
			if (correcte)
			{
				//ha guanyat
				mostrar_final(true);
			}
			else
			{
				//gastem una pista, si no en queden, ha perdut
				if (!play->mesSegons())
				{
					//ha perdut
					mostrar_final(false);
				}
				this->actualitzarPistes();
			}
		}
	}

	private: System::Void btn_pista_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->play->mesSegons();
		this->actualitzarPistes();
	}

	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		//si s'activa vol dir que la song ja s'ha reproduit el temps pertinent
		this->timer->Enabled = false;
		SongPlayer->Stop();
	}

private: System::Void btn_exit_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Close();
	}

private: System::Void btn_repetir_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->reiniciar();
	}
};
}
