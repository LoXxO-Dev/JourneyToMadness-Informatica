//
// Created by User on 25/11/2025.
//

#ifndef METRICACALIDAD_HPP
#define METRICACALIDAD_HPP


#include "Metrica.hpp"
#include "utils.hpp"
class MetricaCalidad :public Metrica{
private:
    int bitrate_promedio_kbps;
    double porcentaje_frames_perdidos;
    int fps_promedio;

public:

    MetricaCalidad();
    virtual ~MetricaCalidad();
    int obtener_tipo()const;
    void leer(ifstream &arch) override;
    void imprimir(ofstream &arch) override;
    int get_bitrate_promedio_kbps() const;

    void set_bitrate_promedio_kbps(int bitrate_promedio_kbps);

    double get_porcentaje_frames_perdidos() const;

    void set_porcentaje_frames_perdidos(double porcentaje_frames_perdidos);

    int get_fps_promedio() const;

    void set_fps_promedio(int fps_promedio);
};



#endif //METRICACALIDAD_HPP
