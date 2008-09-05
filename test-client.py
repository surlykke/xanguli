#!/usr/bin/env python
import dbus

def getObject(bus, name, interface)
  o = bus.get_object('org.xanguli.Service', name)
  res = dbus.Interface(o, dbus_interface=interface)
  return res

bus = dbus.SessionBus()
manager = getObject(bus, '/Manager', 'org.xanguli.Manager')
print 'fik manager'

dbus.Interface(tmp, dbus_interface='org.xanguli.Session')

button_name = session.CreateTtkButton('top', {'text': 'hej'})
print 'button_name: ' + button_name
#tmp = bus.get_object('org.xanguli.TtkButton', button_name)
#button = dbus.Interface(tmp, dbus_interface='org.xanguli.TtkButton')
