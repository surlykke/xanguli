#include <dbus/dbus.h>
#include <string>
#include <sstream>
#include <iostream>
#include <tcl.h>
#include <tk.h>

#include "Controller.h"
#include "IdGenerator.h"
#include "XanguliException.h"

namespace Xanguli {

int xanguli_command(ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[]) {
  std::string widget_path;
  int widget_path_len;
  std::string signal;
  int signal_len;

  if (3 != objc) {
    ::Tcl_WrongNumArgs(interp, 1, objv, "widget command_name");
    return TCL_ERROR;
  }

  widget_path = Tcl_GetStringFromObj(objv[1], &widget_path_len);

  signal = Tcl_GetStringFromObj(objv[2], &signal_len);

  /*
   * TODO:
   * send signal 'signal' on the object owning 'widget_path'
   */

  std::cout << widget_path << " - " << signal << "\n";
  return TCL_OK;
}

Controller::Controller(std::string dbusId) {
  interp = Tcl_CreateInterp();

  if (Tcl_Init(interp) != TCL_OK) {
	  throw new XanguliException("Could not initiate interpreter\n");
  }
  if (Tcl_Eval(interp, "package require Tk") != TCL_OK) {
	  throw new XanguliException("Could not initiate tk");
  }
  if (Tcl_Eval(interp, "package require Ttk") != TCL_OK) {
	  throw new XanguliException("Could not initiate ttk");
  }
  // Make a callback hook for tcl commands
  Tcl_CreateObjCommand (interp, "xanguli_command", xanguli_command, NULL, NULL);

  // TODO Make callback for bindings...
}


void Controller::createWidget(std::string widget_name,
		                      std::string parent_dbus_id,
		                      std::map<std::string, std::string> options,
						      std::string &dbus_id) {
	// TODO
//  std::cout << "tk_id = " << tk_id;
//
//  // Nyt object
//  TtkButton* ttkButton = new TtkButton(dbus_id, tk_id, options, interp);
//
//  std::string cmd = "button " + tk_id;
//
//  // TODO: Put options på
//
//  if (Tcl_Eval(interp, cmd.c_str()) != TCL_OK) {
//    // set error felt
//	return false;
//  }
//  return true;
}

bool Controller::tkMainloop() {
  Tk_MainLoop();
  return true;
}

}
