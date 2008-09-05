#include "TtkButton.h"
#include "TkWidget.h"

namespace Xanguli {


TtkButton::TtkButton(dbus_string dbusId, dbus_string parent, dbus_map options, Tcl_Interp* interp)
  : TkWidget(dbusId) {
}


void TtkButton::text(std::string text) {
//  printf("Så er vi i TtkButton.text: %s\n", text);
//  char cmd[128];
//  sprintf(cmd, "%s configure -text \"%s\"", button->id, text);
//  printf("Udfører %s\n", cmd);
//  if (Tcl_Eval(button->interp, cmd) != TCL_OK) {
//    lose("Kunne ikke udføre '%s'\n", cmd);
//  }
}

void TtkButton::command(std::string command_name) {
//  printf("I ttk_button_command: %s\n", command_name);
//  string cmd;
////  sprintf(cmd, "%s configure -command [list xanguli_command %s %s]", button->id, button->id, command_name);
//  printf("Udfører %s\n", cmd);
//  if (Tcl_Eval(button->interp, cmd) != TCL_OK) {
////    lose("Kunne ikke udføre '%s'\n", cmd);
}

}
