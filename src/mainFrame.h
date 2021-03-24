#ifndef MAINFRAME_H
#define MAINFRAME_H

#include "pickingFrame.h"

class MainFrame : public wxFrame
{
public:
	MainFrame();

private:
	wxButton * btn_save;
	wxButton * btn_load;
	PickingFrame * pickingFrame;

public:
	void OnSaveButtonClicked(wxCommandEvent &evt);
	void OnLoadButtonClicked(wxCommandEvent &evt);
};

#endif //MAINFRAME_H