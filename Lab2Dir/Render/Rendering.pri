!RENDERING_PRI {

CONFIG += RENDERING_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include($$PWD/../Utils/Functions/Functions.pri)

HEADERS += \
    $$PWD/fieldrender.h \
    $$PWD/fieldrenderimpl.h

SOURCES += \
    $$PWD/fieldrender.cpp \
    $$PWD/fieldrenderimpl.cpp

}
