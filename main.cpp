//#include <iostream>
//
//int main() {
//    std::cout << "Hello, World!" << std::endl;
//    return 0;
//}
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <math.h>
#include <cmath>
#include <iomanip>

using namespace std;
struct student {
    char name[10], family[10], fathername[10];
    string studentID, nationalID, entraceyear, grade, birthyear;
};
struct code {
    string Code, name;
    float grade;
};
struct ID {
    float id, grade;
};
struct Grade {
    float grade, id;
};
struct code1 {
    float grade;
};

int main() {
    fstream f2, f3, f[20], f5, f6, f1[20];
    const int b = 7;
    string a[b], x, y, z;
    int i, e, ch;
    code c[20];
    code1 x1[20];
    f2.open("d:\\pfiles\\StudentInfo.txt", ios::out);
    f3.open("d:\\pfiles\\StudentInfo.txt", ios::in);
    student s[100];
    cout << "\t\tW e l l C o m e\t\tP r o j e c t 1\n";
    cout << "\t\t\tEnter a number ( 1 - 12 )\n";
    cout << "\t\t1 : Add a student\n";
    cout << "\t\t2 : Delete a student\n";
    cout << "\t\t3 : Update the student information\n";
    cout << "\t\t4 : Search for student information and grades\n";
    cout << "\t\t5 : Insert the new score\n";
    cout << "\t\t6 : Insert a list of grades for a course\n";
    cout << "\t\t7 : Remove score\n";
    cout << "\t\t8 : Remove score for a list\n";
    cout << "\t\t9 : Score updates\n";
    cout << "\t\t10 : View the status of lesson\n";
    cout << "\t\t11 : View the status of lesson\n";
    cout << "\t\t12 : Add Course\n";
    cout << "\t\t13 : End program\n";
    cout << "\t\t\t>>>> Which number : ";
    cin >> ch;
    system("cls");
    if (ch == 12) {
        cout << "Enter number of courses : ";
        cin >> e;
        for (i = 0; i < e; i++) {
            cout << "\nEnter name of course  " << i + 1 << " : ";
            cin >> c[i].name;
            cout << "Enter code of course  " << i + 1 << " : ";
            cin >> c[i].Code;
            f[i].open("d:\\pfiles\\" + c[i].Code + ".txt", ios::out);
            f1[i].open("d:\\pfiles\\" + c[i].Code + ".txt", ios::in);
        }
        system("cls");
        cout << "Courses Added Successfully\n";
        cout << "Enter end to return to menu : ";
        string z1;
        while (cin >> z1) {
            if (z1 == "end") {
                system("cls");
                main();
            }
        }
    }
    if (ch == 1) {
        cout << "\t\t\t\t>>> Add Student <<<\n\nEnter number of students : ";
        int m;
        cin >> m;
        system("cls");
        for (i = 0; i < m; i++) {
            int j = 0;
            //cout << "Enter grade of student:  " << i + 1 << " : ";
            //cin >> s[i].grade;
            //f[i] << s[i].grade << ' ';
            cout << "Enter Name of student  " << i + 1 << " : \t\t";
            cin >> s[i].name;
            a[j] = s[i].name;
            f2 << a[j] << ' ';
            cout << "\nEnter Family of student  " << i + 1 << " : \t\t";
            cin >> s[i].family;
            a[j + 1] = s[i].family;
            f2 << a[j + 1] << ' ';
            cout << "\nEnter FatherName of student  " << i + 1 << " : \t";
            cin >> s[i].fathername;
            a[j + 2] = s[i].fathername;
            f2 << a[j + 2] << ' ';
            cout << "\nEnter ID of student  " << i + 1 << " : \t\t";
            cin >> s[i].studentID;
            a[j + 3] = s[i].studentID;
            f2 << a[j + 3] << ' ';
            //f[i] << a[j + 3] << '\n';
            cout << "\nEnter NationalID of student  " << i + 1 << " : \t";
            cin >> s[i].nationalID;
            a[j + 4] = s[i].nationalID;
            f2 << a[j + 4] << ' ';
            cout << "\nEnter EntraceYear of student  " << i + 1 << " : \t";
            cin >> s[i].entraceyear;
            a[j + 5] = s[i].entraceyear;
            f2 << a[j + 5] << ' ';
            cout << "\nEnter BirthYear of student  " << i + 1 << " : \t";
            cin >> s[i].birthyear;
            a[j + 6] = s[i].birthyear;
            f2 << a[j + 6] << '\n';
            system("cls");
        }
        cout << "Students Informations Added Successfully\n";
        cout << "Enter end to return to menu : ";
        string z1;
        while (cin >> z1) {
            if (z1 == "end") {
                system("cls");
                main();
            }
        }
    }
    if (ch == 4) {
        cout << "\t\tSearch for student information and grades\n\nEnter student ID : ";
        string z;
        cin >> z;
        while (!f3.eof()) {
            for (i = 0; i < b; i++)
                f3 >> a[i];
            if (z == a[3]) {
                cout << "\n\n";
                cout << a[3] << " , " << a[0] << ' ' << a[1] << "\n";
                cout << "Birth Year  : " << a[6] << "\n";
                cout << "Entrance Year  : " << a[5] << "\n";
                cout << "National Code  : " << a[4] << "\n\n";
            }
        }
        cout << "Course ID      Grade\n";
        cout << "-------------------------\n";
        for (i = 0; i < e; i++) {
            cout << c[i].Code << "\t\t";
            string p;
            while (!f1[i].eof()) {
                f1[i] >> c[i].grade >> p;
                if (z == p) {
                    cout << c[i].grade << "\n\n";
                    x1[i].grade = c[i].grade;
                }
            }
        }
        float sum = 0, mean, sum1 = 0, var;
        for (i = 0; i < e; i++)
            sum += x1[i].grade;
        mean = sum / e;
        cout << "Mean" << "\t\t" << mean << "\n";
        for (i = 0; i < e; i++)
            sum1 += pow((x1[i].grade - mean), 2);
        var = sum1 / e;
        cout << "Variance\t" << var << "\n";
        float max = 20, min = 0;
        int a1, o;
        for (i = 0; i < e; i++) {
            if (x1[i].grade < max) {
                max = x1[i].grade;
                a1 = i;
            } else if (x1[i].grade > min) {
                min = x1[i].grade;
                o = i;
            }
        }
        cout << "Min\t\t" << x1[a1].grade;
        cout << "\nMax\t\t" << x1[o].grade;
        cout << "\nEnter end to return to menu : ";
        string t1;
        while (cin >> t1) {
            if (t1 == "end") {
                system("cls");
                main();
            }
        }
    }
    if (ch == 5) {
        cout << "\t\t\tInsert the new score\n\nEnter code of course : ";
        string r, t, y;
        cin >> r;
        cout << "Enter student ID : ";
        cin >> y;
        cout << "Enter grade of student : ";
        cin >> t;
        f5.open("d:\\pfiles\\" + r + ".txt", ios::app);
        f5 << t << ' ' << y << '\n';
        cout << "Grade successfully added\n";
        cout << "Enter end to return to menu : ";
        string z1;
        while (cin >> z1) {
            if (z1 == "end") {
                system("cls");
                main();
            }
        }

    }
    if (ch == 6) {
        ID d[100];
        cout << "\t\tInsert a list of grades for a course\n\nEnter code of course : ";
        string r;
        cin >> r;
        f5.open("d:\\pfiles\\" + r + ".txt", ios::app);
        cout << "Enter number of students : ";
        int n1;
        cin >> n1;
        for (i = 0; i < n1; i++) {
            cout << "Enter Grade of student " << i + 1 << " : ";
            cin >> d[i].grade;
            f5 << d[i].grade << ' ';
            cout << "Enter ID of student " << i + 1 << " : ";
            cin >> d[i].id;
            f5 << d[i].id << '\n';
        }
        cout << "Enter end to return to menu : ";
        string t1;
        while (cin >> t1) {
            system("cls");
            main();
        }
    }
    if (ch == 10) {
        ID d[100], temp;
        cout << "\t\tView the status of lesson\n\nEnter code of course : ";
        string r, t, w, e;
        cin >> r;
        cout << "Enter name of course : ";
        cin >> t;
        f5.open("d:\\pfiles\\" + r + ".txt", ios::in);
        cout << "Enter number of ids : ";
        int u;
        cin >> u;
        cout << "\n>>>> Course Name :  " << t << "\n";
        cout << ">>>> Course Code :  " << r;
        cout << "\n\nStudent ID\t" << "Grade\n";
        cout << "----------------------------\n";
        while (!f5.eof()) {
            for (i = 0; i < u; i++)
                f5 >> d[i].grade >> d[i].id;
            for (int i = u - 1; i >= 1; i--) {
                for (int j = 0; j < i; j++) {
                    if (d[j].id > d[j + 1].id) {
                        temp = d[j];
                        d[j] = d[j + 1];
                        d[j + 1] = temp;
                    }
                }
            }
        }
        for (i = 0; i < u; i++)
            cout << d[i].id << "\t\t" << d[i].grade << "\n";
        float sum = 0, mean, sum1 = 0, var;
        for (i = 0; i < u; i++)
            sum += d[i].grade;
        mean = sum / u;
        cout << "Mean\t\t" << mean << "\n";
        for (i = 0; i < u; i++)
            sum1 += pow((d[i].grade - mean), 2);
        var = sum1 / u;
        cout << "Variance\t" << var;
        cout << "\nEnter end to return to menu : ";
        string z1;
        while (cin >> z1) {
            if (z1 == "end") {
                system("cls");
                main();
            }
        }
    }
    if (ch == 11) {
        cout << "\t\tView the status of lesson\n\nEnter code of course : ";
        string r, z, t;
        cin >> r;
        cout << "Enter name of course : ";
        cin >> t;
        Grade g[100], temp;
        cout << "Enter number of grades : ";
        int k;
        cin >> k;
        fstream f5;
        f5.open("d:\\pfiles\\" + r + ".txt", ios::in);
        cout << "\n>>>> Course Name :  " << t << "\n";
        cout << ">>>> Course Code :  " << r;
        cout << "\n\nStudent ID\t" << "Grade\n";
        cout << "________________________\n";
        while (!f5.eof()) {
            for (i = 0; i < k; i++)
                f5 >> g[i].grade >> g[i].id;
            for (int i = k - 1; i >= 1; i--) {
                for (int j = 0; j < i; j++) {
                    if (g[j].grade < g[j + 1].grade) {
                        temp = g[j];
                        g[j] = g[j + 1];
                        g[j + 1] = temp;
                    }
                }
            }
        }
        for (i = 0; i < k; i++)
            cout << g[i].id << "\t\t" << g[i].grade << "\n";
        float sum = 0, mean, sum1 = 0, var;
        for (i = 0; i < k; i++)
            sum += g[i].grade;
        mean = sum / k;
        cout << "Mean\t\t" << mean << "\n";
        for (i = 0; i < k; i++)
            sum1 += pow((g[i].grade - mean), 2);
        var = sum1 / k;
        cout << "Variance\t" << var;
        cout << "\nEnter end to return to menu : ";
        string z1;
        while (cin >> z1) {
            if (z1 == "end") {
                system("cls");
                main();
            }
        }

    }
    if (ch == 13) {
        cout << "\n\tYour Program is End\n\tEnter number 1 to go out from project : ";
        while (cin >> z) {
            if (z == "1")
                exit(0);
        }
    }
    if (ch == 2) {
        fstream e1, e2, e3, e4;
        cout << "\t\t\tDelete a student\n\nEnter student ID : ";
        string z;
        cin >> z;
        int nl = 0, nl2 = 0;
        string name, family, faname, id, naid, eyear, byear;
        while (f3 >> name >> family >> faname >> id >> naid >> eyear >> byear) {
            nl++;
            if (z == id)
                break;
        }
        f3.close();
        e1.open("d:\\pfiles\\StudentInfo.txt", ios::in);
        e2.open("d:\\pfiles\\StudentInfocopy.txt", ios::out);
        while (e1 >> name >> family >> faname >> id >> naid >> eyear >> byear) {
            nl2++;
            if (nl != nl2)
                e2 << name << ' ' << family << ' ' << faname << ' ' << id << ' ' << naid << ' ' << eyear << ' ' << byear
                   << '\n';
        }
        e1.close();
        e2.close();
        e3.open("d:\\pfiles\\StudentInfocopy.txt", ios::in);
        e4.open("d:\\pfiles\\StudentInfo.txt", ios::out);
        while (e3 >> name >> family >> faname >> id >> naid >> eyear >> byear)
            e4 << name << ' ' << family << ' ' << faname << ' ' << id << ' ' << naid << ' ' << eyear << ' ' << byear
               << '\n';
        e3.close();
        e4.close();
        cout << "student informations successfully deleted";
        cout << "\nEnter end to return to menu : ";
        string z1;
        while (cin >> z1) {
            if (z1 == "end") {
                system("cls");
                main();
            }
        }

    }
    if (ch == 3) {
        fstream e1, e2, e3, e4;
        cout << "\t\tUpdate the student information\n\nEnter student ID : ";
        string z;
        cin >> z;
        int nl = 0, nl2 = 0;
        string name, family, faname, id, naid, eyear, byear;
        while (f3 >> name >> family >> faname >> id >> naid >> eyear >> byear) {
            nl++;
            if (z == id)
                break;
        }
        f3.close();
        e1.open("d:\\pfiles\\StudentInfo.txt", ios::in);
        e2.open("d:\\pfiles\\StudentInfocopy.txt", ios::out);
        while (e1 >> name >> family >> faname >> id >> naid >> eyear >> byear) {
            nl2++;
            if (nl != nl2)
                e2 << name << ' ' << family << ' ' << faname << ' ' << id << ' ' << naid << ' ' << eyear << ' ' << byear
                   << '\n';
            else if (nl == nl2) {
                const int o = 6;
                string h[o];
                int s = 0;
                cout << "Enter student new Name : \t";
                cin >> h[s];
                e2 << h[s] << ' ';
                cout << "Enter student new Family : \t";
                cin >> h[s + 1];
                e2 << h[s + 1] << ' ';
                cout << "Enter student new FatherName : \t";
                cin >> h[s + 2];
                e2 << h[s + 2] << ' ';
                e2 << id << ' ';
                cout << "Enter student new NationalID : \t";
                cin >> h[s + 3];
                e2 << h[s + 3] << ' ';
                cout << "Enter student new EntranceYear: ";
                cin >> h[s + 4];
                e2 << h[s + 4] << ' ';
                cout << "Enter student new BirthYear : \t";
                cin >> h[s + 5];
                e2 << h[s + 5] << "\n";
            }
        }
        e1.close();
        e2.close();
        e3.open("d:\\pfiles\\StudentInfocopy.txt", ios::in);
        e4.open("d:\\pfiles\\StudentInfo.txt", ios::out);
        while (e3 >> name >> family >> faname >> id >> naid >> eyear >> byear)
            e4 << name << ' ' << family << ' ' << faname << ' ' << id << ' ' << naid << ' ' << eyear << ' ' << byear
               << '\n';
        e3.close();
        e4.close();
        cout << "student information successfully Updated";
        cout << "\nEnter end to return to menu : ";
        string z1;
        while (cin >> z1) {
            if (z1 == "end") {
                system("cls");
                main();
            }
        }

    }
    if (ch == 8) {
        fstream e1, e2, e3, e4;
        cout << "\t\tRemove score for a list\n\nEnter code of course : ";
        string r, z, u, t;
        cin >> r;
        cout << "Enter number of students you want to delete his grades : ";
        int nn;
        cin >> nn;
        for (i = 0; i < nn; i++) {
            cout << "\nEnter student " << i + 1 << " ID : ";
            cin >> z;
            int nl = 0, nl2 = 0;
            f5.open("d:\\pfiles\\" + r + ".txt", ios::in);
            while (f5 >> t >> y) {
                nl++;
                if (z == y) {
                    cout << "student " << i + 1 << " Grade is : " << t;
                    break;
                }
            }
            f5.close();
            cout << "\nAre you sure to delete geade (yes or no) : ";
            string h1;
            cin >> h1;
            if (h1 == "yes") {
                e1.open("d:\\pfiles\\" + r + ".txt", ios::in);
                e2.open("d:\\pfiles\\rcopy.txt", ios::out);
                while (e1 >> t >> y) {
                    nl2++;
                    if (nl != nl2)
                        e2 << t << " " << y << "\n";
                }
                e1.close();
                e2.close();
                e3.open("d:\\pfiles\\rcopy.txt", ios::in);
                e4.open("d:\\pfiles\\" + r + ".txt", ios::out);
                while (e3 >> t >> y)
                    e4 << t << " " << y << "\n";
                e3.close();
                e4.close();
                cout << "student " << i + 1 << " grade successfully deleted\n\n";
            } else if (h1 == "no")
                cout << "grade not deleted\n";
        }
        cout << "Enter end to return to menu : ";
        string z1;
        while (cin >> z1) {
            if (z1 == "end") {
                system("cls");
                main();
            }
        }
    }
    if (ch == 7) {
        fstream e1, e2, e3, e4;
        cout << "\t\t\tRemove Score\n\nEnter code of course : ";
        string r, z, u, t;
        cin >> r;
        cout << "Enter student ID : ";
        cin >> z;
        int nl = 0, nl2 = 0;
        f5.open("d:\\pfiles\\" + r + ".txt", ios::in);
        while (f5 >> t >> y) {
            nl++;
            if (z == y) {
                cout << "Grade is : " << t;
                break;
            }
        }
        f5.close();
        cout << "\nAre you sure to delete geade (yes or no) : ";
        string h1;
        while (cin >> h1) {
            if (h1 == "yes") {
                e1.open("d:\\pfiles\\" + r + ".txt", ios::in);
                e2.open("d:\\pfiles\\rcopy.txt", ios::out);
                while (e1 >> t >> y) {
                    nl2++;
                    if (nl != nl2)
                        e2 << t << " " << y << "\n";
                }
                e1.close();
                e2.close();
                e3.open("d:\\pfiles\\rcopy.txt", ios::in);
                e4.open("d:\\pfiles\\" + r + ".txt", ios::out);
                while (e3 >> t >> y)
                    e4 << t << " " << y << "\n";
                e3.close();
                e4.close();
                cout << "student grade successfully deleted\n";
            } else if (h1 == "no")
                cout << "grade not deleted\n";
            cout << "Enter end to return to menu : ";
            string z1;
            while (cin >> z1) {
                if (z1 == "end") {
                    system("cls");
                    main();
                }
            }
        }
    }
    if (ch == 9) {
        fstream e1, e2, e3, e4;
        cout << "\t\t\tScore Update\n\nEnter code of course : ";
        string r, z, u, t;
        cin >> r;
        cout << "Enter student ID : ";
        cin >> z;
        int nl = 0, nl2 = 0;
        f5.open("d:\\pfiles\\" + r + ".txt", ios::in);
        while (f5 >> t >> y) {
            nl++;
            if (z == y) {
                cout << "Grade is : " << t << "\n";
                break;
            }
        }
        f5.close();
        e1.open("d:\\pfiles\\" + r + ".txt", ios::in);
        e2.open("d:\\pfiles\\rcopy.txt", ios::out);
        while (e1 >> t >> y) {
            nl2++;
            if (nl != nl2)
                e2 << t << " " << y << "\n";
            else if (nl == nl2) {
                cout << "Enter new grade : ";
                cin >> u;
                e2 << u << ' ' << y << '\n';
            }
        }
        e1.close();
        e2.close();
        e3.open("d:\\pfiles\\rcopy.txt", ios::in);
        e4.open("d:\\pfiles\\" + r + ".txt", ios::out);
        while (e3 >> t >> y)
            e4 << t << " " << y << "\n";
        e3.close();
        e4.close();
        cout << "\nstudent grade successfully updated\n";
        cout << "Enter end to return to menu : ";
        string z1;
        while (cin >> z1) {
            if (z1 == "end") {
                system("cls");
                main();
            }
        }
    }
    f2.close();
    f3.close();
    f5.close();
    f6.close();
    for (i = 0; i < e; i++) {
        f[i].close();
        f1[i].close();
    }
    cin.get();
    cin.ignore();
}