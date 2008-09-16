#include "dbus/dbus.h"

namespace Xanguli {
class Dispatcher
  {
  public:
    DBusHandlerResult* DispatchMessage(DBusConnection *bus, DBusMessage *message, void* user_data);
  };
}
