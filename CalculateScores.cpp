# include <iostream>
# include <vector>
using namespace std;

double ScoreSum(vector<double> listScore, int listScoreLen);
double ScoreAverage(vector<double> listScore, int listScoreLen);

int main () {

    int scoreCounter = 0;
    cout << "Enter your score counter: " << endl;
    cin >> scoreCounter;

    vector<double> scoreList;
    int scoreListLen = 0;

    for (int i = 1; i <= scoreCounter; i++) {
        double score;
        cout << "Enter " << i << " score: " << endl;
        cin >> score;

        if (score > 20 || score < 0) {
            i--;
            cout << score << " is'nt valid score. The score must be between 0 and 20." << endl;
        } else {
            scoreList.push_back(score);
            scoreListLen++;
        }
    }

    double sumResult = ScoreSum(scoreList, scoreListLen);
    double averageResult = ScoreAverage(scoreList, scoreListLen);
    cout << "\n__________________________\n" 
    << "Score sum: " 
    << sumResult 
    << "\n" 
    << "Score average: " 
    << averageResult << endl;

    return 0;
}

double ScoreSum(vector<double> listScore, int listScoreLen) {

    double scoreSum = 0;

    for (int i = 0; i < listScoreLen; i++) {
        scoreSum += listScore[i];
    }

    return scoreSum;
}

double ScoreAverage(vector<double> listScore, int listScoreLen) {

    double scoreAverage = 0;

    for (int i = 0; i < listScoreLen; i++) {
        scoreAverage += listScore[i];
    }
    
    scoreAverage /= listScoreLen;

    return scoreAverage;
}
