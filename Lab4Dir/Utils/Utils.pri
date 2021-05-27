!UTILS_PRI {

CONFIG += UTILS_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

HEADERS += \
    $$PWD/pathutils.h

SOURCES += \
    $$PWD/pathutils.cpp

}

HEADERS += \
    $$PWD/dataparsing.h

SOURCES += \
    $$PWD/dataparsing.cpp

