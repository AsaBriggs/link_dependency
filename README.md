Trivial C++ component to perform link-time checking of dependencies being satisfied.

The library deals with dependencies in the form of tags; if software wants link-time checking of a dependency then a tag is created to represent the dependency, users of the dependency create objects of type link_dep::Declare<TheTagType> and the component that satisfies the dependency creates an object of type link_dep::Define<TheTagType>.

It is vital that users agree on unique tags for their domain, not just relying on fundamental types. The tags don't have to be complete types as they are used in name alone.

For instance, in a common header file plugin.h

'''cpp
namespace PluginTags {
struct WidgetTag;
}

namespace Plugin {
struct IPlugin { virtual ~IPlugin() {} };
}
'''

The user of the widget does
'''cpp
#include "plugin.h"
#include "link_dependency.h"

void useWidget()
{
  link_dep::Declare<PluginTags::WidgetTag> check;
  // Now do soemthing to get and use a widget
}
'''

and the component that satisfies the widget dependency does

'''cpp
#include "plugin.h"
#include "link_dependency.h"

namespace PluginImpl {
struct Widget : IPlugin
{
    virtual ~Widget()
    {
        link_dep::Define<PluginTags::WidgetTag> def;
    }
};
}
'''

Also see main.cpp for the test. compile with macro TRIGGER_LINK_FAILURE to trigger a link-time failure.