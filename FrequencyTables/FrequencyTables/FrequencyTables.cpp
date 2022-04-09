#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
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
vector<double> scorePercentages(vector<double>unitScores, vector<double> scoreCounts); //WE NEED TO REWORK THIS ONE
template <typename T, typename K>
double studentCareerScorePerc(K studentKey, vector<T> studentScores);
template <typename T, typename K>
double studWeightPerc(K studentKey, vector<T> studentScores);
template <class T>
int countVector(vector<T> vec);
bool isEven(vector<double> vec);
double median(vector<double> vec);
double mean(vector<double> vec);
template <class K>
double medianPerc(K scoreKey, vector<double> vec);
template <class K>
double meanPerc(K scoreKey, vector<double> vec);

int main()
{
    map<double, vector<Unit>> studentDatabase;

    vector<double> odd{ 14,13,20,21,12,17,12 };
    vector<double> even{ 40,46,48,49,43,44,49,50 };
    cout << "even vector is even? " << isEven(even) << " median " << median(even);
    cout << " Mean " << fixed << setprecision(2) << mean(even) << endl;
    cout << "odd vector is even? " << isEven(odd) << " median " << median(odd);
    cout << " Mean " << fixed << setprecision(2) << mean(odd) << endl;
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
/// <returns vector scoreCount> 
/// A vector containing the the number of occurences of each possible score in the unit.
/// Example: Index of 0 would contain the number of times a 0 was scored. 
/// </returns>
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

/// 
/// FUNCTION BELOW DOES NOT DO WHAT WE THINK IT DOES, WE WILL NEED TO REWORK THIS
/// I AM GOING TO TRY TO MEET WITH LUKE TO SEE HOW BEST TO APPROACH THIS

/// <summary>
/// takes the score counts, which are sorted individually.
/// Then counts the frequency of each score as it goes through them up to the top score
/// then takes the frequency and divides it by the total number of scores and multiplies into a percentage
/// </summary>
/// <param name="unitScores">The unit scores.</param>
/// <param name="scoreCounts">The score counts.</param>
/// <returns></returns>
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
/// 
/// <typeparam name="T"> 
/// T generic represents score member currently
/// </typeparam>
/// 
/// <typeparam name="K">
///  K generic represents a key member
/// </typeparam>
/// 
/// <param name="studentKey">
/// A key containing aditional information of the student
/// </param>
/// 
/// <param name="studentScores">
/// Assumed Vector of Student's scores
/// </param>
/// 
/// <returns>
/// Overall percentage grade of given score for a single student. 
/// Returns as a percentage value rounded to two decimal places 
/// </returns>
/// 
/// <author> Austin Youngren
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
        studMaxScore += mScore;
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
/// 
/// <typeparam name="T"> 
/// T generic represents score member currently
/// </typeparam>
/// 
/// <typeparam name="K">
///  K generic represents a key member
/// </typeparam>
/// 
/// <param name="studentKey">
/// A key containing aditional information of the student
/// </param>
/// 
/// <param name="studentScores">
/// Assumed Vector of Student's scores
/// </param>
/// 
/// <returns>
/// Returns overall weighted grade of given scores.
/// Returned as a percentage value rounded to two decimals
/// </returns>
template <typename T, typename K>
double studWeightPerc(K studentKey, vector<T> studentScores)
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

/// <summary>
/// Counts any vector using generic type T and returns int
/// </summary>
/// 
/// <typeparam name="T">
/// Generic place holder
/// </typeparam>
/// 
/// <param name="vec">
///  Data set as score values
/// </param>
/// 
/// <returns>
/// size of the vector - int
/// </returns>
/// 
/// <author> Kenneth Wallin
template <class T>
int countVector(vector<T> vec)
{
	int count = 0;
	for (T stuff: vec)
	{
		count++;
	}
	return count;
}

/// <summary>
/// Returns true if the passed score list is even other wise it will return false for odd
/// </summary>
/// 
/// <param name="vec">
/// Data set as score values
/// </param>
/// 
/// <returns> 
/// true or false - bool
/// </returns>
/// 
/// <author> Kenneth Wallin
bool isEven(vector<double> vec)
{
	if (countVector(vec) % 2 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/// <summary>
/// Returns median of data set Requires #include <algorithm>
/// </summary>
/// 
/// <param name="vec">
///  Data set as score values
/// </param>
/// 
/// <returns>
/// Median of Scores of sent data set - double
/// </returns>
/// 
/// <author> Kenneth Wallin
/// <editor> Austin Youngren 
double median(vector<double> vec)
{
	int count = countVector(vec);
	sort(vec.begin(), vec.end());
    double median;
	if (isEven(vec))
	{
		median = ((vec[(count / 2) - 1] + vec[count / 2]) / 2);
        return median;
	}
	else
	{
        median = vec[((count + 1) / 2) - 1];
        return median;
	}
}

/// <summary>
/// returns mean of data set
/// </summary>
/// 
/// <param name="vec">
/// Data set as score values
/// </param>
/// 
/// <returns>
/// Mean of Scores of sent data set - double
/// </returns>
/// 
/// <author> Kenneth Wallin
/// <editor> Austin Youngren 
double mean(vector<double> vec)
{
	int count = countVector(vec);
	int total = 0;
    double mean;
	for (double score : vec)
	{
		total += score;
	}
	mean = ((double)total / (double)count);
    return mean;
}

/// <summary>
/// Converts the data set into their percentage values.
/// Then, finds the median of the percentages.
///  #include <algorithm> for sorting
/// </summary>
/// 
/// <param name="vec"> 
/// Data set as score values
/// </param>
/// 
/// <returns>
/// Median of Score Percentages of sent data set 
/// rounded to two decimals - double 
/// </returns>
/// 
/// <authors> Austin Youngren & Kenneth Walin 
template <class K>
double medianPerc(K scoreKey, vector<double> vec)
{
    int count = countVector(vec);
    double temp;
    vector<double> scorePercs;
    for (int i = 0; i < scorePercs; i++)
    {
        if (scoreKey.getMaxPoints.at(i) != 0)
        {
            temp = ((scorePercs.at(i) / scoreKey.getMaxPoints.at(i) * 100);
            temp = round(temp * 100.0) / 100.0;
            scorePercs.push_back(temp);
        }
    }
    sort(scorePercs.begin(), scorePercs.end());

    double median;
    if (isEven(scorePercs))
    {
        median = ((scorePercs[(count / 2) - 1] + scorePercs[count / 2]) / 2);
        return median;
    }
    else
    {
        median = vec[((count + 1) / 2) - 1];
        return median;
    }
}

/// <summary>
/// Finds the mean of data set of vector 
/// data set values as a percentage
/// </summary>
/// 
/// <param name="vec">
/// Data set as score values 
/// </param>
/// 
/// <returns>
///  Mean of Score Percentages of sent data set 
/// rounded to two decimals - double 
/// </returns>
/// 
/// <author> Austin Youngren & Kenneth Wallin
template <class K>
double meanPerc(K scoreKey, vector<double> vec)
{
    int count;
    int total = 0;
    double temp;
    vector<double> scorePercs;
    for (int i = 0; i < scorePercs; i++)
    {
        if (scoreKey.getMaxScore.at(i) != 0)
        {
            temp = ((scorePercs.at(i) / scoreKey.getMaxScore.at(i)) * 100);
            temp = round(temp * 100.0) / 100.0;
            scorePercs.push_back(temp);
        }
    }

    double mean;
    count = countVector(scorePercs);
    for (double perc : vec)
    {
        total += score;
    }
    mean = ((double)total / count);
    return mean;
}