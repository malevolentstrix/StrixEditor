#pragma once
#include <wx/wx.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/richtext/richtextbuffer.h>
#include <wx/richtext/richtextprint.h>

class Application : public wxApp {
public:
	virtual bool OnInit();
		wxRichTextPrinting* GetPrinting() const;
};