#include "EntryMoney.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    SlotMachine::EntryMoney form;
    Application::Run(% form);
}
