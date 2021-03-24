#include "application.h"
#include "mainFrame.h"

bool Application::OnInit()
{
	MainFrame * mainFrame = new MainFrame();
	mainFrame->Show();
	return true;
}