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

HEADERS += \
    $$PWD/caselist.h \
    $$PWD/logic.h

SOURCES += \
    $$PWD/caselist.cpp \
    $$PWD/logic.cpp

