#pragma once
#include <ostream>
using namespace std;
namespace _SmartPointer {
    class ReferenceCount
    {
    public:
        int smartCount; 
        int weakCount;
    public:
        void AddReference()
        {
            smartCount++;
        }
        int ReleaseReference()
        {
            return smartCount--;
        }
    };
    template <typename T> class SmartPointer
    {
    public:
        T* ptr;
        ReferenceCount* reference;

    public:
        SmartPointer() : ptr(0), reference(0)
        {
            reference = new ReferenceCount();
            reference->AddReference();
        }

        SmartPointer(T* value) : ptr(value), reference(0)
        {
            reference = new ReferenceCount();
            reference->AddReference();
        }

        SmartPointer(const SmartPointer<T>& SmartPointer) : ptr(SmartPointer.ptr), reference(SmartPointer.reference)
        {
            reference->AddReference();
        }

        ~SmartPointer()
        {
            if (reference->ReleaseReference() == 0)
            {
                delete ptr;
                delete reference;
            }
        }

        T& operator* ()
        {
            return *ptr;
        }

        T* operator-> ()
        {
            return ptr;
        }

        SmartPointer<T>& operator = (const SmartPointer<T>& SmartPointer)
        {
            if (this != &SmartPointer)
            {

                if (reference->ReleaseReference() == 0)
                {
                    delete ptr;
                    delete reference;
                }

                ptr = SmartPointer.ptr;
                reference = SmartPointer.reference;
                reference->AddReference();
            }
            return *this;
        }
    };
}