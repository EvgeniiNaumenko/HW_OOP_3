#include "MyString.h"
#include <iostream>
using namespace std;

//•	конструктор по умолчанию, позволяющий создать строку длиной 80 символов;
MyString::MyString() :MyString(80) {}

//•	конструктор, позволяющий создавать строку произвольного размера;
MyString::MyString(int lenght)
{
	if (lenght > 0)
	{
		this->length = lenght;
		this->str = new char[this->length];
		countObj++;
	}
}
//•	конструктор, который создаёт строку и инициализирует её строкой, полученной от пользователя.
MyString::MyString(char* s)
{
	if (s != nullptr)
	{
		for (int i = 0; s[i] != '\0'; i++)
		{
			if (s[i] != '\0')
			{
				this->length++;
			}
		}
		this->str = new char[this->length+1];
		for (int i = 0; i < this->length; i++)
		{
			this->str[i] = s[i];
		}
		this->str[this->length] = '\0';
		countObj++;
	}
}

//•	void MyStrcpy(MyString& obj);// копирование строк
MyString::MyString(const MyString& obj)
{
	this->length = obj.length;
	if (obj.str != nullptr)
	{
		this->str = new char[this->length+1];
		for (int i = 0; i < this->length; i++)
		{
			this->str[i] = obj.str[i];
		}
		this->str[this->length] = '\0';
		countObj++;
	}
}

//•	деструктор;
MyString::~MyString()
{
	if (str != nullptr)
	{
		delete[] str;
	}
}

//•	методы для ввода строк с клавиатуры и вывода строк на экран.
void MyString::input()
{
	if (this->str != nullptr)
	{
		delete[] str;
	}
	int count = 0;
	int const mesSize = 100;
	char newMes[mesSize];
	cout << "Enter message!" << endl;
	cin.getline(newMes, mesSize - 1);

	// пересмотреть
	for (int i = 0; i<mesSize; i++)
	{
		if (newMes[i] != '\0')
		{
			count++;
		}
		else
		{
			break;
		}
	}
	this->str = new char[length + 1];
	for (int i = 0; i < count+1; i++)
	{
		this->str[i] = newMes[i];
	}
	this->str[count] = '\0';

}

//•	методы для ввода строк с клавиатуры и вывода строк на экран.
void MyString::output()
{
	if (this->str != nullptr)
	{
		for (int i = 0; i < this->length; i++)
		{
			if (str[i] != '\0')
			{
				cout << str[i];
			}
			else
				break;
		}
		cout << endl;
	}
}

//•	int MyStrLen();// возвращает длину строки
int MyString::MyStrLen()
{
	return this->length;
}

// в задании нет! возвращает указатель на новый массив символов!
char* MyString::getStr()
{
	char* strCopy = new char[this->length];
	for (int i = 0; i < length; i++)
	{
		strCopy[i] = this->str[i];
	}
	strCopy[length] = '\0';
	return strCopy;
}
// в задании нет! установка строки
void MyString::setStr()
{
	if (this->str!= nullptr)
	{
		delete[]str;
	}
	cout << "Enter message! (Length :" << this->length-1<<"char) "<< endl;
	this->str = new char[this->length];
	cin.getline(this->str, this->length);
	for (int i = 0; i < length; i++)
	{
		str[i] = this->str[i];
	}
	this->str[length] = '\0';
	
}
//•	Статическое поле сохраняет кол - во созданных объектов.
int MyString::getCountObj()
{
	return countObj;
}

//•	bool MyStrStr(const char* str);// поиск подстроки в строке
bool MyString::MyStrStr(const char* str)
{
	for (int i = 0; this->str[i] != '\0'; ++i) {
		int j = 0;
		while (str[j] != '\0' && this->str[i + j] == str[j]) {
			++j;
		}
		if (str[j] == '\0') {
			return true; // Подстрока найдена
		}
	}
	return false; // Подстрока не найдена
}

//•	int  MyChr(char c); // поиск символа в строке(индекс найденного символа, либо -1)
int MyString::MyChr(char c)
{
	for (int i = 0; i < this->length; i++)
	{
		if (this->str[i]== c)
		{
			return i;
		}
	}
	return -1;
}

//•	void MyStrCat(MyString& b); // объединение строк
void MyString::MyStrCat(MyString& str)
{
	int newLength = this->length + str.length+2;
	char* newStr = new char[newLength];
	for (int i = 0; i < this->length; i++)
	{
		newStr[i] = this->str[i];	
	}
	newStr[this->length] = ' ';
	for (int i = this->length+1,j = 0; j < str.length; i++, j++)
	{
		newStr[i] = str.str[j];
	}
	newStr[newLength-1] = '\0';
	this->length = newLength;
	delete[] this->str;
	this->str = newStr;
}

//•	void MyDelChr(char c); // удаляет указанный символ 
void MyString::MyDelChr(char c)
{
	int counter = 0;
	for (int i = 0; i < this->length; i++)
	{
		if (this->str[i] == c)
		{
			counter++;
		}
	}
	int newLength = this->length -counter;
	char* newStr = new char[newLength];
	for (int i = 0,j=0; i < this-> length; i++)
	{
		if (this->str[i]!= c)
		{
			newStr[j] = this->str[i];
			j++;
		}
	}
	newStr[newLength] = '\0';
	this->length = newLength;
	delete[] this->str;
	this->str = newStr;
}

//•	int MyStrCmp(MyString& b); // сравнение строк 
int MyString::MyStrCmp(MyString& b)
{
	int result = strcmp(this->str, b.str);

	if (result == 0) {
		return 0; // строки равны
	}
	else if (result < 0) {
		return -1; // первая строка меньше второй
	}
	else {
		return 1; // наоборот
	}
}

int MyString::countObj = 0; // инициализация статического поля