#include "dbus/dbus.h"
namespace Xanguli {

	class Container {
	public:
		DBusHandlerResult* handleMessage(DBusConnection* bus, DBusMessage* message);
	};
}
