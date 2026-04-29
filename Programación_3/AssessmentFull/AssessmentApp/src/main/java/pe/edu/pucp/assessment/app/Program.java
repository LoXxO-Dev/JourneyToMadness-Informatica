package pe.edu.pucp.assessment.app;

import pe.edu.pucp.assessment.bo.AssessmentBO;
import pe.edu.pucp.assessment.bo.QuestionBO;
import pe.edu.pucp.assessment.bo.TeacherBO;
import pe.edu.pucp.assessment.bo.impl.AssessmentBOImpl;
import pe.edu.pucp.assessment.bo.impl.QuestionBOImpl;
import pe.edu.pucp.assessment.bo.impl.TeacherBOImpl;
import pe.edu.pucp.assessment.model.Assessment;
import pe.edu.pucp.assessment.model.AssessmentItem;
import pe.edu.pucp.assessment.model.Question;
import pe.edu.pucp.assessment.model.Teacher;
import pe.edu.pucp.assessment.model.TipoQuestion;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class Program {
    public static void main(String[] args) {
        TeacherBO teacherBO = new TeacherBOImpl();
        QuestionBO questionBO = new QuestionBOImpl();
        AssessmentBO assessmentBO = new AssessmentBOImpl();

        Integer idTeacher1 = null;
        Integer idTeacher2 = null;
        Integer idQuestion1 = null;
        Integer idQuestion2 = null;
        Integer idQuestion3 = null;
        Integer idAssessment = null;

        try {
            // ===== TEACHERS =====
            System.out.println("=== Creando Teachers ===");
            Teacher teacher1 = new Teacher("11111111", "Freddy", "Paz");
            idTeacher1 = teacherBO.insertar(teacher1);
            System.out.println("Teacher creado: " + teacherBO.obtenerPorId(idTeacher1));

            Teacher teacher2 = new Teacher("22222222", "Jose", "Corcuera");
            idTeacher2 = teacherBO.insertar(teacher2);
            System.out.println("Teacher creado: " + teacherBO.obtenerPorId(idTeacher2));

            teacher1.setFirstName("Freddy Andres");
            teacherBO.actualizar(teacher1);
            System.out.println("Teacher actualizado: " + teacherBO.obtenerPorId(idTeacher1));

            System.out.println("Lista de teachers: " + teacherBO.listar().size() + " registros");

            // ===== QUESTIONS =====
            System.out.println("\n=== Creando Questions ===");

            // Single choice
            Question q1 = new Question();
            q1.setPrompt("1 + 1 = ?");
            q1.setTipo(TipoQuestion.SINGLE_CHOICE);
            q1.setAvailableOptions(List.of("1", "2", "11", "0"));
            q1.setCorrectOption(2);
            idQuestion1 = questionBO.insertar(q1);
            System.out.println("Question creada: " + questionBO.obtenerPorId(idQuestion1));

            // Single choice
            Question q2 = new Question();
            q2.setPrompt("2 * 4 = ?");
            q2.setTipo(TipoQuestion.SINGLE_CHOICE);
            q2.setAvailableOptions(List.of("24", "2", "8", "16"));
            q2.setCorrectOption(3);
            idQuestion2 = questionBO.insertar(q2);
            System.out.println("Question creada: " + questionBO.obtenerPorId(idQuestion2));

            // Multiple choice
            Question q3 = new Question();
            q3.setPrompt("¿Cuáles son planetas del sistema solar?");
            q3.setTipo(TipoQuestion.MULTIPLE_CHOICE);
            q3.setAvailableOptions(List.of("Tierra", "Luna", "Marte", "Europa"));
            q3.setCorrectOptions(List.of(1, 3));
            idQuestion3 = questionBO.insertar(q3);
            System.out.println("Question creada: " + questionBO.obtenerPorId(idQuestion3));

            System.out.println("Lista de questions: " + questionBO.listar().size() + " registros");

            // ===== ASSESSMENT =====
            System.out.println("\n=== Creando Assessment ===");

            List<Teacher> teachers = new ArrayList<>();
            teachers.add(teacher1);
            teachers.add(teacher2);

            List<AssessmentItem> items = new ArrayList<>();
            items.add(new AssessmentItem(q1, 3.0));
            items.add(new AssessmentItem(q2, 2.5));
            items.add(new AssessmentItem(q3, 4.5));

            Assessment assessment = new Assessment(120, new Date(), teachers, items);
            idAssessment = assessmentBO.insertar(assessment);
            System.out.println("Assessment creado: " + assessmentBO.obtenerPorId(idAssessment));

            // Actualizar duracion
            assessment.setDurationInMinutes(90);
            assessmentBO.actualizar(assessment);
            System.out.println("Assessment actualizado: " + assessmentBO.obtenerPorId(idAssessment));

            System.out.println("Lista de assessments: " + assessmentBO.listar().size() + " registros");

            System.out.println("\n=== Flujo completado exitosamente ===");

        } catch (Exception e) {
            System.err.println("Error en el flujo: " + e.getMessage());
            e.printStackTrace();
        } finally {
            // ===== LIMPIEZA =====
            System.out.println("\n=== Limpieza de datos de prueba ===");
            try {
                if (idAssessment != null) {
                    assessmentBO.eliminar(idAssessment);
                    System.out.println("Assessment eliminado: " + idAssessment);
                }
                if (idQuestion3 != null) {
                    questionBO.eliminar(idQuestion3);
                    System.out.println("Question3 eliminada: " + idQuestion3);
                }
                if (idQuestion2 != null) {
                    questionBO.eliminar(idQuestion2);
                    System.out.println("Question2 eliminada: " + idQuestion2);
                }
                if (idQuestion1 != null) {
                    questionBO.eliminar(idQuestion1);
                    System.out.println("Question1 eliminada: " + idQuestion1);
                }
                if (idTeacher2 != null) {
                    teacherBO.eliminar(idTeacher2);
                    System.out.println("Teacher2 eliminado: " + idTeacher2);
                }
                if (idTeacher1 != null) {
                    teacherBO.eliminar(idTeacher1);
                    System.out.println("Teacher1 eliminado: " + idTeacher1);
                }
                System.out.println("Limpieza completada.");
            } catch (Exception e) {
                System.err.println("Error en limpieza: " + e.getMessage());
            }
        }
    }
}
