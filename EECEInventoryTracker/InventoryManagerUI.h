#pragma once
#include "StudentForm.h"
#include "EquipmentForm.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <unordered_map>
#include "Student.h"
#include "StudentForm.h"
#include <msclr/marshal_cppstd.h>
#include "BorrowForm.h"

namespace EECEInventoryTracker {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class InventoryManagerUI : public System::Windows::Forms::Form {
    public:
        InventoryManagerUI(void) {
            InitializeComponent();
        }
        InventoryManagerUI(Form^ obj1, String^ studentNo) {
            InitializeComponent();
            obj = obj1;
            studentNumber = studentNo;
            std::string studentNoStr = msclr::interop::marshal_as<std::string>(studentNo);
            Student temp("C:\\path\\to\\your\\students.csv"); // Update with your actual path
            std::string studentName = temp.getName(studentNoStr); //Get name of student with this id number.
            nameTopLeft->Text = converterToString(studentName); //Convert std::string to System String and assign to label
        }
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

        String^ studentNumber;
    private: System::Windows::Forms::Button^ button3;


           Form^ obj;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void) {
            this->components = (gcnew System::ComponentModel::Container());
            this->MyProfile = (gcnew System::Windows::Forms::Button());
            this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->nameTopLeft = (gcnew System::Windows::Forms::Label());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->panel1->SuspendLayout();
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
            this->nameTopLeft->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
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
            // InventoryManagerUI
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1187, 563);
            this->Controls->Add(this->panel1);
            this->Name = L"InventoryManagerUI";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"EECE Inventory Tracker | Dashboard";
            this->Load += gcnew System::EventHandler(this, &InventoryManagerUI::InventoryManagerUI_Load);
            this->panel1->ResumeLayout(false);
            this->panel1->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion
    private: System::Void MyProfile_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Hide(); // Hides current form
        StudentForm^ studentForm = gcnew StudentForm(this, studentNumber); // Transition to MyProfile
        studentForm->ShowDialog(); // Show My Profile
        this->Show();
    }
    private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Close();
        obj->Show();
    }
    private: System::Void InventoryManagerUI_Load(System::Object^ sender, System::EventArgs^ e) {
        nameTopLeft->Text = studentNumber;
    }
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Hide();
        EquipmentForm^ equipmentForm = gcnew EquipmentForm(this);
        equipmentForm->ShowDialog();
        this->Show();
    }
    private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
        BorrowForm^ borrowForm = gcnew BorrowForm(this, nameTopLeft->Text);
        this->Hide();
        borrowForm->ShowDialog();
    }
};
}
