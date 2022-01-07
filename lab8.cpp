#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<fstream.h>

class employee
{
	int ID;
	char Name[10];
	float Salary;

	public:
    employee()
    {
        ID = 0;
        Salary = 0;
        //Name = "anonynous";
    }
   

	void setid(int id){ID = id;};
	void setName(char name[]){strcpy(Name, name);};
	void setSalary(float sal){Salary = sal;};
	int getid(void){return ID;};
	char* getName(void){return Name;};
	float getSalary(void){return Salary;};

    friend ostream& operator <<(ostream& out, employee e);
    friend istream& operator >>(istream& in, employee& e);
    friend ofstream& operator <<(ofstream& out, employee e);
    friend ifstream& operator >>(ifstream& in, employee& e);
};

int main()
{
    clrscr();
	employee emp1, emp2;

    cin>>emp1;
    //cout<<emp1;

    //writting in the text file test
    ofstream obj1;
    obj1.open("test.txt");
    obj1<<emp1;
    obj1.close();

    //reading from the text file test
    ifstream obj2;
    obj2.open("test.txt");
    obj2>>emp2;
    cout<<emp2;
    obj2.close();


    getch();
	return 0;
}


ostream& operator <<(ostream& out, employee e)
{
    out<<"ID: "<<e.ID<<endl;
    out<<"Name: "<<e.Name<<endl;
    out<<"Salary: "<<e.Salary<<endl;
    return out;
}

istream& operator >>(istream& in, employee& e)
{
    cout<<"Enter the ID: ";
    in>>e.ID;
    cout<<"Enter the Name: ";
    in>>e.Name;
    cout<<"Enter the salary: ";
    in>>e.Salary;
    return cin;
}

ofstream& operator <<(ofstream& out, employee e)
{
    out<<e.ID<<endl;
    out<<e.Name<<endl;
    out<<e.Salary<<endl;
    return out;
}

ifstream& operator >>(ifstream& in, employee& e)
{
    in>>e.ID;
    in>>e.Name;
    in>>e.Salary;
    return in;
}