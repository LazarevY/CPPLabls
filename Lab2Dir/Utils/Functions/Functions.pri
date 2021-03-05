!FUNCTIONS_PRI {

CONFIG += FUNCTIONS_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

HEADERS += \
    $$PWD/function.h \
    $$PWD/maptablefunctionimpl.h \
    $$PWD/tablefunction.h

SOURCES += \
    $$PWD/function.cpp \
    $$PWD/maptablefunctionimpl.cpp \
    $$PWD/tablefunction.cpp

}

