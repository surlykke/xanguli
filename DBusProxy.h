/*
 * DBusProxy.h
 *
 *  Created on: 28-08-2008
 *      Author: cpet2308
 */

#ifndef DBUSPROXY_H_
#define DBUSPROXY_H_

#include "dbus/dbus.h"
#include <string>

namespace Xanguli {

class DBusProxy {
public:
	DBusProxy(DBusConnection *bus, std::string service, std::string interface, std::string path);
	virtual ~DBusProxy();
	bool call(std::string method, std::string in_signature, std::string out_signature, ...);

private:

	DBusConnection *bus;
	std::string service;
	std::string interface;
	std::string path;

};

}
#endif /* DBUSPROXY_H_ */
