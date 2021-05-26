!LOGIC_PRI {

CONFIG += LOGIC_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

HEADERS += \
    $$PWD/case.h \
    $$PWD/casetable.h \
    $$PWD/nocasefoundexception.h

SOURCES += \
    $$PWD/case.cpp \
    $$PWD/casetable.cpp \
    $$PWD/nocasefoundexception.cpp

}

