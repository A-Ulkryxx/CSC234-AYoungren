/*

*/
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <list>
#include <sstream>
using namespace std;

/**
 * @brief Student class.
 * Contains:
 * int studentNumber
 * int district
 * string schoolYear
 * string date;
 * map<string,string> scores
 *
 * even though the scores are ints, when they are read from the
 * file, they are strings. we convert them to ints via the getScore
 * method.
 *
 */

 /*
 int getScore(string columnName)
 {
     if (this->scores[columnName] == "") {
         return 0;
 }
     else
     {
         return stoi(this->scores[columnName]); // stoi converts string to int
     }

 }
 */

class Student
{
private:
    double idNum;
    double districtID;
    string gender;
    string language;
    string ethnicity;

public:
    Student()
    {
        idNum = 0;
        districtID = 0;
        gender = "";
        language = "";
        ethnicity = "";
    }

    Student(double paraIDNum, double paraDistrictID, string paraGender, string paraLanguage, string paraEthnicity)
    {
        this->idNum = paraIDNum;
        this->districtID = paraDistrictID;
        this->gender = paraGender;
        this->language = paraLanguage;
        this->ethnicity = paraEthnicity;
    }

    void setIDNum(double paraIDNum)
    {
        this->idNum = paraIDNum;
    }

    double getIDNum()
    {
        return this->idNum;
    }

    void setdistrictID(double paraDistrictID)
    {
        this->districtID = paraDistrictID;
    }

    double getDistrictID()
    {
        return this->districtID;
    }

    void setGender(string paraGender)
    {
        this->gender = paraGender;
    }

    string getGender()
    {
        return this->gender;
    }

    void setLanguage(string paraLanguage)
    {
        this->language = paraLanguage;
    }

    string getLanguage()
    {
        return this->language;
    }

    void setEthnicity(string paraEthnicity)
    {
        this->ethnicity = paraEthnicity;
    }

    string getEthnicity()
    {
        return this->ethnicity;
    }
};

class Unit
{
private:
    string assessment;
    double grade;
    string date;
    string schoolYear;
    double district;
public:
    Unit()
    {
        assessment = "";
        grade = 0;
        date = "";
        schoolYear = "";
        district = 0;
    }

    Unit(string paraAssessment, double paraGrade, string paraDate, string paraSchoolYear, double paraDistrict)
    {
        this->assessment = paraAssessment;
        this->grade = paraGrade;
        this->date = paraDate;
        this->schoolYear = paraSchoolYear;
        this->district = paraDistrict;
    }

    void setAssessment(string paraAssessment)
    {
        this->assessment = paraAssessment;
    }

    string getAssessment()
    {
        return this->assessment;
    }

    void setGrade(double paraGrade)
    {
        this->grade = paraGrade;
    }

    double getGrade()
    {
        return this->grade;
    }

    void setDate(string paraDate)
    {
        this->date = paraDate;
    }

        // date format in file is yyyy-mm-dd
    string getDate()
    {
        return this->date;
    }

    void setSchoolYear(string paraSchoolYear)
    {
        this->schoolYear = paraSchoolYear;
    }

    string getSchoolYear()
    {
        return this->schoolYear;
    }

    void setDistrict(double paraDistrict)
    {
        this->district = paraDistrict;
    }

    double getDistrict()
    {
        return this->district;
    }

};


/*
string toString()
{
    string output;
    output = "Student: "+to_string(this->studentNumber) +"\n";
    output += "District:" + to_string(this->district)+"\n";
    output += "School year:" + this->schoolYear + "\n";
    output += "Date:" + this->date + "\n";
    output += "Scores:\n";
    for(pair<string,string> s:scores)
    {
        output += s.first + ":" + s.second + "\n";
    }

    return output;
}
*/


/**
 * @brief split a string on a delimiter
 *
 * @param givenString the string to be spliot
 * @param delimiter the character to split on
 * @return vector<string> a vector with the individual elements
 */
vector<string> split(string givenString, char delimiter);

/**
* @brief get the list of files to read. takes no parameters
*
* @return vector<string> list of files to read
*/
vector<string> getFileList();

vector<Student> buildStudentVector();

void readCSV(map<double, vector<Unit>> studentDatabase);


/*
vector<string> countBySchoolYear(vector<Student> students, vector<string> columnHeaders, vector<string> schoolYears, int scoreCounts[10])
{
    map<int, double> output;

    // format of each CSV line is as follows:
    // column name, school year, 0, percentage of total that were zero, 1, percentage of total that were 1, ...[until the max score is reached]\n
    // because of this, lines will be of variable length so whatever is reading them
    //
    // we can either a: write this out to a file, or b: use redirection on the command line to capture output to a file
    string csvLine;
    vector<string> csvLines;
    for (string year : schoolYears)
    {
        for (int columnNumber = 4; columnNumber < columnHeaders.size(); columnNumber++)
        {
            zeroArray(scoreCounts);
            //cout << endl<<columnHeaders[columnNumber]<<endl;
            vector<Student> studentSubSet = getBySchoolYear(year, students);
            output = countScores(columnNumber, studentSubSet, columnHeaders, scoreCounts);
            csvLine = columnHeaders[columnNumber] + ",";
            csvLine += year + ",";
            for (pair<int, double> p : output)
            {
                csvLine += to_string(p.first) + "," + to_string(p.second) + ",";
            }
            csvLine.erase(csvLine.length() - 1);
            csvLine += "\n";
            cout << csvLine;
            csvLines.push_back(csvLine);



        }

    }
    return csvLines;
}
*/



/* main right now is full of tests. bejigger as necessary.
 TODO: option to select a file, or alternately just run through all
 of them (ouch!) or pass one on the command line. windows would barf
 on the spaces in the filenames, though. linux... might.

 we now have a few search functions, and you can run them one after
 the other to narrow the search -- for instance you can select all students
 in a school year, then feed that result into a search for all students
 in a given district.. etc.
*/
int main()   //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
{
    //int scoreCounts[]{ 0,0,0,0,0,0,0,0,0,0 };
    //vector<string> schoolYears{ "2015-2016","2016-2017","2017-2018","2018-2019","2019-2020","2020-2021" }; // all the school years i could find
    vector<Student> students;
    //vector<Student> test;
    //vector<string> columnHeaders;
//    vector<string> fileList;



    // change this filename as necessary -- this is just how it is on my system at present
    // eventually this whole enchilada will be wrapped in a for(string filename:fileNames) loop
    //students = readCSV("207 Grade K - Unit 6 Checkpoint.csv",columnHeaders);
    //vector<string> csvLines=countBySchoolYear( students, columnHeaders, schoolYears,scoreCounts);

//    vector<string> fileList = getFileList();

    /*
    for (int i = 0; i < fileList.size(); i++)
    {
        students = readCSV(fileList[i], columnHeaders);
        cout << fileList[i] << endl;
        //        vector<string> csvLines = countBySchoolYear(students, columnHeaders, schoolYears, scoreCounts);
    }
    */

    students = buildStudentVector();
    vector<Unit> unitVector;
    map<double, vector<Unit>> studentDatabase;
    vector<vector<Unit>> vectorOfUnitVector;

    /*
    for (int i = 0; i < students.size(); i++)
    {
        vector<Unit> innerUnitVector = { Unit() };
        unitVector[i]. new vector<Unit>;
        
    }
    */


    
    for (int i = 0; i < students.size(); i++)
    {

        studentDatabase[students[i].getIDNum()];  //ERROR ON THIS LINE
    }
    

    readCSV(studentDatabase);

    /*
    for (int i = 0; i < students.size(); i++)
    {
        studentDatabase.insert(students[i], unitVector);
    }
    */
    
}   //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

vector<string> split(string givenString, char delimiter)
{
    string token;
    vector<string> tokens;
    stringstream ss(givenString);
    while (getline(ss, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}


void readCSV(map<double, vector<Unit>> studentDatabase)                        //vector<Student> readCSV(string filename, vector<string>& columnHeaders)
{
        //COLUMN HEADERS
        //0: Student Number
        //1: School District
        //2: School Year
        //3: Date of the "Unit"
        //4 and onward: The name of the test that was taken


    int count = 0;
    int columnLength;
    vector<string> lineZero;
    vector<Unit> unitVector;


//    int i = 0;
    Student student;
    vector<Student> output;

    ifstream theFile;
    string line;
    //vector<Student> students;
    vector<string> columnHeaders;
    vector<string> lineVector;

    vector<string> fileList = getFileList();

    for (int i = 0; i < fileList.size(); i++)
    {
        theFile.open(fileList[i]);
        cout << fileList[i] << endl;

        if (!theFile.is_open()) {
            cout << "can't find the file[" << fileList[i] << "]!";
        }
        else
        {
            // first we get the column headers
            while (getline(theFile, line))
            {


                columnHeaders = split(line, ',');
                //columnHeaders.back().erase(columnHeaders.back().length() - 1);
                columnLength = columnHeaders.size();


                if (count == 0)
                {
                    lineZero = columnHeaders;
                    count++;
                }
                else
                {

                    for (int n = 4; n < columnLength; n++)
                    {
                        //Unit(assess lineZero[n], grade columnHeader[n], date columnHeader[3], year columnHeader[2], district columnHeader[1]);
                        Unit unit = Unit(lineZero[n], (double)(stoi(columnHeaders[n])), columnHeaders[3], columnHeaders[2], (double)(stoi(columnHeaders[1])));
                        unitVector.push_back(unit);
                    }

                    for (int i = 0; i < unitVector.size(); i++)
                    {
                        studentDatabase.at(stoi(columnHeaders[0])).push_back(unitVector[i]);        //ABSALOUTLY KILLS THE TIME COMPLEXITY, RESEARCH NEEDED
                    }

                    cout << "line " << count << endl;
                    count++;
                }

            }

            cout << "File " << fileList[i] << " had " << count << " lines" << endl;
            count = 0;
        }

        theFile.close();

    }








//    theFile.open(filename);

    /*
    if (!theFile.is_open()) {
        cout << "can't find the file[" << filename << "]!";
        exit(1);
    }
    */


    /*
    // first we get the column headers
    getline(theFile, line);
    columnHeaders = split(line, ',');

    // there's a \n at the end of the last element
    columnHeaders.back().erase(columnHeaders.back().length() - 1);
    


    // now we start creating Students
    // each line is one line from the csv. we split it on the commas into lineVector
    // looping through the whole file this might take a minute.
    while (getline(theFile, line))
    {
        lineVector = split(line, ',');

        // basically parse the values here. note that reading from a file, everything is a string
        // so we need to use stoi(string) to convert them to ints. the stoi(string) function converts a
        // string to an int

        // set initial student info
        Student student1((double)(stoi(lineVector[0])), (double)(stoi(lineVector[1])), lineVector[2], lineVector[3], lineVector[4]);

        // now we start stuffing the scores in. we're starting at column 4
        // since that's where the scores start.
        i = 4;

        while (i < columnHeaders.size())
        {
            student.setScore(columnHeaders[i], lineVector[i]);
            i++;

            students.push_back(student);
            count++;
        }

    }
    return students;
    */
}


vector<Student> buildStudentVector()
{
    int count = 0;
    int i = 0;
    Student student;
    vector<Student> output;
    ifstream theFile;
    string line;
    vector<Student> students;
    vector<string> columnHeaders;
    vector<string> lineVector;
    string fileName = "Students.csv";

    theFile.open(fileName);

    if (!theFile.is_open()) {
        cout << "can't find the file[" << fileName << "]!";
        exit(1);
    }
    // first we get the column headers
    getline(theFile, line);
    columnHeaders = split(line, ',');

    // there's a \n at the end of the last element
    columnHeaders.back().erase(columnHeaders.back().length() - 1);


    // now we start creating Students
    // each line is one line from the csv. we split it on the commas into lineVector
    // looping through the whole file this might take a minute.
    while (getline(theFile, line))
    {
        lineVector = split(line, ',');
        if (lineVector.size() == 4)
        {
            lineVector.push_back("");
        }
        
        // basically parse the values here. note that reading from a file, everything is a string
        // so we need to use stoi(string) to convert them to ints. the stoi(string) function converts a
        // string to an int

        // set initial student info
 //       Student student1((double)(stoi(lineVector[0])), (double)(stoi(lineVector[1])), lineVector[2], lineVector[3], lineVector[4]);

        // now we start stuffing the scores in. we're starting at column 4
        // since that's where the scores start.

        
        
        Student student1((double)(stoi(lineVector[0])), (double)(stoi(lineVector[1])), lineVector[2], lineVector[3], lineVector[4]);
        students.push_back(student1);
        count++;
        

        

    }
    cout << "We created files on " << count << " students";
    return students;
}

vector<string> getFileList()
{
    vector<string> output;
    ifstream theFile;
    string line;
    theFile.open("filelist");
    while (getline(theFile, line)) {
        output.push_back(line);
    }
    return output;
}