#ifndef PICKINGNAMEFRAME_H
#define PICKINGNAMEFRAME_H

#include "wx/wx.h"
#include "savesHandler.h"

class PickingNameFrame : public wxFrame
{
public:
	PickingNameFrame(wxWindow * parent, std::shared_ptr<SavesHandler> sh);

private:
	std::string defaultName;
	std::unique_ptr<wxTextCtrl> editBox;
	std::unique_ptr<wxButton> btn_OK;
	std::shared_ptr<SavesHandler> sh;
	int lastSelectedBtn;

public:
	void setLastSelectedBtn(int lastSelectedBtn);
	void setDefaultName(const std::string &defaultName);
	void OnOKButtonClicked(wxCommandEvent &evt);
	void OnClose(wxCloseEvent &evt);
};

#endif //PICKINGNAMEFRAME_H