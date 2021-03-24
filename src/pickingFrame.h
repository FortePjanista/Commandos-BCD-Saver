#ifndef PICKINGFRAME_H
#define PICKINGFRAME_H

#include "wx/wx.h"
#include "pickingNameFrame.h"
#include "savesHandler.h"
#include "constants.h"

class PickingFrame : public wxFrame
{
public:
	PickingFrame(wxWindow * parent);

private:
	constexpr static int btnsCount = SAVE_FILES_COUNT;
	int mode;
	std::unique_ptr<wxButton> buttons[btnsCount];
	std::unique_ptr<PickingNameFrame> pickingNameFrame;
	std::shared_ptr<SavesHandler> sh;

public:
	void updateBtnNames();
	void setMode(int mode);
	int getMode();
	void OnButtonClicked(wxCommandEvent &evt);
	void OnClose(wxCloseEvent &evt);
};

#endif //PICKINGFRAME_H