#include "Dispatcher.h"
#include "Container.h"
namespace Xanguli {
DBusHandlerResult* Dispatcher::DispatchMessage(DBusConnection* bus,
                                               DBusMessage* message,
			                                   void* user_data) {
    Container* container = (Container*) user_data;
    return container->handleMessage(bus, message);
}
}
