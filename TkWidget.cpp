#include "TkWidget.h"
#include <iostream>

namespace Xanguli {

TkWidget::TkWidget(dbus_string dbusId) : ServerObject(dbusId)
{
	// TODO
}

void pack()
{
  std::cout << "Ind i tk_widget_pack..\n";
}

}
