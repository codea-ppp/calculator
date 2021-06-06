#include "compute.h"
#include "checkstring.h"

void Compute::computeProgram()
{
    long int nodePower = 1;
    double temp = 0.0;

    int power = 0;
    switch (status)
    {
    case Binary: power = 2; break;
    case Octal: power = 8; break;
    case Hexadecimal: power = 16; break;
    }

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
                        storeOperandsStackProgram.push(temp);
                        temp = 0.0;
                    }

                    if (changeFormatStackProgram.isEmpty())
                        changeFormatStackProgram.push(2);
                    else {
                        while (changeFormatStackProgram.top() != BRACKET_LEFT &&
                               changeFormatStackProgram.top() - OP_SUB > 10) {
                            int instruction = changeFormatStackProgram.pop();
                            if (OP_MOD == instruction)
                            {
                                storeOperandsStackProgram.push(
                                            R_computeForMode(
                                                int(storeOperandsStackProgram.pop().getDecimal()),
                                                int(storeOperandsStackProgram.pop().getDecimal())));
                            }
                            else
                            {
                                MetaBinaryContainer op1 = storeOperandsStackProgram.pop();
                                MetaBinaryContainer op2 = storeOperandsStackProgram.pop();
                                MetaBinaryContainer computeResult = R_computeProgram(op1, op2, instruction);
                                storeOperandsStackProgram.push(computeResult);
                            }
                        }
                        changeFormatStackProgram.push(OP_SUB);
                    }
                }
                nodePower = 1;
            }
            else if ('0' == container[i][19])
            {
                rightBracket = false;

                if (!nextNode)
                {
                    temp *= power;
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
                    nodePower *= power;

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
                rightBracket = false;

                if (!nextNode)
                {
                    temp *= power;
                    if (nextNeg)
                    {
                        if ('0' == container[i][20])
                            temp += -10.0;
                        else if ('1' == container[i][20])
                            temp += -11.0;
                        else if ('2' == container[i][20])
                            temp += -12.0;
                        else if ('3' == container[i][20])
                            temp += -13.0;
                        else if ('4' == container[i][20])
                            temp += -14.0;
                        else if ('5' == container[i][20])
                            temp += -15.0;
                    }
                    else
                    {
                        if ('0' == container[i][20])
                            temp += 10.0;
                        else if ('1' == container[i][20])
                            temp += 11.0;
                        else if ('2' == container[i][20])
                            temp += 12.0;
                        else if ('3' == container[i][20])
                            temp += 13.0;
                        else if ('4' == container[i][20])
                            temp += 14.0;
                        else if ('5' == container[i][20])
                            temp += 15.0;
                    }
                }
                else if (nextNode)
                {
                    nodePower *= power;

                    if (nodePower > 10000000)
                        continue;

                    if (nextNeg)
                    {
                        if ('0' == container[i][20])
                            temp += -10.0;
                        else if ('1' == container[i][20])
                            temp += -11.0 / nodePower;
                        else if ('2' == container[i][20])
                            temp += -12.0 / nodePower;
                        else if ('3' == container[i][20])
                            temp += -13.0 / nodePower;
                        else if ('4' == container[i][20])
                            temp += -14.0 / nodePower;
                        else if ('5' == container[i][20])
                            temp += -15.0 / nodePower;
                    }
                    else
                    {
                        if ('0' == container[i][20])
                            temp += 10.0;
                        else if ('1' == container[i][20])
                            temp += 11.0 / nodePower;
                        else if ('2' == container[i][20])
                            temp += 12.0 / nodePower;
                        else if ('3' == container[i][20])
                            temp += 13.0 / nodePower;
                        else if ('4' == container[i][20])
                            temp += 14.0 / nodePower;
                        else if ('5' == container[i][20])
                            temp += 15.0 / nodePower;
                    }
                }

                isNew = false;
            }
            else if (('2' == container[i][19] && '1' != container[i][20]) ||
                       ('3' == container[i][19] &&
                        ('0' == container[i][20] || '1' == container[i][20] || '2' == container[i][20])))
            {
                if (rightBracket)
                {
                    rightBracket = false;
                }
                else
                {
                    storeOperandsStackProgram.push(temp);
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
                    if ('0' == container[i][20])
                        mark = OP_AND;
                    else if ('1' == container[i][20])
                        mark = OP_OR;
                    else if ('2' == container[i][20])
                        mark = OP_XOR;
                }

                if (changeFormatStackProgram.isEmpty())
                    changeFormatStackProgram.push(mark);
                else
                {
                    while (changeFormatStackProgram.top() != BRACKET_LEFT &&
                           changeFormatStackProgram.top() - mark > 10) {
                        int instruction = changeFormatStackProgram.pop();
                        if (OP_MOD == instruction)
                        {
                            storeOperandsStackProgram.push(
                                        R_computeForMode(
                                            int(storeOperandsStackProgram.pop().getDecimal()),
                                            int(storeOperandsStackProgram.pop().getDecimal())));
                        }
                        else
                        {
                            MetaBinaryContainer op1 = storeOperandsStackProgram.pop();
                            MetaBinaryContainer op2 = storeOperandsStackProgram.pop();
                            MetaBinaryContainer computeResult = R_computeProgram(op1, op2, instruction);
                            storeOperandsStackProgram.push(computeResult);
                        }
                    }
                    changeFormatStackProgram.push(mark);
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
                    changeFormatStackProgram.push(92);

                    rightBracket = false;

                    nextNeg = false;
                    nextNode = false;

                    isNew = true;
                }
                else if ('3' == container[i][20])
                {
                    storeOperandsStackProgram.push(temp);
                    temp = 0.0;

                    while (changeFormatStackProgram.top() != 92)
                    {
                        int instruction = changeFormatStackProgram.pop();
                        if (OP_MOD == instruction)
                        {
                            storeOperandsStackProgram.push(
                                        R_computeForMode(
                                            int(storeOperandsStackProgram.pop().getDecimal()),
                                            int(storeOperandsStackProgram.pop().getDecimal())));
                        }
                        else
                        {
                            MetaBinaryContainer op1 = storeOperandsStackProgram.pop();
                            MetaBinaryContainer op2 = storeOperandsStackProgram.pop();
                            MetaBinaryContainer computeResult = R_computeProgram(op1, op2, instruction);
                            storeOperandsStackProgram.push(computeResult);
                        }
                    }

                    changeFormatStackProgram.pop();

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

        switch (type)
        {
        case PRO_NOT: !storeOperandsStackProgram.top(); break;
        case PRO_ROL: storeOperandsStackProgram.top().ROL(); break;
        case PRO_ROR: storeOperandsStackProgram.top().ROR(); break;
        case PRO_LSR: storeOperandsStackProgram.top().LSR(); break;
        case PRO_LSL: storeOperandsStackProgram.top().LSL(); break;
        case PRO_EQU: break;
        }

        emit resultProgramSender(package.getContainer(), makeTheProgramPackageToMessageGetter(true));
        fleshTextSender(resultString, true);
    }
    catch (QString error)
    {
        emit resultProgramSender(package.getContainer(), makeTheProgramPackageToMessageGetter(false));
        fleshTextSender(error, true);
    }
}

int Compute::makeTheProgramPackageToMessageGetter(bool isSuccess)
{
    tempPackage.clear();
    resultString.clear();

    int capacity = 0;
    if (isSuccess)
    {
        switch (status)
        {
        case Binary: resultString = storeOperandsStackProgram.pop().getBinary(); break;
        case Octal: resultString = storeOperandsStackProgram.pop().getOctal(); break;
        case Hexadecimal: resultString = storeOperandsStackProgram.pop().getHexadecimal(); break;
        }

        for (int i = 0; i < resultString.length(); i++)
        {
            package[i].append("compute____program_");
            if ('0' == resultString[i])
                package[i].append("00");
            else if ('1' == resultString[i])
                package[i].append("01");
            else if ('2' == resultString[i])
                package[i].append("02");
            else if ('3' == resultString[i])
                package[i].append("03");
            else if ('4' == resultString[i])
                package[i].append("04");
            else if ('5' == resultString[i])
                package[i].append("05");
            else if ('6' == resultString[i])
                package[i].append("06");
            else if ('7' == resultString[i])
                package[i].append("07");
            else if ('8' == resultString[i])
                package[i].append("08");
            else if ('9' == resultString[i])
                package[i].append("09");
            else if ('A' == resultString[i])
                package[i].append("10");
            else if ('B' == resultString[i])
                package[i].append("11");
            else if ('C' == resultString[i])
                package[i].append("12");
            else if ('D' == resultString[i])
                package[i].append("13");
            else if ('E' == resultString[i])
                package[i].append("14");
            else if ('F' == resultString[i])
                package[i].append("15");

            capacity++;
        }

        return capacity;
    }
    // if false set the CE to the messageGetter
    else
    {
        tempPackage.addRear("compute____program_90");
        return capacity;
    }
}
