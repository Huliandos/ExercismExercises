#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> roundedScores {};
    for(double score : student_scores)
        roundedScores.push_back((int)score);
    return roundedScores;
}


// Count the number of failing students out of the group provided.
// scores lower than or equal to 40 fail
int count_failed_students(std::vector<int> student_scores) {
    int failedStudents {0};
    for(int score : student_scores)
    {
        if(score <= 40)
            failedStudents++;
    }
    return failedStudents;
}

// Determine how many of the provided student scores were 'the best' based on the provided threshold.
std::vector<int> above_threshold(std::vector<int> student_scores, int threshold) {
    std::vector<int> bestStudentScores {};
    for(int score : student_scores)
    {
        if(score >= threshold)
            bestStudentScores.push_back(score);
    }
    return bestStudentScores;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    int gradeRange = (highest_score - 40) / 4;
    return {41, 40+gradeRange+1, 40+gradeRange*2+1, 40+gradeRange*3+1};;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::vector<std::string> scoreboard {};
    for(int i=0; i<student_scores.size(); i++)
    {
        scoreboard.push_back(std::to_string(i+1) + ". " + student_names[i] + ": " + std::to_string(student_scores[i]));
    }
    return scoreboard;
}

// Create a string that contains the name of the first student to make a perfect score on the exam.
std::string perfect_score(std::vector<int> student_scores, std::vector<std::string> student_names) {
    for(int i=0; i<student_scores.size(); i++)
    {
        if(student_scores[i] == 100)
            return student_names[i];
    }
    return "";
}
