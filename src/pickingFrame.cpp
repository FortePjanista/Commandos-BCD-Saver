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
	sh = std::make_shared<SavesHandler>(btnsCount);
	sh->loadInfoIntoSaveFiles();
	pickingNameFrame = std::make_unique<PickingNameFrame>(this, sh);

	SetIcon(wxICON(aaaa));
}

void PickingFrame::updateBtnNames()
{
	for (int i = 0; i < btnsCount; i++)
	{
		buttons[i]->SetLabel(sh->getSaveFileInfo(i));
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
		//get defaultName
		pickingNameFrame->setDefaultName(sh->getSaveFileInfo(id));

		//getFileId
		pickingNameFrame->setLastSelectedBtn(id);

		//call rename frame
		Hide();
		pickingNameFrame->SetPosition(GetPosition());
		pickingNameFrame->Show();

		//sh.save(id, getnewname) -> call it at the end of the execution of the above frame
	}
	else if(mode == MODE_LOAD)
	{
		sh->load(id);
		Hide();
		GetParent()->Show();
	}
}

void PickingFrame::OnClose(wxCloseEvent & evt)
{
	GetParent()->Show();
	Hide();
}
