!LAB2_PRI {

CONFIG += LAB2_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)


include($$PWD/ObjectsHandlers/ObjectsHandlers.pri)
include($$PWD/Logic/Logic.pri)
include($$PWD/Objects/Objects.pri)
include($$PWD/Utils/Vector/Vector.pri)
include($$PWD/Utils/Functions/Functions.pri)
include($$PWD/Render/Rendering.pri)
include($$PWD/Logging/Logging.pri)
include($$PWD/UI/UI.pri)


}
