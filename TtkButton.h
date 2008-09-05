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

/**
 * dbus-object:
 *   signals:
 *   - command:
 *       args:
 *       - name: command-name
 *         type: s
 *
 */
class TtkButton : public TkWidget
{
public:
	TtkButton(dbus_string dbusId, dbus_string parent, dbus_map options, Tcl_Interp* interp);
	void text(dbus_string text);

	/**
	 * dbus-method:
	 *   args:
	 *   - name: command
	 *   - type: s
	 *   - doc:  The name of the command to invoke when the button is pressed.
	 */
	void command(std::string commandName);
};

}
#endif

