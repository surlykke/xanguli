/*
 * DBusConnection.cpp
 *
 *  Created on: 29-08-2008
 *      Author: cpet2308
 */

#include "DBusConnection.h"

namespace Xanguli {

DBusConnection::DBusConnection(std::string path) {
}

DBusConnection::~DBusConnection() {
	// TODO Auto-generated destructor stub
}

DBusConnection DBusConnection::SessionBus() {
	DBusConnection result("");
	return result; // FIXME
}

void DBusConnection::mainLoop() {
	// FIXME
}

}
