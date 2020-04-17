
# Create Library
add_library( UpsilonRender STATIC
    Render.c
)

# Library Include
target_include_directories(UpsilonRender PUBLIC "${PROJECT_SOURCE_DIR}/Include/Base")
target_include_directories(UpsilonRender PUBLIC "${PROJECT_SOURCE_DIR}/Include/Math")
target_include_directories(UpsilonRender PUBLIC "${PROJECT_SOURCE_DIR}/Include/Render")

# Find 3rd Libraries
find_package(OpenGL REQUIRED FATAL_ERROR)
find_package(Vulkan REQUIRED)

# Add 3rd Libraries Include
target_include_directories(OpenGL::GL)

if(Vulkan_FOUND)
    target_include_directories(UpsilonRender  PUBLIC Vulkan::Vulkan)
endif()

# Link 3rd Party Libraries
target_link_libraries(UpsilonRender Vulkan::Vulkan)



