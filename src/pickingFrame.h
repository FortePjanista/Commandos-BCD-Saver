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
	void ChangeFrame(int newFrame);

	void OnButtonClicked(wxCommandEvent &evt);
	void OnClose(wxCloseEvent &evt);

private:
	constexpr static int btnsCount = SAVE_FILES_COUNT;

	void InitButtons();
	void InitBoxSizer();

	int mode;
	std::unique_ptr<wxButton> buttons[btnsCount];
	std::unique_ptr<PickingNameFrame> pickingNameFrame;
	std::shared_ptr<SavesHandler> sh;
};

#endif // PICKING_FRAME_H