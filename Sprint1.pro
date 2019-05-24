TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    tweet.cpp \
    dsstring.cpp \
    test.cpp

HEADERS += \
    tweet.h \
    dsstring.h \
    catch.hpp
