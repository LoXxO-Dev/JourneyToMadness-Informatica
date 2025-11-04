//
// Created by User on 4/11/2025.
//

#ifndef FLOTA_HPP
#define FLOTA_HPP
#include "DroneEstacionamiento.hpp"
#include "DroneSemaforo.hpp"
#include "DroneVelocidad.hpp"
#include "utils.hpp"


class Flota {
private:
    DroneVelocidad drones_velocidad[20];
    DroneSemaforo drones_semaforo[20];
    DroneEstacionamiento drones_estacionamientos[20];
    int n_drones_velocidad;
    int n_drones_semaforo;
    int n_drones_estacionamiento;

public:
    Flota();
    void cargar_drones(ifstream &arch, char *tipo_dron);
    void actualizarDronesInfracciones(ifstream &arch,double &multa);
    int buscarDroneVelocidad(const char *id);
    int buscarDroneSemaforo(const char *id);
    int buscarDroneEstacionamiento(const char *id);
    void imprimir( ofstream &arch);
    int get_n_drones_velocidad() const;

    void set_n_drones_velocidad(int n_drones_velocidad);

    int get_n_drones_semaforo() const;

    void set_n_drones_semaforo(int n_drones_semaforo);

    int get_n_drones_estacionamiento() const;

    void set_n_drones_estacionamiento(int n_drones_estacionamiento);
};



#endif //FLOTA_HPP
