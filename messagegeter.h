#ifndef MESSAGEGETER_H
#define MESSAGEGETER_H

#include <QWidget>
#include <QStack>

#include "myarray.h"
#include "commands.h"

class MessageGeter : public QWidget
{
    Q_OBJECT
public:
    explicit MessageGeter(QWidget *parent = nullptr);
    ~MessageGeter();

signals:
    // signals to compute
    void containerScienceSender(QString* container, int capacity, int type);
    void containerProgramSender(QString* container, int capacity, int type);

    // flesh text signal
    // the bool value is true means the program text browser
    void fleshTextSender(QString, bool);

    // virtual keyboard contrl signal

    // the two signals and slots have not the allow or block version
    // it must be called under if and behind the greater contrl
    void myBlockScienceZeroSender(void);
    void myAllowScienceLessSender(void);

    void myBlockProgramZeroSender(void);
    void myAllowProgramLessSender(void);

    void myBlockScienceSpecialNumberSender(void);
    void myBlockScienceNumbersSender(void);
    void myBlockScienceOneOperandsOperatorsSender(void);
    void myBlockScienceTwoOperandsOperatorsSender(void);
    void myBlockScienceLeftBracketSender(void);
    void myBlockScienceRightBracketSender(void);
    void myBlockScienceNodeSender(void);
    void myBlockScienceBackSender(void);
    void myBlockScienceLogSender(void);

    void myAllowScienceNumbersSender(void);
    void myAllowScienceOneOperandsOperatorsSender(void);
    void myAllowScienceTwoOperandsOperatorsSender(void);
    void myAllowScienceLeftBracketSender(void);
    void myAllowScienceRightBracketSender(void);
    void myAllowScienceNodeSender(void);
    void myAllowScienceBackSender(void);

    void myBlockProgramNumbersSender(void);
    void myBlockProgramOneOperandsOperatorsSender(void);
    void myBlockProgramTwoOperandsOperatorsSender(void);
    void myBlockProgramLeftBracketSender(void);
    void myBlockProgramRightBracketSender(void);
    void myBlockProgramNodeSender(void);
    void myBlockProgramBackSender(void);

    void myAllowProgramNumbersSender(void);
    void myAllowProgramOneOperandsOperatorsSender(void);
    void myAllowProgramTwoOperandsOperatorsSender(void);
    void myAllowProgramLeftBracketSender(void);
    void myAllowProgramRightBracketSender(void);
    void myAllowProgramNodeSender(void);
    void myAllowProgramBackSender(void);

    void myProgramCESender(void);
    void myScienceCESender(void);

public slots:
    void getMessage(void);

    void getMessageFromComputeScience(QString* string, int capacity);
    void getMessageFromComputeProgram(QString* string, int capacity);

private:
    void analyzeData(QString _data);

    void creatScienceString(QString data, QString* string);
    void creatProgramString(QString data, QString* string);

    QString stringScience;
    QString stringProgram;

    QStack<int> insertSizeStackScience;
    QStack<int> insertSizeStackProgram;

    MyArray* containerScience;
    MyArray* containerProgram;

    int leftBracketCountScience;
    int leftBracketCountProgram;

    bool newScienceNumber;
    bool newProgramNumber;

    bool lessClickAsNegativeScienceNumber;
    bool lessClickAsNegativeProgramNumber;
};

#endif // MESSAGEGETER_H
