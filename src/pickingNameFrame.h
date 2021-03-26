#ifndef PICKINGNAMEFRAME_H
#define PICKINGNAMEFRAME_H

#include "wx/wx.h"
#include "savesHandler.h"

class PickingNameFrame : public wxFrame
{
public:
	PickingNameFrame(wxWindow * parent, std::shared_ptr<SavesHandler> sh);

	void setFileIDToSave(int idToSave);
	void setNameToEdit(const std::string &defaultName);

	void OnOKButtonClicked(wxCommandEvent &evt);
	void OnClose(wxCloseEvent &evt);

private:
	std::unique_ptr<wxTextCtrl> editBox;
	std::unique_ptr<wxButton> btn_OK;
	std::shared_ptr<SavesHandler> sh;
	int idToSave;

	void ChangeFrame(int newFrame);
};

#endif //PICKINGNAMEFRAME_H