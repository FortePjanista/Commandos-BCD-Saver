#include "application.h"

#include "pathsHandler.h"
#include "mainFrame.h"

using namespace boost::filesystem;

bool Application::OnInit()
{
	MainFrame * mainFrame = new MainFrame();
	mainFrame->Show();

	auto & paths = PathsHandler::Get();
	if (!exists(paths.getCommandosUserDirectoryPath()))
	{
		wxMessageBox(wxT("You don't have Commandos - Beyond the Enemy lines installed."), wxT("Warning"), wxICON_WARNING);
	}
	else if (!exists(paths.getREDTMPPath()))
	{
		wxMessageBox(wxT("Someone in game has to hit ctrl + S before saving anywhere"), wxT("Info"), wxICON_INFORMATION);
	}

	return true;
}