-- =================================================================
-- Script SQL - Assessment Labs
-- Base de datos: assessmentlabs
-- Motor: MySQL 8.0.36
-- =================================================================

USE assessmentlabs;

-- -----------------------------------------------------------------
-- Tabla: teacher
-- -----------------------------------------------------------------
CREATE TABLE IF NOT EXISTS teacher (
    id         INT          NOT NULL AUTO_INCREMENT,
    pucp_code  VARCHAR(10)  NOT NULL UNIQUE,
    first_name VARCHAR(100) NOT NULL,
    last_name  VARCHAR(100) NOT NULL,
    PRIMARY KEY (id)
);

-- -----------------------------------------------------------------
-- Tabla: question
-- -----------------------------------------------------------------
CREATE TABLE IF NOT EXISTS question (
    id    INT                              NOT NULL AUTO_INCREMENT,
    prompt TEXT                            NOT NULL,
    tipo  ENUM('SINGLE_CHOICE','MULTIPLE_CHOICE') NOT NULL,
    PRIMARY KEY (id)
);

-- -----------------------------------------------------------------
-- Tabla: question_option  (opciones disponibles de cada pregunta)
-- -----------------------------------------------------------------
CREATE TABLE IF NOT EXISTS question_option (
    id             INT          NOT NULL AUTO_INCREMENT,
    question_id    INT          NOT NULL,
    numero_opcion  INT          NOT NULL,
    descripcion    VARCHAR(500) NOT NULL,
    PRIMARY KEY (id),
    FOREIGN KEY (question_id) REFERENCES question(id)
);

-- -----------------------------------------------------------------
-- Tabla: question_answer  (respuestas correctas de cada pregunta)
-- -----------------------------------------------------------------
CREATE TABLE IF NOT EXISTS question_answer (
    id            INT NOT NULL AUTO_INCREMENT,
    question_id   INT NOT NULL,
    numero_opcion INT NOT NULL,
    PRIMARY KEY (id),
    FOREIGN KEY (question_id) REFERENCES question(id)
);

-- -----------------------------------------------------------------
-- Tabla: assessment
-- -----------------------------------------------------------------
CREATE TABLE IF NOT EXISTS assessment (
    id                   INT      NOT NULL AUTO_INCREMENT,
    duration_in_minutes  INT      NOT NULL,
    start_date           DATETIME NOT NULL,
    PRIMARY KEY (id)
);

-- -----------------------------------------------------------------
-- Tabla: assessment_teacher  (relacion N:N assessment-teacher)
-- -----------------------------------------------------------------
CREATE TABLE IF NOT EXISTS assessment_teacher (
    assessment_id INT NOT NULL,
    teacher_id    INT NOT NULL,
    PRIMARY KEY (assessment_id, teacher_id),
    FOREIGN KEY (assessment_id) REFERENCES assessment(id),
    FOREIGN KEY (teacher_id)    REFERENCES teacher(id)
);

-- -----------------------------------------------------------------
-- Tabla: assessment_item  (preguntas dentro de un assessment con puntaje)
-- -----------------------------------------------------------------
CREATE TABLE IF NOT EXISTS assessment_item (
    id            INT    NOT NULL AUTO_INCREMENT,
    assessment_id INT    NOT NULL,
    question_id   INT    NOT NULL,
    score         DOUBLE NOT NULL,
    PRIMARY KEY (id),
    FOREIGN KEY (assessment_id) REFERENCES assessment(id),
    FOREIGN KEY (question_id)   REFERENCES question(id)
);
