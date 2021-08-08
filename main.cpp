#include <vector>
#include <cstdio>

template <typename T>
struct ForceSetupAndTearDown
{
    void doPerformAction()
    {
        static_cast<T*>(this)->setUp();
        static_cast<T*>(this)->performAction();
        static_cast<T*>(this)->tearDown();
    }
};

struct ForcedType final : public ForceSetupAndTearDown<ForcedType>
{
    void performAction() {
        std::puts(__FUNCSIG__);
    }
    void setUp() {
        std::puts(__FUNCSIG__);
    }
    void tearDown() {
        std::puts(__FUNCSIG__);
    }
};

int main()
{
    ForcedType ft;
    ft.doPerformAction();
    return 0;
}