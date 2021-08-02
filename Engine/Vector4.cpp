#include "Vector4.h"
#include "FloatHelper.h"
using namespace _Vector4;

_Vector4::Vector4D::Vector4D(float x1, float y1, float z1, float w1) : 
x(x1),
y(y1),
z(z1),
w(w1)
{
}

_Vector4::Vector4D::Vector4D(const Vector4D& vector4) : 
x(vector4.x),
y(vector4.y),
z(vector4.z),
w(vector4.w)
{
}

Vector4D& _Vector4::Vector4D::operator=(Vector4D& vector4)
{
	return Vector4D(x = vector4.x, y = vector4.y, z = vector4.z, w = vector4.w);
}

Vector4D _Vector4::Vector4D::operator+(Vector4D& vector4)
{
	return Vector4D(x + vector4.x, y + vector4.y, z + vector4.z, w + vector4.w);
}

Vector4D _Vector4::Vector4D::operator-(Vector4D& vector4)
{
	return Vector4D(x - vector4.x, y - vector4.y, z - vector4.z, w - vector4.w);
}

bool _Vector4::Vector4D::operator==(Vector4D& vector4)
{
	return (_FloatHelper::AboutEqual(x, vector4.x) && _FloatHelper::AboutEqual(y, vector4.y) && _FloatHelper::AboutEqual(z, vector4.z) && _FloatHelper::AboutEqual(w, vector4.w));
}

bool _Vector4::Vector4D::operator!=(Vector4D& vector4)
{
	return (!_FloatHelper::AboutEqual(x, vector4.x) || !_FloatHelper::AboutEqual(y, vector4.y) || !_FloatHelper::AboutEqual(z, vector4.z) || !_FloatHelper::AboutEqual(w, vector4.w));
}
