// using set
#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    int roll;
    int marks;

    Student(string name, int roll, int marks)
    {
        this->name = name;
        this->roll = roll;
        this->marks = marks;
    }
};

class cmp
{
public:
    bool operator()(Student l, Student r) const
    {
        if(l.marks != r.marks)
        {
            return l.marks > r.marks;
        }
        else
        {
            return l.roll < r.roll;
        }
    }
};

int main()
{
    set<Student, cmp> st;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;

        Student obj(name, roll, marks);
        st.insert(obj);
    }

    if(!st.empty())
    {
        cout << st.begin()->name << " "
             << st.begin()->roll << " "
             << st.begin()->marks << endl;
    }

    return 0;
}

// using map

#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    int roll;
    int mark;

    Student(string name, int roll, int mark)
    {
        this->name = name;
        this->roll = roll;
        this->mark = mark;
    }
};

class cmp
{
public:
    bool operator()(pair<int, int> l, pair<int, int> r) const
    {
        if(l.first != r.first)
        {
            return l.first > r.first;
        }
        else
        {
            return l.second < r.second;
        }
    }
};

int main()
{
    map<pair<int, int>, Student, cmp> mp;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string name;
        int roll, mark;

        cin >> name >> roll >> mark;

        Student obj(name, roll, mark);

        mp.insert({{mark, roll}, obj});
    }

    if(!mp.empty())
    {
        cout << mp.begin()->second.name << " "
             << mp.begin()->second.roll << " "
             << mp.begin()->second.mark << endl;
    }

    return 0;
}
