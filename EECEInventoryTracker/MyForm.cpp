#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace EECEInventoryTracker;
using namespace std;
[STAThread]

int main() {

	Application::Run(gcnew MyForm);
	return 0;
}