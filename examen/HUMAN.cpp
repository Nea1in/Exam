#include "HUMAN.h"
int Human::counter = 0;
Human::Human()
{
	counter++;
	id = counter;
	birthDate.tm_mday = 0;
	birthDate.tm_mon = 0;
	birthDate.tm_year = 0;
}
Human::Human(string& _name, tm& _birthDate)
{
	id = ++counter;
	name = _name;
	birthDate = _birthDate;
}
void Human::ConsoleOutput()
{
	cout << "Name: " << name << endl;
	cout << "Person ID: " << id << endl;
	cout << "Birth date: " << birthDate.tm_mday << "." << birthDate.tm_mon << "." << birthDate.tm_year << endl;
}
void Human::ConsoleInput()
{
	cout << "Name -> ";
	getline(cin, name);
	cout << "Birth date -> ";
	cin >> birthDate.tm_mday;
	cin >> birthDate.tm_mon;
	cin >> birthDate.tm_year;
}
int Human::GetId()
{
	return id;
}
void Human::adultAge()
{
	int age;
	time_t t = time(0);
	tm tmt = *(localtime(&t));
	age = tmt.tm_year + 1900 - birthDate.tm_year;
	if (age < 18)
		cout << "not adult" << endl;
	else
		if (age >= 18 && birthDate.tm_mon < tmt.tm_mon + 1)
			cout << "not adult" << endl;
		else
			if (age >= 18 && birthDate.tm_mon == tmt.tm_mon + 1 && birthDate.tm_mday < tmt.tm_mday)
				cout << "not adult" << endl;
			else
				cout << "adult" << endl;
}
void Worker::Sal()
{
	tm end = { 0,0,0,0,0,0,0,0,0 };
	tm begining = { 0,0,0,0,0,0,0,0,0 };
	double workingDays;
	double periodSalary;
	cout << "Input begining date -> ";
	cin >> begining.tm_mday;
	cin >> begining.tm_mon;
	begining.tm_mon = begining.tm_mon - 1;
	cin >> begining.tm_year;
	begining.tm_year = begining.tm_year - 1900;
	cout << "Input end date -> ";
	cin >> end.tm_mday;
	cin >> end.tm_mon;
	end.tm_mon = end.tm_mon - 1;
	cin >> end.tm_year;
	end.tm_year = end.tm_year - 1900;
	workingDays = (difftime(mktime(&end), mktime(&begining))) / 86400;
	periodSalary = workingDays * 8 * hourCost;
	cout << "Salary for indicated period is " << periodSalary << " uan" << endl;
}
void Worker::ConsoleInput()
{
	Human::ConsoleInput();
	cin.ignore();
	cout << "Input worker's post -> ";
	getline(cin, post);
	cout << "Input cost per hour -> ";
	cin >> hourCost;
	cout << endl;
}
void Worker::ConsoleOutput()
{
	Human::ConsoleOutput();
	cout << "Post: " << post << endl;
	cout << "Cost per hour, UAH: " << hourCost << endl;
	cout << endl;
}
void Worker::SetPost(string _post)
{
	post = _post;
}
void Worker::SetHourCost(int _hourCost)
{
	hourCost = _hourCost;
}
void Department::ConsoleInput()
{
	cout << "Input departmnet number -> ";
	cin >> deptNumber;
	cin.ignore();
	cout << "Input department name -> ";
	getline(cin, deptName);
	Worker::ConsoleInput();
	cout << endl;
}
void Department::ConsoleOutput()
{
	cout << "Departmnet number: " << deptNumber << endl;
	cout << "Department name: " << deptName << endl;
	Worker::ConsoleOutput();
	cout << endl;
}
int Department::GetDeptNumber()
{
	return deptNumber;
}
string Department::GetDeptName()
{
	return deptName;
}
void Department::ShowWorker()
{
	Worker::ConsoleOutput();
	cout << endl;
}
void Department::WorkerSalary()
{
	Worker::Sal();
}