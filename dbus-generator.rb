#!/usr/bin/env ruby
require 'rexml/document'


def method-declarations(doc)
  doc.root.elements.find_all {|el| el.name == 'mapping'}.map do |el|
<<-EOS
EOS

def dbustypes2ctypes(dbustypes)
  # TODO
end


doc = REXML::Document.new($stdin)
puts <<-EOF
namespace xanguli::containers {
  class #{doc.root.attributes['class']}_container : public XanguliContainer 
  {
 }
}
EOF
