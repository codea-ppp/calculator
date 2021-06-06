#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPushButton"
#include "QRadioButton"



// allow and program
void MainWindow::myAllowProgramBackGetter()
{
    ui->pushButton_program_91->setDisabled(false);
}

void MainWindow::myAllowProgramLeftBracketGetter()
{
    ui->pushButton_program_92->setDisabled(false);
}

void MainWindow::myAllowProgramNodeGetter()
{
    ui->pushButton_program_94->setDisabled(false);
}

void MainWindow::myAllowProgramOneOperandsOperatorsGetter()
{
    ui->pushButton_program_33->setDisabled(false);
    ui->pushButton_program_34->setDisabled(false);
    ui->pushButton_program_35->setDisabled(false);
    ui->pushButton_program_36->setDisabled(false);
    ui->pushButton_program_37->setDisabled(false);

    ui->pushButton_program_50->setDisabled(false);

    ui->radioButton_binary->setDisabled(false);
    ui->radioButton_hexadecimal->setDisabled(false);
    ui->radioButton_octal->setDisabled(false);
}

void MainWindow::myAllowProgramRightBracketGetter()
{
    ui->pushButton_program_93->setDisabled(false);
}

void MainWindow::myAllowProgramTwoOperandsOperatorsGetter()
{
    ui->pushButton_program_20->setDisabled(false);
    ui->pushButton_program_21->setDisabled(false);
    ui->pushButton_program_22->setDisabled(false);
    ui->pushButton_program_23->setDisabled(false);
    ui->pushButton_program_24->setDisabled(false);

    ui->pushButton_program_30->setDisabled(false);
    ui->pushButton_program_31->setDisabled(false);
    ui->pushButton_program_32->setDisabled(false);
}

void MainWindow::myAllowProgramLessGetter()
{
    ui->pushButton_program_21->setDisabled(false);
}



// allow and science
void MainWindow::myAllowScienceBackGetter()
{
    ui->pushButton_science_91->setDisabled(false);
}

void MainWindow::myAllowScienceLeftBracketGetter()
{
    ui->pushButton_science_92->setDisabled(false);
}

void MainWindow::myAllowScienceNodeGetter()
{
    ui->pushButton_science_94->setDisabled(false);
}

void MainWindow::myAllowScienceNumbersGetter()
{
    ui->pushButton_science_00->setDisabled(false);
    ui->pushButton_science_01->setDisabled(false);
    ui->pushButton_science_02->setDisabled(false);
    ui->pushButton_science_03->setDisabled(false);
    ui->pushButton_science_04->setDisabled(false);
    ui->pushButton_science_05->setDisabled(false);
    ui->pushButton_science_06->setDisabled(false);
    ui->pushButton_science_07->setDisabled(false);
    ui->pushButton_science_08->setDisabled(false);
    ui->pushButton_science_09->setDisabled(false);
    ui->pushButton_science_10->setDisabled(false);
    ui->pushButton_science_11->setDisabled(false);
}

void MainWindow::myAllowScienceOneOperandsOperatorsGetter()
{
    ui->pushButton_science_30->setDisabled(false);
    ui->pushButton_science_31->setDisabled(false);
    ui->pushButton_science_32->setDisabled(false);
    ui->pushButton_science_33->setDisabled(false);
    ui->pushButton_science_34->setDisabled(false);
    ui->pushButton_science_35->setDisabled(false);
    ui->pushButton_science_36->setDisabled(false);
    ui->pushButton_science_38->setDisabled(false);

    ui->pushButton_science_50->setDisabled(false);
}

void MainWindow::myAllowScienceRightBracketGetter()
{
    ui->pushButton_science_93->setDisabled(false);
}

void MainWindow::myAllowScienceTwoOperandsOperatorsGetter()
{
    ui->pushButton_science_20->setDisabled(false);
    ui->pushButton_science_21->setDisabled(false);
    ui->pushButton_science_22->setDisabled(false);
    ui->pushButton_science_23->setDisabled(false);
    ui->pushButton_science_24->setDisabled(false);

    ui->pushButton_science_37->setDisabled(false);
}

void MainWindow::myAllowScienceLessGetter()
{
    ui->pushButton_science_21->setDisabled(false);
}



// block and program
void MainWindow::myBlockProgramBackGetter()
{
    ui->pushButton_program_91->setDisabled(true);
}

void MainWindow::myBlockProgramLeftBracketGetter()
{
    ui->pushButton_program_92->setDisabled(true);
}

void MainWindow::myBlockProgramNodeGetter()
{
    ui->pushButton_program_94->setDisabled(true);
}

void MainWindow::myBlockProgramNumbersGetter()
{
    ui->pushButton_program_00->setDisabled(true);
    ui->pushButton_program_01->setDisabled(true);
    ui->pushButton_program_02->setDisabled(true);
    ui->pushButton_program_03->setDisabled(true);
    ui->pushButton_program_04->setDisabled(true);
    ui->pushButton_program_05->setDisabled(true);
    ui->pushButton_program_06->setDisabled(true);
    ui->pushButton_program_07->setDisabled(true);
    ui->pushButton_program_08->setDisabled(true);
    ui->pushButton_program_09->setDisabled(true);
    ui->pushButton_program_10->setDisabled(true);
    ui->pushButton_program_11->setDisabled(true);
    ui->pushButton_program_12->setDisabled(true);
    ui->pushButton_program_13->setDisabled(true);
    ui->pushButton_program_14->setDisabled(true);
    ui->pushButton_program_15->setDisabled(true);
}

void MainWindow::myBlockProgramOneOperandsOperatorsGetter()
{
    ui->pushButton_program_33->setDisabled(true);
    ui->pushButton_program_34->setDisabled(true);
    ui->pushButton_program_35->setDisabled(true);
    ui->pushButton_program_36->setDisabled(true);
    ui->pushButton_program_37->setDisabled(true);

    ui->pushButton_program_50->setDisabled(true);

    ui->radioButton_binary->setDisabled(true);
    ui->radioButton_hexadecimal->setDisabled(true);
    ui->radioButton_octal->setDisabled(true);
}

void MainWindow::myBlockProgramRightBracketGetter()
{
    ui->pushButton_program_93->setDisabled(true);
}

void MainWindow::myBlockProgramTwoOperandsOperatorsGetter()
{
    ui->pushButton_program_20->setDisabled(true);
    ui->pushButton_program_21->setDisabled(true);
    ui->pushButton_program_22->setDisabled(true);
    ui->pushButton_program_23->setDisabled(true);
    ui->pushButton_program_24->setDisabled(true);

    ui->pushButton_program_30->setDisabled(true);
    ui->pushButton_program_31->setDisabled(true);
    ui->pushButton_program_32->setDisabled(true);
}

void MainWindow::myBlockProgramZeroGetter()
{
    ui->pushButton_program_00->setDisabled(true);
}



// block and science
void MainWindow::myBlockScienceBackGetter()
{
    ui->pushButton_science_91->setDisabled(true);
}

void MainWindow::myBlockScienceLeftBracketGetter()
{
    ui->pushButton_science_92->setDisabled(true);
}

void MainWindow::myBlockScienceNodeGetter()
{
    ui->pushButton_science_94->setDisabled(true);
}

void MainWindow::myBlockScienceNumbersGetter()
{
    ui->pushButton_science_00->setDisabled(true);
    ui->pushButton_science_01->setDisabled(true);
    ui->pushButton_science_02->setDisabled(true);
    ui->pushButton_science_03->setDisabled(true);
    ui->pushButton_science_04->setDisabled(true);
    ui->pushButton_science_05->setDisabled(true);
    ui->pushButton_science_06->setDisabled(true);
    ui->pushButton_science_07->setDisabled(true);
    ui->pushButton_science_08->setDisabled(true);
    ui->pushButton_science_09->setDisabled(true);
    ui->pushButton_science_10->setDisabled(true);
    ui->pushButton_science_11->setDisabled(true);
}

void MainWindow::myBlockScienceOneOperandsOperatorsGetter()
{
    ui->pushButton_science_30->setDisabled(true);
    ui->pushButton_science_31->setDisabled(true);
    ui->pushButton_science_32->setDisabled(true);
    ui->pushButton_science_33->setDisabled(true);
    ui->pushButton_science_34->setDisabled(true);
    ui->pushButton_science_35->setDisabled(true);
    ui->pushButton_science_36->setDisabled(true);
    ui->pushButton_science_38->setDisabled(true);

    ui->pushButton_science_50->setDisabled(true);
}

void MainWindow::myBlockScienceRightBracketGetter()
{
    ui->pushButton_science_93->setDisabled(true);
}

void MainWindow::myBlockScienceTwoOperandsOperatorsGetter()
{
    ui->pushButton_science_20->setDisabled(true);
    ui->pushButton_science_21->setDisabled(true);
    ui->pushButton_science_22->setDisabled(true);
    ui->pushButton_science_23->setDisabled(true);
    ui->pushButton_science_24->setDisabled(true);

    ui->pushButton_science_37->setDisabled(true);
}

void MainWindow::myBlockScienceZeroGetter()
{
    ui->pushButton_science_00->setDisabled(true);
}

void MainWindow::myBlocksScienceSpecialNumbersGetter()
{
    ui->pushButton_science_10->setDisabled(true);
    ui->pushButton_science_11->setDisabled(true);
}
