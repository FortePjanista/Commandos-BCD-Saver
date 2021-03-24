#ifndef PICKINGFRAME_H
#define PICKINGFRAME_H

#include "wx/wx.h"
#include "pickingNameFrame.h"
#include "savesHandler.h"
#include "constants.h"

class PickingFrame : public wxFrame
{
public:
	PickingFrame(int btnsCount, wxWindow * parent);

private:
	int mode;
	int btnsCount;
	wxButton** buttons;
	PickingNameFrame * pickingNameFrame;
	SavesHandler * sh;

public:
	void updateBtnNames();
	void setMode(int mode);
	int getMode();
	void OnButtonClicked(wxCommandEvent &evt);
	void OnClose(wxCloseEvent &evt);
};

#endif //PICKINGFRAME_H