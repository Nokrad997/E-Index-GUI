QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Admin.cpp \
    Student.cpp \
    Teacher.cpp \
    Person.cpp \
    addabsence.cpp \
    addgrades.cpp \
    addstudent.cpp \
    addteacher.cpp \
    addtest.cpp \
    adminwindow.cpp \
    edituserdata.cpp \
    main.cpp \
    mainwindow.cpp \
    registration.cpp \
    studentwindow.cpp \
    userwindow.cpp

HEADERS += \
    Person.h \
    Admin.h \
    Student.h \
    Teacher.h \
    AdminRepository.h \
    StudentRepository.h \
    TeacherRepository.h \
    addabsence.h \
    addgrades.h \
    addstudent.h \
    addteacher.h \
    addtest.h \
    adminwindow.h \
    edituserdata.h \
    mainwindow.h \
    registration.h \
    studentwindow.h \
    userwindow.h

FORMS += \
    addabsence.ui \
    addgrades.ui \
    addstudent.ui \
    addteacher.ui \
    addtest.ui \
    adminwindow.ui \
    edituserdata.ui \
    mainwindow.ui \
    registration.ui \
    studentwindow.ui \
    userwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
