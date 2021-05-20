//pd's Vector classes (math sense)
#pragma once

#include <math.h>

/*==========================================
============ 2D Vector =====================
==========================================*/

template <typename T> class Vector2D
{
public:
    static const Vector2D Empty;

    //no constructor, so this class stays aggregate and can be initialized using the curly braces {}
    T X,Y;

    //operator overloads
    //addition
    Vector2D operator+(const Vector2D& a) const
    {
        return Vector2D{ X + a.X, Y + a.Y };
    }
    //addition
    Vector2D& operator+=(const Vector2D& a)
    {
        X += a.X;
        Y += a.Y;
        return *this;
    }
    //substraction
    Vector2D operator-(const Vector2D& a) const
    {
        return Vector2D{ X - a.X, Y - a.Y };
    }
    //substraction
    Vector2D& operator-=(const Vector2D& a)
    {
        X -= a.X;
        Y -= a.Y;
        return *this;
    }
    //negation
    Vector2D operator-() const
    {
        return Vector2D{ -X, -Y };
    }
    //equality
    bool operator==(const Vector2D& a) const
    {
        return (X == a.X && Y == a.Y);
    }
    //unequality
    bool operator!=(const Vector2D& a) const
    {
        return (X != a.X || Y != a.Y);
    }
    //scalar multiplication
    Vector2D operator*(double r) const
    {
        return Vector2D{ static_cast<T>(X * r), static_cast<T>(Y * r) };
    }
    //scalar multiplication
    Vector2D& operator*=(double r)
    {
        X *= r;
        Y *= r;
        return *this;
    }
    //vector multiplication
    double operator*(const Vector2D& a) const
    {
        return static_cast<double>(X) * a.X + static_cast<double>(Y) * a.Y;
    }
    //magnitude
    double Magnitude() const
    {
        return sqrt(MagnitudeSquared());
    }
    //magnitude squared
    double MagnitudeSquared() const
    {
        return *this * *this;
    }
    //distance from another vector
    double DistanceFrom(const Vector2D& a) const
    {
        return (a - *this).Magnitude();
    }
    //distance from another vector, squared
    double DistanceFromSquared(const Vector2D& a) const
    {
        return (a - *this).MagnitudeSquared();
    }
    //collinearity
    bool IsCollinearTo(const Vector2D& a) const
    {
        auto const c = static_cast<double>(X) * a.Y;
        return c == static_cast<double>(Y) * a.X;
    }
    //find scalar
    double FindScalar(const Vector2D& a) const
    {
        double r = static_cast<double>(a.X) / static_cast<double>(X);
        if(static_cast<T>(r * Y) == a.Y) {
            return r;
        } else {
            //the vectors are not collinear, return NaN!
            unsigned long NaN[2] = {0xFFFFFFFF,0x7FFFFFFF};
            return *reinterpret_cast<double*>(NaN);
        }
    }
};

template <typename T>
const Vector2D<T> Vector2D<T>::Empty = {T(), T()};

/*==========================================
============ 3D Vector =====================
==========================================*/

template <typename T> class Vector3D
{
public:
    static const Vector3D Empty;

    //no constructor, so this class stays aggregate and can be initialized using the curly braces {}
    T X,Y,Z;

    //operator overloads
    //addition
    Vector3D operator+(const Vector3D& a) const
    {
        return Vector3D{ X + a.X, Y + a.Y, Z + a.Z };
    }
    //addition
    Vector3D& operator+=(const Vector3D& a)
    {
        X += a.X;
        Y += a.Y;
        Z += a.Z;
        return *this;
    }
    //substraction
    Vector3D operator-(const Vector3D& a) const
    {
        return Vector3D{ X - a.X, Y - a.Y, Z - a.Z };
    }
    //substraction
    Vector3D& operator-=(const Vector3D& a)
    {
        X -= a.X;
        Y -= a.Y;
        Z -= a.Z;
        return *this;
    }
    //negation
    Vector3D operator-() const
    {
        return Vector3D{ -X, -Y, -Z };
    }
    //equality
    bool operator==(const Vector3D& a) const
    {
        return (X == a.X && Y == a.Y && Z == a.Z);
    }
    //unequality
    bool operator!=(const Vector3D& a) const
    {
        return (X != a.X || Y != a.Y || Z != a.Z);
    }
    //scalar multiplication
    Vector3D operator*(double r) const
    {
        return Vector3D{
            static_cast<T>(X * r),
            static_cast<T>(Y * r),
            static_cast<T>(Z * r) };
    }
    //scalar multiplication
    Vector3D& operator*=(double r)
    {
        X *= r;
        Y *= r;
        Z *= r;
        return *this;
    }
    //vector multiplication
    double operator*(const Vector3D& a) const
    {
        return static_cast<double>(X) * a.X
            + static_cast<double>(Y) * a.Y
            + static_cast<double>(Z) * a.Z;
    }
    //magnitude
    double Magnitude() const
    {
        return sqrt(MagnitudeSquared());
    }
    //magnitude squared
    double MagnitudeSquared() const
    {
        return *this * *this;
    }
    //distance from another vector
    double DistanceFrom(const Vector3D& a) const
    {
        return (a - *this).Magnitude();
    }
    //distance from another vector, squared
    double DistanceFromSquared(const Vector3D& a) const
    {
        return (a - *this).MagnitudeSquared();
    }
    //collinearity
    bool IsCollinearTo(const Vector3D& a) const
    {
        return CrossProduct(a).MagnitudeSquared() == 0;
    }
    //find scalar
    double FindScalar(const Vector3D& a) const
    {
        double r = static_cast<double>(a.X) / static_cast<double>(X);
        if((static_cast<T>(r * Y) == a.Y) && (static_cast<T>(r * Z) == a.Z)) {
            return r;
        } else {
            //the vectors are not collinear, return NaN!
            unsigned long NaN[2] = {0xFFFFFFFF,0x7FFFFFFF};
            return *reinterpret_cast<double*>(NaN);
        }
    }
    //cross product
    Vector3D CrossProduct(const Vector3D& a) const
    {
        return Vector3D{
            Y * a.Z - Z * a.Y,
            Z * a.X - X * a.Z,
            X * a.Y - Y * a.X };
    }
};

template <typename T>
const Vector3D<T> Vector3D<T>::Empty = {T(), T(), T()};

template <typename T> class Vector4D
{
public:
    static const Vector4D Empty;

    //no constructor, so this class stays aggregate and can be initialized using the curly braces {}
    T X, Y, Z, W;

    //methods are WIP
};

template <typename T>
const Vector4D<T> Vector4D<T>::Empty = { T(), T(), T(), T() };

class NOVTABLE Matrix3DStruct
{
public:
    union
    {
        Vector4D<float> Row[3];
        float row[3][4];
        float Data[12];
    };

    // plain floats ctor
    Matrix3DStruct(
        float m00, float m01, float m02, float m03,
        float m10, float m11, float m12, float m13,
        float m20, float m21, float m22, float m23)
        { JMP_THIS(0x5AE630); }

    // column vector ctor
    Matrix3DStruct(
        Vector3D<float> const& vec0,
        Vector3D<float> const& vec1,
        Vector3D<float> const& vec2,
        Vector3D<float> const& vec3)
        { JMP_THIS(0x5AE690); }

    // some other rotation ctor?
    Matrix3DStruct(float unknown1, float unknown2)
        { JMP_THIS(0x5AE6F0); }

    // rotation ctor
    Matrix3DStruct(Vector3D<float>* axis, float angle)
        { JMP_THIS(0x5AE750); }

    // copy ctor
    Matrix3DStruct(Matrix3DStruct* copyOf)
        { JMP_THIS(0x5AE610); }

    // convenience ctor
    Matrix3DStruct(bool identity = false) : Data()
    {
        if (identity)
            this->MakeIdentity();
    }

    // 1-matrix
    void MakeIdentity()
        { JMP_THIS(0x5AE860); }

    void Translate(float x, float y, float z)
        { JMP_THIS(0x5AE890); }

    void Translate(Vector3D<float> const& vec)
        { JMP_THIS(0x5AE8F0); }

    void TranslateX(float x)
        { JMP_THIS(0x5AE980); }

    void TranslateY(float y)
        { JMP_THIS(0x5AE9B0); }

    void TranslateZ(float z)
        { JMP_THIS(0x5AE9E0); }
    /*
    void __thiscall Scale(float factor)
        { JMP_THIS(0x); }

    void __thiscall Scale(float x, float y, float z)
        { JMP_THIS(0x); }

    void __thiscall ScaleX(float factor)
        { JMP_THIS(0x); }

    void __thiscall ScaleY(float factor)
        { JMP_THIS(0x); }

    void __thiscall ScaleZ(float factor)
        { JMP_THIS(0x); }

    void __thiscall ShearYZ(float y, float z)
        { JMP_THIS(0x); }

    void __thiscall ShearXY(float x, float y)
        { JMP_THIS(0x); }

    void __thiscall ShearXZ(float x, float z)
        { JMP_THIS(0x); }

    void __thiscall PreRotateX(float theta)
        { JMP_THIS(0x); }

    void __thiscall PreRotateY(float theta)
        { JMP_THIS(0x); }

    void __thiscall PreRotateZ(float theta)
        { JMP_THIS(0x); }

    void __thiscall RotateX(float theta)
        { JMP_THIS(0x); }

    void __thiscall RotateX(float s, float c)
        { JMP_THIS(0x); }

    void __thiscall RotateY(float theta)
        { JMP_THIS(0x); }

    void __thiscall RotateY(float s, float c)
        { JMP_THIS(0x); }

    void __thiscall RotateZ(float theta)
        { JMP_THIS(0x); }

    void __thiscall RotateZ(float s, float c)
        { JMP_THIS(0x); }

    float __thiscall GetXVal()
        { JMP_THIS(0x); }

    float __thiscall GetYVal()
        { JMP_THIS(0x); }

    float __thiscall GetZVal()
        { JMP_THIS(0x); }

    float __thiscall GetXRotation()
        { JMP_THIS(0x); }

    float __thiscall GetXVal()
        { JMP_THIS(0x); }

    float __thiscall GetXVal()
        { JMP_THIS(0x); }

    Vector3D<float> __thiscall RotateVector(Vector3D<float> const& vec)
        { JMP_THIS(0x); }

    // TODO add everything else

    */
};