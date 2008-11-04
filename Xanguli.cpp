#include <dbus/dbus.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "Xanguli.h"
#include "DBusProxy.h"
#include "org_xanguli_Xanguli.h"
#include "org_freedesktop_DBus_Introspectable.h"
#include "ServerObject.h"

namespace Xanguli {

	Xanguli::Xanguli() {

	}

	void Xanguli::run() {
		DBusError error;
		dbus_error_init(&error);
		DBusConnection *bus = dbus_bus_get(DBUS_BUS_SESSION, &error);

		DBusProxy dbusProxy(bus,
							"org.freedesktop.DBus",
							"org.freedesktop.DBus",
							"/org/freedesktop/DBus");
		unsigned int retval = 0;
		dbusProxy.call("RequestName", "su", "u", "org.xanguli.Service", 0, &retval);
		ServerObject* serverObject = new ServerObject(bus, "/Xanguli");
		(*serverObject) << new org_xanguli_Xanguli<Xanguli>(new Xanguli())
		                << new org_freedesktop_DBus_Introspectable<ServerObject>(serverObject);
		ServerObject::register_object(bus, serverObject, "/Xanguli");
		while(dbus_connection_read_write_dispatch(bus, -1));
		// TODO cleanup
	}

	void Xanguli::CreateController(std::string& path) {
		path = "Yihaa";
	}

}


int main(int argc, char **argv) {
	std::string tmp;
	tmp += "Hej\n";
	tmp += "der\n";
	std::cout << tmp;
	Xanguli::Xanguli::run();
}
