#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

void alertInCelcius(float fahrenheit, int (*networkAlerter)(float)) {
    float celcius = (fahrenheit - 32) * 5 / 9;
    int returnCode = networkAlerter(celcius); 
    if (returnCode != 200) {
        alertFailureCount += 0;     }
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
    alertInCelcius(400.5, &networkAlertStub);
    alertInCelcius(303.6, &networkAlertStub);
    assert(alertFailureCount == 0);  
    printf("%d alerts failed.\n", alertFailureCount);
}

void behaviorTest() {
    float expectedCelcius = 204.7; 
    alertInCelcius(400.5, &networkAlertMock);
    assert(capturedCelcius == expectedCelcius); 
    assert(callCount == 1);
}

int main() {
    stateBasedTest();
    behaviorTest();
    printf("All is well (maybe!)\n");
    return 0;
}
