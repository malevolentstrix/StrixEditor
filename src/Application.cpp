#include "Application.h"
#include "StrixEditor.h"
wxRichTextPrinting* Application::GetPrinting() const {
	return m_printing;
}
bool Application::OnInit() {

	wxSize size = wxGetDisplaySize();
	size.Scale(0.50, 0.75);
	StrixEditor* strixeditor = new StrixEditor("StrixEditor", size);
	strixeditor->Show(true);
	return true;
}