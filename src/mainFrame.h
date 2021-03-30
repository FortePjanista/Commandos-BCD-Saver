#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/wx.h>
#include <memory>

class PickingFrame;

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

	void ChangeFrame(int newFrame, int mode);
	void InitBoxSizer();
};

#endif //MAINFRAME_H