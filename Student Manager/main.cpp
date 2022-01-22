#include"stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include <conio.h>
#include<cstring>
#include <math.h>
#include <cmath>

using namespace std;
struct student {
    string name;//نام
    string fname;//فامیلی
    string stno;//شماره دانشجویی
    string ncode;//کد ملی
    string by;//سال تولد
    string ey;//سال ورود
};
struct lessons {
    string stno;//شماره دانشجویی
    string score;//نمره
};

void menu();

int main() {
    student m[100];
    lessons l[100];
    string name;//نام
    string fname;//فامیلی
    string stno;//شماره دانشجویی
    string ncode;//کد ملی
    string by;//سال تولد
    string ey;//سال ورود
    int n, s = 0, op, t = 0, df = 0, jk = 0, lk = 0, ff, dc, pp = 0, vn = 0, kza = 0, za = 0, mo = 0, al = 0;
    float sum = 0, avg, fg[100], var = 0, trr = 0;
    string ch, gg, mm, a, b, mn, pv, cc, leco;
    char c = '1', y, yy, uut[20];
    fstream le, f, st, lest, lec;
    f.open("d:\\files\\check.txt", ios::in);
    while (!f.eof()) {
        f.get(c);
        s++;
        f.close();
    }
    if (s == 1)   //بررسی میکند که آیا اولین باری است که برنامه اجرا میشود یا نه
    {
        lec.open("d:\\files\\lec.txt", ios::out);
        cout << " Please enter numbers of lessons : ";
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cout << " Please enter name of lesson " << i << " : ";
            cin >> b;
            cout << " Please enter code of lesson " << i << " : ";
            cin >> a;
            le.open("d:\\files\\" + a + ".txt", ios::out);
            for (int j = 0; j < b.length(); j++)
                le.put(b[j]);
            for (int j = 0; j < a.length(); j++)
                lec.put(a[j]);
            lec.put('\n');
            if (i == n) {
                f.open("d:\\files\\check.txt", ios::out);
                f.put(c);
                f.close();
            }
            le.close();
        }
        lec.close();
    }
    st.open("d:\\files\\student-info.txt", ios::in);
    getline(st, ch);
    int ii = 0;
    while (!st.eof()) {
        getline(st, ch);
        if (ch != "") {
            int i = 0;
            while (ch[i] != ',' && ch[i] != '\0') {
                m[ii].stno += ch[i];
                i++;
            }
            i++;
            while (ch[i] != ',' && ch[i] != '\0') {
                m[ii].name += ch[i];
                i++;
            }
            i++;
            while (ch[i] != ',' && ch[i] != '\0') {
                m[ii].fname += ch[i];
                i++;
            }
            i++;
            while (ch[i] != ',' && ch[i] != '\0') {
                m[ii].ncode += ch[i];
                i++;
            }
            i++;
            while (ch[i] != ',' && ch[i] != '\0') {
                m[ii].by += ch[i];
                i++;
            }
            i++;
            while (ch[i] != ',' && ch[i] != '\0') {
                m[ii].ey += ch[i];
                i++;
            }
            ii++;
        }
    }
    st.close();
    system("cls");
    menu();
    cout << " Please enter number of action you want : " << endl << endl;
    cin >> op;
    system("cls");
    if (op == 1) {
        cout << "              Add e new studant" << endl << endl << endl << endl;
        cout << "  Please enter students name : ";
        cin >> name;
        cout << "  Please enter students family name : ";
        cin >> fname;
        cout << "  Please enter students student number : ";
        cin >> stno;
        cout << "  Please enter students national code : ";
        cin >> ncode;
        cout << "  Please enter students birth year : ";
        cin >> by;
        cout << "  Please enter students enter year : ";
        cin >> ey;
        st.open("d:\\files\\student-info.txt", ios::app);
        st.put('\n');
        for (int i = 0; i < stno.length(); i++)
            st.put(stno[i]);
        st.put(',');
        for (int i = 0; i < name.length(); i++)
            st.put(name[i]);
        st.put(',');
        for (int i = 0; i < fname.length(); i++)
            st.put(fname[i]);
        st.put(',');
        for (int i = 0; i < ncode.length(); i++)
            st.put(ncode[i]);
        st.put(',');
        for (int i = 0; i < by.length(); i++)
            st.put(by[i]);
        st.put(',');
        for (int i = 0; i < ey.length(); i++)
            st.put(ey[i]);
        st.put(',');
        st.close();
        system("cls");
        cout << "  New student added successfully" << endl << endl << endl;
        cout << "  If you want to continue press Y , if not press N : ";
        cin >> y;
        if (y == 'y') {
            system("cls");
            main();
        }
    } else if (op == 2) {
        cout << " Please enter student id for remove student : ";
        cin >> gg;
        for (int i = 0; i < ii; i++)
            if (m[i].stno == gg)
                jk = i;
        for (int i = jk; i < ii; i++)
            m[i] = m[i + 1];
        st.open("d:\\files\\student-info.txt", ios::out);
        for (int i = 0; i < ii - 1; i++) {
            char cv[30];
            for (int j = 0; j < m[i].stno.length(); j++)
                cv[j] = m[i].stno[j];
            st.put('\n');
            for (int k = 0; k < m[i].stno.length(); k++)
                st.put(cv[k]);
            for (int j = 0; j < m[i].name.length(); j++)
                cv[j] = m[i].name[j];
            st.put(',');
            for (int k = 0; k < m[i].name.length(); k++)
                st.put(cv[k]);
            for (int j = 0; j < m[i].fname.length(); j++)
                cv[j] = m[i].fname[j];
            st.put(',');
            for (int k = 0; k < m[i].fname.length(); k++)
                st.put(cv[k]);
            for (int j = 0; j < m[i].ncode.length(); j++)
                cv[j] = m[i].ncode[j];
            st.put(',');
            for (int k = 0; k < m[i].ncode.length(); k++)
                st.put(cv[k]);
            for (int j = 0; j < m[i].by.length(); j++)
                cv[j] = m[i].by[j];
            st.put(',');
            for (int k = 0; k < m[i].by.length(); k++)
                st.put(cv[k]);
            for (int j = 0; j < m[i].ey.length(); j++)
                cv[j] = m[i].ey[j];
            st.put(',');
            for (int k = 0; k < m[i].ey.length(); k++)
                st.put(cv[k]);
            st.put(',');
        }
        st.close();
        system("cls");
        cout << " This student removed successfully" << endl << endl << endl;
        cout << "  If you want to continue press Y , if not press N : ";
        cin >> y;
        if (y == 'y') {
            system("cls");
            main();
        }
    } else if (op == 3) {
        system("cls");
        cout << "Go" << endl;
        cout << " Please enter student id for update student : " << endl;
        cin >> gg;
        for (int i = 0; i < ii; i++)
            if (m[i].stno == gg) {
                cout << "NAME : ";
                cout << m[i].name << endl;
                cout << "FAMILY NAME : ";
                cout << m[i].fname << endl;
                cout << "NATIONAL CODE : ";
                cout << m[i].ncode << endl;
                cout << "BIRTH YEAR : ";
                cout << m[i].by << endl;
                cout << "ENTRANCE  YEAR : ";
                cout << m[i].ey << endl << endl;
                cout << "     Please enter new informations" << endl << endl;
                cout << "NAME : ";
                cin >> m[i].name;
                cout << "FAMILY NAME : ";
                cin >> m[i].fname;
                cout << "NATIONAL CODE : ";
                cin >> m[i].ncode;
                cout << "BIRTH YEAR : ";
                cin >> m[i].by;
                cout << "ENTRANCE  YEAR : ";
                cin >> m[i].ey;
                st.open("d:\\files\\student-info.txt", ios::out);
                for (int i = 0; i < ii; i++) {
                    char cv[30];
                    for (int j = 0; j < m[i].stno.length(); j++)
                        cv[j] = m[i].stno[j];
                    st.put('\n');
                    for (int k = 0; k < m[i].stno.length(); k++)
                        st.put(cv[k]);
                    for (int j = 0; j < m[i].name.length(); j++)
                        cv[j] = m[i].name[j];
                    st.put(',');
                    for (int k = 0; k < m[i].name.length(); k++)
                        st.put(cv[k]);
                    for (int j = 0; j < m[i].fname.length(); j++)
                        cv[j] = m[i].fname[j];
                    st.put(',');
                    for (int k = 0; k < m[i].fname.length(); k++)
                        st.put(cv[k]);
                    for (int j = 0; j < m[i].ncode.length(); j++)
                        cv[j] = m[i].ncode[j];
                    st.put(',');
                    for (int k = 0; k < m[i].ncode.length(); k++)
                        st.put(cv[k]);
                    for (int j = 0; j < m[i].by.length(); j++)
                        cv[j] = m[i].by[j];
                    st.put(',');
                    for (int k = 0; k < m[i].by.length(); k++)
                        st.put(cv[k]);
                    for (int j = 0; j < m[i].ey.length(); j++)
                        cv[j] = m[i].ey[j];
                    st.put(',');
                    for (int k = 0; k < m[i].ey.length(); k++)
                        st.put(cv[k]);
                    st.put(',');
                }
                st.close();
                system("cls");
                cout << " This student removed successfully" << endl << endl << endl;
                cout << "  If you want to continue press Y , if not press N : ";
                cin >> y;
                if (y == 'y') {
                    system("cls");
                    main();
                }
            }
    } else if (op == 4) {
        int count_1 = 0;
        float avg_1 = 0, sum_1 = 0, max_1 = 0, min_1 = 20, var_1 = 0, nomre = 0, nomreha[50], sum_2 = 0;
        cout << "  Please enter student ID for print information : ";
        cin >> gg;
        for (int i = 0; i < ii; i++)
            if (m[i].stno == gg) {
                cout << endl << endl << endl << "student ID : ";
                cout << m[i].stno << endl;
                cout << "NAME : ";
                cout << m[i].name << endl;
                cout << "FAMILY NAME : ";
                cout << m[i].fname << endl;
                cout << "NATIONAL CODE : ";
                cout << m[i].ncode << endl;
                cout << "BIRTH YEAR : ";
                cout << m[i].by << endl;
                cout << "ENTRANCE  YEAR : ";
                cout << m[i].ey << endl << endl << endl;
                st.close();
                cout << "Course name\tCourse Id\tGrade\n";
                lec.open("d:\\files\\lec.txt", ios::in);
                while (!lec.eof()) {
                    getline(lec, a);
                    le.open("d:\\files\\" + a + ".txt", ios::in);
                    getline(le, pv);
                    cc = pv;
                    while (!le.eof()) {
                        dc = 0;
                        getline(le, pv);
                        if (pv != "") {
                            while (pv[dc] != ',') {
                                mn += pv[dc];
                                dc++;
                            }
                            if (mn == gg) {
                                dc++;
                                mn = "";
                                while (pv[dc] != ',') {
                                    mn += pv[dc];
                                    dc++;
                                }
                                cout << cc << "\t\t" << a << "\t\t" << mn << endl;
                                nomre = (float) atof(mn.c_str());
                                nomreha[count_1] = nomre;
                                sum_1 += nomre;
                                count_1++;
                                if (nomre > max_1)
                                    max_1 = nomre;
                                else if (nomre < min_1)
                                    min_1 = nomre;
                            }
                            mn = "";
                        }
                    }
                    le.close();
                }
                lec.close();
                avg_1 = sum_1 / count_1;
                for (int j = 0; j < count_1; ++j) {
                    sum_2 += pow(nomreha[i] - avg_1, 2);
                }
                var_1 = sum_2 / count_1;
                cout << "\nStatistical Information" << endl;
                cout << "Max score : " << max_1 << endl;
                cout << "Min score : " << min_1 << endl;
                cout << "Average : " << avg_1 << endl;
                cout << "Variance : " << var_1 << endl << endl;
                cout << "  If you want to continue press Y , if not press N : ";
                cin >> y;
                if (y == 'y') {
                    system("cls");
                    main();
                }
            }
    } else if (op == 5) {
        system("cls");
        cout << endl;
        cout << " Please enter code of lesson : ";
        cin >> a;
        le.open("d:\\files\\" + a + ".txt", ios::app);
        cout << " Please enter student ID : ";
        cin >> gg;
        for (int i = 0; i < ii; i++)
            if (m[i].stno == gg) {
                le.put('\n');
                for (int j = 0; j < m[i].stno.length(); j++)
                    le.put(gg[j]);
                le.put(',');
                string ll;
                char hh[5];
                cout << " Please enter score of student for this lesson : ";
                cin >> ll;
                for (int j = 0; j < ll.length(); j++)
                    hh[j] = ll[j];
                for (int j = 0; j < ll.length(); j++)
                    le.put(hh[j]);
                le.put(',');
            }
        le.close();
        cout << "  If you want to continue press Y , if not press N : ";
        cin >> y;
        if (y == 'y') {
            system("cls");
            main();
        }
    } else if (op == 6) {
        cout << " Please enter code of lesson : ";
        cin >> a;
        cout << " Please enter numbers of students : ";
        cin >> ff;
        for (int bb = 1; bb <= ff; bb++) {
            le.open("d:\\files\\" + a + ".txt", ios::app);
            cout << " Please enter student " << bb << " ID : ";
            cin >> gg;
            for (int i = 0; i < ii; i++)
                if (m[i].stno == gg) {
                    le.put('\n');
                    for (int j = 0; j < m[i].stno.length(); j++)
                        le.put(gg[j]);
                    le.put(',');
                    string ll;
                    char hh[5];
                    cout << " Please enter score of student for this lesson : ";
                    cin >> ll;
                    for (int j = 0; j < ll.length(); j++)
                        hh[j] = ll[j];
                    for (int j = 0; j < ll.length(); j++)
                        le.put(hh[j]);
                    le.put(',');
                }
            le.close();
        }
        cout << "  If you want to continue press Y , if not press N : ";
        cin >> y;
        if (y == 'y') {
            system("cls");
            main();
        }
    } else if (op == 7) {
        cout << " Please enter lesson code to delete score : ";
        cin >> leco;
        cout << " Please enter student ID : ";
        cin >> gg;
        le.open("d:\\files\\" + leco + ".txt", ios::in);
        int fu = 0;
        getline(le, ch);
        for (int i = 0; i < ch.length(); i++) {
            uut[i] = ch[i];
            vn++;
        }
        while (!le.eof()) {
            getline(le, ch);
            if (ch != "") {
                int uf = 0;
                while (ch[uf] != ',' && ch[uf] != '\0') {
                    l[fu].stno += ch[uf];
                    uf++;
                }
                uf++;
                while (ch[uf] != ',' && ch[uf] != '\0') {
                    l[fu].score += ch[uf];
                    uf++;
                }
                fu++;
            }
        }
        le.close();
        for (int i = 0; i < fu; i++) {
            if (gg == l[i].stno) {
                int sa = i;
                cout << " Score of this lesson for this student is : " << l[i].score << endl << endl;
                cout << " Are you sure for delete this score ? ";
                cin >> yy;
                if (yy == 'y') {
                    for (int u = sa; u < fu; u++)
                        l[u] = l[u + 1];
                    le.open("d:\\files\\" + leco + ".txt", ios::out);
                    for (int j = 0; j < vn; j++)
                        le.put(uut[j]);
                    le.put('\n');
                    for (int v = 0; v < fu - 1; v++) {
                        char cv[30];
                        for (int j = 0; j < l[v].stno.length(); j++)
                            if (l[v].stno[j] != '\0')
                                cv[j] = l[v].stno[j];
                        for (int k = 0; k < l[v].stno.length(); k++)
                            if (cv[k] != '\0')
                                le.put(cv[k]);
                        le.put(',');
                        for (int j = 0; j < l[v].score.length(); j++)
                            if (l[v].score[j] != '\0')
                                cv[j] = l[v].score[j];
                        for (int k = 0; k < l[v].score.length(); k++)
                            if (cv[k] != '\0')
                                le.put(cv[k]);
                        le.put(',');
                        le.put('\n');
                    }
                }
                pp++;
            }
        }
        le.close();
        if (pp == 0)
            cout << "       There is not score in this lesson for this student";
        cout << "  If you want to continue press Y , if not press N : ";
        cin >> y;
        if (y == 'y') {
            system("cls");
            main();
        }

    } else if (op == 8) {
        cout << " Please enter lesson code to delete score : ";
        cin >> leco;
        le.open("d:\\files\\" + leco + ".txt", ios::in);
        int fu = 0;
        getline(le, ch);
        for (int i = 0; i < ch.length(); i++) {
            uut[i] = ch[i];
            vn++;
        }
        while (!le.eof()) {
            getline(le, ch);
            if (ch != "") {
                int uf = 0;
                while (ch[uf] != ',' && ch[uf] != '\0') {
                    l[fu].stno += ch[uf];
                    uf++;
                }
                uf++;
                while (ch[uf] != ',' && ch[uf] != '\0') {
                    l[fu].score += ch[uf];
                    uf++;
                }
                fu++;
            }
        }
        le.close();
        int ty;
        cout << " Please enter numbers of students to delete : ";
        cin >> ty;
        for (int gh = 1; gh <= ty; gh++) {
            pp = 0;
            cout << " Please enter student " << gh << " ID : ";
            cin >> gg;
            for (int i = 0; i < fu; i++) {
                if (gg == l[i].stno) {
                    int sa = i;
                    cout << " Score of this lesson for this student is : " << l[i].score << endl << endl;
                    cout << " Are you sure for delete this score ? ";
                    cin >> yy;
                    if (yy == 'y') {
                        for (int u = sa; u < fu; u++)
                            l[u] = l[u + 1];
                        le.open("d:\\files\\" + leco + ".txt", ios::out);
                        for (int j = 0; j < vn; j++)
                            le.put(uut[j]);
                        le.put('\n');
                        for (int v = 0; v < fu - 1; v++) {
                            char cv[30];
                            for (int j = 0; j < l[v].stno.length(); j++)
                                if (l[v].stno[j] != '\0')
                                    cv[j] = l[v].stno[j];
                            for (int k = 0; k < l[v].stno.length(); k++)
                                if (cv[k] != '\0')
                                    le.put(cv[k]);
                            le.put(',');
                            for (int j = 0; j < l[v].score.length(); j++)
                                if (l[v].score[j] != '\0')
                                    cv[j] = l[v].score[j];
                            for (int k = 0; k < l[v].score.length(); k++)
                                if (cv[k] != '\0')
                                    le.put(cv[k]);
                            le.put(',');
                            le.put('\n');
                        }
                    }
                    pp++;
                }
            }
            le.close();
            if (pp == 0)
                cout << "       There is not score in this lesson for this student";
        }
        cout << "  If you want to continue press Y , if not press N : ";
        cin >> y;
        if (y == 'y') {
            system("cls");
            main();
        }
    } else if (op == 9) {
        cout << "  Please enter lesson code for update : ";
        cin >> leco;
        cout << " Please enter student ID : ";
        cin >> gg;
        le.open("d:\\files\\" + leco + ".txt", ios::in);
        int fu = 0;
        getline(le, ch);
        for (int i = 0; i < ch.length(); i++) {
            uut[i] = ch[i];
            vn++;
        }
        while (!le.eof()) {
            getline(le, ch);
            if (ch != "") {
                int uf = 0;
                while (ch[uf] != ',' && ch[uf] != '\0') {
                    l[fu].stno += ch[uf];
                    uf++;
                }
                uf++;
                while (ch[uf] != ',' && ch[uf] != '\0') {
                    l[fu].score += ch[uf];
                    uf++;
                }
                fu++;
            }
        }
        le.close();
        for (int i = 0; i < fu; i++) {
            if (gg == l[i].stno) {
                int sa = i;
                cout << " Score of this lesson for this student is : " << l[i].score << " now " << endl << endl;
                cout << " Please enter new score : ";
                cin >> l[i].score;
                le.open("d:\\files\\" + leco + ".txt", ios::out);
                for (int j = 0; j < vn; j++)
                    le.put(uut[j]);
                le.put('\n');
                for (int v = 0; v < fu; v++) {
                    char cv[30];
                    for (int j = 0; j < l[v].stno.length(); j++)
                        if (l[v].stno[j] != '\0')
                            cv[j] = l[v].stno[j];
                    for (int k = 0; k < l[v].stno.length(); k++)
                        if (cv[k] != '\0')
                            le.put(cv[k]);
                    le.put(',');
                    for (int j = 0; j < l[v].score.length(); j++)
                        if (l[v].score[j] != '\0')
                            cv[j] = l[v].score[j];
                    for (int k = 0; k < l[v].score.length(); k++)
                        if (cv[k] != '\0')
                            le.put(cv[k]);
                    le.put(',');
                    le.put('\n');
                }
                le.close();
            }
        }
        cout << "\n\n";
        cout << "  If you want to continue press Y , if not press N : ";
        cin >> y;
        if (y == 'y') {
            system("cls");
            main();
        }
    } else if (op == 10) {
        cout << "  Please enter lesson code : ";
        cin >> leco;
        le.open("d:\\files\\" + leco + ".txt", ios::in);
        int fu = 0;
        getline(le, ch);
        string kjj;
        kjj = ch;
        int uo = 0;
        while (!le.eof()) {
            getline(le, ch);
            if (ch != "") {
                int uf = 0;
                while (ch[uf] != ',' && ch[uf] != '\0') {
                    l[fu].stno += ch[uf];
                    uf++;
                }
                uf++;
                while (ch[uf] != ',' && ch[uf] != '\0') {
                    l[fu].score += ch[uf];
                    uf++;
                }
                trr = (float) atof(l[fu].score.c_str());
                sum = sum + trr;
                fg[uo] = (float) atof(l[fu].score.c_str());
                if (trr >= 0 && trr < 5)
                    kza++;
                if (trr >= 5 && trr < 10)
                    za++;
                if (trr >= 10 && trr < 15)
                    mo++;
                if (trr >= 15 && trr <= 20)
                    al++;
                fu++;
                uo++;
            }
        }
        avg = sum / fu;
        le.close();
        string maxi, maxim;
        for (int i = fu - 1; i >= 0; i--)
            for (int j = 0; j < i; j++)
                if (l[j].stno > l[j + 1].stno) {
                    maxi = l[j].stno;
                    maxim = l[j].score;
                    l[j].stno = l[j + 1].stno;
                    l[j].score = l[j + 1].score;
                    l[j + 1].stno = maxi;
                    l[j + 1].score = maxim;
                }
        cout << " Lesson name : " << kjj << endl;
        cout << " Lesson code : " << leco;
        cout << endl << endl << "Student ID" << "\t" << "Grade" << endl << endl;
        for (int i = 0; i < fu; i++)
            cout << l[i].stno << "\t" << l[i].score << endl;
        cout << endl << endl << endl << "Average" << "\t" << "\t" << avg;
        int rt = 0;
        for (int yu = 0; fg[yu] != '\0'; yu++) {
            var = var + ((avg - fg[yu]) * (avg - fg[yu]));
            rt++;
        }
        float vari;
        vari = var / rt;
        cout << endl << "Variance" << "\t" << vari << endl << endl << endl;
        cout << "\t" << (char) 94;
        cout << "\t" << "|" << endl << "\t" << "|" << endl;
        cout << "   [0,5)|";
        for (int pk = 1; pk <= kza; pk++)
            cout << "_";
        cout << " " << kza;
        cout << endl << "\t" << "|" << endl << "\t" << "|" << endl;
        cout << "  [5,10)|";
        for (int pk = 1; pk <= za; pk++)
            cout << "_";
        cout << " " << za;
        cout << endl << "\t" << "|" << endl << "\t" << "|" << endl;
        cout << " [10,15)|";
        for (int pk = 1; pk <= mo; pk++)
            cout << "_";
        cout << " " << mo;
        cout << endl << "\t" << "|" << endl << "\t" << "|" << endl;
        cout << " [15,20]|";
        for (int pk = 1; pk <= al; pk++)
            cout << "_";
        cout << " " << al;
        cout << endl << "\t" << "|" << endl;
        cout << "\t" << " ------------------------" << (char) 125;
        cout << "\n\n";
        cout << "  If you want to continue press Y , if not press N : ";
        cin >> y;
        if (y == 'y') {
            system("cls");
            main();
        }
    } else if (op == 11) {
        cout << "  Please enter lesson code : ";
        cin >> leco;
        le.open("d:\\files\\" + leco + ".txt", ios::in);
        int fu = 0;
        getline(le, ch);
        string kjj;
        kjj = ch;
        int uo = 0;
        while (!le.eof()) {
            getline(le, ch);
            if (ch != "") {
                int uf = 0;
                while (ch[uf] != ',' && ch[uf] != '\0') {
                    l[fu].stno += ch[uf];
                    uf++;
                }
                uf++;
                while (ch[uf] != ',' && ch[uf] != '\0') {
                    l[fu].score += ch[uf];
                    uf++;
                }
                trr = (float) atof(l[fu].score.c_str());
                sum = sum + trr;
                fg[uo] = (float) atof(l[fu].score.c_str());
                if (trr >= 0 && trr < 5)
                    kza++;
                if (trr >= 5 && trr < 10)
                    za++;
                if (trr >= 10 && trr < 15)
                    mo++;
                if (trr >= 15 && trr <= 20)
                    al++;
                fu++;
                uo++;
            }
        }
        avg = sum / fu;
        le.close();
        string maxi, maxim;
        for (int i = fu - 1; i >= 0; i--)
            for (int j = 0; j < i; j++)
                if (l[j].score > l[j + 1].score) {
                    maxi = l[j].stno;
                    maxim = l[j].score;
                    l[j].stno = l[j + 1].stno;
                    l[j].score = l[j + 1].score;
                    l[j + 1].stno = maxi;
                    l[j + 1].score = maxim;
                }
        cout << " Lesson name : " << kjj << endl;
        cout << " Lesson code : " << leco;
        cout << endl << endl << "Student ID" << "\t" << "Grade" << endl << endl;
        for (int i = 0; i < fu; i++)
            cout << l[i].stno << "\t" << l[i].score << endl;
        cout << endl << endl << endl << "Average" << "\t" << "\t" << avg;
        int rt = 0;
        for (int yu = 0; fg[yu] != '\0'; yu++) {
            var = var + ((avg - fg[yu]) * (avg - fg[yu]));
            rt++;
        }
        float vari;
        vari = var / rt;
        cout << endl << "Variance" << "\t" << vari << endl << endl << endl;
        cout << "\t" << (char) 94;
        cout << "\t" << "|" << endl << "\t" << "|" << endl;
        cout << "   [0,5)|";
        for (int pk = 1; pk <= kza; pk++)
            cout << "_";
        cout << " " << kza;
        cout << endl << "\t" << "|" << endl << "\t" << "|" << endl;
        cout << "  [5,10)|";
        for (int pk = 1; pk <= za; pk++)
            cout << "_";
        cout << " " << za;
        cout << endl << "\t" << "|" << endl << "\t" << "|" << endl;
        cout << " [10,15)|";
        for (int pk = 1; pk <= mo; pk++)
            cout << "_";
        cout << " " << mo;
        cout << endl << "\t" << "|" << endl << "\t" << "|" << endl;
        cout << " [15,20]|";
        for (int pk = 1; pk <= al; pk++)
            cout << "_";
        cout << " " << al;
        cout << endl << "\t" << "|" << endl;
        cout << "\t" << " ------------------------" << (char) 125;
        cout << "\n\n";
        cout << "  If you want to continue press Y , if not press N : ";
        cin >> y;
        if (y == 'y') {
            system("cls");
            main();
        }
    } else if (op == 0) {
        lec.open("d:\\files\\lec.txt", ios::in);
        cout << " Please enter numbers of lessons : ";
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cout << " Please enter name of lesson " << i << " : ";
            cin >> b;
            cout << " Please enter code of lesson " << i << " : ";
            cin >> a;
            le.open("d:\\files\\" + a + ".txt", ios::out);
            for (int j = 0; j < b.length(); j++)
                le.put(b[j]);
            for (int j = 0; j < a.length(); j++)
                lec.put(a[j]);
            lec.put('\n');
            le.close();
        }
        lec.close();
        cout << "\n\n";
        cout << "  If you want to continue press Y , if not press N : ";
        cin >> y;
        if (y == 'y') {
            system("cls");
            main();
        }
    } else if (op == 13) {
        int out;
        cout << "\n\tYour Program is End\n\tPress Any key to go out from project : ";
        cin >> out;
        exit(0);
    } else {
        int back;
        cout << endl;
        cout << "\n\tWrong number";
        cout << "\n\tPress Any key to back to project : ";
        cin >> back;
        main();
    }
    cin.get();
    cin.ignore();
}

void menu() {
    cout << "            Welcome" << endl;
    cout << " 0 : Add a new lesson" << endl;
    cout << " 1 : Add a new student" << endl;
    cout << " 2 : Remove a student" << endl;
    cout << " 3 : Updating information of a student" << endl;
    cout << " 4 : Information of students" << endl;
    cout << " 5 : Add a new score" << endl;
    cout << " 6 : Add some scores for a lesson" << endl;
    cout << " 7 : Remove a score" << endl;
    cout << " 8 : Remove some scores" << endl;
    cout << " 9 : Updating a score" << endl;
    cout << " 10 : Information of a lesson according to student ID" << endl;
    cout << " 11 : Information of a lesson according to scores" << endl;
    cout << " 12 : EXIT" << endl;
}