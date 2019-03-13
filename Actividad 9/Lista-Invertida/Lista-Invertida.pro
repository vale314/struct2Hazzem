TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    libro.cpp \
    biblioteca.cpp \
    tdaindice.cpp \
    tdalistainvertida.cpp \
    administrador.cpp \
    tdageneros.cpp

HEADERS += \
    libro.h \
    biblioteca.h \
    tdaindice.h \
    tdalistainvertida.h \
    list.hpp \
    list.h \
    administrador.h \
    tdageneros.h
