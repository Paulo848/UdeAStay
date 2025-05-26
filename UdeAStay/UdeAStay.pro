TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        alojamiento.cpp \
        anfitrion.cpp \
        huesped.cpp \
        main.cpp \
        fecha.cpp \
        reservacion.cpp \
        utilid.cpp

HEADERS += \
    alojamiento.h \
    anfitrion.h \
    fecha.h \
    huesped.h \
    reservacion.h \
    utilid.h
