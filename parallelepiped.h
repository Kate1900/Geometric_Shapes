#pragma once
#include"Shapes.h"
#include"rectangle.h"
#include <iostream>

using namespace std;


template <class T>
class Parallelepiped : public  Shapes
{
private:
	int edge_1;
	int edge_2;
	T*** Array;
public:
	Parallelepiped();
	Parallelepiped(int e1, int e2, T _value);
	Parallelepiped(const Parallelepiped& parallepiped);
	~Parallelepiped();

	int GetEdge_1();
	int GetEdge_2();
	T GetValue();
	void SetEdge(int _edge_1, int _edge_2);

	float Perimeter() override;
	ostream& print(ostream& off) override;

	bool operator ==(const Parallelepiped& opt);
};

template<class T>
inline Parallelepiped<T>::Parallelepiped()
{
	edge_1 = 5;
	edge_2 = 10;
	Array = new T * *[edge_1];
	for (int i = 0; i < edge_1; i++)
	{
		Array[i] = new T * [edge_2];
		for (int j = 0; j < edge_2; j++)
			Array[i][j] = new T[edge_2];
	}
	Array[0][0][0] = '&';
}

template<class T>
inline Parallelepiped<T>::Parallelepiped(int e1, int e2, T _value)
{
	edge_1 = e1;
	edge_2 = e2;
	Array = new T * *[edge_1];
	for (int i = 0; i < edge_1; i++)
	{
		Array[i] = new T * [edge_2];
		for (int j = 0; j < edge_2; j++)
			Array[i][j] = new T[edge_2];
	}
	for (int i = 0; i < edge_1; i++)
		for (int j = 0; j < edge_2; j++)
			for (int l = 0; l < edge_2; l++)
				Array[i][j][l] = _value;
}

template<class T>
inline Parallelepiped<T>::Parallelepiped(const Parallelepiped& parallepiped)
{
	if (Array != 0)
	{
		for (int i = 0; i < edge_1; i++)
			for (int j = 0; j < edge_2; j++)
				delete[] Array[i][j];
		for (int i = 0; i < edge_1; i++)
			delete[] Array[i];
		delete[] Array;
	}
	edge_1 = parallepiped.edge_1;
	edge_2 = parallepiped.edge_2;
	Array = new T * *[edge_1];
	for (int i = 0; i < edge_1; i++)
	{
		Array[i] = new T * [edge_2];
		for (int j = 0; j < edge_2; j++)
			Array[i][j] = new T[edge_2];
	}
	for (int i = 0; i < edge_1; i++)
		for (int j = 0; j < edge_2; j++)
			for (int l = 0; l < edge_2; l++)
				Array[i][j][l] = parallepiped.Array[i][j][l];
}

template<class T>
inline Parallelepiped<T>::~Parallelepiped()
{
	if (Array != 0)
	{
		for (int i = 0; i < edge_1; i++)
			for (int j = 0; j < edge_2; j++)
				delete[] Array[i][j];
		for (int i = 0; i < edge_2; i++)
			delete[] Array[i];
		delete[] Array;
		Array = 0;
		edge_1 = 0;
		edge_2 = 0;
	}
}

template<class T>
inline int Parallelepiped<T>::GetEdge_1()
{
	return edge_1;
}

template<class T>
inline int Parallelepiped<T>::GetEdge_2()
{
	return edge_2;
}

template<class T>
inline T Parallelepiped<T>::GetValue()
{
	return Array[0][0][0];
}

template<class T>
inline void Parallelepiped<T>::SetEdge(int _edge_1, int _edge_2)
{
	T tmp = Array[0][0][0];
	if (Array != 0)
	{
		for (int i = 0; i < edge_1; i++)
			for (int j = 0; j < edge_2; j++)
				delete[] Array[i][j];
		for (int i = 0; i < edge_2; i++)
			delete[] Array[i];
		delete[] Array;
	}
	edge_1 = _edge_1;
	edge_2 = _edge_2;
	Array = new T * *[edge_1];
	for (int i = 0; i < edge_1; i++)
	{
		Array[i] = new T * [edge_2];
		for (int j = 0; j < edge_2; j++)
			Array[i][j] = new T[edge_2];
	}
	for (int i = 0; i < edge_1; i++)
		for (int j = 0; j < edge_2; j++)
			for (int l = 0; l < edge_2; l++)
				Array[i][j][l] = tmp;
}

template<class T>
inline float Parallelepiped<T>::Perimeter()
{
	return 4 * edge_1 + 8 * edge_2;
}

template<class T>
inline ostream& Parallelepiped<T>::print(ostream& off)
{
	Rectangle<T> tmp(edge_1, edge_2, Array[0][0][0]);
	tmp.print(off);
	return off;
}

template<class T>
inline bool Parallelepiped<T>::operator==(const Parallelepiped& opt)
{
	if (edge_1 == opt.edge_1 && edge_2 == opt.edge_2 && Array[0][0][0] == opt.Array[0][0][0])
		return true;
	return false;
}