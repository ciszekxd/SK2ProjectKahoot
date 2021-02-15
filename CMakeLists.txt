cmake_minimum_required(VERSION 3.5)

project(SK2ProjectKahoot LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

find_package(Qt5 COMPONENTS Network REQUIRED)


add_executable(
    SK2ProjectKahoot
    main.cpp
    ./server/server.h
    ./server/server.cpp
    ./client/client.h
    ./client/client.cpp
    #mainwindow.cpp
    #mainwindow.h
    mainwindowv2.cpp
    mainwindowv2.h
    mainwindow.ui
    ./client/clientconnectionmanager.cpp
    ./client/clientconnectionmanager.h
    ./game/gameserver.cpp
    ./game/gameserver.h
    ./game/gameclient.cpp
    ./game/gameclient.h
    ./page/selectionpage.h
    ./page/selectionpage.cpp
    ./page/setpathpage.cpp
    ./page/setpathpage.h
    ./page/page.cpp
    ./page/page.h
    ./page/clientconnectionpage.cpp
    ./page/clientconnectionpage.h
    ./page/gmpage.cpp
    ./page/gmpage.h
    ./page/gamepage.cpp
    ./page/gamepage.h
    ./questions/ABCQandAInterface.hpp
    ./questions/Answer.hpp
    ./questions/QnAManager.hpp
    ./questions/Question.hpp
    )


target_link_libraries(SK2ProjectKahoot PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt5::Network)
