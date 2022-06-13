#pragma once
#include "DataBase.h"

namespace Hotel {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::SqlClient;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			textDateOfBirth->Text = "mm.dd.yyyy";
			textDateOfIssueOfPassport->Text = "mm.dd.yyyy";
		}

		bool isRoomFree() {
			DataBase^ db = gcnew DataBase();
			DataTable^ table = gcnew DataTable();
			SqlDataAdapter^ adapter = gcnew SqlDataAdapter();

			SqlCommand^ command = gcnew SqlCommand("SELECT * FROM Rooms WHERE TypeOfRoom = @tor AND DaysOfReservation = 0", db->getConnection());
			command->Parameters->Add("@tor", SqlDbType::Char)->Value = textTypeOfRoom->Text;

			adapter->SelectCommand = command;
			adapter->Fill(table);

			if (table->Rows->Count > 0)
				return false;
			else {
				labelStatus->Text = "All Rooms with that parameters are occupied!";
				return true;
			}				
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labelRoomReservation;
	protected:
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ labelSurname;
	private: System::Windows::Forms::Label^ labelName;
	private: System::Windows::Forms::Label^ labelMiddleName;
	private: System::Windows::Forms::Label^ labelDateOfBirth;
	private: System::Windows::Forms::Label^ labelDateOfIssueOfPassport;
	private: System::Windows::Forms::Label^ labelPassportSeries;
	private: System::Windows::Forms::Label^ labelPassportID;
	private: System::Windows::Forms::Label^ labelTypeOfRoom;
	private: System::Windows::Forms::Label^ labelDaysOfReservation;
	private: System::Windows::Forms::Button^ buttonReserve;
	private: System::Windows::Forms::Button^ buttonExit;
	private: System::Windows::Forms::Panel^ panel2;
	private: ZBobb::AlphaBlendTextBox^ textSurname;
	private: ZBobb::AlphaBlendTextBox^ textName;

	private: System::Windows::Forms::Panel^ panel3;
	private: ZBobb::AlphaBlendTextBox^ textMiddleName;

	private: System::Windows::Forms::Panel^ panel4;
	private: ZBobb::AlphaBlendTextBox^ textDateOfBirth;

	private: System::Windows::Forms::Panel^ panel5;
	private: ZBobb::AlphaBlendTextBox^ textDateOfIssueOfPassport;

	private: System::Windows::Forms::Panel^ panel6;
	private: ZBobb::AlphaBlendTextBox^ textPassportSeries;

	private: System::Windows::Forms::Panel^ panel7;
	private: ZBobb::AlphaBlendTextBox^ textPassportID;

	private: System::Windows::Forms::Panel^ panel8;
	private: ZBobb::AlphaBlendTextBox^ textDaysOfReservation;

	private: System::Windows::Forms::Panel^ panel9;
	private: System::Windows::Forms::ComboBox^ textTypeOfRoom;
	private: System::Windows::Forms::Label^ labelStatus;
	private: System::Windows::Forms::Button^ buttonReloadDB;




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->labelRoomReservation = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->labelSurname = (gcnew System::Windows::Forms::Label());
			this->labelName = (gcnew System::Windows::Forms::Label());
			this->labelMiddleName = (gcnew System::Windows::Forms::Label());
			this->labelDateOfBirth = (gcnew System::Windows::Forms::Label());
			this->labelDateOfIssueOfPassport = (gcnew System::Windows::Forms::Label());
			this->labelPassportSeries = (gcnew System::Windows::Forms::Label());
			this->labelPassportID = (gcnew System::Windows::Forms::Label());
			this->labelTypeOfRoom = (gcnew System::Windows::Forms::Label());
			this->labelDaysOfReservation = (gcnew System::Windows::Forms::Label());
			this->buttonReserve = (gcnew System::Windows::Forms::Button());
			this->buttonExit = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->textSurname = (gcnew ZBobb::AlphaBlendTextBox());
			this->textName = (gcnew ZBobb::AlphaBlendTextBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->textMiddleName = (gcnew ZBobb::AlphaBlendTextBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->textDateOfBirth = (gcnew ZBobb::AlphaBlendTextBox());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->textDateOfIssueOfPassport = (gcnew ZBobb::AlphaBlendTextBox());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->textPassportSeries = (gcnew ZBobb::AlphaBlendTextBox());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->textPassportID = (gcnew ZBobb::AlphaBlendTextBox());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->textDaysOfReservation = (gcnew ZBobb::AlphaBlendTextBox());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->textTypeOfRoom = (gcnew System::Windows::Forms::ComboBox());
			this->labelStatus = (gcnew System::Windows::Forms::Label());
			this->buttonReloadDB = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// labelRoomReservation
			// 
			this->labelRoomReservation->AutoSize = true;
			this->labelRoomReservation->BackColor = System::Drawing::Color::Transparent;
			this->labelRoomReservation->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20));
			this->labelRoomReservation->Location = System::Drawing::Point(423, 57);
			this->labelRoomReservation->Name = L"labelRoomReservation";
			this->labelRoomReservation->Size = System::Drawing::Size(231, 37);
			this->labelRoomReservation->TabIndex = 0;
			this->labelRoomReservation->Text = L"Room Reservation";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->Location = System::Drawing::Point(432, 94);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(211, 2);
			this->panel1->TabIndex = 1;
			// 
			// labelSurname
			// 
			this->labelSurname->AutoSize = true;
			this->labelSurname->BackColor = System::Drawing::Color::Transparent;
			this->labelSurname->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F));
			this->labelSurname->Location = System::Drawing::Point(356, 121);
			this->labelSurname->Name = L"labelSurname";
			this->labelSurname->Size = System::Drawing::Size(67, 20);
			this->labelSurname->TabIndex = 2;
			this->labelSurname->Text = L"Surname";
			// 
			// labelName
			// 
			this->labelName->AutoSize = true;
			this->labelName->BackColor = System::Drawing::Color::Transparent;
			this->labelName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F));
			this->labelName->Location = System::Drawing::Point(356, 146);
			this->labelName->Name = L"labelName";
			this->labelName->Size = System::Drawing::Size(49, 20);
			this->labelName->TabIndex = 3;
			this->labelName->Text = L"Name";
			// 
			// labelMiddleName
			// 
			this->labelMiddleName->AutoSize = true;
			this->labelMiddleName->BackColor = System::Drawing::Color::Transparent;
			this->labelMiddleName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F));
			this->labelMiddleName->Location = System::Drawing::Point(356, 171);
			this->labelMiddleName->Name = L"labelMiddleName";
			this->labelMiddleName->Size = System::Drawing::Size(100, 20);
			this->labelMiddleName->TabIndex = 4;
			this->labelMiddleName->Text = L"Middle Name";
			// 
			// labelDateOfBirth
			// 
			this->labelDateOfBirth->AutoSize = true;
			this->labelDateOfBirth->BackColor = System::Drawing::Color::Transparent;
			this->labelDateOfBirth->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F));
			this->labelDateOfBirth->Location = System::Drawing::Point(356, 196);
			this->labelDateOfBirth->Name = L"labelDateOfBirth";
			this->labelDateOfBirth->Size = System::Drawing::Size(94, 20);
			this->labelDateOfBirth->TabIndex = 5;
			this->labelDateOfBirth->Text = L"Date of Birth";
			// 
			// labelDateOfIssueOfPassport
			// 
			this->labelDateOfIssueOfPassport->AutoSize = true;
			this->labelDateOfIssueOfPassport->BackColor = System::Drawing::Color::Transparent;
			this->labelDateOfIssueOfPassport->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F));
			this->labelDateOfIssueOfPassport->Location = System::Drawing::Point(356, 221);
			this->labelDateOfIssueOfPassport->Name = L"labelDateOfIssueOfPassport";
			this->labelDateOfIssueOfPassport->Size = System::Drawing::Size(172, 20);
			this->labelDateOfIssueOfPassport->TabIndex = 6;
			this->labelDateOfIssueOfPassport->Text = L"Date of Issue of Passport";
			// 
			// labelPassportSeries
			// 
			this->labelPassportSeries->AutoSize = true;
			this->labelPassportSeries->BackColor = System::Drawing::Color::Transparent;
			this->labelPassportSeries->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F));
			this->labelPassportSeries->Location = System::Drawing::Point(356, 246);
			this->labelPassportSeries->Name = L"labelPassportSeries";
			this->labelPassportSeries->Size = System::Drawing::Size(107, 20);
			this->labelPassportSeries->TabIndex = 7;
			this->labelPassportSeries->Text = L"Passport Series";
			// 
			// labelPassportID
			// 
			this->labelPassportID->AutoSize = true;
			this->labelPassportID->BackColor = System::Drawing::Color::Transparent;
			this->labelPassportID->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F));
			this->labelPassportID->Location = System::Drawing::Point(356, 271);
			this->labelPassportID->Name = L"labelPassportID";
			this->labelPassportID->Size = System::Drawing::Size(83, 20);
			this->labelPassportID->TabIndex = 8;
			this->labelPassportID->Text = L"Passport ID";
			// 
			// labelTypeOfRoom
			// 
			this->labelTypeOfRoom->AutoSize = true;
			this->labelTypeOfRoom->BackColor = System::Drawing::Color::Transparent;
			this->labelTypeOfRoom->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F));
			this->labelTypeOfRoom->Location = System::Drawing::Point(356, 300);
			this->labelTypeOfRoom->Name = L"labelTypeOfRoom";
			this->labelTypeOfRoom->Size = System::Drawing::Size(102, 20);
			this->labelTypeOfRoom->TabIndex = 9;
			this->labelTypeOfRoom->Text = L"Type of Room";
			// 
			// labelDaysOfReservation
			// 
			this->labelDaysOfReservation->AutoSize = true;
			this->labelDaysOfReservation->BackColor = System::Drawing::Color::Transparent;
			this->labelDaysOfReservation->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F));
			this->labelDaysOfReservation->Location = System::Drawing::Point(356, 326);
			this->labelDaysOfReservation->Name = L"labelDaysOfReservation";
			this->labelDaysOfReservation->Size = System::Drawing::Size(140, 20);
			this->labelDaysOfReservation->TabIndex = 10;
			this->labelDaysOfReservation->Text = L"Days of Reservation";
			// 
			// buttonReserve
			// 
			this->buttonReserve->BackColor = System::Drawing::Color::White;
			this->buttonReserve->FlatAppearance->BorderSize = 0;
			this->buttonReserve->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->buttonReserve->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->buttonReserve->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonReserve->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F));
			this->buttonReserve->ForeColor = System::Drawing::Color::Black;
			this->buttonReserve->Location = System::Drawing::Point(415, 380);
			this->buttonReserve->Name = L"buttonReserve";
			this->buttonReserve->Size = System::Drawing::Size(113, 38);
			this->buttonReserve->TabIndex = 11;
			this->buttonReserve->Text = L"Reserve";
			this->buttonReserve->UseVisualStyleBackColor = false;
			this->buttonReserve->Click += gcnew System::EventHandler(this, &MainForm::buttonReserve_Click);
			// 
			// buttonExit
			// 
			this->buttonExit->BackColor = System::Drawing::Color::Transparent;
			this->buttonExit->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->buttonExit->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->buttonExit->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->buttonExit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonExit->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F));
			this->buttonExit->ForeColor = System::Drawing::Color::White;
			this->buttonExit->Location = System::Drawing::Point(564, 380);
			this->buttonExit->Name = L"buttonExit";
			this->buttonExit->Size = System::Drawing::Size(113, 38);
			this->buttonExit->TabIndex = 12;
			this->buttonExit->Text = L"Exit";
			this->buttonExit->UseVisualStyleBackColor = false;
			this->buttonExit->Click += gcnew System::EventHandler(this, &MainForm::buttonExit_Click);
			// 
			// panel2
			// 
			this->panel2->Location = System::Drawing::Point(542, 143);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(186, 2);
			this->panel2->TabIndex = 14;
			// 
			// textSurname
			// 
			this->textSurname->BackAlpha = 0;
			this->textSurname->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->textSurname->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textSurname->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F));
			this->textSurname->ForeColor = System::Drawing::Color::White;
			this->textSurname->Location = System::Drawing::Point(542, 121);
			this->textSurname->Name = L"textSurname";
			this->textSurname->Size = System::Drawing::Size(186, 20);
			this->textSurname->TabIndex = 15;
			this->textSurname->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::textSurname_KeyDown);
			// 
			// textName
			// 
			this->textName->BackAlpha = 0;
			this->textName->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->textName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F));
			this->textName->ForeColor = System::Drawing::Color::White;
			this->textName->Location = System::Drawing::Point(542, 146);
			this->textName->Name = L"textName";
			this->textName->Size = System::Drawing::Size(186, 20);
			this->textName->TabIndex = 17;
			this->textName->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::textSurname_KeyDown);
			// 
			// panel3
			// 
			this->panel3->Location = System::Drawing::Point(542, 168);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(186, 2);
			this->panel3->TabIndex = 16;
			// 
			// textMiddleName
			// 
			this->textMiddleName->BackAlpha = 0;
			this->textMiddleName->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->textMiddleName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textMiddleName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F));
			this->textMiddleName->ForeColor = System::Drawing::Color::White;
			this->textMiddleName->Location = System::Drawing::Point(542, 171);
			this->textMiddleName->Name = L"textMiddleName";
			this->textMiddleName->Size = System::Drawing::Size(186, 20);
			this->textMiddleName->TabIndex = 19;
			this->textMiddleName->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::textSurname_KeyDown);
			// 
			// panel4
			// 
			this->panel4->Location = System::Drawing::Point(542, 193);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(186, 2);
			this->panel4->TabIndex = 18;
			// 
			// textDateOfBirth
			// 
			this->textDateOfBirth->BackAlpha = 0;
			this->textDateOfBirth->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->textDateOfBirth->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textDateOfBirth->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F));
			this->textDateOfBirth->ForeColor = System::Drawing::Color::White;
			this->textDateOfBirth->Location = System::Drawing::Point(542, 196);
			this->textDateOfBirth->Name = L"textDateOfBirth";
			this->textDateOfBirth->Size = System::Drawing::Size(186, 20);
			this->textDateOfBirth->TabIndex = 21;
			this->textDateOfBirth->Enter += gcnew System::EventHandler(this, &MainForm::textDateOfBirth_Enter);
			this->textDateOfBirth->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::textSurname_KeyDown);
			this->textDateOfBirth->Leave += gcnew System::EventHandler(this, &MainForm::textDateOfBirth_Leave);
			// 
			// panel5
			// 
			this->panel5->Location = System::Drawing::Point(542, 218);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(186, 2);
			this->panel5->TabIndex = 20;
			// 
			// textDateOfIssueOfPassport
			// 
			this->textDateOfIssueOfPassport->BackAlpha = 0;
			this->textDateOfIssueOfPassport->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->textDateOfIssueOfPassport->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textDateOfIssueOfPassport->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F));
			this->textDateOfIssueOfPassport->ForeColor = System::Drawing::Color::White;
			this->textDateOfIssueOfPassport->Location = System::Drawing::Point(542, 221);
			this->textDateOfIssueOfPassport->Name = L"textDateOfIssueOfPassport";
			this->textDateOfIssueOfPassport->Size = System::Drawing::Size(186, 20);
			this->textDateOfIssueOfPassport->TabIndex = 23;
			this->textDateOfIssueOfPassport->Enter += gcnew System::EventHandler(this, &MainForm::textDateOfIssueOfPassport_Enter);
			this->textDateOfIssueOfPassport->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::textSurname_KeyDown);
			this->textDateOfIssueOfPassport->Leave += gcnew System::EventHandler(this, &MainForm::textDateOfIssueOfPassport_Leave);
			// 
			// panel6
			// 
			this->panel6->Location = System::Drawing::Point(542, 243);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(186, 2);
			this->panel6->TabIndex = 22;
			// 
			// textPassportSeries
			// 
			this->textPassportSeries->BackAlpha = 0;
			this->textPassportSeries->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->textPassportSeries->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textPassportSeries->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F));
			this->textPassportSeries->ForeColor = System::Drawing::Color::White;
			this->textPassportSeries->Location = System::Drawing::Point(542, 246);
			this->textPassportSeries->Name = L"textPassportSeries";
			this->textPassportSeries->Size = System::Drawing::Size(186, 20);
			this->textPassportSeries->TabIndex = 25;
			this->textPassportSeries->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::textSurname_KeyDown);
			// 
			// panel7
			// 
			this->panel7->Location = System::Drawing::Point(542, 268);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(186, 2);
			this->panel7->TabIndex = 24;
			// 
			// textPassportID
			// 
			this->textPassportID->BackAlpha = 0;
			this->textPassportID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->textPassportID->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textPassportID->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F));
			this->textPassportID->ForeColor = System::Drawing::Color::White;
			this->textPassportID->Location = System::Drawing::Point(542, 271);
			this->textPassportID->Name = L"textPassportID";
			this->textPassportID->Size = System::Drawing::Size(186, 20);
			this->textPassportID->TabIndex = 27;
			this->textPassportID->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::textSurname_KeyDown);
			// 
			// panel8
			// 
			this->panel8->Location = System::Drawing::Point(542, 293);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(186, 2);
			this->panel8->TabIndex = 26;
			// 
			// textDaysOfReservation
			// 
			this->textDaysOfReservation->BackAlpha = 0;
			this->textDaysOfReservation->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->textDaysOfReservation->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textDaysOfReservation->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F));
			this->textDaysOfReservation->ForeColor = System::Drawing::Color::White;
			this->textDaysOfReservation->Location = System::Drawing::Point(542, 326);
			this->textDaysOfReservation->Name = L"textDaysOfReservation";
			this->textDaysOfReservation->Size = System::Drawing::Size(186, 20);
			this->textDaysOfReservation->TabIndex = 29;
			this->textDaysOfReservation->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::textSurname_KeyDown);
			// 
			// panel9
			// 
			this->panel9->Location = System::Drawing::Point(542, 348);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(186, 2);
			this->panel9->TabIndex = 28;
			// 
			// textTypeOfRoom
			// 
			this->textTypeOfRoom->BackColor = System::Drawing::Color::White;
			this->textTypeOfRoom->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->textTypeOfRoom->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F));
			this->textTypeOfRoom->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Standard", L"Suite", L"Business" });
			this->textTypeOfRoom->Location = System::Drawing::Point(542, 296);
			this->textTypeOfRoom->Name = L"textTypeOfRoom";
			this->textTypeOfRoom->Size = System::Drawing::Size(186, 28);
			this->textTypeOfRoom->TabIndex = 30;
			// 
			// labelStatus
			// 
			this->labelStatus->AutoSize = true;
			this->labelStatus->BackColor = System::Drawing::Color::Transparent;
			this->labelStatus->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelStatus->Location = System::Drawing::Point(382, 446);
			this->labelStatus->Name = L"labelStatus";
			this->labelStatus->Size = System::Drawing::Size(0, 21);
			this->labelStatus->TabIndex = 31;
			// 
			// buttonReloadDB
			// 
			this->buttonReloadDB->BackColor = System::Drawing::Color::Transparent;
			this->buttonReloadDB->FlatAppearance->BorderSize = 0;
			this->buttonReloadDB->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->buttonReloadDB->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->buttonReloadDB->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonReloadDB->Location = System::Drawing::Point(1075, 539);
			this->buttonReloadDB->Name = L"buttonReloadDB";
			this->buttonReloadDB->Size = System::Drawing::Size(20, 20);
			this->buttonReloadDB->TabIndex = 32;
			this->buttonReloadDB->UseVisualStyleBackColor = false;
			this->buttonReloadDB->Click += gcnew System::EventHandler(this, &MainForm::buttonReloadDB_Click);
			// 
			// MainForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1095, 559);
			this->Controls->Add(this->buttonReloadDB);
			this->Controls->Add(this->labelStatus);
			this->Controls->Add(this->textTypeOfRoom);
			this->Controls->Add(this->textDaysOfReservation);
			this->Controls->Add(this->panel9);
			this->Controls->Add(this->textPassportID);
			this->Controls->Add(this->panel8);
			this->Controls->Add(this->textPassportSeries);
			this->Controls->Add(this->panel7);
			this->Controls->Add(this->textDateOfIssueOfPassport);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->textDateOfBirth);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->textMiddleName);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->textName);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->textSurname);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->buttonExit);
			this->Controls->Add(this->buttonReserve);
			this->Controls->Add(this->labelDaysOfReservation);
			this->Controls->Add(this->labelTypeOfRoom);
			this->Controls->Add(this->labelPassportID);
			this->Controls->Add(this->labelPassportSeries);
			this->Controls->Add(this->labelDateOfIssueOfPassport);
			this->Controls->Add(this->labelDateOfBirth);
			this->Controls->Add(this->labelMiddleName);
			this->Controls->Add(this->labelName);
			this->Controls->Add(this->labelSurname);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->labelRoomReservation);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MainForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Room Reservation";
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void buttonReserve_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textSurname->Text == "" || textName->Text == "" || textDateOfBirth->Text == "mm.dd.yyyy" ||
		textDateOfIssueOfPassport->Text == "mm.dd.yyyy" || textPassportSeries->Text == "" ||
		textPassportID->Text == "" || textTypeOfRoom->Text == "" || textDaysOfReservation->Text == "") {
		labelStatus->Text = "                       Fill in all the Fields!";
		return;
	}

	if (isRoomFree())
		return;

	DataBase^ db = gcnew DataBase();
	SqlCommand^ command = gcnew SqlCommand("INSERT INTO Clients (Surname, Name, MiddleName, DateOfBirth, DateOfIssueOfPassport, PassportSeries, PassportID) VALUES (@sur, @name, @middle, @dob, @doiop, @ps, @pid); UPDATE Rooms SET DaysOfReservation = @dor, ID_Client = (SELECT max(ID_Client) FROM Clients) WHERE TypeOfRoom = @tor AND DaysOfReservation = 0 AND ID_Room = (SELECT min(ID_Room) FROM Rooms WHERE DaysOfReservation = 0 AND TypeOfRoom = @tor); SELECT RoomNumber FROM Rooms WHERE ID_Client = (SELECT max(ID_Client) FROM Clients);", db->getConnection());
	command->Parameters->Add("@sur", SqlDbType::Char)->Value = textSurname->Text;
	command->Parameters->Add("@name", SqlDbType::Char)->Value = textName->Text;
	command->Parameters->Add("@middle", SqlDbType::Char)->Value = textMiddleName->Text;
	command->Parameters->Add("@dob", SqlDbType::Date)->Value = Convert::ToString(textDateOfBirth->Text);
	command->Parameters->Add("@doiop", SqlDbType::Date)->Value = Convert::ToString(textDateOfIssueOfPassport->Text);
	command->Parameters->Add("@ps", SqlDbType::Int)->Value = textPassportSeries->Text;
	command->Parameters->Add("@pid", SqlDbType::Int)->Value = textPassportID->Text;
	command->Parameters->Add("@tor", SqlDbType::Char)->Value = textTypeOfRoom->Text;
	command->Parameters->Add("@dor", SqlDbType::Int)->Value = textDaysOfReservation->Text;

	db->openConnection();

	int n;

	if (SqlDataReader^ reader = command->ExecuteReader()) {
		while (reader->Read())
			n = Convert::ToInt32(reader["RoomNumber"]->ToString());
		labelStatus->Text = "                 You are reserving a Room!\n               You can go to the Room ¹" + n;
	}
	else
		labelStatus->Text = "All Rooms with that parameters are occupied!";

	db->closeConnection();
}
	private: System::Void buttonExit_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
private: System::Void textDateOfBirth_Enter(System::Object^ sender, System::EventArgs^ e) {
	if (this->textDateOfBirth->Text == "mm.dd.yyyy")
		this->textDateOfBirth->Text = "";
}
private: System::Void textDateOfBirth_Leave(System::Object^ sender, System::EventArgs^ e) {
	if (this->textDateOfBirth->Text == "")
		this->textDateOfBirth->Text = "mm.dd.yyyy";
}
private: System::Void textDateOfIssueOfPassport_Enter(System::Object^ sender, System::EventArgs^ e) {
	if (this->textDateOfIssueOfPassport->Text == "mm.dd.yyyy")
		this->textDateOfIssueOfPassport->Text = "";
}
private: System::Void textDateOfIssueOfPassport_Leave(System::Object^ sender, System::EventArgs^ e) {
	if (this->textDateOfIssueOfPassport->Text == "")
		this->textDateOfIssueOfPassport->Text = "mm.dd.yyyy";
}
private: System::Void textSurname_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyValue == (int)Keys::Enter) {
		buttonReserve->PerformClick();
	}
}

	   bool dragging;
	   Point offset;
private: System::Void MainForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	dragging = true;
	offset.X = e->X;
	offset.Y = e->Y;
}
private: System::Void MainForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (dragging) {
		Point currentScreenPos = PointToScreen(Point(e->X - offset.X, e->Y - offset.Y));
		Location = currentScreenPos;
	}
}
private: System::Void MainForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	dragging = false;
}
private: System::Void buttonReloadDB_Click(System::Object^ sender, System::EventArgs^ e) {
	DataBase^ db = gcnew DataBase();
	SqlCommand^ command = gcnew SqlCommand("DELETE FROM Clients; DBCC CHECKIDENT('HOTEL.dbo.Clients', RESEED, 0); TRUNCATE TABLE Rooms; INSERT INTO Rooms (RoomNumber, TypeOfRoom, DaysOfReservation) VALUES (10, 'Standard', 0), (11, 'Standard', 0), (12, 'Standard', 0), (13, 'Standard', 0), (14, 'Standard', 0), (15, 'Standard', 0), (20, 'Suite', 0), (21, 'Suite', 0), (22, 'Suite', 0), (23, 'Suite', 0), (24, 'Suite', 0), (25, 'Suite', 0), (30, 'Business', 0), (31, 'Business', 0), (32, 'Business', 0), (33, 'Business', 0), (34, 'Business', 0), (35, 'Business', 0);", db->getConnection());

	db->openConnection();

	if (command->ExecuteNonQuery())
		labelStatus->Text = "                     All Tables are cleared!";
	else
		labelStatus->Text = "                       Tables not cleared!";

	db->closeConnection();
}
};
}
