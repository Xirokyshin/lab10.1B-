#include "pch.h"
#include "CppUnitTest.h"
#include "../PR10.1.B.cpp"  
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        // ���� ��� CountHighAverageStudents
        TEST_METHOD(TestCountHighAverageStudents)
        {
            // ������� ����� ��������
            Student students[3] = {
                {"��������", 2, KN, 5, 5},  // ������� � ��������������
                {"��������", 3, INF, 4, 4}, // ������� � ���������� ��������
                {"���������", 1, ME, 5, 3}  // ������� � ���������
            };
            students[0].ocinka_programuvannia = 5;  
            students[1].ocinka_chyselni_metody = 5; 
            students[2].ocinka_pedahohika = 5;     

            
            int result = CountHighAverageStudents(students, 3);
            Assert::AreEqual(0, result);
        }

        // ���� ��� FindHighestAverageSubject
        TEST_METHOD(TestFindHighestAverageSubject)
        {
            // ������� ����� ��������
            Student students[4] = {
                {"��������", 2, KN, 5, 4},  // ������� � ��������������
                {"��������", 3, INF, 3, 5}, // ������� � ���������� ��������
                {"���������", 1, ME, 4, 4}, // ������� � ���������
                {"���������", 4, TN, 5, 5}  // ������� � ���������
            };

            students[0].ocinka_programuvannia = 5;   
            students[1].ocinka_chyselni_metody = 4;  
            students[2].ocinka_pedahohika = 5;       
            students[3].ocinka_pedahohika = 5;       

            
            string expected = "�������������";
            string result = FindHighestAverageSubject(students, 4);
            Assert::AreEqual(expected, result);
        }
    };
}
