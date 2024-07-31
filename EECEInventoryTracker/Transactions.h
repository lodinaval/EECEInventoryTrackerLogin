#pragma once

#include <fstream>
#include <msclr/marshal_cppstd.h>
#include <sstream>

namespace EECEInventoryTracker {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class Transactions : public System::Windows::Forms::Form
    {
    public:
        Form^ previousForm;

        Transactions(Form^ prevForm)
        {
            InitializeComponent();
            previousForm = prevForm;
            LoadTransactionData();
        }

    protected:
        ~Transactions()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::DataGridView^ dataGridView1;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Button^ backButton;

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->backButton = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            this->SuspendLayout();
            // 
            // dataGridView1
            // 
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView1->Location = System::Drawing::Point(0, 69);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->ReadOnly = true;
            this->dataGridView1->Size = System::Drawing::Size(783, 493);
            this->dataGridView1->TabIndex = 0;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(331, 22);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(122, 22);
            this->label1->TabIndex = 1;
            this->label1->Text = L"Transactions";
            // 
            // backButton
            // 
            this->backButton->Location = System::Drawing::Point(26, 10);
            this->backButton->Name = L"backButton";
            this->backButton->Size = System::Drawing::Size(75, 50);
            this->backButton->TabIndex = 2;
            this->backButton->Text = L"Home";
            this->backButton->UseVisualStyleBackColor = true;
            this->backButton->Click += gcnew System::EventHandler(this, &Transactions::backButton_Click);
            // 
            // Transactions
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(784, 561);
            this->Controls->Add(this->backButton);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->dataGridView1);
            this->Name = L"Transactions";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"EECE Inventory Tracker | Transactions";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private:
        void LoadTransactionData()
        {
            DataTable^ transactionTable = gcnew DataTable();
            transactionTable->Columns->Add("Transaction ID");
            transactionTable->Columns->Add("Student Number");
            transactionTable->Columns->Add("DateTime");
            transactionTable->Columns->Add("ID");
            transactionTable->Columns->Add("Name");
            transactionTable->Columns->Add("Type");
            transactionTable->Columns->Add("Status");
            transactionTable->Columns->Add("Specs");
            transactionTable->Columns->Add("Quantity");

            std::ifstream file("C:\\Users\\Keith Naval\\Downloads\\borrowTransactions.csv");
            std::string line;
            if (std::getline(file, line)) {
                // First line is the header, so skip it.
            }
            while (std::getline(file, line)) {
                std::istringstream iss(line);
                std::string transactionID, studentNumber, dateTime, id, name, type, status, specs, quantity;
                std::getline(iss, transactionID, ',');
                std::getline(iss, studentNumber, ',');
                std::getline(iss, dateTime, ',');
                std::getline(iss, id, ',');
                std::getline(iss, name, ',');
                std::getline(iss, type, ',');
                std::getline(iss, status, ',');
                std::getline(iss, specs, ',');
                std::getline(iss, quantity, ',');

                DataRow^ row = transactionTable->NewRow();
                row["Transaction ID"] = gcnew String(transactionID.c_str());
                row["Student Number"] = gcnew String(studentNumber.c_str());
                row["DateTime"] = gcnew String(dateTime.c_str());
                row["ID"] = gcnew String(id.c_str());
                row["Name"] = gcnew String(name.c_str());
                row["Type"] = gcnew String(type.c_str());
                row["Status"] = gcnew String(status.c_str());
                row["Specs"] = gcnew String(specs.c_str());
                row["Quantity"] = gcnew String(quantity.c_str());
                transactionTable->Rows->Add(row);
            }

            dataGridView1->DataSource = transactionTable;
        }

        void backButton_Click(System::Object^ sender, System::EventArgs^ e) {
            this->Hide();
            previousForm->Show();
        }
    };
}
