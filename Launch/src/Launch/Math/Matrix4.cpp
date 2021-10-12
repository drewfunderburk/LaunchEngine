#include "Vector3.h"
#include "Vector4.h"
#include "Matrix4.h"
#include <cmath>

Launch::Matrix4::Matrix4()
{
    m11 = 1; m12 = 0; m13 = 0; m14 = 0;
    m21 = 0; m22 = 1; m23 = 0; m24 = 0;
    m31 = 0; m32 = 0; m33 = 1; m34 = 0;
    m41 = 0; m42 = 0; m43 = 0; m44 = 1;
}

Launch::Matrix4::Matrix4(float m11, float m12, float m13, float m14,
                 float m21, float m22, float m23, float m24,
                 float m31, float m32, float m33, float m34,
                 float m41, float m42, float m43, float m44)
{
    this->m11 = m11; this->m12 = m12; this->m13 = m13; this->m14 = m14;
    this->m21 = m21; this->m22 = m22; this->m23 = m23; this->m24 = m24;
    this->m31 = m31; this->m32 = m32; this->m33 = m33; this->m34 = m34;
    this->m41 = m41; this->m42 = m42; this->m43 = m43; this->m44 = m44;
}

Launch::Matrix4 Launch::Matrix4::operator+(Matrix4 rhs)
{
    return Matrix4
    (
        this->m11 + rhs.m11, this->m12 + rhs.m12, this->m13 + rhs.m13, this->m14 + rhs.m14,
        this->m21 + rhs.m21, this->m22 + rhs.m22, this->m23 + rhs.m23, this->m24 + rhs.m24,
        this->m31 + rhs.m31, this->m32 + rhs.m32, this->m33 + rhs.m33, this->m34 + rhs.m34,
        this->m41 + rhs.m41, this->m42 + rhs.m42, this->m43 + rhs.m43, this->m44 + rhs.m44
    );
}

Launch::Matrix4 Launch::Matrix4::operator-(Matrix4 rhs)
{
    return Matrix4
    (
        this->m11 - rhs.m11, this->m12 - rhs.m12, this->m13 - rhs.m13, this->m14 - rhs.m14,
        this->m21 - rhs.m21, this->m22 - rhs.m22, this->m23 - rhs.m23, this->m24 - rhs.m24,
        this->m31 - rhs.m31, this->m32 - rhs.m32, this->m33 - rhs.m33, this->m34 - rhs.m34,
        this->m41 - rhs.m41, this->m42 - rhs.m42, this->m43 - rhs.m43, this->m44 - rhs.m44
    );
}

Launch::Matrix4 Launch::Matrix4::operator*(Matrix4 rhs)
{
    return Matrix4
    (
        //Row1
        this->m11 * rhs.m11 + this->m12 * rhs.m21 + this->m13 * rhs.m31 + this->m14 * rhs.m41,
        this->m11 * rhs.m12 + this->m12 * rhs.m22 + this->m13 * rhs.m32 + this->m14 * rhs.m42,
        this->m11 * rhs.m13 + this->m12 * rhs.m23 + this->m13 * rhs.m33 + this->m14 * rhs.m43,
        this->m11 * rhs.m14 + this->m12 * rhs.m24 + this->m13 * rhs.m34 + this->m14 * rhs.m44,
        //Row 2
        this->m21 * rhs.m11 + this->m22 * rhs.m21 + this->m23 * rhs.m31 + this->m24 * rhs.m41,
        this->m21 * rhs.m12 + this->m22 * rhs.m22 + this->m23 * rhs.m32 + this->m24 * rhs.m42,
        this->m21 * rhs.m13 + this->m22 * rhs.m23 + this->m23 * rhs.m33 + this->m24 * rhs.m43,
        this->m21 * rhs.m14 + this->m22 * rhs.m24 + this->m23 * rhs.m34 + this->m24 * rhs.m44,
        //Row 3
        this->m31 * rhs.m11 + this->m32 * rhs.m21 + this->m33 * rhs.m31 + this->m34 * rhs.m41,
        this->m31 * rhs.m12 + this->m32 * rhs.m22 + this->m33 * rhs.m32 + this->m34 * rhs.m42,
        this->m31 * rhs.m13 + this->m32 * rhs.m23 + this->m33 * rhs.m33 + this->m34 * rhs.m43,
        this->m31 * rhs.m14 + this->m32 * rhs.m24 + this->m33 * rhs.m34 + this->m34 * rhs.m44,
        //Row 4
        this->m41 * rhs.m11 + this->m42 * rhs.m21 + this->m43 * rhs.m31 + this->m44 * rhs.m41,
        this->m41 * rhs.m12 + this->m42 * rhs.m22 + this->m43 * rhs.m32 + this->m44 * rhs.m42,
        this->m41 * rhs.m13 + this->m42 * rhs.m23 + this->m43 * rhs.m33 + this->m44 * rhs.m43,
        this->m41 * rhs.m14 + this->m42 * rhs.m24 + this->m43 * rhs.m34 + this->m44 * rhs.m44
    );
}

Launch::Vector4 Launch::Matrix4::operator*(Vector4 rhs)
{
    return Vector4
    (
        //Row1
        (m11 * rhs.x) + (m12 * rhs.y) + (m13 * rhs.z) + (m14 * rhs.w),
        //Row 2
        (m21 * rhs.x) + (m22 * rhs.y) + (m23 * rhs.z) + (m24 * rhs.w),
        //Row 3
        (m31 * rhs.x) + (m32 * rhs.y) + (m33 * rhs.z) + (m34 * rhs.w),
        //Row 4
        (m41 * rhs.x) + (m42 * rhs.y) + (m43 * rhs.z) + (m44 * rhs.w)
    );
}

bool Launch::Matrix4::operator==(Matrix4 rhs)
{
    return m11 == rhs.m11 && m12 == rhs.m12 && m13 == rhs.m13 && m14 == rhs.m14 &&
        m21 == rhs.m21 && m22 == rhs.m22 && m23 == rhs.m23 && m24 == rhs.m24 &&
        m31 == rhs.m31 && m32 == rhs.m32 && m33 == rhs.m33 && m34 == rhs.m34 &&
        m41 == rhs.m41 && m42 == rhs.m42 && m43 == rhs.m43 && m44 == rhs.m44;
}

Launch::Matrix4 Launch::Matrix4::createRotationZ(float radians)
{
    return Matrix4
    (
        (float)cos(radians), (float)sin(radians), 0, 0,
        -(float)sin(radians), (float)cos(radians), 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    );
}

Launch::Matrix4 Launch::Matrix4::createRotationY(float radians)
{
    return Matrix4
    (
        (float)cos(radians), 0, -(float)sin(radians), 0,
        0, 1, 0, 0,
        (float)sin(radians), 0, (float)cos(radians), 0,
        0, 0, 0, 1
    );
}

Launch::Matrix4 Launch::Matrix4::createRotationX(float radians)
{
    return Matrix4
    (
        1, 0, 0, 0,
        0, (float)cos(radians), (float)sin(radians), 0,
        0, -(float)sin(radians), (float)cos(radians), 0,
        0, 0, 0, 1
    );
}

Launch::Matrix4 Launch::Matrix4::createTranslation(Vector3 position)
{
    return Matrix4
    (
        1, 0, 0, position.x,
        0, 1, 0, position.y,
        0, 0, 1, position.z,
        0, 0, 0, 1
    );
}

Launch::Matrix4 Launch::Matrix4::createScale(Vector3 scale)
{
    return Matrix4
    (
        scale.x, 0, 0, 0,
        0, scale.y, 0, 0,
        0, 0, scale.z, 0,
        0, 0, 0, 1
    );
}
