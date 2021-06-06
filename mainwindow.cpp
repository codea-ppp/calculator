#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <new>
#include "QPushButton"
#include "QRadioButton"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->textBrowser_show_program_calculator->setFontPointSize(30);
    ui->textBrowser_show_science_calculator->setFontPointSize(30);

    computer = new(std::nothrow) Compute();
    if (nullptr == computer)
        abort();

    // inialization the message getter
    messageGeter = new(std::nothrow) MessageGeter();
    if (nullptr == messageGeter)
        abort();

    // set the inialization of virtual keyboard
    iniVirtualPuttons();

    // build the connection between MessageGetter and virtual keyboard
    messagePassPort();

    // build the connection amount the buttons
    setLockAndUnlockOnInput();

    // set connection between radioButton and virtual keyboard
    radioButtonBanVirtualKeyboard();

    // inialization with the binary mode
    ui->radioButton_binary->setDisabled(false);
    ui->radioButton_binary->click();
    myAllowProgramNumbersGetter();
}

MainWindow::~MainWindow()
{
    delete messageGeter;
    delete computer;
    delete ui;
}

void MainWindow::fleshTextGetter(QString string, bool which)
{
    if (which)
        ui->textBrowser_show_program_calculator->setText(string);
    else
        ui->textBrowser_show_science_calculator->setText(string);
}

// the message analyze connections will build here
void MainWindow::setLockAndUnlockOnInput()
{
    // reinialization
    connect(ui->pushButton_program_90, &QPushButton::pressed,
            this, &MainWindow::iniVirtualProgramPutton);
    connect(ui->pushButton_science_90, &QPushButton::pressed,
            this, &MainWindow::iniVirtualSciencePutton);

    // special for the number in different decimal
    connect(this, &MainWindow::myAllowProgramNumbersGetter,
            this, &MainWindow::rebuildconnectProgramForBinaryStyle);
    connect(this, &MainWindow::myAllowProgramNumbersGetter,
            this, &MainWindow::rebuildconnectProgramForOctalStyle);
    connect(this, &MainWindow::myAllowProgramNumbersGetter,
            this, &MainWindow::rebuildconnectProgramForHexadecimalStyle);


    // other connections
    // special for "0" button because "/"
    connect(messageGeter, &MessageGeter::myBlockScienceZeroSender,
            this, &MainWindow::myBlockScienceZeroGetter);
    connect(messageGeter, &MessageGeter::myBlockProgramZeroSender,
            this, &MainWindow::myBlockProgramZeroGetter);

    // special for "-" because it can be a number and a two operands operator
    connect(messageGeter, &MessageGeter::myAllowScienceLessSender,
            this, &MainWindow::myAllowScienceLessGetter);
    connect(messageGeter, &MessageGeter::myAllowProgramLessSender,
            this, &MainWindow::myAllowScienceLessGetter);

    // allows for program mode
    connect(messageGeter, &MessageGeter::myAllowProgramBackSender,
            this, &MainWindow::myAllowProgramBackGetter);
    connect(messageGeter, &MessageGeter::myAllowProgramLeftBracketSender,
            this, &MainWindow::myAllowProgramLeftBracketGetter);
    connect(messageGeter, &MessageGeter::myAllowProgramNodeSender,
            this, &MainWindow::myAllowProgramNodeGetter);
    connect(messageGeter, &MessageGeter::myAllowProgramNumbersSender,
            this, &MainWindow::myAllowProgramNumbersGetter);
    connect(messageGeter, &MessageGeter::myAllowProgramOneOperandsOperatorsSender,
            this, &MainWindow::myAllowProgramOneOperandsOperatorsGetter);
    connect(messageGeter, &MessageGeter::myAllowProgramRightBracketSender,
            this, &MainWindow::myAllowProgramRightBracketGetter);
    /* as "-" is been handle specially */
    connect(messageGeter, &MessageGeter::myAllowProgramTwoOperandsOperatorsSender,
            this, &MainWindow::myAllowProgramTwoOperandsOperatorsGetter);

    // allows for science mode
    connect(messageGeter, &MessageGeter::myAllowScienceBackSender,
            this, &MainWindow::myAllowScienceBackGetter);
    connect(messageGeter, &MessageGeter::myAllowScienceLeftBracketSender,
            this, &MainWindow::myAllowScienceLeftBracketGetter);
    connect(messageGeter, &MessageGeter::myAllowScienceNodeSender,
            this, &MainWindow::myAllowScienceNodeGetter);
    connect(messageGeter, &MessageGeter::myAllowScienceNumbersSender,
            this, &MainWindow::myAllowScienceNumbersGetter);
    connect(messageGeter, &MessageGeter::myAllowScienceOneOperandsOperatorsSender,
            this, &MainWindow::myAllowScienceOneOperandsOperatorsGetter);
    connect(messageGeter, &MessageGeter::myAllowScienceRightBracketSender,
            this, &MainWindow::myAllowScienceRightBracketGetter);
    /* as "-" is been handle specially */
    connect(messageGeter, &MessageGeter::myAllowScienceTwoOperandsOperatorsSender,
            this, &MainWindow::myAllowScienceTwoOperandsOperatorsGetter);

    // blocks for program mode
    connect(messageGeter, &MessageGeter::myBlockProgramBackSender,
            this, &MainWindow::myBlockProgramBackGetter);
    connect(messageGeter, &MessageGeter::myBlockProgramLeftBracketSender,
            this, &MainWindow::myBlockProgramLeftBracketGetter);
    connect(messageGeter, &MessageGeter::myBlockProgramNodeSender,
            this, &MainWindow::myBlockProgramNodeGetter);
    connect(messageGeter, &MessageGeter::myBlockProgramNumbersSender,   /* as "0" is been handle specially */
            this, &MainWindow::myBlockProgramNumbersGetter);
    connect(messageGeter, &MessageGeter::myBlockProgramOneOperandsOperatorsSender,
            this, &MainWindow::myBlockProgramOneOperandsOperatorsGetter);
    connect(messageGeter, &MessageGeter::myBlockProgramRightBracketSender,
            this, &MainWindow::myBlockProgramRightBracketGetter);
    connect(messageGeter, &MessageGeter::myBlockProgramTwoOperandsOperatorsSender,
            this, &MainWindow::myBlockProgramTwoOperandsOperatorsGetter);

    // blocks for science mode
    connect(messageGeter, &MessageGeter::myBlockScienceSpecialNumberSender,
            this, &MainWindow::myBlocksScienceSpecialNumbersGetter);
    connect(messageGeter, &MessageGeter::myBlockScienceBackSender,
            this, &MainWindow::myBlockScienceBackGetter);
    connect(messageGeter, &MessageGeter::myBlockScienceLeftBracketSender,
            this, &MainWindow::myBlockScienceLeftBracketGetter);
    connect(messageGeter, &MessageGeter::myBlockScienceNodeSender,
            this, &MainWindow::myBlockScienceNodeGetter);
    connect(messageGeter, &MessageGeter::myBlockScienceNumbersSender,   /* as "0" is been handle specially */
            this, &MainWindow::myBlockScienceNumbersGetter);
    connect(messageGeter, &MessageGeter::myBlockScienceOneOperandsOperatorsSender,
            this, &MainWindow::myBlockScienceOneOperandsOperatorsGetter);
    connect(messageGeter, &MessageGeter::myBlockScienceRightBracketSender,
            this, &MainWindow::myBlockScienceRightBracketGetter);
    connect(messageGeter, &MessageGeter::myBlockScienceTwoOperandsOperatorsSender,
            this, &MainWindow::myBlockScienceTwoOperandsOperatorsGetter);

    // back at end is CE
    connect(messageGeter, &MessageGeter::myScienceCESender,
            this, &MainWindow::iniVirtualSciencePutton);
    connect(messageGeter, &MessageGeter::myProgramCESender,
            this, &MainWindow::iniVirtualProgramPutton);
}

// connect the functions which contrl virtual keyboard style
void MainWindow::radioButtonBanVirtualKeyboard()
{

    // program calculator virtual keyboard settings
    // virtual keyboard ui connections
    connect(ui->radioButton_binary, &QRadioButton::pressed,
            this, &MainWindow::keyboard_binary_style);
    connect(ui->radioButton_octal, &QRadioButton::pressed,
            this, &MainWindow::keyboard_octal_style);
    connect(ui->radioButton_hexadecimal, &QRadioButton::pressed,
            this, &MainWindow::keyboard_hexadecimal_style);


    connect(ui->radioButton_binary, &QRadioButton::pressed,
            computer, &Compute::setBinary);
    connect(ui->radioButton_octal, &QRadioButton::pressed,
            computer, &Compute::setOctal);
    connect(ui->radioButton_hexadecimal, &QRadioButton::pressed,
            computer, &Compute::setHexadecimal);

    return;
}

// this function connect button with messageGetter
void MainWindow::messagePassPort()
{
    // radio buttons
    connect(ui->radioButton_binary, &QRadioButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->radioButton_octal, &QRadioButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->radioButton_hexadecimal, &QRadioButton::pressed,
            messageGeter, &MessageGeter::getMessage);

    // feed back the input result
    connect(messageGeter, &MessageGeter::fleshTextSender,
            this, &MainWindow::fleshTextGetter);
    connect(computer, &Compute::fleshTextSender,
            this, &MainWindow::fleshTextGetter);

    // connection between compute and messageGetter
    connect(messageGeter, &MessageGeter::containerScienceSender,
            computer, &Compute::containerScienceGetter);
    connect(messageGeter, &MessageGeter::containerProgramSender,
            computer, &Compute::containerProgramGetter);

    connect(computer, &Compute::resultScienceSender,
            messageGeter, &MessageGeter::getMessageFromComputeScience);
    connect(computer, &Compute::resultProgramSender,
            messageGeter, &MessageGeter::getMessageFromComputeProgram);

    // the connection between the button and message getter
    // connect the program mode buttons with message getter
    // basic number
    connect(ui->pushButton_program_00, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_program_01, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_program_02, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_program_03, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_program_04, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_program_05, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_program_06, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_program_07, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_program_08, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_program_09, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_program_10, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_program_11, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_program_12, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_program_13, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_program_14, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_program_15, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);

    // 6 kinds basic operation
    connect(ui->pushButton_program_20, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_program_21, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_program_22, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_program_23, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_program_24, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);

    // the equal
    connect(ui->pushButton_program_50, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);

    // 8 kinds logic operation
    connect(ui->pushButton_program_30, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_program_31, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_program_32, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_program_33, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_program_34, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_program_35, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_program_36, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_program_37, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);

    // brackets
    connect(ui->pushButton_program_92, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_program_93, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);

    // clear options
    connect(ui->pushButton_program_90, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_program_91, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);

    // node options
    connect(ui->pushButton_program_94, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);


    // connect the science mode buttons with message getter
    // basic number
    connect(ui->pushButton_science_00, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_science_01, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_science_02, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_science_03, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_science_04, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_science_05, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_science_06, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_science_07, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_science_08, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_science_09, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);

    // special number
    connect(ui->pushButton_science_10, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_science_11, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);

    // 5 kinds basic operation
    connect(ui->pushButton_science_20, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_science_21, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_science_22, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_science_23, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_science_24, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);

    // the equal
    connect(ui->pushButton_science_50, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);

    // 12 kinds advance operations
    connect(ui->pushButton_science_30, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_science_31, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_science_32, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_science_33, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_science_34, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_science_35, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_science_36, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_science_37, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_science_38, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);

    // brackets
    connect(ui->pushButton_science_92, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_science_93, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);

    // clear options
    connect(ui->pushButton_science_90, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);
    connect(ui->pushButton_science_91, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);

    // node options
    connect(ui->pushButton_science_94, &QPushButton::pressed,
            messageGeter, &MessageGeter::getMessage);

    return;
}
