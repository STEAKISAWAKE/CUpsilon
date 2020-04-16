/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*!
 * Most of functions in this header are optimized manually with SIMD
 * if available. You dont need to call/incude SIMD headers manually
 */

/*
 Macros:
   GLMS_MAT4_IDENTITY_INIT
   GLMS_MAT4_ZERO_INIT
   GLMS_MAT4_IDENTITY
   GLMS_MAT4_ZERO

 Functions:
    mat4s   glms_mat4_ucopy(mat4s mat);
    mat4s   glms_mat4_copy(mat4s mat);
    mat4s   glms_mat4_identity(void);
    void    glms_mat4_identity_array(mat4s * __restrict mat, size_t count);
    mat4s   glms_mat4_zero(void);
    mat3s   glms_mat4_pick3(mat4s mat);
    mat3s   glms_mat4_pick3t(mat4s mat);
    mat4s   glms_mat4_ins3(mat3s mat);
    mat4s   glms_mat4_mul(mat4s m1, mat4s m2);
    mat4s   glms_mat4_mulN(mat4s * __restrict matrices[], uint32_t len);
    vec4s   glms_mat4_mulv(mat4s m, vec4s v);
    float   glms_mat4_trace(mat4s m);
    float   glms_mat4_trace3(mat4s m);
    versors glms_mat4_quat(mat4s m);
    vec3s   glms_mat4_mulv3(mat4s m, vec3s v, float last);
    mat4s   glms_mat4_transpose(mat4s m);
    mat4s   glms_mat4_scale_p(mat4s m, float s);
    mat4s   glms_mat4_scale(mat4s m, float s);
    float   glms_mat4_det(mat4s mat);
    mat4s   glms_mat4_inv(mat4s mat);
    mat4s   glms_mat4_inv_fast(mat4s mat);
    mat4s   glms_mat4_swap_col(mat4s mat, int col1, int col2);
    mat4s   glms_mat4_swap_row(mat4s mat, int row1, int row2);
    float   glms_mat4_rmc(vec4s r, mat4s m, vec4s c);
 */

#ifndef cglms_mat4s_h
#define cglms_mat4s_h

#include "../common.h"
#include "../types-struct.h"
#include "../mat4.h"
#include "vec4.h"
#include "vec3.h"

#define GLMS_MAT4_IDENTITY_INIT  {GLM_MAT4_IDENTITY_INIT}
#define GLMS_MAT4_ZERO_INIT      {GLM_MAT4_ZERO_INIT}

/* for C only */
#define GLMS_MAT4_IDENTITY ((mat4s)GLMS_MAT4_IDENTITY_INIT)
#define GLMS_MAT4_ZERO     ((mat4s)GLMS_MAT4_ZERO_INIT)

/*!
 * @brief copy all members of [mat] to [dest]
 *
 * matrix may not be aligned, u stands for unaligned, this may be useful when
 * copying a matrix from external source e.g. asset importer...
 *
 * @param[in]  mat  source
 * @returns         destination
 */

mat4s
glms_mat4_ucopy(mat4s mat) {
  mat4s r;
  glm_mat4_ucopy(mat.raw, r.raw);
  return r;
}

/*!
 * @brief copy all members of [mat] to [dest]
 *
 * @param[in]  mat  source
 * @returns         destination
 */

mat4s
glms_mat4_copy(mat4s mat) {
  mat4s r;
  glm_mat4_copy(mat.raw, r.raw);
  return r;
}

/*!
 * @brief make given matrix identity. It is identical with below, 
 *        but it is more easy to do that with this func especially for members
 *        e.g. glm_mat4_identity(aStruct->aMatrix);
 *
 * @code
 * glm_mat4_copy(GLM_MAT4_IDENTITY, mat); // C only
 *
 * // or
 * mat4 mat = GLM_MAT4_IDENTITY_INIT;
 * @endcode
 *
 * @retuns  destination
 */

mat4s
glms_mat4_identity(void) {
  mat4s r;
  glm_mat4_identity(r.raw);
  return r;
}

/*!
 * @brief make given matrix array's each element identity matrix
 *
 * @param[in, out]  mat   matrix array (must be aligned (16/32)
 *                        if alignment is not disabled)
 *
 * @param[in]       count count of matrices
 */

void
glms_mat4_identity_array(mat4s * __restrict mat, size_t count) {
  CGLM_ALIGN_MAT mat4s t = GLMS_MAT4_IDENTITY_INIT;
  size_t i;

  for (i = 0; i < count; i++) {
    glm_mat4_copy(t.raw, mat[i].raw);
  }
}

/*!
 * @brief make given matrix zero.
 *
 * @returns  matrix
 */

mat4s
glms_mat4_zero(void) {
  mat4s r;
  glm_mat4_zero(r.raw);
  return r;
}

/*!
 * @brief copy upper-left of mat4 to mat3
 *
 * @param[in]  mat  source
 * @returns         destination
 */

mat3s
glms_mat4_pick3(mat4s mat) {
  mat3s r;
  glm_mat4_pick3(mat.raw, r.raw);
  return r;
}

/*!
 * @brief copy upper-left of mat4 to mat3 (transposed)
 *
 * the postfix t stands for transpose
 *
 * @param[in]  mat  source
 * @returns         destination
 */

mat3s
glms_mat4_pick3t(mat4s mat) {
  mat3s r;
  glm_mat4_pick3t(mat.raw, r.raw);
  return r;
}

/*!
 * @brief copy mat3 to mat4's upper-left
 *
 * @param[in]  mat  source
 * @returns         destination
 */

mat4s
glms_mat4_ins3(mat3s mat) {
  mat4s r;
  glm_mat4_ins3(mat.raw, r.raw);
  return r;
}

/*!
 * @brief multiply m1 and m2 to dest
 *
 * m1, m2 and dest matrices can be same matrix, it is possible to write this:
 *
 * @code
 * mat4 m = GLM_MAT4_IDENTITY_INIT;
 * glm_mat4_mul(m, m, m);
 * @endcode
 *
 * @param[in]  m1   left matrix
 * @param[in]  m2   right matrix
 * @returns         destination matrix
 */

mat4s
glms_mat4_mul(mat4s m1, mat4s m2) {
  mat4s r;
  glm_mat4_mul(m1.raw, m2.raw, r.raw);
  return r;
}

/*!
 * @brief mupliply N mat4 matrices and store result in dest
 *
 * this function lets you multiply multiple (more than two or more...) matrices
 * <br><br>multiplication will be done in loop, this may reduce instructions
 * size but if <b>len</b> is too small then compiler may unroll whole loop,
 * usage:
 * @code
 * mat m1, m2, m3, m4, res;
 *
 * res = glm_mat4_mulN((mat4 *[]){&m1, &m2, &m3, &m4}, 4);
 * @endcode
 *
 * @warning matrices parameter is pointer array not mat4 array!
 *
 * @param[in]  matrices mat4 * array
 * @param[in]  len      matrices count
 * @returns             result matrix
 */

mat4s
glms_mat4_mulN(mat4s * __restrict matrices[], uint32_t len) {
  CGLM_ALIGN_MAT mat4s r = GLMS_MAT4_IDENTITY_INIT;
  size_t i;

  for (i = 0; i < len; i++) {
    r = glms_mat4_mul(r, *matrices[i]);
  }
  
  return r;
}

/*!
 * @brief multiply mat4 with vec4 (column vector) and store in dest vector
 *
 * @param[in]  m    mat4 (left)
 * @param[in]  v    vec4 (right, column vector)
 * @returns         vec4 (result, column vector)
 */

vec4s
glms_mat4_mulv(mat4s m, vec4s v) {
  vec4s r;
  glm_mat4_mulv(m.raw, v.raw, r.raw);
  return r;
}

/*!
 * @brief trace of matrix
 *
 * sum of the elements on the main diagonal from upper left to the lower right
 *
 * @param[in]  m matrix
 */

float
glms_mat4_trace(mat4s m) {
  return glm_mat4_trace(m.raw);
}

/*!
 * @brief trace of matrix (rotation part)
 *
 * sum of the elements on the main diagonal from upper left to the lower right
 *
 * @param[in]  m matrix
 */

float
glms_mat4_trace3(mat4s m) {
  return glm_mat4_trace3(m.raw);
}

/*!
 * @brief convert mat4's rotation part to quaternion
 *
 * @param[in]  m    affine matrix
 * @returns         destination quaternion
 */

versors
glms_mat4_quat(mat4s m) {
  versors r;
  glm_mat4_quat(m.raw, r.raw);
  return r;
}

/*!
 * @brief multiply vector with mat4
 *
 * @param[in]  m    mat4(affine transform)
 * @param[in]  v    vec3
 * @param[in]  last 4th item to make it vec4
 * @returns         result vector (vec3)
 */

vec3s
glms_mat4_mulv3(mat4s m, vec3s v, float last) {
  vec3s r;
  glm_mat4_mulv3(m.raw, v.raw, last, r.raw);
  return r;
}

/*!
 * @brief tranpose mat4 and store result in same matrix
 *
 * @param[in] m source
 * @returns     result
 */

mat4s
glms_mat4_transpose(mat4s m) {
  glm_mat4_transpose(m.raw);
  return m;
}

/*!
 * @brief scale (multiply with scalar) matrix without simd optimization
 *
 * multiply matrix with scalar
 *
 * @param[in] m matrix
 * @param[in] s scalar
 * @returns     matrix    
 */

mat4s
glms_mat4_scale_p(mat4s m, float s) {
  glm_mat4_scale_p(m.raw, s);
  return m;
}

/*!
 * @brief scale (multiply with scalar) matrix
 *
 * multiply matrix with scalar
 *
 * @param[in] m matrix
 * @param[in] s scalar
 * @returns     matrix
 */

mat4s
glms_mat4_scale(mat4s m, float s) {
  glm_mat4_scale(m.raw, s);
  return m;
}

/*!
 * @brief mat4 determinant
 *
 * @param[in] mat matrix
 *
 * @return determinant
 */

float
glms_mat4_det(mat4s mat) {
  return glm_mat4_det(mat.raw);
}

/*!
 * @brief inverse mat4 and store in dest
 *
 * @param[in]  mat  matrix
 * @returns         inverse matrix
 */

mat4s
glms_mat4_inv(mat4s mat) {
  mat4s r;
  glm_mat4_inv(mat.raw, r.raw);
  return r;
}

/*!
 * @brief inverse mat4 and store in dest
 *
 * this func uses reciprocal approximation without extra corrections
 * e.g Newton-Raphson. this should work faster than normal,
 * to get more precise use glm_mat4_inv version.
 *
 * NOTE: You will lose precision, glm_mat4_inv is more accurate
 *
 * @param[in]  mat  matrix
 * @returns         inverse matrix
 */

mat4s
glms_mat4_inv_fast(mat4s mat) {
  mat4s r;
  glm_mat4_inv_fast(mat.raw, r.raw);
  return r;
}

/*!
 * @brief swap two matrix columns
 *
 * @param[in] mat  matrix
 * @param[in] col1 col1
 * @param[in] col2 col2
 * @returns        matrix
 */

mat4s
glms_mat4_swap_col(mat4s mat, int col1, int col2) {
  glm_mat4_swap_col(mat.raw, col1, col2);
  return mat;
}

/*!
 * @brief swap two matrix rows
 *
 * @param[in] mat  matrix
 * @param[in] row1 row1
 * @param[in] row2 row2
 * @returns        matrix
 */

mat4s
glms_mat4_swap_row(mat4s mat, int row1, int row2) {
  glm_mat4_swap_row(mat.raw, row1, row2);
  return mat;
}

/*!
 * @brief helper for  R (row vector) * M (matrix) * C (column vector)
 *
 * rmc stands for Row * Matrix * Column
 *
 * the result is scalar because R * M = Matrix1x4 (row vector),
 * then Matrix1x4 * Vec4 (column vector) = Matrix1x1 (Scalar)
 *
 * @param[in]  r   row vector or matrix1x4
 * @param[in]  m   matrix4x4
 * @param[in]  c   column vector or matrix4x1
 *
 * @return scalar value e.g. B(s)
 */

float
glms_mat4_rmc(vec4s r, mat4s m, vec4s c) {
  return glm_mat4_rmc(r.raw, m.raw, c.raw);
}

#endif /* cglms_mat4s_h */
