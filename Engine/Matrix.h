#pragma once
#include "Vector4.h"
using namespace _Vector4;
namespace _Matrix {
    class Matrix
    {
    public:
        Matrix(float r1c1 = 0.f, float r2c1 = 0.f, float r3c1 = 0.f, float r4c1 = 0.f,
            float r1c2 = 0.f, float r2c2 = 0.f, float r3c2 = 0.f, float r4c2 = 0.f, 
            float r1c3 = 0.f, float r2c3 = 0.f, float r3c3 = 0.f, float r4c3 = 0.f, 
            float r1c4 = 0.f, float r2c4 = 0.f, float r3c4 = 0.f, float r4c4 = 0.f);

        Matrix(const Matrix& matrix);

        ~Matrix()
        {}

        void set(float _r1c1 = 0.f, float _r2c1 = 0.f, float _r3c1 = 0.f, float _r4c1 = 0.f,
            float _r1c2 = 0.f, float _r2c2 = 0.f, float _r3c2 = 0.f, float _r4c2 = 0.f,
            float _r1c3 = 0.f, float _r2c3 = 0.f, float _r3c3 = 0.f, float _r4c3 = 0.f,
            float _r1c4 = 0.f, float _r2c4 = 0.f, float _r3c4 = 0.f, float _r4c4 = 0.f)
        {
            r1c1 = _r1c1; r2c1 = _r2c1; r3c1 = _r3c1; r4c1 = _r4c1;
            r1c2 = _r1c2; r2c2 = _r2c2; r3c2 = _r3c2; r4c2 = _r4c2;
            r1c3 = _r1c3; r2c3 = _r2c3; r3c3 = _r3c3; r4c3 = _r4c3;
            r1c4 = _r1c4; r2c4 = _r2c4; r3c4 = _r3c4; r4c4 = _r4c4;
        };

        static void Transpose(Matrix matrix);
        static void Inversion(Matrix matrix);
        static void Transform(Matrix matrix, float x, float y, float z);
        static void XRotation(Matrix matrix, float angle);
        static void YRotation(Matrix matrix, float angle);
        static void ZRotation(Matrix matrix, float angle);
        static void Scale(Matrix matrix, float value);
        static Vector4D MultiplyVector4(Matrix matrix, Vector4D vector);
        Matrix operator*(Matrix& matrix);
        bool operator==(Matrix& matrix);

    public:
        float r1c1, r2c1, r3c1, r4c1,
            r1c2, r2c2, r3c2, r4c2,
            r1c3, r2c3, r3c3, r4c3,
            r1c4, r2c4, r3c4, r4c4;
    };

}