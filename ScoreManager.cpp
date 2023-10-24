#include "ScoreManager.h"
#include <iostream>
#include <algorithm>
using namespace std;

ScoreManager::ScoreManager() : numStudents(0) { }       //ó�� ������ ��� �л� ���� 0

void ScoreManager::AddStudent(const Student& student)  { students[numStudents++] = student; }   //�л��� ������ �޾� students�迭�� ���� �� �л� �� ����

void ScoreManager::StudentsInfo() const           //��� �л����� ���� ��ȯ
{
    for (int i = 0; i < numStudents; ++i) { students[i].Info(); }
}

void ScoreManager::SearchName(const std::string& name) const      //�л��� �̸��� �Է¹޾� �л��� ���� ���
{
    bool found = false;                     //�л��� �̸��� �ִ� ��� true�� ����
    for (int i = 0; i < numStudents; ++i)   //����Ǿ��ִ� �л� ����ŭ �ݺ�
    {
        if (students[i].GetName() == name)  //�̸��� ���� ���
        {
            students[i].Info();      //�л��� ���� ���
            found = true;
        }
    }

    if (!found) { cout << "�ش� �̸��� �л��� ã�� �� �����ϴ�.\n"; }  //�´� �̸��� ���� ��� ���
}

void ScoreManager::SearchNum(int number) const     //�л��� ��ȣ�� �Է¹޾� �л��� ���� ���
{
    bool found = false;                         //��ȣ�� �´� �л��� �ִ� ��� true�� ����
    for (int i = 0; i < numStudents; ++i)       //����Ǿ��ִ� �л� ����ŭ �ݺ�
    {
        if (students[i].GetNumber() == number)  //���� ��ȣ�� ������ ���
        {
            students[i].Info();          //�л��� ���� ���
            found = true;
        }
    }

    if (!found) { cout << "�ش� ��ȣ�� �л��� ã�� �� �����ϴ�.\n"; }  //�´� ��ȣ�� ���� ��� ���
}

void ScoreManager::AvgRank(string targetName) const    //�̸��� �Է¹޾� ��հ� ���� ���
{
    int targetIndex = -1;                           //�Է� ���� �л��� �ε��� ã��
    for (int i = 0; i < numStudents; ++i)           //����Ǿ��ִ� �л� ����ŭ �ݺ�
    {
        if (students[i].GetName() == targetName) { targetIndex = i; }   //����Ǿ��ִ� �̸��� �Է¹��� �̸��� ���� ��� targetIndex�� i�� ����
    }

    if (targetIndex != -1)                          //�ε����� ����Ǿ��� ���
    {
        const Student& targetStudent = students[targetIndex];   //�Է¹��� �л��� ���� ��������
        double average = targetStudent.Avg();      //�л��� ��� ���
        
        int rank = 1;                                           //�л��� ������ ������ ��������
        for (int i = 0; i < numStudents; ++i) { if (students[i].Avg() > average) { rank++; } }     //�ٸ� �л���� ����� ����Ͽ� �Է¹��� �л��� ��պ��� ���� ��� rank����

        cout << "�̸� : " << targetStudent.GetName() << ", ��� : " << average << " ���� : " << rank << endl;   //�л��� ��հ� ���� ���
    }
    else { cout << "�ش� �̸��� �л��� ã�� �� �����ϴ�.\n";}  //�̸��� ���� ���
}

void ScoreManager::AvgSort() const             //����� ���� ������� �̸� ���
{
    Student studentsCopy[MAX_DATA_COUNT];                       //��� ������� ������ ���ο� �迭 ����
    for (int i = 0; i < numStudents; ++i) { studentsCopy[i] = students[i]; }    //�迭�� ����Ǿ��ִ� ���� ����

    sort(studentsCopy, studentsCopy + numStudents, [](const Student& a, const Student& b) { return a.Avg() > b.Avg(); } );    // ��տ� ���� �������� ����

    cout << "����� ���� ������ �л� �̸� ���\n";
    for (int i = 0; i < numStudents; ++i) { cout << studentsCopy[i].GetName() << "\n"; }    //���ĵ� �迭 ������� ���
}

const Student& ScoreManager::GetStudent(int index) const { return students[index]; }        //private�� �����Ǿ��ִ� �л��� ���� ��ȯ

int ScoreManager::GetNum() const { return numStudents; }                            //private�� �����Ǿ��ִ� ����Ǿ��ִ� �л� �� ��ȯ