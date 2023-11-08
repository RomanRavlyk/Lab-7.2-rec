#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 7.2 rec/Lab 7.2 rec.cpp" // ϳ�������� ��� �������� ����

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            int n = 5;
            int** a = new int* [n];
            for (int i = 0; i < n; i++)
                a[i] = new int[n];

            // �������� ������� ����������, �� � ������ ��������� ����
            int Low = -50;
            int High = 50;
            CreateRows(a, n, Low, High, 0);

            // �������� ���� ������� (FindMinMax) � ��������� �����
            int minAboveDiagonal = a[0][n - 1];
            int maxBelowDiagonal = a[n - 1][0];
            int sum = 0;
            FindMinMax(a, n, 0, 0, minAboveDiagonal, maxBelowDiagonal, sum);

            // ���������, �� ��������� ������� ����������� ����������
            Assert::AreEqual(-12, minAboveDiagonal);
            Assert::AreEqual(40, maxBelowDiagonal);
            Assert::AreEqual(28, sum);

            // ��������� ������� ���'��
            for (int i = 0; i < n; i++)
                delete[] a[i];
            delete[] a;
        }
    };
}