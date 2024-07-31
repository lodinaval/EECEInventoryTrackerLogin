#pragma once
#include "EquipmentForm.h"
#include "Student.h"
#include "StudentForm.h"
#include "Faculty.h"
#include "BorrowForm.h"
#include "Transactions.h"
#include "MaintenanceForm.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <unordered_map>
#include <msclr/marshal_cppstd.h>

namespace EECEInventoryTracker {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class InventoryManagerUI : public System::Windows::Forms::Form {
    public:
        bool isFaculty = true;

        InventoryManagerUI(void) {
            InitializeComponent();
        }

        InventoryManagerUI(Form^ obj1, String^ id) {
            InitializeComponent();
            obj = obj1;
            StudentNumber = id; // Assign the student number

            std::string idstr = convertToStdString(id); // Convert System::String^ to std::string
            Faculty faculty("C:\\Users\\Keith Naval\\Downloads\\mapuaFaculty.csv"); // Load faculty data
            Student student("C:\\Users\\Keith Naval\\Downloads\\students.csv"); // Load student data

            // Top Left Name Functionality & Hides Features if Not a Faculty Member
            if (faculty.isFaculty(idstr)) {
                std::string facultyNameStr = faculty.getName(idstr);
                nameTopLeft->Text = converterToString(facultyNameStr);
            }
            else {
                std::string studentNameStr = student.getName(idstr);
                nameTopLeft->Text = converterToString(studentNameStr);
                isFaculty = false;
            }
        }

        property String^ StudentNumber;

        InventoryManagerUI(Form^ obj1) {
            obj = obj1;
            InitializeComponent();
        }

    protected:
        ~InventoryManagerUI() {
            if (components) {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Button^ MyProfile;
        System::Windows::Forms::ImageList^ imageList1;
        System::Windows::Forms::Panel^ panel1;
        System::Windows::Forms::Button^ button1;
        System::Windows::Forms::Button^ button2;
        System::Windows::Forms::Label^ nameTopLeft;
        System::ComponentModel::IContainer^ components;

    private: System::Windows::Forms::Button^ button3;
    private: System::Windows::Forms::PictureBox^ pictureBox1;
    private: System::Windows::Forms::Button^ button4;
    private: System::Windows::Forms::Button^ button5;

           Form^ obj;

#pragma region Windows Form Designer generated code
           void InitializeComponent(void) {
               this->components = (gcnew System::ComponentModel::Container());
               System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(InventoryManagerUI::typeid));
               this->MyProfile = (gcnew System::Windows::Forms::Button());
               this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
               this->panel1 = (gcnew System::Windows::Forms::Panel());
               this->button4 = (gcnew System::Windows::Forms::Button());
               this->button3 = (gcnew System::Windows::Forms::Button());
               this->button2 = (gcnew System::Windows::Forms::Button());
               this->nameTopLeft = (gcnew System::Windows::Forms::Label());
               this->button1 = (gcnew System::Windows::Forms::Button());
               this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
               this->button5 = (gcnew System::Windows::Forms::Button());
               this->panel1->SuspendLayout();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
               this->SuspendLayout();
               // 
               // MyProfile
               // 
               this->MyProfile->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
                   static_cast<System::Int32>(static_cast<System::Byte>(40)));
               this->MyProfile->FlatAppearance->BorderColor = System::Drawing::Color::White;
               this->MyProfile->FlatAppearance->BorderSize = 0;
               this->MyProfile->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
               this->MyProfile->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16));
               this->MyProfile->ForeColor = System::Drawing::Color::White;
               this->MyProfile->Location = System::Drawing::Point(0, 435);
               this->MyProfile->Margin = System::Windows::Forms::Padding(0);
               this->MyProfile->Name = L"MyProfile";
               this->MyProfile->Size = System::Drawing::Size(194, 62);
               this->MyProfile->TabIndex = 9;
               this->MyProfile->Text = L"My Profile";
               this->MyProfile->UseVisualStyleBackColor = false;
               this->MyProfile->Click += gcnew System::EventHandler(this, &InventoryManagerUI::MyProfile_Click);
               // 
               // imageList1
               // 
               this->imageList1->ColorDepth = System::Windows::Forms::ColorDepth::Depth8Bit;
               this->imageList1->ImageSize = System::Drawing::Size(16, 16);
               this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
               // 
               // panel1
               // 
               this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
                   static_cast<System::Int32>(static_cast<System::Byte>(40)));
               this->panel1->Controls->Add(this->button5);
               this->panel1->Controls->Add(this->button4);
               this->panel1->Controls->Add(this->button3);
               this->panel1->Controls->Add(this->button2);
               this->panel1->Controls->Add(this->nameTopLeft);
               this->panel1->Controls->Add(this->button1);
               this->panel1->Controls->Add(this->MyProfile);
               this->panel1->Location = System::Drawing::Point(-3, 0);
               this->panel1->Name = L"panel1";
               this->panel1->Size = System::Drawing::Size(192, 563);
               this->panel1->TabIndex = 10;
               // 
               // button4
               // 
               this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
                   static_cast<System::Int32>(static_cast<System::Byte>(40)));
               this->button4->FlatAppearance->BorderColor = System::Drawing::Color::White;
               this->button4->FlatAppearance->BorderSize = 0;
               this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
               this->button4->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16));
               this->button4->ForeColor = System::Drawing::Color::White;
               this->button4->Location = System::Drawing::Point(-2, 252);
               this->button4->Margin = System::Windows::Forms::Padding(0);
               this->button4->Name = L"button4";
               this->button4->Size = System::Drawing::Size(194, 62);
               this->button4->TabIndex = 13;
               this->button4->Text = L"Transactions";
               this->button4->UseVisualStyleBackColor = false;
               this->button4->Click += gcnew System::EventHandler(this, &InventoryManagerUI::button4_Click);
               // 
               // button3
               // 
               this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
                   static_cast<System::Int32>(static_cast<System::Byte>(40)));
               this->button3->FlatAppearance->BorderColor = System::Drawing::Color::White;
               this->button3->FlatAppearance->BorderSize = 0;
               this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
               this->button3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16));
               this->button3->ForeColor = System::Drawing::Color::White;
               this->button3->Location = System::Drawing::Point(-2, 190);
               this->button3->Margin = System::Windows::Forms::Padding(0);
               this->button3->Name = L"button3";
               this->button3->Size = System::Drawing::Size(194, 62);
               this->button3->TabIndex = 12;
               this->button3->Text = L"Borrow";
               this->button3->UseVisualStyleBackColor = false;
               this->button3->Click += gcnew System::EventHandler(this, &InventoryManagerUI::button3_Click);
               // 
               // button2
               // 
               this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
                   static_cast<System::Int32>(static_cast<System::Byte>(40)));
               this->button2->FlatAppearance->BorderColor = System::Drawing::Color::White;
               this->button2->FlatAppearance->BorderSize = 0;
               this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
               this->button2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16));
               this->button2->ForeColor = System::Drawing::Color::White;
               this->button2->Location = System::Drawing::Point(0, 501);
               this->button2->Margin = System::Windows::Forms::Padding(0);
               this->button2->Name = L"button2";
               this->button2->Size = System::Drawing::Size(194, 62);
               this->button2->TabIndex = 11;
               this->button2->Text = L"Sign Out";
               this->button2->UseVisualStyleBackColor = false;
               this->button2->Click += gcnew System::EventHandler(this, &InventoryManagerUI::button2_Click);
               // 
               // nameTopLeft
               // 
               this->nameTopLeft->AutoSize = true;
               this->nameTopLeft->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
                   static_cast<System::Int32>(static_cast<System::Byte>(40)));
               this->nameTopLeft->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10));
               this->nameTopLeft->ForeColor = System::Drawing::Color::White;
               this->nameTopLeft->Location = System::Drawing::Point(3, 0);
               this->nameTopLeft->MinimumSize = System::Drawing::Size(194, 65);
               this->nameTopLeft->Name = L"nameTopLeft";
               this->nameTopLeft->Size = System::Drawing::Size(194, 65);
               this->nameTopLeft->TabIndex = 11;
               this->nameTopLeft->Text = L"label1";
               this->nameTopLeft->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
               // 
               // button1
               // 
               this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
                   static_cast<System::Int32>(static_cast<System::Byte>(40)));
               this->button1->FlatAppearance->BorderColor = System::Drawing::Color::White;
               this->button1->FlatAppearance->BorderSize = 0;
               this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
               this->button1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16));
               this->button1->ForeColor = System::Drawing::Color::White;
               this->button1->Location = System::Drawing::Point(-2, 119);
               this->button1->Margin = System::Windows::Forms::Padding(0);
               this->button1->Name = L"button1";
               this->button1->Size = System::Drawing::Size(194, 62);
               this->button1->TabIndex = 10;
               this->button1->Text = L"Equipment";
               this->button1->UseVisualStyleBackColor = false;
               this->button1->Click += gcnew System::EventHandler(this, &InventoryManagerUI::button1_Click);
               // 
               // pictureBox1
               // 
               this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
               this->pictureBox1->Location = System::Drawing::Point(186, 0);
               this->pictureBox1->Name = L"pictureBox1";
               this->pictureBox1->Size = System::Drawing::Size(1001, 563);
               this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
               this->pictureBox1->TabIndex = 11;
               this->pictureBox1->TabStop = false;
               // 
               // button5
               // 
               this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
                   static_cast<System::Int32>(static_cast<System::Byte>(40)));
               this->button5->FlatAppearance->BorderColor = System::Drawing::Color::White;
               this->button5->FlatAppearance->BorderSize = 0;
               this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
               this->button5->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16));
               this->button5->ForeColor = System::Drawing::Color::White;
               this->button5->Location = System::Drawing::Point(-2, 314);
               this->button5->Margin = System::Windows::Forms::Padding(0);
               this->button5->Name = L"button5";
               this->button5->Size = System::Drawing::Size(194, 62);
               this->button5->TabIndex = 14;
               this->button5->Text = L"Maintenance";
               this->button5->UseVisualStyleBackColor = false;
               this->button5->Click += gcnew System::EventHandler(this, &InventoryManagerUI::button5_Click);
               // 
               // InventoryManagerUI
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->ClientSize = System::Drawing::Size(1187, 563);
               this->Controls->Add(this->pictureBox1);
               this->Controls->Add(this->panel1);
               this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
               this->Name = L"InventoryManagerUI";
               this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
               this->Text = L"EECE Inventory Tracker | Dashboard";
               this->Load += gcnew System::EventHandler(this, &InventoryManagerUI::InventoryManagerUI_Load);
               this->panel1->ResumeLayout(false);
               this->panel1->PerformLayout();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
               this->ResumeLayout(false);

           }
#pragma endregion
private: System::Void MyProfile_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Hide(); // Hides current form
    StudentForm^ studentForm = gcnew StudentForm(this, StudentNumber); // Transition to MyProfile and passes StudentNumber
    studentForm->ShowDialog(); // Show My Profile
    this->Show();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Close();
    obj->Show();
}
private: System::Void InventoryManagerUI_Load(System::Object^ sender, System::EventArgs^ e) {
    if (!isFaculty) {
        button1->Visible = false;
        button4->Visible = false;
        button5->Visible = false;
    }
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Hide();
    EquipmentForm^ equipmentForm = gcnew EquipmentForm(this);
    equipmentForm->ShowDialog();
    this->Show();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
    BorrowForm^ borrowForm = gcnew BorrowForm(this, StudentNumber);
    this->Hide();
    borrowForm->ShowDialog();
    this->Show();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
    Transactions^ transactionForm = gcnew Transactions(this);
    this->Hide();
    transactionForm->Show();
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
    MaintenanceForm^ maintenanceForm = gcnew MaintenanceForm(this);
    maintenanceForm->Show();
    this->Hide();
}
};
}

