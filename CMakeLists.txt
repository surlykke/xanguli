cmake_minimum_required(VERSION 2.6)
project(Xanguli)

add_executable(xanguli
               Xanguli.cpp
               TkWidget.cpp
               Controller.cpp
               IdGenerator.cpp
               DBusProxy.cpp
               DBusInterface.cpp
               XanguliException.cpp
               ServerObject.cpp)

add_executable(test-client
               test-client.c)

include_directories(/usr/include
                    /usr/include/tcl8.5 
                    /usr/include/dbus-1.0 
                    /usr/lib/dbus-1.0/include 
                    /usr/include/c++/4.3
                    /usr/include/dbus-1.0
                    /usr/include/glib-2.0
                    /usr/lib/glib-2.0/include)

target_link_libraries(xanguli libtcl8.5.so libtk8.5.so libdbus-1.so)
target_link_libraries(test-client libdbus-glib-1.so)
