/*
 * ServerObject.cpp
 *
 *  Created on: 18-10-2008
 *      Author: christian
 */

#include "ServerObject.h"
#include <iostream>

namespace Xanguli {

ServerObject::ServerObject(DBusConnection* bus, std::string path) : introspect_xml("") {
}

ServerObject::~ServerObject() {
}

DBusHandlerResult ServerObject::messageHandler(DBusConnection* bus, DBusMessage* message, void* user_data) {
	std::cout << "I messageHandler\n";
	return ((ServerObject*) user_data)->handleCall(bus, message);
}

void ServerObject::register_object(DBusConnection* bus, ServerObject *serverObject, std::string path) {
	DBusError error;
	dbus_error_init(&error);
	DBusObjectPathVTable vtable;
	vtable.message_function = &messageHandler;
	vtable.unregister_function = NULL;
	dbus_connection_try_register_object_path (bus, path.c_str(), &vtable, serverObject, &error);
}

DBusHandlerResult ServerObject::handleCall(DBusConnection* connection, DBusMessage* methodCall) {
	std::cout << "I handleCall\n";
	const char* interfaceName = dbus_message_get_interface(methodCall);
	std::cout << "Interfacename = " << interfaceName << "\n";
	dbus_uint32_t serial = dbus_message_get_serial(methodCall);
	DBusInterface* interface = interfaces[interfaceName];
	DBusMessage* reply;
	if (interface == NULL) {
		reply = dbus_message_new_error(methodCall, DBUS_ERROR_FAILED, "No such interface");
	} else {
		reply = interface->handleCall(methodCall);
	}
	dbus_connection_send(connection, reply, &serial);
}

void ServerObject::Introspect(std::string& xml_data) {
	xml_data  = "<!DOCTYPE node PUBLIC '-//freedesktop//DTD D-BUS Object Introspection 1.0//EN'\n"
		        "'http://www.freedesktop.org/standards/dbus/1.0/introspect.dtd'>\n"
	            "<node name='/'>\n";

	std::map<std::string, DBusInterface*>::iterator it;
	for (it = interfaces.begin(); it != interfaces.end(); it++) {
		xml_data += it->second->GetXml();
	}
	xml_data += "</node>\n";
}

ServerObject& ServerObject::operator<< (DBusInterface* interface) {
	std::cout <<  "<< " + interface->GetInterfaceName() << "\n";
	interfaces[interface->GetInterfaceName()] = interface;
	return *this;
}

}
