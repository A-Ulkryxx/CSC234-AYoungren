#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

//Data Structure's Class for Units, pulled for testing and creation.
class Unit
{
private:
    string assessment;
    double grade;
    string date;
    string schoolYear;
    double district;
    int maxScore; // added by Austin for conceptual purposes
public:
    Unit()
    {
        assessment = "";
        grade = 0;
        date = "";
        schoolYear = "";
        district = 0;
        maxScore = 0; // added by Austin for conceptual purposes
    }

    Unit(string paraAssessment, double paraGrade, string paraDate, string paraSchoolYear, double paraDistrict, int paraMaxScore)
    {
        this->assessment = paraAssessment;
        this->grade = paraGrade;
        this->date = paraDate;
        this->schoolYear = paraSchoolYear;
        this->district = paraDistrict;
        this->maxScore = paraMaxScore; // added by Austin for conceptual purposes
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

    void setMaxScore(int paraMaxScore) // added by Austin for conceptual purposes
    {
        this->district = paraMaxScore;
    }

    int getMaxScore() // added by Austin for conceptual purposes
    {
        return this->maxScore;
    }

};

vector<double> scoreDistribution(vector<Unit> unitScores);

int main()
{
    map<double, vector<Unit>> studentDatabase;

    // will be hard to test until Data Structures completes what their map will look like
    // Once completed I will have a better understanding of how the call of the data will work.

    system("PAUSE");
    return 0;
}

/// <summary>
/// Counts the number of occurances of each score within a unit across all students.
/// </summary>
/// 
/// <param name="unitScores">
/// A vector containing units. Will likely be replaced by student map which
/// will cause use to change our for loop conditions slightly.
/// </param>
/// 
/// <returns vector = "scoreCount> 
/// A vector containing the the number of occurences of each possible score in the unit.
/// Index of 0 would contain the number of times a 0 was scored. 
/// </returns>
/// <summary>
/// Counts the number of occurances of each score within a unit across all students.
/// </summary>
/// <param name="unitScores">
/// A vector containing units. Will likely be replaced by student map which
/// will cause use to change our for loop conditions slightly.
/// </param>
/// <returns vector = "scoreCount> 
/// A vector containing the the number of occurences of each possible score in the unit.
/// Index of 0 would contain the number of times a 0 was scored. 
/// </returns>
static vector<double> scoreDistribution(vector<Unit> unitScores)
{
    vector<double> scoreCounts;
    double highestScore = 0;

    for (Unit score : unitScores)
    {
        if (score.getGrade() > highestScore)
        {
            highestScore = score.getGrade();
        }
    }

    for (int i = 0; i < highestScore; i++)
    {
        scoreCounts.push_back(0);
    }

    for (Unit score : unitScores)
    {
        scoreCounts.at(score.getGrade())++;
    }

    return scoreCounts;
}

/// <summary>
/// 
/// </summary>
/// <param name="unitScores"></param>
/// <returns "scorePercentage"> a vector </returns>
vector<double> scorePercentages(vector<Unit>unitScores) 
{

    vector<double> scoreCounts = scoreDistribution(unitScores);
    double scoreSum = 0;
    vector<double> scorePercentage;
    double temp;

    for (double s : scoreCounts)
    {
        scoreSum = scoreSum + s;
    }

    for (double p : scoreCounts)
    {
        temp = ((p / scoreSum) * 100);
        temp = round(temp * 100.0) / 100.0;
        scorePercentage.push_back(temp);
    }

    return scorePercentage;
}


vector<Unit> getUnitScores(map<double, vector<Unit>> studentDatabase, string specifiedAssessment)
{
    vector<Unit> unitScores;
    for (double student : studentDatabase)
    {
        for (Unit u : student.getUnit())
        {
            if (u.getAssessment() == specifiedAssessment)
            {
                unitScores.push_back(u.getGrade());
            }
        }
    }

    return unitScores;
}