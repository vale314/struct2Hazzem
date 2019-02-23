TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    grafo.cpp \
    vertice.cpp \
    arista.cpp \
    menu.cpp

HEADERS += \
    grafo.h \
    vertice.h \
    arista.h \
    ldl.h \
    nodoldl.h \
    menu.h
