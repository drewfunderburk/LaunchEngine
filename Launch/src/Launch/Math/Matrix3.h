#pragma once
#include "../Core.h"

namespace Launch
{
    struct LAUNCH_API Matrix3
    {
    public:

        float m11, m12, m13, m21, m22, m23, m31, m32, m33;

        Matrix3();

        Matrix3(float m11, float m12, float m13,
            float m21, float m22, float m23,
            float  m31, float  m32, float m33);

        Matrix3 operator +(Matrix3 rhs);

        Matrix3 operator -(Matrix3 rhs);

        Matrix3 operator *(Matrix3 rhs);

        Vector3 operator *(Vector3 rhs);

        bool operator ==(Matrix3 rhs);

        /// <summary>
        /// Creates a matrix thats been rotated by the given amount of radians
        ///on the z axis.
        /// </summary>
        /// <returns></returns>
        static Matrix3 createRotation(float radians);

        /// <summary>
        /// Creates a matrix thats been rotated by the given amount of radians
        ///on the y axis.
        /// </summary>
        /// <returns></returns>
        static Matrix3 createTranslation(Vector2 position);

        /// <summary>
        /// Creates a matrix thats been scaled by the given vector.
        /// </summary>
        /// <returns></returns>
        static Matrix3 createScale(Vector2 scale);
    };
}


