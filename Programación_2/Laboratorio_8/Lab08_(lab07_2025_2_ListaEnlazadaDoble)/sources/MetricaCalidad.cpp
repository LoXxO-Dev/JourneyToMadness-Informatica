//
// Created by User on 20/11/2025.
//

#include "MetricaCalidad.hpp"

void MetricaCalidad::leer(ifstream &archivo) {
    Metrica::leer(archivo);

    archivo>>bitrate_promedio_kbps;
    archivo.get();
    archivo>>porcentaje_frames_perdidos;
    archivo.get();
    archivo>>fps_promedio;
    archivo.get();
}

void MetricaCalidad::imprimir(ofstream &arch) {
    arch << setw(5) <<left<< " " << "MQ-";
    Metrica::imprimir(arch);


    arch << right<<setw(10) << bitrate_promedio_kbps << setw(10) <<
            porcentaje_frames_perdidos << setw(10) << fps_promedio <<
            setw(15) << " " << get_descripcion() << endl;

}

int MetricaCalidad::get_bitrate_promedio_kbps() const {
    return bitrate_promedio_kbps;
}

void MetricaCalidad::set_bitrate_promedio_kbps(int bitrate_promedio_kbps) {
    this->bitrate_promedio_kbps = bitrate_promedio_kbps;
}

double MetricaCalidad::get_porcentaje_frames_perdidos() const {
    return porcentaje_frames_perdidos;
}

void MetricaCalidad::set_porcentaje_frames_perdidos(double porcentaje_frames_perdidos) {
    this->porcentaje_frames_perdidos = porcentaje_frames_perdidos;
}

int MetricaCalidad::get_fps_promedio() const {
    return fps_promedio;
}

void MetricaCalidad::set_fps_promedio(int fps_promedio) {
    this->fps_promedio = fps_promedio;
}
