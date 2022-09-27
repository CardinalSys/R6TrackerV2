#pragma 
#include <string>
#define WIN32_LEAN_AND_MEAN
#include "proc.h"
#include <Psapi.h>
#undef WIN32_LEAN_AND_MEAN


namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::IO;
	using namespace System::Text;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Summary for Form1
	/// </summary>

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			pictureBox1->Image = Image::FromFile("img/Unranked.png");
			//
			//TODO: Add the constructor code here
			//
		}
	private: System::Windows::Forms::Timer^ ScanValues;
	public:

	private: System::Windows::Forms::Label^ KillsValueText;
	public:
	private: System::Windows::Forms::Label^ PlayerNameText;
	private: System::Windows::Forms::Label^ KillsText;
	private: System::Windows::Forms::Label^ DeathsText;
	private: System::Windows::Forms::Label^ DeathsValueText;
	private: System::Windows::Forms::Label^ AssistsText;
	private: System::Windows::Forms::Label^ AssistsValueText;
	private: System::Windows::Forms::Label^ KDText;
	private: System::Windows::Forms::Label^ KDValueText;
	private: System::Windows::Forms::Label^ WinsText;

	private: System::Windows::Forms::Label^ WinsValueText;
	private: System::Windows::Forms::Label^ LossesText;
	private: System::Windows::Forms::Label^ LossesValueText;
	private: System::Windows::Forms::Label^ WRText;
	private: System::Windows::Forms::Label^ WRValueText;
	private: System::Windows::Forms::Label^ ExpValueText;

	private: System::Windows::Forms::PictureBox^ pictureBox1;




		   
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ ProcessScan;
	private: System::Windows::Forms::Label^ LvlText;

	protected:

	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		uintptr_t PlayerAddr;
		uintptr_t MatchAddr;
		uintptr_t moduleBase;
		uintptr_t OnMatchAddr;
		uintptr_t killsAddress;
		uintptr_t deathsAddress;
		uintptr_t expAddress;
		proc p;
		HANDLE hProcess = 0;
		HANDLE hConsole;
		//final values
		UINT kills = 0;
		UINT deaths = 0;
		UINT assists = 0;
		double kd();

		UINT wins = 0;
		UINT losses = 0;
		double wr();

		UINT totalXp = 0;
		UINT lvlXp = 3000;
		UINT lvl = 1;

		//match values result
		UINT matchKills = 0;
		UINT matchDeaths = 0;
		UINT matchAssists = 0;
		UINT matchExp = 0;

		void MatchResult();
		void LvlSystem();

		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->ProcessScan = (gcnew System::Windows::Forms::Timer(this->components));
			this->LvlText = (gcnew System::Windows::Forms::Label());
			this->ScanValues = (gcnew System::Windows::Forms::Timer(this->components));
			this->KillsValueText = (gcnew System::Windows::Forms::Label());
			this->PlayerNameText = (gcnew System::Windows::Forms::Label());
			this->KillsText = (gcnew System::Windows::Forms::Label());
			this->DeathsText = (gcnew System::Windows::Forms::Label());
			this->DeathsValueText = (gcnew System::Windows::Forms::Label());
			this->AssistsText = (gcnew System::Windows::Forms::Label());
			this->AssistsValueText = (gcnew System::Windows::Forms::Label());
			this->KDText = (gcnew System::Windows::Forms::Label());
			this->KDValueText = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->WinsText = (gcnew System::Windows::Forms::Label());
			this->WinsValueText = (gcnew System::Windows::Forms::Label());
			this->LossesText = (gcnew System::Windows::Forms::Label());
			this->LossesValueText = (gcnew System::Windows::Forms::Label());
			this->WRText = (gcnew System::Windows::Forms::Label());
			this->WRValueText = (gcnew System::Windows::Forms::Label());
			this->ExpValueText = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// ProcessScan
			// 
			this->ProcessScan->Enabled = true;
			this->ProcessScan->Tick += gcnew System::EventHandler(this, &Form1::ProcessScan_Tick);
			// 
			// LvlText
			// 
			this->LvlText->AutoSize = true;
			this->LvlText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LvlText->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->LvlText->Location = System::Drawing::Point(141, 71);
			this->LvlText->Name = L"LvlText";
			this->LvlText->Size = System::Drawing::Size(30, 17);
			this->LvlText->TabIndex = 0;
			this->LvlText->Text = L"Lvl:";
			// 
			// ScanValues
			// 
			this->ScanValues->Interval = 200;
			this->ScanValues->Tick += gcnew System::EventHandler(this, &Form1::ScanValues_Tick);
			// 
			// KillsValueText
			// 
			this->KillsValueText->AutoSize = true;
			this->KillsValueText->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->KillsValueText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->KillsValueText->ForeColor = System::Drawing::Color::Snow;
			this->KillsValueText->Location = System::Drawing::Point(35, 168);
			this->KillsValueText->Name = L"KillsValueText";
			this->KillsValueText->Size = System::Drawing::Size(18, 20);
			this->KillsValueText->TabIndex = 1;
			this->KillsValueText->Text = L"0";
			// 
			// PlayerNameText
			// 
			this->PlayerNameText->AutoSize = true;
			this->PlayerNameText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PlayerNameText->ForeColor = System::Drawing::SystemColors::Control;
			this->PlayerNameText->Location = System::Drawing::Point(130, 47);
			this->PlayerNameText->Name = L"PlayerNameText";
			this->PlayerNameText->Size = System::Drawing::Size(51, 20);
			this->PlayerNameText->TabIndex = 2;
			this->PlayerNameText->Text = L"Name";
			// 
			// KillsText
			// 
			this->KillsText->AutoSize = true;
			this->KillsText->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->KillsText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->KillsText->ForeColor = System::Drawing::Color::Snow;
			this->KillsText->Location = System::Drawing::Point(49, 187);
			this->KillsText->Name = L"KillsText";
			this->KillsText->Size = System::Drawing::Size(88, 20);
			this->KillsText->TabIndex = 3;
			this->KillsText->Text = L"Asesinatos";
			// 
			// DeathsText
			// 
			this->DeathsText->AutoSize = true;
			this->DeathsText->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->DeathsText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DeathsText->ForeColor = System::Drawing::Color::Snow;
			this->DeathsText->Location = System::Drawing::Point(160, 187);
			this->DeathsText->Name = L"DeathsText";
			this->DeathsText->Size = System::Drawing::Size(67, 20);
			this->DeathsText->TabIndex = 5;
			this->DeathsText->Text = L"Muertes";
			// 
			// DeathsValueText
			// 
			this->DeathsValueText->AutoSize = true;
			this->DeathsValueText->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->DeathsValueText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DeathsValueText->ForeColor = System::Drawing::Color::Snow;
			this->DeathsValueText->Location = System::Drawing::Point(146, 168);
			this->DeathsValueText->Name = L"DeathsValueText";
			this->DeathsValueText->Size = System::Drawing::Size(18, 20);
			this->DeathsValueText->TabIndex = 4;
			this->DeathsValueText->Text = L"0";
			// 
			// AssistsText
			// 
			this->AssistsText->AutoSize = true;
			this->AssistsText->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->AssistsText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AssistsText->ForeColor = System::Drawing::Color::Snow;
			this->AssistsText->Location = System::Drawing::Point(247, 185);
			this->AssistsText->Name = L"AssistsText";
			this->AssistsText->Size = System::Drawing::Size(90, 20);
			this->AssistsText->TabIndex = 7;
			this->AssistsText->Text = L"Asistencias";
			// 
			// AssistsValueText
			// 
			this->AssistsValueText->AutoSize = true;
			this->AssistsValueText->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->AssistsValueText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AssistsValueText->ForeColor = System::Drawing::Color::Snow;
			this->AssistsValueText->Location = System::Drawing::Point(233, 166);
			this->AssistsValueText->Name = L"AssistsValueText";
			this->AssistsValueText->Size = System::Drawing::Size(18, 20);
			this->AssistsValueText->TabIndex = 6;
			this->AssistsValueText->Text = L"0";
			// 
			// KDText
			// 
			this->KDText->AutoSize = true;
			this->KDText->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->KDText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->KDText->ForeColor = System::Drawing::Color::Snow;
			this->KDText->Location = System::Drawing::Point(355, 185);
			this->KDText->Name = L"KDText";
			this->KDText->Size = System::Drawing::Size(31, 20);
			this->KDText->TabIndex = 9;
			this->KDText->Text = L"KD";
			// 
			// KDValueText
			// 
			this->KDValueText->AutoSize = true;
			this->KDValueText->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->KDValueText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->KDValueText->ForeColor = System::Drawing::Color::Snow;
			this->KDValueText->Location = System::Drawing::Point(341, 166);
			this->KDValueText->Name = L"KDValueText";
			this->KDValueText->Size = System::Drawing::Size(18, 20);
			this->KDValueText->TabIndex = 8;
			this->KDValueText->Text = L"0";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(39, 30);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(74, 83);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 10;
			this->pictureBox1->TabStop = false;
			// 
			// WinsText
			// 
			this->WinsText->AutoSize = true;
			this->WinsText->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->WinsText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->WinsText->ForeColor = System::Drawing::Color::Snow;
			this->WinsText->Location = System::Drawing::Point(48, 244);
			this->WinsText->Name = L"WinsText";
			this->WinsText->Size = System::Drawing::Size(70, 20);
			this->WinsText->TabIndex = 12;
			this->WinsText->Text = L"Victorias";
			// 
			// WinsValueText
			// 
			this->WinsValueText->AutoSize = true;
			this->WinsValueText->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->WinsValueText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->WinsValueText->ForeColor = System::Drawing::Color::Snow;
			this->WinsValueText->Location = System::Drawing::Point(34, 225);
			this->WinsValueText->Name = L"WinsValueText";
			this->WinsValueText->Size = System::Drawing::Size(18, 20);
			this->WinsValueText->TabIndex = 11;
			this->WinsValueText->Text = L"0";
			// 
			// LossesText
			// 
			this->LossesText->AutoSize = true;
			this->LossesText->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->LossesText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LossesText->ForeColor = System::Drawing::Color::Snow;
			this->LossesText->Location = System::Drawing::Point(159, 244);
			this->LossesText->Name = L"LossesText";
			this->LossesText->Size = System::Drawing::Size(71, 20);
			this->LossesText->TabIndex = 14;
			this->LossesText->Text = L"Derrotas";
			// 
			// LossesValueText
			// 
			this->LossesValueText->AutoSize = true;
			this->LossesValueText->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->LossesValueText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LossesValueText->ForeColor = System::Drawing::Color::Snow;
			this->LossesValueText->Location = System::Drawing::Point(145, 225);
			this->LossesValueText->Name = L"LossesValueText";
			this->LossesValueText->Size = System::Drawing::Size(18, 20);
			this->LossesValueText->TabIndex = 13;
			this->LossesValueText->Text = L"0";
			// 
			// WRText
			// 
			this->WRText->AutoSize = true;
			this->WRText->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->WRText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->WRText->ForeColor = System::Drawing::Color::Snow;
			this->WRText->Location = System::Drawing::Point(262, 244);
			this->WRText->Name = L"WRText";
			this->WRText->Size = System::Drawing::Size(36, 20);
			this->WRText->TabIndex = 16;
			this->WRText->Text = L"WR";
			// 
			// WRValueText
			// 
			this->WRValueText->AutoSize = true;
			this->WRValueText->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->WRValueText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->WRValueText->ForeColor = System::Drawing::Color::Snow;
			this->WRValueText->Location = System::Drawing::Point(248, 225);
			this->WRValueText->Name = L"WRValueText";
			this->WRValueText->Size = System::Drawing::Size(18, 20);
			this->WRValueText->TabIndex = 15;
			this->WRValueText->Text = L"0";
			// 
			// ExpValueText
			// 
			this->ExpValueText->AutoSize = true;
			this->ExpValueText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ExpValueText->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->ExpValueText->Location = System::Drawing::Point(161, 96);
			this->ExpValueText->Name = L"ExpValueText";
			this->ExpValueText->Size = System::Drawing::Size(28, 17);
			this->ExpValueText->TabIndex = 17;
			this->ExpValueText->Text = L"0/0";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(416, 306);
			this->Controls->Add(this->ExpValueText);
			this->Controls->Add(this->WRText);
			this->Controls->Add(this->WRValueText);
			this->Controls->Add(this->LossesText);
			this->Controls->Add(this->LossesValueText);
			this->Controls->Add(this->WinsText);
			this->Controls->Add(this->WinsValueText);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->KDText);
			this->Controls->Add(this->KDValueText);
			this->Controls->Add(this->AssistsText);
			this->Controls->Add(this->AssistsValueText);
			this->Controls->Add(this->DeathsText);
			this->Controls->Add(this->DeathsValueText);
			this->Controls->Add(this->KillsText);
			this->Controls->Add(this->PlayerNameText);
			this->Controls->Add(this->KillsValueText);
			this->Controls->Add(this->LvlText);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ProcessScan_Tick(System::Object^ sender, System::EventArgs^ e) {
		//Get ProcId of the target process
		DWORD procId = p.GetProcID(L"RainbowSix.exe");
		if (procId != 0)
		{
			ProcessScan->Enabled = false;
			hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			//GetModuleBaseAddress
			moduleBase = p.GetModuleBaseAddress(procId, L"RainbowSix.exe");
			//Get Handle to Process
			hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);
			//Resolve base address of the pointer
			PlayerAddr = moduleBase + 0x06EB6348;
			MatchAddr = moduleBase + 0x06E72A88;
			OnMatchAddr = moduleBase + 0x77E923C;
			TCHAR filename[MAX_PATH];
			if (GetModuleFileNameExW(hProcess, NULL, filename, MAX_PATH))
			{
				String^ path = gcnew String(filename);
				path = path->Replace("RainbowSix.exe", "uplay_r2.ini");
				StreamReader^ reader = File::OpenText(path);
				String^ lines = reader->ReadToEnd();
				PlayerNameText->Text = lines->Split('\n')[1]->Replace("Username = ", "");
			}
			

			ScanValues->Enabled = true;

		}

	}
	private: System::Void ScanValues_Tick(System::Object^ sender, System::EventArgs^ e) {


		std::vector<unsigned int> emptyOffsets;
		uintptr_t OnMatchAddress = p.FindDMAAddy(hProcess, OnMatchAddr, emptyOffsets);
		char onMatch;
		ReadProcessMemory(hProcess, (BYTE*)OnMatchAddress, &onMatch, sizeof(char), nullptr);
		if(onMatch == 1)
		{ 
			//Read Exp
			std::vector<unsigned int> ExpOffsets = { 0x28, 0x30, 0x304 };
			expAddress = p.FindDMAAddy(hProcess, PlayerAddr, ExpOffsets);
			UINT tempExp;
			ReadProcessMemory(hProcess, (BYTE*)expAddress, &tempExp, sizeof(UINT), nullptr);
			if (tempExp != matchExp && tempExp > 0 && tempExp < 5000)
			{
				UINT resetExp = 0;
				matchExp = tempExp;
				totalXp += matchExp;
				matchExp = 0;
				WriteProcessMemory(hProcess, (BYTE*)expAddress, &resetExp, sizeof(resetExp), 0);

				MatchResult();

			}

			//Read kills
			std::vector<unsigned int> killsOffsets = { 0x28, 0x30, 0x2FC };
			killsAddress = p.FindDMAAddy(hProcess, PlayerAddr, killsOffsets);
			char tempKills;
			ReadProcessMemory(hProcess, (BYTE*)killsAddress, &tempKills, sizeof(char), nullptr);
			if (tempKills != matchKills && tempKills > 0 && tempKills < 25)
			{
				char newVal = 0;
				matchKills = tempKills;
				kills += matchKills;
				matchKills = 0;
				WriteProcessMemory(hProcess, (BYTE*)killsAddress, &newVal, sizeof(newVal), 0);
			}


			//Read deaths
			std::vector<unsigned int> deathOffsets = { 0x28, 0x30, 0x2F8 };
			deathsAddress = p.FindDMAAddy(hProcess, PlayerAddr, deathOffsets);

			char tempDeaths;
			ReadProcessMemory(hProcess, (BYTE*)deathsAddress, &tempDeaths, sizeof(char), nullptr);
			if (tempDeaths != matchDeaths && tempDeaths > 0 && tempDeaths < 25)
			{
				char newVal = 0;
				matchDeaths = tempDeaths;
				deaths += matchDeaths;
				matchDeaths = 0;
				WriteProcessMemory(hProcess, (BYTE*)deathsAddress, &newVal, sizeof(newVal), 0);
			}

			//Read Assists
			std::vector<unsigned int> assistsOffsets = { 0x28, 0x30, 0x300 };
			uintptr_t assistsAddress = p.FindDMAAddy(hProcess, PlayerAddr, assistsOffsets);

			char tempAssists;
			ReadProcessMemory(hProcess, (BYTE*)assistsAddress, &tempAssists, sizeof(char), nullptr);
			if (tempAssists != matchAssists && tempAssists > 0 && tempAssists < 25)
			{
				char newVal = 0;
				matchAssists = tempAssists;
				assists += matchAssists;
				matchAssists = 0;
				WriteProcessMemory(hProcess, (BYTE*)assistsAddress, &newVal, sizeof(newVal), 0);
			}

			LvlSystem();
		}
		else
		{
			char newVal = 0;
			int resetExp = 0;
			if(killsAddress != NULL)
				WriteProcessMemory(hProcess, (BYTE*)killsAddress, &newVal, sizeof(newVal), 0);
			if(deathsAddress != NULL)
				WriteProcessMemory(hProcess, (BYTE*)deathsAddress, &newVal, sizeof(newVal), 0);
			if (expAddress != NULL)
				WriteProcessMemory(hProcess, (BYTE*)expAddress, &resetExp, sizeof(resetExp), 0);


		}

		//Update UI
		KillsValueText->Text = kills.ToString();
		DeathsValueText->Text = deaths.ToString();
		AssistsValueText->Text = assists.ToString();
		KDValueText->Text = kd().ToString("f2");
		WinsValueText->Text = wins.ToString();
		LossesValueText->Text = losses.ToString();
		WRValueText->Text = wr().ToString("f2");
		LvlText->Text = "Lvl: " + lvl;
		ExpValueText->Text = "Exp: " + totalXp + "/" + lvlXp;
	}
};
}

/*
For update:
-Read first the exp value (1 final value on scan)
-Find kills, deaths and assist with structures
-Find W/L values on SP matchs and after on custom game (4 final values)
-On Match value is static (4 final values, 1 static)
*/
