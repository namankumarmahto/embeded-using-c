#include <stdio.h>

/* Union for raw sensor data */
union RawValue {
    unsigned char  raw8;
    unsigned short raw12;
    unsigned int   raw24;
    unsigned long  raw28;
};

/* Structure for sensor */
struct Sensor {
    char name[20];
    int resolution;       // 8, 12, 24, 28
    union RawValue raw;
    float calibrated;
    float res_factor;
    float offset;
};

int main() {

    struct Sensor sensors[10] = {

        {"TEMP",     12, .raw.raw12 = 1500, 0.01f,  -40.0f},
        {"PRESSURE", 24, .raw.raw24 = 800000, 0.001f, 0.0f},
        {"HUMIDITY",  8, .raw.raw8  = 200,   0.5f,    0.0f},
        {"GAS",      28, .raw.raw28 = 12000000, 0.0001f, 1.5f},
        {"LIGHT",     12, .raw.raw12 = 2048,  0.02f,  0.0f},
        {"SOUND",      8, .raw.raw8  = 180,   1.0f,   0.0f},
        {"VIBRATION", 24, .raw.raw24 = 500000,0.005f, 0.0f},
        {"CO2",       28, .raw.raw28 = 9000000,0.0002f,2.0f},
        {"ALTITUDE",  12, .raw.raw12 = 3000,  0.1f,   -10.0f},
        {"SPEED",      8, .raw.raw8  = 120,   1.2f,   0.0f}
    };

    int i;

    for (i = 0; i < 10; i++) {

        switch (sensors[i].resolution) {

            case 8:
                sensors[i].calibrated =
                    sensors[i].raw.raw8 * sensors[i].res_factor + sensors[i].offset;
                break;

            case 12:
                sensors[i].calibrated =
                    sensors[i].raw.raw12 * sensors[i].res_factor + sensors[i].offset;
                break;

            case 24:
                sensors[i].calibrated =
                    sensors[i].raw.raw24 * sensors[i].res_factor + sensors[i].offset;
                break;

            case 28:
                sensors[i].calibrated =
                    sensors[i].raw.raw28 * sensors[i].res_factor + sensors[i].offset;
                break;
        }
    }

    /* Display results */
    printf("Predefined Sensor Data\n");
    printf("----------------------\n");

    for (i = 0; i < 10; i++) {
        printf("\nSensor Name : %s", sensors[i].name);
        printf("\nResolution  : %d-bit", sensors[i].resolution);
        printf("\nCalibrated Value : %.2f\n", sensors[i].calibrated);
    }

    return 0;
}
