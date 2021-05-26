!LAB4_PRI {

CONFIG += LAB4_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include($$PWD/GUI/GUI.pri)
include($$PWD/Logic/Logic.pri)
include($$PWD/Logging/Logging.pri)
include($$PWD/Utils/Utils.pri)

}
