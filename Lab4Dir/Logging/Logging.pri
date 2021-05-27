!LOGGERS_PRI {

CONFIG += LOGGERS_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

HEADERS += \
    $$PWD/guilogger.h \
    $$PWD/logger.h \
    $$PWD/consolelogger.h \
    $$PWD/doublelogger.h \
    $$PWD/mocklogger.h \
    $$PWD/filelogger.h \
    $$PWD/difflogger.h


SOURCES += \
    $$PWD/guilogger.cpp \
    $$PWD/logger.cpp \
    $$PWD/consolelogger.cpp \
    $$PWD/doublelogger.cpp \
    $$PWD/mocklogger.cpp \
    $$PWD/filelogger.cpp \
    $$PWD/difflogger.cpp
}

HEADERS += \
    $$PWD/multilogger.h

SOURCES += \
    $$PWD/multilogger.cpp
