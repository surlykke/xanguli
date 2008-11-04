#!/usr/bin/env ruby
require 'dbus'
bus = DBus::SessionBus.instance
xanguli_Service = bus.service('org.xanguli.Service')
obj = xanguli_Service.object('/Xanguli')
obj.introspect
introspectable = obj['org.freedesktop.DBus.Introspectable']
puts "Introspect:\n" + introspectable.Introspect[0]
xanguli = obj['org.xanguli.Xanguli']
puts "CreateController:\n" + xanguli.CreateController[0]

