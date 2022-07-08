#pragma once
class Lesson
{
    string name;
    int credit;
    int hour;
public:
    Lesson(string name, int credit, int hour)
        :name(name), credit(credit), hour(hour)
    {}

    string getName()const { return name; }
    int getCredit()const { return credit; }
    int getHour()const { return hour; }
    friend ostream& operator<<(ostream& output, const Lesson& s);
};
ostream& operator<<(ostream& output, const Lesson& s)
{
    cout << "Name: " << s.name << endl
        << "Credit: " << s.credit << endl
        << "Hour: " << s.hour << endl;
    return output;
}

class Exam
{
    Lesson lesson;
    double point;
    string date;
public:
    Exam(Lesson lesson, double point, string date)
        :lesson(lesson), point(point), date(date)
    {}

    Lesson getLesson()const { return lesson; }
    double getPoint()const { return point; }
    string getDate()const { return date; }
    friend ostream& operator<<(ostream& output, const Exam& s);
};
ostream& operator<<(ostream& output, const Exam& s)
{
    cout << "Lesson: " << endl;
    cout << s.lesson;
    cout << "Point: " << s.point << endl;
    cout << "Date: " << s.date << endl;
    return output;
}

class Bankcard
{
    string longCode;
    string password;
    double balance;
    short expiredMonth;
    short expiredYear;
public:
    Bankcard(string longCode, string password, double balance, short expiredMonth, short expiredYear)
        :longCode(longCode), password(password), balance(balance), expiredMonth(expiredMonth), expiredYear(expiredYear)
    {}
    string getLongCode()const { return longCode; }
    string getPassword()const { return password; }
    double getBalance()const { return balance; }
    short getExpiredMonth()const { return expiredMonth; }
    short getExpiredYear()const { return expiredYear; }
    friend ostream& operator<<(ostream& output, const Bankcard& s);
};
ostream& operator<<(ostream& output, const Bankcard& s)
{
    cout << "Long code: " << s.longCode << endl
        << "Password: " << s.password << endl
        << "Balance: " << s.balance << endl
        << "Expired time:" << s.expiredMonth << "/" << s.expiredYear << endl;
    return output;
}
class Bank
{
    string name;
    string location;
    vector<Bankcard>bankCards;
public:
    Bank(string name, string location)
        :name(name), location(location)
    {}
    string getName()const { return name; }
    string getLocation()const { return location; }
    vector<Bankcard>& BankCards() { return bankCards; }

};

class Student
{
    string name;
    string surname;
    string speciality;
    double score;
    double money;
    Bankcard bankCard;
    vector<Exam>exams;
public:
    Student(string name, string surname, string speciality, double score, double money, Bankcard bankCard)
        :name(name), surname(surname), speciality(speciality), score(score), money(money), bankCard(bankCard)
    {}

    string getName()const { return name; }
    string getSurname()const { return surname; }
    string getSpeciality()const { return speciality; }
    vector<Exam>& getExams() { return exams; }
    double getMoney()const { return money; }
    double getScore()const { return score; }
    Bankcard getBankcard()const { return bankCard; }

    double showBalance()const
    {
        return bankCard.getBalance();
    }

    friend ostream& operator<<(ostream& output, const Student& s);
};
ostream& operator<<(ostream& output, const Student& s)
{
    cout << "Name: " << s.name << endl
        << "Surname: " << s.surname << endl
        << "Speciality: " << s.speciality << endl
        << "Score: " << s.score << endl
        << "Money: " << s.money << endl
        << "Bankcard: " << s.bankCard << endl;
    cout << "====== Exams ======" << endl;
    for (size_t i = 0; i < s.exams.size(); i++)
    {
        cout << s.exams[i] << endl;
    }
    return output;
}
class Group
{
    string name;
    vector<Student>students;
    vector<Lesson>lessons;
public:
    Group(string name)
    { }

    string getName()const { return name; }
    vector<Student>& GetStudents() { return students; }
    vector<Lesson>& Getlessons() { return lessons; };

    friend ostream& operator<<(ostream& output, const Group& s);
};
ostream& operator<<(ostream& output, const Group& s)
{
    cout << "Name: " << s.name << endl;
    cout << "Students: " << endl;
    for (size_t i = 0; i < s.students.size(); i++)
    {
        cout << s.students[i] << endl;
    }
    cout << "Lessons: " << endl;
    for (size_t i = 0; i < s.lessons.size(); i++)
    {
        cout << s.lessons[i] << endl;
    }
    return output;
}

class Teacher
{
    string name;
    string surname;
    short age;
    vector<Group>groups;
    string department;
    double salary;
    Bankcard bankCard;

public:
    Teacher(string name, string surname, short age, string department, double salary, Bankcard bankCard)
        :name(name), surname(surname), age(age), department(department), salary(salary), bankCard(bankCard)
    {}

    string getName()const { return name; }
    string getSurname()const { return surname; }
    short getAge()const { return age; }
    vector<Group>& getGroups() { return groups; }
    string getDepartment()const { return department; }
    double getSalary()const { return salary; }
    Bankcard getBankcard()const { return bankCard; }

    friend ostream& operator<<(ostream& output, const Teacher& s);
};
ostream& operator<<(ostream& output, const Teacher& s)
{
    cout << "Name: " << s.name << endl
        << "Surname: " << s.surname << endl
        << "Age: " << s.age << endl
        << "Department: " << s.department << endl
        << "Salary: " << s.salary << endl;
    cout << "Groups: " << endl;
    for (size_t i = 0; i < s.groups.size(); i++)
    {
        cout << s.groups[i] << endl;
    }
    cout << "BankCard: " << s.bankCard << endl;
    return output;
}


class University
{
    string name;
    vector<Teacher>teachers;
    vector<Student>students;
public:
    vector<Teacher>& getTeachers() { return teachers; }
    vector<Student>& getStudents() { return students; }
    University(string name)
        :name(name)
    {}
    double getUniversityScore()const
    {
        double sum = 0;
        for (size_t i = 0; i < students.size(); i++)
        {
            sum += students[i].getScore();
        }
        return (sum / students.size());
    }

    void showAllStudents()
    {
        for (size_t i = 0; i < students.size(); i++)
        {
            cout << students[i] << endl;
        }
    }
    void showAllTeachers()
    {
        for (size_t i = 0; i < teachers.size(); i++)
        {
            cout << teachers[i] << endl;
        }
    }

    double getPayment()
    {
        double sumTeachers = 0;
        for (size_t i = 0; i < teachers.size(); i++)
        {
            sumTeachers += teachers[i].getSalary();
        }
        double sumStudents = 0;
        for (size_t i = 0; i < students.size(); i++)
        {
            sumStudents += students[i].getMoney();
        }

        return sumTeachers + sumStudents;
    }
};

class Start
{
public:
    static void StartMain()
    {
        Student s1("Alex", "Smith", "IT", 80, 130, Bankcard{ "3454 189247 27275", "password1", 4000, 7, 2025 });
        s1.getExams().push_back(Exam{ Lesson{ "Programming",6,50 }, 95, "03.06.2022" });
        s1.getExams().push_back(Exam{ Lesson{ "Calculus",4,30 }, 91, "07.06.2022" });
        s1.getExams().push_back(Exam{ Lesson{ "Computer achitecture",98,50 }, 70, "06.06.2022" });

        Student s2("Dorian", "Cash", "Medicine", 79, 130, Bankcard{ "3675 336347 45376", "password2", 500, 7, 2025 });
        s2.getExams().push_back(Exam{ Lesson{ "Programming",6,50 }, 95, "03.06.2022" });
        s2.getExams().push_back(Exam{ Lesson{ "Calculus",4,30 }, 91, "07.06.2022" });
        s2.getExams().push_back(Exam{ Lesson{ "Computer achitecture",98,50 }, 70, "06.06.2022" });

        Student s3("Edward", "Walsh", "IT", 100, 200, Bankcard{ "450 84872 24557 260", "password3", 3000, 7, 2025 });
        s3.getExams().push_back(Exam{ Lesson{ "Programming",6,50 }, 95, "03.06.2022" });
        s3.getExams().push_back(Exam{ Lesson{ "Calculus",4,30 }, 91, "07.06.2022" });
        s3.getExams().push_back(Exam{ Lesson{ "Computer achitecture",98,50 }, 70, "06.06.2022" });

        Student s4("Moana", "Castro", "language", 60, 90, Bankcard{ "6334 6323 8612 3747", "password4", 200, 7, 2025 });
        s4.getExams().push_back(Exam{ Lesson{ "Programming",6,50 }, 95, "03.06.2022" });
        s4.getExams().push_back(Exam{ Lesson{ "Calculus",4,30 }, 91, "07.06.2022" });
        s4.getExams().push_back(Exam{ Lesson{ "Computer achitecture",98,50 }, 70, "06.06.2022" });

        Student s5("Asher", "Lynch", "Architecture", 95, 200, Bankcard{ "5343 8744 7775 5254", "password5", 8000, 7, 2025 });
        s5.getExams().push_back(Exam{ Lesson{ "Programming",6,50 }, 95, "03.06.2022" });
        s5.getExams().push_back(Exam{ Lesson{ "Calculus",4,30 }, 91, "07.06.2022" });
        s5.getExams().push_back(Exam{ Lesson{ "Computer achitecture",98,50 }, 70, "06.06.2022" });


        Group g682("682.21E");
        g682.GetStudents().push_back(s1);
        g682.GetStudents().push_back(s2);


        g682.Getlessons().push_back(Lesson{ "Programming",6,50 });
        g682.Getlessons().push_back(Lesson{ "Calculus",4,30 });
        g682.Getlessons().push_back(Lesson{ "Computer achitecture",8,50 });
        Group g687("687.21");
        g687.GetStudents().push_back(s3);
        g687.GetStudents().push_back(s4);
        g687.GetStudents().push_back(s5);

        g687.Getlessons().push_back(Lesson{ "Literature",6,50 });
        g687.Getlessons().push_back(Lesson{ "English",4,30 });
        g687.Getlessons().push_back(Lesson{ "History",8,50 });

        Teacher t1("Teacher1", "Surname1", 30, "IT", 1500, Bankcard{ "3454 189247 27275", "password1", 4000, 7, 2025 });
        t1.getGroups().push_back(g682);

        Teacher t2("Teacher2", "Surname2", 27, "Med", 900, Bankcard{ "3675 336347 45376", "password2", 4000, 7, 2025 });
        t2.getGroups().push_back(g682);
        t2.getGroups().push_back(g687);
        Teacher t3("Teacher3", "Surname3", 48, "Literature", 700, Bankcard{ "450 84872 24557 260", "password3", 4000, 7, 2025 });
        t3.getGroups().push_back(g687);
        Teacher t4("Teacher4", "Surname4", 26, "Mathematics", 2000, Bankcard{ "5343 8744 7775 5254", "password4", 4000, 7, 2025 });
        t4.getGroups().push_back(g682);

        Bank bank("KapitalBank", "Baku,Azerbaijan");
        bank.BankCards().push_back(s1.getBankcard());
        bank.BankCards().push_back(s2.getBankcard());
        bank.BankCards().push_back(s3.getBankcard());
        bank.BankCards().push_back(s4.getBankcard());
        bank.BankCards().push_back(s5.getBankcard());

        bank.BankCards().push_back(t1.getBankcard());
        bank.BankCards().push_back(t2.getBankcard());
        bank.BankCards().push_back(t3.getBankcard());
        bank.BankCards().push_back(t4.getBankcard());

        University university("ADNSU");
        university.getStudents().push_back(s1);
        university.getStudents().push_back(s2);
        university.getStudents().push_back(s3);
        university.getStudents().push_back(s4);
        university.getStudents().push_back(s5);

        university.getTeachers().push_back(t1);
        university.getTeachers().push_back(t2);
        university.getTeachers().push_back(t3);
        university.getTeachers().push_back(t4);

        cout << "University score: " << university.getUniversityScore() << endl;
        cout << "===== All students =====" << endl;
        university.showAllStudents();

        cout << "===== All teachers =====" << endl;
        university.showAllTeachers();

        cout << "All payment: " << university.getPayment() << endl;
    }
};