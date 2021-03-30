#ifndef PICKING_FRAME_H
#define PICKING_FRAME_H

#include "wx/wx.h"
#include "constants.h"

class SavesHandler;
class PickingNameFrame;

class PickingFrame : public wxFrame
{
public:
	PickingFrame(wxWindow * parent);

	void updateBtnNames();
	void setMode(int mode);
	int getMode();

	void OnButtonClicked(wxCommandEvent &evt);
	void OnClose(wxCloseEvent &evt);

private:
	constexpr static int btnsCount = SAVE_FILES_COUNT;

	int mode;
	std::unique_ptr<wxButton> buttons[btnsCount];
	std::shared_ptr<SavesHandler> sh;
	PickingNameFrame * pickingNameFrame;

	void InitButtons();
	void InitBoxSizer();
	void ChangeFrame(int newFrame);
};

#endif // PICKING_FRAME_H