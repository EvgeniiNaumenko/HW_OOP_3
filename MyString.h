#pragma once
class MyString
{
	char* str;
	int length;
	static int countObj;
public:
	MyString(); //������������ �� ���������, ����������� ������� ������ ������ 80 ��������;
	MyString(int size); //�	�����������, ����������� ��������� ������ ������������� �������;
	MyString(char* s); //�	�����������, ������� ������ ������ � �������������� � �������, ���������� �� ������������.
	MyString(const MyString& obj); //�void MyStrcpy(MyString& obj);// ����������� �����
	~MyString(); //�	����������;
	void input(); //������� ��� ����� ����� � ���������� � ������ ����� �� �����.
	void output(); //������� ��� ����� ����� � ���������� � ������ ����� �� �����.
	int MyStrLen(); // ���������� ����� ������
	char* getStr(); // � ������� ���! ���������� ��������� �� ����� ������ ��������!
	void setStr(); // � ������� ���! ��������� ������
	static int getCountObj(); //�	����������� ���� ��������� ��� - �� ��������� ��������.
	bool MyStrStr(const char* str); // ����� ��������� � ������
	int  MyChr(char c); // ����� ������� � ������(������ ���������� �������, ���� -1)
	void MyStrCat(MyString& str); // ����������� �����
	void MyDelChr(char c); // ������� ��������� ������ 
	int MyStrCmp(MyString& b); // ��������� ����� 
};

