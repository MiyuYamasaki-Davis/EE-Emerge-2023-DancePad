#include "Board.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main(array<String^>^ argv)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	EEE::Board board;
	Application::Run(% board);
}