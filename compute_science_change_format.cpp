#include "compute.h"
#include "checkstring.h"

void Compute::computeScience()
{
    long int nodePower = 1;
    double temp = 0.0;
    try {
        bool rightBracket = false;
        for (int i = 0; i < capacity; i++)
        {
            // "-" is handled specially
            // because it can be a negative number or a operator
            if ('2' == container[i][19] && '1' == container[i][20])
            {
                if (isNew)
                {
                    isNew = false;
                    nextNeg = true;
                }
                else
                {
                    // act as a normal two operands operator
                    isNew = true;
                    nextNeg = false;

                    if (rightBracket)
                    {
                        rightBracket = false;
                    }
                    else
                    {
                        storeOperandsStackScience.push(temp);
                        temp = 0.0;
                    }

                    if (changeFormatStackScience.isEmpty())
                        changeFormatStackScience.push(2);
                    else {
                        while (changeFormatStackScience.top() != BRACKET_LEFT &&
                               changeFormatStackScience.top() - OP_SUB > 10) {
                            int instruction = changeFormatStackScience.pop();
                            if (OP_MOD == instruction)
                            {
                                storeOperandsStackScience.push(
                                            R_computeForMode(
                                                int(storeOperandsStackScience.pop()),
                                                int(storeOperandsStackScience.pop())));
                            }
                            else
                            {
                                storeOperandsStackScience.push(
                                            R_computeScience(
                                                storeOperandsStackScience.pop(), storeOperandsStackScience.pop(), instruction));
                            }
                        }
                        changeFormatStackScience.push(OP_SUB);
                    }
                }
                nodePower = 1;
            }
            else if ('0' == container[i][19])
            {
                rightBracket = false;

                if (!nextNode)
                {
                    temp *= 10;
                    if (nextNeg)
                    {
                        if ('0' == container[i][20])
                            temp += 0;
                        else if ('1' == container[i][20])
                            temp += -1.0;
                        else if ('2' == container[i][20])
                            temp += -2.0;
                        else if ('3' == container[i][20])
                            temp += -3.0;
                        else if ('4' == container[i][20])
                            temp += -4.0;
                        else if ('5' == container[i][20])
                            temp += -5.0;
                        else if ('6' == container[i][20])
                            temp += -6.0;
                        else if ('7' == container[i][20])
                            temp += -7.0;
                        else if ('8' == container[i][20])
                            temp += -8.0;
                        else if ('9' == container[i][20])
                            temp += -9.0;
                    }
                    else
                    {
                        if ('0' == container[i][20])
                            temp += 0.0;
                        else if ('1' == container[i][20])
                            temp += 1.0;
                        else if ('2' == container[i][20])
                            temp += 2.0;
                        else if ('3' == container[i][20])
                            temp += 3.0;
                        else if ('4' == container[i][20])
                            temp += 4.0;
                        else if ('5' == container[i][20])
                            temp += 5.0;
                        else if ('6' == container[i][20])
                            temp += 6.0;
                        else if ('7' == container[i][20])
                            temp += 7.0;
                        else if ('8' == container[i][20])
                            temp += 8.0;
                        else if ('9' == container[i][20])
                            temp += 9.0;
                    }
                }
                else if (nextNode)
                {
                    nodePower *= 10;

                    if (nodePower > 10000000)
                        continue;

                    if (nextNeg)
                    {
                        if ('0' == container[i][20])
                            temp += 0.0;
                        else if ('1' == container[i][20])
                            temp += -1.0 / nodePower;
                        else if ('2' == container[i][20])
                            temp += -2.0 / nodePower;
                        else if ('3' == container[i][20])
                            temp += -3.0 / nodePower;
                        else if ('4' == container[i][20])
                            temp += -4.0 / nodePower;
                        else if ('5' == container[i][20])
                            temp += -5.0 / nodePower;
                        else if ('6' == container[i][20])
                            temp += -6.0 / nodePower;
                        else if ('7' == container[i][20])
                            temp += -7.0 / nodePower;
                        else if ('8' == container[i][20])
                            temp += -8.0 / nodePower;
                        else if ('9' == container[i][20])
                            temp += -9.0 / nodePower;
                    }
                    else
                    {
                        if ('0' == container[i][20])
                            temp += 0;
                        else if ('1' == container[i][20])
                            temp += 1.0 / nodePower;
                        else if ('2' == container[i][20])
                            temp += 2.0 / nodePower;
                        else if ('3' == container[i][20])
                            temp += 3.0 / nodePower;
                        else if ('4' == container[i][20])
                            temp += 4.0 / nodePower;
                        else if ('5' == container[i][20])
                            temp += 5.0 / nodePower;
                        else if ('6' == container[i][20])
                            temp += 6.0 / nodePower;
                        else if ('7' == container[i][20])
                            temp += 7.0 / nodePower;
                        else if ('8' == container[i][20])
                            temp += 8.0 / nodePower;
                        else if ('9' == container[i][20])
                            temp += 9.0 / nodePower;
                    }
                }

                isNew = false;
            }
            else if ('1' == container[i][19])
            {
                // attention that we shouldn`t push temp here
                // as 0 that is needn`t

                if ('0' == container[i][20])
                {
                    storeOperandsStackScience.push(2.17273747);
                }
                else if ('1' == container[i][20])
                {
                    storeOperandsStackScience.push(3.14159265);
                }

                nextNeg = false;
                nextNode = false;

                isNew = true;

                rightBracket = false;

                nodePower = 1;
            }
            else if (('2' == container[i][19] && '1' != container[i][20]) ||
                       ('3' == container[i][19] && '7' == container[i][20]))
            {
                if (rightBracket)
                {
                    rightBracket = false;
                }
                else
                {
                    storeOperandsStackScience.push(temp);
                    temp = 0.0;
                }

                // to set the prority
                int mark = -1;
                if ('2' == container[i][19])
                {
                    if ('0' == container[i][20])
                        mark = OP_ADD;
                    else if ('2' == container[i][20])
                        mark = OP_MUL;
                    else if ('3' == container[i][20])
                        mark = OP_DIV;
                    else if ('4' == container[i][20])
                        mark = OP_MOD;
                }
                else if ('3' == container[i][19])
                {
                    if ('7' == container[i][20])
                        mark = OP_POW;
                }

                if (changeFormatStackScience.isEmpty())
                    changeFormatStackScience.push(mark);
                else
                {
                    while (changeFormatStackScience.top() != BRACKET_LEFT &&
                           changeFormatStackScience.top() - mark > 10) {
                        int instruction = changeFormatStackScience.pop();
                        if (OP_MOD == instruction)
                        {
                            storeOperandsStackScience.push(
                                        R_computeForMode(
                                            int(storeOperandsStackScience.pop()),
                                            int(storeOperandsStackScience.pop())));
                        }
                        else
                        {
                            storeOperandsStackScience.push(
                                        R_computeScience(
                                            storeOperandsStackScience.pop(), storeOperandsStackScience.pop(), instruction));
                        }
                    }
                    changeFormatStackScience.push(mark);
                }

                nextNode = false;
                nextNeg = false;

                isNew = true;

                nodePower = 1;
            }
            else if ('9' == container[i][19])
            {
                if ('2' == container[i][20])
                {
                    // ( must not push temp
                    // because the thing before ( must be a operator which have pushed

                    // ( is 92
                    changeFormatStackScience.push(92);

                    rightBracket = false;

                    nextNeg = false;
                    nextNode = false;

                    isNew = true;
                }
                else if ('3' == container[i][20])
                {
                    if (rightBracket)
                    {
                        rightBracket = false;
                    }
                    else
                    {
                        storeOperandsStackScience.push(temp);
                        temp = 0.0;
                    }

                    while (changeFormatStackScience.top() != 92)
                    {
                        int instruction = changeFormatStackScience.pop();
                        if (OP_MOD == instruction)
                        {
                            storeOperandsStackScience.push(
                                        R_computeForMode(
                                            int(storeOperandsStackScience.pop()),
                                            int(storeOperandsStackScience.pop())));
                        }
                        else
                        {
                            storeOperandsStackScience.push(
                                        R_computeScience(
                                            storeOperandsStackScience.pop(), storeOperandsStackScience.pop(), instruction));
                        }
                    }

                    changeFormatStackScience.pop();

                    rightBracket = true;

                    nextNeg = false;
                    nextNode = false;

                    isNew = false;
                }
                else if ('4' == container[i][20])
                {
                    nextNode = true;
                    rightBracket = false;
                    isNew = false;
                }

                nodePower = 1;
            }
        }

        storeOperandsStackScience.push(R_computeScience(storeOperandsStackScience.pop(), type));

        emit resultScienceSender(package.getContainer(), makeTheSciencePackageToMessageGetter(true));
        fleshTextSender(resultString, false);
    }
    catch (QString error)
    {
        emit resultScienceSender(package.getContainer(), makeTheSciencePackageToMessageGetter(false));
        fleshTextSender(error, false);
    }
}

int Compute::makeTheSciencePackageToMessageGetter(bool isSuccess)
{
    tempPackage.clear();
    resultString.clear();

    int capacity = 0;
    if (isSuccess)
    {
        double result = storeOperandsStackScience.pop();

        if (result < 0)
        {
            // add the "-" at the first
            tempPackage.addRear("compute____science_21");
            resultString.append("-");

            // as a positive number
            result = -result;
            capacity = 1;
        }
        else if (0.00000001 > result)
        {
            package.addRear("compute____science_00");
            resultString.append("0");
            return 1;
        }

        // as a node number
        if (result - int(result) > 0.00000001)
        {
            int _result = int(result);
            int temp = _result % 10;

            for (; _result > 0; capacity++)
            {
                // the standard format is
                //                 pushButton_science_03
                tempPackage.addRear("compute____science_0");
                switch (temp)
                {
                case 0:
                    tempPackage[capacity].append("0");
                    break;
                case 1:
                    tempPackage[capacity].append("1");
                    break;
                case 2:
                    tempPackage[capacity].append("2");
                    break;
                case 3:
                    tempPackage[capacity].append("3");
                    break;
                case 4:
                    tempPackage[capacity].append("4");
                    break;
                case 5:
                    tempPackage[capacity].append("5");
                    break;
                case 6:
                    tempPackage[capacity].append("6");
                    break;
                case 7:
                    tempPackage[capacity].append("7");
                    break;
                case 8:
                    tempPackage[capacity].append("8");
                    break;
                case 9:
                    tempPackage[capacity].append("9");
                    break;
                }

                _result /= 10;
                temp = _result % 10;
            }

            for (int i = 0; i < capacity; i++)
            {
                package.addRear(tempPackage.top());
                resultString.append(tempPackage.top()[20]);
                tempPackage.deleteRear();
            }

            package.addRear("compute____science_94");
            resultString.append(".");

            _result = int(result);
            result -= _result;
            result *= 10;
            temp = int(result);

            int nodeLimit = 0;
            for ( ; result > 0.00000001; capacity++)
            {
                // the standard format is
                //                 pushButton_science_03
                package.addRear("compute____science_0");
                switch (temp)
                {
                case 0:
                    package[capacity].append("0");
                    resultString.append("0");
                    break;
                case 1:
                    package[capacity].append("1");
                    resultString.append("1");
                    break;
                case 2:
                    package[capacity].append("2");
                    resultString.append("2");
                    break;
                case 3:
                    package[capacity].append("3");
                    resultString.append("3");
                    break;
                case 4:
                    package[capacity].append("4");
                    resultString.append("4");
                    break;
                case 5:
                    package[capacity].append("5");
                    resultString.append("5");
                    break;
                case 6:
                    package[capacity].append("6");
                    resultString.append("6");
                    break;
                case 7:
                    package[capacity].append("7");
                    resultString.append("7");
                    break;
                case 8:
                    package[capacity].append("8");
                    resultString.append("8");
                    break;
                case 9:
                    package[capacity].append("9");
                    resultString.append("9");
                    break;
                }

                _result = int(result);
                result -= _result;
                result *= 10;
                temp = int(result);
                if (nodeLimit++ > 6)
                    break;
            }
        }
        // as a interge
        else
        {
            int _result = int(result);
            int temp = _result % 10;

            for (; _result > 0; capacity++)
            {
                // the standard format is
                //                 pushButton_science_03
                tempPackage.addRear("compute____science_0");
                switch (temp)
                {
                case 0:
                    tempPackage[capacity].append("0");
                    break;
                case 1:
                    tempPackage[capacity].append("1");
                    break;
                case 2:
                    tempPackage[capacity].append("2");
                    break;
                case 3:
                    tempPackage[capacity].append("3");
                    break;
                case 4:
                    tempPackage[capacity].append("4");
                    break;
                case 5:
                    tempPackage[capacity].append("5");
                    break;
                case 6:
                    tempPackage[capacity].append("6");
                    break;
                case 7:
                    tempPackage[capacity].append("7");
                    break;
                case 8:
                    tempPackage[capacity].append("8");
                    break;
                case 9:
                    tempPackage[capacity].append("9");
                    break;
                }

                _result /= 10;
                temp = _result % 10;
            }

            for (int i = 0; i < capacity; i++)
            {
                package.addRear(tempPackage.top());
                resultString.append(tempPackage.top()[20]);
                tempPackage.deleteRear();
            }
        }

        return capacity;
    }
    // if false set the CE to the messageGetter
    else
    {
        tempPackage.addRear("compute____science_90");
        return capacity;
    }
}
