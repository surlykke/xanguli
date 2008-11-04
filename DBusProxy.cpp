/*
 * DBusProxy.cpp
 *
 *  Created on: 28-08-2008
 *      Author: Christian Surlykke
 */

#include <iostream>
#include "DBusProxy.h"
#include "dbus/dbus.h"

namespace Xanguli {

DBusProxy::DBusProxy(DBusConnection *bus, std::string service, std::string interface, std::string path) {
	this->bus = bus;
	this->service = service;
	this->interface = interface;
	this->path = path;
}

DBusProxy::~DBusProxy() {
}

bool DBusProxy::call(std::string method, std::string in_signature, std::string out_signature, ... ) {
	DBusError error;

	std::cout << "service = " << service << "\n"
	          << "path = " << path << "\n"
	          << "interface = " << interface << "\n"
	          << "method = " << method << "\n";

	DBusMessage* message = dbus_message_new_method_call(service.c_str(), path.c_str(), interface.c_str(), method.c_str());
	DBusMessageIter messageIter;
	dbus_message_iter_init_append(message, &messageIter);
	std::cout << "iter initted\n";
	va_list arguments;
	va_start(arguments, out_signature);
	std::string s = "test";
	for (std::string::const_iterator it = in_signature.begin(); it != in_signature.end(); it++) {
		std::cout << "signature '" << *it << "'\n";
		if (*it == 'i') {
	          int i = va_arg(arguments, int);
			  dbus_message_iter_append_basic(&messageIter, DBUS_TYPE_INT32, &i);
			  std::cout << "Appended " << i << "\n";
		}
		else if (*it == 'u') {
	          unsigned int i = va_arg(arguments, unsigned int);
			  dbus_message_iter_append_basic(&messageIter, DBUS_TYPE_UINT32, &i);
			  std::cout << "Appended " << i << "\n";
		}
		else if (*it == 's') {
          char* s = va_arg(arguments, char*);
          dbus_message_iter_append_basic(&messageIter, DBUS_TYPE_STRING, &s);
		  std::cout << "Appended '" << s << "'\n";
		}
		else {
			std::cerr << "Signature type'" << in_signature << "' not known\n";
		}
	}
	dbus_error_init(&error);
	DBusMessage* reply = dbus_connection_send_with_reply_and_block(bus, message, 20, &error);

	if (reply != NULL) {
		std::cout << "Got reply\n";
		DBusMessageIter replyIter;
		dbus_message_iter_init(reply, &replyIter);
	    for (std::string::const_iterator it = out_signature.begin(); it != out_signature.end(); it++) {
			std::cout << "out_signature '" << *it << "'\n";
			if (*it == 'i') {
		          int* i = va_arg(arguments, int*);
				  dbus_message_iter_get_basic(&replyIter, i);
				  std::cout << "Got " << *i << "\n";
			}
			else if (*it == 'u') {
				  std::cout << "Getting argument\n";
		          unsigned int* i = va_arg(arguments, unsigned int*);
				  std::cout << "Getting value from message\n";
		          dbus_message_iter_get_basic(&replyIter, i);
		          std::cout << "Got value: ";
				  std::cout << *i << "\n";
			}
			else if (*it == 's') {
	          char** s = va_arg(arguments, char**);
	          dbus_message_iter_get_basic(&replyIter, s);
			  std::cout << "Got '" << *s << "'\n";
			}
			else {
				std::cerr << "Signature type'" << out_signature << "' not known\n";
			}

	    }
	}
	else {
		std::cout << "Got error\n";
		std::cout << "Error name: " << error.name << "\n";
		std::cout << "Error message: " << error.message << "\n";
	}

	va_end(arguments);
	std::cout << "Leaving call\n";
    return true;
}

}
