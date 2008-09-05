cmake_minimum_required(VERSION 2.6)
project(Xanguli)
add_executable(xanguli xanguli.cpp TtkButton.cpp TkWidget.cpp Controller.cpp IdGenerator.cpp DBusProxy.cpp ServerObject.cpp Manager.cpp DBusConnection.cpp) 
include_directories(/usr/include/dbus-1.0 /usr/lib/dbus-1.0/include)
target_link_libraries(xanguli libtcl8.5.so libtk8.5.so)

