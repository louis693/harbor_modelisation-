TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

TARGET = Model
DESTDIR = $$PJDIR/exec
OBJECTS_DIR = $$PJDIR/temp/$$TARGET

HEADERS += \
    building.h \
    harbor.h \
    interfaces.h \
    people.h \
    product.h \
    ship.h \
    transport.h

SOURCES += main.cpp \
    building.cpp \
    people.cpp \
    product.cpp \
    ship.cpp \
    transport.cpp

#Linking SystemC
#Unix
unix:LIBS += -L$$(SYSTEMC_HOME)/lib-linux/ -lsystemc-2.3.1
unix:INCLUDEPATH += $$(SYSTEMC_HOME)/include
unix:DEPENDPATH += $$(SYSTEMC_HOME)/include

#Windows
win32:LIBS += -L$$PJDIR/lib/ -lSystemC
win32:INCLUDEPATH += $$PJDIR/src/systemc/src
win32:DEPENDPATH += $$PJDIR/src/systemc/src


