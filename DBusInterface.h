/*
 * DBusInterface.h
 *
 *  Created on: 18-10-2008
 *      Author: christian
 */

#ifndef DBUSINTERFACE_H_
#define DBUSINTERFACE_H_
#include <string>
#include "dbus/dbus.h"

namespace Xanguli {
class DBusInterface {
	public:
		DBusInterface();
		virtual ~DBusInterface();
		std::string GetXml();
		virtual std::string GetInterfaceName();
		virtual DBusMessage* handleCall(DBusMessage* message) = 0;

	protected:
		std::string interfaceName;
		std::string xml;
	};

}

#endif /* DBUSINTERFACE_H_ */
