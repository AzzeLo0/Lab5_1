#include <iostream>

using namespace std;

// Рекурсивна функція Аккермана
unsigned long long ackermannRec(int m, int n, int depth, int& maxDepth)
{
    if (depth > maxDepth)
    {
        maxDepth = depth;
    }
    if (m == 0)
    {
        return n + 1;
    }
    if (n == 0)
    {
        return ackermannRec(m - 1, 1, depth + 1, maxDepth);
    }
    return ackermannRec(
        m - 1,
        ackermannRec(m, n - 1, depth + 1, maxDepth),
        depth + 1,
        maxDepth
    );
}
// Ітеративний варіант
unsigned long long ackermannIter(int m, int n, long long& iterations)
{
    int stack[10000];
    int top = 0;
    stack[0] = m;
    iterations = 0;
    while (top >= 0)
    {
        m = stack[top];
        top = top - 1;
        iterations = iterations + 1;
        if (m == 0)
        {
            n = n + 1;
        }
        else if (n == 0)
        {
            n = 1;
            top = top + 1;
            stack[top] = m - 1;
        }
        else
        {
            n = n - 1;
            top = top + 1;
            stack[top] = m - 1;
            top = top + 1;
            stack[top] = m;
        }
    }
    return n;
}
int main()
{
    cout << "Laboratory work 5, variant 3" << endl;
    cout << "Student: Sarzhevskyi Daniil Oleksandrovych" << endl;
    cout << "Group: IPZ-12(6)" << endl;
    int m, n;
    int maxDepth = 0;
    long long iterations;
    cout << "\nTASK 1" << endl;
    cout << "Enter m: ";
    cin >> m;
    cout << "Enter n: ";
    cin >> n;
    if (m < 0 || n < 0)
    {
        cout << "Incorrect values" << endl;
        return 0;
    }
    unsigned long long resultRec;
    unsigned long long resultIter;
    resultRec = ackermannRec(m, n, 1, maxDepth);
    resultIter = ackermannIter(m, n, iterations);
    cout << endl;
    cout << "Recursive result = " << resultRec << endl;
    cout << "Recursion depth = " << maxDepth << endl;
    cout << endl;
    cout << "Iterative result = " << resultIter << endl;
    cout << "Iterations = " << iterations << endl;
    return 0;
}