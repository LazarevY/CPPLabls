!GUI_PRI {

CONFIG += GUI_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

FORMS += \
    $$PWD/mainwindow.ui

HEADERS += \
    $$PWD/mainwindow.h

SOURCES += \
    $$PWD/mainwindow.cpp

}

