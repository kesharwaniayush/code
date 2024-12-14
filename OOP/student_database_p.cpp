#include<iostream>
using namespace std;
class Student
{
public:
    string name;
    int roll_number;
    string blood_group;
    string dob;
    string standard;
    string division;
    long long int tel;
    static int counter;
    Student()  //default constructor
    {
        roll_number = 0;
        counter++;
    }
    Student(int roll_number)  //parameterized constructor
    {
        this->roll_number = roll_number;
        counter++;
    }
    Student (Student &obj)  //copy constructor
    {
        name = obj.name;
        roll_number = obj.roll_number;
        blood_group = obj.blood_group;
        dob = obj.dob;
        standard = obj.standard;
        division = obj.division;
        tel = obj.tel;
        counter++;
    }
    ~Student()  //destructor
    {
        cout << "Deleting objects" << endl;
        counter--;
    }
    static void display_counter()
    {
        cout << "The number of objects created are- " << counter << endl;
    }
    void addData();
    friend void display(Student &obj);
};
void Student :: addData()
{
    cout << "\nEnter name-\n";
    cin >> name;
    cout << "Enter roll number-\n";
    cin >> roll_number;
    cout << "Enter blood group-\n";
    cin >> blood_group;
    cout << "Enter date of birth-\n";
    cin >> dob;
    cout << "Enter standard-\n";
    cin >> standard;
    cout << "Enter division-\n";
    cin >> division;

    int flag=1;
    do
    {
        try
        {
            cout << "Enter mobile number\n";
            cin >> tel;
            if (tel < 1000000000 || tel > 9999999999)
                throw tel;
            else
                flag = 0;
        }
        catch (long long int tel)
        {
            cout << "Invalid mobile number" << endl;
            flag=1;
        }
    }while(flag==1);
}
void display(Student &obj)
{
    cout << "\nName is- " << obj.name << endl;
    cout << "Roll number is- " << obj.roll_number << endl;
    cout << "Blood group is- " << obj.blood_group << endl;
    cout << "Date of birth is- " << obj.dob << endl;
    cout << "Standard is- " << obj.standard << endl;
    cout << "Division is- " << obj.division << endl;
    cout << "Mobile number is- " << obj.tel << endl;
}
int Student :: counter = 0;

int main()
{
    cout << "How many students are in your class?\n";
    int number;
    cin >> number;
    Student *s[50];
    for (int i = 0; i < number; i++)
    {
        s[i] =  new Student();
        s[i] -> addData();
    }
    for (int i = 0; i < number; i++)
    {
        display(*s[i]);
    }
    Student :: display_counter();
    for (int i = 0; i < number; i++)
    {
        delete(s[i]);
    }
}