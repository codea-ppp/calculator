#-------------------------------------------------
#
# Project created by QtCreator 2018-12-10T19:39:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = calculator
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    messagegeter.cpp \
    myarray.cpp \
    compute.cpp \
    mainwindow_allow_block.cpp \
    mainwindow_inilization_buttons.cpp \
    mainwindow_virtual_keyboard_style.cpp \
    compute_science.cpp \
    meta_binary_container.cpp \
    pool.cpp \
    meta_binary_container_move.cpp \
    meta_binary_container_logic_compute.cpp \
    meta_binary_container_get_qstring.cpp \
    meta_binary_container_extand.cpp \
    compute_science_change_format.cpp \
    compute_program_change_format.cpp \
    compute_program.cpp \
    bit_node.cpp

HEADERS += \
        mainwindow.h \
    messagegeter.h \
    myarray.h \
    compute.h \
    commands.h \
    checkstring.h \
    meta_binary_container.h \
    pool.h \
    bit_node.h \
    global.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../icons/Iconsmind-Outline-Arrow-OutLeft.ico \
    ../icons/Iconsmind-Outline-Arrow-OutRight.ico
