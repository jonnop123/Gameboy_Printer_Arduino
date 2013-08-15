#pragma once

namespace serial {

	using namespace System;
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
			//
			//TODO: Add the constructor code here
			//
		}

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
	private: System::IO::Ports::SerialPort^  serialPort1;
	protected: 
	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::TextBox^  COMBox;

	private: System::Windows::Forms::Label^  label2;


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  TextBox;































	private: System::ComponentModel::IContainer^  components;

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
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->COMBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->TextBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(27, 113);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Send";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// COMBox
			// 
			this->COMBox->Location = System::Drawing::Point(27, 78);
			this->COMBox->Name = L"COMBox";
			this->COMBox->Size = System::Drawing::Size(100, 20);
			this->COMBox->TabIndex = 2;
			this->COMBox->Text = L"COM4";
			this->COMBox->TextChanged += gcnew System::EventHandler(this, &Form1::COMBox_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(24, 62);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(94, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Arduino COM port:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(24, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(171, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Text to print: (max. 360 characters)";
			// 
			// TextBox
			// 
			this->TextBox->Location = System::Drawing::Point(27, 25);
			this->TextBox->MaxLength = 180;
			this->TextBox->Name = L"TextBox";
			this->TextBox->Size = System::Drawing::Size(806, 20);
			this->TextBox->TabIndex = 8;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(863, 165);
			this->Controls->Add(this->TextBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->COMBox);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Gameboy Printer Text";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 String^ text = "t";
				 text += TextBox->Text;
				 text += "/";
				 this->serialPort1->PortName = COMBox->Text;
				 this->serialPort1->Open();
				 this->serialPort1->Write(text);
				 this->serialPort1->Close();
			 }
	private: System::Void textBox8_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void COMBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

