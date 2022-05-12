project(ui)

add_subdirectory(sidebar)


add_executable(ui-main-window ui-main-window.cpp main-window.cpp main-window.h)
target_link_libraries(ui-main-window ${QT5BASE_LIBRARIES})
target_include_directories(ui-main-window PUBLIC ${QT5BASE_INCLUDE_DIRS})