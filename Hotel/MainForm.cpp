#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Hotel::MainForm form;
	Application::Run(% form);
	return 0;
}