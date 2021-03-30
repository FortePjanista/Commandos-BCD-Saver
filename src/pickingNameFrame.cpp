#include "pickingNameFrame.h"

#include "constants.h"
#include "savesHandler.h"

constexpr int PICKING_NAME_FRAME_X_SIZE = 150;
constexpr int PICKING_NAME_FRAME_Y_SIZE = 100;

constexpr int BUTTON_X_SIZE = 60;
constexpr int BUTTON_Y_SIZE = 30;

PickingNameFrame::PickingNameFrame(wxWindow * parent, std::shared_ptr<SavesHandler> _sh) 
	: wxFrame(parent, wxID_ANY, "Select name", parent->GetPosition(), wxSize(PICKING_NAME_FRAME_X_SIZE, PICKING_NAME_FRAME_Y_SIZE),
																										wxCAPTION | wxCLOSE_BOX),
	editBox(std::make_unique<wxTextCtrl>(this, wxID_ANY, "Empty", wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER)),
	btn_OK(std::make_unique<wxButton>(this, 11000, "OK", wxDefaultPosition, wxSize(BUTTON_X_SIZE, BUTTON_Y_SIZE))),
	idToSave(0),
	sh(_sh)
{
	SetIcon(wxICON(aaaa));

	// Init box sizer
	InitBoxSizer();

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
	switch(newFrame)
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

	// Set focus on thos edit box to edit name instantly
	editBox->SetFocus();
}

void PickingNameFrame::InitBoxSizer()
{
	wxBoxSizer * sizer = new wxBoxSizer(wxVERTICAL); // Will be deleted by wxWidgets

	// The proportion variable is responsible for knowing whether the sizer should also
	// affect children of this frame. (0 - no, more than 0 - yes)
	int changeChildrenAlso = 1;
	int itemFlags = wxALIGN_CENTRE | wxSHAPED | wxFIXED_MINSIZE | wxRIGHT | wxLEFT;
	sizer->Add(editBox.get(), changeChildrenAlso, itemFlags);
	sizer->Add(btn_OK.get(), changeChildrenAlso, itemFlags);

	// Calculate children postions
	sizer->Layout();

	// Add to this frame
	SetSizer(sizer);
}