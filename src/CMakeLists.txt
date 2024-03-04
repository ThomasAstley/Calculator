qt_add_executable(Calculator
    mainwindow.ui
    mainwindow.cpp
    main.cpp
)

target_link_libraries(Calculator PRIVATE Qt6::Widgets Qt6::Gui Qt6::Core)

set_target_properties(Calculator PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)