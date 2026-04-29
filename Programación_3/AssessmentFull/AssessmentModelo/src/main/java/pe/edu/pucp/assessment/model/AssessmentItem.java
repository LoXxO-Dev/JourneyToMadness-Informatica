package pe.edu.pucp.assessment.model;

public class AssessmentItem {
    private Integer id;
    private Question question;
    private double score;

    public AssessmentItem() {}

    public AssessmentItem(Question question, double score) {
        this.question = question;
        this.score = score;
    }

    public Integer getId() { return id; }
    public void setId(Integer id) { this.id = id; }

    public Question getQuestion() { return question; }
    public void setQuestion(Question question) { this.question = question; }

    public double getScore() { return score; }
    public void setScore(double score) { this.score = score; }

    @Override
    public String toString() {
        return "Item[" + id + "] score=" + score + " -> " + question;
    }
}
