#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPushButton"


void MainWindow::keyboard_binary_style()
{
    disconnect(this, &MainWindow::myAllowProgramNumbersGetter,
               this, &MainWindow::rebuildconnectProgramForOctalStyle);
    disconnect(this, &MainWindow::myAllowProgramNumbersGetter,
               this, &MainWindow::rebuildconnectProgramForHexadecimalStyle);

    return;
}

void MainWindow::keyboard_octal_style()
{
    connect(this, &MainWindow::myAllowProgramNumbersGetter,
            this, &MainWindow::rebuildconnectProgramForOctalStyle);
    disconnect(this, &MainWindow::myAllowProgramNumbersGetter,
               this, &MainWindow::rebuildconnectProgramForHexadecimalStyle);

    return;
}

void MainWindow::keyboard_hexadecimal_style()
{
    connect(this, &MainWindow::myAllowProgramNumbersGetter,
            this, &MainWindow::rebuildconnectProgramForOctalStyle);
    connect(this, &MainWindow::myAllowProgramNumbersGetter,
            this, &MainWindow::rebuildconnectProgramForHexadecimalStyle);

    return;
}



// the functions below are connected with the functions in the
// file mainwindow_allow_block.cpp is used for able the correct
// buttons when myAllow[Science, Program]NumberGetter() are called
void MainWindow::rebuildconnectProgramForBinaryStyle()
{
    ui->pushButton_program_00->setDisabled(false);
    ui->pushButton_program_01->setDisabled(false);

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

void MainWindow::rebuildconnectProgramForOctalStyle()
{
    ui->pushButton_program_00->setDisabled(false);
    ui->pushButton_program_01->setDisabled(false);
    ui->pushButton_program_02->setDisabled(false);
    ui->pushButton_program_03->setDisabled(false);
    ui->pushButton_program_04->setDisabled(false);
    ui->pushButton_program_05->setDisabled(false);
    ui->pushButton_program_06->setDisabled(false);
    ui->pushButton_program_07->setDisabled(false);

    ui->pushButton_program_08->setDisabled(true);
    ui->pushButton_program_09->setDisabled(true);
    ui->pushButton_program_10->setDisabled(true);
    ui->pushButton_program_11->setDisabled(true);
    ui->pushButton_program_12->setDisabled(true);
    ui->pushButton_program_13->setDisabled(true);
    ui->pushButton_program_14->setDisabled(true);
    ui->pushButton_program_15->setDisabled(true);
}

void MainWindow::rebuildconnectProgramForHexadecimalStyle()
{
    ui->pushButton_program_00->setDisabled(false);
    ui->pushButton_program_01->setDisabled(false);
    ui->pushButton_program_02->setDisabled(false);
    ui->pushButton_program_03->setDisabled(false);
    ui->pushButton_program_04->setDisabled(false);
    ui->pushButton_program_05->setDisabled(false);
    ui->pushButton_program_06->setDisabled(false);
    ui->pushButton_program_07->setDisabled(false);
    ui->pushButton_program_08->setDisabled(false);
    ui->pushButton_program_09->setDisabled(false);
    ui->pushButton_program_10->setDisabled(false);
    ui->pushButton_program_11->setDisabled(false);
    ui->pushButton_program_12->setDisabled(false);
    ui->pushButton_program_13->setDisabled(false);
    ui->pushButton_program_14->setDisabled(false);
    ui->pushButton_program_15->setDisabled(false);
}
