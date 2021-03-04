!OBJECTSHANDLERS_PRI {

CONFIG += OBJECTSHANDLERS_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include($$PWD/../Objects/Objects.pri)

HEADERS += \
    $$PWD/molehanlder.h \
    $$PWD/objecthandler.h \
    $$PWD/baseobjecthandler.h

SOURCES += \
    $$PWD/molehanlder.cpp \
    $$PWD/objecthandler.cpp \
    $$PWD/baseobjecthandler.cpp
}
