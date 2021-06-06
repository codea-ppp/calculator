#include "meta_binary_container.h"
#include "new"

MetaBinaryContainer::MetaBinaryContainer()
{
    capacity = 0;
    isNegative = false;
}

MetaBinaryContainer::MetaBinaryContainer(double n)
{
    capacity = 0;
    isNegative = false;

    if (!int(n))
    {
        container.chainHead = container.chainRear = Pool::getInstance()->getRelax();
    }
    else
        setContainer(n);
}
