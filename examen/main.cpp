#include "HUMAN.h"
void ShowDeptList(Department* deptList)
{
	deptList->ConsoleOutput();
}
void ShowAllDepts(Department** deptList, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (deptList[i] != nullptr)
			ShowDeptList(deptList[i]);
	}
}
void WorkerSearch(Department** deptList, int searchId, int deptCounter)
{
	int count = 0;
	for (int i = 0; i<deptCounter; i++)
	{
		if (deptList[i]->GetId() == searchId)
		{
			count++;
			deptList[i]->ShowWorker();
		}
	}
	if (count == 0)
		cout << "No worker found" << endl;
}
void WorkerSalary(Department** deptList, int searchId, int deptCounter)
{
	for (int i = 0; i<deptCounter; i++)
	{
		if (deptList[i]->GetId() == searchId)
		{
			deptList[i]->WorkerSalary();
		}
	}

}
void DepartmentSearch(Department** deptList, int searchId, int deptCounter)
{
	int count = 0;
	for (int i = 0; i<deptCounter; i++)
	{
		if (deptList[i]->GetDeptNumber() == searchId)
		{
			count++;
			deptList[i]->ConsoleOutput();
		}
	}
	if (count == 0)
		cout << "No department found" << endl;
}
int main()
{
	Department** deptList = nullptr;
	int deptCounter = 0;
	Department** prevDeptList = nullptr;
	int option = 0;
	while (true)
	{
		cout << "1. Add department \n";
		cout << "2. Show all departments \n";
		cout << "3. Worker Search \n";
		cout << "4. Remove department\n";
		cout << "5. Calculate workers salary\n";
		cout << "6. Search for a branch by department number\n";
		cout << "7. Exit\n";
		cin >> option;
		cin.ignore();
		switch (option)
		{
		case 1:
		{
			prevDeptList = deptList;
			deptCounter++;
			deptList = new Department*[deptCounter];
			for (int i = 0; i < (deptCounter)-1; ++i)
			{
				deptList[i] = prevDeptList[i];
			}
			delete[]prevDeptList;
			deptList[(deptCounter)-1] = new Department;
			deptList[(deptCounter)-1]->ConsoleInput();
			break;
		}
		case 2:
		{
			for (int i = 0; i < deptCounter; ++i)
				if (deptList[i] != nullptr)
					ShowDeptList(deptList[i]);
			break;
		}
		case 3:
		{
			int searchId;
			cout << "Enter the worker's ID for search --> ";
			cin >> searchId;
			WorkerSearch(deptList, searchId, deptCounter);
			break;
		}
		case 4:
		{
			ShowAllDepts(deptList, deptCounter);
			int selectID = 0;
			cout << "Input Department Number for removing -->";
			cin >> selectID;
			cin.ignore();
			int counter = 0;
			for (int i = 0; i <deptCounter; ++i)
			{
				if (deptList[i]->GetDeptNumber() == selectID && deptList[i]->GetId() == 0)
				{
					delete deptList[i];
					deptList[i] = nullptr;
				}
				else
					counter++;
				if (counter == 1)
					cout << "ERROR: You cannot remove department with workers!" << endl;
				cout << endl;
			}
			break;
		}
		case 5:
		{
			int searchId;
			cout << "Enter the worker's ID for to calculate the salary --> ";
			cin >> searchId;
			WorkerSearch(deptList, searchId, deptCounter);
			WorkerSalary(deptList, searchId, deptCounter);
			cout << endl;
			break;
		}
		case 6:
		{
			int searchId;
			cout << "Enter the departments's ID for search --> ";
			cin >> searchId;
			DepartmentSearch(deptList, searchId, deptCounter);
			cout << endl;
			break;
		}
		case 7:
		{
			for (int i = 0; i < deptCounter; ++i)
				delete deptList[i];
			delete[] deptList;
			exit(0);
			break;
		}
		}
	}
}
