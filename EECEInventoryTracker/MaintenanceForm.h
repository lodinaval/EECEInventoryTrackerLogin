#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <msclr/marshal_cppstd.h>

namespace EECEInventoryTracker {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace std;

    public ref class MaintenanceForm : public System::Windows::Forms::Form
    {
    public:
        MaintenanceForm(Form^ previous)
        {
            InitializeComponent();
            previousForm = previous;
            LoadMaintenanceData();
            LoadEquipmentData();
            InitializeTextBoxes();
        }

    protected:
        ~MaintenanceForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::DataGridView^ dataGridView1;
    private: System::Windows::Forms::DataGridView^ dataGridView2;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Button^ backButton;
    private: System::Windows::Forms::Button^ addButton;
    private: System::Windows::Forms::TextBox^ equipmentIDTextBox;
    private: System::Windows::Forms::TextBox^ dateTextBox;
    private: System::Windows::Forms::TextBox^ descriptionTextBox;
    private: System::Windows::Forms::TextBox^ technicianTextBox;
    private: Form^ previousForm;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ searchIDLabel;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Label^ label5;

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->backButton = (gcnew System::Windows::Forms::Button());
            this->addButton = (gcnew System::Windows::Forms::Button());
            this->equipmentIDTextBox = (gcnew System::Windows::Forms::TextBox());
            this->dateTextBox = (gcnew System::Windows::Forms::TextBox());
            this->descriptionTextBox = (gcnew System::Windows::Forms::TextBox());
            this->technicianTextBox = (gcnew System::Windows::Forms::TextBox());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->searchIDLabel = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
            this->SuspendLayout();
            // 
            // dataGridView1
            // 
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView1->Location = System::Drawing::Point(338, 88);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->Size = System::Drawing::Size(434, 402);
            this->dataGridView1->TabIndex = 0;
            // 
            // dataGridView2
            // 
            this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView2->Location = System::Drawing::Point(12, 88);
            this->dataGridView2->Name = L"dataGridView2";
            this->dataGridView2->Size = System::Drawing::Size(320, 402);
            this->dataGridView2->TabIndex = 1;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(462, 53);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(214, 22);
            this->label1->TabIndex = 2;
            this->label1->Text = L"Maintenance Records";
            // 
            // backButton
            // 
            this->backButton->Location = System::Drawing::Point(12, 10);
            this->backButton->Name = L"backButton";
            this->backButton->Size = System::Drawing::Size(75, 65);
            this->backButton->TabIndex = 3;
            this->backButton->Text = L"Home";
            this->backButton->UseVisualStyleBackColor = true;
            this->backButton->Click += gcnew System::EventHandler(this, &MaintenanceForm::backButton_Click);
            // 
            // addButton
            // 
            this->addButton->Location = System::Drawing::Point(697, 499);
            this->addButton->Name = L"addButton";
            this->addButton->Size = System::Drawing::Size(75, 50);
            this->addButton->TabIndex = 4;
            this->addButton->Text = L"Add";
            this->addButton->UseVisualStyleBackColor = true;
            this->addButton->Click += gcnew System::EventHandler(this, &MaintenanceForm::addButton_Click);
            // 
            // equipmentIDTextBox
            // 
            this->equipmentIDTextBox->Location = System::Drawing::Point(12, 521);
            this->equipmentIDTextBox->Name = L"equipmentIDTextBox";
            this->equipmentIDTextBox->Size = System::Drawing::Size(100, 20);
            this->equipmentIDTextBox->TabIndex = 5;
            this->equipmentIDTextBox->TextChanged += gcnew System::EventHandler(this, &MaintenanceForm::RemovePlaceholderText);
            this->equipmentIDTextBox->Leave += gcnew System::EventHandler(this, &MaintenanceForm::AddPlaceholderText);
            // 
            // dateTextBox
            // 
            this->dateTextBox->Location = System::Drawing::Point(140, 521);
            this->dateTextBox->Name = L"dateTextBox";
            this->dateTextBox->Size = System::Drawing::Size(100, 20);
            this->dateTextBox->TabIndex = 6;
            this->dateTextBox->TextChanged += gcnew System::EventHandler(this, &MaintenanceForm::RemovePlaceholderText);
            this->dateTextBox->Leave += gcnew System::EventHandler(this, &MaintenanceForm::AddPlaceholderText);
            // 
            // descriptionTextBox
            // 
            this->descriptionTextBox->Location = System::Drawing::Point(271, 521);
            this->descriptionTextBox->Multiline = true;
            this->descriptionTextBox->Name = L"descriptionTextBox";
            this->descriptionTextBox->Size = System::Drawing::Size(200, 20);
            this->descriptionTextBox->TabIndex = 7;
            this->descriptionTextBox->TextChanged += gcnew System::EventHandler(this, &MaintenanceForm::RemovePlaceholderText);
            this->descriptionTextBox->Leave += gcnew System::EventHandler(this, &MaintenanceForm::AddPlaceholderText);
            // 
            // technicianTextBox
            // 
            this->technicianTextBox->Location = System::Drawing::Point(492, 521);
            this->technicianTextBox->Name = L"technicianTextBox";
            this->technicianTextBox->Size = System::Drawing::Size(180, 20);
            this->technicianTextBox->TabIndex = 8;
            this->technicianTextBox->TextChanged += gcnew System::EventHandler(this, &MaintenanceForm::RemovePlaceholderText);
            this->technicianTextBox->Leave += gcnew System::EventHandler(this, &MaintenanceForm::AddPlaceholderText);
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(105, 53);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(149, 22);
            this->label2->TabIndex = 9;
            this->label2->Text = L"Lab Equipment";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(139, 505);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(105, 13);
            this->label3->TabIndex = 11;
            this->label3->Text = L"Date MM/DD/YYYY";
            this->label3->Click += gcnew System::EventHandler(this, &MaintenanceForm::label3_Click);
            // 
            // searchIDLabel
            // 
            this->searchIDLabel->AutoSize = true;
            this->searchIDLabel->Location = System::Drawing::Point(10, 505);
            this->searchIDLabel->Name = L"searchIDLabel";
            this->searchIDLabel->Size = System::Drawing::Size(18, 13);
            this->searchIDLabel->TabIndex = 10;
            this->searchIDLabel->Text = L"ID";
            this->searchIDLabel->Click += gcnew System::EventHandler(this, &MaintenanceForm::searchIDLabel_Click);
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(269, 505);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(60, 13);
            this->label4->TabIndex = 12;
            this->label4->Text = L"Description";
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Location = System::Drawing::Point(489, 505);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(60, 13);
            this->label5->TabIndex = 13;
            this->label5->Text = L"Technician";
            // 
            // MaintenanceForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(784, 561);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->searchIDLabel);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->technicianTextBox);
            this->Controls->Add(this->descriptionTextBox);
            this->Controls->Add(this->dateTextBox);
            this->Controls->Add(this->equipmentIDTextBox);
            this->Controls->Add(this->addButton);
            this->Controls->Add(this->backButton);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->dataGridView2);
            this->Controls->Add(this->dataGridView1);
            this->Name = L"MaintenanceForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"EECE Inventory Tracker | Maintenance";
            this->Load += gcnew System::EventHandler(this, &MaintenanceForm::MaintenanceForm_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion


    private: System::Void backButton_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Hide();
        previousForm->Show();
    }

    private: System::Void addButton_Click(System::Object^ sender, System::EventArgs^ e) {
        std::ofstream file("C:\\Users\\Keith Naval\\Downloads\\maintenance.csv", std::ios::app);

        std::string equipmentID = msclr::interop::marshal_as<std::string>(equipmentIDTextBox->Text);
        std::string date = msclr::interop::marshal_as<std::string>(dateTextBox->Text);
        std::string description = msclr::interop::marshal_as<std::string>(descriptionTextBox->Text);
        std::string technician = msclr::interop::marshal_as<std::string>(technicianTextBox->Text);

        file << equipmentID << "," << date << "," << description << "," << technician << "\n";
        file.close();

        LoadMaintenanceData();
    }

private: System::Void MaintenanceForm_Load(System::Object^ sender, System::EventArgs^ e) {
    LoadMaintenanceData();
    LoadEquipmentData();
    InitializeTextBoxes();
}

private: System::Void LoadMaintenanceData() {
    DataTable^ maintenanceTable = gcnew DataTable();
    maintenanceTable->Columns->Add("Equipment ID");
    maintenanceTable->Columns->Add("Date");
    maintenanceTable->Columns->Add("Description");
    maintenanceTable->Columns->Add("Technician");

    std::ifstream file("C:\\Users\\Keith Naval\\Downloads\\maintenance.csv");
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string equipmentID, date, description, technician;
        std::getline(iss, equipmentID, ',');
        std::getline(iss, date, ',');
        std::getline(iss, description, ',');
        std::getline(iss, technician, ',');

        DataRow^ row = maintenanceTable->NewRow();
        row["Equipment ID"] = gcnew String(equipmentID.c_str());
        row["Date"] = gcnew String(date.c_str());
        row["Description"] = gcnew String(description.c_str());
        row["Technician"] = gcnew String(technician.c_str());
        maintenanceTable->Rows->Add(row);
    }

    dataGridView1->DataSource = maintenanceTable;
}

private: System::Void LoadEquipmentData() {
    DataTable^ equipmentTable = gcnew DataTable();
    equipmentTable->Columns->Add("ID");
    equipmentTable->Columns->Add("Name");
    equipmentTable->Columns->Add("Type");
    equipmentTable->Columns->Add("Status");
    equipmentTable->Columns->Add("Specs");
    equipmentTable->Columns->Add("Quantity");

    std::ifstream file("C:\\Users\\Keith Naval\\Downloads\\equipments.csv");
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string id, name, type, status, specs, quantity;
        std::getline(iss, id, ',');
        std::getline(iss, name, ',');
        std::getline(iss, type, ',');
        std::getline(iss, status, ',');
        std::getline(iss, specs, ',');
        std::getline(iss, quantity, ',');

        DataRow^ row = equipmentTable->NewRow();
        row["ID"] = gcnew String(id.c_str());
        row["Name"] = gcnew String(name.c_str());
        row["Type"] = gcnew String(type.c_str());
        row["Status"] = gcnew String(status.c_str());
        row["Specs"] = gcnew String(specs.c_str());
        row["Quantity"] = gcnew String(quantity.c_str());
        equipmentTable->Rows->Add(row);
    }

    dataGridView2->DataSource = equipmentTable;
}

private: System::Void InitializeTextBoxes() {
    equipmentIDTextBox->Text = "Equipment ID";
    dateTextBox->Text = "Date (MM/DD/YYYY)";
    descriptionTextBox->Text = "Description";
    technicianTextBox->Text = "Technician";
}

private: System::Void RemovePlaceholderText(System::Object^ sender, System::EventArgs^ e) {
    TextBox^ textBox = (TextBox^)sender;
    if (textBox->Text == "Equipment ID" || textBox->Text == "Date (MM/DD/YYYY)" || textBox->Text == "Description" || textBox->Text == "Technician") {
        textBox->Text = "";
    }
}

private: System::Void AddPlaceholderText(System::Object^ sender, System::EventArgs^ e) {
    TextBox^ textBox = (TextBox^)sender;
    if (String::IsNullOrWhiteSpace(textBox->Text)) {
        if (textBox == equipmentIDTextBox) textBox->Text = "Equipment ID";
        else if (textBox == dateTextBox) textBox->Text = "Date (MM/DD/YYYY)";
        else if (textBox == descriptionTextBox) textBox->Text = "Description";
        else if (textBox == technicianTextBox) textBox->Text = "Technician";
    }
}

private: System::Void equipmentIDTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void dateTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void descriptionTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void technicianTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void searchIDLabel_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}

