#pragma once
#include "../Core.h"
#include "Vector3.h"
#include <string>

namespace Launch
{
    struct LAUNCH_API Vector4
    {
        float x;
        float y;
        float z;
        float w;

        Vector4();
        Vector4(float x, float y, float z, float w);
        Vector4(Vector3 vector, float w);

        friend Vector4 operator *(float scalar, Vector4 lhs);

        Vector4 operator +(Vector4 rhs);

        Vector4 operator -(Vector4 rhs);

        Vector4 operator *(float scalar);

        Vector4 operator /(float scalar);

        bool operator == (Vector4 rhs);

        /// <summary>
        /// Returns the length of the vector.
        /// </summary>
        /// <returns></returns>
        float getMagnitude();

        /// <summary>
        /// Returns a copy of this vector normalized.
        /// </summary>
        /// <returns></returns>
        Vector4 getNormalized();

        /// <summary>
        /// Returns a string representation of this vector.
        /// </summary>
        /// <returns></returns>
        std::string toString();

        /// <summary>
        /// Returns the normalized version of the vector passed in.
        /// </summary>
        /// <param name="vector">The vector that will be normalized</param>
        /// <returns></returns>
        static Vector4 normalize(Vector4 vector);

        /// <summary>
        /// Returns the dot product of the two vectors given.
        /// </summary>
        /// <param name="lhs"></param>
        /// <param name="rhs"></param>
        /// <returns></returns>
        static float dotProduct(Vector4 lhs, Vector4 rhs);

        /// <summary>
        /// Returns the cross product of the two vectors given.
        /// </summary>
        /// <param name="lhs"></param>
        /// <param name="rhs"></param>
        /// <returns></returns>
        static Vector4 crossProduct(Vector4 lhs, Vector4 rhs);

        /// <summary>
        /// Interpolates a vector between two points
        /// </summary>
        /// <param name="start">Starting position. Returned when time = 0</param>
        /// <param name="end">Ending position. Returned when time = 1</param>
        /// <param name="time">How far between the points to travel</param>
        /// <returns>Interpolated value between start and end equal to a + (b - a) * t</returns>
        static Vector4 lerp(Vector4 start, Vector4 end, float time);

        /// <summary>
        /// Finds the distance between two points
        /// </summary>
        /// <param name="start">Starting position</param>
        /// <param name="end">Ending position</param>
        /// <returns></returns>
        static float distance(Vector4 start, Vector4 end);

        /// <summary>
        /// Shorthand for Vector4(0.0f, 0.0f, 0.0f, 0.0f)
        /// </summary>
        /// <returns></returns>
        static Vector4 zero() { return Vector4(0.0f, 0.0f, 0.0f, 0.0f); }

        /// <summary>
        /// Shorthand for Vector4(1.0f, 1.0f, 1.0f, 1.0f)
        /// </summary>
        /// <returns></returns>
        static Vector4 one() { return Vector4(1.0f, 1.0f, 1.0f, 1.0f); }
    };
}


