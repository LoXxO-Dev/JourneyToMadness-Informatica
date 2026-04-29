package pe.edu.pucp.assessment.model;

import java.util.ArrayList;
import java.util.List;

public class Question {
    private Integer id;
    private String prompt;
    private TipoQuestion tipo;
    private List<String> availableOptions;
    // Para SingleChoice: indice 1-based de la opcion correcta
    private Integer correctOption;
    // Para MultipleChoice: lista de indices 1-based de opciones correctas
    private List<Integer> correctOptions;

    public Question() {
        this.availableOptions = new ArrayList<>();
        this.correctOptions = new ArrayList<>();
    }

    public Integer getId() { return id; }
    public void setId(Integer id) { this.id = id; }

    public String getPrompt() { return prompt; }
    public void setPrompt(String prompt) { this.prompt = prompt; }

    public TipoQuestion getTipo() { return tipo; }
    public void setTipo(TipoQuestion tipo) { this.tipo = tipo; }

    public List<String> getAvailableOptions() { return availableOptions; }
    public void setAvailableOptions(List<String> availableOptions) { this.availableOptions = availableOptions; }

    public Integer getCorrectOption() { return correctOption; }
    public void setCorrectOption(Integer correctOption) { this.correctOption = correctOption; }

    public List<Integer> getCorrectOptions() { return correctOptions; }
    public void setCorrectOptions(List<Integer> correctOptions) { this.correctOptions = correctOptions; }

    @Override
    public String toString() {
        return "[" + id + "] (" + tipo + ") " + prompt;
    }
}
