#include "Vector2.h"
#include "Vector3.h"
#include "Matrix3.h"
#include <cmath>

Launch::Matrix3::Matrix3()
{
    m11 = 1; m12 = 0; m13 = 0;
    m21 = 0; m22 = 1; m23 = 0;
    m31 = 0; m32 = 0; m33 = 1;
}

Launch::Matrix3::Matrix3(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33)
{
    this->m11 = m11; this->m12 = m12; this->m13 = m13;
    this->m21 = m21; this->m22 = m22; this->m23 = m23;
    this->m31 = m31; this->m32 = m32; this->m33 = m33;
}

Launch::Matrix3 Launch::Matrix3::operator+(Matrix3 rhs)
{
    return Matrix3
    (
        this->m11 + rhs.m11, this->m12 + rhs.m12, this->m13 + rhs.m13,
        this->m21 + rhs.m21, this->m22 + rhs.m22, this->m23 + rhs.m23,
        this->m31 + rhs.m31, this->m32 + rhs.m32, this->m33 + rhs.m33
    );
}

Launch::Matrix3 Launch::Matrix3::operator-(Matrix3 rhs)
{
    return Matrix3
    (
        this->m11 - rhs.m11, this->m12 - rhs.m12, this->m13 - rhs.m13,
        this->m21 - rhs.m21, this->m22 - rhs.m22, this->m23 - rhs.m23,
        this->m31 - rhs.m31, this->m32 - rhs.m32, this->m33 - rhs.m33
    );
}

Launch::Matrix3 Launch::Matrix3::operator*(Matrix3 rhs)
{
    return Matrix3
    (
        //Row1
        this->m11 * rhs.m11 + this->m12 * rhs.m21 + this->m13 * rhs.m31,
        this->m11 * rhs.m12 + this->m12 * rhs.m22 + this->m13 * rhs.m32,
        this->m11 * rhs.m13 + this->m12 * rhs.m23 + this->m13 * rhs.m33,
        //Row 2
        this->m21 * rhs.m11 + this->m22 * rhs.m21 + this->m23 * rhs.m31,
        this->m21 * rhs.m12 + this->m22 * rhs.m22 + this->m23 * rhs.m32,
        this->m21 * rhs.m13 + this->m22 * rhs.m23 + this->m23 * rhs.m33,
        //Row 3
        this->m31 * rhs.m11 + this->m32 * rhs.m21 + this->m33 * rhs.m31,
        this->m31 * rhs.m12 + this->m32 * rhs.m22 + this->m33 * rhs.m32,
        this->m31 * rhs.m13 + this->m32 * rhs.m23 + this->m33 * rhs.m33
    );
}

Launch::Vector3 Launch::Matrix3::operator*(Vector3 rhs)
{
    return Vector3
    (
        //Row1
        (this->m11 * rhs.x) + (this->m12 * rhs.y) + (this->m13 * rhs.z),
        //Row 2
        (this->m21 * rhs.x) + (this->m22 * rhs.y) + (this->m23 * rhs.z),
        //Row 3
        (this->m31 * rhs.x) + (this->m32 * rhs.y) + (this->m33 * rhs.z)
    );
}

bool Launch::Matrix3::operator ==(Matrix3 rhs)
{
    return m11 == rhs.m11 && m12 == rhs.m12 && m13 == rhs.m13 &&
           m21 == rhs.m21 && m22 == rhs.m22 && m23 == rhs.m23 &&
           m31 == rhs.m31 && m32 == rhs.m32 && m33 == rhs.m33;
}

Launch::Matrix3 Launch::Matrix3::createRotation(float radians)
{
    return Matrix3
    (
        (float)cos(radians), (float)sin(radians), 0,
        -(float)sin(radians), (float)cos(radians), 0,
        0, 0, 1
    );
}

Launch::Matrix3 Launch::Matrix3::createTranslation(Vector2 position)
{
    return Matrix3
    (
        1, 0, position.x,
        0, 1, position.y,
        0, 0, 1
    );
}

Launch::Matrix3 Launch::Matrix3::createScale(Vector2 scale)
{
    return Matrix3
    (
        scale.x, 0, 0,
        0, scale.y, 0,
        0, 0, 1
    );
}
