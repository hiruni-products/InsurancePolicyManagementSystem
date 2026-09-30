#pragma once

// IMPORTANT:
// Native C++ headers are included BEFORE Windows Forms namespaces.
// This avoids a name conflict between the Windows SDK IDataObject
// type and System::Windows::Forms::IDataObject.

#include <msclr/marshal_cppstd.h>
#include "../Core/InsuranceSystem.h"

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

        TabControl^ tabs;

        // ---------------- CUSTOMER REGISTRATION CONTROLS ----------------
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

        // ---------------- CUSTOMER CLAIM CONTROLS ----------------
        TextBox^ txtClaimID;
        TextBox^ txtClaimHolderID;
        TextBox^ txtClaimAmount;
        Label^ lblCustomerClaimStatus;
        Label^ lblClaimResult;

        // ---------------- ADMIN CLAIM CONTROLS ----------------
        TextBox^ txtAdminClaimID;
        ComboBox^ cmbAdminClaimStatus;
        Label^ lblAdminClaimDetails;
        Label^ lblAdminClaimResult;

    public:
        MainForm()
        {
            system = new InsuranceSystem();
            InitializeComponent();
        }

        ~MainForm()
        {
            if (system != nullptr)
            {
                delete system;
                system = nullptr;
            }
        }

    private:
        std::string toStdString(String^ text)
        {
            return msclr::interop::marshal_as<std::string>(text);
        }

        String^ toManagedString(const std::string& text)
        {
            return gcnew String(text.c_str());
        }

        Label^ makeLabel(String^ text, int x, int y)
        {
            Label^ label = gcnew Label();
            label->Text = text;
            label->Location = Point(x, y);
            label->AutoSize = true;
            return label;
        }

        TextBox^ makeTextBox(int x, int y, int width)
        {
            TextBox^ box = gcnew TextBox();
            box->Location = Point(x, y);
            box->Width = width;
            return box;
        }

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

        // Build the main window.
        // Customer claim actions and admin claim actions are kept in separate tabs.
        void InitializeComponent()
        {
            this->Text = "Insurance Policy Management System";
            this->Size = Drawing::Size(820, 580);
            this->StartPosition = FormStartPosition::CenterScreen;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;

            Label^ title = gcnew Label();
            title->Text = "INSURANCE POLICY MANAGEMENT SYSTEM";
            title->Font = gcnew Drawing::Font("Segoe UI", 18, FontStyle::Bold);
            title->AutoSize = true;
            title->Location = Point(135, 20);
            this->Controls->Add(title);

            tabs = gcnew TabControl();
            tabs->Location = Point(20, 70);
            tabs->Size = Drawing::Size(760, 450);
            this->Controls->Add(tabs);

            TabPage^ holderTab = gcnew TabPage("Customer Registration");
            TabPage^ planTab = gcnew TabPage("Policy Plan");
            TabPage^ premiumTab = gcnew TabPage("Premium");
            TabPage^ customerClaimTab = gcnew TabPage("Customer Claim");
            TabPage^ adminClaimTab = gcnew TabPage("Admin Claim Review");

            tabs->TabPages->Add(holderTab);
            tabs->TabPages->Add(planTab);
            tabs->TabPages->Add(premiumTab);
            tabs->TabPages->Add(customerClaimTab);
            tabs->TabPages->Add(adminClaimTab);

            buildHolderTab(holderTab);
            buildPlanTab(planTab);
            buildPremiumTab(premiumTab);
            buildCustomerClaimTab(customerClaimTab);
            buildAdminClaimTab(adminClaimTab);
        }

        // ---------------- CUSTOMER REGISTRATION TAB ----------------
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

            page->Controls->Add(makeButton(
                "Register",
                180,
                285,
                120,
                gcnew EventHandler(this, &MainForm::btnRegister_Click)));

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

        void btnRegister_Click(Object^ sender, EventArgs^ e)
        {
            int age = 0;

            if (!Int32::TryParse(txtAge->Text, age))
            {
                lblHolderResult->Text = "Age must be a number.";
                lblHolderResult->ForeColor = Color::DarkRed;
                return;
            }

            std::string message;

            bool success = system->addPolicyHolder(
                toStdString(txtHolderID->Text),
                toStdString(txtName->Text),
                toStdString(txtNIC->Text),
                toStdString(txtPhone->Text),
                toStdString(txtAddress->Text),
                age,
                message);

            lblHolderResult->Text = toManagedString(message);
            lblHolderResult->ForeColor = success ? Color::DarkGreen : Color::DarkRed;
        }

        void btnSearchHolder_Click(Object^ sender, EventArgs^ e)
        {
            PolicyHolder holder;

            if (system->getPolicyHolder(toStdString(txtHolderID->Text), holder))
            {
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

        void btnSelectPlan_Click(Object^ sender, EventArgs^ e)
        {
            double coverageAmount = 0.0;

            if (cmbPlan->SelectedIndex == -1)
            {
                lblPlanResult->Text = "Please select a policy plan.";
                lblPlanResult->ForeColor = Color::DarkRed;
                return;
            }

            if (!Double::TryParse(txtCoverage->Text, coverageAmount))
            {
                lblPlanResult->Text = "Coverage amount must be a number.";
                lblPlanResult->ForeColor = Color::DarkRed;
                return;
            }

            std::string message;

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

        void btnCalculatePremium_Click(Object^ sender, EventArgs^ e)
        {
            double premium = 0.0;
            std::string message;

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

        // ---------------- CUSTOMER CLAIM TAB ----------------
        // Customer can submit a claim and view its status.
        // Customer cannot change the claim status.
        void buildCustomerClaimTab(TabPage^ page)
        {
            Label^ roleInfo = makeLabel(
                "CUSTOMER: Submit a claim or search to view its current status.",
                30,
                20);
            roleInfo->Font = gcnew Drawing::Font("Segoe UI", 10, FontStyle::Bold);
            roleInfo->ForeColor = Color::DarkBlue;
            page->Controls->Add(roleInfo);

            page->Controls->Add(makeLabel("Claim ID", 30, 70));
            txtClaimID = makeTextBox(190, 65, 250);
            page->Controls->Add(txtClaimID);

            page->Controls->Add(makeLabel("Holder ID", 30, 115));
            txtClaimHolderID = makeTextBox(190, 110, 250);
            page->Controls->Add(txtClaimHolderID);

            page->Controls->Add(makeLabel("Claim Amount (Rs.)", 30, 160));
            txtClaimAmount = makeTextBox(190, 155, 250);
            page->Controls->Add(txtClaimAmount);

            page->Controls->Add(makeButton(
                "Submit Claim",
                190,
                215,
                125,
                gcnew EventHandler(this, &MainForm::btnSubmitClaim_Click)));

            page->Controls->Add(makeButton(
                "Search Claim",
                325,
                215,
                125,
                gcnew EventHandler(this, &MainForm::btnSearchClaim_Click)));

            page->Controls->Add(makeLabel("Current Status:", 30, 285));
            lblCustomerClaimStatus = makeLabel("-", 190, 285);
            lblCustomerClaimStatus->Font = gcnew Drawing::Font("Segoe UI", 11, FontStyle::Bold);
            lblCustomerClaimStatus->ForeColor = Color::DarkBlue;
            page->Controls->Add(lblCustomerClaimStatus);

            lblClaimResult = makeLabel("", 30, 335);
            lblClaimResult->ForeColor = Color::DarkBlue;
            page->Controls->Add(lblClaimResult);
        }

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

            if (success)
            {
                lblCustomerClaimStatus->Text = "Pending";
            }
        }

        void btnSearchClaim_Click(Object^ sender, EventArgs^ e)
        {
            Claim claim;

            if (system->getClaim(toStdString(txtClaimID->Text), claim))
            {
                txtClaimHolderID->Text = toManagedString(claim.getHolderID());
                txtClaimAmount->Text = String::Format("{0:F2}", claim.getClaimAmount());
                lblCustomerClaimStatus->Text = toManagedString(claim.getStatus());

                lblClaimResult->Text = "Claim found.";
                lblClaimResult->ForeColor = Color::DarkGreen;
            }
            else
            {
                lblCustomerClaimStatus->Text = "-";
                lblClaimResult->Text = "Claim not found.";
                lblClaimResult->ForeColor = Color::DarkRed;
            }
        }

        // ---------------- ADMIN CLAIM REVIEW TAB ----------------
        // Only this admin section can change a claim status.
        void buildAdminClaimTab(TabPage^ page)
        {
            Label^ roleInfo = makeLabel(
                "ADMIN / STAFF: Search a claim, review it, then update its status.",
                30,
                20);
            roleInfo->Font = gcnew Drawing::Font("Segoe UI", 10, FontStyle::Bold);
            roleInfo->ForeColor = Color::DarkRed;
            page->Controls->Add(roleInfo);

            page->Controls->Add(makeLabel("Claim ID", 30, 75));
            txtAdminClaimID = makeTextBox(190, 70, 250);
            page->Controls->Add(txtAdminClaimID);

            page->Controls->Add(makeButton(
                "Search Claim",
                460,
                68,
                130,
                gcnew EventHandler(this, &MainForm::btnSearchAdminClaim_Click)));

            lblAdminClaimDetails = makeLabel(
                "Holder ID: -\r\nClaim Amount: -\r\nCurrent Status: -",
                30,
                135);
            lblAdminClaimDetails->Font = gcnew Drawing::Font("Segoe UI", 10);
            page->Controls->Add(lblAdminClaimDetails);

            page->Controls->Add(makeLabel("New Status", 30, 235));
            cmbAdminClaimStatus = gcnew ComboBox();
            cmbAdminClaimStatus->Location = Point(190, 230);
            cmbAdminClaimStatus->Width = 250;
            cmbAdminClaimStatus->DropDownStyle = ComboBoxStyle::DropDownList;
            cmbAdminClaimStatus->Items->Add("Pending");
            cmbAdminClaimStatus->Items->Add("Under Review");
            cmbAdminClaimStatus->Items->Add("Approved");
            cmbAdminClaimStatus->Items->Add("Rejected");
            page->Controls->Add(cmbAdminClaimStatus);

            page->Controls->Add(makeButton(
                "Update Status",
                190,
                290,
                140,
                gcnew EventHandler(this, &MainForm::btnUpdateClaim_Click)));

            lblAdminClaimResult = makeLabel("", 30, 350);
            lblAdminClaimResult->ForeColor = Color::DarkBlue;
            page->Controls->Add(lblAdminClaimResult);
        }

        void btnSearchAdminClaim_Click(Object^ sender, EventArgs^ e)
        {
            Claim claim;

            if (system->getClaim(toStdString(txtAdminClaimID->Text), claim))
            {
                lblAdminClaimDetails->Text =
                    "Holder ID: " + toManagedString(claim.getHolderID()) +
                    "\r\nClaim Amount: Rs. " + String::Format("{0:F2}", claim.getClaimAmount()) +
                    "\r\nCurrent Status: " + toManagedString(claim.getStatus());

                cmbAdminClaimStatus->SelectedItem = toManagedString(claim.getStatus());
                lblAdminClaimResult->Text = "Claim found. Select a new status if required.";
                lblAdminClaimResult->ForeColor = Color::DarkGreen;
            }
            else
            {
                lblAdminClaimDetails->Text = "Holder ID: -\r\nClaim Amount: -\r\nCurrent Status: -";
                cmbAdminClaimStatus->SelectedIndex = -1;
                lblAdminClaimResult->Text = "Claim not found.";
                lblAdminClaimResult->ForeColor = Color::DarkRed;
            }
        }

        void btnUpdateClaim_Click(Object^ sender, EventArgs^ e)
        {
            if (cmbAdminClaimStatus->SelectedIndex == -1)
            {
                lblAdminClaimResult->Text = "Please select a claim status.";
                lblAdminClaimResult->ForeColor = Color::DarkRed;
                return;
            }

            std::string message;

            bool success = system->updateClaimStatus(
                toStdString(txtAdminClaimID->Text),
                toStdString(cmbAdminClaimStatus->SelectedItem->ToString()),
                message);

            lblAdminClaimResult->Text = toManagedString(message);
            lblAdminClaimResult->ForeColor = success ? Color::DarkGreen : Color::DarkRed;

            if (success)
            {
                Claim claim;
                if (system->getClaim(toStdString(txtAdminClaimID->Text), claim))
                {
                    lblAdminClaimDetails->Text =
                        "Holder ID: " + toManagedString(claim.getHolderID()) +
                        "\r\nClaim Amount: Rs. " + String::Format("{0:F2}", claim.getClaimAmount()) +
                        "\r\nCurrent Status: " + toManagedString(claim.getStatus());
                }
            }
        }
    };
}
