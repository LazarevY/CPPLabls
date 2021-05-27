!UTILS_PRI {

CONFIG += UTILS_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

HEADERS += \
    $$PWD/pathutils.h

SOURCES += \
    $$PWD/pathutils.cpp

}

HEADERS += \
    $$PWD/appexception.h \
    $$PWD/dataparsing.h \
    $$PWD/datawriting.h

SOURCES += \
    $$PWD/appexception.cpp \
    $$PWD/dataparsing.cpp \
    $$PWD/datawriting.cpp

