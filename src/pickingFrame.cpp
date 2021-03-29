#include "pickingFrame.h"

#include "savesHandler.h"
#include "pickingNameFrame.h"

PickingFrame::PickingFrame(wxWindow * parent)
	: wxFrame(parent, wxID_ANY, "Select a slot", parent->GetPosition(), 
							wxSize(150, 700), wxCAPTION | wxCLOSE_BOX),
	sh(std::make_shared<SavesHandler>()),
	pickingNameFrame(std::make_unique<PickingNameFrame>(this, sh)),
	mode(MODE_SAVE)
{
	InitButtons();
	InitBoxSizer();

	//Bind events
	Bind(wxEVT_CLOSE_WINDOW, &PickingFrame::OnClose, this);


	//SetMinSize(wxSize(150, 664));
	//SetMaxSize(wxSize(150, -1));

	SetIcon(wxICON(aaaa));
}

void PickingFrame::InitButtons()
{
	for (int i = 0; i < btnsCount; i++)
	{
		buttons[i] = std::make_unique<wxButton>(this, 10010 + i, "Slot " + std::to_string(i));
		buttons[i]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &PickingFrame::OnButtonClicked, this);
	}
}

void PickingFrame::InitBoxSizer()
{
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL); // <- Will be deleted by wxWidgets
	for (int i = 0; i < btnsCount; i++)
	{
		sizer->SetItemMinSize(buttons[i].get(), wxSize(100, 62));
		sizer->Add(buttons[i].get(), 30, wxALIGN_CENTRE | wxSHAPED | wxFIXED_MINSIZE | wxRIGHT | wxLEFT, 20);
		sizer->SetItemMinSize(buttons[i].get(), wxSize(120, 60));
	}
	sizer->Layout();
	this->SetSizer(sizer);
}

void PickingFrame::updateBtnNames()
{
	for (int i = 0; i < btnsCount; i++)
	{
		buttons[i]->SetLabel(sh->getSaveFileName(i));
	}
}

void PickingFrame::OnButtonClicked(wxCommandEvent &evt)
{
	// Get button's ID
	int id = evt.GetId() - 10010;
	if (mode == MODE_SAVE)
	{
		//Focus edit box
		pickingNameFrame->setNameToEdit(sh->getSaveFileName(id));

		//Pass file ID to be potentially saved later
		pickingNameFrame->setFileIDToSave(id);

		ChangeFrame(FRAME_PICKING_NAME);
	}
	else if(mode == MODE_LOAD)
	{
		int result = sh->load(id);
		switch(result)
		{
		case ERROR_REDTMP_DOESNT_EXIST:
			wxMessageBox(wxT("Someone in game has to hit ctrl + S before loading"), wxT("Info"), wxICON_INFORMATION);
			return;
		case ERROR_SAVE_FILE_IS_EMPTY:
		case ERROR_SAVE_FILE_DOESNT_EXIST:
			wxMessageBox(wxT("Selected slot is empty"), wxT("Info"), wxICON_INFORMATION);
			return;
		}
		ChangeFrame(FRAME_MAIN);
	}
}

void PickingFrame::OnClose(wxCloseEvent & evt)
{
	ChangeFrame(FRAME_MAIN);
}

void PickingFrame::ChangeFrame(int newFrame)
{
	Hide();
	switch (newFrame)
	{
	case FRAME_MAIN:
	{
		wxPoint pos = GetPosition();
		pos.x -= 75;
		GetParent()->SetPosition(pos);
		GetParent()->Show();
		break;
	}
	case FRAME_PICKING_NAME:
		pickingNameFrame->SetPosition(GetPosition());
		pickingNameFrame->Show();
	}
}

void PickingFrame::setMode(int _mode)
{
	mode = _mode;
}

int PickingFrame::getMode()
{
	return mode;
}
