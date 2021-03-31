#include "mainFrame.h"

#include "pickingFrame.h"

constexpr int FRAME_SIZE_X = 300;
constexpr int FRAME_SIZE_Y = 325;

constexpr int BUTTONS_HORIZONTAL_MARGIN = 20;

MainFrame::MainFrame()
	: wxFrame(
			  /* parent:   */	nullptr,
			  /* id:       */	wxID_ANY,
			  /* name:     */	"Commandos - Saver",
			  /* position: */	wxDefaultPosition,
			  /* size:     */	wxSize(FRAME_SIZE_X, FRAME_SIZE_Y),
			  /* flags:    */	wxCAPTION | wxMINIMIZE_BOX | wxCLOSE_BOX
			  ),
	btn_save(std::make_unique<wxButton>(this, 10000, "Save")),
	btn_load(std::make_unique<wxButton>(this, 10001, "Load")),
	pickingFrame(std::make_unique<PickingFrame>(this))
{
	SetIcon(wxICON(aaaa));

	// Init box sizer
	InitBoxSizer();

	// Bind events
	btn_save->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &MainFrame::OnSaveButtonClicked, this);
	btn_load->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &MainFrame::OnLoadButtonClicked, this);
}

void MainFrame::OnSaveButtonClicked(wxCommandEvent &evt)
{
	ChangeFrame(FRAME_PICKING, MODE_SAVE);

	evt.Skip();
}

void MainFrame::OnLoadButtonClicked(wxCommandEvent &evt)
{
	ChangeFrame(FRAME_PICKING, MODE_LOAD);

	evt.Skip();
}

void MainFrame::ChangeFrame(int newFrame, int mode)
{
	Hide();
	switch(newFrame)
	{
	case FRAME_PICKING:
	{
		// Update names shown on buttons
		pickingFrame->updateBtnNames();
		pickingFrame->setMode(mode);

		wxPoint pos = GetPosition();
		pos.x += 75;
		pickingFrame->SetPosition(pos);
		pickingFrame->Show();
	}
	}
}

void MainFrame::InitBoxSizer()
{
	wxBoxSizer * sizer = new wxBoxSizer(wxVERTICAL); // wxWidgets will deallocate it

	// The proportion variable is responsible for knowing whether the sizer should also
	// affect children of this frame. (0 - no, more than 0 - yes)
	int changeChildren = 1;
	int flags = wxALIGN_CENTRE | wxSHAPED | wxFIXED_MINSIZE | wxRIGHT | wxLEFT;
	sizer->Add(btn_save.get(), changeChildren, flags, BUTTONS_HORIZONTAL_MARGIN);
	sizer->Add(btn_load.get(), changeChildren, flags, BUTTONS_HORIZONTAL_MARGIN);

	this->SetSizer(sizer);
	sizer->Layout();
}
