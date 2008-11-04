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

#include <string>
#include <map>

namespace Xanguli {


class Controller {
public:
	Controller(std::string dbusId);

	void createWidget(std::string widget_name,
					  std::string parent_dbus_id,
					  std::map<std::string, std::string> options,
					  std::string &dbus_id);

	/**
	 * dbus-method:
	 *   name: Mainloop
	 */
	bool tkMainloop();

private:
  Tcl_Interp *interp;
  std::string dbusId;
};

}
#endif
