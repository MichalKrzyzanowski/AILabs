/// <summary>
/// Author: Michal Krzyzanowski
/// </summary>


#include "MyVector3.h"
#include <string.h>
#define PI           3.14159265358979323846

/// <summary>
/// Default constructor set all 3 values to zero
/// </summary>
MyVector3::MyVector3() :
	x{ 0.0 },
	y{ 0.0 },
	z{ 0.0 }
{
}


/// <summary>
/// default destructor
/// nothing to release because we only have
/// primitive type data
/// </summary>
MyVector3::~MyVector3()
{
}


/// <summary>
/// 
/// </summary>
/// <returns>the vector as a string surrounded by square brackets and separated by commas</returns>
std::string MyVector3::toString()
{
	const std::string output = "[" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) + "]";
	return output;
}


// passing x, y and z values into myVector3
MyVector3::MyVector3(double t_x, double t_y, double t_z)
{
	x = t_x;
	y = t_y;
	z = t_z;
}


/// <summary>
/// create a vector 3 from an sf::vector3f
/// </summary>
/// <param name="t_sfVector">input vector</param>
MyVector3::MyVector3(sf::Vector3f t_sfVector)
{
	x = static_cast<double>(t_sfVector.x);
	y = static_cast<double>(t_sfVector.y);
	z = static_cast<double>(t_sfVector.z);
}


// converts vector 3 int to myVector3
MyVector3::MyVector3(sf::Vector3i t_sfVector)
{
	x = static_cast<double>(t_sfVector.x);
	y = static_cast<double>(t_sfVector.y);
	z = static_cast<double>(t_sfVector.z);
}


// converts vector 2 int to myVector3
MyVector3::MyVector3(sf::Vector2i t_sfVector)
{
	x = static_cast<double>(t_sfVector.x);
	y = static_cast<double>(t_sfVector.y);
	z = 0;
}


// converts vector 2 unsigned to myVector3
MyVector3::MyVector3(sf::Vector2u t_sfVector)
{
	x = static_cast<double>(t_sfVector.x);
	y = static_cast<double>(t_sfVector.y);
	z = 0;
}


// converts vector 2 float to myVector3
MyVector3::MyVector3(sf::Vector2f t_sfVector)
{
	x = static_cast<double>(t_sfVector.x);
	y = static_cast<double>(t_sfVector.y);
	z = 0;
}


// myVector3 addition
MyVector3 MyVector3::operator+(const MyVector3 t_right) const
{
	MyVector3 vector3Add{ 0.0f, 0.0f, 0.0f };

	vector3Add.x = x + t_right.x;
	vector3Add.y = y + t_right.y;
	vector3Add.z = z + t_right.z;

	return vector3Add;
}


// myVector3 subtraction
MyVector3 MyVector3::operator-(const MyVector3 t_right) const
{
	MyVector3 vector3Sub{ 0.0f, 0.0f, 0.0f };

	vector3Sub.x = x - t_right.x;
	vector3Sub.y = y - t_right.y;
	vector3Sub.z = z - t_right.z;

	return vector3Sub;
}


// myVector3 multiplication
MyVector3 MyVector3::operator*(const double t_scalar) const
{
	MyVector3 vector3Multiply{ x, y, z };

	vector3Multiply.x = vector3Multiply.x * t_scalar;
	vector3Multiply.y = vector3Multiply.y * t_scalar;
	vector3Multiply.z = vector3Multiply.z * t_scalar;


	return vector3Multiply;
}


// myVector3 division
MyVector3 MyVector3::operator/(const double t_divisor) const
{
	MyVector3 vector3Divide{ x, y, z };

	vector3Divide.x = vector3Divide.x / t_divisor;
	vector3Divide.y = vector3Divide.y / t_divisor;
	vector3Divide.z = vector3Divide.z / t_divisor;

	return vector3Divide;
}


// adds two vectors together. public x, y, z values changed
MyVector3 MyVector3::operator+=(const MyVector3 t_right)
{
	MyVector3 vector3AddEquals{ 0.0f, 0.0f, 0.0f };

	x += t_right.x;
	y += t_right.y;
	z += t_right.z;

	vector3AddEquals.x = x;
	vector3AddEquals.y = y;
	vector3AddEquals.z = z;

	return vector3AddEquals;
}


// subs one vector from another. public x, y, z values changed
MyVector3 MyVector3::operator-=(const MyVector3 t_right)
{
	MyVector3 vector3SubEquals{ 0.0f, 0.0f, 0.0f };

	x -= t_right.x;
	y -= t_right.y;
	z -= t_right.z;

	vector3SubEquals.x = x;
	vector3SubEquals.y = y;
	vector3SubEquals.z = z;

	return vector3SubEquals;
}


// checks for equality
bool MyVector3::operator==(const MyVector3 t_right) const
{
	MyVector3 vector3Equals{ x, y, z };

	bool vectorEquality{ false };

	// if both vectors have the same values for x, y, z
	if (vector3Equals.x == t_right.x && vector3Equals.y == t_right.y && vector3Equals.z == t_right.z)
	{
		vectorEquality = true;
	}

	return vectorEquality;
}


// checks for inequality
bool MyVector3::operator!=(const MyVector3 t_right) const
{
	MyVector3 vector3NotEquals{ x, y, z };

	bool vectorInequality{ false };

	// if both vectors have the different values for x, y, z
	if (vector3NotEquals.x != t_right.x && vector3NotEquals.y != t_right.y && vector3NotEquals.z != t_right.z)
	{
		vectorInequality = true;
	}

	return vectorInequality;
}


// reverse sing of x, y,z components of a MyVector3
MyVector3 MyVector3::operator-()
{
	x *= -1;
	y *= -1;
	z *= -1;

	return MyVector3(x, y, z);
}


// reverse sign of x coordinate of MyVector3
void MyVector3::reverseX()
{
	x *= -1;
}


// reverse sign of y coordinate of MyVector3
void MyVector3::reverseY()
{
	y *= -1;
}


// length of 3D vector
double MyVector3::length() const
{
	double sumOfSquares = (x * x) + (y * y) + (z * z); // length squared

	double length = sqrt(sumOfSquares); // length

	return length;
}


// length squared of a 3D vector
double MyVector3::lengthSquared() const
{
	double lengthSquared = (x * x) + (y * y) + (z * z); // length squared

	return lengthSquared;
}


// get scalar value of 2 MyVector3's
double MyVector3::dot(const MyVector3 t_other) const
{
	double dotProduct = (x * t_other.x) + (y * t_other.y) + (z * t_other.z);

	return dotProduct;
}

// get area of parallelogram using MyVector3's 
MyVector3 MyVector3::crossProduct(const MyVector3 t_other) const
{
	MyVector3 crossProduct{ x, y, z }; // MyVector3 containing public x, y, z

	// area of 3D parallelogram
	crossProduct = MyVector3{ y * t_other.z - z * t_other.y, z * t_other.x - x * t_other.z, x * t_other.y - y * t_other.x };

	return crossProduct;
}


// get angle in between 2 MyVector3's
double MyVector3::angleBetween(const MyVector3 t_other) const
{
	MyVector3 angleBetween{ x ,y ,z };
	double scalar = dot(t_other); // scalar from dot product function

	double lengthA = angleBetween.length(); // length of first MyVector3
	double lengthB = t_other.length(); // length of MyVector3 passed as a parameter

	// angle in radians
	double angleRadians = (scalar / (lengthA * lengthB));
	angleRadians = std::acos(angleRadians);

	double angleDegrees = angleRadians * (180.0f / PI); // angle in radians converted to degrees

	return angleDegrees;
}


// gets a MyVector3 of magnitude 1. original MyVector3 is changed
MyVector3 MyVector3::unit() const
{
	MyVector3 unitVector{};
	double vectorLength = length();

	if (vectorLength != 0.0)
	{
		unitVector = MyVector3{ x / vectorLength, y / vectorLength, z / vectorLength };
	}

	return unitVector;
}


// gets a MyVector3 of magnitude 1. original MyVector3 is unchanged
void MyVector3::normalise()
{
	MyVector3 unitVector{ x, y, z };
	double vectorLength = length();

	if (vectorLength != 0.0)
	{
		x /= vectorLength;
		y /= vectorLength;
		z /= vectorLength;
	}
}

// get a MyVector3 that is parallel to original MyVector3
MyVector3 MyVector3::projection(const MyVector3 t_onto) const
{
	double scalar = dot(t_onto) / t_onto.lengthSquared();

	return MyVector3{} = t_onto * scalar;
}

// get a MyVector3 that is perpendicular to original MyVector3
MyVector3 MyVector3::rejection(const MyVector3 t_onto) const
{
	return MyVector3{ x, y, z } -projection(t_onto);
}


// converts myVector3 to vector 2 unsigned 
MyVector3::operator sf::Vector2u()
{
	// unsigned cannot be negative
	if (x < 0)
	{
		x *= -1;
	}

	// unsigned cannot be negative
	if (y < 0)
	{
		y *= -1;
	}

	return sf::Vector2u{ static_cast<unsigned>(round(x)), static_cast<unsigned>(round(y)) };
}
