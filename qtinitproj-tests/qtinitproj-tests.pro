include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)

# Custom build paths
DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/.obj
MOC_DIR = $$PWD/build/$$DESTINATION_PATH/.moc
RCC_DIR = $$PWD/build/$$DESTINATION_PATH/.qrc
UI_DIR = $$PWD/build/$$DESTINATION_PATH/.ui

QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase c++14
CONFIG -= app_bundle

TARGET = client-tests
TEMPLATE = app

INCLUDEPATH += source

SOURCES +=  source/models/client-tests.cpp
