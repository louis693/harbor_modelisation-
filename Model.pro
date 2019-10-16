TEMPLATE = subdirs
TARGET = Model

PJDIR = $$PWD
cache (PJDIR, set)

win32: SUBDIRS +=  $$PJDIR/src/systemc 
SUBDIRS +=  $$PJDIR/src/Model 


CONFIG += ordered
