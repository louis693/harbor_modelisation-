TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../_systemc/systemc_lib/release/ -lSystemC
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../_systemc/systemc_lib/debug/ -lSystemC
else:unix: LIBS += -L$$PWD/../../../../../../_systemc/systemc_lib/ -lSystemC

INCLUDEPATH += $$PWD/../../../../../../_systemc/systemc
DEPENDPATH += $$PWD/../../../../../../_systemc/systemc
