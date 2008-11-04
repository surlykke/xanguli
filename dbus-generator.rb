#!/usr/bin/env ruby
require 'rexml/document'
require 'yaml'
require 'erb'

class Interface
  attr_accessor :xml, :name, :interface, :methods, :header_tag
end

class InterfaceMethod 
  attr_accessor :name, :parameters
  
  def in_parameters
    @parameters.find_all{|p| p.direction == :in}
  end
   
  def out_parameters
    @parameters.find_all{|p| p.direction == :out}
  end

  def parameter_list
    @parameters.map{|p| p.name}.join(", ")
  end
end

class MethodParameter
  attr_accessor :name, :type, :signature, :direction
end

Template = <<-EOS
// Autogenerated - don't touch!
#ifndef <%=klass.header_tag%>
#define <%=klass.header_tag%>
#include <iostream>
#include <string.h>
#include <string> 
#include <vector>
#include <map>
#include "Variant.h"
#include "dbus/dbus.h"
#include "DBusInterface.h"
#include "Marshall.h"

namespace <%=@namespace%> {
  template<class impl> 
  class <%=klass.name%> : public DBusInterface {
  private:
% klass.methods.each do |method|
    DBusMessage* handleCall_<%=method.name%>(DBusMessage* message) {
      std::cout << "Ind i <%=method.name%>\\n";
%     method.parameters.each do |p|
      <%=p.type%> <%=p.name%>;
%     end
%     if method.in_parameters.size > 0
%     puts method.name + ": " + method.in_parameters.size.to_s
      DBusMessageIter inIter;
      dbus_message_iter_init(message, &inIter);
%     method.in_parameters.each do |p|
      marshall<<%=p.type%>>(&inIter, <%=p.name%>);
      std::cout << "Getting " << <%=p.name%> << " from message \\n"; 
      dbus_message_iter_next(&inIter);
%     end
%     end
      
      obj-><%=method.name%>(<%= method.parameter_list%>); 
      DBusMessage* reply = dbus_message_new_method_return(message);

%     if method.out_parameters.size > 0
      DBusMessageIter outIter;
      dbus_message_iter_init_append(reply, &outIter); 
%     method.out_parameters.each do |p|
      std::cout << "Puttin " << <%=p.name%> << " on reply\\n";
      deMarshall(&outIter, <%=p.name%>);
%     end      
%     end
      return reply; 
    };

% end
    impl* obj;
  public:
    <%=klass.name%>(impl* obj){
      this->obj = obj;
      this->xml = 
%     klass.xml.split("\\n").each do |line|
        <%=(line + "\\n").inspect%>
%     end
	;
    };

    virtual DBusMessage* handleCall(DBusMessage* message) {
      const char* methodName = dbus_message_get_member(message);
%   klass.methods.each do |method|
      if (strcmp("<%= method.name %>", methodName) == 0)  {
        return handleCall_<%= method.name %>(message);
      } 
      else
%   end
        return dbus_message_new_error(message, DBUS_ERROR_FAILED, "No such method"); 
    };

    std::string GetInterfaceName() {
      return <%=klass.interface.inspect%>; 
    };
  };
}
#endif /* <%=klass.header_tag%> */
EOS

class DBusGenerator
  def initialize
    parse_options
    klass = parse_xml
    puts "Writing: " + klass.name + ".h" 
    File.open(klass.name + ".h", "w+") do |f|
      f.write(ERB.new(Template, nil, "%<>").result(binding))
    end
  end

  def parse_options 
    require 'optparse'
    h = {:namespace=>""}
    opts = OptionParser.new
    opts.on("-n", 
            "--namespace=NAMESPACE", 
            String, 
            "Namespace for the interface class") {|v| h[:namespace] = v}
    opts.on("-i", 
            "--interface=INTERFACE",
            String,
            "Implemented interface") {|v| h[:interface] = v}
    opts.parse!(ARGV)
    if h[:interface] == nil or ARGV.size > 0
      puts opts.to_s
      exit(1)
    end
    @interface_file, @namespace = h[:interface], h[:namespace]
  end
 
  def parse_xml
    doc =  REXML::Document.new(File.open(@interface_file + '.xml')).root
    interface = Interface.new
    interface.xml = doc.root.to_s 
    interface.interface = doc.root.attributes['name'] 
    interface.name = doc.root.attributes['name'].gsub(/\./, "_") 
    interface.header_tag = interface.name.upcase + "_H_" 
    interface.methods = doc.elements.find_all {|el| el.name = 'method'}.map{|m| method(m)}
    return interface
  end

  def method(element)
    m = InterfaceMethod.new
    m.name = element.attributes['name']
    m.parameters = element.elements.find_all {|e| e.name = 'arg'}.map {|e| parameter(e)}
    return m 
  end

  def parameter(element)
    param =  MethodParameter.new
    param.name = "v_" + element.attributes['name']
    param.signature = element.attributes['type']
    param.direction = (element.attributes['direction'] == 'out' ? :out : :in)
    param.type = type(param.signature)
    return param 
  end

  CTypeMap = {"u" => "unsigned int",
              "i" => "int",
	      "s" => "char*"};


  TypeMap = {"u" => "unsigned int",
             "i" => "int",
             "s" => "std::string",
             "v" => "Variant"};

  def type(sig) 
    if m = /^[uisv]$/.match(sig)
      TypeMap[sig]
    elsif m = /^a([uisv])$/.match(sig)
      "std::vector<#{TypeMap[m[1]]}>"
    elsif m = /^a\{([uis])([uisv])\}/.match(sig)
      "std::map<#{TypeMap[m[1]]}, #{TypeMap[m[2]]}>"
    end
  end

  def methodCall(m)
    methodName = m.attributes['name'] 
    typeinfo = get_typeinfo(m) 
    
    <<-EOS.pp(binding)
   EOS
  end

end

DBusGenerator.new
 
