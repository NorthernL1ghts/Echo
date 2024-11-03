// MathF.h
#pragma once

#include <glm/glm.hpp>
#include <iostream>
#include <cmath>

namespace Echo {

    class MathF {
    public:
        // Calculates the wave speed for a SAW
        static float CalculateWaveSpeed(float frequency, float wavelength);

        // Calculates the wavelength of a SAW
        static float CalculateWavelength(float waveSpeed, float frequency);

        // Calculates the frequency of a SAW
        static float CalculateFrequency(float waveSpeed, float wavelength);

        // Calculates the pitch of a wave
        static float CalculatePitch(float frequency);

        // Prints the properties related to SAW
        static void PrintSAWProperties(float frequency, float wavelength, float waveSpeed);

        class Waves {
        public:
            // Computes sine element-wise
            static float Sin(float x);

            // Computes cosine element-wise
            static float Cos(float x);

            // Computes tangent element-wise
            static float Tan(float x);

            // Computes exponentiation element-wise
            static float Exp(float x);

            // Computes natural logarithm element-wise
            static float Log(float x);

            // Computes square root element-wise
            static float Sqrt(float x);

            // Computes x raised to the power of y element-wise
            static float Power(float x, float y);

            // Computes arctan(y / x) element-wise
            static float Arctan2(float y, float x);

            // Computes the Gaussian function element-wise
            static float Gaussian(float x, float mean, float std);

            // Computes the sawtooth waveform element-wise
            static float Sawtooth(float x, float width = 1.0f);

            // Computes the square waveform element-wise
            static float SquareWave(float x, float period = 2.0f * 3.14159265f);

            // Computes the triangular waveform element-wise
            static float TriangularWave(float x, float width = 1.0f);
        };
    };

} // namespace Echo
