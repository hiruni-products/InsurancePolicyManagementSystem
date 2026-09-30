#include <iostream>
#include <iomanip>
#include <limits>

#include "../Core/InsuranceSystem.h"

using namespace std;

// This console program is only for testing the same core logic used by the GUI.
// It is useful when the GUI is not yet available.
int main()
{
    // Create one InsuranceSystem object.
    InsuranceSystem system;

    // choice stores the user's main-menu selection.
    int choice = 0;

    // Keep showing the menu until the user selects Exit.
    do
    {
        cout << "\n==========================================" << endl;
        cout << "    INSURANCE POLICY MANAGEMENT SYSTEM" << endl;
        cout << "==========================================" << endl;
        cout << "1. Register Policy Holder" << endl;
        cout << "2. Search Policy Holder" << endl;
        cout << "3. Select Policy Plan" << endl;
        cout << "4. Calculate Premium" << endl;
        cout << "5. Submit Claim" << endl;
        cout << "6. View Claim" << endl;
        cout << "7. Update Claim Status" << endl;
        cout << "8. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        // Option 1: Register a new policy holder.
        if (choice == 1)
        {
            string holderID;
            string name;
            string nic;
            string phone;
            string address;
            int age;
            string message;

            // Remove the newline left by the previous cin operation.
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "\nHolder ID : ";
            getline(cin, holderID);

            cout << "Name      : ";
            getline(cin, name);

            cout << "NIC       : ";
            getline(cin, nic);

            cout << "Phone     : ";
            getline(cin, phone);

            cout << "Address   : ";
            getline(cin, address);

            cout << "Age       : ";
            cin >> age;

            bool success = system.addPolicyHolder(holderID, name, nic, phone, address, age, message);

            cout << "\n" << message << endl;
        }

        // Option 2: Search and display a policy holder.
        else if (choice == 2)
        {
            string holderID;
            PolicyHolder holder;

            cout << "\nEnter Holder ID: ";
            cin >> holderID;

            if (system.getPolicyHolder(holderID, holder))
            {
                cout << "\nName            : " << holder.getName() << endl;
                cout << "NIC             : " << holder.getNIC() << endl;
                cout << "Phone           : " << holder.getPhone() << endl;
                cout << "Address         : " << holder.getAddress() << endl;
                cout << "Age             : " << holder.getAge() << endl;
                cout << "Selected Plan   : " << (holder.hasPlan() ? holder.getSelectedPlan() : "Not Selected") << endl;
            }
            else
            {
                cout << "\nPolicy holder not found." << endl;
            }
        }

        // Option 3: Select a policy plan for a holder.
        else if (choice == 3)
        {
            string holderID;
            int planChoice;
            string planName;
            double coverageAmount;
            string message;

            cout << "\nEnter Holder ID: ";
            cin >> holderID;

            cout << "\n1. Life Insurance" << endl;
            cout << "2. Health Insurance" << endl;
            cout << "3. Vehicle Insurance" << endl;
            cout << "Select Plan: ";
            cin >> planChoice;

            if (planChoice == 1)
            {
                planName = "Life Insurance";
            }
            else if (planChoice == 2)
            {
                planName = "Health Insurance";
            }
            else if (planChoice == 3)
            {
                planName = "Vehicle Insurance";
            }
            else
            {
                planName = "";
            }

            cout << "Coverage Amount (Rs.): ";
            cin >> coverageAmount;

            bool success = system.selectPolicyPlan(holderID, planName, coverageAmount, message);

            cout << "\n" << message << endl;
        }

        // Option 4: Calculate the premium for a holder.
        else if (choice == 4)
        {
            string holderID;
            double premium = 0.0;
            string message;

            cout << "\nEnter Holder ID: ";
            cin >> holderID;

            if (system.calculatePremium(holderID, premium, message))
            {
                cout << fixed << setprecision(2);
                cout << "\nTotal Premium: Rs. " << premium << endl;
            }
            else
            {
                cout << "\n" << message << endl;
            }
        }

        // Option 5: Submit a new claim.
        else if (choice == 5)
        {
            string claimID;
            string holderID;
            double claimAmount;
            string message;

            cout << "\nClaim ID     : ";
            cin >> claimID;

            cout << "Holder ID    : ";
            cin >> holderID;

            cout << "Claim Amount : Rs. ";
            cin >> claimAmount;

            bool success = system.createClaim(claimID, holderID, claimAmount, message);

            cout << "\n" << message << endl;
        }

        // Option 6: Search and display one claim.
        else if (choice == 6)
        {
            string claimID;
            Claim claim;

            cout << "\nEnter Claim ID: ";
            cin >> claimID;

            if (system.getClaim(claimID, claim))
            {
                cout << fixed << setprecision(2);
                cout << "\nHolder ID    : " << claim.getHolderID() << endl;
                cout << "Claim Amount : Rs. " << claim.getClaimAmount() << endl;
                cout << "Status       : " << claim.getStatus() << endl;
            }
            else
            {
                cout << "\nClaim not found." << endl;
            }
        }

        // Option 7: Update the status of an existing claim.
        else if (choice == 7)
        {
            string claimID;
            int statusChoice;
            string newStatus;
            string message;

            cout << "\nEnter Claim ID: ";
            cin >> claimID;

            cout << "1. Pending" << endl;
            cout << "2. Under Review" << endl;
            cout << "3. Approved" << endl;
            cout << "4. Rejected" << endl;
            cout << "Select Status: ";
            cin >> statusChoice;

            if (statusChoice == 1)
            {
                newStatus = "Pending";
            }
            else if (statusChoice == 2)
            {
                newStatus = "Under Review";
            }
            else if (statusChoice == 3)
            {
                newStatus = "Approved";
            }
            else if (statusChoice == 4)
            {
                newStatus = "Rejected";
            }
            else
            {
                newStatus = "";
            }

            bool success = system.updateClaimStatus(claimID, newStatus, message);

            cout << "\n" << message << endl;
        }

        // Option 8: Exit the program.
        else if (choice == 8)
        {
            cout << "\nProgram closed successfully." << endl;
        }

        // Any other number is invalid.
        else
        {
            cout << "\nInvalid choice. Please try again." << endl;
        }

    } while (choice != 8);

    return 0;
}
