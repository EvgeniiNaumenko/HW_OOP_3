#pragma once
class MyString
{
	char* str;
	int length;
	static int countObj;
public:
	MyString(); //Хконструктор по умолчанию, позвол€ющий создать строку длиной 80 символов;
	MyString(int size); //Х	конструктор, позвол€ющий создавать строку произвольного размера;
	MyString(char* s); //Х	конструктор, который создаЄт строку и инициализирует еЄ строкой, полученной от пользовател€.
	MyString(const MyString& obj); //Хvoid MyStrcpy(MyString& obj);// копирование строк
	~MyString(); //Х	деструктор;
	void input(); //Хметоды дл€ ввода строк с клавиатуры и вывода строк на экран.
	void output(); //Хметоды дл€ ввода строк с клавиатуры и вывода строк на экран.
	int MyStrLen(); // возвращает длину строки
	char* getStr(); // в задании нет! возвращает указатель на новый массив символов!
	void setStr(); // в задании нет! установка строки
	static int getCountObj(); //Х	—татическое поле сохран€ет кол - во созданных объектов.
	bool MyStrStr(const char* str); // поиск подстроки в строке
	int  MyChr(char c); // поиск символа в строке(индекс найденного символа, либо -1)
	void MyStrCat(MyString& str); // объединение строк
	void MyDelChr(char c); // удал€ет указанный символ 
	int MyStrCmp(MyString& b); // сравнение строк 
};

