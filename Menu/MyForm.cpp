#include "MyForm.h"
using namespace Menu;
void mani() {

	srand(time(NULL));

	MyForm^ form = gcnew MyForm();
	Application::Run(form);
	Application::Exit();
}
