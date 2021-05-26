#include "Application.h"
#include "StrixEditor.h"

bool Application::OnInit() {

	wxSize size = wxGetDisplaySize();
	size.Scale(0.50, 0.75);
	StrixEditor* strixeditor = new StrixEditor("StrixEditor", size);
	strixeditor->Show(true);
	return true;
}