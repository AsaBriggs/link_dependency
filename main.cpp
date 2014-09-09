#include "link_dependency.h"

namespace link_dep {
namespace {
struct aTag {};
struct aTag2 {};

Declare<aTag> t;
Define<aTag> t1;

#ifdef TRIGGER_LINK_FAILURE
Declare<aTag2> t2;
#endif

} // unnamed namespace
} // namespace link_dependency

int main () {}
