#include <iostream>
#include <string>
using namespace std;

class Section
{
private:
	string room;
	string teacher;
	int secNum;

public:
	Section()
	{
		room = "BP 119";
		teacher = "Vicki";
		secNum = 601;
	}
	Section(string parRoom, string parTeacher, int parSecNum)
	{
		room = parRoom;
		teacher = parTeacher;
		secNum = parSecNum;
	}

	string getRoom()
	{
		return room;
	}
	void setRoom(string paraRoom)
	{
		room = paraRoom;
	}
	string getTeacher()
	{
		return teacher;
	}
	void setTeacher(string paraTeacher)
	{
		teacher = paraTeacher;
	}
	int getSecNum()
	{
		return secNum;
	}
	void setSecNum(int paraSecNum)
	{
		secNum = paraSecNum;
	}
	
};

class Course
{
private:
	string courseNum;
	int maxStudents;
	int credits;
	Section sectionInfo;
public:
	Course()
	{
		courseNum = "CSC 234";
		maxStudents = 20;
		credits = 3;
	}
	Course(string parCourseNum, int parMaxStudents, int parCredits)
	{
		courseNum = parCourseNum;
		maxStudents = parMaxStudents;
		credits = parCredits;
	}
	string getCourseNum()
	{
		return courseNum;
	}
	void setCourseNum(string paraCourseNum)
	{
		courseNum = paraCourseNum;
	}
	int getMax()
	{
		return maxStudents;
	}
	void setMax(int parMax)
	{
		maxStudents = parMax;
	}
	int getCredits()
	{
		return credits;
	}
	void setCredits(int paraCredits)
	{
		credits = paraCredits;
	}
	Section getSectionInfo()
	{
		return sectionInfo;
	}
};


void printCourse(Course& course);
void inputCourse(Course& course);

int main()
{
	Course class1;
	Course class2 = Course("CSC 161", 19, 4);

	printCourse(class1);
	cout << endl;
	inputCourse(class1);
	cout << endl;
	printCourse(class1);
	cout << endl;
	printCourse(class2);

	return 0;
}


void printCourse(Course &course)
{
	cout << "The course number is: " << course.getCourseNum() << endl;
	cout << "The max Students is: " << course.getMax() << endl;
	cout << "The amount of credits for the class is: " << course.getCredits() << endl;
	cout << "Course room: " << course.getSectionInfo().getRoom() << endl;
	cout << "Course Teacher: " << course.getSectionInfo().getTeacher() << endl;
	cout << "Course Section: " << course.getSectionInfo().getSecNum() << endl;

}

void inputCourse(Course &course)
{
	string courseNum;
	int max;
	int credits;
	string junk;
	
	cout << "Enter the maximum number of students";
	cin >> max;
	course.setMax(max);
	getline(cin, junk); //clears the input stream


	cout << "Enter the course number";
	getline( cin, courseNum);
	course.setCourseNum(courseNum);

	cout << "Enter the number of credits";
	cin >> credits;
	course.setCredits(credits);
}