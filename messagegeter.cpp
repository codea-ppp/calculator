#include "messagegeter.h"
#include "checkstring.h"
#include "QAbstractButton"

MessageGeter::MessageGeter(QWidget *parent) : QWidget(parent)
{
    leftBracketCountScience = 0;
    leftBracketCountProgram = 0;

    newScienceNumber = true;
    newProgramNumber = true;

    lessClickAsNegativeScienceNumber = true;
    lessClickAsNegativeScienceNumber = true;

    containerScience = new(std::nothrow) MyArray();
    if (nullptr == containerScience)
        abort();

    containerProgram = new(std::nothrow) MyArray();
    if (nullptr == containerProgram)
        abort();
}

// analyzeData is only do allow or block buttons on the UI
// and decide the input number whether belong to a negative number
// "CE" and "back" message are not handled here
void MessageGeter::analyzeData(QString data)
{
    // every baunch must have at least 6 times emits in one call
    // science mode
    if (IS_SCIENCE)
    {
        // data is a number
        if (IS_SCIENCE_NUMBER_DEFAULT_SCIENCE)
        {
            emit myBlockScienceLeftBracketSender();

            if (!!leftBracketCountScience)
                emit myAllowScienceRightBracketSender();
            else
                emit myBlockScienceRightBracketSender();

            if (!leftBracketCountScience)
                emit myAllowScienceOneOperandsOperatorsSender();
            else
                emit myBlockScienceOneOperandsOperatorsSender();

            if (newScienceNumber && IS_NOT_SCIENCE_SPECIAL_NUMBER_DEFAUT_SCIENCE)
                emit myAllowScienceNodeSender();
            else
                emit myBlockScienceNodeSender();

            emit myAllowScienceTwoOperandsOperatorsSender();

            if (IS_NOT_SCIENCE_SPECIAL_NUMBER_DEFAUT_SCIENCE)
                emit myAllowScienceNumbersSender();
            else
                emit myBlockScienceNumbersSender();

            if (!!containerScience->getCapacity())
                emit myAllowScienceBackSender();

            myBlockScienceSpecialNumberSender();

            lessClickAsNegativeScienceNumber = false;
        }
        else if (IS_LESS)
        {
            if (lessClickAsNegativeScienceNumber)
            {
                // as the negative mark must follow the number
                emit myBlockProgramLeftBracketSender();
                emit myBlockScienceLogSender();
                emit myBlockScienceNodeSender();
                emit myBlockScienceOneOperandsOperatorsSender();
                emit myBlockScienceRightBracketSender();
                emit myBlockScienceTwoOperandsOperatorsSender();

                // the number
                emit myAllowScienceNumbersSender();
                lessClickAsNegativeScienceNumber = false;
            }
            else
            {
                emit myBlockScienceNodeSender();

                emit myAllowScienceLeftBracketSender();

                emit myAllowScienceNumbersSender();
                newScienceNumber = true;
                if ('3' == data[20] || '6' == data[20])
                    emit myBlockScienceZeroSender();

                emit myBlockScienceRightBracketSender();

                emit myBlockScienceOneOperandsOperatorsSender();

                emit myBlockScienceTwoOperandsOperatorsSender();

                if (!!containerScience->getCapacity())
                    emit myAllowScienceBackSender();

                emit myAllowScienceLessSender();
                lessClickAsNegativeScienceNumber = true;
            }
        }
        else if (IS_SCIENCE_TWO_OPERANDS_OPERATOR_DEFAUT_SCIENCE)
        {
            emit myBlockScienceNodeSender();

            emit myAllowScienceLeftBracketSender();

            emit myAllowScienceNumbersSender();
            newScienceNumber = true;
            if ('3' == data[20] || '6' == data[20])
                emit myBlockScienceZeroSender();

            emit myBlockScienceRightBracketSender();

            emit myBlockScienceOneOperandsOperatorsSender();

            emit myBlockScienceTwoOperandsOperatorsSender();

            if (!!containerScience->getCapacity())
                emit myAllowScienceBackSender();

            emit myAllowScienceLessSender();
            lessClickAsNegativeScienceNumber = true;
        }
        else if (IS_BRACKET_LEFT)
        {
            // leftBracketCountScience should not be added here
            // it has been added already at the caller
            emit myAllowScienceLeftBracketSender();

            emit myBlockScienceRightBracketSender();

            emit myAllowScienceNumbersSender();
            newScienceNumber = true;

            emit myBlockScienceOneOperandsOperatorsSender();

            emit myBlockScienceTwoOperandsOperatorsSender();

            emit myBlockScienceNodeSender();

            if (!!containerScience->getCapacity())
                emit myAllowScienceBackSender();

            emit myAllowScienceLessSender();
            lessClickAsNegativeScienceNumber = true;
        }
        else if (IS_BRACKET_RIGHT)
        {
            if (!!leftBracketCountScience)
                emit myAllowScienceRightBracketSender();
            else
                emit myBlockScienceRightBracketSender();

            emit myBlockScienceLeftBracketSender();

            if (!leftBracketCountScience)
                emit myAllowScienceOneOperandsOperatorsSender();
            else
                emit myBlockScienceOneOperandsOperatorsSender();

            emit myAllowScienceTwoOperandsOperatorsSender();

            emit myBlockScienceNumbersSender();
            newScienceNumber = true;

            emit myBlockScienceNodeSender();

            if (!!containerScience->getCapacity())
                emit myAllowScienceBackSender();

            lessClickAsNegativeScienceNumber = false;
        }
        // data is .
        else if (IS_NODE)
        {
            emit myAllowScienceNumbersSender();
            newScienceNumber = false;

            emit myBlockScienceLeftBracketSender();

            emit myBlockScienceRightBracketSender();

            emit myBlockScienceOneOperandsOperatorsSender();

            emit myBlockScienceTwoOperandsOperatorsSender();

            emit myBlockScienceNodeSender();

            // because e and PI may not be a part of
            // number in real
            emit myBlockScienceSpecialNumberSender();

            if (!!containerScience->getCapacity())
                emit myAllowScienceBackSender();

            lessClickAsNegativeScienceNumber = false;
        }
        else if (IS_SCIENCE_ONE_OPERANDS_OPERATOR_DEFAUT_SCIENCE)
        {
            emit myAllowScienceOneOperandsOperatorsSender();

            emit myBlockScienceNumbersSender();
            newScienceNumber = false;

            emit myBlockScienceRightBracketSender();

            emit myBlockScienceNodeSender();

            emit myBlockScienceLeftBracketSender();

            emit myAllowScienceTwoOperandsOperatorsSender();

            if (!!containerScience->getCapacity())
                emit myAllowScienceBackSender();

            lessClickAsNegativeScienceNumber = true;
        }
    }
    // program mode
    else if (IS_PROGRAM || IS_RADIOBUTTON)
    {
        // data is number
        if (IS_PROGRAM_NUMBER_DEFAUT_PROGRAM)
        {
            emit myBlockProgramLeftBracketSender();

            if (!!leftBracketCountProgram)
                emit myAllowProgramRightBracketSender();
            else
                emit myBlockProgramRightBracketSender();

            if (!leftBracketCountProgram)
                emit myAllowProgramOneOperandsOperatorsSender();
            else
                emit myBlockProgramOneOperandsOperatorsSender();

            if (newProgramNumber)
                emit myAllowProgramNodeSender();
            else
                emit myBlockProgramNodeSender();

            emit myAllowProgramTwoOperandsOperatorsSender();

            emit myAllowProgramNumbersSender();

            if (!!containerProgram->getCapacity())
                emit myAllowProgramBackSender();

            lessClickAsNegativeProgramNumber = true;
        }
        else if (IS_LESS)
        {
            if (lessClickAsNegativeProgramNumber)
            {
                // block every thing expect number and special signal
                emit myBlockProgramLeftBracketSender();
                emit myBlockProgramNodeSender();
                emit myBlockProgramOneOperandsOperatorsSender();
                emit myBlockProgramRightBracketSender();
                emit myBlockProgramTwoOperandsOperatorsSender();

                // allow the numbers
                emit myAllowProgramNumbersSender();
                lessClickAsNegativeProgramNumber = false;
            }
            else
            {
                emit myBlockProgramNodeSender();

                emit myAllowProgramLeftBracketSender();

                emit myAllowProgramNumbersSender();
                newProgramNumber = true;
                if ('3' == data[20])
                    emit myBlockProgramZeroSender();

                emit myBlockProgramRightBracketSender();

                emit myBlockProgramOneOperandsOperatorsSender();

                emit myBlockProgramTwoOperandsOperatorsSender();

                if (!!containerProgram->getCapacity())
                    emit myAllowProgramBackSender();

                emit myAllowProgramLessSender();

                lessClickAsNegativeProgramNumber = true;
            }
        }
        // data is a two operands operator
        else if (IS_PROGRAM_TWO_OPERANDS_OPERATOR_DEFAUT_PROGRAM)
        {
            emit myBlockProgramNodeSender();

            emit myAllowProgramLeftBracketSender();

            emit myAllowProgramNumbersSender();
            newProgramNumber = true;
            if ('3' == data[20])
                emit myBlockProgramZeroSender();

            emit myBlockProgramRightBracketSender();

            emit myBlockProgramOneOperandsOperatorsSender();

            emit myBlockProgramTwoOperandsOperatorsSender();

            if (!!containerProgram->getCapacity())
                emit myAllowProgramBackSender();

            emit myAllowProgramLessSender();

            lessClickAsNegativeProgramNumber = true;
        }
        else if (IS_BRACKET_LEFT)
        {
            emit myAllowProgramLeftBracketSender();
            newScienceNumber = true;

            emit myAllowProgramRightBracketSender();

            emit myAllowProgramNumbersSender();

            emit myBlockProgramOneOperandsOperatorsSender();

            emit myBlockProgramTwoOperandsOperatorsSender();

            emit myBlockProgramNodeSender();

            if (!!containerProgram->getCapacity())
                emit myAllowProgramBackSender();

            emit myAllowProgramLessSender();

            lessClickAsNegativeProgramNumber = true;
        }
        else if (IS_BRACKET_RIGHT)
        {
            if (!!leftBracketCountProgram)
                emit myAllowProgramRightBracketSender();
            else
                emit myBlockProgramRightBracketSender();

            emit myAllowProgramLeftBracketSender();

            if (!leftBracketCountProgram)
                emit myAllowProgramOneOperandsOperatorsSender();
            else
                emit myBlockProgramOneOperandsOperatorsSender();

            emit myAllowProgramTwoOperandsOperatorsSender();

            emit myBlockProgramNumbersSender();
            newProgramNumber = true;

            emit myBlockProgramNodeSender();

            if (!!containerProgram->getCapacity())
                emit myAllowProgramBackSender();

            lessClickAsNegativeProgramNumber = false;
        }
        else if (IS_NODE)
        {
            emit myAllowProgramNumbersSender();
            newProgramNumber = false;

            emit myBlockProgramNodeSender();

            emit myBlockProgramLeftBracketSender();

            emit myBlockProgramRightBracketSender();

            emit myBlockProgramOneOperandsOperatorsSender();

            emit myBlockProgramTwoOperandsOperatorsSender();

            if (!!containerProgram->getCapacity())
                emit myAllowProgramBackSender();

            lessClickAsNegativeProgramNumber = false;
        }
        else if (IS_PROGRAM_ONE_OPERANDS_OPERATOR_DEFAUT_PROGRAM)
        {
            emit myAllowProgramOneOperandsOperatorsSender();

            emit myBlockProgramNumbersSender();
            newProgramNumber = false;

            if (!!leftBracketCountProgram)
                emit myAllowProgramRightBracketSender();
            else
                emit myBlockProgramRightBracketSender();

            emit myBlockProgramNodeSender();

            emit myBlockProgramLeftBracketSender();

            emit myAllowProgramTwoOperandsOperatorsSender();

            if (!!containerProgram->getCapacity())
                emit myAllowProgramBackSender();

            lessClickAsNegativeProgramNumber = true;
        }
        else if (IS_PROGRAM_SPECIAL_BAN_DEFAUT_PROGRAM ||
                 (IS_RADIOBUTTON && containerProgram->getCapacity()))
        {
            emit myBlockProgramLeftBracketSender();

            if (!!leftBracketCountProgram)
                emit myAllowProgramRightBracketSender();
            else
                emit myBlockProgramRightBracketSender();

            if (!leftBracketCountProgram)
                emit myAllowProgramOneOperandsOperatorsSender();
            else
                emit myBlockProgramOneOperandsOperatorsSender();

            emit myBlockProgramNodeSender();

            emit myAllowProgramTwoOperandsOperatorsSender();

            emit myBlockProgramNumbersSender();

            if (!!containerProgram->getCapacity())
                emit myAllowProgramBackSender();

            lessClickAsNegativeScienceNumber = false;
        }
    }
}

void MessageGeter::getMessage()
{
    QAbstractButton* button = static_cast<QAbstractButton*>(sender());
    QString data = button->objectName();

    // only do the add left bracket count
    // anyway it just do a litter for ")" compare
    // all the logic is lost and so it is not "else"
    if (IS_BRACKET_LEFT)
    {
        if (IS_SCIENCE)
            leftBracketCountScience++;
        else if (IS_PROGRAM)
            leftBracketCountProgram++;
    }
    if (IS_BRACKET_RIGHT)
    {
        if (IS_SCIENCE)
            leftBracketCountScience--;
        else if (IS_PROGRAM)
            leftBracketCountProgram--;
    }

    if (IS_CE)
    {
        if (IS_SCIENCE)
        {
            containerScience->clear();
            insertSizeStackScience.clear();
            stringScience.clear();

            newScienceNumber = true;

            emit myScienceCESender();
        }
        else if (IS_PROGRAM)
        {
            containerProgram->clear();
            insertSizeStackProgram.clear();
            stringProgram.clear();

            newProgramNumber = true;

            emit myProgramCESender();
        }
    }

    // it remove the lastest string from container string
    else if (IS_BACK)
    {
        if (IS_SCIENCE)
        {
            if ('9' == containerScience->top()[19] && '2' == containerScience->top()[20])
                leftBracketCountScience--;
            else if ('9' == containerScience->top()[19] && '3' == containerScience->top()[20])
                leftBracketCountScience++;

            if (IS_SCIENCE_COMPUTE_DEFAUT_SCIENCE)
            {
                containerScience->clear();
                insertSizeStackScience.clear();
                stringScience.clear();

                emit myScienceCESender();
            }
            else
            {
                containerScience->deleteRear();

                int pop = insertSizeStackScience.pop();
                stringScience.remove(stringScience.length() - pop, pop);

                if (!!containerScience->getCapacity())
                {
                    emit myAllowScienceBackSender();
                    analyzeData(containerScience->top());
                }
                else
                {
                    containerScience->clear();
                    insertSizeStackScience.clear();
                    stringScience.clear();

                    newScienceNumber = true;

                    emit myScienceCESender();
                }
            }
        }
        else if (IS_PROGRAM)
        {
            if ('9' == containerProgram->top()[19] && '2' == containerProgram->top()[20])
                leftBracketCountProgram--;
            else if ('9' == containerProgram->top()[19] && '3' == containerProgram->top()[20])
                leftBracketCountScience++;


            if (IS_PROGRAM_COMPUTE_DEFAUT_PROGRAM)
            {
                containerProgram->clear();
                insertSizeStackProgram.clear();
                stringProgram.clear();

                emit myProgramCESender();
            }
            else
            {
                containerProgram->deleteRear();

                int pop = insertSizeStackProgram.pop();
                stringProgram.remove(stringProgram.length() - pop, pop);

                if (!!containerProgram->getCapacity())
                {
                    emit myAllowProgramBackSender();
                    analyzeData(containerProgram->top());
                }
                else
                {
                    containerProgram->clear();
                    insertSizeStackProgram.clear();
                    stringProgram.clear();

                    newProgramNumber = true;

                    emit myProgramCESender();
                }
            }
        }
    }

    // something otherwise
    else
    {
        analyzeData(data);

        if (IS_SCIENCE)
        {
            creatScienceString(data, &stringScience);
            containerScience->addRear(data);
        }
        else if (IS_PROGRAM)
        {
            creatProgramString(data, &stringProgram);
            containerProgram->addRear(data);
        }   
    }
    // this is the send message mode
    // check the data whether a one operand operator
    // if true it will send message to the compute mode and do not redraw the text
    // otherwise it will redraw the text
    if (IS_SCIENCE)
    {
        // one operand operator should send to compute mode
        if ('5' == data[19] ||
           ('3' == data[19] && ('0' == data[20] || '1' == data[20] || '2' == data[20] ||
                '3' == data[20] || '4' == data[20] || '5' == data[20] || '6' == data[20] || '8' == data[20])))
        {
            // add ")" before formal compute
            // "(" is added when get the message
            containerScience->addRear("pushButton_science_93");

            if ('5' == data[19])
                emit containerScienceSender(containerScience->getContainer(), containerScience->getCapacity(), SCI_EQU);

            else if ('0' == data[20])
                emit containerScienceSender(containerScience->getContainer(), containerScience->getCapacity(), SCI_SIN);
            else if ('1' == data[20])
                emit containerScienceSender(containerScience->getContainer(), containerScience->getCapacity(), SCI_COS);
            else if ('2' == data[20])
                emit containerScienceSender(containerScience->getContainer(), containerScience->getCapacity(), SCI_TAN);
            else if ('3' == data[20])
                emit containerScienceSender(containerScience->getContainer(), containerScience->getCapacity(), SCI_COT);
            else if ('4' == data[20])
                emit containerScienceSender(containerScience->getContainer(), containerScience->getCapacity(), SCI_SEC);
            else if ('5' == data[20])
                emit containerScienceSender(containerScience->getContainer(), containerScience->getCapacity(), SCI_CSC);
            else if ('6' == data[20])
                emit containerScienceSender(containerScience->getContainer(), containerScience->getCapacity(), SCI_LOG);
            else if ('8' == data[20])
                emit containerScienceSender(containerScience->getContainer(), containerScience->getCapacity(), SCI_SQU);
        }

        // otherwise reflesh the text brower
        else
        {
            emit fleshTextSender(stringScience, false);
        }
    }
    else if (IS_PROGRAM)
    {

        // one operand operator should send to compute mode
        if('5' == data[19] || ('3' == data[19] && ('3' == data[20] || '4' == data[20] || '5' == data[20] ||
               '6' == data[20] || '7' == data[20])))
        {
           // add ")" before formal compute
           // "(" is added when get the message
           containerProgram->addRear("pushButton_science_93");

           if ('5' == data[19])
           {
               emit containerProgramSender(containerProgram->getContainer(), containerProgram->getCapacity(), PRO_EQU);
           }

           else if ('3' == data[20])
               emit containerProgramSender(containerProgram->getContainer(), containerProgram->getCapacity(), PRO_NOT);
           else if ('4' == data[20])
               emit containerProgramSender(containerProgram->getContainer(), containerProgram->getCapacity(), PRO_ROR);
           else if ('5' == data[20])
               emit containerProgramSender(containerProgram->getContainer(), containerProgram->getCapacity(), PRO_ROL);
           else if ('6' == data[20])
               emit containerProgramSender(containerProgram->getContainer(), containerProgram->getCapacity(), PRO_LSR);
           else if ('7' == data[20])
               emit containerProgramSender(containerProgram->getContainer(), containerProgram->getCapacity(), PRO_LSL);
       }

       // otherwise reflesh the text brower
       else
       {
           emit fleshTextSender(stringProgram, true);
       }
    }
    else if (IS_RADIOBUTTON)
    {
        if (containerProgram->getCapacity())
        {
            containerProgram->addRear("pushButton_science_93");
            emit containerProgramSender(containerProgram->getContainer(), containerProgram->getCapacity(), PRO_EQU);
        }
        emit myBlockProgramNumbersSender();
    }
}

// "CE" and "back" message are not handled here
void MessageGeter::creatScienceString(QString data, QString* string)
{
    if ('0' == data[19])
    {
        if ('0' == data[20])
        {
            string->append('0');
            insertSizeStackScience.push(QString('0').size());
        }
        else if ('1' == data[20])
        {
            string->append('1');
            insertSizeStackScience.push(QString('1').size());
        }
        else if ('2' == data[20])
        {
            string->append('2');
            insertSizeStackScience.push(QString('2').size());
        }
        else if ('3' == data[20])
        {
            string->append('3');
            insertSizeStackScience.push(QString('3').size());
        }
        else if ('4' == data[20])
        {
            string->append('4');
            insertSizeStackScience.push(QString('4').size());
        }
        else if ('5' == data[20])
        {
            string->append('5');
            insertSizeStackScience.push(QString('5').size());
        }
        else if ('6' == data[20])
        {
            string->append('6');
            insertSizeStackScience.push(QString('6').size());
        }
        else if ('7' == data[20])
        {
            string->append('7');
            insertSizeStackScience.push(QString('7').size());
        }
        else if ('8' == data[20])
        {
            string->append('8');
            insertSizeStackScience.push(QString('8').size());
        }
        else if ('9' == data[20])
        {
            string->append('9');
            insertSizeStackScience.push(QString('9').size());
        }
    }
    else if ('1' == data[19])
    {
        if ('0' == data[20])
        {
            string->append(" Π ");
            insertSizeStackScience.push(QString(" Π ").size());
        }
        else if ('1' == data[20])
        {
            string->append(" e ");
            insertSizeStackScience.push(QString(" e ").size());
        }
    }
    else if ('2' == data[19])
    {
        if ('0' == data[20])
        {
            string->append(" + ");
            insertSizeStackScience.push(QString(" + ").size());
        }
        else if ('1' == data[20])
        {
            string->append(" - ");
            insertSizeStackScience.push(QString(" - ").size());
        }
        else if ('2' == data[20])
        {
            string->append(" * ");
            insertSizeStackScience.push(QString(" * ").size());
        }
        else if ('3' == data[20])
        {
            string->append(" / ");
            insertSizeStackScience.push(QString(" / ").size());
        }
        else if ('4' == data[20])
        {
            string->append(" % ");
            insertSizeStackScience.push(QString(" % ").size());
        }
    }
    else if ('3' == data[19])
    {
        if ('7' == data[20])
        {
            string->append(" ^ ");
            insertSizeStackScience.push(QString(" ^ ").size());
        }
    }
    else if ('9' == data[19])
    {
        if ('2' == data[20])
        {
            string->append(" ( ");
            insertSizeStackScience.push(QString(" ) ").size());
        }
        else if ('3' == data[20])
        {
            string->append(" ) ");
            insertSizeStackScience.push(QString(" ) ").size());
        }
        else if ('4' == data[20])
        {
            string->append('.');
            insertSizeStackScience.push(QString('.').size());
        }
    }
}

// "CE" and "back" message are not handled here
void MessageGeter::creatProgramString(QString data, QString* string)
{
    if ('0' == data[19])
    {
        if ('0' == data[20])
        {
            string->append('0');
            insertSizeStackProgram.push(QString('0').size());
        }
        else if ('1' == data[20])
        {
            string->append('1');
            insertSizeStackProgram.push(QString('1').size());
        }
        else if ('2' == data[20])
        {
            string->append('2');
            insertSizeStackProgram.push(QString('2').size());
        }
        else if ('3' == data[20])
        {
            string->append('3');
            insertSizeStackProgram.push(QString('3').size());
        }
        else if ('4' == data[20])
        {
            string->append('4');
            insertSizeStackProgram.push(QString('4').size());
        }
        else if ('5' == data[20])
        {
            string->append('5');
            insertSizeStackProgram.push(QString('5').size());
        }
        else if ('6' == data[20])
        {
            string->append('6');
            insertSizeStackProgram.push(QString('6').size());
        }
        else if ('7' == data[20])
        {
            string->append('7');
            insertSizeStackProgram.push(QString('7').size());
        }
        else if ('8' == data[20])
        {
            string->append('8');
            insertSizeStackProgram.push(QString('8').size());
        }
        else if ('9' == data[20])
        {
            string->append('9');
            insertSizeStackProgram.push(QString('9').size());
        }
    }
    else if ('1' == data[19])
    {
        if ('0' == data[20])
        {
            string->append('A');
            insertSizeStackProgram.push(QString('A').size());
        }
        else if ('1' == data[20])
        {
            string->append('B');
            insertSizeStackProgram.push(QString('B').size());
        }
        else if ('2' == data[20])
        {
            string->append('C');
            insertSizeStackProgram.push(QString('C').size());
        }
        else if ('3' == data[20])
        {
            string->append('D');
            insertSizeStackProgram.push(QString('D').size());
        }
        else if ('4' == data[20])
        {
            string->append('E');
            insertSizeStackProgram.push(QString('E').size());
        }
        else if ('5' == data[20])
        {
            string->append('F');
            insertSizeStackProgram.push(QString('F').size());
        }
    }
    else if ('2' == data[19])
    {
        if ('0' == data[20])
        {
            string->append(" + ");
            insertSizeStackProgram.push(QString(" + ").size());
        }
        else if ('1' == data[20])
        {
            string->append(" - ");
            insertSizeStackProgram.push(QString(" - ").size());
        }
        else if ('2' == data[20])
        {
            string->append(" * ");
            insertSizeStackProgram.push(QString(" * ").size());
        }
        else if ('3' == data[20])
        {
            string->append(" / ");
            insertSizeStackProgram.push(QString(" / ").size());
        }
        else if ('4' == data[20])
        {
            string->append(" % ");
            insertSizeStackProgram.push(QString(" % ").size());
        }
    }
    else if ('3' == data[19])
    {
        if ('0' == data[20])
        {
            string->append(" AND ");
            insertSizeStackProgram.push(QString(" AND ").size());
        }
        else if ('1' == data[20])
        {
            string->append(" OR ");
            insertSizeStackProgram.push(QString(" OR ").size());
        }
        else if ('2' == data[20])
        {
            string->append(" XOR ");
            insertSizeStackProgram.push(QString(" XOR ").size());
        }
        else if ('3' == data[20])
        {
            string->append(" NOT ");
            insertSizeStackProgram.push(QString(" NOT ").size());
        }
        else if ('4' == data[20])
        {
            string->append(" ROR ");
            insertSizeStackProgram.push(QString(" ROR ").size());
        }
        else if ('5' == data[20])
        {
            string->append(" ROL ");
            insertSizeStackProgram.push(QString(" ROL ").size());
        }
        else if ('6' == data[20])
        {
            string->append(" LSR ");
            insertSizeStackProgram.push(QString(" LSR ").size());
        }
        else if ('7' == data[20])
        {
            string->append(" LSL ");
            insertSizeStackProgram.push(QString(" LSL ").size());
        }
    }
    else if ('9' == data[19])
    {
        if ('2' == data[20])
        {
            string->append(" ( ");
            insertSizeStackProgram.push(QString(" ) ").size());
        }
        else if ('3' == data[20])
        {
            string->append(" ) ");
            insertSizeStackProgram.push(QString(" ) ").size());
        }
        else if ('4' == data[20])
        {
            string->append('.');
            insertSizeStackProgram.push(QString('.').size());
        }
    }
}

void MessageGeter::getMessageFromComputeProgram(QString* string, int capacity)
{
    insertSizeStackProgram.clear();
    stringProgram.clear();
    containerProgram->clear();

    newProgramNumber = true;

    for (int i = 0; i < capacity; i++)
    {
        containerProgram->addRear(string[i]);
        creatProgramString(string[i], &stringProgram);
    }

    // ban number
    analyzeData("specialBan_program_95");

    if (!capacity)
        emit myProgramCESender();
}

void MessageGeter::getMessageFromComputeScience(QString* string, int capacity)
{
    insertSizeStackScience.clear();
    stringScience.clear();
    containerScience->clear();

    newScienceNumber = true;

    for (int i = 0; i < capacity; i++)
    {
        containerScience->addRear(string[i]);
        creatScienceString(string[i], &stringScience);
    }
    //           pushButton_science_00
    analyzeData("specialBan_science_10");

    if (!capacity)
        emit myScienceCESender();
}

MessageGeter::~MessageGeter()
{
    delete containerProgram;
    delete containerScience;
}
