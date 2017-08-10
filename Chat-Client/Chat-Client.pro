#-------------------------------------------------
#
# Project created by QtCreator 2017-03-15T10:35:45
#
#-------------------------------------------------

QT       += core gui sql network
#LIBS     += -lcrypto
#HEADERS  += /usr/local/include/botan-2/botan/botan.h
#INCLUDEPATH += /usr/local/include/botan-2/botan
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chat-Client
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    about.cpp \
    regist.cpp \
    addfriend.cpp \
    filesend.cpp \
    filereceive.cpp \
    database.cpp \
    resetpassword.cpp \
    question.cpp \
    md5.cpp \
    define.cpp \
    chatwidgit.cpp \
    widgt.cpp \
    changepwd.cpp \
    userinfo.cpp \
    Rijndael.cpp \
    aestools.cpp \

HEADERS  += mainwindow.h \
    about.h \
    regist.h \
    define.h \
    addfriend.h \
    filesend.h \
    filereceive.h \
    database.h \
    resetpassword.h \
    question.h \
    md5.h \
    chatwidgit.h \
    widgt.h \
    changepwd.h \
    userinfo.h \
    aestools.h \
    Rijndael.h \

FORMS    += mainwindow.ui \
    about.ui \
    regist.ui \
    addfriend.ui \
    filesend.ui \
    filereceive.ui \
    resetpassword.ui \
    question.ui \
    chatwidgit.ui \
    widgt.ui \
    changepwd.ui \
    userinfo.ui
