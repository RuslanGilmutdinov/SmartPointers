#pragma once
#include "auto_ptr.h"

template<typename T>
class unique_ptr : public auto_ptr<T>
{
public:
	unique_ptr();
	unique_ptr(T* ptr);

	unique_ptr(unique_ptr & uniqueptr) = delete;
	unique_ptr& operator = (unique_ptr & uniqueptr) = delete;
	
	unique_ptr(unique_ptr&& uniqueptr);
	unique_ptr& operator = (unique_ptr && uniqueptr);
	
	~unique_ptr();

	
};

template<typename T>
unique_ptr<T>::unique_ptr()
{
	pointer_ = nullptr;
}

template<typename T>
unique_ptr<T>::~unique_ptr()
{
	delete pointer_;
}

template<typename T>
unique_ptr<T>::unique_ptr(T* ptr)
{
	pointer_ = ptr;
}

template<typename T>
unique_ptr<T>::unique_ptr(unique_ptr && uniqueptr)
{
	std::swap(pointer_, uniqueptr.pointer_);
}

template<typename T>
unique_ptr<T> & unique_ptr<T>::operator=(unique_ptr&& uniqueptr)
{
	std::swap(pointer_, uniqueptr.pointer_);
}
