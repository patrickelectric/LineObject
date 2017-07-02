QT += core 3dcore 3drender 3dinput 3dextras qml quick testlib

SOURCES += \
    gcodeto3d.cpp \
    linemeshgeometry.cpp \
    linemesh.cpp \
    linemeshpart.cpp \
    gridmesh.cpp \
    main.cpp

HEADERS +=\
    gcodeto3d.h \
    linemeshgeometry.h \
    linemesh.h \
    linemeshpart.h \
    gridmesh.h

OTHER_FILES += \
    AnimatedEntity.qml \
    main.qml \
    WireframeMaterial.qml \

RESOURCES += \
    main.qrc
