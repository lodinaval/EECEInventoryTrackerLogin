#pragma once
#include "Student.h"
#include <msclr/marshal_cppstd.h>
#include <string>
#include "Faculty.h"
#include "StringConverter.h"

namespace EECEInventoryTracker {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class StudentForm : public System::Windows::Forms::Form
    {
    public:
        Form^ studentForm;
    private: System::Windows::Forms::Button^ Back;
    private: System::Windows::Forms::PictureBox^ pictureBox1;
    private: System::Windows::Forms::Label^ studentProgramLabel;

    private: System::Windows::Forms::Label^ label8;
    private: System::Windows::Forms::Label^ studentEmailL;


    private: System::Windows::Forms::Label^ label10;
    public:
        Form^ obj4;
        StudentForm(void)
        {
            InitializeComponent();
        }

        StudentForm(Form^ obj1, String^ idNo)
        {
            InitializeComponent();
            obj4 = obj1;

            std::string idNumberStr = msclr::interop::marshal_as<std::string>(idNo);
            Student MyProfile("C:\\Users\\Keith Naval\\Downloads\\students.csv"); // Load students
            Faculty MyProfileFaculty("C:\\Users\\Keith Naval\\Downloads\\mapuaFaculty.csv"); //Load faculty

            if (MyProfileFaculty.isFaculty(idNumberStr)) {
                std::string facultyName = MyProfileFaculty.getName(idNumberStr);
                studentNameLabel->Text = converterToString(facultyName);

                studentNumberLabel->Text = idNo;

                std::string facultyDepartment = MyProfileFaculty.getDepartment(idNumberStr);
                label8->Text = "Department";
                studentProgramLabel->Text = converterToString(facultyDepartment);

                std::string facultyContactInfo = MyProfileFaculty.getContactInfo(idNumberStr);
                studentContactInfoLabel->Text = converterToString(facultyContactInfo);

                std::string facultyEmail = MyProfileFaculty.getEmail(idNumberStr);
                studentEmailL->Text = converterToString(facultyEmail);
            }
            else {
                std::string studentName = MyProfile.getName(idNumberStr);
                studentNameLabel->Text = converterToString(studentName);

                studentNumberLabel->Text = idNo;

                std::string studentProgram = MyProfile.getProgram(idNumberStr);
                studentProgramLabel->Text = converterToString(studentProgram);

                std::string studentContactInfo = MyProfile.getContactInfo(idNumberStr);
                studentContactInfoLabel->Text = converterToString(studentContactInfo);

                std::string studentEmail = MyProfile.getEmail(idNumberStr);
                studentEmailL->Text = converterToString(studentEmail);
            }
            
        }


        StudentForm(Form^ obj1) {
            obj4 = obj1;
            InitializeComponent();
        }

    protected:
        ~StudentForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ studentNumberLabel;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ studentNameLabel;




    private: System::Windows::Forms::Label^ studentContactInfoLabel;

    private: System::Windows::Forms::Label^ label7;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Label^ studentEmailLabel;
    private: System::Windows::Forms::Label^ label6;

    protected:

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(StudentForm::typeid));
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->studentNumberLabel = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->studentNameLabel = (gcnew System::Windows::Forms::Label());
            this->studentContactInfoLabel = (gcnew System::Windows::Forms::Label());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->studentEmailLabel = (gcnew System::Windows::Forms::Label());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->Back = (gcnew System::Windows::Forms::Button());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->studentProgramLabel = (gcnew System::Windows::Forms::Label());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->studentEmailL = (gcnew System::Windows::Forms::Label());
            this->label10 = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->SuspendLayout();
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->BackColor = System::Drawing::SystemColors::Control;
            this->label2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Bold));
            this->label2->Location = System::Drawing::Point(382, 125);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(162, 32);
            this->label2->TabIndex = 2;
            this->label2->Text = L"ID Number:";
            // 
            // studentNumberLabel
            // 
            this->studentNumberLabel->AutoSize = true;
            this->studentNumberLabel->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20));
            this->studentNumberLabel->Location = System::Drawing::Point(386, 177);
            this->studentNumberLabel->Name = L"studentNumberLabel";
            this->studentNumberLabel->Size = System::Drawing::Size(30, 33);
            this->studentNumberLabel->TabIndex = 3;
            this->studentNumberLabel->Text = L"$";
            this->studentNumberLabel->Click += gcnew System::EventHandler(this, &StudentForm::studentNumberLabel_Click);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->BackColor = System::Drawing::SystemColors::Control;
            this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Bold));
            this->label1->Location = System::Drawing::Point(382, 24);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(102, 32);
            this->label1->TabIndex = 4;
            this->label1->Text = L"Name:";
            // 
            // studentNameLabel
            // 
            this->studentNameLabel->AutoSize = true;
            this->studentNameLabel->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20));
            this->studentNameLabel->Location = System::Drawing::Point(386, 72);
            this->studentNameLabel->Name = L"studentNameLabel";
            this->studentNameLabel->Size = System::Drawing::Size(30, 33);
            this->studentNameLabel->TabIndex = 5;
            this->studentNameLabel->Text = L"$";
            this->studentNameLabel->Click += gcnew System::EventHandler(this, &StudentForm::studentNameLabel_Click);
            // 
            // studentContactInfoLabel
            // 
            this->studentContactInfoLabel->AutoSize = true;
            this->studentContactInfoLabel->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20));
            this->studentContactInfoLabel->Location = System::Drawing::Point(386, 491);
            this->studentContactInfoLabel->Name = L"studentContactInfoLabel";
            this->studentContactInfoLabel->Size = System::Drawing::Size(30, 33);
            this->studentContactInfoLabel->TabIndex = 9;
            this->studentContactInfoLabel->Text = L"$";
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->BackColor = System::Drawing::SystemColors::Control;
            this->label7->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Bold));
            this->label7->Location = System::Drawing::Point(382, 439);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(184, 32);
            this->label7->TabIndex = 8;
            this->label7->Text = L"Contact Info:";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20));
            this->label3->Location = System::Drawing::Point(0, 0);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(0, 33);
            this->label3->TabIndex = 4;
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->BackColor = System::Drawing::SystemColors::Control;
            this->label4->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Bold));
            this->label4->Location = System::Drawing::Point(0, 0);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(0, 32);
            this->label4->TabIndex = 5;
            // 
            // studentEmailLabel
            // 
            this->studentEmailLabel->AutoSize = true;
            this->studentEmailLabel->Font = (gcnew System::Drawing::Font(L"Century Gothic", 15));
            this->studentEmailLabel->Location = System::Drawing::Point(0, 0);
            this->studentEmailLabel->Name = L"studentEmailLabel";
            this->studentEmailLabel->Size = System::Drawing::Size(0, 23);
            this->studentEmailLabel->TabIndex = 2;
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->BackColor = System::Drawing::SystemColors::Control;
            this->label6->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Bold));
            this->label6->Location = System::Drawing::Point(0, 0);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(0, 32);
            this->label6->TabIndex = 3;
            // 
            // Back
            // 
            this->Back->Font = (gcnew System::Drawing::Font(L"Century Gothic", 25));
            this->Back->Location = System::Drawing::Point(12, 439);
            this->Back->Name = L"Back";
            this->Back->Size = System::Drawing::Size(165, 112);
            this->Back->TabIndex = 1;
            this->Back->Text = L"BACK";
            this->Back->Click += gcnew System::EventHandler(this, &StudentForm::Back_Click_1);
            // 
            // pictureBox1
            // 
            this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
            this->pictureBox1->Location = System::Drawing::Point(12, 29);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(340, 352);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox1->TabIndex = 0;
            this->pictureBox1->TabStop = false;
            // 
            // studentProgramLabel
            // 
            this->studentProgramLabel->AutoSize = true;
            this->studentProgramLabel->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20));
            this->studentProgramLabel->Location = System::Drawing::Point(386, 287);
            this->studentProgramLabel->Name = L"studentProgramLabel";
            this->studentProgramLabel->Size = System::Drawing::Size(30, 33);
            this->studentProgramLabel->TabIndex = 11;
            this->studentProgramLabel->Text = L"$";
            // 
            // label8
            // 
            this->label8->AutoSize = true;
            this->label8->BackColor = System::Drawing::SystemColors::Control;
            this->label8->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Bold));
            this->label8->Location = System::Drawing::Point(382, 235);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(133, 32);
            this->label8->TabIndex = 10;
            this->label8->Text = L"Program:";
            // 
            // studentEmailL
            // 
            this->studentEmailL->AutoSize = true;
            this->studentEmailL->Font = (gcnew System::Drawing::Font(L"Century Gothic", 15));
            this->studentEmailL->Location = System::Drawing::Point(386, 391);
            this->studentEmailL->Name = L"studentEmailL";
            this->studentEmailL->Size = System::Drawing::Size(21, 23);
            this->studentEmailL->TabIndex = 13;
            this->studentEmailL->Text = L"$";
            // 
            // label10
            // 
            this->label10->AutoSize = true;
            this->label10->BackColor = System::Drawing::SystemColors::Control;
            this->label10->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Bold));
            this->label10->Location = System::Drawing::Point(382, 339);
            this->label10->Name = L"label10";
            this->label10->Size = System::Drawing::Size(83, 32);
            this->label10->TabIndex = 12;
            this->label10->Text = L"Email";
            // 
            // StudentForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(784, 563);
            this->Controls->Add(this->studentEmailL);
            this->Controls->Add(this->label10);
            this->Controls->Add(this->studentProgramLabel);
            this->Controls->Add(this->label8);
            this->Controls->Add(this->pictureBox1);
            this->Controls->Add(this->Back);
            this->Controls->Add(this->studentEmailLabel);
            this->Controls->Add(this->label6);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->studentContactInfoLabel);
            this->Controls->Add(this->label7);
            this->Controls->Add(this->studentNameLabel);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->studentNumberLabel);
            this->Controls->Add(this->label2);
            this->Location = System::Drawing::Point(21, 24);
            this->Name = L"StudentForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
            this->Text = L"EECE Inventory Tracker | My Profile";
            this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &StudentForm::StudentForm_FormClosed);
            this->Load += gcnew System::EventHandler(this, &StudentForm::StudentForm_Load);
            this->Click += gcnew System::EventHandler(this, &StudentForm::Back_Click);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void studentNumberLabel_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void StudentForm_Load(System::Object^ sender, System::EventArgs^ e) {


    }
    private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void studentNameLabel_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void studentEmailLabel_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void Back_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void Back_Click_1(System::Object^ sender, System::EventArgs^ e) {
        this->Hide();
    }
private: System::Void StudentForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
}
};
}
