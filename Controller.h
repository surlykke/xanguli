/*
 * XanguliController.h
 *
 *  Created on: 26-08-2008
 *      Author: cpet2308
 */
#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <dbus-1.0/dbus/dbus.h>
#include <stdio.h>
#include <stdlib.h>
#include <tcl.h>

#include "ServerObject.h"
#include "dbus-types.h"

namespace Xanguli {


class Controller : public ServerObject
{
public:
	Controller(dbus_string dbusId);

	/**
	 * dbus-method:
	 *   name: TtkButton
	 *   args:
	 *   - name: parent
	 *     type: s
	 *   - name: options
	 *     type: a{ss}
	 *   - name: dbusPath
	 *     type: s
	 *     direction: out
	 */
	bool ttkButton(dbus_string parent, dbus_map options, dbus_string &dbusPattern);

	/**
	 * dbus-method:
	 *   name: Mainloop
	 */
	bool tkMainloop();

private:
  Tcl_Interp *interp;
  dbus_string dbusId;
};

}
#endif
