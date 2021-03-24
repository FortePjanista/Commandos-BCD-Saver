#include "pickingNameFrame.h"

PickingNameFrame::PickingNameFrame(wxWindow * parent) 
	: wxFrame(parent, wxID_ANY, "Select name", parent->GetPosition(),
							wxSize(150,100), wxCAPTION | wxCLOSE_BOX),
	defaultName("Empty"), sh(nullptr)
{
	editBox = new wxTextCtrl(this, wxID_ANY, defaultName);
	btn_OK = new wxButton(this, 11000, "OK");
	btn_OK->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &PickingNameFrame::OnOKButtonClicked, this);
	btn_OK->SetSize(wxSize(60, 30));

	wxBoxSizer * sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(editBox, 30, wxALIGN_CENTRE | wxSHAPED | wxFIXED_MINSIZE | wxRIGHT | wxLEFT, 0);
	sizer->Add(btn_OK, 30, wxALIGN_CENTRE | wxSHAPED | wxFIXED_MINSIZE | wxRIGHT | wxLEFT, 0);

	SetSizer(sizer);
	sizer->Layout();

	Bind(wxEVT_CLOSE_WINDOW, &PickingNameFrame::OnClose, this);

	SetIcon(wxICON(aaaa));
}

void PickingNameFrame::setLastSelectedBtn(int _lastSelectedBtn)
{
	lastSelectedBtn = _lastSelectedBtn;
}

void PickingNameFrame::setSavesHandler(SavesHandler * _sh)
{
	sh = _sh;
}

void PickingNameFrame::setDefaultName(std::string _defaultName)
{
	defaultName = _defaultName;
}

void PickingNameFrame::OnOKButtonClicked(wxCommandEvent & evt)
{
	//save here
	wxString newName = editBox->GetValue();
	sh->save(lastSelectedBtn, newName.ToStdString());


	sh->loadInfoIntoSaveFiles();

	//hide
	Hide();
	GetParent()->GetParent()->Show();
	evt.Skip();
}

void PickingNameFrame::OnClose(wxCloseEvent & evt)
{

	GetParent()->Show();
	Hide();
}
