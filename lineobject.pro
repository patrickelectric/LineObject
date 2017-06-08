QT += core 3dcore 3drender 3dinput 3dextras qml quick

SOURCES += \
    gcodeto3d.cpp \
    linemeshgeometry.cpp \
    linemesh.cpp \
    gridmesh.cpp \
    main.cpp

HEADERS +=\
    gcodeto3d.h \
    linemeshgeometry.h \
    linemesh.h\
    gridmesh.h

OTHER_FILES += \
    AnimatedEntity.qml
    main.qml

RESOURCES += \
    main.qrc
