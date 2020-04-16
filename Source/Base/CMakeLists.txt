add_library(UpsilonBase STATIC
    Vector.c
)

target_include_directories(UpsilonBase PUBLIC ${PROJECT_SOURCE_DIR}/Include/Base)