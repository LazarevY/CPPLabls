!OBJECTSHANDLERS_PRI {

CONFIG += OBJECTSHANDLERS_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include($$PWD/../Objects/Objects.pri)
include($$PWD/../Utils/Functions/Functions.pri)
include($$PWD/../Utils/Random/Random.pri)

HEADERS += \
    $$PWD/molehanlder.h \
    $$PWD/objecthandler.h \
    $$PWD/baseobjecthandler.h \
    $$PWD/cottagerhandler.h \
    $$PWD/harvestremovehandler.h

SOURCES += \
    $$PWD/molehanlder.cpp \
    $$PWD/objecthandler.cpp \
    $$PWD/baseobjecthandler.cpp \
    $$PWD/cottagerhandler.cpp \
    $$PWD/harvestremovehandler.cpp
}
