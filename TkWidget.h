/*
 * TkWidget.h
 *
 *  Created on: 26-08-2008
 *      Author: cpet2308
 */
#ifndef TKWIDGET_H_
#define TKWIDGET_H_

#include "ServerObject.h"
#include "dbus-types.h"

namespace Xanguli {

class TkWidget : public ServerObject
{
public:
	TkWidget(dbus_string dbusId);
    void pack(); // Fixme
};

}
#endif
