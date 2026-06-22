import java.util.*;


public class TestFinalExam {
    public static void main(String[] args) {
        FinalExam exam = new FinalExam(50, 7); // 50 questions, 7 missed

        System.out.println("Final Exam Score: " + exam.getScore());
        System.out.println("Grade: " + exam.getGrade());
        System.out.println("Each question worth: " + exam.getPointsEach());
        System.out.println("Questions missed: " + exam.getQuestionsMissed());
    }
}



class GradedActivity {
    protected double score;

    public void setScore(double score) {
        this.score = score;
    }

    public double getScore() {
        return score;
    }

    public char getGrade() {
        if (score >= 90)
            return 'A';
        else if (score >= 80)
            return 'B';
        else if (score >= 70)
            return 'C';
        else if (score >= 60)
            return 'D';
        else
            return 'F';
    }
}


class FinalExam extends GradedActivity {
    private int totalQuestions;
    private int questionsMissed;
    private double pointsEach;

    public FinalExam(int totalQuestions, int questionsMissed) {
        this.totalQuestions = totalQuestions;
        this.questionsMissed = questionsMissed;
        this.pointsEach = 100.0 / totalQuestions;

        double numericScore = 100.0 - (questionsMissed * pointsEach);
        setScore(numericScore); // Use method from superclass
    }


    public int getQuestionsMissed() {
        return questionsMissed;
    }

    public double getPointsEach() {
        return pointsEach;
    }
}


