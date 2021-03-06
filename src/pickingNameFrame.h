#ifndef PICKINGNAMEFRAME_H
#define PICKINGNAMEFRAME_H

#include "wx/wx.h"

class SavesHandler;

class PickingNameFrame : public wxFrame
{
public:
	PickingNameFrame(wxWindow * parent, std::shared_ptr<SavesHandler> sh);

	void setFileIDToSave(int idToSave);
	void setNameToEdit(const std::string &defaultName);

	void OnOKButtonClicked(wxCommandEvent &evt);
	void OnClose(wxCloseEvent &evt);
	void OnTextChange(wxCommandEvent& evt);
	void OnEnterPress(wxCommandEvent& evt);
	void OnKeyDown(wxKeyEvent& evt);

private:
	std::unique_ptr<wxTextCtrl> editBox;
	std::unique_ptr<wxButton> btn_OK;
	std::shared_ptr<SavesHandler> sh;
	int idToSave;

	void ChangeFrame(int newFrame);
	void InitBoxSizer();
};

#endif //PICKINGNAMEFRAME_H