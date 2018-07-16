#-------------------------------------------------
#
# Project created by QtCreator 2018-07-02T12:46:49
#
#-------------------------------------------------

QT       += core gui
QT       += network sql xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTMessager
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    chatunit/ChatUnit.cpp\
    chatunit/ChatServer.cpp\
    entity/Client.cpp\
    entity/Request.cpp\
    entity/requests/GetClientsRequest.cpp\
    entity/responces/GetClientsResponse.cpp\
    entity/Response.cpp\
     chatunit/ChatClient.cpp\
     request_executors/IRequestExecutor.cpp\
     request_executors/GetClientsExeutor.cpp\
      request_executors/MessageExecutor.cpp\
      entity/requests/MessageRequest.cpp\
      entity/responces/MessageResponse.cpp \
    GUI/implement/MainWindow.cpp \
    GUI/implement/ConnectDialog.cpp \
    GUI/Presenter/Presenter.cpp \
    GUI/implement/ToolsDialog.cpp





HEADERS += \
    chatunit/ChatUnit.h\
    chatunit/ChatServer.h\
    chatunit/IUnit.h\
    entity/Client.h\
    entity/Request.h\
    entity/requests/GetClientsRequest.h\
    entity/responces/GetClientsResponse.h\
    entity/Response.h\
    chatunit/ChatClient.h\
    request_executors/IRequestExecutor.h\
    request_executors/GetClientsExeutor.h\
    request_executors/MessageExecutor.h\
    entity/requests/MessageRequest.h\
    entity/responces/MessageResponse.h \
    GUI/implement/MainWindow.h \
    GUI/implement/ConnectDialog.h \
    GUI/Presenter/Presenter.h \
    GUI/implement/ToolsDialog.h












FORMS += \
    GUI/formsUi/MainWindow.ui \
    GUI/formsUi/ConnectDialog.ui \
    GUI/formsUi/ToolsDialog.ui
