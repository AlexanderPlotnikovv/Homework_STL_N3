#include <iostream>
#include <stdexcept>

class Exception : public std::exception
{
public:
	const char* what() { return "Error in array"; }
};

template<class T>
class vector
{
	T* arr;
	unsigned Size = 0;
	unsigned Capacity = 0;
public:
	vector(int size) : Capacity(size), Size(0)
	{
		arr = new T [Capacity];
		for (int i = 0; i != Capacity; ++i)
		{
			arr[i] = 0;
		}
	}
	vector()
	{
		arr = nullptr;
	}
	vector(const vector& vec)
	{
		Size = vec.Size;
		Capacity = vec.Capacity;
		arr = new T[Capacity];
		for (int i = 0; i != Capacity; ++i)
		{
			arr[i] = vec.arr[i];
		}
	}
	const T* data()
	{
		return arr;
	}
	 const void print()
	{
		for (int i = 0; i != Size; ++i)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}
	const T at(int i)
	{
		if (i >= Size || i < 0)
		{
			throw Exception();
		}
		else
		{
			return arr[i];
		}
	}
	void push_back(T a)
	{
		if (Size < Capacity)
		{
			arr[Size] = a;
			Size++;
		}
		else
		{
			Capacity *= 2;
			T* arrhelp = new T [Capacity];
			for (int i = 0; i != Size; ++i)
			{
				arrhelp[i] = arr[i];
			}
			delete[]arr;
			arrhelp[Size] = a;
			Size++;
			arr = arrhelp;
		}
	}
	void input(int count)
	{
		int help = Size;
		for (int i = Size; i != help+count; ++i)
		{
			T w;
			std::cin >> w;
			push_back(w);
		}
	}
	vector& operator=(const vector& v)
	{
		if (this == &v)
		{
			return *this;
		}
		else
		{
			delete[]arr;
			Size = v.Size;
			Capacity = v.Capacity;
			arr = new T[Capacity];
			for (int i = 0; i != Capacity; ++i)
			{
				arr[i] = v.arr[i];
			}
			return *this;
		}
	}
	const unsigned size()
	{
		return Size;
	}
	const unsigned capacity()
	{
		return Capacity;
	}
	T& operator[](int i)
	{
		return arr[i];
	}
	~vector()
	{
		delete[]arr;
	}
};

int main()
{
	int size;
	std::cin >> size;
	vector<char> vec(size);
	std::cout << vec.size() << " " << vec.capacity() << std::endl;
	vec.input(size);
	std::cout << vec.size() << " " << vec.capacity() << std::endl;
	vec.print();
	std::cout << vec.at(3) << std::endl;
	vec.push_back('f');
	vec.push_back('g');
	vec.print();
	std::cout << vec.size() << " " << vec.capacity() << std::endl;
	vector<char> v = vec;
	v.print();
	std::cout << v.size() << " " << v.capacity() << std::endl;
	v.input(3);
	v.print();
	std::cout << v.size() << " " << v.capacity() << std::endl;
	return 0;
}