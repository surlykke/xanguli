/*
 * TtkButton.h
 *
 *  Created on: 26-08-2008
 *      Author: cpet2308
 */
#ifndef TTKBUTTON_H_
#define TTKBUTTON_H_

#include <dbus/dbus.h>
#include <tcl.h>
#include <stdio.h>
#include <stdlib.h>
#include "TkWidget.h"
#include "dbus-types.h"

namespace Xanguli {

class TtkButton : public TkWidget
{
public:
	TtkButton(dbus_string dbusId, dbus_string parent, dbus_map options, Tcl_Interp* interp);

	void text(dbus_string text);

	void command(std::string commandName);
};

}
#endif

