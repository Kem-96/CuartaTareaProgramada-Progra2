QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    formproducto.cpp \
    formtienda.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    formproducto.h \
    formtienda.h \
    mainwindow.h

FORMS += \
    formProducto.ui \
    formtienda.ui \
    mainwindow.ui

TRANSLATIONS += \
    ui_es_CR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Tienda_local/release/ -lTienda_local
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Tienda_local/debug/ -lTienda_local
else:unix: LIBS += -L$$OUT_PWD/../Tienda_local/ -lTienda_local

INCLUDEPATH += $$PWD/../Tienda_local
DEPENDPATH += $$PWD/../Tienda_local

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Tienda_local/release/libTienda_local.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Tienda_local/debug/libTienda_local.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Tienda_local/release/Tienda_local.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Tienda_local/debug/Tienda_local.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Tienda_local/libTienda_local.a
