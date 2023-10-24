#pragma once

#define MAX_DATA_COUNT 10

#ifndef _SCOREMANAGER_H_
#define _SCOREMANAGER_H_

#include "student.h"

class ScoreManager 
{
private:
    Student students[MAX_DATA_COUNT];               //�л��� �ִ� 10����� �����ϵ��� �迭�� ���� ����
    int numStudents;                                //�л� �� ����

public:
    ScoreManager();                                 //�⺻������
    void AddStudent(const Student& student);        //�л� ���� �߰�
    void StudentsInfo() const;                      //��� �л����� ���� ���
    void SearchName(const string& name) const;      //�̸����� �л��� ���� ���
    void SearchNum(int number) const;               //��ȣ�� �л��� ���� ���
    void AvgRank(string targetName) const;          //�̸��� �Է¹޾� ��հ� ���� ���
    void AvgSort() const;                           //����� ���� ������� �̸� ���

    const Student& GetStudent(int index) const;     //�ش� �ε����� ����Ǿ��ִ� �л��� ���� ��ȯ
    int GetNum() const;                             //Ŭ������ ����Ǿ��ִ� �л��� �� ��ȯ
};

#endif // !_SCOREMANAGER_H_
