#pragma once
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <windows.h>

namespace SlotMachine {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Summary for Slot_Machine
	/// </summary>
	public ref class Slot_Machine : public System::Windows::Forms::Form
	{
	public:

		double rewardMultiplier;
		Slot_Machine(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		Slot_Machine(String^money, String^multiplier)
		{
			InitializeComponent();
			moneyAmountLbl->Text = money;
			// Stores the money value entered from the entry form 
			rewardMultiplier = System::Convert::ToDouble(multiplier); 
			// Stores the reward multiplier value entered from the entry form
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Slot_Machine()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ mrRobotLbl;
	private: System::Windows::Forms::Label^ allRewardLbl;

	protected:



	private: System::Windows::Forms::Label^ tripleLbl;
	private: System::Windows::Forms::Label^ tripleRewardLbl;

	private: System::Windows::Forms::Label^ grandPrizeLbl;



	private: System::Windows::Forms::Label^ slotLbl0;
	private: System::Windows::Forms::Label^ slotLbl1;
	private: System::Windows::Forms::Label^ slotLbl2;
	private: System::Windows::Forms::Label^ slotLbl3;






	private: System::Windows::Forms::TextBox^ insertTxb;


	private: System::Windows::Forms::Button^ insertBtn;




	private: System::Windows::Forms::Label^ moneyLbl;

	private: System::Windows::Forms::Label^ dollar3;





	private: System::Windows::Forms::Label^ moneyAmountLbl;

	private: System::Windows::Forms::Button^ playBtn;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ highScoreToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitGameToolStripMenuItem;
	private: System::Windows::Forms::Timer^ ColorRand;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;









	private: System::ComponentModel::IContainer^ components;
	protected:

	private:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Slot_Machine::typeid));
			this->mrRobotLbl = (gcnew System::Windows::Forms::Label());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->highScoreToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitGameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->allRewardLbl = (gcnew System::Windows::Forms::Label());
			this->tripleLbl = (gcnew System::Windows::Forms::Label());
			this->tripleRewardLbl = (gcnew System::Windows::Forms::Label());
			this->grandPrizeLbl = (gcnew System::Windows::Forms::Label());
			this->slotLbl0 = (gcnew System::Windows::Forms::Label());
			this->slotLbl1 = (gcnew System::Windows::Forms::Label());
			this->slotLbl2 = (gcnew System::Windows::Forms::Label());
			this->slotLbl3 = (gcnew System::Windows::Forms::Label());
			this->insertTxb = (gcnew System::Windows::Forms::TextBox());
			this->insertBtn = (gcnew System::Windows::Forms::Button());
			this->moneyLbl = (gcnew System::Windows::Forms::Label());
			this->dollar3 = (gcnew System::Windows::Forms::Label());
			this->moneyAmountLbl = (gcnew System::Windows::Forms::Label());
			this->playBtn = (gcnew System::Windows::Forms::Button());
			this->ColorRand = (gcnew System::Windows::Forms::Timer(this->components));
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// mrRobotLbl
			// 
			this->mrRobotLbl->AutoSize = true;
			this->mrRobotLbl->BackColor = System::Drawing::Color::Black;
			this->mrRobotLbl->ContextMenuStrip = this->contextMenuStrip1;
			this->mrRobotLbl->Font = (gcnew System::Drawing::Font(L"MrRobot", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mrRobotLbl->ForeColor = System::Drawing::Color::Red;
			this->mrRobotLbl->Location = System::Drawing::Point(65, 141);
			this->mrRobotLbl->Name = L"mrRobotLbl";
			this->mrRobotLbl->Size = System::Drawing::Size(363, 64);
			this->mrRobotLbl->TabIndex = 0;
			this->mrRobotLbl->Text = L"mr robot";
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->BackColor = System::Drawing::Color::White;
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->highScoreToolStripMenuItem,
					this->exitGameToolStripMenuItem, this->aboutToolStripMenuItem
			});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(181, 92);
			// 
			// highScoreToolStripMenuItem
			// 
			this->highScoreToolStripMenuItem->Name = L"highScoreToolStripMenuItem";
			this->highScoreToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->highScoreToolStripMenuItem->Text = L"Player Score";
			this->highScoreToolStripMenuItem->Click += gcnew System::EventHandler(this, &Slot_Machine::highScoreToolStripMenuItem_Click);
			// 
			// exitGameToolStripMenuItem
			// 
			this->exitGameToolStripMenuItem->Name = L"exitGameToolStripMenuItem";
			this->exitGameToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->exitGameToolStripMenuItem->Text = L"Exit Game";
			this->exitGameToolStripMenuItem->Click += gcnew System::EventHandler(this, &Slot_Machine::exitGameToolStripMenuItem_Click);
			// 
			// allRewardLbl
			// 
			this->allRewardLbl->AutoSize = true;
			this->allRewardLbl->BackColor = System::Drawing::Color::Black;
			this->allRewardLbl->ContextMenuStrip = this->contextMenuStrip1;
			this->allRewardLbl->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->allRewardLbl->Font = (gcnew System::Drawing::Font(L"HACKED", 59));
			this->allRewardLbl->ForeColor = System::Drawing::Color::Yellow;
			this->allRewardLbl->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->allRewardLbl->Location = System::Drawing::Point(12, 59);
			this->allRewardLbl->Name = L"allRewardLbl";
			this->allRewardLbl->Size = System::Drawing::Size(68, 82);
			this->allRewardLbl->TabIndex = 1;
			this->allRewardLbl->Text = L"$";
			this->allRewardLbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tripleLbl
			// 
			this->tripleLbl->AutoSize = true;
			this->tripleLbl->BackColor = System::Drawing::Color::Black;
			this->tripleLbl->ContextMenuStrip = this->contextMenuStrip1;
			this->tripleLbl->Font = (gcnew System::Drawing::Font(L"Impact", 36, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tripleLbl->ForeColor = System::Drawing::Color::Lime;
			this->tripleLbl->Location = System::Drawing::Point(74, 227);
			this->tripleLbl->Name = L"tripleLbl";
			this->tripleLbl->Size = System::Drawing::Size(149, 60);
			this->tripleLbl->TabIndex = 2;
			this->tripleLbl->Text = L"TRIPLE";
			// 
			// tripleRewardLbl
			// 
			this->tripleRewardLbl->AutoSize = true;
			this->tripleRewardLbl->BackColor = System::Drawing::Color::Black;
			this->tripleRewardLbl->ContextMenuStrip = this->contextMenuStrip1;
			this->tripleRewardLbl->Font = (gcnew System::Drawing::Font(L"Impact", 36, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tripleRewardLbl->ForeColor = System::Drawing::Color::Lime;
			this->tripleRewardLbl->Location = System::Drawing::Point(229, 227);
			this->tripleRewardLbl->Name = L"tripleRewardLbl";
			this->tripleRewardLbl->Size = System::Drawing::Size(51, 60);
			this->tripleRewardLbl->TabIndex = 3;
			this->tripleRewardLbl->Text = L"$";
			// 
			// grandPrizeLbl
			// 
			this->grandPrizeLbl->AutoSize = true;
			this->grandPrizeLbl->BackColor = System::Drawing::Color::Black;
			this->grandPrizeLbl->ContextMenuStrip = this->contextMenuStrip1;
			this->grandPrizeLbl->Font = (gcnew System::Drawing::Font(L"HACKED", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grandPrizeLbl->ForeColor = System::Drawing::Color::Yellow;
			this->grandPrizeLbl->Location = System::Drawing::Point(92, 9);
			this->grandPrizeLbl->Name = L"grandPrizeLbl";
			this->grandPrizeLbl->Size = System::Drawing::Size(302, 50);
			this->grandPrizeLbl->TabIndex = 4;
			this->grandPrizeLbl->Text = L"GRAND PRIZE!!!";
			// 
			// slotLbl0
			// 
			this->slotLbl0->AutoSize = true;
			this->slotLbl0->BackColor = System::Drawing::Color::WhiteSmoke;
			this->slotLbl0->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->slotLbl0->ContextMenuStrip = this->contextMenuStrip1;
			this->slotLbl0->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->slotLbl0->Font = (gcnew System::Drawing::Font(L"MrRobot", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->slotLbl0->ForeColor = System::Drawing::Color::Black;
			this->slotLbl0->Location = System::Drawing::Point(52, 363);
			this->slotLbl0->Name = L"slotLbl0";
			this->slotLbl0->Size = System::Drawing::Size(70, 66);
			this->slotLbl0->TabIndex = 5;
			this->slotLbl0->Text = L"$";
			this->slotLbl0->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// slotLbl1
			// 
			this->slotLbl1->AutoSize = true;
			this->slotLbl1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->slotLbl1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->slotLbl1->ContextMenuStrip = this->contextMenuStrip1;
			this->slotLbl1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->slotLbl1->Font = (gcnew System::Drawing::Font(L"MrRobot", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->slotLbl1->ForeColor = System::Drawing::Color::Black;
			this->slotLbl1->Location = System::Drawing::Point(153, 363);
			this->slotLbl1->Name = L"slotLbl1";
			this->slotLbl1->Size = System::Drawing::Size(70, 66);
			this->slotLbl1->TabIndex = 6;
			this->slotLbl1->Text = L"$";
			this->slotLbl1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// slotLbl2
			// 
			this->slotLbl2->AutoSize = true;
			this->slotLbl2->BackColor = System::Drawing::Color::WhiteSmoke;
			this->slotLbl2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->slotLbl2->ContextMenuStrip = this->contextMenuStrip1;
			this->slotLbl2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->slotLbl2->Font = (gcnew System::Drawing::Font(L"MrRobot", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->slotLbl2->ForeColor = System::Drawing::Color::Black;
			this->slotLbl2->Location = System::Drawing::Point(252, 363);
			this->slotLbl2->Name = L"slotLbl2";
			this->slotLbl2->Size = System::Drawing::Size(70, 66);
			this->slotLbl2->TabIndex = 7;
			this->slotLbl2->Text = L"$";
			this->slotLbl2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// slotLbl3
			// 
			this->slotLbl3->AutoSize = true;
			this->slotLbl3->BackColor = System::Drawing::Color::WhiteSmoke;
			this->slotLbl3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->slotLbl3->ContextMenuStrip = this->contextMenuStrip1;
			this->slotLbl3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->slotLbl3->Font = (gcnew System::Drawing::Font(L"MrRobot", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->slotLbl3->ForeColor = System::Drawing::Color::Black;
			this->slotLbl3->Location = System::Drawing::Point(349, 363);
			this->slotLbl3->Name = L"slotLbl3";
			this->slotLbl3->Size = System::Drawing::Size(70, 66);
			this->slotLbl3->TabIndex = 8;
			this->slotLbl3->Text = L"$";
			this->slotLbl3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// insertTxb
			// 
			this->insertTxb->BackColor = System::Drawing::Color::WhiteSmoke;
			this->insertTxb->ContextMenuStrip = this->contextMenuStrip1;
			this->insertTxb->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->insertTxb->Location = System::Drawing::Point(324, 519);
			this->insertTxb->Name = L"insertTxb";
			this->insertTxb->Size = System::Drawing::Size(70, 20);
			this->insertTxb->TabIndex = 11;
			this->insertTxb->Text = L"$$$";
			this->insertTxb->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->insertTxb->Click += gcnew System::EventHandler(this, &Slot_Machine::insertTxb_Click);
			// 
			// insertBtn
			// 
			this->insertBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->insertBtn->ContextMenuStrip = this->contextMenuStrip1;
			this->insertBtn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->insertBtn->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->insertBtn->ForeColor = System::Drawing::SystemColors::Control;
			this->insertBtn->Location = System::Drawing::Point(324, 545);
			this->insertBtn->Name = L"insertBtn";
			this->insertBtn->Size = System::Drawing::Size(70, 23);
			this->insertBtn->TabIndex = 12;
			this->insertBtn->Text = L"Insert";
			this->insertBtn->UseVisualStyleBackColor = false;
			this->insertBtn->Click += gcnew System::EventHandler(this, &Slot_Machine::insertBtn_Click);
			// 
			// moneyLbl
			// 
			this->moneyLbl->AutoSize = true;
			this->moneyLbl->BackColor = System::Drawing::Color::Transparent;
			this->moneyLbl->ContextMenuStrip = this->contextMenuStrip1;
			this->moneyLbl->Font = (gcnew System::Drawing::Font(L"Impact", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->moneyLbl->ForeColor = System::Drawing::Color::Lime;
			this->moneyLbl->Location = System::Drawing::Point(44, 504);
			this->moneyLbl->Name = L"moneyLbl";
			this->moneyLbl->Size = System::Drawing::Size(93, 34);
			this->moneyLbl->TabIndex = 13;
			this->moneyLbl->Text = L"Money:";
			// 
			// dollar3
			// 
			this->dollar3->AutoSize = true;
			this->dollar3->BackColor = System::Drawing::Color::Transparent;
			this->dollar3->ContextMenuStrip = this->contextMenuStrip1;
			this->dollar3->Font = (gcnew System::Drawing::Font(L"Impact", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dollar3->ForeColor = System::Drawing::Color::Lime;
			this->dollar3->Location = System::Drawing::Point(44, 538);
			this->dollar3->Name = L"dollar3";
			this->dollar3->Size = System::Drawing::Size(31, 34);
			this->dollar3->TabIndex = 14;
			this->dollar3->Text = L"$";
			// 
			// moneyAmountLbl
			// 
			this->moneyAmountLbl->AutoSize = true;
			this->moneyAmountLbl->BackColor = System::Drawing::Color::Transparent;
			this->moneyAmountLbl->ContextMenuStrip = this->contextMenuStrip1;
			this->moneyAmountLbl->Font = (gcnew System::Drawing::Font(L"Impact", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->moneyAmountLbl->ForeColor = System::Drawing::Color::Lime;
			this->moneyAmountLbl->Location = System::Drawing::Point(70, 538);
			this->moneyAmountLbl->Name = L"moneyAmountLbl";
			this->moneyAmountLbl->Size = System::Drawing::Size(30, 34);
			this->moneyAmountLbl->TabIndex = 15;
			this->moneyAmountLbl->Text = L"0";
			// 
			// playBtn
			// 
			this->playBtn->BackColor = System::Drawing::Color::Chartreuse;
			this->playBtn->ContextMenuStrip = this->contextMenuStrip1;
			this->playBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->playBtn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->playBtn->Font = (gcnew System::Drawing::Font(L"MrRobot", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->playBtn->Location = System::Drawing::Point(349, 465);
			this->playBtn->Name = L"playBtn";
			this->playBtn->Size = System::Drawing::Size(101, 39);
			this->playBtn->TabIndex = 17;
			this->playBtn->Text = L"PLAY";
			this->playBtn->UseVisualStyleBackColor = false;
			this->playBtn->Click += gcnew System::EventHandler(this, &Slot_Machine::playBtn_Click);
			// 
			// ColorRand
			// 
			this->ColorRand->Enabled = true;
			this->ColorRand->Interval = 1;
			this->ColorRand->Tick += gcnew System::EventHandler(this, &Slot_Machine::ColorRand_Tick);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Slot_Machine::aboutToolStripMenuItem_Click);
			// 
			// Slot_Machine
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(472, 594);
			this->ContextMenuStrip = this->contextMenuStrip1;
			this->Controls->Add(this->playBtn);
			this->Controls->Add(this->moneyAmountLbl);
			this->Controls->Add(this->dollar3);
			this->Controls->Add(this->moneyLbl);
			this->Controls->Add(this->insertBtn);
			this->Controls->Add(this->insertTxb);
			this->Controls->Add(this->slotLbl3);
			this->Controls->Add(this->slotLbl2);
			this->Controls->Add(this->slotLbl1);
			this->Controls->Add(this->slotLbl0);
			this->Controls->Add(this->grandPrizeLbl);
			this->Controls->Add(this->tripleRewardLbl);
			this->Controls->Add(this->tripleLbl);
			this->Controls->Add(this->allRewardLbl);
			this->Controls->Add(this->mrRobotLbl);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->DoubleBuffered = true;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Slot_Machine";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Mr Robot";
			this->Load += gcnew System::EventHandler(this, &Slot_Machine::Slot_Machine_Load);
			this->contextMenuStrip1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		double playerInput; 
		// Declared globally to be accessed anywhere inside the class

private: System::Void insertBtn_Click(System::Object^ sender, System::EventArgs^ e) 
{ 
	SoundPlayer^ sound = gcnew SoundPlayer;
	sound->SoundLocation = "C:\\Users\\Raphael Light\\Music\\slotmachinefx\\insert.wav";
	sound->Load();
	sound->Play(); //Plays button sound effect

	double money = System::Convert::ToDouble(moneyAmountLbl->Text);
	//Initializes money to the value of money amount label by converting its text to double

	if (money != 0)
	{
		playerInput = System::Convert::ToDouble(insertTxb->Text);
		// Initializes playerInput to the value entered in the insert textbox by converting its text to double
		double ALL_MATCH_REWARD = playerInput * rewardMultiplier; // Sets the All-Match Win reward value
		double THREE_MATCH_REWARD = playerInput * ((rewardMultiplier / 100) * 20); // Sets the Triple-Match Win reward value

		if (money - playerInput < 0) // Restricts the money label text to nonnegative values
			moneyAmountLbl->Text = System::Convert::ToString(0);
		else
			moneyAmountLbl->Text = System::Convert::ToString(money - playerInput);

		if (ALL_MATCH_REWARD <= 9999) // Corrects text alignment of All-Match Reward label
		{
			allRewardLbl->Left = 135;
			allRewardLbl->Text = "$" + System::Convert::ToString(ALL_MATCH_REWARD);
		}
		else if (ALL_MATCH_REWARD > 9999 && ALL_MATCH_REWARD <= 99999)
		{
			allRewardLbl->Left = 115;
			allRewardLbl->Text = "$" + System::Convert::ToString(ALL_MATCH_REWARD);
		}
		else if (ALL_MATCH_REWARD > 99999 && ALL_MATCH_REWARD <= 999999)
		{
			allRewardLbl->Left = 90;
			allRewardLbl->Text = "$" + System::Convert::ToString(ALL_MATCH_REWARD);
		}
		else if (ALL_MATCH_REWARD > 999999 && ALL_MATCH_REWARD <= 9999999)
		{
			allRewardLbl->Left = 75;
			allRewardLbl->Text = "$" + System::Convert::ToString(ALL_MATCH_REWARD);
		}
		else if (ALL_MATCH_REWARD > 9999999 && ALL_MATCH_REWARD <= 999999999)
		{
			allRewardLbl->Left = 37;
			allRewardLbl->Text = "$" + System::Convert::ToString(ALL_MATCH_REWARD);
		}
		else if (ALL_MATCH_REWARD > 999999999 && ALL_MATCH_REWARD <= 99999999999999)
		{
			allRewardLbl->Left = 15;
			allRewardLbl->Text = "$" + System::Convert::ToString(ALL_MATCH_REWARD);
		}
		else
		{
			allRewardLbl->Left = 135;
			allRewardLbl->Text = "$" + System::Convert::ToString(ALL_MATCH_REWARD);
		}

		if (THREE_MATCH_REWARD > 999999 && THREE_MATCH_REWARD <= 9999999) // Corrects text alignment of Triple-Match Reward label
		{
			tripleLbl->Left = 42;
			tripleRewardLbl->Left = 197;
			tripleRewardLbl->Text = "$" + System::Convert::ToString(THREE_MATCH_REWARD);
		}
		else if (THREE_MATCH_REWARD > 9999999 && THREE_MATCH_REWARD <= 99999999)
		{
			tripleLbl->Left = 30;
			tripleRewardLbl->Left = 185;
			tripleRewardLbl->Text = "$" + System::Convert::ToString(THREE_MATCH_REWARD);
		}
		else if (THREE_MATCH_REWARD > 99999999 && THREE_MATCH_REWARD <= 999999999)
		{
			tripleLbl->Left = 16;
			tripleRewardLbl->Left = 171;
			tripleRewardLbl->Text = "$" + System::Convert::ToString(THREE_MATCH_REWARD);
		}
		else if (THREE_MATCH_REWARD > 999999999 && THREE_MATCH_REWARD <= 99999999999999)
		{
			tripleLbl->Left = 2;
			tripleRewardLbl->Left = 157;
			tripleRewardLbl->Text = "$" + System::Convert::ToString(THREE_MATCH_REWARD);
		}
		else
		{
			tripleLbl->Left = 74;
			tripleRewardLbl->Left = 229;
			tripleRewardLbl->Text = "$" + System::Convert::ToString(THREE_MATCH_REWARD);
		}
	}
	else if (money == 0)
	{
		if (MessageBox::Show("You're out of luck. Friend. \n\n Slot Machines are all about luck. \n\n So best of luck next time.",
			"You Lost.", MessageBoxButtons::OK) == System::Windows::Forms::DialogResult::OK)
			Application::Exit();
	}
}
private: System::Void playBtn_Click(System::Object^ sender, System::EventArgs^ e) 
{
	SoundPlayer^sound = gcnew SoundPlayer;
	sound->SoundLocation = "C:\\Users\\Raphael Light\\Music\\slotmachinefx\\play.wav";
	sound->Load();
	sound->Play(); // Plays button sound effect

	std::ofstream fout;
	std::ifstream fin;
	// Declares fstream variables for storing player score
	System::Char slotSymbols[6] = { '#','$','7','9','O','*' };
	System::Char slots[4];
	// Initializes slot machine symbols and slot machine slots
	double money = System::Convert::ToDouble(moneyAmountLbl->Text);
	// Initializes money to the value of money amount label by converting its text to double
	double reward; // Stores reward
	int playerScore1, playerScore2; 
	// Stores All-Match Wins and Triple-Match Wins respectively
	static int player_score1 = 0;
	static int player_score2 = 0;
	// Player score counters

	if (money >= 0 && playerInput > 0)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(500)); 
		// Half a second delay so as not to overlap with play button sound effect
		sound->SoundLocation = "C:\\Users\\Raphael Light\\Music\\slotmachinefx\\slot_machine_wheel.wav";
		sound->Load();
		sound->Play(); // Plays slot machine rolling sound effect

		std::this_thread::sleep_for(std::chrono::milliseconds(4000)); // Four seconds delay as the slot machine rolls
		srand(time(0));
		for (int i = 0; i <= 3; i++) 
			slots[i] = slotSymbols[rand() % 6]; // Slot symbol setter and randomizer
		slotLbl0->Text = System::Convert::ToString(slots[0]);
		slotLbl1->Text = System::Convert::ToString(slots[1]);
		slotLbl2->Text = System::Convert::ToString(slots[2]);
		slotLbl3->Text = System::Convert::ToString(slots[3]);

		if (slotLbl0->Text == slotLbl1->Text && slotLbl0->Text == slotLbl2->Text && slotLbl0->Text == slotLbl3->Text)
		{
			sound->SoundLocation = "C:\\Users\\Raphael Light\\Music\\slotmachinefx\\slot_machine_win.wav";
			sound->Load();
			sound->Play(); // Plays slot machine All-Match Win sound effect
			reward = playerInput * rewardMultiplier; // Sets the reward value times the full value of the reward multiplier
			money = money + reward; // Adds the reward value to the amount of money
			if (MessageBox::Show("YOU WON!!!\n\n Your reward is $" + reward + "\n Your money is now $" + money + "\n\n Do you still want to play?",
				"ALL-MATCH WIN!!!", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::No) 
				Application::Exit();
			// Winning prompt
			moneyAmountLbl->Text = System::Convert::ToString(money); // Updates the money amount label
			player_score1++; // Increments All-Match Wins score
		}
		else if (slotLbl0->Text == slotLbl1->Text && slotLbl0->Text == slotLbl2->Text || slotLbl1->Text == slotLbl2->Text && slotLbl1->Text == slotLbl3->Text)
		{
			sound->SoundLocation = "C:\\Users\\Raphael Light\\Music\\slotmachinefx\\slot_machine_triples.wav";
			sound->Load();
			sound->Play(); // Plays slot machine Triple-Match Win sound effect
			reward = playerInput * ((rewardMultiplier / 100) * 20); // Sets the reward value times the 20% value of the reward multiplier
			money = money + reward; // Adds the reward value to the amount of money
			if (MessageBox::Show("TRIPLE MATCH! You win $" + reward + "\n Your money is now $" + money + "\n\n Do you still want to play?",
				"TRIPLE-MATCH WIN!!!", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::No)
				Application::Exit();
			// Winning prompt
			moneyAmountLbl->Text = System::Convert::ToString(money); // Updates the money amount label
			player_score2++; // Increments Triple-Match Wins score
		}
		playerInput = 0; // Resets player input
	}
	else
	{
		MessageBox::Show("Insert your money.", "Insert Money", MessageBoxButtons::OK, MessageBoxIcon::Information);
		// Insert money prompt
	}
	fout.open("playerscore.txt");
	fin.open("playerscore.txt");
	// Opens player score save file
	if (fin.peek() == std::ifstream::traits_type::eof()) // Checks if the file is empty
	{
		// Sets the player score record to the score counter
		playerScore1 = player_score1;
		playerScore2 = player_score2;
		fout << playerScore1 << " " << playerScore2;
	}
	fin >> playerScore1 >> playerScore2; // Gets player score values
	if (player_score1 > playerScore1)
	{
		// Records All-Match Win score
		playerScore1 = player_score1;
		fout << playerScore1 << " ";
	}
	if (player_score2 > playerScore2)
	{
		// Records Triple-Match Win score
		playerScore2 = player_score2;
		fout << playerScore2 << " ";
	}
	fout.close();
	fin.close();
	// File close
	
	// NOTE: The player score record was originally meant for high score record, 
	//		 but after spending hours making it work, I wasn't able to identify
	//		 the reason why the conditions in the conditional statements doesn't work properly.
	//		 They do work in terms of recording the current score but not for keeping it until a greater score is detected.
	//		 Thus, I made it a player score record instead. Although you can still see the logical inconsistencies.
}

private: System::Void exitGameToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
{
	// Context Tool Strip, Exit Game
	Application::Exit(); 
}
private: System::Void highScoreToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) // Context Tool Strip, View Player Score
{
	// Context Tool Strip, View Player Score
	std::ifstream fin;
	double playerScore1, playerScore2;
	fin.open("playerscore.txt");
	fin >> playerScore1 >> playerScore2;
	MessageBox::Show("All-Match Wins: " + playerScore1 + "\n Triple-Match Wins: " + playerScore2, "Player Score", MessageBoxButtons::OK);
	fin.close();
}
private: System::Void aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	// Context Tool Strip, About Game
	MessageBox::Show("Hello, friend.\n\n Welcome to Mr Robot Slot Machine.\n The rule of this slot machine is simple." +
		"\n The greater the bet, the greater the reward.\n The more money you insert, the greater your reward will be.\n\n Goodluck, friend.", "About", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
private: System::Void insertTxb_Click(System::Object^ sender, System::EventArgs^ e)
{
	// Deletes money prompt upon clicking insert textbox for the first time
	if (insertTxb->Text == "$$$")
		insertTxb->Text = "";
}
private: System::Void ColorRand_Tick(System::Object^ sender, System::EventArgs^ e) 
{
	// Color randomizer for prize labels
	srand(time(0));
	grandPrizeLbl->ForeColor = Color::FromArgb(rand() % 256, rand() % 256, rand() % 256, rand() % 256);
	tripleLbl->ForeColor = Color::FromArgb(rand() % 256, rand() % 256, rand() % 256, rand() % 256);
}
private: System::Void Slot_Machine_Load(System::Object^ sender, System::EventArgs^ e) 
{
	// Color randomizer initialized
	ColorRand->Start();
	ColorRand->Enabled = true;
}
};
}
