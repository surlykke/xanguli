/*
 * DBusConnection.cpp
 *
 *  Created on: 29-08-2008
 *      Author: cpet2308
 */

#include "DBusConnection.h"
#include <memory>
#include <string>

namespace Xanguli {

DBusConnection::DBusConnection(std::string path) {

}

DBusConnection::~DBusConnection() {
	// Nix zu tun
}

DBusConnection DBusConnection::SessionBus() {
	DBusConnection result("");
	return result; // FIXME
}

void DBusConnection::mainLoop() {
	// FIXME
}

}
