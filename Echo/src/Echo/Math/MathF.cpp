// MathF.cpp
#include "MathF.h"

namespace Echo {

    // Calculates the wave speed for a SAW
    float MathF::CalculateWaveSpeed(float frequency, float wavelength) {
        if (wavelength == 0) {
            std::cerr << "Wavelength cannot be zero." << std::endl;
            return 0.0f; // Avoid division by zero
        }
        return frequency * wavelength;
    }

    // Calculates the wavelength of a SAW
    float MathF::CalculateWavelength(float waveSpeed, float frequency) {
        if (frequency == 0) {
            std::cerr << "Frequency cannot be zero." << std::endl;
            return 0.0f; // Avoid division by zero
        }
        return waveSpeed / frequency;
    }

    // Calculates the frequency of a SAW
    float MathF::CalculateFrequency(float waveSpeed, float wavelength) {
        if (wavelength == 0) {
            std::cerr << "Wavelength cannot be zero." << std::endl;
            return 0.0f; // Avoid division by zero
        }
        return waveSpeed / wavelength;
    }

    // Calculates the pitch of a wave based on frequency
    float MathF::CalculatePitch(float frequency) {
        // Pitch can be calculated in various ways; this is a simple placeholder.
        return 20.0f * log10(frequency); // Example: Using logarithmic scale
    }

    // Prints the properties related to SAW
    void MathF::PrintSAWProperties(float frequency, float wavelength, float waveSpeed) {
        std::cout << "Surface Acoustic Wave Properties:" << std::endl;
        std::cout << "Frequency: " << frequency << " Hz" << std::endl;
        std::cout << "Wavelength: " << wavelength << " m" << std::endl;
        std::cout << "Wave Speed: " << waveSpeed << " m/s" << std::endl;
    }

    // Wave calculations
    float MathF::Waves::Sin(float x) {
        return std::sin(x);
    }

    float MathF::Waves::Cos(float x) {
        return std::cos(x);
    }

    float MathF::Waves::Tan(float x) {
        return std::tan(x);
    }

    float MathF::Waves::Exp(float x) {
        return std::exp(x);
    }

    float MathF::Waves::Log(float x) {
        return std::log(x);
    }

    float MathF::Waves::Sqrt(float x) {
        return std::sqrt(x);
    }

    float MathF::Waves::Power(float x, float y) {
        return std::pow(x, y);
    }

    float MathF::Waves::Arctan2(float y, float x) {
        return std::atan2(y, x);
    }

    float MathF::Waves::Gaussian(float x, float mean, float std) {
        return std::exp(-0.5f * std::pow((x - mean) / std, 2)) / (std * std::sqrt(2 * 3.14159265f));
    }

    float MathF::Waves::Sawtooth(float x, float width) {
        return 2.0f * (x / width - std::floor(0.5f + x / width));
    }

    float MathF::Waves::SquareWave(float x, float period) {
        return 0.5f * (1 + std::signbit(MathF::Waves::Sin(x / (period / 2.0f * 3.14159265f))));
    }

    float MathF::Waves::TriangularWave(float x, float width) {
        return 2.0f * std::abs(MathF::Waves::Sawtooth(x / (width / 2.0f))) - 1.0f;
    }

} // namespace Echo
