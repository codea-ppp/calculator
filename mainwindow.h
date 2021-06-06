#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "messagegeter.h"
#include "compute.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // message between button and messageGeter
    void messagePassPort(void);

    // lock and unlock buttons on the run time
    void setLockAndUnlockOnInput(void);

signals:
    void myAllowProgramNumbersGetter(void);

public slots:
    // to get the flesh text
    // whichTextBrower is true means program
    void fleshTextGetter(QString, bool whichTextBrower);

    // radio button ban the virtual keyboard
    void radioButtonBanVirtualKeyboard(void);


    // virtual keyboard style slot
    void keyboard_binary_style(void);
    void keyboard_octal_style(void);
    void keyboard_hexadecimal_style(void);

    void rebuildconnectProgramForBinaryStyle(void);
    void rebuildconnectProgramForOctalStyle(void);
    void rebuildconnectProgramForHexadecimalStyle(void);

    // keyboard change when run time
    void myBlockScienceZeroGetter(void);
    void myAllowScienceLessGetter(void);

    void myBlockProgramZeroGetter(void);
    void myAllowProgramLessGetter(void);

    // attention the 50 is not set because it always able
    void myBlocksScienceSpecialNumbersGetter(void);
    void myBlockScienceNumbersGetter(void);
    void myBlockScienceOneOperandsOperatorsGetter(void);
    void myBlockScienceTwoOperandsOperatorsGetter(void);
    void myBlockScienceLeftBracketGetter(void);
    void myBlockScienceRightBracketGetter(void);
    void myBlockScienceNodeGetter(void);
    void myBlockScienceBackGetter(void);

    void myAllowScienceNumbersGetter(void);
    void myAllowScienceOneOperandsOperatorsGetter(void);
    void myAllowScienceTwoOperandsOperatorsGetter(void);
    void myAllowScienceLeftBracketGetter(void);
    void myAllowScienceRightBracketGetter(void);
    void myAllowScienceNodeGetter(void);
    void myAllowScienceBackGetter(void);

    void myBlockProgramNumbersGetter(void);
    void myBlockProgramOneOperandsOperatorsGetter(void);
    void myBlockProgramTwoOperandsOperatorsGetter(void);
    void myBlockProgramLeftBracketGetter(void);
    void myBlockProgramRightBracketGetter(void);
    void myBlockProgramNodeGetter(void);
    void myBlockProgramBackGetter(void);

    void myAllowProgramOneOperandsOperatorsGetter(void);
    void myAllowProgramTwoOperandsOperatorsGetter(void);
    void myAllowProgramLeftBracketGetter(void);
    void myAllowProgramRightBracketGetter(void);
    void myAllowProgramNodeGetter(void);
    void myAllowProgramBackGetter(void);

private:
    void iniVirtualPuttons(void);
    void iniVirtualSciencePutton(void);
    void iniVirtualProgramPutton(void);

    Ui::MainWindow *ui;

    MessageGeter* messageGeter;

    Compute* computer;
};

#endif // MAINWINDOW_H
