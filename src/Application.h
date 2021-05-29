#pragma once
#include <wx/wx.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/richtext/richtextbuffer.h>
#include <wx/richtext/richtextprint.h>

class Application : public wxApp {
public:
	virtual bool OnInit();
#if wxUSE_PRINTING_ARCHITECTURE
	wxRichTextPrinting* m_printing;
	wxRichTextPrinting* GetPrinting() const;

#endif
};