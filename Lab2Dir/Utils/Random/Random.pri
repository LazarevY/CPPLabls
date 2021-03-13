!RANDOM_PRI {

CONFIG += RANDOM_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

HEADERS += \
    $$PWD/probabilitychecker.h \
    $$PWD/randomgenerator.h

SOURCES += \
    $$PWD/probabilitychecker.cpp \
    $$PWD/randomgenerator.cpp

}
