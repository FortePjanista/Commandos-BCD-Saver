#ifndef PICKINGNAMEFRAME_H
#define PICKINGNAMEFRAME_H

#include "wx/wx.h"
#include "savesHandler.h"

class PickingNameFrame : public wxFrame
{
public:
	PickingNameFrame(wxWindow * parent);

private:
	std::string defaultName;
	wxTextCtrl * editBox;
	wxButton * btn_OK;
	SavesHandler * sh;
	int lastSelectedBtn;

public:
	void setLastSelectedBtn(int lastSelectedBtn);
	void setSavesHandler(SavesHandler * sh);
	void setDefaultName(std::string defaultName);
	void OnOKButtonClicked(wxCommandEvent &evt);
	void OnClose(wxCloseEvent &evt);
};

#endif //PICKINGNAMEFRAME_H