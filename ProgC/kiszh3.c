#include <stdio.h>
#include <stdbool.h>

//egy ember BMI indexe
typedef struct BMI {
	double tomeg, magassag;
}BMI;

//megnézi hogy egy ember átlagos e
bool isAtlagos(BMI);

//beolvassa egy ember adatait
BMI beEmber();

//kiírja egy ember adatait
void kiirEmber(BMI);

//main
void kiszh3() {
	kiirEmber(beEmber());
}

void kiirEmber(BMI ember) {
	printf("Tomeg: %g, Magassag: %g", ember.tomeg, ember.magassag);
}

BMI beEmber() {
	BMI ember;
	scanf("%lf %lf", &ember.tomeg, &ember.magassag);
	return ember;
}

bool isAtlagos(BMI ember) {
	if ((ember.tomeg / ember.magassag / ember.magassag) > 18.5 && (ember.tomeg / ember.magassag / ember.magassag) < 25.0)return true;
	return false;
}