#!/usr/bin/env ruby
require 'dbus'
bus = DBus::SessionBus.instance
Xanguli_Service = bus.service('org.xanguli.Service')

def object(name, interface)
  puts "Ind i object: name = #{name}, interface = #{interface}"
  tmp = Xanguli_Service.object(name)
  tmp.introspect 
  puts tmp[interface].methods.inspect
  puts tmp["org.freedesktop.DBus.Introspectable"].Introspect
  tmp[interface]
end

Manager = object('/Manager', 'org.xanguli.Manager')

controller = object(Manager.create_controller[0], 'org.xanguli.Controller')
button_path = controller.create_ttk_button('', {"text"=>"knap"}) 
button = object(button_path[0], 'org.xanguli.TtkButton')
puts "Got button"
button.text("Fra Ruby");
button.command("rubyKommando");
button.pack
puts "Did pack - starting mainloop"
controller.tk_mainloop


