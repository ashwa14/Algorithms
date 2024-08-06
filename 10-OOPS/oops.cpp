#include <bits/stdc++.h>
using namespace std;
#define ll long long

//* Human class
class Human
{
protected:
    string secret = "humansecret";

private:
    string pvt = "humanprivate";

public:
    int age = 30, weight = 76;
};

// *Student class
class Student : protected Human
{
public:
    string name = "student";
    void print()
    {
        cout << this->secret << endl;
        // cout << pvt << endl;
        cout << name << endl;
        cout << age << endl;
        cout << weight << endl;
    }
};

// *GStudent class

class GStudent : public Student
{
public:
    // string name = "gstudent";
    void print()
    {
        cout << name << endl;
        cout << age << endl; // member "Human::age" (declared at line 12) is inaccessible
        // cout << weight << endl; // error :  member "Human::weight" (declared at line 12) is inaccessible
    }
};

int main()
{
    Human h1;
    // cout << h1.secret << endl;

    Student s1;
    // cout << s1.age << endl;    // member "Human::age" (declared at line 12) is inaccessibleC/C++(265)
    // cout << s1.weight << endl; // error :  member "Human::weight" (declared at line 12) is inaccessibleC/C++(265)
    cout << s1.name << endl; // student
    s1.print();              // student 30 76

    GStudent g1;
    g1.print(); // student
    return 0;
}

