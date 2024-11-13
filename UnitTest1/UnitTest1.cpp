#include "pch.h"
#include "CppUnitTest.h"
#include "../PR10.1.B.cpp"  
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        // Тест для CountHighAverageStudents
        TEST_METHOD(TestCountHighAverageStudents)
        {
            // Приклад даних студентів
            Student students[3] = {
                {"Іваненко", 2, KN, 5, 5},  // Студент з програмуванням
                {"Петренко", 3, INF, 4, 4}, // Студент з чисельними методами
                {"Сидоренко", 1, ME, 5, 3}  // Студент з педагогіки
            };
            students[0].ocinka_programuvannia = 5;  
            students[1].ocinka_chyselni_metody = 5; 
            students[2].ocinka_pedahohika = 5;     

            
            int result = CountHighAverageStudents(students, 3);
            Assert::AreEqual(0, result);
        }

        // Тест для FindHighestAverageSubject
        TEST_METHOD(TestFindHighestAverageSubject)
        {
            // Приклад даних студентів
            Student students[4] = {
                {"Іваненко", 2, KN, 5, 4},  // Студент з програмуванням
                {"Петренко", 3, INF, 3, 5}, // Студент з чисельними методами
                {"Сидоренко", 1, ME, 4, 4}, // Студент з педагогіки
                {"Коваленко", 4, TN, 5, 5}  // Студент з педагогіки
            };

            students[0].ocinka_programuvannia = 5;   
            students[1].ocinka_chyselni_metody = 4;  
            students[2].ocinka_pedahohika = 5;       
            students[3].ocinka_pedahohika = 5;       

            
            string expected = "Програмування";
            string result = FindHighestAverageSubject(students, 4);
            Assert::AreEqual(expected, result);
        }
    };
}
