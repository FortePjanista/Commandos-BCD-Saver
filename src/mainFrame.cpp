#include "mainFrame.h"

MainFrame::MainFrame()
	: wxFrame(nullptr, wxID_ANY, "Commandos - Saver", wxDefaultPosition, wxSize(300, 325),
												wxCAPTION | wxMINIMIZE_BOX | wxCLOSE_BOX) // was wxSize(300, 325) wxSize(150, 205)  | wxRESIZE_BORDER
{
	SetIcon(wxICON(aaaa));
	SetMinSize(wxSize(130, 205));
	SetMaxSize(wxSize(400, 664));
	btn_save = new wxButton(this, 10000, "Save");
	btn_load = new wxButton(this, 10001, "Load");

	btn_save->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &MainFrame::OnSaveButtonClicked, this);
	btn_load->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &MainFrame::OnLoadButtonClicked, this);

	wxBoxSizer * sizer = new wxBoxSizer(wxVERTICAL);

	sizer->SetItemMinSize(btn_save, wxSize(100, 62));
	sizer->SetItemMinSize(btn_load, wxSize(100, 62));

	sizer->Add(btn_save, 30, wxALIGN_CENTRE | wxSHAPED | wxFIXED_MINSIZE | wxRIGHT | wxLEFT, 20);
	sizer->Add(btn_load, 30, wxALIGN_CENTER | wxSHAPED | wxFIXED_MINSIZE | wxRIGHT | wxLEFT, 20);

	sizer->SetItemMinSize(btn_save, wxSize(120, 60));
	sizer->SetItemMinSize(btn_load, wxSize(120, 60));


	this->SetSizer(sizer);
	sizer->Layout();

	//Picking Frame
	pickingFrame = new PickingFrame(10, this);

}

void MainFrame::OnSaveButtonClicked(wxCommandEvent &evt)
{
	this->Hide();
	wxPoint pos = GetPosition();
	pos.x += 75;
	pickingFrame->SetPosition(pos);
	pickingFrame->Show();
	pickingFrame->updateBtnNames();
	pickingFrame->setMode(MODE_SAVE);
	evt.Skip();
}

void MainFrame::OnLoadButtonClicked(wxCommandEvent &evt)
{
	this->Hide();
	wxPoint pos = GetPosition();
	pos.x += 75;
	pickingFrame->SetPosition(pos);
	pickingFrame->Show();
	pickingFrame->updateBtnNames();

	pickingFrame->setMode(MODE_LOAD);
	evt.Skip();
}
