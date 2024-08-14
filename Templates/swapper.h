/*
	!!! Note that The compiler needs to have access to the entire template definition (not just the signature)
	in order to generate code for each instantiation of the template,
	so you need to move the definitions of the functions to your header.

	Specficication and implementation files for Swapper Class
*/

#include<iostream>
#include<string>

#ifndef SWAPPER_H
#define SWAPPER_H

template <class T>
class Swapper
{
	public:
		Swapper(T first, T second);

		void swap();
		T getFirst() const;
		T getSecond() const;

	private:
		T first;
		T second;
};

template <class T> // We need to specify this before every method in the template class
Swapper<T>::Swapper(T first, T second)
{
	this->first = first;
	this->second = second;
}

template <class T>
void Swapper<T>::swap() {

	T temp = this->first; // Temporary variable
	this->first = this->second;
	this->second = temp;
}

template <class T>
T Swapper<T>::getFirst() const {
	return this->first;
}

template <class T>
T Swapper<T>::getSecond() const {
	return this->second;
}

#endif