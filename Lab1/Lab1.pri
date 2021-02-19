!LAB1_PRI {

CONFIG += LAB1_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

HEADERS += \
    $$PWD/lab1tests.h \
    $$PWD/mysnprintf.h

SOURCES += \
    $$PWD/lab1tests.cpp \
    $$PWD/mysnprintf.cpp

}

