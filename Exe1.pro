TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    transport.cpp \
    ship.cpp \
    product.cpp \
    building.cpp \
    people.cpp

unix:!macx: LIBS += -L$$(SYSTEMC_HOME)/lib-linux/ -lsystemc-2.3.1

INCLUDEPATH += $$(SYSTEMC_HOME)/include
DEPENDPATH += $$(SYSTEMC_HOME)/include

HEADERS += \
    transport.h \
    ship.h \
    product.h \
    send_human_if.h \
    send_product_if.h \
    send_building_if.h \
    building.h \
    people.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../_systemc/systemc_lib/release/ -lSystemC
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../_systemc/systemc_lib/debug/ -lSystemC

INCLUDEPATH += $$PWD/../../../../../../_systemc/systemc
DEPENDPATH += $$PWD/../../../../../../_systemc/systemc
