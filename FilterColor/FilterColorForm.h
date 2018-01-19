#pragma once

namespace TGMT {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FilterColorForm
	/// </summary>
	public ref class FilterColorForm : public System::Windows::Forms::Form
	{		
		int iLowH = 0;
		int iHighH = 179;

		int iLowS = 0;
		int iHighS = 255;

		int iLowV = 0;
		int m_blurSize;
	private: System::Windows::Forms::NumericUpDown^  numHmin;
	private: System::Windows::Forms::NumericUpDown^  numHmax;
	private: System::Windows::Forms::NumericUpDown^  numSmin;
	private: System::Windows::Forms::NumericUpDown^  numSmax;
	private: System::Windows::Forms::NumericUpDown^  numVmin;
	private: System::Windows::Forms::NumericUpDown^  numVmax;
	private: System::Windows::Forms::Label^  lblBlur;
	private: System::Windows::Forms::Button^  btnCount;
	private: System::Windows::Forms::Label^  lblCount;


			 int iHighV = 255;
		void FilterColor();



	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TrackBar^  trackBar7;
			 
	public:
		FilterColorForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FilterColorForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TrackBar^  trackBar1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TrackBar^  trackBar2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TrackBar^  trackBar3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TrackBar^  trackBar4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TrackBar^  trackBar5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TrackBar^  trackBar6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  txtFilePath;

	private: System::Windows::Forms::Button^  btnBrowse;














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
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->trackBar3 = (gcnew System::Windows::Forms::TrackBar());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->trackBar4 = (gcnew System::Windows::Forms::TrackBar());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->trackBar5 = (gcnew System::Windows::Forms::TrackBar());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->trackBar6 = (gcnew System::Windows::Forms::TrackBar());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->txtFilePath = (gcnew System::Windows::Forms::TextBox());
			this->btnBrowse = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->trackBar7 = (gcnew System::Windows::Forms::TrackBar());
			this->numHmin = (gcnew System::Windows::Forms::NumericUpDown());
			this->numHmax = (gcnew System::Windows::Forms::NumericUpDown());
			this->numSmin = (gcnew System::Windows::Forms::NumericUpDown());
			this->numSmax = (gcnew System::Windows::Forms::NumericUpDown());
			this->numVmin = (gcnew System::Windows::Forms::NumericUpDown());
			this->numVmax = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblBlur = (gcnew System::Windows::Forms::Label());
			this->btnCount = (gcnew System::Windows::Forms::Button());
			this->lblCount = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numHmin))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numHmax))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numSmin))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numSmax))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numVmin))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numVmax))->BeginInit();
			this->SuspendLayout();
			// 
			// trackBar1
			// 
			this->trackBar1->Enabled = false;
			this->trackBar1->Location = System::Drawing::Point(52, 54);
			this->trackBar1->Margin = System::Windows::Forms::Padding(2);
			this->trackBar1->Maximum = 179;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(503, 45);
			this->trackBar1->TabIndex = 0;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &FilterColorForm::trackBar1_Scroll);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 54);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(34, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"H min";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 97);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(37, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"H max";
			// 
			// trackBar2
			// 
			this->trackBar2->Enabled = false;
			this->trackBar2->Location = System::Drawing::Point(52, 90);
			this->trackBar2->Margin = System::Windows::Forms::Padding(2);
			this->trackBar2->Maximum = 179;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(503, 45);
			this->trackBar2->TabIndex = 2;
			this->trackBar2->Value = 179;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &FilterColorForm::trackBar2_Scroll);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 133);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(33, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"S min";
			// 
			// trackBar3
			// 
			this->trackBar3->Enabled = false;
			this->trackBar3->Location = System::Drawing::Point(52, 130);
			this->trackBar3->Margin = System::Windows::Forms::Padding(2);
			this->trackBar3->Maximum = 255;
			this->trackBar3->Name = L"trackBar3";
			this->trackBar3->Size = System::Drawing::Size(503, 45);
			this->trackBar3->TabIndex = 4;
			this->trackBar3->Scroll += gcnew System::EventHandler(this, &FilterColorForm::trackBar3_Scroll);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(9, 174);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(36, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"S max";
			// 
			// trackBar4
			// 
			this->trackBar4->Enabled = false;
			this->trackBar4->Location = System::Drawing::Point(52, 173);
			this->trackBar4->Margin = System::Windows::Forms::Padding(2);
			this->trackBar4->Maximum = 255;
			this->trackBar4->Name = L"trackBar4";
			this->trackBar4->Size = System::Drawing::Size(503, 45);
			this->trackBar4->TabIndex = 6;
			this->trackBar4->Value = 255;
			this->trackBar4->Scroll += gcnew System::EventHandler(this, &FilterColorForm::trackBar4_Scroll);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(9, 216);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(33, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"V min";
			// 
			// trackBar5
			// 
			this->trackBar5->Enabled = false;
			this->trackBar5->Location = System::Drawing::Point(52, 214);
			this->trackBar5->Margin = System::Windows::Forms::Padding(2);
			this->trackBar5->Maximum = 255;
			this->trackBar5->Name = L"trackBar5";
			this->trackBar5->Size = System::Drawing::Size(503, 45);
			this->trackBar5->TabIndex = 8;
			this->trackBar5->Scroll += gcnew System::EventHandler(this, &FilterColorForm::trackBar5_Scroll);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(9, 259);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(36, 13);
			this->label6->TabIndex = 11;
			this->label6->Text = L"V max";
			// 
			// trackBar6
			// 
			this->trackBar6->Enabled = false;
			this->trackBar6->Location = System::Drawing::Point(52, 254);
			this->trackBar6->Margin = System::Windows::Forms::Padding(2);
			this->trackBar6->Maximum = 255;
			this->trackBar6->Name = L"trackBar6";
			this->trackBar6->Size = System::Drawing::Size(503, 45);
			this->trackBar6->TabIndex = 10;
			this->trackBar6->Value = 255;
			this->trackBar6->Scroll += gcnew System::EventHandler(this, &FilterColorForm::trackBar6_Scroll);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(11, 18);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(62, 13);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Input image";
			// 
			// txtFilePath
			// 
			this->txtFilePath->Location = System::Drawing::Point(96, 16);
			this->txtFilePath->Margin = System::Windows::Forms::Padding(2);
			this->txtFilePath->Name = L"txtFilePath";
			this->txtFilePath->Size = System::Drawing::Size(335, 20);
			this->txtFilePath->TabIndex = 13;
			this->txtFilePath->TextChanged += gcnew System::EventHandler(this, &FilterColorForm::txtFilePath_TextChanged);
			// 
			// btnBrowse
			// 
			this->btnBrowse->Location = System::Drawing::Point(435, 14);
			this->btnBrowse->Margin = System::Windows::Forms::Padding(2);
			this->btnBrowse->Name = L"btnBrowse";
			this->btnBrowse->Size = System::Drawing::Size(28, 24);
			this->btnBrowse->TabIndex = 14;
			this->btnBrowse->Text = L"...";
			this->btnBrowse->UseVisualStyleBackColor = true;
			this->btnBrowse->Click += gcnew System::EventHandler(this, &FilterColorForm::btnBrowse_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(9, 302);
			this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(25, 13);
			this->label9->TabIndex = 22;
			this->label9->Text = L"Blur";
			// 
			// trackBar7
			// 
			this->trackBar7->Enabled = false;
			this->trackBar7->Location = System::Drawing::Point(52, 297);
			this->trackBar7->Margin = System::Windows::Forms::Padding(2);
			this->trackBar7->Maximum = 49;
			this->trackBar7->Name = L"trackBar7";
			this->trackBar7->Size = System::Drawing::Size(503, 45);
			this->trackBar7->TabIndex = 21;
			this->trackBar7->Scroll += gcnew System::EventHandler(this, &FilterColorForm::trackBar7_Scroll);
			// 
			// numHmin
			// 
			this->numHmin->Location = System::Drawing::Point(560, 55);
			this->numHmin->Margin = System::Windows::Forms::Padding(2);
			this->numHmin->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 179, 0, 0, 0 });
			this->numHmin->Name = L"numHmin";
			this->numHmin->Size = System::Drawing::Size(38, 20);
			this->numHmin->TabIndex = 24;
			this->numHmin->ValueChanged += gcnew System::EventHandler(this, &FilterColorForm::numHmin_ValueChanged);
			// 
			// numHmax
			// 
			this->numHmax->Location = System::Drawing::Point(560, 92);
			this->numHmax->Margin = System::Windows::Forms::Padding(2);
			this->numHmax->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 179, 0, 0, 0 });
			this->numHmax->Name = L"numHmax";
			this->numHmax->Size = System::Drawing::Size(38, 20);
			this->numHmax->TabIndex = 25;
			this->numHmax->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 179, 0, 0, 0 });
			this->numHmax->ValueChanged += gcnew System::EventHandler(this, &FilterColorForm::numHmax_ValueChanged);
			// 
			// numSmin
			// 
			this->numSmin->Location = System::Drawing::Point(560, 132);
			this->numSmin->Margin = System::Windows::Forms::Padding(2);
			this->numSmin->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
			this->numSmin->Name = L"numSmin";
			this->numSmin->Size = System::Drawing::Size(38, 20);
			this->numSmin->TabIndex = 26;
			this->numSmin->ValueChanged += gcnew System::EventHandler(this, &FilterColorForm::numSmin_ValueChanged);
			// 
			// numSmax
			// 
			this->numSmax->Location = System::Drawing::Point(560, 173);
			this->numSmax->Margin = System::Windows::Forms::Padding(2);
			this->numSmax->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
			this->numSmax->Name = L"numSmax";
			this->numSmax->Size = System::Drawing::Size(38, 20);
			this->numSmax->TabIndex = 27;
			this->numSmax->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
			this->numSmax->ValueChanged += gcnew System::EventHandler(this, &FilterColorForm::numSmax_ValueChanged);
			// 
			// numVmin
			// 
			this->numVmin->Location = System::Drawing::Point(560, 214);
			this->numVmin->Margin = System::Windows::Forms::Padding(2);
			this->numVmin->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
			this->numVmin->Name = L"numVmin";
			this->numVmin->Size = System::Drawing::Size(38, 20);
			this->numVmin->TabIndex = 28;
			this->numVmin->ValueChanged += gcnew System::EventHandler(this, &FilterColorForm::numVmin_ValueChanged);
			// 
			// numVmax
			// 
			this->numVmax->Location = System::Drawing::Point(560, 256);
			this->numVmax->Margin = System::Windows::Forms::Padding(2);
			this->numVmax->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
			this->numVmax->Name = L"numVmax";
			this->numVmax->Size = System::Drawing::Size(38, 20);
			this->numVmax->TabIndex = 29;
			this->numVmax->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
			this->numVmax->ValueChanged += gcnew System::EventHandler(this, &FilterColorForm::numVmax_ValueChanged);
			// 
			// lblBlur
			// 
			this->lblBlur->AutoSize = true;
			this->lblBlur->Location = System::Drawing::Point(561, 301);
			this->lblBlur->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblBlur->Name = L"lblBlur";
			this->lblBlur->Size = System::Drawing::Size(35, 13);
			this->lblBlur->TabIndex = 30;
			this->lblBlur->Text = L"label8";
			// 
			// btnCount
			// 
			this->btnCount->Location = System::Drawing::Point(490, 15);
			this->btnCount->Name = L"btnCount";
			this->btnCount->Size = System::Drawing::Size(75, 23);
			this->btnCount->TabIndex = 31;
			this->btnCount->Text = L"Count";
			this->btnCount->UseVisualStyleBackColor = true;
			this->btnCount->Click += gcnew System::EventHandler(this, &FilterColorForm::btnCount_Click);
			// 
			// lblCount
			// 
			this->lblCount->AutoSize = true;
			this->lblCount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCount->ForeColor = System::Drawing::Color::Red;
			this->lblCount->Location = System::Drawing::Point(571, 18);
			this->lblCount->Name = L"lblCount";
			this->lblCount->Size = System::Drawing::Size(16, 17);
			this->lblCount->TabIndex = 32;
			this->lblCount->Text = L"0";
			// 
			// FilterColorForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(664, 343);
			this->Controls->Add(this->lblCount);
			this->Controls->Add(this->btnCount);
			this->Controls->Add(this->lblBlur);
			this->Controls->Add(this->numVmax);
			this->Controls->Add(this->numVmin);
			this->Controls->Add(this->numSmax);
			this->Controls->Add(this->numSmin);
			this->Controls->Add(this->numHmax);
			this->Controls->Add(this->numHmin);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->trackBar7);
			this->Controls->Add(this->btnBrowse);
			this->Controls->Add(this->txtFilePath);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->trackBar6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->trackBar5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->trackBar4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->trackBar3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->trackBar2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->trackBar1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"FilterColorForm";
			this->Text = L"FilterColor";
			this->Load += gcnew System::EventHandler(this, &FilterColorForm::FilterColorForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FilterColorForm::FilterColorForm_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numHmin))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numHmax))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numSmin))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numSmax))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numVmin))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numVmax))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void txtFilePath_TextChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void btnBrowse_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void FilterColorForm_Load(System::Object^  sender, System::EventArgs^  e);
private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e);
private: System::Void trackBar2_Scroll(System::Object^  sender, System::EventArgs^  e); 
private: System::Void trackBar3_Scroll(System::Object^  sender, System::EventArgs^  e);
private: System::Void trackBar4_Scroll(System::Object^  sender, System::EventArgs^  e);
private: System::Void trackBar5_Scroll(System::Object^  sender, System::EventArgs^  e);
private: System::Void trackBar6_Scroll(System::Object^  sender, System::EventArgs^  e);
private: System::Void trackBar7_Scroll(System::Object^  sender, System::EventArgs^  e);
private: System::Void numHmin_ValueChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void numHmax_ValueChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void numSmin_ValueChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void numSmax_ValueChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void numVmin_ValueChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void numVmax_ValueChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void FilterColorForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
private: System::Void btnCount_Click(System::Object^  sender, System::EventArgs^  e);
};
}
