# AssessmentFull - Laboratorio DB + Capas

## Arquitectura por capas

```
AssessmentApp          → Programa de prueba (Program.java)
    ↓ usa
AssessmentNegocio      → Lógica de negocio (BO interfaces + impl con transacciones)
    ↓ usa
AssessmentPersistencia → Acceso a datos (DAO interfaces + implementaciones MySQL)
    ↓ usa
AssessmentDBManager    → Conexión Singleton a MySQL (DBManager, DBFactoryProvider)
AssessmentModelo       → Clases del dominio (Teacher, Question, Assessment, ...)
```

## Pasos para configurar antes del laboratorio

### 1. Encriptar el password de BD
Ejecutar `Crypto.main()` con tu password real para obtener el valor encriptado:
```
password en texto: labs1inf3020261
```
Copiar el resultado encriptado en `db.properties`.

### 2. Configurar db.properties
Editar `AssessmentDBManager/src/main/resources/db.properties`:
```properties
db.host=<TU_ENDPOINT_RDS_AWS>
db.puerto=3306
db.esquema=assessmentlabs
db.usuario=admin
db.password=<RESULTADO_DE_Crypto.encrypt("labs1inf3020261")>
db.tipo=MySQL
```

### 3. Ejecutar script SQL
Correr `script_db.sql` en MySQL Workbench contra tu instancia RDS.

### 4. Compilar y ejecutar
En IntelliJ: abrir carpeta `AssessmentFull` → Maven detecta el pom.xml raíz.
Ejecutar `Program.main()`.

## Patrones aplicados

| Patrón    | Dónde se aplica                                    |
|-----------|----------------------------------------------------|
| Singleton | `MySQLDBManager.getInstance()` + `DBFactoryProvider.getManager()` |
| DAO       | `TeacherDAO`, `QuestionDAO`, `AssessmentDAO` + implementaciones MySQL |
| Factory   | `DBManagerFactory` → `MySQLDBManagerFactory`       |

## Manejo de transacciones

Cada método en las clases `*BOImpl` sigue el patrón:
```java
connection.setAutoCommit(false);
// ... operaciones DAO pasando la misma conexion ...
connection.commit();
// en catch: connection.rollback();
// en finally: connection.close();
```

## Diagrama de dependencias entre módulos

```
AssessmentModelo  ←──────────────────────────┐
AssessmentDBManager ←──────────────────────  │
AssessmentPersistencia (depende de los dos) ←─┤
AssessmentNegocio (depende de Persistencia) ←─┤
AssessmentApp (depende de Negocio)            │
```
