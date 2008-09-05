/*
 * DBusConnection.h
 *
 *  Created on: 29-08-2008
 *      Author: cpet2308
 */

#ifndef DBUSCONNECTION_H_
#define DBUSCONNECTION_H_
#include <string>

namespace Xanguli {

class DBusConnection {
public:
	static DBusConnection SessionBus();
	static DBusConnection SystemBus();
	DBusConnection(std::string path);
	virtual ~DBusConnection();
	void mainLoop();

private:
	std::string path;
};

}

#endif /* DBUSCONNECTION_H_ */
