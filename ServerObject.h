/*
 * ServerObject.h
 *
 *  Created on: 18-10-2008
 *      Author: Christian Surlykke
 */

#ifndef SERVEROBJECT_H_
#define SERVEROBJECT_H_

#include <string>
#include <map>
#include "dbus/dbus.h"
#include "DBusInterface.h"

namespace Xanguli {
	class ServerObject {
	public:
		ServerObject(DBusConnection *bus, std::string path);
		virtual ~ServerObject();
		static DBusHandlerResult messageHandler(DBusConnection* connection, DBusMessage* message, void* user_data);
		DBusHandlerResult handleCall(DBusConnection* connection, DBusMessage* message);
		void Introspect(std::string& xml_data);
		ServerObject& operator<<(DBusInterface* interface);
		static void register_object(DBusConnection *bus, ServerObject *serverObject, std::string path);
	private:
		std::map<std::string, DBusInterface*> interfaces;
		std::string introspect_xml;
	};
}
#endif /* SERVEROBJECT_H_ */
