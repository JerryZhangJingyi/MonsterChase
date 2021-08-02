#include "FloatHelper.h"
#include <math.h>

bool _FloatHelper::IsNaN(float value)
{
	volatile float val = value;
	return value != value;
}

bool _FloatHelper::AboutEqual(float value1, float value2)
{
	float epsilon = .0001f;
	return fabs(value1 - value2) < epsilon;
}

bool _FloatHelper::IsZero(float value)
{
	return AreEqualEps(value, 0, .000000001f);
}

bool _FloatHelper::AreEqualEps(float value1, float value2, float maxDiff)
{
	return fabs(value1 - value2) < maxDiff;
}
