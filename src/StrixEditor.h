#pragma once
#include "wx/wx.h"
#include "wx/richtext/richtextctrl.h"
#include <wx/richtext/richtextbuffer.h>
// Menu Items
enum {
	ID_Quit = wxID_EXIT,
	ID_Open = wxID_OPEN,
	ID_Save = wxID_SAVE,
};

class StrixEditor : public wxFrame {
public:
	StrixEditor(const wxString& title, const wxSize& size);

// Window Menubar
	wxMenuBar* menubar;
	wxMenu* file;

	// Event Handlers
	void OnQuit(wxCommandEvent& event);
	void OnOpen(wxCommandEvent& event);
	void OnSave(wxCommandEvent& event);
	void OnSaveAs(wxCommandEvent& event);
private:
	DECLARE_EVENT_TABLE()
	wxRichTextCtrl* m_richTextCtrl;

};


