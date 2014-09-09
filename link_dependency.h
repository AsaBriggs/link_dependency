#ifndef INCLUDED_LINK_DEPENDENCY
#define INCLUDED_LINK_DEPENDENCY

namespace link_dep {

template<typename Tag>
struct Define;

template<typename Tag>
struct Declare
{
    friend __attribute__((__noinline__))
    void check(Declare<Tag>*, Define<Tag>*);

    ~Declare() { check(this, 0); }
};

template<typename Tag>
struct Define
{
    friend __attribute__((__noinline__))
    void check(Declare<Tag>*, Define<Tag>*) {}

    ~Define() { check(0, this); }
};

} // namespace link_dep

#endif
