QT       += core gui

#To enable, e.g., address sanitizer you have to write:

CONFIG += sanitizer sanitize_address
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    dialog.cpp

HEADERS += \
    dialog.h

FORMS += \
    dialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
//########################################################################################################
//QMAKE_CXXFLAGS += -fsanitize=undefined
QMAKE_CXXFLAGS += -fsanitize=undefined
LIBS += -lubsan
