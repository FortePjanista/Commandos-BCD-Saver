#ifndef MAINFRAME_H
#define MAINFRAME_H

#include "pickingFrame.h"

class MainFrame : public wxFrame
{
public:
	MainFrame();

	void OnSaveButtonClicked(wxCommandEvent &evt);
	void OnLoadButtonClicked(wxCommandEvent &evt);

private:
	std::unique_ptr<wxButton> btn_save;
	std::unique_ptr<wxButton> btn_load;
	std::unique_ptr<PickingFrame> pickingFrame;
};

#endif //MAINFRAME_H