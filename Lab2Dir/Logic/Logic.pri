!LOGIC_PRI {

CONFIG += LOGIC_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)


}

HEADERS += \
    $$PWD/field.h \
    $$PWD/logic.h

SOURCES += \
    $$PWD/field.cpp \
    $$PWD/logic.cpp