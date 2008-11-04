#!/usr/bin/env python
import dbus

#def getObject(bus, name, interface)
#  res = dbus.Interface(o, interface)
#  return res

bus = dbus.SessionBus()
xanguliIntro = dbus.Interface(bus, '/Xanguli', 'org.freedesktop.DBus.Introspectable')
print xanguliIntro.introspect
xanguliXanguli = dbus.Interface(bus, '/Xanguli', 'org.xanguli.Xanguli')
print 'fik xanguli'

