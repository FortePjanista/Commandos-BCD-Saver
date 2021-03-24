#ifndef MAINFRAME_H
#define MAINFRAME_H

#include "pickingFrame.h"

class MainFrame : public wxFrame
{
public:
	MainFrame();

private:
	std::unique_ptr<wxButton> btn_save;
	std::unique_ptr<wxButton> btn_load;
	std::unique_ptr<PickingFrame> pickingFrame;

public:
	void OnSaveButtonClicked(wxCommandEvent &evt);
	void OnLoadButtonClicked(wxCommandEvent &evt);
};

#endif //MAINFRAME_H