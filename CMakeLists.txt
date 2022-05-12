project(mailspring)
cmake_minimum_required(VERSION 3.15)

SET(QT_MINIMUM_VERSION "5.12.0")

SET(CMAKE_AUTOUIC ON)
SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTORCC ON)
SET(QT_USE_QTGUI TRUE)
SET(QT_USE_QTXML TRUE)
SET(CMAKE_CXX_STANDARD 11)
SET(MAIL_SPRING_DEBUG 1)
SET(MAIL_SPRING_VERSION "0.0.0")
SET(CMAKE_INCLUDE_DIRECTORIES_BEFORE ON)

ADD_DEFINITIONS("-Wall" "-g" "-O0"
        "-DQT_NO_KEYWORDS"
        "-DAPP_NAME=\"mailspring\""
        "-DDEBUG=${MAIL_SPRING_DEBUG}"
        "-DVERSION=\"${MAIL_SPRING_VERSION}\"")

find_package(PkgConfig)
find_package(Qt5Core "${QT_MINIMUM_VERSION}" REQUIRED)
find_package(Qt5Widgets "${QT_MINIMUM_VERSION}" REQUIRED)

find_package(Threads REQUIRED)

#pkg_check_modules (LIBGLIB REQUIRED glib-2.0 gio-2.0 gio-unix-2.0)
pkg_check_modules (QT5BASE REQUIRED Qt5Widgets)

add_subdirectory(app)