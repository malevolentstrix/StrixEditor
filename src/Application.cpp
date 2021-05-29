#include "Application.h"
#include "StrixEditor.h"
#if wxUSE_PRINTING_ARCHITECTURE
wxRichTextPrinting* Application::GetPrinting() const {
	return m_printing;
}

#endif
bool Application::OnInit() {

	wxSize size = wxGetDisplaySize();
	size.Scale(0.50, 0.75);
	StrixEditor* strixeditor = new StrixEditor("StrixEditor", size);

#if wxUSE_PRINTING_ARCHITECTURE
	m_printing = new wxRichTextPrinting();
	m_printing->SetFooterText("Page @PAGENUM@", wxRICHTEXT_PAGE_ALL, wxRICHTEXT_PAGE_RIGHT);

	// Set parent window to allow print preview windows aware of its parent.
	m_printing->SetParentWindow(strixeditor);
#endif
	strixeditor->Show(true);
	return true;
}