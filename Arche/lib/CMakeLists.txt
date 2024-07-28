# Define the library project
project(ArcheLib)

# Add all the source files in the lib/src and lib/include directories
file(GLOB_RECURSE SOURCES "src/*.cpp" "include/*.h")

# Create Dynamic Library
add_library(Arche SHARED ${SOURCES})

target_link_libraries(Arche PRIVATE spdlog::spdlog)

# Export the include directory
target_include_directories(Arche PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Define BUILD_SHARED_LIB to handle export macros
target_compile_definitions(Arche PRIVATE BUILD_SHARED_LIB)

# Set the output directories for the library
set_target_properties(Arche PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Optional: Enable warnings and treat them as errors
if (CMAKE_COMPILER_IS_GNUCXX)
    target_compile_options(Arche PRIVATE -Wall -Wextra -Werror)
endif()

# Optional: Install rules
install(TARGETS Arche
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

install(DIRECTORY include/ DESTINATION include)
