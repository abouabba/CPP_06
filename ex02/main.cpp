# include "Base.hpp"


int main()
{
    std::srand(std::time(NULL));

    Base base;
    Base* obj = base.generate();

    base.identify(obj);
    base.identify(*obj);

    delete obj;
}