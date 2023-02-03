#pragma once
#include <iostream>
#include <Windows.h>
#include "song.h"

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
	protected:

	protected:

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->btn_play = (gcnew System::Windows::Forms::Button());
			this->CBox_list_songs = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// btn_play
			// 
			this->btn_play->Location = System::Drawing::Point(211, 200);
			this->btn_play->Name = L"btn_play";
			this->btn_play->Size = System::Drawing::Size(75, 23);
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
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(500, 500);
			this->Controls->Add(this->CBox_list_songs);
			this->Controls->Add(this->btn_play);
			this->Name = L"MyForm";
			this->Text = L"Heardle";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

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
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->play->playSong();
	}
	};

}
