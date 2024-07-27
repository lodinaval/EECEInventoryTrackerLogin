#pragma once
#include <fstream>
#include <iostream>
#include <msclr/marshal_cppstd.h>
#include "InventoryManagerUI.h"
#include "Student.h"

namespace EECEInventoryTracker {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
            studentData = new Student("C:\\Users\\Keith Naval\\Downloads\\students.csv"); // Update with your actual path
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
            delete studentData;
        }

    private:
        Student* studentData;
        System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
        System::ComponentModel::IContainer^ components;

    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::TextBox^ textBox1;
    private: System::Windows::Forms::Panel^ panel1;
    private: System::Windows::Forms::Panel^ panel2;
    private: System::Windows::Forms::TextBox^ textBox2;
    private: System::Windows::Forms::Button^ button1;

#pragma region Windows Form Designer generated code
           void InitializeComponent(void)
           {
               this->components = (gcnew System::ComponentModel::Container());
               System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
               this->label1 = (gcnew System::Windows::Forms::Label());
               this->label2 = (gcnew System::Windows::Forms::Label());
               this->label3 = (gcnew System::Windows::Forms::Label());
               this->textBox1 = (gcnew System::Windows::Forms::TextBox());
               this->panel1 = (gcnew System::Windows::Forms::Panel());
               this->panel2 = (gcnew System::Windows::Forms::Panel());
               this->textBox2 = (gcnew System::Windows::Forms::TextBox());
               this->button1 = (gcnew System::Windows::Forms::Button());
               this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
               this->SuspendLayout();
               // 
               // label1
               // 
               this->label1->AutoSize = true;
               this->label1->BackColor = System::Drawing::Color::White;
               this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 28));
               this->label1->Location = System::Drawing::Point(61, 96);
               this->label1->Name = L"label1";
               this->label1->Size = System::Drawing::Size(140, 45);
               this->label1->TabIndex = 0;
               this->label1->Text = L"Sign in";
               // 
               // label2
               // 
               this->label2->AutoSize = true;
               this->label2->BackColor = System::Drawing::Color::White;
               this->label2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10));
               this->label2->Location = System::Drawing::Point(67, 163);
               this->label2->Name = L"label2";
               this->label2->Size = System::Drawing::Size(90, 19);
               this->label2->TabIndex = 1;
               this->label2->Text = L"Student No.";
               // 
               // label3
               // 
               this->label3->AutoSize = true;
               this->label3->BackColor = System::Drawing::Color::White;
               this->label3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10));
               this->label3->Location = System::Drawing::Point(67, 236);
               this->label3->Name = L"label3";
               this->label3->Size = System::Drawing::Size(72, 19);
               this->label3->TabIndex = 2;
               this->label3->Text = L"Password";
               this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
               // 
               // textBox1
               // 
               this->textBox1->BackColor = System::Drawing::Color::White;
               this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
               this->textBox1->Cursor = System::Windows::Forms::Cursors::Default;
               this->textBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
               this->textBox1->Location = System::Drawing::Point(70, 193);
               this->textBox1->MaxLength = 50;
               this->textBox1->Name = L"textBox1";
               this->textBox1->Size = System::Drawing::Size(220, 20);
               this->textBox1->TabIndex = 0;
               this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox1_KeyDown);
               this->textBox1->MouseHover += gcnew System::EventHandler(this, &MyForm::textBox1_MouseHover);
               // 
               // panel1
               // 
               this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
               this->panel1->Location = System::Drawing::Point(70, 217);
               this->panel1->Margin = System::Windows::Forms::Padding(0);
               this->panel1->Name = L"panel1";
               this->panel1->Size = System::Drawing::Size(220, 2);
               this->panel1->TabIndex = 3;
               // 
               // panel2
               // 
               this->panel2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
               this->panel2->Location = System::Drawing::Point(70, 295);
               this->panel2->Margin = System::Windows::Forms::Padding(0);
               this->panel2->Name = L"panel2";
               this->panel2->Size = System::Drawing::Size(220, 2);
               this->panel2->TabIndex = 5;
               // 
               // textBox2
               // 
               this->textBox2->BackColor = System::Drawing::Color::White;
               this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
               this->textBox2->Cursor = System::Windows::Forms::Cursors::Default;
               this->textBox2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
               this->textBox2->Location = System::Drawing::Point(70, 270);
               this->textBox2->Name = L"textBox2";
               this->textBox2->Size = System::Drawing::Size(220, 20);
               this->textBox2->TabIndex = 4;
               this->textBox2->UseSystemPasswordChar = true;
               this->textBox2->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox2_KeyDown);
               this->textBox2->MouseHover += gcnew System::EventHandler(this, &MyForm::textBox2_MouseHover);
               // 
               // button1
               // 
               this->button1->BackColor = System::Drawing::Color::RoyalBlue;
               this->button1->FlatAppearance->BorderColor = System::Drawing::Color::White;
               this->button1->FlatAppearance->BorderSize = 0;
               this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
               this->button1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12));
               this->button1->ForeColor = System::Drawing::Color::White;
               this->button1->Location = System::Drawing::Point(70, 319);
               this->button1->Margin = System::Windows::Forms::Padding(0);
               this->button1->Name = L"button1";
               this->button1->Size = System::Drawing::Size(110, 48);
               this->button1->TabIndex = 6;
               this->button1->Text = L"Sign In";
               this->button1->UseVisualStyleBackColor = false;
               this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
               // 
               // contextMenuStrip1
               // 
               this->contextMenuStrip1->Name = L"contextMenuStrip1";
               this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
               // 
               // MyForm
               // 
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
               this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
               this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
               this->ClientSize = System::Drawing::Size(727, 477);
               this->Controls->Add(this->button1);
               this->Controls->Add(this->panel2);
               this->Controls->Add(this->textBox2);
               this->Controls->Add(this->panel1);
               this->Controls->Add(this->textBox1);
               this->Controls->Add(this->label3);
               this->Controls->Add(this->label2);
               this->Controls->Add(this->label1);
               this->Cursor = System::Windows::Forms::Cursors::Default;
               this->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F));
               this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
               this->Name = L"MyForm";
               this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
               this->Text = L"Sign in to EECE Inventory Tracker";
               this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
               this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
               this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
               this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseUp);
               this->ResumeLayout(false);
               this->PerformLayout();

           }
#pragma endregion
    private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        std::string email = msclr::interop::marshal_as<std::string>(textBox1->Text);
        std::string password = msclr::interop::marshal_as<std::string>(textBox2->Text);

        if (studentData->verifyCredentials(email, password)) {
            InventoryManagerUI^ obj2 = gcnew InventoryManagerUI(this, textBox1->Text);
            textBox1->Text = "";
            textBox2->Text = "";
            this->Hide();
            obj2->Show();
        }
        else {
            MessageBox::Show("Username or password is incorrect.", "EECE Inventory Tracker", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    private: bool dragging;
    private: Point offset;

    private: System::Void MyForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
        dragging = true;
        offset.X = e->X;
        offset.Y = e->Y;
    }

    private: System::Void MyForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
        if (dragging) {
            Point currentScreenPosition;
            currentScreenPosition = PointToScreen(Point(e->X, e->Y));
            Location = Point(currentScreenPosition.X - offset.X, currentScreenPosition.Y - offset.Y);
        }
    }

    private: System::Void MyForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
        dragging = false;
    }

    private: System::Void textBox1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
        if (e->KeyValue == (int)Keys::Enter) {
            textBox2->Focus();
        }
    }

    private: System::Void textBox2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
        if (e->KeyValue == (int)Keys::Enter) {
            button1->PerformClick();
        }
    }
    private: System::Void textBox1_MouseHover(System::Object^ sender, System::EventArgs^ e) {
        this->textBox1->Cursor = Cursors::IBeam;
    }
    private: System::Void textBox2_MouseHover(System::Object^ sender, System::EventArgs^ e) {
        this->textBox2->Cursor = Cursors::IBeam;
    }
    private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
    }
    };
}
