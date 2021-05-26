!LOGGERS_PRI {

CONFIG += LOGGERS_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

HEADERS += \
    $$PWD/guilogger.h \
    $$PWD/logger.h \
    $$PWD/consolelogger.h \
    $$PWD/multilogger.h \
    $$PWD/doublelogger.h \
    $$PWD/mocklogger.h \
    $$PWD/filelogger.h

SOURCES += \
    $$PWD/guilogger.cpp \
    $$PWD/logger.cpp \
    $$PWD/consolelogger.cpp \
    $$PWD/multilogger.cpp \
    $$PWD/doublelogger.cpp \
    $$PWD/mocklogger.cpp \
    $$PWD/filelogger.cpp
}

