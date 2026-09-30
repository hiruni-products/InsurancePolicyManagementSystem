// MainForm contains the Windows Forms GUI.
#include "MainForm.h"

// Use the .NET namespaces needed to start a Windows Forms application.
using namespace System;
using namespace System::Windows::Forms;
using namespace InsurancePolicyManagementSystemGUI;

// STAThreadAttribute is required by Windows Forms.
[STAThreadAttribute]
int main(array<String^>^ args)
{
    // Turn on standard Windows visual styles.
    Application::EnableVisualStyles();

    // Use the normal Windows Forms text rendering behavior.
    Application::SetCompatibleTextRenderingDefault(false);

    // Create and run the MainForm window.
    Application::Run(gcnew MainForm());

    // Return zero when the application closes normally.
    return 0;
}
