!LOGIC_PRI {

CONFIG += LOGIC_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include($$PWD/../Objects/Objects.pri)
include($$PWD/../ObjectsHandlers/ObjectsHandlers.pri)
include($$PWD/../GlobalContext/GlobalContext.pri)


HEADERS += \
    $$PWD/field.h \
    $$PWD/fieldcell.h \
    $$PWD/logic.h

SOURCES += \
    $$PWD/field.cpp \
    $$PWD/fieldcell.cpp \
    $$PWD/logic.cpp

}
