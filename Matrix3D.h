// 3 incomplete functions for Matrix3D
#pragma once

#include <YRMathVector.h>

class Matrix3D
{
public:
    union
    {
        Vector4D<float> Row[3];
        float row[3][4];
        float Data[12];
    };

    // plain floats ctor
    Matrix3D(
        float m00, float m01, float m02, float m03,
        float m10, float m11, float m12, float m13,
        float m20, float m21, float m22, float m23)
        { JMP_THIS(0x5AE630); }

    // column vector ctor
    Matrix3D(
        Vector3D<float> const& vec0,
        Vector3D<float> const& vec1,
        Vector3D<float> const& vec2,
        Vector3D<float> const& vec3)
        { JMP_THIS(0x5AE690); }

    // some other rotation ctor?
    Matrix3D(float unknown1, float unknown2)
        { JMP_THIS(0x5AE6F0); }

    // rotation ctor
    Matrix3D(Vector3D<float>* axis, float angle)
        { JMP_THIS(0x5AE750); }

    // copy ctor
    Matrix3D(Matrix3D* copyOf)
        { JMP_THIS(0x5AE610); }

    // convenience ctor
    Matrix3D(bool identity = false) : Data()
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

    void __thiscall Scale(float factor)
        { JMP_THIS(0x5AEA10); }

    void __thiscall Scale(float x, float y, float z)
        { JMP_THIS(0x5AEA70); }

    void __thiscall ScaleX(float factor)
        { JMP_THIS(0x5AEAD0); }

    void __thiscall ScaleY(float factor)
        { JMP_THIS(0x5AEAF0); }

    void __thiscall ScaleZ(float factor)
        { JMP_THIS(0x5AEB20); }

    void __thiscall ShearYZ(float y, float z)
        { JMP_THIS(0x5AEB50); }

    void __thiscall ShearXY(float x, float y)
        { JMP_THIS(0x5AEBA0); }

    void __thiscall ShearXZ(float x, float z)
        { JMP_THIS(0x5AEBF0); }

    void __thiscall PreRotateX(float theta)
        { JMP_THIS(0x5AEC40); }

    void __thiscall PreRotateY(float theta)
        { JMP_THIS(0x5AED50); }

    void __thiscall PreRotateZ(float theta)
        { JMP_THIS(0x5AEE50); }

    void __thiscall RotateX(float theta)
        { JMP_THIS(0x5AEF60); }

    void __thiscall RotateX(float s, float c)
        { JMP_THIS(0x5AF000); }

    void __thiscall RotateY(float theta)
        { JMP_THIS(0x5AF080); }

    void __thiscall RotateY(float s, float c)
        { JMP_THIS(0x5AF120); }

    void __thiscall RotateZ(float theta)
        { JMP_THIS(0x5AF1A0); }

    void __thiscall RotateZ(float s, float c)
        { JMP_THIS(0x5AF240); }

    float __thiscall GetXVal()
        { JMP_THIS(0x5AF2C0); }

    float __thiscall GetYVal()
        { JMP_THIS(0x5AF310); }

    float __thiscall GetZVal()
        { JMP_THIS(0x5AF360); }

    float __thiscall GetXRotation()
        { JMP_THIS(0x5AF3B0); }

    float __thiscall GetYRotation()
        { JMP_THIS(0x5AF410); }

    float __thiscall GetZRotation()
        { JMP_THIS(0x5AF470); }

	// invisible arg
    Vector3D<float> __thiscall RotateVector(Vector3D<float> const& vec)
        { JMP_THIS(0x5AF4D0); }

	// FIXME Matrix3D::operator*
	// static Matrix3D __fastcall operator*(Matrix3D& a, Matrix3D const& b)
	// 	{ JMP_STD(0x5AF980); }

	// TODO sort out operator* between matrix and vector
	// static Vector3D<float> __fastcall operator*(Matrix3D const& A, Vector3D<float> const& a)
	// 	{ JMP_STD(0x5AFB80); }

	// invisible arg
	static Matrix3D __fastcall matrix_func_005AFC20(Matrix3D& a, Matrix3D const& b)
		{ JMP_STD(0x5AF980); }
};
