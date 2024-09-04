#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

#include "Matrix.hpp"


template<typename T> struct Vector2;
template<typename T> struct Vector3;



template<typename T> struct Vector2
{
    T x, y;

    Vector2() = default;
    Vector2(const T& x, const T& y) : x(x), y(y) {}
    Vector2(const Vector3<T>& _Vec) : x(_Vec.x), y(_Vec.y) {}


    Vector2<T> operator+(const Vector2<T>& _Vec) const 
    {
        return {x + _Vec.x, y + _Vec.y};
    }

    Vector2<T> operator-(const Vector2<T>& _Vec) const 
    {
        return {x - _Vec.x, y - _Vec.y};
    }

    Vector2<T> operator-() const
    {
        return {-x, -y};
    }

    Vector2<T> operator*(const T& _Scalar) const 
    {
        return {x * _Scalar, y * _Scalar};
    }

    Vector2<T> operator/(const T& _Scalar) const 
    {
        return {x / _Scalar, y / _Scalar};
    }

    Vector2<T>& operator+=(const Vector2<T>& _Vec) 
    {
        x += _Vec.x;
        y += _Vec.y;
        return *this;
    }

    Vector2<T>& operator-=(const Vector2<T>* _Vec) 
    {
        x -= _Vec.x;
        y -= _Vec.y;
        return *this;
    }

    Vector2<T>& operator*=(const T& _Scalar) 
    {
        x *= _Scalar;
        y *= _Scalar;
        return *this;
    }

    Vector2<T>& operator/=(const T& _Scalar) 
    {
        x /= _Scalar;
        y /= _Scalar;
        return *this;
    }

    Vector2<T>& operator=(const Vector2<T>& _Vec)
    {
        x = _Vec.x;
        y = _Vec.y;
        return *this;
    }
};

template<typename T> Vector2<T> operator*(const T& _Scalar, const Vector2<T>& _Vec) 
{
    return {
        _Vec.x * _Scalar, 
        _Vec.y * _Scalar
    };
}

template<typename T> Vector2<T> operator/(const T& _Scalar, const Vector2<T>& _Vec) 
{
    return {
        _Scalar / _Vec.x, 
        _Scalar / _Vec.y
    };
}

template<typename T> T dot(const Vector2<T>& _Vec_A, const Vector2<T>& _Vec_B) 
{
    return _Vec_A.x * _Vec_B.x + 
           _Vec_A.y * _Vec_B.y;
}

template<typename T> T cross(const Vector2<T>& _Vec_A, const Vector2<T>& _Vec_B) 
{
    return _Vec_A.x * _Vec_B.y -
           _Vec_A.y * _Vec_B.x;
}

template<typename T> T norm(const Vector2<T>& _Vec) 
{
    return std::sqrt(
        _Vec.x * _Vec.x +
        _Vec.y * _Vec.y
    );
}

template<typename T> T norm(const Vector2<T>& _Vec_A, const Vector2<T>& _Vec_B) 
{
    return sqrt(
        (_Vec_A.x - _Vec_B.x) * (_Vec_A.x - _Vec_B.x) +
        (_Vec_A.y - _Vec_B.y) * (_Vec_A.y - _Vec_B.y)
    );
}

template<typename T> T norm_square(const Vector2<T>& _Vec) 
{
    return (
        _Vec.x * _Vec.x +
        _Vec.y * _Vec.y
    );
}

template<typename T> T norm_square(const Vector2<T>& _Vec_A, const Vector2<T>& _Vec_B) 
{
    return (
        (_Vec_A.x - _Vec_B.x) * (_Vec_A.x - _Vec_B.x) +
        (_Vec_A.y - _Vec_B.y) * (_Vec_A.y - _Vec_B.y)
    );
}

template<typename T> Vector2<T> unit(const Vector2<T>& _Vec) 
{
    return _Vec / norm(_Vec);
}














template<typename T> struct Vector3
{
    T x, y, z;

    Vector3() = default;
    Vector3(const T& x, const T& y, const T& z) : x(x), y(y), z(z) {}

    Vector3<T> operator+(const Vector3<T>& _Vec) const 
    {
        return {x + _Vec.x, y + _Vec.y, z + _Vec.z};
    }

    Vector3<T> operator-(const Vector3<T>& _Vec) const 
    {
        return {x - _Vec.x, y - _Vec.y, z - _Vec.z};
    }

    Vector3<T> operator*(const Matrix<T, 3, 3>& _Matrix)
    {
        return {
            x * _Matrix[0][0] + y * _Matrix[1][0] + z * _Matrix[2][0],
            x * _Matrix[0][1] + y * _Matrix[1][1] + z * _Matrix[2][1],
            x * _Matrix[0][2] + y * _Matrix[1][2] + z * _Matrix[2][2]
        };
    }

    Vector3<T> operator-() const
    {
        return {-x, -y, -z};
    }

    Vector3<T> operator*(const T& _Scalar) const 
    {
        return {x * _Scalar, y * _Scalar, z * _Scalar};
    }

    Vector3<T> operator/(const T& _Scalar) const 
    {
        return {x / _Scalar, y / _Scalar, z / _Scalar};
    }

    Vector3<T>& operator+=(const Vector3<T>& _Vec) 
    {
        x += _Vec.x;
        y += _Vec.y;
        z += _Vec.z;
        return *this;
    }

    Vector3<T>& operator-=(const Vector3<T>* _Vec) 
    {
        x -= _Vec.x;
        y -= _Vec.y;
        z -= _Vec.z;
        return *this;
    }

    Vector3<T>& operator*=(const T& _Scalar) 
    {
        x *= _Scalar;
        y *= _Scalar;
        z *= _Scalar;
        return *this;
    }

    Vector3<T>& operator/=(const T& _Scalar) 
    {
        x /= _Scalar;
        y /= _Scalar;
        z /= _Scalar;
        return *this;
    }

    Vector3<T>& operator=(const Vector3<T>& _Vec)
    {
        x = _Vec.x;
        y = _Vec.y;
        z = _Vec.z;
        return *this;
    }

    Vector3<T>& operator*=(const Matrix<T, 3, 3>& _Matrix)
    {
        // return {
        //     x * _Matrix[0][0] + y * _Matrix[1][0] + z * _Matrix[2][0],
        //     x * _Matrix[0][1] + y * _Matrix[1][1] + z * _Matrix[2][1],
        //     x * _Matrix[0][2] + y * _Matrix[1][2] + z * _Matrix[2][2]
        // };

        *this = *this * _Matrix;
        return *this;
    }

    Vector3<T>& rotateX(const T& _Theta)
    {
        T cos_theta = static_cast<T>(cos(_Theta));
        T sin_theta = static_cast<T>(sin(_Theta));

        return *this *= {{
            {       1,          0,          0           },
            {       0,          cos_theta,  -sin_theta  },
            {       0,          sin_theta,  cos_theta   }
        }};
    }

    Vector3<T>& rotateY(const T& _Theta)
    {
        T cos_theta = static_cast<T>(cos(_Theta));
        T sin_theta = static_cast<T>(sin(_Theta));

        return *this *= {{
            {       cos_theta,  0,          sin_theta   },
            {       0,          1,          0           },
            {       -sin_theta, 0,          cos_theta   }
        }};
    }

    Vector3<T>& rotateZ(const T& _Theta)
    {
        T cos_theta = static_cast<T>(cos(_Theta));
        T sin_theta = static_cast<T>(sin(_Theta));

        return *this *= {{
            {       cos_theta,  -sin_theta, 0           },
            {       sin_theta,  cos_theta,  0           },
            {       0,          0,          1           }
        }};
    }
};

template<typename T> Vector3<T> operator*(const T& _Scalar, const Vector3<T>& _Vec) 
{
    return {
        _Vec.x * _Scalar, 
        _Vec.y * _Scalar, 
        _Vec.z * _Scalar
    };
}

template<typename T> Vector3<T> operator/(const T& _Scalar, const Vector3<T>& _Vec) 
{
    return {
        _Scalar / _Vec.x, 
        _Scalar / _Vec.y, 
        _Scalar / _Vec.z
    };
}

template<typename T> T dot(const Vector3<T>& _Vec_A, const Vector3<T>& _Vec_B) 
{
    return _Vec_A.x * _Vec_B.x + 
           _Vec_A.y * _Vec_B.y + 
           _Vec_A.z * _Vec_B.z;
}

template<typename T> Vector3<T> cross(const Vector3<T>& _Vec_A, const Vector3<T>& _Vec_B) 
{
    return {
        _Vec_A.y * _Vec_B.z - _Vec_A.z * _Vec_B.y,
        _Vec_A.z * _Vec_B.x - _Vec_A.x * _Vec_B.z,
        _Vec_A.x * _Vec_B.y - _Vec_A.y * _Vec_B.x
    };
}

template<typename T> T norm(const Vector3<T>& _Vec) 
{
    return sqrt(
        _Vec.x * _Vec.x +
        _Vec.y * _Vec.y +
        _Vec.z * _Vec.z
    );
}

template<typename T> T norm(const Vector3<T>& _Vec_A, const Vector3<T>& _Vec_B) 
{
    return sqrt(
        (_Vec_A.x - _Vec_B.x) * (_Vec_A.x - _Vec_B.x) +
        (_Vec_A.y - _Vec_B.y) * (_Vec_A.y - _Vec_B.y) +
        (_Vec_A.z - _Vec_B.z) * (_Vec_A.z - _Vec_B.z)
    );
}

template<typename T> T norm_square(const Vector3<T>& _Vec) 
{
    return (
        _Vec.x * _Vec.x +
        _Vec.y * _Vec.y +
        _Vec.z * _Vec.z
    );
}

template<typename T> T norm_square(const Vector3<T>& _Vec_A, const Vector3<T>& _Vec_B) 
{
    return (
        (_Vec_A.x - _Vec_B.x) * (_Vec_A.x - _Vec_B.x) +
        (_Vec_A.y - _Vec_B.y) * (_Vec_A.y - _Vec_B.y) +
        (_Vec_A.z - _Vec_B.z) * (_Vec_A.z - _Vec_B.z)
    );
}

template<typename T> Vector3<T> unit(const Vector3<T>& _Vec) 
{
    return _Vec / norm(_Vec);
}






#endif


