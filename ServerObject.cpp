/*
 * ServerObject.cpp
 *
 *  Created on: 26-08-2008
 *      Author: cpet2308
 */
#include <string>
#include <iostream>

#include "ServerObject.h"
#include "Manager.h"

namespace Xanguli {

ServerObject::ServerObject(dbus_string pDbusId) {
	dbusId = pDbusId;
//	XanguliManager::instance()->registerObject(this);
}

ServerObject::~ServerObject() {
	// TODO Auto-generated destructor stub
}

void ServerObject::lose(std::string str)
{
  std::cerr << str;
}

}
