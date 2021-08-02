#include "Collision.h"
#include "Matrix.h"
#include "Vector4.h"
#include <xlocinfo>
#include <windows.h>
#include <corecrt_math.h>

using namespace _Matrix;
using namespace _Vector4;

bool _Collision::AABBCollision(_SmartPointer::SmartPointer<_GameObject::GameObject> actor1, _SmartPointer::SmartPointer<_GameObject::GameObject> actor2)
{
    //coordinates for a
    Matrix mRotA
    (1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1);
    Matrix::ZRotation(mRotA, 0);
    Matrix mTransA
    (1, 0, 0, actor1->X,
        0, 1, 0, actor1->Y,
        0, 0, 1, 0,
        0, 0, 0, 1);

    Matrix mAToWorld = mTransA * mRotA;

    Matrix mWorldToA = mAToWorld;
    Matrix::Inversion(mWorldToA);

    //coordinates for B
    Matrix mRotB
    (1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1);
    Matrix::ZRotation(mRotB, 0);
    Matrix mTransB
    (1, 0, 0, actor2->X,
        0, 1, 0, actor2->Y,
        0, 0, 1, 0,
        0, 0, 0, 1);

    Matrix mBToWorld = mTransB * mRotB;

    Matrix mWorldToB = mBToWorld;
    Matrix::Inversion(mWorldToB);

    //collision detection A
    Matrix mAToB = mWorldToB * mAToWorld;
    Vector4D ABBCenterInB = Matrix::MultiplyVector4(mAToB, Vector4D(actor1->X, actor1->Y, 1.0f, 1.0f));
    Vector4D AExtentsXInB = Matrix::MultiplyVector4(mAToB, Vector4D(actor1->width / 2, 0.0f, 0.0f, 0.0f));
    Vector4D AExtentsYInB = Matrix::MultiplyVector4(mAToB, Vector4D(0.0f, actor1->height / 2, 0.0f, 0.0f));
    Vector4D AExtendsInB(fabs(AExtentsXInB.x) + fabs(AExtentsYInB.x), fabs(AExtentsXInB.y) + fabs(AExtentsYInB.y), 0.0f, 0.0f);
    float AProjectionOntoB_X = fabs(AExtentsXInB.x) + fabs(AExtentsYInB.x);
    bool IsSeparated;
    //A X
    if (fabs(actor2->X - ABBCenterInB.x) > actor2->width / 2 + AExtendsInB.x == true)
    {
        IsSeparated = true;
        return IsSeparated;
    }
    
    if (fabs(actor2->Y - ABBCenterInB.y) > actor2->height / 2 + AExtendsInB.y == true)
    {
        IsSeparated = true;
        return IsSeparated;
    }
    
    //collision detection B
    Matrix mBToA = mWorldToA * mBToWorld;
    Vector4D ABBCenterInA = Matrix::MultiplyVector4(mBToA, Vector4D(actor2->X, actor2->Y, 1.0f, 1.0f));
    Vector4D BExtentsXInA = Matrix::MultiplyVector4(mBToA, Vector4D(actor2->width / 2, 0.0f, 0.0f, 0.0f));
    Vector4D BExtentsYInA = Matrix::MultiplyVector4(mBToA, Vector4D(0.0f, actor2->height / 2, 0.0f, 0.0f));
    Vector4D BExtendsInA(fabs(BExtentsXInA.x) + fabs(BExtentsYInA.x), fabs(BExtentsXInA.y) + fabs(BExtentsYInA.y), 0.0f, 0.0f);
    float BProjectionOntoA_X = fabs(BExtentsXInA.x) + fabs(BExtentsYInA.x);

    if (fabs(actor1->X - ABBCenterInA.x) > actor1->width / 2 + BExtendsInA.x == true)
    {
        IsSeparated = true;
        return IsSeparated;
    }
    
    if (fabs(actor1->Y - ABBCenterInA.y) > actor1->height / 2 + BExtendsInA.y == true)
    {
        IsSeparated = true;
        return IsSeparated;
    }
    
    IsSeparated = false;

    return IsSeparated;

}

void _Collision::CheckCollision(std::list<_SmartPointer::SmartPointer<_GameObject::GameObject>> actors)
{
    int i = 0;
    while (i < actors.size())
    {
        int j = i + 1;
        while (j < actors.size())
        {
            std::list<_SmartPointer::SmartPointer<_GameObject::GameObject>>::iterator a = actors.begin();
            std::advance(a, i);
            std::list<_SmartPointer::SmartPointer<_GameObject::GameObject>>::iterator b = actors.begin();
            std::advance(b, j);
            AABBCollision(*a, *b);
            j++;
        }
        i++;
    }
}

void _Collision::CollisionResponse(_SmartPointer::SmartPointer<_GameObject::GameObject> actor, int CollisionType)
{
    if (CollisionType == 0) // contact on right
    {
        actor->X -= actor->velocity;
    }
    else if (CollisionType == 1) // contact on left
    {
        actor->X += actor->velocity;
    }
    else if (CollisionType == 2) // contact from above
    {
        actor->Y -= actor->velocity;
    }
    else if (CollisionType == 3) // contact from below
    {
        actor->Y += actor->velocity;
    }
}
