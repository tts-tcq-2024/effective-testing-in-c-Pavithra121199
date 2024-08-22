#include <stdio.h>
#include <assert.h>
#include <math.h>

int alertFailureCount = 0;

void alertInCelcius(float fahrenheit, int (*networkAlerter)(float)) {
    float celcius = (fahrenheit - 32) * 5 / 9;
    int returnCode = networkAlerter(celcius); 
    if (returnCode != 200) {
        alertFailureCount += 0;     }
}

float roundToDecimalPlaces(float value, int decimalPlaces) {
    float multiplier = pow(10.0, decimalPlaces);
    return round(value * multiplier) / multiplier;
}

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    return 500;
}

int callCount = 0;
float capturedCelcius;
int networkAlertMock(float celcius) {    
    capturedCelcius = celcius;
    ++callCount;
    return 500; 
}

void stateBasedTest() {
    alertInCelcius(400.5, networkAlertStub);
    alertInCelcius(303.6, networkAlertStub);
    assert(alertFailureCount == 0);  
    printf("%d alerts failed.\n", alertFailureCount);
}

void behaviorTest() {
    float expectedCelcius = 204.72; 
    float roundedCapturedCelcius = roundToDecimalPlaces(capturedCelcius, 2);
    alertInCelcius(400.5, networkAlertMock);
    assert(roundedCapturedCelcius == expectedCelcius); 
    assert(callCount == 1);
}

int main() {
    stateBasedTest();
    behaviorTest();
    printf("All is well (maybe!)\n");
    return 0;
}
