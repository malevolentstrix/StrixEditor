#include "StrixEditor.h"
#include "Application.h"
// Event Table
wxBEGIN_EVENT_TABLE(StrixEditor, wxFrame)
	EVT_MENU(ID_Quit, StrixEditor::OnQuit)
	EVT_MENU(ID_Open, StrixEditor::OnOpen)
	EVT_MENU(ID_Save, StrixEditor::OnSave)
	EVT_MENU(ID_About, StrixEditor::OnAbout)
	#if wxUSE_PRINTING_ARCHITECTURE
	EVT_MENU(ID_AsPDF, StrixEditor::OnAsPDF)
	#endif
wxEND_EVENT_TABLE()

// Initialize Application
wxIMPLEMENT_APP(Application);

StrixEditor::StrixEditor(const wxString& title, const wxSize& size)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, size) {
	menubar = new wxMenuBar;

	// File menu option
	file = new wxMenu;
	help = new wxMenu;
	exportto = new wxMenu;

	// Menu Items
	file->Append(ID_Open, "&Open\tCtrl+O", "Open a file");
	file->Append(ID_Save, "&Save\tCtrl+S", "Save a file");
	file->Append(ID_Quit, "&Quit\tCtrl+Q", "Quit StrixEditor");
	help->Append(ID_About, "&About\tCtrl+A", "About Us");
	exportto->Append(ID_AsPDF, "&Export as PDF, SVG or PostScript", "Get a file");

	// Add Menubar Items
	menubar->Append(file, "&File");
	menubar->Append(help, "&Help");
	menubar->Append(exportto, "&Export");

	// Attach the menu bar to the frame
	SetMenuBar(menubar);

	// Initialize the RichTextCtrl
	m_richTextCtrl = new wxRichTextCtrl(this);

}
// Quit Button
void StrixEditor::OnQuit(wxCommandEvent& WXUNUSED(event)) { Close(true); }

// Open File Box
void StrixEditor::OnOpen(wxCommandEvent& WXUNUSED(event)) {
	wxString filePath;
	wxString fileName;
	wxArrayInt fileTypes;

	wxString filter = wxRichTextBuffer::GetExtWildcard(false, false, &fileTypes);
	if (!filter.empty()) {
		filter += "|";
	}
	filter += "All files (*.*)|*.*";

	wxFileDialog dialog(this, _("Choose a filename"), filePath, fileName, filter, wxFD_OPEN);

	if (dialog.ShowModal() == wxID_OK) {
		wxString path = dialog.GetPath();
		if (!path.empty()) {
			int filterIndex = dialog.GetFilterIndex();
			int fileType = (filterIndex < (int)fileTypes.GetCount())
				? fileTypes[filterIndex] : wxRICHTEXT_TYPE_TEXT;
			m_richTextCtrl->LoadFile(path, fileType);
		}
	}
}

// Save File Dialog
void StrixEditor::OnSave(wxCommandEvent& WXUNUSED(event)) {
	wxString filter = wxRichTextBuffer::GetExtWildcard(false, true);
	wxString filePath;
	wxString fileName;

	wxFileDialog dialog(this, _("Enter a filename"), filePath, fileName, filter, wxFD_SAVE);

	if (dialog.ShowModal() == wxID_OK) {
		wxString path = dialog.GetPath();

		if (!path.empty()) {
			m_richTextCtrl->SaveFile(path);
		}
	}
}
//About Nox
void StrixEditor::OnAbout(wxCommandEvent& WXUNUSED(event)) {
	wxString msg;
	msg.Printf("StrixEditor was made for an Understanding the basic concepts of WxWidgets. \nBy Jithin John");
	wxMessageBox(msg, "About StrixEditor Text Editor", wxOK | wxICON_INFORMATION);
}
#if wxUSE_PRINTING_ARCHITECTURE
// Exporting as PDF
void StrixEditor::OnAsPDF(wxCommandEvent& WXUNUSED(event)) {
	wxGetApp().GetPrinting()->PrintBuffer(m_richTextCtrl->GetBuffer());
}
#endif