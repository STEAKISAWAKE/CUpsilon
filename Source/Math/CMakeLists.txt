add_library(UpsilonMath STATIC

    # Upsilon
    

    # CGLM
    cglm/affine.c
    cglm/bezier.c
    cglm/box.c
    cglm/cam.c
    cglm/curve.c
    cglm/ease.c
    cglm/euler.c
    cglm/frustum.c
    cglm/io.c
    cglm/mat2.c
    cglm/mat3.c
    cglm/mat4.c
    cglm/plane.c
    cglm/project.c
    cglm/quat.c
    cglm/quat.c
    cglm/ray.c
    cglm/sphere.c
    cglm/vec2.c
    cglm/vec3.c
    cglm/vec4.c
)

target_include_directories(UpsilonMath PUBLIC ${PROJECT_SOURCE_DIR}/Include/Math)