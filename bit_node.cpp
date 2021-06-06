#include "meta_binary_container.h"
#include "bit_node.h"
#include "pool.h"
#include "global.h"

bitNode::bitNode(bitNode const& source)
{
    nodeIndex = source.nodeIndex;
    metaBit* temp = chainHead;

    bool ini = true;

    // here use the i->next because have allocated once before
    for (metaBit* i = source.chainHead; i != nullptr; i = i->next)
    {
        temp = chainRear;

        chainRear = Pool::getInstance()->getRelax();

        chainRear->bit = i->bit;

        if (!ini)
        {
            temp->next = chainRear;
            chainRear->father = temp;
        }

        if (ini)
        {
            chainHead = chainRear;
            ini = false;
        }
    }
}

bitNode const& bitNode::operator=(bitNode const& source)
{
    if (this == &source)
        return *this;
    else
    {
        nodeIndex = source.nodeIndex;
        metaBit* temp = chainHead;

        bool ini = true;

        // here use the i->next because have allocated once before
        for (metaBit* i = source.chainHead; i != nullptr; i = i->next)
        {
            temp = chainRear;

            chainRear = Pool::getInstance()->getRelax();

            chainRear->bit = i->bit;

            if (!ini)
            {
                temp->next = chainRear;
                chainRear->father = temp;
            }


            if (ini)
            {
                chainHead = chainRear;
                ini = false;
            }
        }

        return *this;
    }
}

bitNode::~bitNode()
{
    for (metaBit* i = chainHead; i != nullptr; i = i->next)
    {
        Pool::getInstance()->sendBackToPool(i->index);
    }
}
