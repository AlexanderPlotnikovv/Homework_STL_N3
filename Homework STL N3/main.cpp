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
	vector(int size) : Capacity(size), Size(size)
	{
		arr = new T[Capacity];
		for (int i = 0; i != Capacity; ++i)
		{
			arr[i] = 0;
		}
	}
	vector()
	{
		arr = nullptr;
	}
	void input()
	{
		for (int i = 0; i != Capacity; ++i)
		{
			std::cin >> arr[i];
		}
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
	void push_back(int a)
	{
		if (Size < Capacity)
		{
			arr[Size] = a;
			Size++;
		}
		else
		{
			Capacity *= 2;
			int* arrhelp = new int[Capacity];
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
	const unsigned size()
	{
		return Size;
	}
	const unsigned capacity()
	{
		return Capacity;
	}
	const T operator[](int i)
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
	vector<int> vec(size);
	vec.input();
	std::cout << vec.size() << " " << vec.capacity() << std::endl;
	vec.print();
	std::cout << vec.at(3) << std::endl;
	vec.push_back(5);
	vec.print();
	std::cout << vec.size() << " " << vec.capacity() << std::endl;
	return 0;
}