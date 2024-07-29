#pragma once
#include "Equipment.h"
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

    public ref class EquipmentForm : public System::Windows::Forms::Form
    {
    public:
        EquipmentForm(void)
        {
            InitializeComponent();
            LoadEquipmentData();
        }

        EquipmentForm(Form^ inventoryManagerObj)
        {
            InitializeComponent();
            LoadEquipmentData();
            InventoryManager = inventoryManagerObj;

        }

    protected:
        ~EquipmentForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::DataGridView^ equipmentGridView;
           
    protected:

    private:
        Form^ InventoryManager;
        System::Windows::Forms::Panel^ panel1;
        System::Windows::Forms::Label^ searchStatus;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::TextBox^ addType;
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::TextBox^ addName;
        System::Windows::Forms::Label^ searchIDLabel;
        System::Windows::Forms::TextBox^ addID;
        System::Windows::Forms::ComboBox^ addStatus;
        System::Windows::Forms::Button^ addEquipmentButton;
    private: System::Windows::Forms::Panel^ panel2;
    private: System::Windows::Forms::RichTextBox^ addSpecs;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::TextBox^ searchTextBox;
    private: System::Windows::Forms::Label^ searchLabel;
    private: System::Windows::Forms::Panel^ panel3;
    private: System::Windows::Forms::Label^ labelQuantity;
    private: System::Windows::Forms::TextBox^ addQuantity;
    private: System::Windows::Forms::Button^ backButton;

           System::ComponentModel::Container^ components;

           void LoadEquipmentData() {
               Equipment equipment("C:\\Users\\Keith Naval\\Downloads\\equipments.csv"); // Update with your actual path
               DataTable^ dt = gcnew DataTable();
               dt->Columns->Add("ID");
               dt->Columns->Add("Name");
               dt->Columns->Add("Type");
               dt->Columns->Add("Status");
               dt->Columns->Add("Specs");
               dt->Columns->Add("Quantity");

               for (const auto& item : equipment.getEquipmentData()) {
                   auto equipmentInfo = item.second;
                   DataRow^ row = dt->NewRow();
                   row["ID"] = gcnew String(item.first.c_str());
                   row["Name"] = gcnew String(equipmentInfo.getName().c_str());
                   row["Type"] = gcnew String(equipmentInfo.getType().c_str());
                   row["Status"] = gcnew String(equipmentInfo.getStatus().c_str());
                   row["Specs"] = gcnew String(equipmentInfo.getSpecs().c_str());
                   row["Quantity"] = gcnew String(equipmentInfo.getQuantity().c_str());
                   dt->Rows->Add(row);
               }

               equipmentGridView->DataSource = dt;

               // Add delete button column only if it doesn't exist
               if (equipmentGridView->Columns["deleteButtonColumn"] == nullptr) {
                   System::Windows::Forms::DataGridViewButtonColumn^ deleteButtonColumn = gcnew System::Windows::Forms::DataGridViewButtonColumn();
                   deleteButtonColumn->HeaderText = "Delete";
                   deleteButtonColumn->Name = "deleteButtonColumn";
                   deleteButtonColumn->Text = "Delete";
                   deleteButtonColumn->UseColumnTextForButtonValue = true;
                   equipmentGridView->Columns->Add(deleteButtonColumn);
               }
           }

           void UpdateCsv(const std::string& id, const std::string& name, const std::string& type, const std::string& status, const std::string& specs, const std::string& quantity) {
               std::ifstream file("C:\\Users\\Keith Naval\\Downloads\\equipments.csv");
               std::ofstream tempFile("temp.csv");
               std::string line;

               while (std::getline(file, line)) {
                   std::stringstream ss(line);
                   std::string currentId;
                   std::getline(ss, currentId, ',');

                   if (currentId == id) {
                       tempFile << id << "," << name << "," << type << "," << status << "," << specs << "," << quantity << std::endl;
                   }
                   else {
                       tempFile << line << std::endl;
                   }
               }

               file.close();
               tempFile.close();

               std::remove("C:\\Users\\Keith Naval\\Downloads\\equipments.csv");
               std::rename("temp.csv", "C:\\Users\\Keith Naval\\Downloads\\equipments.csv");
           }

           void removeEntryFromCsv(const std::string& id) {
               std::ifstream file("C:\\Users\\Keith Naval\\Downloads\\equipments.csv");
               std::ofstream tempFile("temp.csv");
               std::string line;

               while (std::getline(file, line)) {
                   std::stringstream ss(line);
                   std::string currentId;
                   std::getline(ss, currentId, ',');

                   if (currentId != id) {
                       tempFile << line << std::endl;
                   }
               }

               file.close();
               tempFile.close();

               std::remove("C:\\Users\\Keith Naval\\Downloads\\equipments.csv");
               std::rename("temp.csv", "C:\\Users\\Keith Naval\\Downloads\\equipments.csv");
           }

#pragma region Windows Form Designer generated code
           void InitializeComponent(void)
           {
               this->equipmentGridView = (gcnew System::Windows::Forms::DataGridView());
               this->panel1 = (gcnew System::Windows::Forms::Panel());
               this->label3 = (gcnew System::Windows::Forms::Label());
               this->addSpecs = (gcnew System::Windows::Forms::RichTextBox());
               this->addEquipmentButton = (gcnew System::Windows::Forms::Button());
               this->addStatus = (gcnew System::Windows::Forms::ComboBox());
               this->searchStatus = (gcnew System::Windows::Forms::Label());
               this->label2 = (gcnew System::Windows::Forms::Label());
               this->addType = (gcnew System::Windows::Forms::TextBox());
               this->label1 = (gcnew System::Windows::Forms::Label());
               this->addName = (gcnew System::Windows::Forms::TextBox());
               this->searchIDLabel = (gcnew System::Windows::Forms::Label());
               this->addID = (gcnew System::Windows::Forms::TextBox());
               this->labelQuantity = (gcnew System::Windows::Forms::Label());
               this->addQuantity = (gcnew System::Windows::Forms::TextBox());
               this->searchTextBox = (gcnew System::Windows::Forms::TextBox());
               this->panel2 = (gcnew System::Windows::Forms::Panel());
               this->searchLabel = (gcnew System::Windows::Forms::Label());
               this->panel3 = (gcnew System::Windows::Forms::Panel());
               this->backButton = (gcnew System::Windows::Forms::Button());
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->equipmentGridView))->BeginInit();
               this->panel1->SuspendLayout();
               this->panel2->SuspendLayout();
               this->panel3->SuspendLayout();
               this->SuspendLayout();
               // 
               // equipmentGridView
               // 
               this->equipmentGridView->AllowUserToAddRows = false;
               this->equipmentGridView->AllowUserToDeleteRows = false;
               this->equipmentGridView->AllowUserToResizeColumns = false;
               this->equipmentGridView->AllowUserToResizeRows = false;
               this->equipmentGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
               this->equipmentGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
               this->equipmentGridView->Dock = System::Windows::Forms::DockStyle::Fill;
               this->equipmentGridView->Location = System::Drawing::Point(0, 0);
               this->equipmentGridView->Name = L"equipmentGridView";
               this->equipmentGridView->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
               this->equipmentGridView->Size = System::Drawing::Size(1064, 485);
               this->equipmentGridView->TabIndex = 0;
               this->equipmentGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &EquipmentForm::dataGridView1_CellContentClick);
               this->equipmentGridView->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &EquipmentForm::equipmentGridView_CellValueChanged);
               // 
               // panel1
               // 
               this->panel1->Controls->Add(this->label3);
               this->panel1->Controls->Add(this->addSpecs);
               this->panel1->Controls->Add(this->addEquipmentButton);
               this->panel1->Controls->Add(this->addStatus);
               this->panel1->Controls->Add(this->searchStatus);
               this->panel1->Controls->Add(this->label2);
               this->panel1->Controls->Add(this->addType);
               this->panel1->Controls->Add(this->label1);
               this->panel1->Controls->Add(this->addName);
               this->panel1->Controls->Add(this->searchIDLabel);
               this->panel1->Controls->Add(this->addID);
               this->panel1->Controls->Add(this->labelQuantity);
               this->panel1->Controls->Add(this->addQuantity);
               this->panel1->Dock = System::Windows::Forms::DockStyle::Bottom;
               this->panel1->Location = System::Drawing::Point(0, 553);
               this->panel1->Name = L"panel1";
               this->panel1->Size = System::Drawing::Size(1064, 82);
               this->panel1->TabIndex = 1;
               this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &EquipmentForm::panel1_Paint);
               // 
               // label3
               // 
               this->label3->AutoSize = true;
               this->label3->Location = System::Drawing::Point(656, 12);
               this->label3->Name = L"label3";
               this->label3->Size = System::Drawing::Size(73, 13);
               this->label3->TabIndex = 11;
               this->label3->Text = L"Specifications";
               // 
               // addSpecs
               // 
               this->addSpecs->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->addSpecs->Location = System::Drawing::Point(659, 32);
               this->addSpecs->Name = L"addSpecs";
               this->addSpecs->Size = System::Drawing::Size(152, 23);
               this->addSpecs->TabIndex = 10;
               this->addSpecs->Text = L"";
               this->addSpecs->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &EquipmentForm::richTextBox1_MouseClick);
               this->addSpecs->TextChanged += gcnew System::EventHandler(this, &EquipmentForm::richTextBox1_TextChanged);
               this->addSpecs->Enter += gcnew System::EventHandler(this, &EquipmentForm::addSpecs_Enter);
               // 
               // addEquipmentButton
               // 
               this->addEquipmentButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->addEquipmentButton->Location = System::Drawing::Point(906, 27);
               this->addEquipmentButton->Name = L"addEquipmentButton";
               this->addEquipmentButton->Size = System::Drawing::Size(136, 31);
               this->addEquipmentButton->TabIndex = 9;
               this->addEquipmentButton->Text = L"Add Equipment";
               this->addEquipmentButton->UseVisualStyleBackColor = true;
               this->addEquipmentButton->Click += gcnew System::EventHandler(this, &EquipmentForm::addEquipmentButton_Click);
               this->addEquipmentButton->Leave += gcnew System::EventHandler(this, &EquipmentForm::addEquipmentButton_Leave);
               this->addEquipmentButton->MouseLeave += gcnew System::EventHandler(this, &EquipmentForm::addEquipmentButton_MouseLeave);
               // 
               // addStatus
               // 
               this->addStatus->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
               this->addStatus->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8));
               this->addStatus->FormattingEnabled = true;
               this->addStatus->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Available", L"Not Available" });
               this->addStatus->Location = System::Drawing::Point(508, 30);
               this->addStatus->Name = L"addStatus";
               this->addStatus->Size = System::Drawing::Size(123, 24);
               this->addStatus->TabIndex = 8;
               // 
               // searchStatus
               // 
               this->searchStatus->AutoSize = true;
               this->searchStatus->Location = System::Drawing::Point(505, 12);
               this->searchStatus->Name = L"searchStatus";
               this->searchStatus->Size = System::Drawing::Size(37, 13);
               this->searchStatus->TabIndex = 7;
               this->searchStatus->Text = L"Status";
               // 
               // label2
               // 
               this->label2->AutoSize = true;
               this->label2->Location = System::Drawing::Point(359, 11);
               this->label2->Name = L"label2";
               this->label2->Size = System::Drawing::Size(31, 13);
               this->label2->TabIndex = 5;
               this->label2->Text = L"Type";
               // 
               // addType
               // 
               this->addType->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10));
               this->addType->Location = System::Drawing::Point(359, 30);
               this->addType->Name = L"addType";
               this->addType->Size = System::Drawing::Size(125, 24);
               this->addType->TabIndex = 4;
               // 
               // label1
               // 
               this->label1->AutoSize = true;
               this->label1->Location = System::Drawing::Point(128, 12);
               this->label1->Name = L"label1";
               this->label1->Size = System::Drawing::Size(35, 13);
               this->label1->TabIndex = 3;
               this->label1->Text = L"Name";
               // 
               // addName
               // 
               this->addName->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10));
               this->addName->Location = System::Drawing::Point(128, 31);
               this->addName->Name = L"addName";
               this->addName->Size = System::Drawing::Size(212, 24);
               this->addName->TabIndex = 2;
               // 
               // searchIDLabel
               // 
               this->searchIDLabel->AutoSize = true;
               this->searchIDLabel->Location = System::Drawing::Point(12, 12);
               this->searchIDLabel->Name = L"searchIDLabel";
               this->searchIDLabel->Size = System::Drawing::Size(18, 13);
               this->searchIDLabel->TabIndex = 1;
               this->searchIDLabel->Text = L"ID";
               // 
               // addID
               // 
               this->addID->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10));
               this->addID->Location = System::Drawing::Point(12, 31);
               this->addID->Name = L"addID";
               this->addID->Size = System::Drawing::Size(91, 24);
               this->addID->TabIndex = 0;
               // 
               // labelQuantity
               // 
               this->labelQuantity->AutoSize = true;
               this->labelQuantity->Location = System::Drawing::Point(837, 12);
               this->labelQuantity->Name = L"labelQuantity";
               this->labelQuantity->Size = System::Drawing::Size(46, 13);
               this->labelQuantity->TabIndex = 14;
               this->labelQuantity->Text = L"Quantity";
               // 
               // addQuantity
               // 
               this->addQuantity->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10));
               this->addQuantity->Location = System::Drawing::Point(839, 31);
               this->addQuantity->Name = L"addQuantity";
               this->addQuantity->Size = System::Drawing::Size(44, 24);
               this->addQuantity->TabIndex = 13;
               // 
               // searchTextBox
               // 
               this->searchTextBox->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10));
               this->searchTextBox->Location = System::Drawing::Point(825, 28);
               this->searchTextBox->Name = L"searchTextBox";
               this->searchTextBox->Size = System::Drawing::Size(217, 24);
               this->searchTextBox->TabIndex = 12;
               this->searchTextBox->TabStop = false;
               this->searchTextBox->TextChanged += gcnew System::EventHandler(this, &EquipmentForm::searchTextBox_TextChanged);
               // 
               // panel2
               // 
               this->panel2->AutoScroll = true;
               this->panel2->Controls->Add(this->equipmentGridView);
               this->panel2->Dock = System::Windows::Forms::DockStyle::Bottom;
               this->panel2->Location = System::Drawing::Point(0, 68);
               this->panel2->Name = L"panel2";
               this->panel2->Size = System::Drawing::Size(1064, 485);
               this->panel2->TabIndex = 2;
               this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &EquipmentForm::panel2_Paint);
               // 
               // searchLabel
               // 
               this->searchLabel->AutoSize = true;
               this->searchLabel->Location = System::Drawing::Point(823, 12);
               this->searchLabel->Name = L"searchLabel";
               this->searchLabel->Size = System::Drawing::Size(41, 13);
               this->searchLabel->TabIndex = 13;
               this->searchLabel->Text = L"Search";
               // 
               // panel3
               // 
               this->panel3->Controls->Add(this->backButton);
               this->panel3->Controls->Add(this->searchLabel);
               this->panel3->Controls->Add(this->searchTextBox);
               this->panel3->Location = System::Drawing::Point(0, -2);
               this->panel3->Name = L"panel3";
               this->panel3->Size = System::Drawing::Size(1064, 64);
               this->panel3->TabIndex = 14;
               // 
               // backButton
               // 
               this->backButton->Location = System::Drawing::Point(27, 12);
               this->backButton->Name = L"backButton";
               this->backButton->Size = System::Drawing::Size(65, 40);
               this->backButton->TabIndex = 14;
               this->backButton->Text = L"HOME";
               this->backButton->UseVisualStyleBackColor = true;
               this->backButton->Click += gcnew System::EventHandler(this, &EquipmentForm::backButton_Click);
               // 
               // EquipmentForm
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->ClientSize = System::Drawing::Size(1064, 635);
               this->Controls->Add(this->panel2);
               this->Controls->Add(this->panel1);
               this->Controls->Add(this->panel3);
               this->Name = L"EquipmentForm";
               this->Text = L"EECE Inventory Tracker | Equipment";
               this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &EquipmentForm::EquipmentForm_FormClosing);
               this->Load += gcnew System::EventHandler(this, &EquipmentForm::EquipmentForm_Load);
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->equipmentGridView))->EndInit();
               this->panel1->ResumeLayout(false);
               this->panel1->PerformLayout();
               this->panel2->ResumeLayout(false);
               this->panel3->ResumeLayout(false);
               this->panel3->PerformLayout();
               this->ResumeLayout(false);

           }
#pragma endregion
    private: System::Void EquipmentForm_Load(System::Object^ sender, System::EventArgs^ e) {
        LoadEquipmentData();
    }
    private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    }
    private: System::Void addEquipmentButton_Click(System::Object^ sender, System::EventArgs^ e) {
        std::string addIDstr = msclr::interop::marshal_as<std::string>(addID->Text);
        std::string addNamestr = msclr::interop::marshal_as<std::string>(addName->Text);
        std::string addTypestr = msclr::interop::marshal_as<std::string>(addType->Text);
        std::string addStatusstr = msclr::interop::marshal_as<std::string>(addStatus->Text);
        std::string specs = msclr::interop::marshal_as<std::string>(addSpecs->Text);
        std::string quantity = msclr::interop::marshal_as<std::string>(addQuantity->Text);

        if (addIDstr.empty() || addNamestr.empty() || addTypestr.empty() || addStatusstr.empty() || quantity.empty()) {
            MessageBox::Show("Please fill in all the required fields: ID, Name, Type, Status, Quantity.", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        Equipment equipment;
        equipment.addEquipment(addIDstr, addNamestr, addTypestr, addStatusstr, specs, quantity, "C:\\Users\\Keith Naval\\Downloads\\equipments.csv");
        LoadEquipmentData();
        equipmentGridView->FirstDisplayedScrollingRowIndex = equipmentGridView->RowCount - 1;
    }
    private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
        if (e->ColumnIndex == equipmentGridView->Columns["deleteButtonColumn"]->Index && e->RowIndex >= 0) {
            String^ id = equipmentGridView->Rows[e->RowIndex]->Cells["ID"]->Value->ToString();
            std::string idStr = msclr::interop::marshal_as<std::string>(id);
            removeEntryFromCsv(idStr);
            LoadEquipmentData();
        }
    }
    private: System::Void equipmentGridView_CellValueChanged(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
        if (e->RowIndex >= 0 && e->ColumnIndex >= 0) {
            DataGridViewRow^ row = equipmentGridView->Rows[e->RowIndex];
            std::string id = msclr::interop::marshal_as<std::string>(row->Cells["ID"]->Value->ToString());
            std::string name = msclr::interop::marshal_as<std::string>(row->Cells["Name"]->Value->ToString());
            std::string type = msclr::interop::marshal_as<std::string>(row->Cells["Type"]->Value->ToString());
            std::string status = msclr::interop::marshal_as<std::string>(row->Cells["Status"]->Value->ToString());
            std::string specs = msclr::interop::marshal_as<std::string>(row->Cells["Specs"]->Value->ToString());
            std::string quantity = msclr::interop::marshal_as<std::string>(row->Cells["Quantity"]->Value->ToString());
            UpdateCsv(id, name, type, status, specs, quantity);
        }
    }
    private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    }
    private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void richTextBox1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
        addSpecs->AutoSize = false;
        addSpecs->Height = 200;
    }
    private: System::Void addEquipmentButton_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
        addSpecs->Height = 26;
    }
    private: System::Void addEquipmentButton_Leave(System::Object^ sender, System::EventArgs^ e) {
        addSpecs->Height = 26;
    }
    private: System::Void addSpecs_Enter(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void EquipmentForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
    }
    private: System::Void searchTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
        String^ search = searchTextBox->Text;
        if (search->Length == 0) {
            (safe_cast<DataTable^>(equipmentGridView->DataSource))->DefaultView->RowFilter = "";
        }
        else {
            String^ filterExpression = String::Format("ID LIKE '%{0}%' OR Name LIKE '%{0}%' OR Type LIKE '%{0}%' OR Status LIKE '%{0}%' OR Specs LIKE '%{0}%' OR Quantity LIKE '%{0}%'", search);
            (safe_cast<DataTable^>(equipmentGridView->DataSource))->DefaultView->RowFilter = filterExpression;
        }
    }
    private: System::Void backButton_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Hide();
        InventoryManager->Show();
    }
};
}
