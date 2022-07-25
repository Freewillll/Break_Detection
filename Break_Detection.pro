
TEMPLATE	= lib
CONFIG	+= qt plugin warn_off
QMAKE_CXXFLAGS += -std=c++0x
#CONFIG	+= x86_64
win32:VAA3DPATH = D:\Vaa3d\v3d_external
unix:!macx:VAA3DPATH = /home/freewill/Vaa3d/v3d_external
INCLUDEPATH	+= $$VAA3DPATH/v3d_main/basic_c_fun



win32 {
    contains(QMAKE_HOST.arch, x86_64) {
    LIBS     += -L$$VAA3DPATH/v3d_main/common_lib/mingw64 -lv3dtiff
    LIBS     += -L$$VAA3DPATH/v3d_main/common_lib/mingw64 -lv3dnewmat
    } else {
    LIBS     += -L$$VAA3DPATH/v3d_main/common_lib/mingw -lv3dtiff
    LIBS     += -L$$VAA3DPATH/v3d_main/common_lib/mingw -lv3dnewmat
    }
}

unix:!macx {
    LIBS += -L$$VAA3DPATH/v3d_main/common_lib/lib -ltiff
    LIBS += -L$$VAA3DPATH/v3d_main/jba/c++ -lv3dnewmat
    QMAKE_CXXFLAGS += -fopenmp
    LIBS += -fopenmp
}


HEADERS	+= Break_Detection_plugin.h \
    help_func.h \
    log.h
SOURCES	+= Break_Detection_plugin.cpp \
    help_func.cpp
SOURCES	+= $$VAA3DPATH/v3d_main/basic_c_fun/v3d_message.cpp
SOURCES += $$VAA3DPATH/v3d_main/basic_c_fun/basic_surf_objs.cpp


TARGET	= $$qtLibraryTarget(Break_Detection)
DESTDIR	= $$VAA3DPATH/bin/plugins/Break_Detection/
