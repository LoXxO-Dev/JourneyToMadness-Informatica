package pe.edu.pucp.assessment.model;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class Assessment {
    private Integer id;
    private int durationInMinutes;
    private Date startDate;
    private List<Teacher> teachers;
    private List<AssessmentItem> assessmentItems;

    public Assessment() {
        this.teachers = new ArrayList<>();
        this.assessmentItems = new ArrayList<>();
    }

    public Assessment(int durationInMinutes, Date startDate,
                      List<Teacher> teachers, List<AssessmentItem> assessmentItems) {
        this.durationInMinutes = durationInMinutes;
        this.startDate = startDate;
        this.teachers = teachers;
        this.assessmentItems = assessmentItems;
    }

    public Integer getId() { return id; }
    public void setId(Integer id) { this.id = id; }

    public int getDurationInMinutes() { return durationInMinutes; }
    public void setDurationInMinutes(int durationInMinutes) { this.durationInMinutes = durationInMinutes; }

    public Date getStartDate() { return startDate; }
    public void setStartDate(Date startDate) { this.startDate = startDate; }

    public List<Teacher> getTeachers() { return teachers; }
    public void setTeachers(List<Teacher> teachers) { this.teachers = teachers; }

    public List<AssessmentItem> getAssessmentItems() { return assessmentItems; }
    public void setAssessmentItems(List<AssessmentItem> assessmentItems) { this.assessmentItems = assessmentItems; }

    @Override
    public String toString() {
        return "Assessment[" + id + "] duracion=" + durationInMinutes + "min, items=" + assessmentItems.size();
    }
}
