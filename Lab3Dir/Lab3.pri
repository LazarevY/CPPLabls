!LAB3_PRI {

CONFIG += LAB3_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)


include($$PWD/AssociativeArray/AssociativeArray.pri)
include($$PWD/CLIUtils/CLIUtils.pri)

HEADERS += \
    $$PWD/hashtablecli.h

SOURCES += \
    $$PWD/hashtablecli.cpp
}

