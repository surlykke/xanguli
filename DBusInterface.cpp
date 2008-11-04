/*
 * DBusInterface.cpp
 *
 *  Created on: 18-10-2008
 *      Author: christian
 */

#include "DBusInterface.h"

namespace Xanguli {
	DBusInterface::DBusInterface() {
	}

	DBusInterface::~DBusInterface() {
	}

	std::string DBusInterface::GetXml() {
		return xml;
	}

	std::string DBusInterface::GetInterfaceName() {return "";};

}
