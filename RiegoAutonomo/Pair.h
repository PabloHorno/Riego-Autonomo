#pragma once
template<typename T1,typename T2>
class Pair
{
public:
	Pair(T1,T2);
	Pair() {};
	T1 first;
	T2 second;
};

template<typename T1, typename T2>
inline Pair<T1, T2>::Pair(T1 first, T2 second)
{
	this->first = first;
	this->second = second;
}