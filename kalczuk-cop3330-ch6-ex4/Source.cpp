#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

class Name_value {

public:
    Name_value(string name, int score) :
        name_(name), score_(score) {}
    string name() { return name_; }
    int score() { return score_; }

private:
    string name_;
    int score_;
};

class ListStudent {

private:
    vector<Name_value> list;

public:
    bool is_vaild(string name) 
    {
        if (list.size() == 0) return 1;
        for (auto elem : list)
            if (elem.name() == name) return 0;

        return 1;
    }
    void add(Name_value student) {
        if (is_vaild(student.name()))
            list.push_back(student);
        else
            cout << "Doublicate name" << endl;
    }
    void printf() {
        for (auto elem : list)
            cout << " Name: " << elem.name() << " \tScore: " << elem.score() << endl;
    }

};



int main(int argc, char const* argv[])
{
    ListStudent List_student;
    try {
        string name;
        int score;
        cout << "Enter name/value pairs, like 'Joe 17 or Barbara 22'. End the program with NoName 0\n";
        for (; cin >> name >> score && name != "NoName" && score != 0;)
            List_student.add({ name,score });
        List_student.printf();
    }
    catch (runtime_error& e) {
        cout << e.what();
    }
    catch (...) {
        cout << "Exiting...";
    }
    return 0;
}