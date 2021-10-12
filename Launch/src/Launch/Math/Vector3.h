#pragma once
#include "../Core.h"

namespace Launch
{
    struct LAUNCH_API Vector3
    {
        float x;
        float y;
        float z;

        Vector3();
        Vector3(float x, float y, float z);

        Vector3 operator +(Vector3 rhs);

        Vector3 operator -(Vector3 rhs);

        Vector3 operator *(float scalar);

        friend Vector3 operator *(float scalar, Vector3 lhs);

        Vector3 operator /(float scalar);

        bool operator ==(Vector3 rhs);

        /// <summary>
        /// Returns the length of the vector.
        /// </summary>
        /// <returns></returns>
        float getMagnitude();

        /// <summary>
        /// Returns a copy of this vector normalized.
        /// </summary>
        /// <returns></returns>
        Vector3 getNormalized();

        /// <summary>
        /// Returns the normalized version of a the vector passed in.
        /// </summary>
        /// <param name="vector">The vector that will be normalized</param>
        /// <returns></returns>
        static Vector3 normalize(Vector3 vector);

        /// <summary>
        /// Returns the dot product of the two vectors given.
        /// </summary>
        /// <param name="lhs"></param>
        /// <param name="rhs"></param>
        /// <returns></returns>
        static float dotProduct(Vector3 lhs, Vector3 rhs);

        /// <summary>
        /// Returns the cross product of the two vectors given.
        /// </summary>
        /// <param name="lhs"></param>
        /// <param name="rhs"></param>
        /// <returns></returns>
        static Vector3 crossProduct(Vector3 lhs, Vector3 rhs);

        /// <summary>
        /// Interpolates a vector between two points
        /// </summary>
        /// <param name="start">Starting position. Returned when time = 0</param>
        /// <param name="end">Ending position. Returned when time = 1</param>
        /// <param name="time">How far between the points to travel</param>
        /// <returns>Interpolated value between start and end equal to a + (b - a) * t</returns>
        static Vector3 lerp(Vector3 start, Vector3 end, float time);

        /// <summary>
        /// Finds the distance between two points
        /// </summary>
        /// <param name="start">Starting position</param>
        /// <param name="end">Ending position</param>
        /// <returns></returns>
        static float distance(Vector3 start, Vector3 end);
    };
}


