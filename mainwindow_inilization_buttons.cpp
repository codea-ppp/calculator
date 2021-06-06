#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPushButton"

void MainWindow::iniVirtualPuttons()
{
    myBlockProgramBackGetter();
    myBlockProgramNodeGetter();
    myBlockProgramLeftBracketGetter();
    myBlockProgramOneOperandsOperatorsGetter();
    myBlockProgramTwoOperandsOperatorsGetter();
    myBlockProgramRightBracketGetter();

    myAllowProgramNumbersGetter();
    myAllowProgramLessGetter();

    myBlockScienceBackGetter();
    myBlockScienceNodeGetter();
    myBlockScienceLeftBracketGetter();
    myBlockScienceOneOperandsOperatorsGetter();
    myBlockScienceTwoOperandsOperatorsGetter();
    myBlockScienceRightBracketGetter();

    myAllowScienceNumbersGetter();
    myAllowScienceLessGetter();


    ui->radioButton_binary->setDisabled(false);
    ui->radioButton_octal->setDisabled(false);
    ui->radioButton_hexadecimal->setDisabled(false);
}

void MainWindow::iniVirtualProgramPutton()
{
    myBlockProgramBackGetter();
    myBlockProgramNodeGetter();
    myBlockProgramLeftBracketGetter();
    myBlockProgramOneOperandsOperatorsGetter();
    myBlockProgramTwoOperandsOperatorsGetter();
    myBlockProgramRightBracketGetter();

    myAllowProgramNumbersGetter();
    myAllowProgramLessGetter();

    ui->radioButton_binary->setDisabled(false);
    ui->radioButton_octal->setDisabled(false);
    ui->radioButton_hexadecimal->setDisabled(false);
}

void MainWindow::iniVirtualSciencePutton()
{
    myBlockScienceBackGetter();
    myBlockScienceNodeGetter();
    myBlockScienceLeftBracketGetter();
    myBlockScienceOneOperandsOperatorsGetter();
    myBlockScienceTwoOperandsOperatorsGetter();
    myBlockScienceRightBracketGetter();

    myAllowScienceNumbersGetter();
    myAllowScienceLessGetter();
}
