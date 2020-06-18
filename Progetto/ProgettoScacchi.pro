QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    alfiere.cpp \
    cavallo.cpp \
    chessbutton.cpp \
    controller.cpp \
    main.cpp \
    mosseacroce.cpp \
    mosseax.cpp \
    pedone.cpp \
    pezzi.cpp \
    prombutton.cpp \
    re.cpp \
    regina.cpp \
    scacchi.cpp \
    scacchiera.cpp \
    torre.cpp \
    vector.cpp

HEADERS += \
    Arrocco_Exc.h \
    EnPassant_Exc.h \
    Mossa_Imposs.h \
    Mossa_illegale.h \
    Promozione.h \
    alfiere.h \
    cavallo.h \
    chessbutton.h \
    controller.h \
    mosseacroce.h \
    mosseax.h \
    pedone.h \
    pedone.h \
    pezzi.h \
    prombutton.h \
    re.h \
    regina.h \
    scacchi.h \
    scacchiera.h \
    torre.h \
    vector.h \
    winner.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



RESOURCES += \
    resources.qrc
