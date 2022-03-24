#include <iostream>
#include <vector>
#include <map>
using namespace std;

<<<<<<< HEAD
//Data Structure's Class for Units, pulled for testing and creation.
=======
   //Data Structure's Class for Units, pulled for testing and creation.
>>>>>>> db8e1fe037e197d4051813072b532d41ff9472c8
class Unit
{
private:
    string assessment;
    double grade;
    string date;
    string schoolYear;
    double district;
<<<<<<< HEAD
    int maxScore; // added by Austin for conceptual purposes
=======
>>>>>>> db8e1fe037e197d4051813072b532d41ff9472c8
public:
    Unit()
    {
        assessment = "";
        grade = 0;
        date = "";
        schoolYear = "";
        district = 0;
<<<<<<< HEAD
        maxScore = 0; // added by Austin for conceptual purposes
    }

    Unit(string paraAssessment, double paraGrade, string paraDate, string paraSchoolYear, double paraDistrict, int paraMaxScore)
=======
    }

    Unit(string paraAssessment, double paraGrade, string paraDate, string paraSchoolYear, double paraDistrict)
>>>>>>> db8e1fe037e197d4051813072b532d41ff9472c8
    {
        this->assessment = paraAssessment;
        this->grade = paraGrade;
        this->date = paraDate;
        this->schoolYear = paraSchoolYear;
        this->district = paraDistrict;
<<<<<<< HEAD
        this->maxScore = paraMaxScore; // added by Austin for conceptual purposes
=======
>>>>>>> db8e1fe037e197d4051813072b532d41ff9472c8
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

<<<<<<< HEAD
    void setMaxScore(int paraMaxScore) // added by Austin for conceptual purposes
    {
        this->district = paraMaxScore;
    }

    int getMaxScore() // added by Austin for conceptual purposes
    {
        return this->maxScore;
    }

=======
>>>>>>> db8e1fe037e197d4051813072b532d41ff9472c8
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
<<<<<<< HEAD
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
=======
>>>>>>> db8e1fe037e197d4051813072b532d41ff9472c8
/// <param name="unitScores">
/// A vector containing units. Will likely be replaced by student map which
/// will cause use to change our for loop conditions slightly.
/// </param>
/// <returns vector = "scoreCount> 
/// A vector containing the the number of occurences of each possible score in the unit.
/// Index of 0 would contain the number of times a 0 was scored. 
/// </returns>
vector<double> scoreDistribution(vector<Unit> unitScores)
{
    vector<double> scoreCounts;
    double highestScore = 0;
<<<<<<< HEAD
    
    for (Unit score : unitScores)
    {
        if (score.getGrade() > highestScore)
        {
            highestScore = score.getGrade();
        }
    }

    for (int i = 0 ; i < highestScore; i++)
    {
        scoreCounts.push_back(0);
    }

    for (Unit score : unitScores)
    {
        scoreCounts.at(score.getGrade())++;
=======
    double count;
    for (Unit score : unitScores)
    {
        if (unitScores.getGrade() > highestScore)
        {
            highestScore = unitScores.getGrade();
        }
    }

    for (int i = 0; i < highestScore; i++)
    {
        count = 0;
        for (Unit score : unitScores)
        {
            if (unitScores.getGrade() == i)
            {
                count++;
            }
        }
        scoreCounts.push_back(count);
>>>>>>> db8e1fe037e197d4051813072b532d41ff9472c8
    }

    return scoreCounts;
}