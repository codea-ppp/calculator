#include "meta_binary_container.h"

QString MetaBinaryContainer::getBinary() const
{
    QString temp;

    if (container.nodeIndex == -1)
    {
        for (metaBit* i = container.chainHead; i != nullptr; i = i->next)
        {
            if (i->bit)
                temp.insert(0, '1');
            else
                temp.insert(0, '0');
        }
    }
    else
    {
        metaBit* nodeLocate = container.chainHead;
        for (int nodeCount = 0; nodeCount < container.nodeIndex; nodeCount++)
        {
            nodeLocate = nodeLocate->next;
        }

        temp.append('.');

        // node part
        for (metaBit* i = nodeLocate; i != nullptr; i = i->father)
        {
            if (i->bit)
                temp.append('1');
            else
                temp.append('0');
        }
        // interge part
        for (metaBit* i = nodeLocate; i != nullptr; i = i->next)
        {
            if (i->bit)
                temp.insert(0, '1');
            else
                temp.insert(0, '0');
        }
    }

    if (isNegative)
        temp.insert(0, '-');

    return temp;
}

QString MetaBinaryContainer::getOctal() const
{
    QString temp;

    int octalNumber = 0;
    int isThree = 0;

    if (container.nodeIndex == -1)
    {
        double power = 1;
        for (metaBit* i = container.chainHead; i != nullptr; i = i->next)
        {
            if (i->bit)
                octalNumber += 1 * power;
            power *= 2;

            if (3 == ++isThree)
            {
                switch (octalNumber)
                {
                case 0: temp.insert(0, '0'); break;
                case 1: temp.insert(0, '1'); break;
                case 2: temp.insert(0, '2'); break;
                case 3: temp.insert(0, '3'); break;
                case 4: temp.insert(0, '4'); break;
                case 5: temp.insert(0, '5'); break;
                case 6: temp.insert(0, '6'); break;
                case 7: temp.insert(0, '7'); break;
                }

                octalNumber = 0;
                isThree = 0;
                power = 1.0;
            }            
        }

        // deal with the last number
        if (isThree != 0)
        {
            switch (octalNumber)
            {
            case 0: temp.insert(0, '0'); break;
            case 1: temp.insert(0, '1'); break;
            case 2: temp.insert(0, '2'); break;
            case 3: temp.insert(0, '3'); break;
            case 4: temp.insert(0, '4'); break;
            case 5: temp.insert(0, '5'); break;
            case 6: temp.insert(0, '6'); break;
            case 7: temp.insert(0, '7'); break;
            }
        }
    }
    else
    {
        metaBit* nodeLocate = container.chainHead;
        for (int nodeCount = 0; nodeCount < container.nodeIndex; nodeCount++)
        {
            nodeLocate = nodeLocate->next;
        }

        temp.append('.');

        double power = 1.0;

        // node part
        for (metaBit* i = nodeLocate; i != nullptr; i = i->father)
        {
            power /= 2;
            if (i->bit)
                octalNumber += 1 * power;

            if (3 == ++isThree)
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

                octalNumber = 0;
                power = 1.0;
                isThree = 0;
            }


        }
        // deal with the last number
        if (isThree != 0)
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
        // interge part
        for (metaBit* i = nodeLocate; i != nullptr; i = i->next)
        {
            if (i->bit)
                octalNumber += 1 * power;
            power *= 2.0;

            if (3 == ++isThree)
            {
                switch (octalNumber)
                {
                case 0: temp.insert(0, '0'); break;
                case 1: temp.insert(0, '1'); break;
                case 2: temp.insert(0, '2'); break;
                case 3: temp.insert(0, '3'); break;
                case 4: temp.insert(0, '4'); break;
                case 5: temp.insert(0, '5'); break;
                case 6: temp.insert(0, '6'); break;
                case 7: temp.insert(0, '7'); break;
                }

                octalNumber = 0;
                isThree = 0;
                power = 1.0;
            }
        }
        // deal with the last number
        if (isThree != 0)
        {
            switch (octalNumber)
            {
            case 0: temp.insert(0, '0'); break;
            case 1: temp.insert(0, '1'); break;
            case 2: temp.insert(0, '2'); break;
            case 3: temp.insert(0, '3'); break;
            case 4: temp.insert(0, '4'); break;
            case 5: temp.insert(0, '5'); break;
            case 6: temp.insert(0, '6'); break;
            case 7: temp.insert(0, '7'); break;
            }
        }
    }

    if (isNegative)
        temp.insert(0, '-');

    return temp;
}

QString MetaBinaryContainer::getHexadecimal() const
{
    QString temp;

    int hexadecimalNumber = 0;
    int isFour = 0;

    if (container.nodeIndex == -1)
    {
        int power = 1;
        for (metaBit* i = container.chainHead; i != nullptr; i = i->next)
        {
            if (i->bit)
                hexadecimalNumber += 1 * power;
            power *= 2;

            if (4 == ++isFour)
            {
                isFour = 0;

                switch (hexadecimalNumber)
                {
                case 0: temp.insert(0, '0'); break;
                case 1: temp.insert(0, '1'); break;
                case 2: temp.insert(0, '2'); break;
                case 3: temp.insert(0, '3'); break;
                case 4: temp.insert(0, '4'); break;
                case 5: temp.insert(0, '5'); break;
                case 6: temp.insert(0, '6'); break;
                case 7: temp.insert(0, '7'); break;
                case 8: temp.insert(0, '8'); break;
                case 9: temp.insert(0, '9'); break;
                case 10: temp.insert(0, 'A'); break;
                case 11: temp.insert(0, 'B'); break;
                case 12: temp.insert(0, 'C'); break;
                case 13: temp.insert(0, 'D'); break;
                case 14: temp.insert(0, 'E'); break;
                case 15: temp.insert(0, 'F'); break;
                }

                power = 1;
                hexadecimalNumber = 0;
                isFour = 0;
            }
        }

        // deal with the last number
        if (isFour != 0)
        {
            switch (hexadecimalNumber)
            {
            case 0: temp.insert(0, '0'); break;
            case 1: temp.insert(0, '1'); break;
            case 2: temp.insert(0, '2'); break;
            case 3: temp.insert(0, '3'); break;
            case 4: temp.insert(0, '4'); break;
            case 5: temp.insert(0, '5'); break;
            case 6: temp.insert(0, '6'); break;
            case 7: temp.insert(0, '7'); break;
            case 8: temp.insert(0, '8'); break;
            case 9: temp.insert(0, '9'); break;
            case 10: temp.insert(0, 'A'); break;
            case 11: temp.insert(0, 'B'); break;
            case 12: temp.insert(0, 'C'); break;
            case 13: temp.insert(0, 'D'); break;
            case 14: temp.insert(0, 'E'); break;
            case 15: temp.insert(0, 'F'); break;
            }
        }
    }
    else
    {
        metaBit* nodeLocate = container.chainHead;
        for (int nodeCount = 0; nodeCount < container.nodeIndex; nodeCount++)
        {
            nodeLocate = nodeLocate->next;
        }
        temp.append('.');

        double power = 1.0;

        // node part
        for (metaBit* i = nodeLocate; i != nullptr; i = i->father)
        {
            power /= 2;
            if (i->bit)
                hexadecimalNumber += 1 * power;

            if (4 == ++isFour)
            {
                isFour = 0;

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
                power = 1.0;
                isFour = 0;
            }
        }
        // deal with the last number
        if (isFour != 0)
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

        // interge part
        for (metaBit* i = nodeLocate; i != nullptr; i = i->next)
        {
            if (i->bit)
                hexadecimalNumber += 1 * power;
            power *= 2;

            if (4 == ++isFour)
            {
                switch (hexadecimalNumber)
                {
                case 0: temp.insert(0, '0'); break;
                case 1: temp.insert(0, '1'); break;
                case 2: temp.insert(0, '2'); break;
                case 3: temp.insert(0, '3'); break;
                case 4: temp.insert(0, '4'); break;
                case 5: temp.insert(0, '5'); break;
                case 6: temp.insert(0, '6'); break;
                case 7: temp.insert(0, '7'); break;
                case 8: temp.insert(0, '8'); break;
                case 9: temp.insert(0, '9'); break;
                case 10: temp.insert(0, 'A'); break;
                case 11: temp.insert(0, 'B'); break;
                case 12: temp.insert(0, 'C'); break;
                case 13: temp.insert(0, 'D'); break;
                case 14: temp.insert(0, 'E'); break;
                case 15: temp.insert(0, 'F'); break;
                }

                power = 1;
                hexadecimalNumber = 0;
                isFour = 0;
            }
        }
        // deal with the last number
        if (isFour != 0)
        {
            switch (hexadecimalNumber)
            {
            case 0: temp.insert(0, '0'); break;
            case 1: temp.insert(0, '1'); break;
            case 2: temp.insert(0, '2'); break;
            case 3: temp.insert(0, '3'); break;
            case 4: temp.insert(0, '4'); break;
            case 5: temp.insert(0, '5'); break;
            case 6: temp.insert(0, '6'); break;
            case 7: temp.insert(0, '7'); break;
            case 8: temp.insert(0, '8'); break;
            case 9: temp.insert(0, '9'); break;
            case 10: temp.insert(0, 'A'); break;
            case 11: temp.insert(0, 'B'); break;
            case 12: temp.insert(0, 'C'); break;
            case 13: temp.insert(0, 'D'); break;
            case 14: temp.insert(0, 'E'); break;
            case 15: temp.insert(0, 'F'); break;
            }
        }
    }

    if (isNegative)
        temp.insert(0, '-');

    return temp;
}

double MetaBinaryContainer::getDecimal() const
{
    double decimalNumber = 0.0;

    metaBit* i = container.chainRear;
    if (container.nodeIndex == -1)
    {
        for ( ; i != nullptr; i = i->father)
        {
            decimalNumber *= 2.0;
            if (i->bit)
                decimalNumber += 1.0;
        }
    }
    else
    {
        // interge part
        for (int index = 0; index < capacity - container.nodeIndex; i++)
        {
            decimalNumber *= 2.0;
            if (i->bit)
                decimalNumber += 1.0;
            i = i->father;
        }

        // node part
        i = container.chainHead;
        for (int index = 0; index < container.nodeIndex; index++)
        {
            decimalNumber /= 2;
            if (i->bit)
                decimalNumber += 0.5;  /* [1 / 2] */
            i = i->next;
        }
    }

    if (isNegative)
        decimalNumber = -decimalNumber;

    return decimalNumber;
}
