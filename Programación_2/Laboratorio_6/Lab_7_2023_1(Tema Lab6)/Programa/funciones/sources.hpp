//
// Created by User on 28/10/2025.
//

#ifndef SOURCES_HPP
#define SOURCES_HPP
#include "utils.hpp"
#include "alumno.hpp"
#include "alumnonota.hpp"
void cargaalumno(alumno *lalumnos);
void carganotas(alumnonota *lnotas) ;
void actualizanotas( alumno *lalumnos,alumnonota* lnotas) ;
int buscarAlumno(alumno *lalumnos,int  codigo) ;
  void   imprimealummno( alumno *lalumnos) ;
#endif //SOURCES_HPP
