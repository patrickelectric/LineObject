QT += core 3dcore 3drender 3dinput 3dextras qml quick widgets

SOURCES += \
    linemeshgeometry.cpp \
    linemesh.cpp \
    gridmesh.cpp \
    mainwindow.cpp \
    main.cpp

HEADERS +=\
    linemeshgeometry.h \
    linemesh.h\
    gridmesh.h \
    mainwindow.h

OTHER_FILES += \
    AnimatedEntity.qml \
    main.qml

RESOURCES += \
    main.qrc

FORMS += \
    mainwindow.ui

CONFIG += debug