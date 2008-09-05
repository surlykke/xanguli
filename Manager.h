/*
 * XanguliManager.h
 *
 *  Created on: 26-08-2008
 *      Author: cpet2308
 */
#ifndef MANAGER_H_
#define MANAGER_H_

#include "TkWidget.h"
#include "dbus-types.h"

namespace Xanguli {

class Manager {
  public:
	  static Manager* instance();

    /**
      * dbus-method:
      *   dbus-name: createController
      *   args:
      *   - name: id
      *     type: s
      *     direction:
      *     doc:  The dbus-id of the created Controller
      *   doc: Creates a new controller instance
      */
    void createController(dbus_string &controllerId);

    void registerObject(ServerObject* obj);

  private:
    Manager();
    static Manager* managerInstance;
};

}
#endif
