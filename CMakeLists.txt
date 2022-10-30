project(TestApp)

find_package(Qt5 5.15.2 COMPONENTS Quick Widgets Core REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Wshadow -Werror")

add_executable(${PROJECT_NAME}
    main.cpp
    src/basiccontroller.cpp
    src/external/customdialog/customdialogcontroller.cpp
    src/external/datadirectorymanager/datadirectorymanager.cpp
    src/external/utils/utils.cpp
    src/quizmenu/quizmenucontroller.cpp
    src/quizview/quizviewcontroller.cpp
    src/studymenu/studymenucontroller.cpp
    src/testingview/testingviewcontroller.cpp

    src/basiccontroller.h
    src/external/customdialog/customdialogcontroller.h
    src/external/customdialog/customdialogmodel.h
    src/external/datadirectorymanager/datadirectorymanager.h
    src/external/utils/utils.h
    src/quizmenu/quizmenucontroller.h
    src/quizmenu/quizmenupagemodel.h
    src/quizview/quizviewcontroller.h
    src/quizview/quizviewmodel.h
    src/studymenu/studymenucontroller.h
    src/studymenu/studymenupagemodel.h
    src/testingview/testingviewcontroller.h
    src/testingview/testingviewpagemodel.h
    src/testingview/testfunctions.h

    qml.qrc
    resources/resources.qrc
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
