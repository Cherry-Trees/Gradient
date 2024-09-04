#ifndef _UTILS_HPP_
#define _UTILS_HPP_

#include <cmath>
#include <vector>
#include <array>
#include <memory>
#include <limits>
#include <string>

#include "Color.hpp"
#include "Vector.hpp"
#include "Matrix.hpp"

typedef Vector2<unsigned>   Vector2u;
typedef Vector2<int>        Vector2i;
typedef Vector2<float>      Vector2f;

typedef Vector3<unsigned>   Vector3u;
typedef Vector3<int>        Vector3i;
typedef Vector3<float>      Vector3f;

const double INF = std::numeric_limits<double>::infinity();
const double PI  = 3.1415926535897932;





Vector3f operator*(const Vector3f& vec, const Matrixf<4, 4>& matrix)
{
    Vector3f result = {
        vec.x * matrix[0][0] + vec.y * matrix[1][0] + vec.z * matrix[2][0] + matrix[3][0],
        vec.x * matrix[0][1] + vec.y * matrix[1][1] + vec.z * matrix[2][1] + matrix[3][1],
        vec.x * matrix[0][2] + vec.y * matrix[1][2] + vec.z * matrix[2][2] + matrix[3][2]
    };

    result /= vec.x * matrix[0][3] + vec.y * matrix[1][3] + vec.z * matrix[2][3] + matrix[3][3];
    return result;
}

// Vector3f operator*(const Matrixf<4, 4>& matrix, const Vector3f& vec) {return vec * matrix;}




Matrixf<4, 4> rotation_x_matrix(const float delta)
{
    return {{
        {1.f,           0.f,            0.f,            0.f},
        {0.f,           cosf(delta),    -sinf(delta),   0.f},
        {0.f,           sinf(delta),    cosf(delta),    0.f},
        {0.f,           0.f ,           0.f,            1.f}
    }};
}

Matrixf<4, 4> rotation_y_matrix(const float delta)
{
    return {{
        {cosf(delta),   0.f,            sinf(delta),    0.f},
        {0.f,           1.f,            0.f,            0.f},
        {-sinf(delta),  0.f,            cosf(delta),    0.f},
        {0.f,           0.f,            0.f,            1.f}
    }};
}

Matrixf<4, 4> rotation_z_matrix(const float delta)
{
    return {{
        {cosf(delta),   sinf(delta),    0.f,            0.f},
        {-sinf(delta),   cosf(delta),   0.f,            0.f},
        {0.f,           0.f,            1.f,            0.f},
        {0.f,           0.f,            0.f,            1.f}
    }};
}





#endif