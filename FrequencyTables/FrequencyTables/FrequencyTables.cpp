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

    //Luke Padula: did this little operator overide to enable sort
    bool operator < (const Student& obj) const
    {
        return (idNum < obj.idNum);

    }
};

vector<double> scoreDistribution(vector<Unit> unitScores);
vector<double> scorePercentages(vector<double>unitScores, vector<double> scoreCounts);

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
/// <param name="unitScores">
/// A vector containing units. Will likely be replaced by student map which
/// will cause use to change our for loop conditions slightly.
/// </param>
/// <returns vector = "scoreCount> 
/// A vector containing the the number of occurences of each possible score in the unit.
/// Index of 0 would contain the number of times a 0 was scored. 
/// </returns>static vector<double> scoreDistribution(vector<Unit> unitScores)
vector<double> scoreDistribution(vector<double> unitScores)
{
    vector<double> scoreCounts;
    double highestScore = 0;

    for (double score : unitScores)
    {
        if (score > highestScore)
        {
            highestScore = score;
        }
    }

    for (int i = 0; i < highestScore; i++)
    {
        scoreCounts.push_back(0);
    }

    for (double score : unitScores)
    {
        scoreCounts[score]++;
    }
    return scoreCounts;



}

/// takes the score counts which sorted each score individually and counts the frequency of each score as it goes through them up to the top score
/// then takes the frequency and divides it by the total number of scores and multiplies into a percentage
/// STILL NEEDS TO BE IMPLEMENTED
vector<double> scorePercentages(vector<double>unitScores, vector<double> scoreCounts)
{

    vector<double> scorePercentage;
    double scoreSum = 0;
    
    double temp;

    for (double s : unitScores)
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

/// <summary>
/// Templates used until more information is recieved from DS.
/// I opted for templates since I am unsure how a key will be placed into the first location of a double vector.
/// 
/// Current takes in a key and a vector. The key is used to find the sum of max scores.
/// The vector is used to find sum of total scores. 
/// These two sums are used to find the raw score percentage of that student.
/// </summary>
/// <typeparam name="T"> T generic represents score member currently</typeparam>
/// <typeparam name="K"> K generic represents a key member</typeparam>
/// <param name="studentKey">A key containing aditional information of the student</param>
/// <param name="studentScores">Assumed Vector of Student's scores</param>
/// <returns>
/// Overall percentage grade of given score for a single student. 
/// Returns as a percentage value rounded to two decimal places 
/// </returns>
template <typename T, typename K>
    //unsure if needed, but accidently created it so... here it is
double studentCareerScorePerc(K studentKey, vector<T> studentScores) 
{
    double studTotalScore = 0;
    double studMaxScore = 0;
    double studRawPerc;
    for (T score : studentScores)
    {
        studTotalScore += score;
    }
    for (T mScore : studentKey.getMaxScores())
    {
        studMaxScore += score;
    }

    studRawPerc = studTotalScore / studMaxScore;
    studRawPerc = round(studRawPerc * 100.0) / 100.0;

    return studTotalPerc;
}

/// <summary>
/// Finds the individual percentage of each performance. 
/// Then adds each individual performance to one percentage sum.
/// percentage sum is divided my the total number of scores to provide weighted performance
/// of scores given. 
/// </summary>
/// <typeparam name="T"> T generic represents score member currently</typeparam>
/// <typeparam name="K"> K generic represents a key member</typeparam>
/// <param name="studentKey">A key containing aditional information of the student</param>
/// <param name="studentScores">Assumed Vector of Student's scores</param>
/// <returns>
/// Returns overall weighted grade of given scores.
///  It returned as a percentage value rounded to two decimals
/// </returns>
template <typename T, typename K>
double studentCareerWeightPerc(K studentKey, vector<T> studentScores)
{
    double studTotalScore = 0;
    double studMaxScore = 0;
    int numOfScores = studentScores.size();
    double studRawPercSum;
    double studWeightedPerc;
    
    for (int i = 0; i < studentScores.size(); i++)
    {
        if (!studentKey.getMaxScores().at(i) == 0)
        {
            studTotalScore = studentScores.at(i);
            studMaxScore = studentKey.getMaxScores().at(i);
            studRawPercSum = studRawPercSum + (studTotalScore / studMaxScore);
        }
    }
    studWeightedPerc = studRawPercSum / numOfScores;
    studWeightedPerc = round(studWeightedPerc * 100.0) / 100.0;

    return studWeightedPerc;
}
