# Define the application project
project(ArcheApp)

# Add all the source files in the app/src directory
file(GLOB_RECURSE SOURCES "src/*.cpp" "include/*.h")

# Create an executable
add_executable(ArcheApp ${SOURCES})

# Link the Arche library
target_link_libraries(ArcheApp PRIVATE Arche)

# Ensure the library is found
target_include_directories(ArcheApp PRIVATE ${CMAKE_SOURCE_DIR}/lib/include
                                            ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Set the output directory for the executable
set_target_properties(ArcheApp PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Optional: Enable warnings and treat them as errors
if (CMAKE_COMPILER_IS_GNUCXX)
    target_compile_options(ArcheApp PRIVATE -Wall -Wextra -Werror)
endif()

# Optional: Install rules
install(TARGETS ArcheApp
        RUNTIME DESTINATION bin)
