#ifndef POOL_H
#define POOL_H

#include "bit_node.h"

#define     POOL_BASIC_CAPACITY     64

class Pool
{
public:
    static Pool* getInstance(void)
    {
        static Pool* _instance_;

        return _instance_;
    }

    static metaBit* getRelax();
    static void sendBackToPool(long int index);

    static bool isOccupted(long int index);

    Pool(Pool const&) = delete;
    Pool(Pool&&) = delete;
    Pool const& operator=(Pool const&) = delete;
    Pool const& operator=(Pool&&) = delete;

private:
    static bool extand(void);

    static metaBit* elements;
    static bool* busy;

    static int currentCapacity;
    static int maxCapacity;

    static int times;

    // i can`t implement pool with template
    // because of mine poor
    Pool() {}


};

#endif // POOL_H
