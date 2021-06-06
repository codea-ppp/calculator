#include "meta_binary_container.h"

QString MetaBinaryContainer::getBinary()
{
    QString temp;

    if (isNegative)
        temp.append('-');

    for (metaBit* i = container.chainHead; i != nullptr; i = i->next)
    {
        if (i->bit)
            temp.append('1');
        else
            temp.append('0');
    }

    return temp;
}

QString MetaBinaryContainer::getOctal()
{
    QString temp;

    if (isNegative)
        temp.append('-');

    int octalNumber = 0;
    int isThree = 0;
    for (metaBit* i = container.chainHead; i != nullptr; i = i->next)
    {
        int nodeCount = 0;
        if (container.nodeIndex == ++nodeCount)
        {
            temp.append('.');
        }
        else if (3 == isThree)
        {
            isThree = 0;

            switch (octalNumber)
            {
            case 0: temp.append('0'); break;
            case 1: temp.append('1'); break;
            case 2: temp.append('2'); break;
            case 3: temp.append('3'); break;
            case 4: temp.append('4'); break;
            case 5: temp.append('5'); break;
            case 6: temp.append('6'); break;
            case 7: temp.append('7'); break;
            }

            octalNumber = 0;
        }

        octalNumber *= 2;
        if (i->bit)
            octalNumber += 1;

        isThree++;
    }

    // deal with the last number
    if (isThree != 3)
    {
        switch (octalNumber)
        {
        case 0: temp.append('0'); break;
        case 1: temp.append('1'); break;
        case 2: temp.append('2'); break;
        case 3: temp.append('3'); break;
        case 4: temp.append('4'); break;
        case 5: temp.append('5'); break;
        case 6: temp.append('6'); break;
        case 7: temp.append('7'); break;
        }
    }

    return temp;
}

QString MetaBinaryContainer::getHexadecimal()
{
    QString temp;

    if (isNegative)
        temp.append('-');

    int hexadecimalNumber = 0;
    int isSixteen = 0;

    if (container.nodeIndex == -1)
    {
        for (metaBit* i = container.chainHead; i != nullptr; i = i->next)
        {
            if (4 == isSixteen)
            {
                isSixteen = 0;

                switch (hexadecimalNumber)
                {
                case 0: temp.append('0'); break;
                case 1: temp.append('1'); break;
                case 2: temp.append('2'); break;
                case 3: temp.append('3'); break;
                case 4: temp.append('4'); break;
                case 5: temp.append('5'); break;
                case 6: temp.append('6'); break;
                case 7: temp.append('7'); break;
                case 8: temp.append('8'); break;
                case 9: temp.append('9'); break;
                case 10: temp.append('A'); break;
                case 11: temp.append('B'); break;
                case 12: temp.append('C'); break;
                case 13: temp.append('D'); break;
                case 14: temp.append('E'); break;
                case 15: temp.append('F'); break;
                }

                hexadecimalNumber = 0;
            }

            hexadecimalNumber *= 2;
            if (i->bit)
                hexadecimalNumber += 1;

            isSixteen++;
        }

        // deal with the last number
        if (isSixteen != 4)
        {
            switch (hexadecimalNumber)
            {
            case 0: temp.append('0'); break;
            case 1: temp.append('1'); break;
            case 2: temp.append('2'); break;
            case 3: temp.append('3'); break;
            case 4: temp.append('4'); break;
            case 5: temp.append('5'); break;
            case 6: temp.append('6'); break;
            case 7: temp.append('7'); break;
            case 8: temp.append('8'); break;
            case 9: temp.append('9'); break;
            case 10: temp.append('A'); break;
            case 11: temp.append('B'); break;
            case 12: temp.append('C'); break;
            case 13: temp.append('D'); break;
            case 14: temp.append('E'); break;
            case 15: temp.append('F'); break;
            }
        }
    }
    else
    {
        metaBit* i = container.chainHead;
        for (int nodeCount = 0; nodeCount < container.nodeIndex; nodeCount++)
        {

        }
    }

    return temp;
}

double MetaBinaryContainer::getDecimal()
{
    double decimalNumber = 0.0;

    metaBit* i = container.chainHead;
    if (container.nodeIndex == -1)
    {
        for ( ; i != nullptr; i = i->next)
        {
            decimalNumber *= 2.0;
            if (i->bit)
                decimalNumber += 1.0;
        }
    }
    else
    {
        // node part
        for (int index = 0; index < container.nodeIndex; index++)
        {
            decimalNumber /= 2;
            if (i->bit)
                decimalNumber += 0.5;  /* [1 / 2] */
            i = i->next;
        }
        // interge part
        for (int index = container.nodeIndex; index < capacity; i++)
        {
            decimalNumber *= 2.0;
            if (i->bit)
                decimalNumber += 1.0;
            i = i->next;
        }
    }

    if (isNegative)
        decimalNumber = -decimalNumber;

    return decimalNumber;
}
