#pragma once
#include "Borrow.h"
#include "Faculty.h"
#include "Student.h"
#include <msclr/marshal_cppstd.h>
#include "StringConverter.h"

namespace EECEInventoryTracker {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class BorrowForm : public System::Windows::Forms::Form
    {
    public:
        BorrowForm(void)
        {
            InitializeComponent();
            LoadEquipmentData();
            InitializeBorrowedItemsGrid();
        }

        Form^ InventoryManager;
    private: System::Windows::Forms::Button^ checkOutButton;
    private: System::Windows::Forms::Button^ backButton;
    public:
        String^ StudentNumber;

        BorrowForm(Form^ inventoryManagerObj, String^ StudentNum)
        {
            InitializeComponent();
            LoadEquipmentData();
            InitializeBorrowedItemsGrid();
            InventoryManager = inventoryManagerObj;
            StudentNumber = StudentNum; // Assign the student number

            std::string idstr = convertToStdString(StudentNum); // Convert System::String^ to std::string
            Faculty faculty("C:\\Users\\Keith Naval\\Downloads\\mapuaFaculty.csv"); // Load faculty data
            Student student("C:\\Users\\Keith Naval\\Downloads\\students.csv"); // Load student data

            // Set the student/faculty name in the label
            if (faculty.isFaculty(idstr)) {
                std::string facultyNameStr = faculty.getName(idstr);
                studentNumberLabel->Text = converterToString(facultyNameStr);
            }
            else {
                std::string studentNameStr = student.getName(idstr);
                studentNumberLabel->Text = converterToString(studentNameStr);
            }
        }


    protected:
        ~BorrowForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::Panel^ panel3;
    private: System::Windows::Forms::Panel^ panel1;
    private: System::Windows::Forms::Label^ searchIDLabel;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ dateLabel;
    private: System::Windows::Forms::DataGridView^ dataGridView1;
    private: System::Windows::Forms::Label^ timeLabel;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Timer^ timer1;
    private: System::Windows::Forms::Label^ searchLabel;
    private: System::Windows::Forms::TextBox^ searchBorrowTextBox;

    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::TextBox^ borrowID;

    private: System::Windows::Forms::Label^ labelQuantity;
    private: System::Windows::Forms::TextBox^ borrowQuantity;

    private: System::Windows::Forms::Button^ borrowButton;
    private: System::Windows::Forms::DataGridView^ borrowedItemsGrid;
    private: DataTable^ equipmentTable;
    private: DataTable^ borrowedItemsTable;
    private: System::Windows::Forms::Label^ studentNumberLabel;

    private: System::Windows::Forms::Label^ label5;

    private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
           void InitializeComponent(void)
           {
               this->components = (gcnew System::ComponentModel::Container());
               this->panel3 = (gcnew System::Windows::Forms::Panel());
               this->backButton = (gcnew System::Windows::Forms::Button());
               this->studentNumberLabel = (gcnew System::Windows::Forms::Label());
               this->label5 = (gcnew System::Windows::Forms::Label());
               this->searchLabel = (gcnew System::Windows::Forms::Label());
               this->searchBorrowTextBox = (gcnew System::Windows::Forms::TextBox());
               this->timeLabel = (gcnew System::Windows::Forms::Label());
               this->label3 = (gcnew System::Windows::Forms::Label());
               this->dateLabel = (gcnew System::Windows::Forms::Label());
               this->searchIDLabel = (gcnew System::Windows::Forms::Label());
               this->borrowButton = (gcnew System::Windows::Forms::Button());
               this->labelQuantity = (gcnew System::Windows::Forms::Label());
               this->borrowQuantity = (gcnew System::Windows::Forms::TextBox());
               this->label2 = (gcnew System::Windows::Forms::Label());
               this->borrowID = (gcnew System::Windows::Forms::TextBox());
               this->panel1 = (gcnew System::Windows::Forms::Panel());
               this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
               this->label1 = (gcnew System::Windows::Forms::Label());
               this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
               this->borrowedItemsGrid = (gcnew System::Windows::Forms::DataGridView());
               this->checkOutButton = (gcnew System::Windows::Forms::Button());
               this->panel3->SuspendLayout();
               this->panel1->SuspendLayout();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->borrowedItemsGrid))->BeginInit();
               this->SuspendLayout();
               // 
               // panel3
               // 
               this->panel3->Controls->Add(this->backButton);
               this->panel3->Controls->Add(this->studentNumberLabel);
               this->panel3->Controls->Add(this->label5);
               this->panel3->Controls->Add(this->searchLabel);
               this->panel3->Controls->Add(this->searchBorrowTextBox);
               this->panel3->Controls->Add(this->timeLabel);
               this->panel3->Controls->Add(this->label3);
               this->panel3->Controls->Add(this->dateLabel);
               this->panel3->Controls->Add(this->searchIDLabel);
               this->panel3->Dock = System::Windows::Forms::DockStyle::Top;
               this->panel3->Location = System::Drawing::Point(0, 0);
               this->panel3->Name = L"panel3";
               this->panel3->Size = System::Drawing::Size(976, 99);
               this->panel3->TabIndex = 15;
               // 
               // backButton
               // 
               this->backButton->Location = System::Drawing::Point(27, 25);
               this->backButton->Name = L"backButton";
               this->backButton->Size = System::Drawing::Size(85, 64);
               this->backButton->TabIndex = 23;
               this->backButton->Text = L"Home";
               this->backButton->UseVisualStyleBackColor = true;
               this->backButton->Click += gcnew System::EventHandler(this, &BorrowForm::backButton_Click);
               // 
               // studentNumberLabel
               // 
               this->studentNumberLabel->AutoSize = true;
               this->studentNumberLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
               this->studentNumberLabel->Location = System::Drawing::Point(488, 54);
               this->studentNumberLabel->Name = L"studentNumberLabel";
               this->studentNumberLabel->Size = System::Drawing::Size(44, 16);
               this->studentNumberLabel->TabIndex = 22;
               this->studentNumberLabel->Text = L"label2";
               // 
               // label5
               // 
               this->label5->AutoSize = true;
               this->label5->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label5->Location = System::Drawing::Point(487, 30);
               this->label5->Name = L"label5";
               this->label5->Size = System::Drawing::Size(123, 19);
               this->label5->TabIndex = 21;
               this->label5->Text = L"Student Name:";
               // 
               // searchLabel
               // 
               this->searchLabel->AutoSize = true;
               this->searchLabel->Location = System::Drawing::Point(744, 30);
               this->searchLabel->Name = L"searchLabel";
               this->searchLabel->Size = System::Drawing::Size(41, 13);
               this->searchLabel->TabIndex = 15;
               this->searchLabel->Text = L"Search";
               // 
               // searchBorrowTextBox
               // 
               this->searchBorrowTextBox->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10));
               this->searchBorrowTextBox->Location = System::Drawing::Point(747, 46);
               this->searchBorrowTextBox->Name = L"searchBorrowTextBox";
               this->searchBorrowTextBox->Size = System::Drawing::Size(217, 24);
               this->searchBorrowTextBox->TabIndex = 14;
               this->searchBorrowTextBox->TabStop = false;
               this->searchBorrowTextBox->TextChanged += gcnew System::EventHandler(this, &BorrowForm::searchBorrowTextBox_TextChanged);
               // 
               // timeLabel
               // 
               this->timeLabel->AutoSize = true;
               this->timeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->timeLabel->Location = System::Drawing::Point(365, 54);
               this->timeLabel->Name = L"timeLabel";
               this->timeLabel->Size = System::Drawing::Size(44, 16);
               this->timeLabel->TabIndex = 6;
               this->timeLabel->Text = L"label2";
               // 
               // label3
               // 
               this->label3->AutoSize = true;
               this->label3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label3->Location = System::Drawing::Point(364, 30);
               this->label3->Name = L"label3";
               this->label3->Size = System::Drawing::Size(50, 19);
               this->label3->TabIndex = 5;
               this->label3->Text = L"Time:";
               // 
               // dateLabel
               // 
               this->dateLabel->AutoSize = true;
               this->dateLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->dateLabel->Location = System::Drawing::Point(182, 54);
               this->dateLabel->Name = L"dateLabel";
               this->dateLabel->Size = System::Drawing::Size(44, 16);
               this->dateLabel->TabIndex = 4;
               this->dateLabel->Text = L"label2";
               // 
               // searchIDLabel
               // 
               this->searchIDLabel->AutoSize = true;
               this->searchIDLabel->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->searchIDLabel->Location = System::Drawing::Point(181, 30);
               this->searchIDLabel->Name = L"searchIDLabel";
               this->searchIDLabel->Size = System::Drawing::Size(49, 19);
               this->searchIDLabel->TabIndex = 3;
               this->searchIDLabel->Text = L"Date:";
               // 
               // borrowButton
               // 
               this->borrowButton->Location = System::Drawing::Point(462, 527);
               this->borrowButton->Name = L"borrowButton";
               this->borrowButton->Size = System::Drawing::Size(75, 27);
               this->borrowButton->TabIndex = 20;
               this->borrowButton->Text = L"Add";
               this->borrowButton->UseVisualStyleBackColor = true;
               this->borrowButton->Click += gcnew System::EventHandler(this, &BorrowForm::borrowButton_Click);
               // 
               // labelQuantity
               // 
               this->labelQuantity->AutoSize = true;
               this->labelQuantity->Location = System::Drawing::Point(379, 513);
               this->labelQuantity->Name = L"labelQuantity";
               this->labelQuantity->Size = System::Drawing::Size(46, 13);
               this->labelQuantity->TabIndex = 19;
               this->labelQuantity->Text = L"Quantity";
               // 
               // borrowQuantity
               // 
               this->borrowQuantity->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10));
               this->borrowQuantity->Location = System::Drawing::Point(382, 529);
               this->borrowQuantity->Name = L"borrowQuantity";
               this->borrowQuantity->Size = System::Drawing::Size(44, 24);
               this->borrowQuantity->TabIndex = 18;
               // 
               // label2
               // 
               this->label2->AutoSize = true;
               this->label2->Location = System::Drawing::Point(255, 513);
               this->label2->Name = L"label2";
               this->label2->Size = System::Drawing::Size(18, 13);
               this->label2->TabIndex = 17;
               this->label2->Text = L"ID";
               // 
               // borrowID
               // 
               this->borrowID->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10));
               this->borrowID->Location = System::Drawing::Point(257, 529);
               this->borrowID->Name = L"borrowID";
               this->borrowID->Size = System::Drawing::Size(91, 24);
               this->borrowID->TabIndex = 16;
               // 
               // panel1
               // 
               this->panel1->Controls->Add(this->dataGridView1);
               this->panel1->Location = System::Drawing::Point(0, 105);
               this->panel1->Name = L"panel1";
               this->panel1->Size = System::Drawing::Size(976, 390);
               this->panel1->TabIndex = 16;
               // 
               // dataGridView1
               // 
               this->dataGridView1->AllowUserToAddRows = false;
               this->dataGridView1->AllowUserToDeleteRows = false;
               this->dataGridView1->AllowUserToResizeColumns = false;
               this->dataGridView1->AllowUserToResizeRows = false;
               this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
               this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
               this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
               this->dataGridView1->Location = System::Drawing::Point(0, 0);
               this->dataGridView1->Name = L"dataGridView1";
               this->dataGridView1->ReadOnly = true;
               this->dataGridView1->Size = System::Drawing::Size(976, 390);
               this->dataGridView1->TabIndex = 19;
               this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &BorrowForm::dataGridView1_CellContentClick);
               // 
               // label1
               // 
               this->label1->AutoSize = true;
               this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label1->Location = System::Drawing::Point(13, 527);
               this->label1->Name = L"label1";
               this->label1->Size = System::Drawing::Size(224, 25);
               this->label1->TabIndex = 18;
               this->label1->Text = L"List of Borrowed Items";
               // 
               // timer1
               // 
               this->timer1->Interval = 1000;
               this->timer1->Tick += gcnew System::EventHandler(this, &BorrowForm::timer1_Tick);
               // 
               // borrowedItemsGrid
               // 
               this->borrowedItemsGrid->AllowUserToAddRows = false;
               this->borrowedItemsGrid->AllowUserToDeleteRows = false;
               this->borrowedItemsGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
               this->borrowedItemsGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
               this->borrowedItemsGrid->Location = System::Drawing::Point(0, 572);
               this->borrowedItemsGrid->Name = L"borrowedItemsGrid";
               this->borrowedItemsGrid->ReadOnly = true;
               this->borrowedItemsGrid->Size = System::Drawing::Size(976, 152);
               this->borrowedItemsGrid->TabIndex = 19;
               // 
               // checkOutButton
               // 
               this->checkOutButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
               this->checkOutButton->Location = System::Drawing::Point(816, 518);
               this->checkOutButton->Name = L"checkOutButton";
               this->checkOutButton->Size = System::Drawing::Size(148, 38);
               this->checkOutButton->TabIndex = 20;
               this->checkOutButton->Text = L"Check Out";
               this->checkOutButton->UseVisualStyleBackColor = true;
               this->checkOutButton->Click += gcnew System::EventHandler(this, &BorrowForm::checkOutButton_Click);
               // 
               // BorrowForm
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->ClientSize = System::Drawing::Size(976, 725);
               this->Controls->Add(this->checkOutButton);
               this->Controls->Add(this->borrowedItemsGrid);
               this->Controls->Add(this->borrowButton);
               this->Controls->Add(this->labelQuantity);
               this->Controls->Add(this->label1);
               this->Controls->Add(this->borrowQuantity);
               this->Controls->Add(this->panel1);
               this->Controls->Add(this->label2);
               this->Controls->Add(this->panel3);
               this->Controls->Add(this->borrowID);
               this->Name = L"BorrowForm";
               this->Text = L"EECE Inventory Tracker | Borrow";
               this->Load += gcnew System::EventHandler(this, &BorrowForm::BorrowForm_Load);
               this->panel3->ResumeLayout(false);
               this->panel3->PerformLayout();
               this->panel1->ResumeLayout(false);
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->borrowedItemsGrid))->EndInit();
               this->ResumeLayout(false);
               this->PerformLayout();

           }
#pragma endregion
    private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    }
    private: System::Void dateLabel_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void BorrowForm_Load(System::Object^ sender, System::EventArgs^ e) {
        DateTime dateTime = DateTime::Now;
        dateLabel->Text = dateTime.ToLongDateString(); //Date
        timeLabel->Text = dateTime.ToLongTimeString(); //Time
        timer1->Start();
        LoadEquipmentData();
        InitializeBorrowedItemsGrid();
    }
    private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
        DateTime timeNow = DateTime::Now;
        timeLabel->Text = timeNow.ToLongTimeString();
    }
    private: System::Void LoadEquipmentData() {
        Equipment equipment("C:\\Users\\Keith Naval\\Downloads\\equipments.csv");
        DataTable^ dt = gcnew DataTable(); // Create new table
        dt->Columns->Add("ID");
        dt->Columns->Add("Name");
        dt->Columns->Add("Type");
        dt->Columns->Add("Status");
        dt->Columns->Add("Specs");
        dt->Columns->Add("Quantity");

        for (int i = 0; i < equipment.equipmentCount; ++i) {
            DataRow^ row = dt->NewRow();
            row["ID"] = gcnew String(equipment.getId(equipment.equipmentData[i].equipmentId).c_str());
            row["Name"] = gcnew String(equipment.getName(equipment.equipmentData[i].equipmentId).c_str());
            row["Type"] = gcnew String(equipment.getType(equipment.equipmentData[i].equipmentId).c_str());
            row["Status"] = gcnew String(equipment.getStatus(equipment.equipmentData[i].equipmentId).c_str());
            row["Specs"] = gcnew String(equipment.getSpecs(equipment.equipmentData[i].equipmentId).c_str());
            row["Quantity"] = gcnew String(equipment.getQuantity(equipment.equipmentData[i].equipmentId).c_str());
            dt->Rows->Add(row);
        }

        equipmentTable = dt;
        dataGridView1->DataSource = equipmentTable;
    }
    private: System::Void InitializeBorrowedItemsGrid() {
        borrowedItemsTable = gcnew DataTable();
        borrowedItemsTable->Columns->Add("ID");
        borrowedItemsTable->Columns->Add("Name");
        borrowedItemsTable->Columns->Add("Type");
        borrowedItemsTable->Columns->Add("Status");
        borrowedItemsTable->Columns->Add("Specs");
        borrowedItemsTable->Columns->Add("Quantity");
        borrowedItemsGrid->DataSource = borrowedItemsTable;
    }
    private: System::Void borrowButton_Click(System::Object^ sender, System::EventArgs^ e) {
        Borrow::BorrowEquipment(borrowID, borrowQuantity, equipmentTable, borrowedItemsTable, dataGridView1);
    }

    private: System::Void searchBorrowTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
        String^ search = searchBorrowTextBox->Text;
        if (search->Length == 0) {
            (safe_cast<DataTable^>(dataGridView1->DataSource))->DefaultView->RowFilter = "";
        }
        else {
            String^ filterExpression = String::Format("ID LIKE '%{0}%' OR Name LIKE '%{0}%' OR Type LIKE '%{0}%' OR Status LIKE '%{0}%' OR Specs LIKE '%{0}%' OR Quantity LIKE '%{0}%'", search);
            (safe_cast<DataTable^>(dataGridView1->DataSource))->DefaultView->RowFilter = filterExpression;
        }
    }
    private: System::Void checkOutButton_Click(System::Object^ sender, System::EventArgs^ e) {
        Borrow::CheckOut(borrowedItemsTable, equipmentTable, InventoryManager, StudentNumber);
        this->Hide();
    }
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void borrowID_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void borrowQuantity_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void labelQuantity_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void backButton_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Hide();
    InventoryManager->Show();
}
};
}