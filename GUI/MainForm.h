#pragma once

// IMPORTANT:
// Native C++ headers are included BEFORE Windows Forms namespaces.
// This avoids a name conflict between the Windows SDK IDataObject
// type and System::Windows::Forms::IDataObject.

// Helper header used only to convert GUI String^ values to standard C++ strings.
#include <msclr/marshal_cppstd.h>

// Core project logic written using normal C++ classes.
#include "../Core/InsuranceSystem.h"

// Windows Forms namespaces are used only after the native headers are loaded.
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace InsurancePolicyManagementSystemGUI
{
    // MainForm is the graphical window shown to the user.
    public ref class MainForm : public Form
    {
    private:
        // Native C++ object that contains all project data and OOP logic.
        InsuranceSystem* system;

        // Main tab control used to separate the four required GUI features.
        TabControl^ tabs;

        // ---------------- POLICY HOLDER CONTROLS ----------------
        TextBox^ txtHolderID;
        TextBox^ txtName;
        TextBox^ txtNIC;
        TextBox^ txtPhone;
        TextBox^ txtAddress;
        TextBox^ txtAge;
        Label^ lblHolderResult;

        // ---------------- POLICY PLAN CONTROLS ----------------
        TextBox^ txtPlanHolderID;
        ComboBox^ cmbPlan;
        TextBox^ txtCoverage;
        Label^ lblPlanResult;

        // ---------------- PREMIUM CONTROLS ----------------
        TextBox^ txtPremiumHolderID;
        Label^ lblPremiumResult;

        // ---------------- CLAIM CONTROLS ----------------
        TextBox^ txtClaimID;
        TextBox^ txtClaimHolderID;
        TextBox^ txtClaimAmount;
        ComboBox^ cmbClaimStatus;
        Label^ lblClaimResult;

    public:
        // Constructor runs when the form is created.
        MainForm()
        {
            // Create the normal C++ InsuranceSystem object.
            system = new InsuranceSystem();

            // Build all GUI controls.
            InitializeComponent();
        }

        // Destructor releases the native C++ object when the form closes.
        ~MainForm()
        {
            if (system != nullptr)
            {
                delete system;
                system = nullptr;
            }
        }

    private:
        // Convert a Windows Forms String^ into a standard C++ std::string.
        std::string toStdString(String^ text)
        {
            return msclr::interop::marshal_as<std::string>(text);
        }

        // Convert a standard C++ std::string into a Windows Forms String^.
        String^ toManagedString(const std::string& text)
        {
            return gcnew String(text.c_str());
        }

        // Small helper used to create a label with less repeated code.
        Label^ makeLabel(String^ text, int x, int y)
        {
            Label^ label = gcnew Label();
            label->Text = text;
            label->Location = Point(x, y);
            label->AutoSize = true;
            return label;
        }

        // Small helper used to create a textbox with less repeated code.
        TextBox^ makeTextBox(int x, int y, int width)
        {
            TextBox^ box = gcnew TextBox();
            box->Location = Point(x, y);
            box->Width = width;
            return box;
        }

        // Small helper used to create a button and attach one click event.
        Button^ makeButton(String^ text, int x, int y, int width, EventHandler^ clickHandler)
        {
            Button^ button = gcnew Button();
            button->Text = text;
            button->Location = Point(x, y);
            button->Width = width;
            button->Height = 35;
            button->Click += clickHandler;
            return button;
        }

        // Create the complete window and the four functional tabs.
        void InitializeComponent()
        {
            // Basic main-window settings.
            this->Text = "Insurance Policy Management System";
            this->Size = Drawing::Size(760, 560);
            this->StartPosition = FormStartPosition::CenterScreen;
            this->FormBorderStyle = FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;

            // Main heading shown above the tabs.
            Label^ title = gcnew Label();
            title->Text = "INSURANCE POLICY MANAGEMENT SYSTEM";
            title->Font = gcnew Drawing::Font("Segoe UI", 18, FontStyle::Bold);
            title->AutoSize = true;
            title->Location = Point(110, 20);
            this->Controls->Add(title);

            // Create tab control.
            tabs = gcnew TabControl();
            tabs->Location = Point(20, 70);
            tabs->Size = Drawing::Size(700, 430);
            this->Controls->Add(tabs);

            // Create one tab for each main assigned feature.
            TabPage^ holderTab = gcnew TabPage("Policy Holder");
            TabPage^ planTab = gcnew TabPage("Policy Plan");
            TabPage^ premiumTab = gcnew TabPage("Premium");
            TabPage^ claimTab = gcnew TabPage("Claim Status");

            tabs->TabPages->Add(holderTab);
            tabs->TabPages->Add(planTab);
            tabs->TabPages->Add(premiumTab);
            tabs->TabPages->Add(claimTab);

            // Build controls inside each tab.
            buildHolderTab(holderTab);
            buildPlanTab(planTab);
            buildPremiumTab(premiumTab);
            buildClaimTab(claimTab);
        }

        // ---------------- POLICY HOLDER TAB ----------------
        void buildHolderTab(TabPage^ page)
        {
            page->Controls->Add(makeLabel("Holder ID", 30, 35));
            txtHolderID = makeTextBox(180, 30, 250);
            page->Controls->Add(txtHolderID);

            page->Controls->Add(makeLabel("Full Name", 30, 75));
            txtName = makeTextBox(180, 70, 250);
            page->Controls->Add(txtName);

            page->Controls->Add(makeLabel("NIC", 30, 115));
            txtNIC = makeTextBox(180, 110, 250);
            page->Controls->Add(txtNIC);

            page->Controls->Add(makeLabel("Phone", 30, 155));
            txtPhone = makeTextBox(180, 150, 250);
            page->Controls->Add(txtPhone);

            page->Controls->Add(makeLabel("Address", 30, 195));
            txtAddress = makeTextBox(180, 190, 250);
            page->Controls->Add(txtAddress);

            page->Controls->Add(makeLabel("Age", 30, 235));
            txtAge = makeTextBox(180, 230, 250);
            page->Controls->Add(txtAge);

            // Register button calls btnRegister_Click.
            page->Controls->Add(makeButton(
                "Register",
                180,
                285,
                120,
                gcnew EventHandler(this, &MainForm::btnRegister_Click)));

            // Search button calls btnSearchHolder_Click.
            page->Controls->Add(makeButton(
                "Search",
                310,
                285,
                120,
                gcnew EventHandler(this, &MainForm::btnSearchHolder_Click)));

            lblHolderResult = makeLabel("", 30, 345);
            lblHolderResult->ForeColor = Color::DarkBlue;
            page->Controls->Add(lblHolderResult);
        }

        // Register button event.
        void btnRegister_Click(Object^ sender, EventArgs^ e)
        {
            // age receives the number typed in the Age textbox.
            int age = 0;

            // Stop if age is not a valid integer.
            if (!Int32::TryParse(txtAge->Text, age))
            {
                lblHolderResult->Text = "Age must be a number.";
                return;
            }

            // message receives the success/error text from the C++ core class.
            std::string message;

            // Call the normal C++ function using textbox values.
            bool success = system->addPolicyHolder(
                toStdString(txtHolderID->Text),
                toStdString(txtName->Text),
                toStdString(txtNIC->Text),
                toStdString(txtPhone->Text),
                toStdString(txtAddress->Text),
                age,
                message);

            // Display the result returned by the core logic.
            lblHolderResult->Text = toManagedString(message);
            lblHolderResult->ForeColor = success ? Color::DarkGreen : Color::DarkRed;
        }

        // Search button event.
        void btnSearchHolder_Click(Object^ sender, EventArgs^ e)
        {
            // Create a temporary object to receive the searched holder record.
            PolicyHolder holder;

            // Search using Holder ID typed in the first textbox.
            if (system->getPolicyHolder(toStdString(txtHolderID->Text), holder))
            {
                // Fill the form using data returned by getter methods.
                txtName->Text = toManagedString(holder.getName());
                txtNIC->Text = toManagedString(holder.getNIC());
                txtPhone->Text = toManagedString(holder.getPhone());
                txtAddress->Text = toManagedString(holder.getAddress());
                txtAge->Text = Convert::ToString(holder.getAge());

                lblHolderResult->Text = "Policy holder found.";
                lblHolderResult->ForeColor = Color::DarkGreen;
            }
            else
            {
                lblHolderResult->Text = "Policy holder not found.";
                lblHolderResult->ForeColor = Color::DarkRed;
            }
        }

        // ---------------- POLICY PLAN TAB ----------------
        void buildPlanTab(TabPage^ page)
        {
            page->Controls->Add(makeLabel("Holder ID", 30, 50));
            txtPlanHolderID = makeTextBox(190, 45, 260);
            page->Controls->Add(txtPlanHolderID);

            page->Controls->Add(makeLabel("Plan", 30, 100));
            cmbPlan = gcnew ComboBox();
            cmbPlan->Location = Point(190, 95);
            cmbPlan->Width = 260;
            cmbPlan->DropDownStyle = ComboBoxStyle::DropDownList;
            cmbPlan->Items->Add("Life Insurance");
            cmbPlan->Items->Add("Health Insurance");
            cmbPlan->Items->Add("Vehicle Insurance");
            page->Controls->Add(cmbPlan);

            page->Controls->Add(makeLabel("Coverage Amount (Rs.)", 30, 150));
            txtCoverage = makeTextBox(190, 145, 260);
            page->Controls->Add(txtCoverage);

            page->Controls->Add(makeButton(
                "Select Plan",
                190,
                205,
                130,
                gcnew EventHandler(this, &MainForm::btnSelectPlan_Click)));

            lblPlanResult = makeLabel("", 30, 270);
            lblPlanResult->ForeColor = Color::DarkBlue;
            page->Controls->Add(lblPlanResult);
        }

        // Select Plan button event.
        void btnSelectPlan_Click(Object^ sender, EventArgs^ e)
        {
            double coverageAmount = 0.0;

            // Check that a plan has been selected in the combo box.
            if (cmbPlan->SelectedIndex == -1)
            {
                lblPlanResult->Text = "Please select a policy plan.";
                lblPlanResult->ForeColor = Color::DarkRed;
                return;
            }

            // Convert coverage textbox into a number.
            if (!Double::TryParse(txtCoverage->Text, coverageAmount))
            {
                lblPlanResult->Text = "Coverage amount must be a number.";
                lblPlanResult->ForeColor = Color::DarkRed;
                return;
            }

            std::string message;

            // Call the C++ core function.
            bool success = system->selectPolicyPlan(
                toStdString(txtPlanHolderID->Text),
                toStdString(cmbPlan->SelectedItem->ToString()),
                coverageAmount,
                message);

            lblPlanResult->Text = toManagedString(message);
            lblPlanResult->ForeColor = success ? Color::DarkGreen : Color::DarkRed;
        }

        // ---------------- PREMIUM TAB ----------------
        void buildPremiumTab(TabPage^ page)
        {
            page->Controls->Add(makeLabel("Holder ID", 30, 70));
            txtPremiumHolderID = makeTextBox(180, 65, 250);
            page->Controls->Add(txtPremiumHolderID);

            page->Controls->Add(makeButton(
                "Calculate Premium",
                180,
                125,
                170,
                gcnew EventHandler(this, &MainForm::btnCalculatePremium_Click)));

            lblPremiumResult = makeLabel("", 30, 205);
            lblPremiumResult->Font = gcnew Drawing::Font("Segoe UI", 12, FontStyle::Bold);
            page->Controls->Add(lblPremiumResult);
        }

        // Calculate Premium button event.
        void btnCalculatePremium_Click(Object^ sender, EventArgs^ e)
        {
            double premium = 0.0;
            std::string message;

            // Ask the C++ core class to calculate the premium.
            bool success = system->calculatePremium(
                toStdString(txtPremiumHolderID->Text),
                premium,
                message);

            if (success)
            {
                lblPremiumResult->Text = "Total Premium: Rs. " + String::Format("{0:F2}", premium);
                lblPremiumResult->ForeColor = Color::DarkGreen;
            }
            else
            {
                lblPremiumResult->Text = toManagedString(message);
                lblPremiumResult->ForeColor = Color::DarkRed;
            }
        }

        // ---------------- CLAIM TAB ----------------
        void buildClaimTab(TabPage^ page)
        {
            page->Controls->Add(makeLabel("Claim ID", 30, 35));
            txtClaimID = makeTextBox(190, 30, 250);
            page->Controls->Add(txtClaimID);

            page->Controls->Add(makeLabel("Holder ID", 30, 80));
            txtClaimHolderID = makeTextBox(190, 75, 250);
            page->Controls->Add(txtClaimHolderID);

            page->Controls->Add(makeLabel("Claim Amount (Rs.)", 30, 125));
            txtClaimAmount = makeTextBox(190, 120, 250);
            page->Controls->Add(txtClaimAmount);

            page->Controls->Add(makeLabel("Status", 30, 170));
            cmbClaimStatus = gcnew ComboBox();
            cmbClaimStatus->Location = Point(190, 165);
            cmbClaimStatus->Width = 250;
            cmbClaimStatus->DropDownStyle = ComboBoxStyle::DropDownList;
            cmbClaimStatus->Items->Add("Pending");
            cmbClaimStatus->Items->Add("Under Review");
            cmbClaimStatus->Items->Add("Approved");
            cmbClaimStatus->Items->Add("Rejected");
            page->Controls->Add(cmbClaimStatus);

            page->Controls->Add(makeButton(
                "Submit Claim",
                80,
                230,
                130,
                gcnew EventHandler(this, &MainForm::btnSubmitClaim_Click)));

            page->Controls->Add(makeButton(
                "Search Claim",
                225,
                230,
                130,
                gcnew EventHandler(this, &MainForm::btnSearchClaim_Click)));

            page->Controls->Add(makeButton(
                "Update Status",
                370,
                230,
                130,
                gcnew EventHandler(this, &MainForm::btnUpdateClaim_Click)));

            lblClaimResult = makeLabel("", 30, 300);
            lblClaimResult->ForeColor = Color::DarkBlue;
            page->Controls->Add(lblClaimResult);
        }

        // Submit Claim button event.
        void btnSubmitClaim_Click(Object^ sender, EventArgs^ e)
        {
            double claimAmount = 0.0;

            if (!Double::TryParse(txtClaimAmount->Text, claimAmount))
            {
                lblClaimResult->Text = "Claim amount must be a number.";
                lblClaimResult->ForeColor = Color::DarkRed;
                return;
            }

            std::string message;

            bool success = system->createClaim(
                toStdString(txtClaimID->Text),
                toStdString(txtClaimHolderID->Text),
                claimAmount,
                message);

            lblClaimResult->Text = toManagedString(message);
            lblClaimResult->ForeColor = success ? Color::DarkGreen : Color::DarkRed;
        }

        // Search Claim button event.
        void btnSearchClaim_Click(Object^ sender, EventArgs^ e)
        {
            Claim claim;

            if (system->getClaim(toStdString(txtClaimID->Text), claim))
            {
                txtClaimHolderID->Text = toManagedString(claim.getHolderID());
                txtClaimAmount->Text = String::Format("{0:F2}", claim.getClaimAmount());
                cmbClaimStatus->SelectedItem = toManagedString(claim.getStatus());

                lblClaimResult->Text = "Claim found.";
                lblClaimResult->ForeColor = Color::DarkGreen;
            }
            else
            {
                lblClaimResult->Text = "Claim not found.";
                lblClaimResult->ForeColor = Color::DarkRed;
            }
        }

        // Update Claim Status button event.
        void btnUpdateClaim_Click(Object^ sender, EventArgs^ e)
        {
            if (cmbClaimStatus->SelectedIndex == -1)
            {
                lblClaimResult->Text = "Please select a claim status.";
                lblClaimResult->ForeColor = Color::DarkRed;
                return;
            }

            std::string message;

            bool success = system->updateClaimStatus(
                toStdString(txtClaimID->Text),
                toStdString(cmbClaimStatus->SelectedItem->ToString()),
                message);

            lblClaimResult->Text = toManagedString(message);
            lblClaimResult->ForeColor = success ? Color::DarkGreen : Color::DarkRed;
        }
    };
}
