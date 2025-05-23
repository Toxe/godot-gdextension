set(GODOTCPP_SUFFIX $<GENEX_EVAL:$<TARGET_PROPERTY:godot::cpp,GODOTCPP_SUFFIX>>)

add_library(${PROJECT_NAME} SHARED
    gdexample.cpp
    gdexample.hpp
    register_types.cpp
    register_types.hpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_EXTENSIONS OFF
    FOLDER ${PROJECT_NAME}
    PREFIX ""
    OUTPUT_NAME "${PROJECT_NAME}${GODOTCPP_SUFFIX}"
    RUNTIME_OUTPUT_DIRECTORY "$<1:${GDEXTENSION_LIBRARY_OUTPUT_DIRECTORY}>"
    LIBRARY_OUTPUT_DIRECTORY "$<1:${GDEXTENSION_LIBRARY_OUTPUT_DIRECTORY}>"
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_23)
target_compile_options(${PROJECT_NAME} PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
target_link_options(${PROJECT_NAME} PRIVATE ${SANITIZER_LINK_OPTIONS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${SANITIZER_LINK_LIBRARIES} godot::cpp)
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

get_target_property("${PROJECT_NAME}_sources" ${PROJECT_NAME} SOURCES)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX "Sources" FILES "${PROJECT_NAME}_sources")

# automatically generate the .gdextension file in the Godot project /bin directory
configure_file(gdextension.in "${GDEXTENSION_LIBRARY_OUTPUT_DIRECTORY}/${PROJECT_NAME}.gdextension" NEWLINE_STYLE UNIX)
