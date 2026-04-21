  /*
Name: NAMBATYA BUSHIRAT
Registration Number: 25/U/BIO/01405/PD
*/

#include <stdio.h>

// Function to get grade and grade point from score
void getGrade(int score, char *grade, int *point) {
    if(score >= 80 && score <= 100) { *grade = 'A'; *point = 5; }
    else if(score >= 70)             { *grade = 'B'; *point = 4; }
    else if(score >= 60)             { *grade = 'C'; *point = 3; }
    else if(score >= 50)             { *grade = 'D'; *point = 2; }
    else if(score >= 0)              { *grade = 'F'; *point = 0; }
}

// Function to calculate GPA
float calculateGPA(int points[], int credits[], int n) {
    int i;
    int totalCredits = 0;
    int weightedSum = 0;
    for(i = 0; i < n; i++) {
        weightedSum += points[i] * credits[i];
        totalCredits += credits[i];
    }
    return (float)weightedSum / totalCredits;
}

// Function to get classification from CGPA
void getClassification(float cgpa, char classification[]) {
    if(cgpa >= 4.40) sprintf(classification, "First Class");
    else if(cgpa >= 3.60) sprintf(classification, "Second Class Upper");
    else if(cgpa >= 2.80) sprintf(classification, "Second Class Lower");
    else if(cgpa >= 2.00) sprintf(classification, "Pass");
    else sprintf(classification, "Fail");
}

int main() {
    // Semester I data
    char *sem1Codes[8] = {"TEMB 1101","TEMB 1102","TEMB 1103","TEMB 1104","TEMB 1105","TEMB 1106","TEMB 1107","TEMB 1108"};
    char *sem1Names[8] = {"Fundamentals of Engineering Mathematics","Biochemistry and Medical Physics","Electrical Engineering Science","Mechanics I","Computing I","Mechanical Drawing","Engineering Profession","Functional Anatomy and Physiology I"};
    int sem1Credits[8] = {4,3,3,3,3,3,2,3};
    
    // Semester II data
    char *sem2Codes[8] = {"TEMB 1201","TEMB 1202","TEMB 1203","TEMB 1204","TEMB 1205","TEMB 1206","TEMB 1207","TEMB 1208"};
    char *sem2Names[8] = {"Further Engineering Mathematics","Computing II","Mechatronics Drawing","Fluid Mechanics","Thermodynamics","Workshop Practice","Functional Anatomy and Physiology II","Electronics I"};
    int sem2Credits[8] = {4,3,3,3,3,3,3,3};
    
    int sem1Scores[8], sem2Scores[8];
    char sem1Grades[8], sem2Grades[8];
    int sem1Points[8], sem2Points[8];
    
    int i;
    
    // printf("Enter scores for Semester I (TEMB 1101 to TEMB 1108):\n");
    for(i=0; i<8; i++) {
        // printf("%s: ", sem1Codes[i]);
        scanf("%d", &sem1Scores[i]);
        if(sem1Scores[i] < 0 || sem1Scores[i] > 100) {
            printf("Invalid score entered\n");
            return 0;
        }
        getGrade(sem1Scores[i], &sem1Grades[i], &sem1Points[i]);
    }
    
    // printf("\nEnter scores for Semester II (TEMB 1201 to TEMB 1208):\n");
    for(i=0; i<8; i++) {
       // printf("%s: ", sem2Codes[i]);
        scanf("%d", &sem2Scores[i]);
        if(sem2Scores[i] < 0 || sem2Scores[i] > 100) {
            printf("Invalid score entered\n");
            return 0;
        }
        getGrade(sem2Scores[i], &sem2Grades[i], &sem2Points[i]);
    }
    
    // Calculate GPA
    float gpa1 = calculateGPA(sem1Points, sem1Credits, 8);
    float gpa2 = calculateGPA(sem2Points, sem2Credits, 8);
    
    // Calculate CGPA
    int allPoints[16], allCredits[16];
    for(i=0; i<8; i++) { allPoints[i] = sem1Points[i]; allCredits[i] = sem1Credits[i]; }
    for(i=0; i<8; i++) { allPoints[i+8] = sem2Points[i]; allCredits[i+8] = sem2Credits[i]; }
    float cgpa = calculateGPA(allPoints, allCredits, 16);
    
    char classification[30];
    getClassification(cgpa, classification);
    
    printf("Semester I GPA: %.2f\n", gpa1);
    printf("Semester II GPA: %.2f\n", gpa2);
    printf("\nCGPA: %.2f\n", cgpa);
    printf("Classification: %s\n", classification);
    
    // Display report
    printf("\n--- Academic Report ---\n");
    printf("Semester I:\n");
    // printf("Code\tScore\tGrade\tGP\tCU\tWC\n");
    for(i=0; i<8; i++) {
        printf("%s\t%d\t%c\t%d\t%d\t%d\n", sem1Codes[i], sem1Scores[i], sem1Grades[i], sem1Points[i], sem1Credits[i], sem1Points[i]*sem1Credits[i]);
    }
    printf("Semester I GPA: %.2f\n", gpa1);
    
    printf("\nSemester II:\n");
    // printf("Code\tScore\tGrade\tGP\tCU\tWC\n");
    for(i=0; i<8; i++) {
        printf("%s\t%d\t%c\t%d\t%d\t%d\n", sem2Codes[i], sem2Scores[i], sem2Grades[i], sem2Points[i], sem2Credits[i], sem2Points[i]*sem2Credits[i]);
    }
    printf("Semester II GPA: %.2f\n", gpa2);
    
    
    
    return 0;
}