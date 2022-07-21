
TEMPLATE	= lib
CONFIG	+= qt plugin warn_off
QT += widgets
#CONFIG	+= x86_64
VAA3DPATH = D:/Vaa3d_QT6/v3d_external
INCLUDEPATH	+= $$VAA3DPATH/v3d_main/basic_c_fun
VAA3DRELEASE = D:/Vaa3D_v6.3.0


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
    LIBS += -L$$VAA3DPATH/v3d_main/common_lib/lib_ubuntu -lv3dtiff
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
DESTDIR	= $$VAA3DRELEASE/plugins/Break_Detection/
