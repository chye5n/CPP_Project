#pragma once
#include <string>
using namespace std;

#ifndef _STUDENT_H_	//if not define		//define�Ǿ����� �ʴٸ� define�ض�
#define _STUDENT_H_

class Student 
{
private:
    string name;
    int number,koreanScore, englishScore, mathScore;

public:
    Student();                              //�⺻������
    Student(const string& name, int number, int koreanScore, int englishScore, int mathScore);  //�л��� ���� �ޱ�
    void Info() const;               //�л��� ���� ���
    double Avg() const;        //�л��� ��հ��

    const string& GetName() const;          //�л��� �̸� ��ȯ
    const int GetNumber() const;            //�л��� ��ȣ ��ȯ
};

#endif // !_STUDENT_H_
