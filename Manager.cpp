#include "Manager.h"
#include "IdGenerator.h"
#include "Controller.h"
#include "dbus-types.h"

namespace Xanguli {

Manager* Manager::instance() {
	// FIXME
	return NULL;
}

void Manager::createController(dbus_string &controllerId) {
  	controllerId = "/xanguli_controller_" + dbus_string(IdGenerator::generateId());
  	//XanguliController *xanguliController = new XanguliController(controllerId);
}

}



