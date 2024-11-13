#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

// ������ ��������������
enum Specialnist { KN, INF, ME, FI, TN };
string specialnistStr[] = { "����'����� �����", "�����������", "���������� �� ��������", "Գ���� �� �����������", "������� ��������" };

// ��������� ��� ��������� ���������� ��� ��������
struct Student {
    string prizv;
    int kurs;
    Specialnist specialnist;
    int ocinka_fizyka;
    int ocinka_matematyka;
    union {
        int ocinka_programuvannia;
        int ocinka_chyselni_metody;
        int ocinka_pedahohika;
    };
};

// ������� ��� ��������� ������ ��������
void CreateStudents(Student* students, const int N) {
    for (int i = 0; i < N; i++) {
        cout << "������� � " << i + 1 << ":" << endl;
        cout << " �������: ";
        cin >> students[i].prizv;
        cout << " ����: ";
        cin >> students[i].kurs;

        int specialnist;
        cout << " ������������ (0 - ����'����� �����, 1 - �����������, 2 - ���������� �� ��������, 3 - Գ���� �� �����������, 4 - ������� ��������): ";
        cin >> specialnist;
        students[i].specialnist = (Specialnist)specialnist;

        // �������� ������ � ������ �� ����������
        cout << " ������ � ������: ";
        cin >> students[i].ocinka_fizyka;
        cout << " ������ � ����������: ";
        cin >> students[i].ocinka_matematyka;

        // �������� ������ ������ ������� �� ������������
        if (students[i].specialnist == KN) {
            cout << " ������ � �������������: ";
            cin >> students[i].ocinka_programuvannia;
        }
        else if (students[i].specialnist == INF) {
            cout << " ������ � ��������� ������: ";
            cin >> students[i].ocinka_chyselni_metody;
        }
        else {
            cout << " ������ � ���������: ";
            cin >> students[i].ocinka_pedahohika;
        }
        cout << endl;
    }
}

// ������� ��� ��������� ������� ��������
void PrintStudents(const Student* students, const int N) {
    cout << "==============================================================================================================================" << endl;
    cout << "| � | �������          | ���� | ������������          | Գ���� | ���������� | ������������� | ������� ������ | ��������� |" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++) {
        cout << "| " << setw(2) << i + 1 << "|  " << setw(16) << left << students[i].prizv
            << " | " << setw(4) << right << students[i].kurs
            << " |" << setw(23) << left << specialnistStr[students[i].specialnist]
            << " | " << setw(6) << right << students[i].ocinka_fizyka
            << " | " << setw(10) << right << students[i].ocinka_matematyka;

        if (students[i].specialnist == KN) {
            cout << " |  " << setw(12) << right << students[i].ocinka_programuvannia
                << " | " << setw(15) << "-"
                << " | " << setw(10) << "-";
        }
        else if (students[i].specialnist == INF) {
            cout << " | " << setw(12) << "-"
                << "  | " << setw(15) << students[i].ocinka_chyselni_metody
                << " | " << setw(10) << "-";
        }
        else {
            cout << " |" << setw(14) << "-"
                << " | " << setw(15) << "-"
                << " | " << setw(10) << students[i].ocinka_pedahohika;
        }
        cout << " |" << endl;
    }
    cout << "==============================================================================================================================" << endl;
}

// ������� ��� ���������� ������� �������� �� ������� ����� > 4.5
int CountHighAverageStudents(const Student* students, const int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        double avg = (students[i].ocinka_fizyka + students[i].ocinka_matematyka) / 2.0;
        if (students[i].specialnist == KN) {
            avg = (avg + students[i].ocinka_programuvannia) / 3.0;
        }
        else if (students[i].specialnist == INF) {
            avg = (avg + students[i].ocinka_chyselni_metody) / 3.0;
        }
        else {
            avg = (avg + students[i].ocinka_pedahohika) / 3.0;
        }

        if (avg > 4.5) {
            count++;
        }
    }
    return count;
}

// ������� ��� ���������� �������� � �������� ������� �����
string FindHighestAverageSubject(const Student* students, const int N) {
    double sumFizyka = 0, sumMatematyka = 0, sumProgramuvannia = 0;
    double sumChyselniMetody = 0, sumPedahohika = 0;
    int countFizyka = 0, countMatematyka = 0, countProgramuvannia = 0;
    int countChyselniMetody = 0, countPedahohika = 0;

    for (int i = 0; i < N; i++) {
        sumFizyka += students[i].ocinka_fizyka;
        countFizyka++;
        sumMatematyka += students[i].ocinka_matematyka;
        countMatematyka++;

        if (students[i].specialnist == KN) {
            sumProgramuvannia += students[i].ocinka_programuvannia;
            countProgramuvannia++;
        }
        else if (students[i].specialnist == INF) {
            sumChyselniMetody += students[i].ocinka_chyselni_metody;
            countChyselniMetody++;
        }
        else {
            sumPedahohika += students[i].ocinka_pedahohika;
            countPedahohika++;
        }
    }

    double avgFizyka = sumFizyka / countFizyka;
    double avgMatematyka = sumMatematyka / countMatematyka;
    double avgProgramuvannia = (countProgramuvannia > 0) ? sumProgramuvannia / countProgramuvannia : 0;
    double avgChyselniMetody = (countChyselniMetody > 0) ? sumChyselniMetody / countChyselniMetody : 0;
    double avgPedahohika = (countPedahohika > 0) ? sumPedahohika / countPedahohika : 0;

    double maxAvg = avgFizyka;
    string subject = "Գ����";

    if (avgMatematyka > maxAvg) {
        maxAvg = avgMatematyka;
        subject = "����������";
    }
    if (avgProgramuvannia > maxAvg) {
        maxAvg = avgProgramuvannia;
        subject = "�������������";
    }
    if (avgChyselniMetody > maxAvg) {
        maxAvg = avgChyselniMetody;
        subject = "������� ������";
    }
    if (avgPedahohika > maxAvg) {
        maxAvg = avgPedahohika;
        subject = "���������";
    }

    return subject;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int N;
    cout << "������ ������� ��������: ";
    cin >> N;

    // ��������� ����� ��� ��������
    Student* students = new Student[N];

    // ������ ������� ��� ���������� � ��������� ��������
    CreateStudents(students, N);
    PrintStudents(students, N);

    // ���������� ������� �������� �� ������� ����� > 4.5
    int highAvgCount = CountHighAverageStudents(students, N);
    cout << "ʳ������ �������� �� ������� ����� ����� �� 4.5: " << highAvgCount << endl;

    // ���������� �������� � �������� ������� �����
    string highestAvgSubject = FindHighestAverageSubject(students, N);
    cout << "������� �� �������� ������� �����: " << highestAvgSubject << endl;

    // ��������� ���'��
    delete[] students;
    return 0;
}
