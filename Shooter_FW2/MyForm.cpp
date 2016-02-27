#include "MyForm.h"


using namespace std;
using namespace System;
using namespace System::Windows::Forms;
[STAThread]


int main(array<String^>^ args){
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	//try{
		Shooter_FW2::MyForm form;
		Application::Run(%form);
	//}
	//catch (Exception error_glupi){

	//}
	
	


}