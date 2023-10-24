#include<iostream>
#include"ScoreManager.h"
#include"Student.h"
using namespace std;

ScoreManager scoreManager;                                                  //ScoreManager ������

void showMenu()                                                             //�޴� �����ֱ�
{
    cout << "1. ������ �Է�" << endl;
    cout << "2. �Է��� ��� ���� ���" << endl;
    cout << "3. �̸����� �˻��ϱ�" << endl;
    cout << "4. ��ȣ�� �˻��ϱ�" << endl;
    cout << "5. �̸� �Է� �Է� �޾� ��հ� ������ ���" << endl;
    cout << "6. ��� ������ ���� ������ �̸��� ���" << endl;
    cout << "���Ḧ ���Ͻø� q �Ǵ� Q�� ��������" << endl;
}

void InputData(ScoreManager& scoreManager)                                  //1. �л� ���� �߰�
{
    if (scoreManager.GetNum() >= MAX_DATA_COUNT) { cout << "�߰� �Է��� �Ұ����մϴ�.\n"; }
    else
    {
        char name[30];
        int num, kor, eng, math;
        cout << "�̸� : ";
        cin >> name;
        cout << "��ȣ : ";
        cin >> num;
        cout << "���� : ";
        cin >> kor;
        cout << "���� : ";
        cin >> eng;
        cout << "���� : ";
        cin >> math;

        Student student(name, num, kor, eng, math);
        scoreManager.AddStudent(student);
    }
}

void SearchName(const ScoreManager& scoreManager)                           //3. �̸����� �˻�
{
    string name;
    cout << "�˻��� �л��� �̸��� �Է��ϼ���: ";
    cin >> name;

    scoreManager.SearchName(name);
}

void SearchNum(const ScoreManager& scoreManager)                            //4. ��ȣ�� �˻�
{
    int num;
    cout << "�˻��� �л��� ��ȣ�� �Է��ϼ���: ";
    cin >> num;

    scoreManager.SearchNum(num);
}

void AvgRank(const ScoreManager& scoreManager)                              //5. �̸����� ��հ� ���� ���
{
    string name;
    cout << "��հ� ������ ����� �л��� �̸��� �Է��ϼ���: ";
    cin >> name;

    scoreManager.AvgRank(name);
}

void RunMenu(char a, ScoreManager& scoreManager)                            //������ �ڵ� ����
{
    switch (a) {
    case '1': InputData(scoreManager); break;
    case '2': scoreManager.StudentsInfo(); break;
    case '3': SearchName(scoreManager); break;
    case '4': SearchNum(scoreManager); break;
    case '5': AvgRank(scoreManager); break;
    case '6': scoreManager.AvgSort(); break;
    case 'q':
    case 'Q': cout << "���α׷��� �����մϴ�.\n"; exit(0); break;
    default: cout << "�߸��� �����Դϴ�. �ٽ� �������ּ���.\n";
    }
}

void selectMenu(ScoreManager& scoreManager)                                 //������ �ڵ��� ��ȣ �Է¹ޱ�
{
    char choice;
    cout << "�����Է� : ";
    cin >> choice;
    RunMenu(choice, scoreManager);
}

void main() 
{
    while (1)
    {
        showMenu();
        selectMenu(scoreManager);
    }
}