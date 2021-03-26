#include "pickingFrame.h"

PickingFrame::PickingFrame(wxWindow * parent): 
	wxFrame(parent, wxID_ANY, "Select a slot", parent->GetPosition(),
							wxSize(150, 700), wxCAPTION | wxCLOSE_BOX),
	mode(MODE_SAVE)
{
	for (int i = 0; i < btnsCount; i++)
	{
		buttons[i] = std::make_unique<wxButton>(this, 10010 + i, "Slot " + std::to_string(i));
		buttons[i]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &PickingFrame::OnButtonClicked, this);
	}

	wxBoxSizer * sizer = new wxBoxSizer(wxVERTICAL);

	for (int i = 0; i < btnsCount; i++)
	{
		sizer->SetItemMinSize(buttons[i].get(), wxSize(100, 62));
		sizer->Add(buttons[i].get(), 30, wxALIGN_CENTRE | wxSHAPED | wxFIXED_MINSIZE | wxRIGHT | wxLEFT, 20);
		sizer->SetItemMinSize(buttons[i].get(), wxSize(120, 60));
	}

	//Binds
	Bind(wxEVT_CLOSE_WINDOW, &PickingFrame::OnClose, this);


	this->SetSizer(sizer);
	sizer->Layout();

	SetMinSize(wxSize(150, 664));
	SetMaxSize(wxSize(150, -1));
	sh = std::make_shared<SavesHandler>();
	pickingNameFrame = std::make_unique<PickingNameFrame>(this, sh);

	SetIcon(wxICON(aaaa));
}

void PickingFrame::updateBtnNames()
{
	for (int i = 0; i < btnsCount; i++)
	{
		buttons[i]->SetLabel(sh->getSaveFileName(i));
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

void PickingFrame::OnButtonClicked(wxCommandEvent &evt)
{
	int id = evt.GetId() - 10010;
	if (mode == MODE_SAVE)
	{
		//Focus edit box
		pickingNameFrame->setNameToEdit(sh->getSaveFileName(id));

		//Set file id to save
		pickingNameFrame->setFileIDToSave(id);

		//Show Picking Name frame
		Hide();
		pickingNameFrame->SetPosition(GetPosition());
		pickingNameFrame->Show();
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
		Hide();
		GetParent()->Show();
	}
}

void PickingFrame::OnClose(wxCloseEvent & evt)
{
	//Go back to Main Frame
	wxPoint pos = GetPosition();
	pos.x -= 75;
	GetParent()->SetPosition(pos);
	Hide();
	GetParent()->Show();
}
