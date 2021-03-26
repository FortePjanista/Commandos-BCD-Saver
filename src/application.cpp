#include "application.h"
#include "mainFrame.h"
#include "pathsHandler.h"

bool Application::OnInit()
{
	MainFrame * mainFrame = new MainFrame();
	mainFrame->Show();

	auto & paths = PathsHandler::Get();
	if (!paths.IsCommandosInstalled())
		wxMessageBox(wxT("You don't have Commandos - Beyond the Enemy lines installed."), wxT("Warning"), wxICON_WARNING);
	else if (!paths.DoesREDTMPExist())
		wxMessageBox(wxT("Someone in game has to hit ctrl + S before saving anywhere"), wxT("Info"), wxICON_INFORMATION);

	return true;
}