#pragma once
#include "SmartPointer.h"

namespace _WeakPointer {
    template <typename T> class WeakPointer
    {
    private:
        T* ptr;
        _SmartPointer::ReferenceCount* reference;
        template<class T> friend class SmartPointer;

    public:
        WeakPointer() : ptr(nullptr), reference(nullptr)
        {
        }
        WeakPointer(std::nullptr_t) : ptr(nullptr), reference(nullptr)
        {
        }
        ~WeakPointer()
        {
            if (reference->weakCount <= 0 && reference->smartCount <= 0)
            {
                delete reference;
            }
        }

        WeakPointer(const WeakPointer& weak) : ptr(weak.ptr), reference(weak.reference)
        {
            if (reference)
            {
                reference->weakCount++;
            }
        }

        WeakPointer(WeakPointer&& weak) : ptr(weak.ptr), reference(weak.reference)
        {
            weak.ptr = nullptr;
            weak.reference = nullptr;
        }

        WeakPointer(const _SmartPointer::SmartPointer<T>& Smart) : ptr(Smart.ptr), reference(Smart.reference)
        {
            if (reference)
            {
                reference->weakCount++;
            }
        }

        T* operator-> ()
        {
            return ptr;
        }
        
        WeakPointer& operator=(const _SmartPointer::SmartPointer<T>& Smart)
        {

            if (reference->weakCount <= 0 && reference->smartCount <= 0)
            {
                delete reference;
            }

            ptr = Smart.ptr;
            reference = Smart.reference;

            if (reference)
            {
                reference->weakCount++;
            }
            return *this;
        };

        bool HasExpired() 
        {
            if (reference == nullptr || reference->smartCount <= 0)
            {
                return true;
            }
            
            return false;
        };

        _SmartPointer::SmartPointer<T> Lock() 
        {
            if (HasExpired())
            {
                return _SmartPointer::SmartPointer<T>(nullptr);
            }
            return _SmartPointer::SmartPointer<T>(*this);
        };
    };
}