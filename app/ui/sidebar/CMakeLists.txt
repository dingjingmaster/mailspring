project(sidebar)

add_executable(ui-sidebar ui-sidebar.cpp ${SIDEBAR_SOURCES} ${WIDGET_SOURCES})
target_link_libraries(ui-sidebar ${QT5BASE_LIBRARIES})
target_include_directories(ui-sidebar PUBLIC ${QT5BASE_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR})