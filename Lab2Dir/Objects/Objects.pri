!OBJECTS_PRI {

CONFIG += OBJECTS_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include($$PWD/../Utils/Vector.pri)

HEADERS += \
    $$PWD/baseobject.h \
    $$PWD/movingobject.h \
    $$PWD/cottager.h \
    $$PWD/mole.h

SOURCES += \
    $$PWD/baseobject.cpp \
    $$PWD/movingobject.cpp \
    $$PWD/cottager.cpp \
    $$PWD/mole.cpp


}
