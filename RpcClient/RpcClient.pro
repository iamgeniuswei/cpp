TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        proto/echo.pb.cc

DISTFILES += \
    proto/echo.proto

HEADERS += \
    proto/echo.pb.h


INCLUDEPATH +=D:\Project\tools\vcpkg\installed\x64-windows\include
LIBS += D:\Project\tools\vcpkg\installed\x64-windows\lib\libprotobuf.lib
LIBS += D:\Project\tools\vcpkg\installed\x64-windows\lib\libprotoc.lib
LIBS += D:\Project\tools\vcpkg\installed\x64-windows\lib\zlib.lib
