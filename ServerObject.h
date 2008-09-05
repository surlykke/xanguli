/*
 * ServerObject.h
 *
 *  Created on: 26-08-2008
 *      Author: cpet2308
 */
#ifndef SERVEROBJECT_H_
#define SERVEROBJECT_H_

#include "dbus-types.h"
#include <string>

namespace Xanguli {

class ServerObject {
public:
	ServerObject(dbus_string dbusId);
	virtual ~ServerObject();
	void lose(std::string str);
	dbus_string getDbusId();

private:
	dbus_string dbusId;
};

}
#endif /* SERVEROBJECT_H_ */
