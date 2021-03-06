QT -= gui
QT += quick

CONFIG += c++17

TARGET = verovio-qt
TEMPLATE = lib

DEFINES += VEROVIOQT_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

QMAKE_CFLAGS_WARN_ON += -Wno-unused-parameter
QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter

SOURCES += \
    src/scenegraphdevicecontext.cpp \
    src/textquickitem.cpp \
    src/toolkit.cpp \
    src/view.cpp

HEADERS += \
    include/vrvqt/scenegraphdevicecontext.h \
    include/vrvqt/textquickitem.h \
    include/vrvqt/toolkit.h \
    include/vrvqt/view.h

INCLUDEPATH += include

{
    INCLUDEPATH += ../../../include/
    INCLUDEPATH += ../../../include/vrv
    INCLUDEPATH += ../../../include/pugi
    INCLUDEPATH += ../../../include/utf8
    INCLUDEPATH += ../../../include/json
    INCLUDEPATH += ../../../libmei
}

android {
    message("* Using settings for Android.")

    LIBS += -L../../android/libs/armeabi-v7a -lverovio-android
}
else {
    message("* Using settings for Other (Linux, Mac, Windows, ...).")

    LIBS += -L../../../tools/build-library -lverovio
}

unix {
    target.path = /usr/lib
    INSTALLS += target
}
