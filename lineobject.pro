QT += core 3dcore 3drender 3dinput 3dextras qml quick

SOURCES += \
    linemeshgeometry.cpp \
    #linemesh.cpp \
    gridmesh.cpp \
    main.cpp

HEADERS +=\
    linemeshgeometry.h \
    #linemesh.h\
    gridmesh.h

OTHER_FILES += \
    AnimatedEntity.qml
    main.qml

RESOURCES += \
    main.qrc
