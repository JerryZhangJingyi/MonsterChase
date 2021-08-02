#pragma once
namespace _FloatHelper {
	bool IsNaN(float value);
	bool AboutEqual(float value1, float value2);
	bool IsZero(float value);
	bool AreEqualEps(float value1, float value2, float maxDiff);
}