#pragma once
namespace _Vector4 {
    class Vector4D
    {
    public:
        Vector4D(float x = 0.f, float y = 0.f, float z = 0.f, float w = 0.f);

        Vector4D(const Vector4D& vector4);

        ~Vector4D()
        {}

        Vector4D& operator=(Vector4D& vector4);
        Vector4D operator+(Vector4D& vector4);
        Vector4D operator-(Vector4D& vector4);
        bool operator==(Vector4D& vector4);
        bool operator!=(Vector4D& vector4);

    public:
        float x;
        float y;
        float z;
        float w;
    };
}