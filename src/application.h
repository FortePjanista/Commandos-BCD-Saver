#ifndef APPLICATION_H
#define APPLICATION_H

#include "wx/wx.h"

class Application : public wxApp
{
public:
	virtual bool OnInit();
};
wxIMPLEMENT_APP(Application);

#endif //APPLICATION_H