!UI_PRI {

CONFIG += UI_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include($$PWD/../Logic/Logic.pri)
include($$PWD/../Utils/Random/Random.pri)

HEADERS += \
    $$PWD/abstarctui.h \
    $$PWD/uiimpl.h

SOURCES += \
    $$PWD/abstarctui.cpp \
    $$PWD/uiimpl.cpp

}

