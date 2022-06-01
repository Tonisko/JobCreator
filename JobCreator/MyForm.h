#include <Windows.h>
#include <string.h>
#include <shlobj_core.h>
#include <comdef.h>
#include <fstream>
#include <set>
#include <math.h>

#include "sqlite3.h"
#pragma comment(lib, "sqlite3.lib")

#include <boost/filesystem.hpp>
#include <boost/format.hpp>
#include <boost/algorithm/hex.hpp>

#pragma comment(lib, "shell32.lib")

namespace JobCreator {

	const char* c;
	_bstr_t b;
	std::string path;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			startup();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ statusLabel;
	protected:

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStrip;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStrip;


	private: System::Windows::Forms::ComboBox^ profilescomboBox;
	private: System::Windows::Forms::ComboBox^ savecomboBox;
	private: System::Windows::Forms::ComboBox^ srcCitycomboBox;
	private: System::Windows::Forms::ComboBox^ srcComcomboBox;




	private: System::Windows::Forms::ComboBox^ desCitycomboBox;
	private: System::Windows::Forms::ComboBox^ desComcomboBox;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;


	private: System::Windows::Forms::MessageBox^ about;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ComboBox^ dbComboBox;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ToolStripMenuItem^ settingsToolStrip;

	private: System::Windows::Forms::ToolStripMenuItem^ darkMode;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::ComboBox^ telCityCombobox;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::ComboBox^ telComCombobox;
	private: System::Windows::Forms::ComboBox^ trailerTypecomboBox;

	private: System::Windows::Forms::ComboBox^ cargocomboBox;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ distanceBox;
	private: System::Windows::Forms::Label^ label12;

	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::ComboBox^ urgencyCombobox;

	private: System::Windows::Forms::ToolStripMenuItem^ donateToolStripMenuItem;
	private: System::Windows::Forms::ComboBox^ trailerVariation;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::ComboBox^ parkingDifficulty;

	private: System::Windows::Forms::Label^ label15;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->statusLabel = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->settingsToolStrip = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->darkMode = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStrip = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStrip = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->donateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->profilescomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->savecomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->srcCitycomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->srcComcomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->desCitycomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->desComcomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dbComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->telCityCombobox = (gcnew System::Windows::Forms::ComboBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->telComCombobox = (gcnew System::Windows::Forms::ComboBox());
			this->trailerTypecomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->cargocomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->distanceBox = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->urgencyCombobox = (gcnew System::Windows::Forms::ComboBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->trailerVariation = (gcnew System::Windows::Forms::ComboBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->parkingDifficulty = (gcnew System::Windows::Forms::ComboBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// statusLabel
			// 
			resources->ApplyResources(this->statusLabel, L"statusLabel");
			this->statusLabel->Name = L"statusLabel";
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->settingsToolStrip,
					this->helpToolStrip
			});
			resources->ApplyResources(this->menuStrip1, L"menuStrip1");
			this->menuStrip1->Name = L"menuStrip1";
			// 
			// settingsToolStrip
			// 
			this->settingsToolStrip->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->darkMode });
			this->settingsToolStrip->Name = L"settingsToolStrip";
			resources->ApplyResources(this->settingsToolStrip, L"settingsToolStrip");
			// 
			// darkMode
			// 
			this->darkMode->CheckOnClick = true;
			this->darkMode->Name = L"darkMode";
			resources->ApplyResources(this->darkMode, L"darkMode");
			this->darkMode->Click += gcnew System::EventHandler(this, &MyForm::darkMode_Click);
			// 
			// helpToolStrip
			// 
			this->helpToolStrip->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->aboutToolStrip,
					this->donateToolStripMenuItem
			});
			this->helpToolStrip->Name = L"helpToolStrip";
			resources->ApplyResources(this->helpToolStrip, L"helpToolStrip");
			// 
			// aboutToolStrip
			// 
			this->aboutToolStrip->Name = L"aboutToolStrip";
			resources->ApplyResources(this->aboutToolStrip, L"aboutToolStrip");
			this->aboutToolStrip->Click += gcnew System::EventHandler(this, &MyForm::aboutToolStripMenuItem_Click);
			// 
			// donateToolStripMenuItem
			// 
			this->donateToolStripMenuItem->Name = L"donateToolStripMenuItem";
			resources->ApplyResources(this->donateToolStripMenuItem, L"donateToolStripMenuItem");
			this->donateToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::donateToolStripMenuItem_Click);
			// 
			// profilescomboBox
			// 
			this->profilescomboBox->FormattingEnabled = true;
			resources->ApplyResources(this->profilescomboBox, L"profilescomboBox");
			this->profilescomboBox->Name = L"profilescomboBox";
			this->profilescomboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::profilescomboBox_SelectedIndexChanged);
			// 
			// savecomboBox
			// 
			this->savecomboBox->FormattingEnabled = true;
			resources->ApplyResources(this->savecomboBox, L"savecomboBox");
			this->savecomboBox->Name = L"savecomboBox";
			// 
			// srcCitycomboBox
			// 
			this->srcCitycomboBox->FormattingEnabled = true;
			resources->ApplyResources(this->srcCitycomboBox, L"srcCitycomboBox");
			this->srcCitycomboBox->Name = L"srcCitycomboBox";
			this->srcCitycomboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::srcCitycomboBox_SelectedIndexChanged);
			// 
			// srcComcomboBox
			// 
			this->srcComcomboBox->FormattingEnabled = true;
			resources->ApplyResources(this->srcComcomboBox, L"srcComcomboBox");
			this->srcComcomboBox->Name = L"srcComcomboBox";
			// 
			// desCitycomboBox
			// 
			this->desCitycomboBox->FormattingEnabled = true;
			resources->ApplyResources(this->desCitycomboBox, L"desCitycomboBox");
			this->desCitycomboBox->Name = L"desCitycomboBox";
			this->desCitycomboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::desCitycomboBox_SelectedIndexChanged);
			// 
			// desComcomboBox
			// 
			this->desComcomboBox->FormattingEnabled = true;
			resources->ApplyResources(this->desComcomboBox, L"desComcomboBox");
			this->desComcomboBox->Name = L"desComcomboBox";
			this->desComcomboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::desComcomboBox_SelectedIndexChanged);
			// 
			// label2
			// 
			resources->ApplyResources(this->label2, L"label2");
			this->label2->Name = L"label2";
			// 
			// label3
			// 
			resources->ApplyResources(this->label3, L"label3");
			this->label3->Name = L"label3";
			// 
			// label4
			// 
			resources->ApplyResources(this->label4, L"label4");
			this->label4->Name = L"label4";
			// 
			// label5
			// 
			resources->ApplyResources(this->label5, L"label5");
			this->label5->Name = L"label5";
			// 
			// label6
			// 
			resources->ApplyResources(this->label6, L"label6");
			this->label6->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label6->Name = L"label6";
			// 
			// label7
			// 
			resources->ApplyResources(this->label7, L"label7");
			this->label7->Name = L"label7";
			// 
			// button1
			// 
			resources->ApplyResources(this->button1, L"button1");
			this->button1->Name = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// dbComboBox
			// 
			this->dbComboBox->FormattingEnabled = true;
			resources->ApplyResources(this->dbComboBox, L"dbComboBox");
			this->dbComboBox->Name = L"dbComboBox";
			// 
			// label1
			// 
			resources->ApplyResources(this->label1, L"label1");
			this->label1->Name = L"label1";
			// 
			// label8
			// 
			resources->ApplyResources(this->label8, L"label8");
			this->label8->Name = L"label8";
			// 
			// telCityCombobox
			// 
			this->telCityCombobox->FormattingEnabled = true;
			resources->ApplyResources(this->telCityCombobox, L"telCityCombobox");
			this->telCityCombobox->Name = L"telCityCombobox";
			this->telCityCombobox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::telCityCombobox_SelectedIndexChanged);
			// 
			// label9
			// 
			resources->ApplyResources(this->label9, L"label9");
			this->label9->Name = L"label9";
			// 
			// telComCombobox
			// 
			this->telComCombobox->FormattingEnabled = true;
			resources->ApplyResources(this->telComCombobox, L"telComCombobox");
			this->telComCombobox->Name = L"telComCombobox";
			// 
			// trailerTypecomboBox
			// 
			this->trailerTypecomboBox->FormattingEnabled = true;
			resources->ApplyResources(this->trailerTypecomboBox, L"trailerTypecomboBox");
			this->trailerTypecomboBox->Name = L"trailerTypecomboBox";
			this->trailerTypecomboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::trailerTypecomboBox_SelectedIndexChanged);
			// 
			// cargocomboBox
			// 
			this->cargocomboBox->FormattingEnabled = true;
			resources->ApplyResources(this->cargocomboBox, L"cargocomboBox");
			this->cargocomboBox->Name = L"cargocomboBox";
			// 
			// label10
			// 
			resources->ApplyResources(this->label10, L"label10");
			this->label10->Name = L"label10";
			// 
			// label11
			// 
			resources->ApplyResources(this->label11, L"label11");
			this->label11->Name = L"label11";
			// 
			// button2
			// 
			resources->ApplyResources(this->button2, L"button2");
			this->button2->Name = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			resources->ApplyResources(this->button3, L"button3");
			this->button3->Name = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// distanceBox
			// 
			resources->ApplyResources(this->distanceBox, L"distanceBox");
			this->distanceBox->Name = L"distanceBox";
			// 
			// label12
			// 
			resources->ApplyResources(this->label12, L"label12");
			this->label12->Name = L"label12";
			// 
			// urgencyCombobox
			// 
			this->urgencyCombobox->FormattingEnabled = true;
			this->urgencyCombobox->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				resources->GetString(L"urgencyCombobox.Items"),
					resources->GetString(L"urgencyCombobox.Items1"), resources->GetString(L"urgencyCombobox.Items2")
			});
			resources->ApplyResources(this->urgencyCombobox, L"urgencyCombobox");
			this->urgencyCombobox->Name = L"urgencyCombobox";
			// 
			// label13
			// 
			resources->ApplyResources(this->label13, L"label13");
			this->label13->Name = L"label13";
			// 
			// trailerVariation
			// 
			this->trailerVariation->FormattingEnabled = true;
			this->trailerVariation->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				resources->GetString(L"trailerVariation.Items"),
					resources->GetString(L"trailerVariation.Items1"), resources->GetString(L"trailerVariation.Items2"), resources->GetString(L"trailerVariation.Items3"),
					resources->GetString(L"trailerVariation.Items4"), resources->GetString(L"trailerVariation.Items5")
			});
			resources->ApplyResources(this->trailerVariation, L"trailerVariation");
			this->trailerVariation->Name = L"trailerVariation";
			// 
			// label14
			// 
			resources->ApplyResources(this->label14, L"label14");
			this->label14->Name = L"label14";
			// 
			// parkingDifficulty
			// 
			this->parkingDifficulty->FormattingEnabled = true;
			this->parkingDifficulty->Items->AddRange(gcnew cli::array< System::Object^  >(2) {
				resources->GetString(L"parkingDifficulty.Items"),
					resources->GetString(L"parkingDifficulty.Items1")
			});
			resources->ApplyResources(this->parkingDifficulty, L"parkingDifficulty");
			this->parkingDifficulty->Name = L"parkingDifficulty";
			// 
			// label15
			// 
			resources->ApplyResources(this->label15, L"label15");
			this->label15->Name = L"label15";
			// 
			// MyForm
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->Controls->Add(this->label15);
			this->Controls->Add(this->parkingDifficulty);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->trailerVariation);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->urgencyCombobox);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->distanceBox);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->cargocomboBox);
			this->Controls->Add(this->trailerTypecomboBox);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->telComCombobox);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->telCityCombobox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dbComboBox);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->desComcomboBox);
			this->Controls->Add(this->desCitycomboBox);
			this->Controls->Add(this->srcComcomboBox);
			this->Controls->Add(this->srcCitycomboBox);
			this->Controls->Add(this->savecomboBox);
			this->Controls->Add(this->profilescomboBox);
			this->Controls->Add(this->statusLabel);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->ShowIcon = false;
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		void light_mode()
		{
			this->BackColor = System::Drawing::SystemColors::Control;

			this->menuStrip1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->menuStrip1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->aboutToolStrip->BackColor = System::Drawing::SystemColors::Control;
			this->aboutToolStrip->ForeColor = System::Drawing::SystemColors::ControlText;
			this->settingsToolStrip->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->settingsToolStrip->ForeColor = System::Drawing::SystemColors::ControlText;
			this->darkMode->BackColor = System::Drawing::SystemColors::Control;
			this->darkMode->ForeColor = System::Drawing::SystemColors::ControlText;

			this->label13->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label12->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label11->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label10->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label9->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label8->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label7->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label6->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label5->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label4->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->statusLabel->ForeColor = System::Drawing::SystemColors::ControlText;

			this->profilescomboBox->BackColor = System::Drawing::SystemColors::Window;
			this->profilescomboBox->ForeColor = System::Drawing::SystemColors::ControlText;
			this->savecomboBox->BackColor = System::Drawing::SystemColors::Window;
			this->savecomboBox->ForeColor = System::Drawing::SystemColors::ControlText;
			this->dbComboBox->BackColor = System::Drawing::SystemColors::Window;
			this->dbComboBox->ForeColor = System::Drawing::SystemColors::ControlText;
			this->srcCitycomboBox->BackColor = System::Drawing::SystemColors::Window;
			this->srcCitycomboBox->ForeColor = System::Drawing::SystemColors::ControlText;
			this->srcComcomboBox->BackColor = System::Drawing::SystemColors::Window;
			this->srcComcomboBox->ForeColor = System::Drawing::SystemColors::ControlText;
			this->desCitycomboBox->BackColor = System::Drawing::SystemColors::Window;
			this->desCitycomboBox->ForeColor = System::Drawing::SystemColors::ControlText;
			this->desComcomboBox->BackColor = System::Drawing::SystemColors::Window;
			this->desComcomboBox->ForeColor = System::Drawing::SystemColors::ControlText;
			this->telCityCombobox->BackColor = System::Drawing::SystemColors::Window;
			this->telCityCombobox->ForeColor = System::Drawing::SystemColors::ControlText;
			this->telComCombobox->BackColor = System::Drawing::SystemColors::Window;
			this->telComCombobox->ForeColor = System::Drawing::SystemColors::ControlText;
			this->trailerVariation->BackColor = System::Drawing::SystemColors::Window;
			this->trailerVariation->ForeColor = System::Drawing::SystemColors::ControlText;
			this->distanceBox->BackColor = System::Drawing::SystemColors::Window;
			this->distanceBox->ForeColor = System::Drawing::SystemColors::ControlText;
			this->urgencyCombobox->BackColor = System::Drawing::SystemColors::Window;
			this->urgencyCombobox->ForeColor = System::Drawing::SystemColors::ControlText;
			this->parkingDifficulty->BackColor = System::Drawing::SystemColors::Window;
			this->parkingDifficulty->ForeColor = System::Drawing::SystemColors::ControlText;

			this->cargocomboBox->BackColor = System::Drawing::SystemColors::Window;
			this->cargocomboBox->ForeColor = System::Drawing::SystemColors::ControlText;
			this->trailerTypecomboBox->BackColor = System::Drawing::SystemColors::Window;
			this->trailerTypecomboBox->ForeColor = System::Drawing::SystemColors::ControlText;
		}

		void dark_mode()
		{
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;

			this->menuStrip1->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->menuStrip1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->aboutToolStrip->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->aboutToolStrip->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->settingsToolStrip->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->settingsToolStrip->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->darkMode->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->darkMode->ForeColor = System::Drawing::SystemColors::ControlLightLight;

			this->label13->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label12->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label11->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label10->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label9->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label8->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label7->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label6->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label5->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label4->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label3->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->statusLabel->ForeColor = System::Drawing::SystemColors::ControlLightLight;

			this->profilescomboBox->BackColor = System::Drawing::SystemColors::ControlText;
			this->profilescomboBox->ForeColor = System::Drawing::SystemColors::Window;
			this->savecomboBox->BackColor = System::Drawing::SystemColors::ControlText;
			this->savecomboBox->ForeColor = System::Drawing::SystemColors::Window;
			this->dbComboBox->BackColor = System::Drawing::SystemColors::ControlText;
			this->dbComboBox->ForeColor = System::Drawing::SystemColors::Window;
			this->srcCitycomboBox->BackColor = System::Drawing::SystemColors::ControlText;
			this->srcCitycomboBox->ForeColor = System::Drawing::SystemColors::Window;
			this->srcComcomboBox->BackColor = System::Drawing::SystemColors::ControlText;
			this->srcComcomboBox->ForeColor = System::Drawing::SystemColors::Window;
			this->desCitycomboBox->BackColor = System::Drawing::SystemColors::ControlText;
			this->desCitycomboBox->ForeColor = System::Drawing::SystemColors::Window;
			this->desComcomboBox->BackColor = System::Drawing::SystemColors::ControlText;
			this->desComcomboBox->ForeColor = System::Drawing::SystemColors::Window;
			this->telCityCombobox->BackColor = System::Drawing::SystemColors::ControlText;
			this->telCityCombobox->ForeColor = System::Drawing::SystemColors::Window;
			this->telComCombobox->BackColor = System::Drawing::SystemColors::ControlText;
			this->telComCombobox->ForeColor = System::Drawing::SystemColors::Window;
			this->trailerVariation->BackColor = System::Drawing::SystemColors::ControlText;
			this->trailerVariation->ForeColor = System::Drawing::SystemColors::Window;
			this->distanceBox->BackColor = System::Drawing::SystemColors::ControlText;
			this->distanceBox->ForeColor = System::Drawing::SystemColors::Window;
			this->urgencyCombobox->BackColor = System::Drawing::SystemColors::ControlText;
			this->urgencyCombobox->ForeColor = System::Drawing::SystemColors::Window;
			this->parkingDifficulty->BackColor = System::Drawing::SystemColors::ControlText;
			this->parkingDifficulty->ForeColor = System::Drawing::SystemColors::Window;

			this->cargocomboBox->BackColor = System::Drawing::SystemColors::ControlText;
			this->cargocomboBox->ForeColor = System::Drawing::SystemColors::Window;
			this->trailerTypecomboBox->BackColor = System::Drawing::SystemColors::ControlText;
			this->trailerTypecomboBox->ForeColor = System::Drawing::SystemColors::Window;
		}

// Start of the application

		void startup()
		{
			std::ifstream file("config.cfg", std::ios::out);
			std::string line = "";
			std::getline(file, line);
			if (line == "true")
			{
				dark_mode();
				this->darkMode->Checked = true;
			}
			else
			{
				light_mode();
				this->darkMode->Checked = false;
			}
			file.close();

			wchar_t Folder[1024];
			HRESULT hr = SHGetFolderPathW(0, CSIDL_PERSONAL, 0, 0, Folder);
			if (!SUCCEEDED(hr))
			{
				this->about->Show("Program was unable to find Documents folder.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				this->Close();
			}
			b = Folder;
			c = b;
			try
			{
				for (auto& i : boost::filesystem::directory_iterator((boost::format("%1%\\Euro Truck Simulator 2\\profiles\\") % c).str()))
				{
					try
					{
						this->profilescomboBox->Items->Add(gcnew String(boost::algorithm::unhex(i.path().string().substr(_bstr_t(b).length() + 33, -1)).c_str()));
					}
					catch (const boost::exception&)
					{
						continue;
					}
				}
			}
			catch (const boost::exception&)
			{
				this->about->Show("Program was unable to locate ETS2 folder.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				this->Close();
			}
			try
			{
				this->profilescomboBox->SelectedIndex = 0;
			}
			catch (System::Exception^)
			{
				System::Windows::Forms::DialogResult check;
				check = this->about->Show("No profiles were found in documents. Do you wish to choose folder automatically?", "Error", MessageBoxButtons::YesNo, MessageBoxIcon::Error);
				if (check == System::Windows::Forms::DialogResult::Yes)
				{
					FolderBrowserDialog^ dialog = gcnew FolderBrowserDialog();
					dialog->Description = "Select \"profiles\" folder";
					dialog->ShowDialog();
					char cStr[200] = { 0 };
					if (dialog->SelectedPath->Length < sizeof(cStr))
						sprintf(cStr, "%s", dialog->SelectedPath);
					std::string stdstr(cStr);
					for (auto& i : boost::filesystem::directory_iterator(stdstr))
					{
						this->profilescomboBox->Items->Add(gcnew String(boost::algorithm::unhex(i.path().string().substr(_bstr_t(b).length() + 33, -1)).c_str()));
					}
					this->profilescomboBox->SelectedIndex = 0;
				}
				else if (check == System::Windows::Forms::DialogResult::No)
				{
					this->Close();
				}
			}
			this->profilescomboBox->Visible = true;
			this->label6->Visible = true;
			for (auto& i : boost::filesystem::directory_iterator(boost::filesystem::path(boost::filesystem::current_path())))
			{
				std::string filename = i.path().string().substr(i.path().string().find_last_of("\\") + 1);
				try
				{
					if (filename == "data.db3")
					{
						continue;
					}
					else if (filename.substr(filename.find_last_of(".")) == ".db3")
					{
						this->dbComboBox->Items->Add(gcnew String(filename.c_str()));
					}
				}
				catch (const std::exception&)
				{
					continue;
				}
			}
			this->dbComboBox->SelectedIndex = 0;
			this->statusLabel->Text = "Ready.";
		}

#pragma endregion

// "About" popup
private: System::Void aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
{
	System::Windows::Forms::DialogResult check;
	check = this->about->Show("Job Creator and Teleporter for ETS2\nVersion: 1.0\n\nNews:\n- Added trailer variations for teleport\n- Added parking difficulties for loading\n- Many other fixes and improvements from beta version\n\n© 2022 Tonisko\n\n\nBig thanks goes to:\n• sunwinbus -> Great helping with development\n• c0de -> Helping with development\n• All pre-release testers\n\n\nWant to support me? Feel free to donate by going to Help -> Donate, any support is highly appreciated!", "App info", MessageBoxButtons::OK, MessageBoxIcon::None);
}

// Changing of the profile in comboBox (same as half of the startup + it executes right after it)
private: System::Void profilescomboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
{
	this->savecomboBox->Items->Clear();
	this->statusLabel->Text = "Retrieving saves...";
	this->statusLabel->Refresh();
	char cStr[100] = { 0 };
	String^ clrString = this->profilescomboBox->GetItemText(this->profilescomboBox->SelectedItem);
	if (clrString->Length < sizeof(cStr))
		sprintf(cStr, "%s", clrString);
	std::string stlString(cStr);
	std::string d = boost::algorithm::hex(stlString);
	for (auto& s : boost::filesystem::directory_iterator((boost::format("%1%\\Euro Truck Simulator 2\\profiles\\%2%\\save\\") % c% d).str()))
	{
		if (!s.path().string().substr(_bstr_t(b).length() + strlen(d.c_str()) + 39, -1).find("autosave_drive") || !s.path().string().substr(_bstr_t(b).length() + strlen(d.c_str()) + 39, -1).find("autosave_job"))
		{
			continue;
		}
		this->savecomboBox->Items->Add(gcnew String(s.path().string().substr(_bstr_t(b).length() + strlen(d.c_str()) + 39, -1).c_str()));
	}
	this->savecomboBox->SelectedIndex = 0;
	this->savecomboBox->Visible = true;
	this->label7->Visible = true;
	this->button1->Visible = true;
	this->statusLabel->Text = "Ready.";
}

// "Load" button - locating, decoding save, retrieving cities from database, putting new info to database
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
{

//Locating + decoding save file
	this->desCitycomboBox->Items->Clear();
	this->desComcomboBox->Items->Clear();
	this->srcCitycomboBox->Items->Clear();
	this->srcComcomboBox->Items->Clear();
	this->telCityCombobox->Items->Clear();
	this->telComCombobox->Items->Clear();
	this->desCitycomboBox->Text = "";
	this->desComcomboBox->Text = "";
	this->srcCitycomboBox->Text = "";
	this->srcComcomboBox->Text = "";
	this->telCityCombobox->Text = "";
	this->telComCombobox->Text = "";
	this->button1->Enabled = false;
	this->button2->Enabled = false;

	this->statusLabel->Text = "Locating and decoding save file...";
	this->statusLabel->Refresh();
	char cStr[100] = { 0 };
	if (this->profilescomboBox->GetItemText(this->profilescomboBox->SelectedItem)->Length < sizeof(cStr))
		sprintf(cStr, "%s", this->profilescomboBox->GetItemText(this->profilescomboBox->SelectedItem));
	std::string stdstr(cStr);
	std::string d = boost::algorithm::hex(stdstr);
	cStr[0] = '\0';
	if (this->savecomboBox->GetItemText(this->savecomboBox->SelectedItem)->Length < sizeof(cStr))
		sprintf(cStr, "%s", this->savecomboBox->GetItemText(this->savecomboBox->SelectedItem));
	std::string f = cStr;
	path = (boost::format("%1%\\Euro Truck Simulator 2\\profiles\\%2%\\save\\%3%\\game.sii") % c % d % f).str();
	system((boost::format("SII_Decrypt.exe \"%1%\"") % path).str().c_str());


// Loading cities from database alphabetically
	cStr[0] = '\0';
	if (this->dbComboBox->GetItemText(this->dbComboBox->SelectedItem)->Length < sizeof(cStr))
		sprintf(cStr, "%s", this->dbComboBox->GetItemText(this->dbComboBox->SelectedItem));
	stdstr = "";
	stdstr += cStr;
	this->statusLabel->Text = "Decoded! Loading cities from database...";
	this->statusLabel->Refresh();
	sqlite3* db;
	int action;
	sqlite3_open(stdstr.c_str(), &db);
	const char* task = "SELECT town FROM cities WHERE rowid IN (SELECT min(rowid) FROM cities GROUP BY town) ORDER BY town ASC";
	sqlite3_stmt* stmt;
	action = sqlite3_prepare_v2(db, task, -1, &stmt, NULL);
	if (action != SQLITE_OK)
	{
		this->statusLabel->Text = "ERROR: Database failed to fetch fata.";
		return;
	}
	while ((action = sqlite3_step(stmt)) == SQLITE_ROW)
	{
		unsigned const char* temp = sqlite3_column_text(stmt, 0);
		const char* toadd = reinterpret_cast<const char*>(temp);
		this->srcCitycomboBox->Items->Add(gcnew System::String(toadd));
		this->desCitycomboBox->Items->Add(gcnew System::String(toadd));
		this->telCityCombobox->Items->Add(gcnew System::String(toadd));
	}
	this->srcCitycomboBox->Visible = true;
	this->desCitycomboBox->Visible = true;
	this->telCityCombobox->Visible = true;
	this->label2->Visible = true;
	this->label4->Visible = true;
	this->label8->Visible = true;


	// Checking if there are new distances and truck + trailer combinations to include into database
	this->statusLabel->Text = "Loaded! Searching for new distances for deliveries. This can take a while! Please, wait...";
	this->statusLabel->Refresh();
	FILE* file = fopen(path.c_str(), "r");
	char mystring[2048];
	std::string line = "";
	std::string town;
	sqlite3* db2;
	sqlite3_open("data.db3", &db2);
	task = "CREATE TABLE IF NOT EXISTS distances (source, target, distance, ferry_time)";

	sqlite3_stmt* stmt2;
	sqlite3_prepare_v2(db2, "SELECT source FROM distances WHERE (source=? AND target=?) OR (source=? AND target=?)", -1, &stmt2, NULL);

	sqlite3_stmt* stmt3;
	sqlite3_prepare_v2(db2, "INSERT INTO distances VALUES (?,?,?,?)", -1, &stmt3, 0);

	action = sqlite3_exec(db2, task, NULL, 0, NULL);
	action = sqlite3_exec(db2, "PRAGMA journal_mode=WAL", NULL, 0, NULL);
	if (action != SQLITE_OK)
	{
		this->statusLabel->Text = "ERROR: Database interaction failed.";
		return;
	}
	while (fgets(mystring, 2048, file) != NULL)
	{
		line = "";
		line += mystring;
		if (line.find("company : ") != std::string::npos)
		{
			if (line.find("quarry") != std::string::npos)
			{
				fgets(mystring, 2048, file);
				continue;
			}
			else
			{
				line.erase(remove(line.begin(), line.end(), '{'), line.end());
				line.erase(remove(line.begin(), line.end(), ' '), line.end());
				line.erase(remove(line.begin(), line.end(), '\n'), line.end());
				town = line.substr(line.find_last_of(".") + 1);
			}
			for (int i = 0; i < 4; i++)
			{
				fgets(mystring, 2048, file);
			}
			line = "";
			line += mystring;
			if (line.find("job_offer: 0") != std::string::npos)
			{
				continue;
			}
			else
			{
				while (fgets(mystring, 2048, file))
				{
					line = "";
					line += mystring;
					if (line.find("job_offer_data : ") != std::string::npos)
					{
						fgets(mystring, 2048, file);
						line = "";
						line += mystring;
						line.erase(remove(line.begin(), line.end(), '\n'), line.end());
						if (line.substr(9) == "\"\"")
						{
							continue;
						}
						else
						{
							line.erase(remove(line.begin(), line.end(), '"'), line.end());
							line.erase(remove(line.begin(), line.end(), '\n'), line.end());
							std::string townfin = line.substr(line.find_last_of(".") + 1);
							sqlite3_bind_text(stmt2, 1, town.c_str(), -1, SQLITE_TRANSIENT);
							sqlite3_bind_text(stmt2, 2, townfin.c_str(), -1, SQLITE_TRANSIENT);
							sqlite3_bind_text(stmt2, 3, townfin.c_str(), -1, SQLITE_TRANSIENT);
							sqlite3_bind_text(stmt2, 4, town.c_str(), -1, SQLITE_TRANSIENT);
							if ((action = sqlite3_step(stmt2)) == SQLITE_ROW)
							{
								sqlite3_reset(stmt2);
								continue;
							}
							else
							{
								sqlite3_reset(stmt2);
								sqlite3_bind_text(stmt3, 1, town.c_str(), -1, SQLITE_TRANSIENT);
								sqlite3_bind_text(stmt3, 2, townfin.c_str(), -1, SQLITE_TRANSIENT);
								for (int i = 0; i < 3; i++)
								{
									fgets(mystring, 2048, file);
								}
								line = "";
								line += mystring;
								line.erase(remove(line.begin(), line.end(), '\n'), line.end());
								sqlite3_bind_text(stmt3, 3, line.substr(23).c_str(), -1, SQLITE_TRANSIENT);
								fgets(mystring, 2048, file);
								line = "";
								line += mystring;
								line.erase(remove(line.begin(), line.end(), '\n'), line.end());
								sqlite3_bind_text(stmt3, 4, line.substr(13).c_str(), -1, SQLITE_TRANSIENT);
								sqlite3_step(stmt3);
								sqlite3_reset(stmt3);
							}

						}
					}
					else if (line.find("company : ") != std::string::npos)
					{
						fseek(file, -100, SEEK_CUR);
						break;
					}
				}
			}
		}
		mystring[0] = '\0';
	}
	sqlite3_finalize(stmt2);
	sqlite3_finalize(stmt3);
	fclose(file);
	sqlite3_close(db);
	sqlite3_close(db2);
	this->statusLabel->Text = "Ready.";
	this->button1->Enabled = true;
}

// Dark mode setting
private: System::Void darkMode_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (!this->darkMode->Checked)
	{
		std::ofstream file("config.cfg", std::ios::in | std::ios::trunc);
		file << "false";
		file.close();
		light_mode();
	}
	else if (this->darkMode->Checked)
	{
		std::ofstream file("config.cfg", std::ios::in | std::ios::trunc);
		file << "true";
		file.close();
		dark_mode();
	}
}
private: System::Void srcCitycomboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
{
	this->srcComcomboBox->Items->Clear();
	this->telComCombobox->Items->Clear();
	this->telCityCombobox->SelectedIndex = this->srcCitycomboBox->SelectedIndex;
	char cStr[100] = { 0 };
	if (this->dbComboBox->GetItemText(this->dbComboBox->SelectedItem)->Length < sizeof(cStr))
		sprintf(cStr, "%s", this->dbComboBox->GetItemText(this->dbComboBox->SelectedItem));
	std::string stdstr(cStr);
	this->statusLabel->Text = "Loading companies from database...";
	this->statusLabel->Refresh();
	sqlite3* db;
	int action;
	sqlite3_open(stdstr.c_str(), &db);
	cStr[0] = '\0';
	if (this->srcCitycomboBox->GetItemText(this->srcCitycomboBox->SelectedItem)->Length < sizeof(cStr))
		sprintf(cStr, "%s", this->srcCitycomboBox->GetItemText(this->srcCitycomboBox->SelectedItem));
	stdstr = "";
	stdstr += cStr;
	std::string task = "SELECT company FROM cities WHERE town=\"" + stdstr + "\" AND is_unload_only=\"0\"";
	sqlite3_stmt* stmt;
	action = sqlite3_prepare_v2(db, task.c_str(), -1, &stmt, NULL);
	if (action != SQLITE_OK)
	{
		this->statusLabel->Text = "ERROR: Database failed to fetch fata.";
		return;
	}
	while ((action = sqlite3_step(stmt)) == SQLITE_ROW)
	{
		unsigned const char* temp = sqlite3_column_text(stmt, 0);
		this->srcComcomboBox->Items->Add(gcnew System::String(reinterpret_cast<const char*>(temp)));
	}
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
	sqlite3_close(db);
	this->srcComcomboBox->SelectedIndex = 0;
	this->telComCombobox->SelectedIndex = 0;

	try
	{
		desCitycomboBox_SelectedIndexChanged(this, e);
	}
	catch (System::Exception^)
	{}

	this->srcComcomboBox->Visible = true;
	this->telComCombobox->Visible = true;
	this->trailerVariation->Visible = true;
	this->label3->Visible = true;
	this->label9->Visible = true;
	this->label14->Visible = true;

	this->statusLabel->Text = "Ready.";
}
private: System::Void telCityCombobox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
{
	this->telComCombobox->Items->Clear();
	char cStr[100] = { 0 };
	if (this->dbComboBox->GetItemText(this->dbComboBox->SelectedItem)->Length < sizeof(cStr))
		sprintf(cStr, "%s", this->dbComboBox->GetItemText(this->dbComboBox->SelectedItem));
	std::string stdstr(cStr);
	this->statusLabel->Text = "Loading companies from database...";
	this->statusLabel->Refresh();
	sqlite3* db;
	int action;
	sqlite3_open(stdstr.c_str(), &db);
	cStr[0] = '\0';
	if (this->telCityCombobox->GetItemText(this->telCityCombobox->SelectedItem)->Length < sizeof(cStr))
		sprintf(cStr, "%s", this->telCityCombobox->GetItemText(this->telCityCombobox->SelectedItem));
	stdstr = "";
	stdstr += cStr;
	std::string task = "SELECT company FROM cities WHERE town=\"" + stdstr + "\" AND is_unload_only=\"0\"";
	sqlite3_stmt* stmt;
	action = sqlite3_prepare_v2(db, task.c_str(), -1, &stmt, NULL);
	if (action != SQLITE_OK)
	{
		this->statusLabel->Text = "ERROR: Database failed to fetch fata.";
		return;
	}
	while ((action = sqlite3_step(stmt)) == SQLITE_ROW)
	{
		unsigned const char* temp = sqlite3_column_text(stmt, 0);
		this->telComCombobox->Items->Add(gcnew System::String(reinterpret_cast<const char*>(temp)));
	}
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
	sqlite3_close(db);
	this->telComCombobox->SelectedIndex = 0;

	this->telComCombobox->Visible = true;
	this->label9->Visible = true;
	this->button3->Visible = true;

	this->statusLabel->Text = "Ready.";
}
private: System::Void desCitycomboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
{
	this->desComcomboBox->Items->Clear();
	char cStr[100] = { 0 };
	if (this->dbComboBox->GetItemText(this->dbComboBox->SelectedItem)->Length < sizeof(cStr))
		sprintf(cStr, "%s", this->dbComboBox->GetItemText(this->dbComboBox->SelectedItem));
	std::string stdstr(cStr);
	this->statusLabel->Text = "Loading companies from database...";
	this->statusLabel->Refresh();
	sqlite3* db;
	int action;
	sqlite3_open(stdstr.c_str(), &db);
	cStr[0] = '\0';
	if (this->desCitycomboBox->GetItemText(this->desCitycomboBox->SelectedItem)->Length < sizeof(cStr))
		sprintf(cStr, "%s", this->desCitycomboBox->GetItemText(this->desCitycomboBox->SelectedItem));
	stdstr = "";
	stdstr += cStr;
	std::string task = "SELECT company FROM cities WHERE town=\"" + stdstr + "\" AND is_unload_only=\"0\"";
	sqlite3_stmt* stmt;
	action = sqlite3_prepare_v2(db, task.c_str(), -1, &stmt, NULL);
	if (action != SQLITE_OK)
	{
		this->statusLabel->Text = "ERROR: Database failed to fetch fata.";
		return;
	}
	while ((action = sqlite3_step(stmt)) == SQLITE_ROW)
	{
		unsigned const char* temp = sqlite3_column_text(stmt, 0);
		this->desComcomboBox->Items->Add(gcnew System::String(reinterpret_cast<const char*>(temp)));
	}
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
	sqlite3_close(db);

	if (this->srcComcomboBox->Items->Count == 0)
	{
		this->desComcomboBox->Visible = true;
		this->desComcomboBox->SelectedIndex = 0;
		this->label5->Visible = true;
		this->statusLabel->Text = "Ready.";
		return;
	}

	sqlite3* db2;
	sqlite3_open("data.db3", &db2);
	sqlite3_stmt* stmt2;
	cStr[0] = { 0 };
	if (this->srcCitycomboBox->GetItemText(this->srcCitycomboBox->SelectedItem)->Length < sizeof(cStr))
		sprintf(cStr, "%s", this->srcCitycomboBox->GetItemText(this->srcCitycomboBox->SelectedItem));
	std::string stdstr2(cStr);
	action = sqlite3_prepare_v2(db2, "SELECT distance FROM distances WHERE (source=? AND target=?) OR (source=? AND target=?)", -1, &stmt2, NULL);
	sqlite3_bind_text(stmt2, 1, stdstr.c_str(), -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt2, 2, stdstr2.c_str(), -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt2, 3, stdstr2.c_str(), -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt2, 4, stdstr.c_str(), -1, SQLITE_TRANSIENT);
	if (action != SQLITE_OK)
	{
		this->statusLabel->Text = "ERROR: Database failed to fetch fata.";
		return;
	}
	bool ran = false;
	while ((action = sqlite3_step(stmt2)) == SQLITE_ROW)
	{
		ran = true;
		unsigned const char* temp = sqlite3_column_text(stmt2, 0);
		this->distanceBox->Text = (gcnew System::String(reinterpret_cast<const char*>(temp)));
	}
	if (!ran)
	{
		this->distanceBox->Text = (gcnew System::String("5000"));
	}
	sqlite3_step(stmt2);
	sqlite3_finalize(stmt2);
	sqlite3_close(db2);

	this->desComcomboBox->Visible = true;
	this->desComcomboBox->SelectedIndex = 0;
	this->label5->Visible = true;

	this->urgencyCombobox->Visible = true;
	this->urgencyCombobox->SelectedIndex = 0;
	this->label13->Visible = true;

	this->parkingDifficulty->Visible = true;
	this->parkingDifficulty->SelectedIndex = 0;
	this->label15->Visible = true;

	this->button2->Enabled = true;
	this->statusLabel->Text = "Ready.";
}

private: System::Void desComcomboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
{
	if (this->srcComcomboBox->Items->Count == 0)
	{
		return;
	}
	this->label12->Visible = true;
	this->distanceBox->Visible = true;

	this->trailerTypecomboBox->Items->Clear();
	this->statusLabel->Text = "Loading cargo types from database...";
	this->statusLabel->Refresh();
	this->trailerTypecomboBox->Items->Add(gcnew System::String("all"));
	sqlite3* db;
	int action;
	sqlite3_open("data.db3", &db);
	sqlite3_stmt* stmt;
	action = sqlite3_prepare_v2(db, "SELECT trailer_type FROM cargoes WHERE rowid IN (SELECT min(rowid) FROM cargoes GROUP BY trailer_type) ORDER BY trailer_type ASC", -1, &stmt, NULL);
	if (action != SQLITE_OK)
	{
		this->statusLabel->Text = "ERROR: Database failed to fetch fata.";
		return;
	}
	while ((action = sqlite3_step(stmt)) == SQLITE_ROW)
	{
		unsigned const char* temp = sqlite3_column_text(stmt, 0);
		this->trailerTypecomboBox->Items->Add(gcnew System::String(reinterpret_cast<const char*>(temp)));
	}
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
	sqlite3_close(db);

	this->trailerTypecomboBox->Visible = true;
	this->trailerTypecomboBox->SelectedIndex = 0;
	this->label10->Visible = true;

	this->statusLabel->Text = "Ready.";
}

private: System::Void trailerTypecomboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
{
	this->cargocomboBox->Items->Clear();
	this->statusLabel->Text = "Loading cargoes from database...";
	this->statusLabel->Refresh();
	sqlite3* db;
	int action;
	sqlite3_open("data.db3", &db);
	char cStr[100] = { 0 };
	if (this->trailerTypecomboBox->GetItemText(this->trailerTypecomboBox->SelectedItem)->Length < sizeof(cStr))
		sprintf(cStr, "%s", this->trailerTypecomboBox->GetItemText(this->trailerTypecomboBox->SelectedItem));
	std::string stdstr(cStr);
	sqlite3_stmt* stmt;
	if (stdstr == "all")
	{
		action = sqlite3_prepare_v2(db, "SELECT cargo FROM cargoes WHERE rowid IN (SELECT min(rowid) FROM cargoes GROUP BY cargo) ORDER BY cargo ASC", -1, &stmt, NULL);
	}
	else
	{
		action = sqlite3_prepare_v2(db, "SELECT cargo FROM cargoes WHERE trailer_type=? AND rowid IN (SELECT min(rowid) FROM cargoes GROUP BY cargo) ORDER BY cargo ASC", -1, &stmt, NULL);
		sqlite3_bind_text(stmt, 1, stdstr.c_str(), -1, SQLITE_TRANSIENT);
	}
	if (action != SQLITE_OK)
	{
		this->statusLabel->Text = "ERROR: Database failed to fetch fata.";
		return;
	}
	while ((action = sqlite3_step(stmt)) == SQLITE_ROW)
	{
		unsigned const char* temp = sqlite3_column_text(stmt, 0);
		this->cargocomboBox->Items->Add(gcnew System::String(std::string(reinterpret_cast<const char*>(temp)).substr(6, -1).c_str()));
	}
	if (this->cargocomboBox->Items->Count == 0)
	{
		action = sqlite3_prepare_v2(db, "SELECT cargo FROM cargoes WHERE trailer_type=? ORDER BY cargo ASC", -1, &stmt, NULL);
		sqlite3_bind_text(stmt, 1, stdstr.c_str(), -1, SQLITE_TRANSIENT);
		if (action != SQLITE_OK)
		{
			this->statusLabel->Text = "ERROR: Database failed to fetch fata.";
			return;
		}
		while ((action = sqlite3_step(stmt)) == SQLITE_ROW)
		{
			unsigned const char* temp = sqlite3_column_text(stmt, 0);
			this->cargocomboBox->Items->Add(gcnew System::String(std::string(reinterpret_cast<const char*>(temp)).substr(6, -1).c_str()));
		}
	}
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
	sqlite3_close(db);

	this->cargocomboBox->Visible = true;
	this->cargocomboBox->SelectedIndex = 0;
	this->label11->Visible = true;
	this->button2->Visible = true;

	this->statusLabel->Text = "Ready.";
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) 
{
	System::Windows::Forms::DialogResult check;
	check = this->about->Show("Make sure you have chosen the right type of the trailer!\nDo you wish to proceed?", "Warning!", MessageBoxButtons::YesNo, MessageBoxIcon::Exclamation);
	if (check == System::Windows::Forms::DialogResult::No)
	{
		return;
	}
	char cStr[100] = { 0 };
	if (this->dbComboBox->GetItemText(this->dbComboBox->SelectedItem)->Length < sizeof(cStr))
		sprintf(cStr, "%s", this->dbComboBox->GetItemText(this->dbComboBox->SelectedItem));
	std::string stdstr(cStr);
	this->statusLabel->Text = "Calculating movement and rewriting save. Please, wait...";
	this->statusLabel->Refresh();
	sqlite3* db;
	sqlite3_stmt* stmt;
	int action;
	sqlite3_open(stdstr.c_str(), &db);
	cStr[0] = '\0';
	if (this->telCityCombobox->GetItemText(this->telCityCombobox->SelectedItem)->Length < sizeof(cStr))
		sprintf(cStr, "%s", this->telCityCombobox->GetItemText(this->telCityCombobox->SelectedItem));
	stdstr = "";
	stdstr += cStr;
	cStr[0] = '\0';
	if (this->telComCombobox->GetItemText(this->telComCombobox->SelectedItem)->Length < sizeof(cStr))
		sprintf(cStr, "%s", this->telComCombobox->GetItemText(this->telComCombobox->SelectedItem));
	std::string stdstr2 = cStr;
	if (this->trailerVariation->SelectedIndex <= 3 || this->parkingDifficulty->SelectedIndex == 1)
	{
		action = sqlite3_prepare_v2(db, "SELECT source_target_medium FROM cities WHERE town=? AND company=?", -1, &stmt, NULL);
	}
	if (this->trailerVariation->SelectedIndex > 3 || this->parkingDifficulty->SelectedIndex == 0)
	{
		action = sqlite3_prepare_v2(db, "SELECT target FROM cities WHERE town=? AND company=?", -1, &stmt, NULL);
	}
	sqlite3_bind_text(stmt, 1, stdstr.c_str(), -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 2, stdstr2.c_str(), -1, SQLITE_TRANSIENT);
	std::string coordinates;
	if (action != SQLITE_OK)
	{
		this->statusLabel->Text = "ERROR: Database failed to fetch fata.";
		return;
	}
	while ((action = sqlite3_step(stmt)) == SQLITE_ROW)
	{
		unsigned const char* temp = sqlite3_column_text(stmt, 0);
		coordinates = reinterpret_cast<const char*>(temp);
	}
	sqlite3_finalize(stmt);
	sqlite3_close(db);
	coordinates.erase(remove(coordinates.begin(), coordinates.end(), ';'), coordinates.end());
	coordinates.erase(remove(coordinates.begin(), coordinates.end(), '('), coordinates.end());
	coordinates.erase(remove(coordinates.begin(), coordinates.end(), ')'), coordinates.end());
	coordinates.erase(remove(coordinates.begin(), coordinates.end(), ','), coordinates.end());
	float coords[7];
	std::stringstream ss(coordinates);
	for (int i = 0; i < 7; i++) 
	{
		ss >> coords[i];
	}

// Calculating movement based on the direction of the coordinates for parking, also based on the trailer
	float length;
	switch (this->trailerVariation->SelectedIndex)
	{
		case 0:
		{
			length = 1;
			break;
		}
		case 1:
		{
			length = 8.6;
			break;
		}
		case 2:
		{
			length = 13.7;
			break;
		}
		case 3:
		{
			length = 15.0;
			break;
		}
		case 4:
		{
			length = 22.7;
			break;
		}
		case 5:
		{
			length = 31.1;
			break;
		}
		default:
		{
			this->statusLabel->Text = "ERROR: Invalid trailer choice. Please, choose available trailer variation.";
			return;
		}
	}
	if ((acos(coords[3]) * 180 / 3.141592654) < 90 || (acos(coords[3]) * 180 / 3.141592654) > 270)
	{
		coords[0] = coords[0] - sin(asin(coords[5]) * 2) * length;
	}
	else
	{
		coords[0] = coords[0] + sin(asin(coords[5]) * 2) * length;
	}
	coords[2] = coords[2] - cos(acos(coords[3]) * 2) * length;

// Saving whole save into stringstream including changes and rewriting saved game
	FILE* file = fopen(path.c_str(), "r");
	std::stringstream fTemp;
	char mystring[2048];
	std::string line = "";
	std::stringstream edited_crdnts;
	edited_crdnts << "(" << coords[0] << ", " << coords[1] << ", " << coords[2] << ") (" << coords[3] << "; " << coords[4] << ", " << coords[5] << ", " << coords[6] << ")";
	std::stringstream rotation;
	rotation << "(0, 0, 0) (" << coords[3] << "; " << coords[4] << ", " << coords[5] << ", " << coords[6] << ")";
	bool finished = false;
	int count = 0;
	while (fgets(mystring, 2048, file) != NULL)
	{
		line = "";
		line += mystring;
		if (line.find(" truck_placement: ") != std::string::npos)
		{
			fTemp << " truck_placement: " << edited_crdnts.str().c_str() << "\n";
		}
		else if (line.find(" trailer_placement: (0, 0, 0) (1; 0, 0, 0)") != std::string::npos)
		{
			fTemp << mystring;
		}
		else if (line.find(" trailer_placement: ") != std::string::npos)
		{
			fTemp << " trailer_placement: " << rotation.str().c_str() << "\n";
		}
		else if (line.find(" slave_trailer_placements[") != std::string::npos)
		{
			fTemp << " slave_trailer_placements[" << count << "]: " << rotation.str().c_str() << "\n";
			count++;
		}
		else
		{
			fTemp << mystring;
		}
		mystring[0] = '\0';
	}
	fclose(file);
	std::ofstream file2(path.c_str(), std::ios::trunc | std::ios::in);
	file2 << fTemp.str();
	file2.close();
	this->statusLabel->Text = "Ready.";
}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
{
	std::string stdstr[9];
	char cStr[100] = { 0 };
	if (this->dbComboBox->GetItemText(this->dbComboBox->SelectedItem)->Length < sizeof(cStr))
		sprintf(cStr, "%s", this->dbComboBox->GetItemText(this->dbComboBox->SelectedItem));
	stdstr[0] += cStr;
	this->statusLabel->Text = "Adding job and rewriting save. Please, wait...";
	this->statusLabel->Refresh();
	sqlite3* db;
	sqlite3_stmt* stmt;
	int action;
	sqlite3_open(stdstr[0].c_str(), &db);

// Retrieving info from all combo boxes and putting it into array
	cStr[0] = '\0';
	if (this->srcCitycomboBox->GetItemText(this->srcCitycomboBox->SelectedItem)->Length < sizeof(cStr))
		sprintf(cStr, "%s", this->srcCitycomboBox->GetItemText(this->srcCitycomboBox->SelectedItem));
	stdstr[0] = "";
	stdstr[0] += cStr;

	cStr[0] = '\0';
	if (this->srcComcomboBox->GetItemText(this->srcComcomboBox->SelectedItem)->Length < sizeof(cStr))
		sprintf(cStr, "%s", this->srcComcomboBox->GetItemText(this->srcComcomboBox->SelectedItem));
	stdstr[1] += cStr;

	cStr[0] = '\0';
	if (this->desCitycomboBox->GetItemText(this->desCitycomboBox->SelectedItem)->Length < sizeof(cStr))
		sprintf(cStr, "%s", this->desCitycomboBox->GetItemText(this->desCitycomboBox->SelectedItem));
	stdstr[2] = "";
	stdstr[2] += cStr;

	cStr[0] = '\0';
	if (this->desComcomboBox->GetItemText(this->desComcomboBox->SelectedItem)->Length < sizeof(cStr))
		sprintf(cStr, "%s", this->desComcomboBox->GetItemText(this->desComcomboBox->SelectedItem));
	stdstr[3] = "";
	stdstr[3] += cStr;

	cStr[0] = '\0';
	if (this->urgencyCombobox->GetItemText(this->urgencyCombobox->SelectedItem)->Length < sizeof(cStr))
		sprintf(cStr, "%s", this->urgencyCombobox->SelectedIndex.ToString());
	stdstr[4] = "";
	stdstr[4] += cStr;

	cStr[0] = '\0';
	if (this->cargocomboBox->GetItemText(this->cargocomboBox->SelectedItem)->Length < sizeof(cStr))
		sprintf(cStr, "%s", this->cargocomboBox->GetItemText(this->cargocomboBox->SelectedItem));
	stdstr[5] = "";
	stdstr[5] += cStr;

	cStr[0] = '\0';
	if (this->distanceBox->Text->Length < sizeof(cStr))
		sprintf(cStr, "%s", this->distanceBox->Text);
	stdstr[6] = "";
	stdstr[6] += cStr;

	std::string coordinates[4];

// Getting coordinates from database and inserting them to array of coordinates
	action = sqlite3_prepare_v2(db, "SELECT target, source_target_medium, target_hard FROM cities WHERE town=? AND company=?", -1, &stmt, NULL);
	sqlite3_bind_text(stmt, 1, stdstr[2].c_str(), -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 2, stdstr[3].c_str(), -1, SQLITE_TRANSIENT);
	if (action != SQLITE_OK)
	{
		this->statusLabel->Text = "ERROR: Database failed to fetch fata.";
		return;
	}
	while ((action = sqlite3_step(stmt)) == SQLITE_ROW)
	{
		coordinates[0] = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
		coordinates[1] = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
		coordinates[2] = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
	}
	sqlite3_finalize(stmt);

// Double or longer trailer is used / which parking is selected
	if (this->trailerVariation->SelectedIndex <= 3 || this->parkingDifficulty->SelectedIndex == 1)
	{
		action = sqlite3_prepare_v2(db, "SELECT source_target_medium FROM cities WHERE town=? AND company=?", -1, &stmt, NULL);
		stdstr[8] = "false";
	}
	if (this->trailerVariation->SelectedIndex > 3 || this->parkingDifficulty->SelectedIndex == 0)
	{
		action = sqlite3_prepare_v2(db, "SELECT target FROM cities WHERE town=? AND company=?", -1, &stmt, NULL);
		stdstr[8] = "true";
	}

	sqlite3_bind_text(stmt, 1, stdstr[0].c_str(), -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 2, stdstr[1].c_str(), -1, SQLITE_TRANSIENT);
	if (action != SQLITE_OK)
	{
		this->statusLabel->Text = "ERROR: Database failed to fetch fata.";
		return;
	}
	while ((action = sqlite3_step(stmt)) == SQLITE_ROW)
	{
		unsigned const char* temp = sqlite3_column_text(stmt, 0);
		coordinates[3] = reinterpret_cast<const char*>(temp);
	}
	sqlite3_finalize(stmt);
	sqlite3_close(db);

// If ferry travel is necessary
	sqlite3* db2;
	sqlite3_open("data.db3", &db2);
	sqlite3_stmt* stmt2;
	action = sqlite3_prepare_v2(db2, "SELECT ferry_time FROM distances WHERE (source=? AND target=?) OR (source=? AND target=?)", -1, &stmt2, NULL);
	sqlite3_bind_text(stmt2, 1, stdstr[0].c_str(), -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt2, 2, stdstr[2].c_str(), -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt2, 3, stdstr[2].c_str(), -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt2, 4, stdstr[0].c_str(), -1, SQLITE_TRANSIENT);
	if (action != SQLITE_OK)
	{
		this->statusLabel->Text = "ERROR: Database failed to fetch fata.";
		return;
	}
	bool ran = false;
	while ((action = sqlite3_step(stmt2)) == SQLITE_ROW)
	{
		ran = true;
		unsigned const char* temp = sqlite3_column_text(stmt2, 0);
		stdstr[7] = reinterpret_cast<const char*>(temp);
	}
	if (!ran)
	{
		stdstr[7] = "0";
	}
	sqlite3_step(stmt2);
	sqlite3_finalize(stmt2);
	sqlite3_close(db2);

// Writing of save + produced data into stringstream, then rewriting save completely
	FILE* file = fopen(path.c_str(), "r");
	std::stringstream fTemp;
	char mystring[2048];
	std::string line = "";
	int time;
	int timeadd;
	bool player_found = false;
	while (fgets(mystring, 2048, file) != NULL)
	{
		line = "";
		line += mystring;

		// Simple delivery time calculation, including some reserve time
		if (line.find(" game_time: ") != std::string::npos)
		{
			time = std::stoi(line.substr(12));
			int distanceint = std::stoi(stdstr[6]);
			if (stdstr[4] == "0")
			{
				timeadd = 4 * distanceint;
			}
			else if (stdstr[4] == "1")
			{
				timeadd = 2 * distanceint;
			}
			else if (stdstr[4] == "2")
			{
				timeadd = 1.5 * distanceint;
			}
			fTemp << mystring;
		}
		else if (line.find(" current_job: _nameless") != std::string::npos || line.find(" current_job:_nameless") != std::string::npos)
		{
			this->statusLabel->Text = "ERROR - This save already has a job. Please finish/cancel it before continuing, save a game, press \"Load\" and try again.";
			return;
		}
		else if (line.find(" assigned_trailer: null") != std::string::npos && player_found)
		{
			this->statusLabel->Text = "ERROR - No trailer is attached. Please, attach a trailer, save a game, press \"Load\" and try again.";
			return;
		}
		else if (line.find(" current_job:") != std::string::npos)
		{
			fTemp << " current_job: " << "_nameless.aaa.aaaa.aaaa" << "\n";
		}
		else if (line.find("player : _nameless") != std::string::npos)
		{
			player_found = true;
			fTemp << mystring;
		}
		else if (line.find("}\n") != std::string::npos && player_found)
		{
			fTemp << mystring;
			fTemp << "\n";
			fTemp << "player_job : _nameless.aaa.aaaa.aaaa {\n";
			fTemp << " company_truck: null\n";
			fTemp << " company_trailer: null\n";
			fTemp << " target_placement: " << coordinates[0] << "\n";
			fTemp << " target_placement_medium: " << coordinates[1] << "\n";
			fTemp << " target_placement_hard: " << coordinates[2] << "\n";
			fTemp << " target_placement_rigid: (0, &60ad78ec, 0) (1; 0, 0, 0)\n";
			fTemp << " source_placement: " << coordinates[3] << "\n";
			fTemp << " selected_target: nil\n";
			fTemp << " time_lower_limit: " << (time + timeadd) << "\n";
			fTemp << " time_upper_limit: " << (time + 300 + timeadd) << "\n";
			fTemp << " job_distance: 0\n";
			fTemp << " fuel_consumed: 0\n";
			fTemp << " last_reported_fuel: 0\n";
			fTemp << " total_fines: 0\n";
			fTemp << " is_trailer_loaded: false\n";
			fTemp << " online_job_id: nil\n";
			fTemp << " online_job_trailer_model: null\n";
			fTemp << " autoload_used: false\n";
			fTemp << " cargo: cargo." << stdstr[5] << "\n";
			fTemp << " source_company: company.volatile." << stdstr[1] << "." << stdstr[0] << "\n";
			fTemp << " target_company: company.volatile." << stdstr[3] << "." << stdstr[2] << "\n";
			fTemp << " is_articulated: " << stdstr[8] << "\n";
			fTemp << " is_cargo_market_job: true\n";
			fTemp << " start_time: " << time << "\n";
			fTemp << " planned_distance_km: " << stdstr[6] << "\n";
			fTemp << " ferry_time: " << stdstr[7] << "\n";
			fTemp << " ferry_price: 0\n";
			fTemp << " urgency: " << stdstr[4] << "\n";
			fTemp << " special: null\n";
			fTemp << " units_count: 33\n";
			fTemp << " fill_ratio: 1\n";
			fTemp << "}\n";
			player_found = false;
		}
		else
		{
			fTemp << mystring;
		}
		mystring[0] = '\0';
	}
	fclose(file);
	std::ofstream file2(path.c_str(), std::ios::trunc | std::ios::in);
	file2 << fTemp.str();
	file2.close();
	this->statusLabel->Text = "Ready.";
}

// Redirection to donating page over default browser
private: System::Void donateToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
{
	ShellExecute(0, 0, L"https://paypal.me/tonisko", 0, 0, SW_SHOW);
}
};
}