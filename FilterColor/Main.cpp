
#include "FilterColorForm.h"

using namespace System;
using namespace System::Diagnostics;
using namespace System::Windows::Forms;
using namespace std;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Runtime::InteropServices;
using namespace System::IO;

[STAThreadAttribute]
void Main(cli::array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	TGMT::FilterColorForm form;
	Application::Run(%form);
}