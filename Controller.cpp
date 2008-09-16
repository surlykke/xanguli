#include <dbus/dbus.h>
#include <string>
#include <sstream>
#include <iostream>
#include <tcl.h>
#include <tk.h>

#include "Controller.h"
#include "Manager.h"
#include "TtkButton.h"
#include "dbus-types.h"
#include "IdGenerator.h"
#include "dbus-types.h"

namespace Xanguli {

int xanguli_command(ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[]) {
  dbus_string widget_path;
  int widget_path_len;
  dbus_string signal;
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

Controller::Controller(dbus_string dbusId) : ServerObject(dbusId) {
  std::cout << "Hej fra xanguli_controller_init\n";


  interp = Tcl_CreateInterp();

  if (Tcl_Init(interp) != TCL_OK) { lose("Could not initiate interpreter\n"); }

  if (Tcl_Eval(interp, "package require Tk") != TCL_OK) { lose("Could not initiate tk"); }

  // Make a callback hook for tcl commands
  Tcl_CreateObjCommand (interp,
                        "xanguli_command",
                        xanguli_command,
                        (ClientData) NULL,
                        (Tcl_CmdDeleteProc *) NULL);
}



bool Controller::ttkButton(dbus_string parent,
								  dbus_map    options,
								  dbus_string &dbus_id) {
  std::cout << "Ind i create_ttk_button\n";
  std::string tk_id = parent + ".ttk_button_" + IdGenerator::generateId();
  dbus_id = tk_id;
  int i;
  for (i = 0; dbus_id[i]; i++) {
    if (dbus_id[i] == '.')
      dbus_id[i] = '/';
  }

  std::cout << "tk_id = " << tk_id;

  // Nyt object
  TtkButton* ttkButton = new TtkButton(dbus_id, tk_id, options, interp);

  std::string cmd = "button " + tk_id;

  // TODO: Put options p�

  if (Tcl_Eval(interp, cmd.c_str()) != TCL_OK) {
    // set error felt
	return false;
  }
  return true;
}

bool Controller::tkMainloop() {
  Tk_MainLoop();
  return true;
}

}
