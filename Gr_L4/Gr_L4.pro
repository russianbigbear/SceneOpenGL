QT += 3dcore 3drender 3dinput 3dextras opengl

LIBS += -lopengl32 -lglut -lglu32

SOURCES += \
    main.cpp \
    orbittransformcontroller.cpp \
    my3d.cpp

HEADERS += \
    orbittransformcontroller.h \
    my3d.h
