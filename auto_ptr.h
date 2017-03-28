#pragma once

template <typename T>
class auto_ptr
{
public:

	auto_ptr();
	auto_ptr(T* ptr);
	auto_ptr(auto_ptr & autoptr);
	~auto_ptr();
	
	auto_ptr & operator =(auto_ptr & p);
	T& operator*();
	T* operator->();
	

protected:
	T* pointer_;

};

template<typename T>
auto_ptr<T>::auto_ptr()
{
	pointer_ = nullptr;
}

	template<typename T>
auto_ptr<T>::auto_ptr(T* ptr)
{
	pointer_ = ptr;
}

template <typename T>
auto_ptr<T>::auto_ptr(auto_ptr & autoptr)
{
	pointer_ = nullptr;
	std::swap(pointer_, autoptr.pointer_);
}

template<typename T>
auto_ptr<T>::~auto_ptr()
{
	//delete *pointer_;
	delete pointer_;
}

template<typename T>
auto_ptr<T> & auto_ptr<T>::operator =(auto_ptr &p)
{
	delete pointer_;
	pointer_ = nullptr;
	std::swap(pointer_, p.pointer_);
	return *this;
}

template<typename T>
T& auto_ptr<T>::operator*()
{
	return *pointer_;
}

template<typename T>
T* auto_ptr<T>::operator->()
{
	return pointer_;
}
