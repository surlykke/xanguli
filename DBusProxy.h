/*
 * DBusProxy.h
 *
 *  Created on: 28-08-2008
 *      Author: cpet2308
 */

#ifndef DBUSPROXY_H_
#define DBUSPROXY_H_

#include "dbus-types.h"

namespace Xanguli {

class DBusProxy {
public:
	DBusProxy(dbus_string service, dbus_string interface, dbus_string path);
	virtual ~DBusProxy();
	bool call(dbus_string method, dbus_string signature,...);
};

}
#endif /* DBUSPROXY_H_ */
