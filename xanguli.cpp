#include <dbus/dbus.h>
#include <stdio.h>
#include <stdlib.h>
#include "DBusProxy.h"
#include "DBusConnection.h"

int main(int argc, char **argv) {
	Xanguli::DBusProxy dbusProxy("org.freedesktop.DBus",
			             "/org/freedesktop/DBus",
			             "org.freedesktop.DBus");
	dbusProxy.call("RequestName",
			       "si",
			       "org.xanguli.sod", 0);
	Xanguli::DBusConnection bus = Xanguli::DBusConnection::SessionBus();

	bus.mainLoop();
}
