project(TestApp)

find_package(Qt5 5.15.2 COMPONENTS Quick Widgets Core REQUIRED)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME}
    main.cpp
    src/basiccontroller.cpp
    src/entryview/entryviewcontroller.cpp

    src/basiccontroller.h
    src/entryview/entryviewcontroller.h

    qml.qrc
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${srcgui_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(${PROJECT_NAME} PROPERTIES AUTOMOC ON AUTORCC ON AUTOUIC ON)
target_link_libraries(${PROJECT_NAME}
    Qt5::Quick
    Qt5::Widgets
    Qt5::Core
)
