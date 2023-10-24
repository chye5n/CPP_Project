#include "Student.h"
#include <iostream>
using namespace std;

Student::Student() : name(""), number(0), koreanScore(0), englishScore(0), mathScore(0) { } //ó�� ������ ��� �л��� ���� �ʱ�ȭ

Student::Student(const string& name, int number, int koreanScore, int englishScore, int mathScore) : name(name), number(number), koreanScore(koreanScore), englishScore(englishScore), mathScore(mathScore) { } //�л��� ���� ����

void Student::Info() const                                  //�л��� ���� ���
{
    double average = Avg();                    //��� ���
    cout << "�̸� : " << name << ", ��ȣ : " << number << ", ���� : " << koreanScore << ", ���� : " << englishScore << ", ���� : " << mathScore << ", ��� : " << average << endl;
}

double Student::Avg() const { return static_cast<double>(koreanScore + englishScore + mathScore) / 3; }    //��հ��

const string& Student::GetName() const { return name; }     //private�� �����Ǿ��ִ� �л��� �̸� ��ȯ

const int Student::GetNumber() const { return number; }     //private�� �����Ǿ��ִ� �л��� ��ȣ ��ȯ
