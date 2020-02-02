#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <time.h> 
#include <iostream>
#include <string>
#include <algorithm>
#include <ctime> 
using namespace std;
class Human
{
	int id;
	string name;
	tm birthDate;
	static int counter;
public: Human();
public: Human(string& _name, tm& _birthDate);
public: virtual void ConsoleOutput();
public: virtual void ConsoleInput();
		friend istream &operator>> (istream& c, Human& f)
		{
			c >> f.name;
			c >> f.birthDate.tm_mday;
			c >> f.birthDate.tm_mon;
			c >> f.birthDate.tm_year;
		}
		friend ostream &operator<< (ostream& t, Human& f)
		{
			t << f.id << endl;
			t << f.name << endl;
			t << f.birthDate.tm_mday;
			t << f.birthDate.tm_mon;
			t << f.birthDate.tm_year;
		}
public: void adultAge();
public: virtual int GetId();
};
class Worker : public Human
{
	string post;
	int hourCost;
public:	class  Report
{
	string reportDate;
	int workHours;
public: Report(string _reportDate, int _workHours) : reportDate(_reportDate), workHours(_workHours) {}
};
		vector <Report> reports;
public: Worker() : hourCost(0), Human() {}
public: Worker(string& _name, tm& _birthDate, string& _post, int _hourCost) :
	post(_post), hourCost(_hourCost), Human(_name, _birthDate)
{
	post = _post;
	hourCost = _hourCost;
}
public: void AddReport(string _date, int _workHours)
{
	reports.push_back(Report(_date, _workHours));
}
public: virtual void Sal();
public: virtual void ConsoleInput();
public: virtual void ConsoleOutput();
public: virtual void SetPost(string _post);
public: virtual void SetHourCost(int _hourCost);
};
class Department : public Worker
{
	int deptNumber;
	string deptName;
public:
	vector <Worker> workersList;
public: Department() : deptNumber(0), Worker() {}
public: Department(int _deptNumber, string& _deptName, string& _name, tm& _birthDate, string& _post, int _hourCost) : deptNumber(_deptNumber), deptName(_deptName), Worker(_name, _birthDate, _post, _hourCost) {}
public: void ConsoleInput();
public: void ConsoleOutput();
public: int GetDeptNumber();
public: string GetDeptName();
public: void ShowWorker();
public: void WorkerSalary();
public: void AddWorker(string& _name, tm& _birthDate, string& _post, int _hourCost)
{
	workersList.push_back(Worker(_name, _birthDate, _post, _hourCost));
}
};
