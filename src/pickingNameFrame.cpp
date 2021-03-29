#include "pickingNameFrame.h"

#include "constants.h"

PickingNameFrame::PickingNameFrame(wxWindow * parent, std::shared_ptr<SavesHandler> sh): 
	wxFrame(parent, wxID_ANY, "Select name", parent->GetPosition(), wxSize(150,100), wxCAPTION | wxCLOSE_BOX),
	editBox(std::make_unique<wxTextCtrl>(this, wxID_ANY, "Empty", wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER)),
	btn_OK(std::make_unique<wxButton>(this, 11000, "OK", wxDefaultPosition, wxSize(60, 30))),
	idToSave(0),
	sh(sh)
{
	// Set frame's icon
	SetIcon(wxICON(aaaa));

	// Init box sizer
	wxBoxSizer * sizer = new wxBoxSizer(wxVERTICAL); // Will be deleted by wxWidgets
	int itemsProportion = 30;
	int itemFlags = wxALIGN_CENTRE | wxSHAPED | wxFIXED_MINSIZE | wxRIGHT | wxLEFT;
	sizer->Add(editBox.get(), itemsProportion, itemFlags);
	sizer->Add(btn_OK.get(), itemsProportion, itemFlags);

	//Set box sizer
	SetSizer(sizer);
	sizer->Layout();

	// Bind events
	Bind(wxEVT_CLOSE_WINDOW, &PickingNameFrame::OnClose, this);
	Bind(wxEVT_CHAR_HOOK, &PickingNameFrame::OnKeyDown, this);
	btn_OK->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &PickingNameFrame::OnOKButtonClicked, this);
	editBox->Bind(wxEVT_TEXT, &PickingNameFrame::OnTextChange, this);
	editBox->Bind(wxEVT_TEXT_ENTER, &PickingNameFrame::OnEnterPress, this);
}

void PickingNameFrame::OnOKButtonClicked(wxCommandEvent & evt)
{
	wxString newName = editBox->GetValue();
	int result = sh->save(idToSave, newName.ToStdString());
	if(result == ERROR_REDTMP_DOESNT_EXIST)
	{
		wxMessageBox(wxT("Someone in game has to hit ctrl + S before saving anywhere"), wxT("Info"), wxICON_INFORMATION);
	}
	ChangeFrame(FRAME_MAIN);
	evt.Skip();
}

void PickingNameFrame::OnClose(wxCloseEvent & evt)
{
	ChangeFrame(FRAME_PICKING);
}

void PickingNameFrame::OnTextChange(wxCommandEvent& evt)
{
	if (editBox->IsEmpty())
		btn_OK->Disable();
	else
		btn_OK->Enable();
	evt.Skip();
}

void PickingNameFrame::OnEnterPress(wxCommandEvent& evt)
{
	MSWClickButtonIfPossible(btn_OK.get());
	evt.Skip();
}

void PickingNameFrame::OnKeyDown(wxKeyEvent& evt)
{
	if (evt.GetKeyCode() == WXK_ESCAPE)
		ChangeFrame(FRAME_PICKING);
	evt.Skip();
}

void PickingNameFrame::ChangeFrame(int newFrame)
{
	Hide();
	switch (newFrame)
	{
	case FRAME_MAIN:
		GetParent()->GetParent()->Show();
		break;
	case FRAME_PICKING:
		GetParent()->Show();
	}
}

void PickingNameFrame::setFileIDToSave(int newIdToSave)
{
	idToSave = newIdToSave;
}

void PickingNameFrame::setNameToEdit(const std::string& defaultName)
{
	editBox->SetValue(defaultName);
	editBox->SetFocus();
}