#pragma once
#include "../Core.h"

namespace Launch
{
    struct LAUNCH_API Vector2
    {
        float x;
        float y;

        Vector2();
        Vector2(float x, float y);

        Vector2 operator +(Vector2 rhs);

        Vector2 operator -(Vector2 rhs);

        Vector2 operator *(float scalar);

        friend Vector2 operator *(float scalar, Vector2 lhs);

        Vector2 operator /(float scalar);

        bool operator ==(Vector2 rhs);

        /// <summary>
        /// Returns the length of the vector.
        /// </summary>
        /// <returns></returns>
        float getMagnitude();

        /// <summary>
        /// Returns a copy of this vector normalized.
        /// </summary>
        /// <returns></returns>
        Vector2 getNormalized();

        /// <summary>
        /// Returns a string representation of this vector.
        /// </summary>
        /// <returns></returns>
        const char* toString();

        /// <summary>
        /// Returns the normalized version of the vector passed in.
        /// </summary>
        /// <param name="vector">The vector that will be normalized</param>
        /// <returns></returns>
        static Vector2 normalize(Vector2 vector);

        /// <summary>
        /// Returns the dot product of the two vectors given.
        /// </summary>
        /// <param name="lhs"></param>
        /// <param name="rhs"></param>
        /// <returns></returns>
        static float dotProduct(Vector2 lhs, Vector2 rhs);

        /// <summary>
        /// Finds the angle in radians between the two vectors given. 
        /// </summary>
        /// <param name="lhs"></param>
        /// <param name="rhs"></param>
        /// <returns></returns>
        static float angle(Vector2 lhs, Vector2 rhs);

        /// <summary>
        /// Interpolates a vector between two points
        /// </summary>
        /// <param name="start">Starting position. Returned when time = 0</param>
        /// <param name="end">Ending position. Returned when time = 1</param>
        /// <param name="time">How far between the points to travel</param>
        /// <returns>Interpolated value between start and end equal to a + (b - a) * t</returns>
        static Vector2 lerp(Vector2 start, Vector2 end, float time);

        /// <summary>
        /// Finds the distance between two points
        /// </summary>
        /// <param name="start">Starting position</param>
        /// <param name="end">Ending position</param>
        /// <returns></returns>
        static float distance(Vector2 start, Vector2 end);

        /// <summary>
        /// Shorthand for Vector2(0.0f, 0.0f)
        /// </summary>
        /// <returns></returns>
        static Vector2 zero() { return Vector2(0.0f, 0.0f); }

        /// <summary>
        /// Shorthand for Vector2(1.0f, 1.0f)
        /// </summary>
        /// <returns></returns>
        static Vector2 zero() { return Vector2(1.0f, 1.0f); }

        /// <summary>
        /// Shorthand for Vector2(0.0f, 1.0f)
        /// </summary>
        /// <returns></returns>
        static Vector2 up() { return Vector2(0.0f, 1.0f); }

        /// <summary>
        /// Shorthand for Vector2(0.0f, -1.0f)
        /// </summary>
        /// <returns></returns>
        static Vector2 down() { return Vector2(0.0f, -1.0f); }

        /// <summary>
        /// Shorthand for Vector2(1.0f, 0.0f)
        /// </summary>
        /// <returns></returns>
        static Vector2 right() { return Vector2(1.0f, 0.0f); }

        /// <summary>
        /// Shorthand for Vector2(-1.0f, 0.0f)
        /// </summary>
        /// <returns></returns>
        static Vector2 left() { return Vector2(-1.0f, 0.0f); }
    };
}


