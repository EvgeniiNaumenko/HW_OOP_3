#include <iostream>
using namespace std;
#include "MyString.h"

//����������� ����� MyString
//�	����������� �� ���������, ����������� ������� ������ ������ 80 ��������;
//�	�����������, ����������� ��������� ������ ������������� �������;
//�	�����������, ������� ������ ������ � �������������� � �������, ���������� �� ������������.
//�	����������;
//�	������ ��� ����� ����� � ���������� � ������ ����� �� �����.
//�	void MyStrcpy(MyString& obj);// ����������� �����
//�	bool MyStrStr(const char* str);// ����� ��������� � ������
//�	int  MyChr(char c); // ����� ������� � ������(������ ���������� �������, ���� -1)
//�	int MyStrLen();// ���������� ����� ������
//�	void MyStrCat(MyString& b); // ����������� �����
//�	void MyDelChr(char c); // ������� ��������� ������ 
//�	int MyStrCmp(MyString& b); // ��������� ����� 
//-1 � ������ ������ ������ ��� ������
//1 � ������ ������ ��� ������
//0 � ������ �����!
//�	����������� ���� ��������� ��� - �� ��������� ��������.





int main()
{
	MyString str; //������ ������ ��������� ����������� �� 80 �������� +1 ��� �������
	char name[] = "Hello";
	MyString str2 = name; // ������� ������ ������ ����� ����������� ����������� ������
	int size = 6;
	MyString str3 = size; //������� ������ ������ ����� ����������� ����������� ������ ������
	str3.input(); // ����� ����� ( �� ������ ������ ������ ������������ �� ����� ������������
	str.output(); //����� ������ ������ � ������� ��� ������ ������
	str2.output(); //����� ������ ������ � ������� ��� ������ ������
	str3.output(); //����� ������ ������ � ������� ��� ������ ������
	MyString str4 = str3; //����������� ������ 3 � ������ 4
	str4.output(); //����� ������ ������ � ������� ��� ������ ������
	char serchChar = 'e'; // ������� ������
	char serchChar2 = 'b'; // ������� ������
	cout<<"index of search char (if -1 no char in str): "<<str2.MyChr(serchChar)<<endl; // ���� ������
	cout << "index of search char (if -1 no char in str): " << str2.MyChr(serchChar2)<<endl; // ���� ������
	char newStr[] = "World!";// ����� ��� �����������
	MyString str5 = newStr;
	char newStr2[] = "World"; // ����� ��� ������
	str2.MyStrCat(str5);
	str5.output();
	str2.output();
	cout << str5.MyStrStr(newStr2) << endl; //����� ��������� � ������ ���� 1 �� ����� ���� 0 �� �������
	cout << " OBJ: " << MyString::getCountObj()<<endl;
	//������� ������
	cout<<str.MyStrLen() <<endl;
	cout << str2.MyStrLen() << endl;
	cout << str3.MyStrLen() << endl;
	cout << str4.MyStrLen() << endl;
	cout << str5.MyStrLen() << endl;
	//������ ������
	str5.MyDelChr('o');//������� ������
	str5.output();
	return 0;
}