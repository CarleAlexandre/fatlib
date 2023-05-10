/*
 * =====================================================================================
 *
 *       Filename:  flmath.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/14/23 06:48:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  fatmeat (), pathofyggdrasil@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <fldata.h>

float fastReverseSqrt(float num) {
	long i;
	float x2, y;
	const float threehalfs = 1.5f;

	x2 = num * 0.5f;
	y = num;
	i = *(long *) &y;
	i = 0x5f3759df - (i >> 1);
	y = *(float *) &i;
	y = y * (threehalfs - (x2 * y * y));
	//y = y * (threehalfs - (x2 * y * y)); could add a second iteration

	return y;
}

/*
 *`tested on proc who support IEEE754 floating point
 * else you should remove the if and last return
 * */
float	flLerp(float a, float b, float x) {
	if (x <= 0.5f)
		return (x * (b - a) + a);
	return (b - (1.0f - x) * (b - a));
}

double	flPow(double number, long power) {
	double result = 1;

	while (power > 0) { 
		if (power & 1) {
			result *= (result * number);
		}
		number = (number * number);
		power >>= 1;
	}
	return (result);
}

/*
 *smoothStep linear interpolation funcion
 * */
float smoothStep(float t) {
    float v1 = t * t;
    float v2 = 1.0f - (1.0f - t) * (1.0f - t);
    return (flLerp(v1, v2, t));
}

/*
	find the distance between two Vector2
*/
float flDistance(Vec2 a, Vec2 b) {
    return (flPow(b.x - a.x, 2) + flPow(b.y - a.y, 2));
}

/*
	Travel a distance to your objectiv coordinate depending of the delta time of last frame and player velocity
*/
Vec2 flTravelTo(Vec2 current, Vec2 target, float velocity, float delta_time) {
	Vec2 direction = { target.x - current.x, target.y - current.y };
    float distance_to_target = flDistance(current, target);
    float move_distance = velocity * delta_time;

    if (distance_to_target > move_distance * move_distance) {
        direction.x *= fastReverseSqrt(distance_to_target);
        direction.y *= fastReverseSqrt(distance_to_target);
        direction.x *= move_distance;
        direction.y *= move_distance;
        current.x += direction.x;
        current.y += direction.y;
    } else {
        current = target;
    }
    return (current);
}

