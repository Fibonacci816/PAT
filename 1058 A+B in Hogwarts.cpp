#include <stdio.h>
#define SICKLE 17
#define KNUT 29

int main()
{
	int Galleon1, Sickle1, Knut1, Galleon2, Sickle2, Knut2;
	scanf("%d.%d.%d", &Galleon1, &Sickle1, &Knut1);
	scanf("%d.%d.%d", &Galleon2, &Sickle2, &Knut2);
    Sickle1 += (Knut1+Knut2) / KNUT;
	Knut1 = (Knut1+Knut2) % KNUT;
	Galleon1 += (Sickle1+Sickle2) / SICKLE;
	Sickle1 = (Sickle1+Sickle2) % SICKLE;
	Galleon1 = Galleon1 + Galleon2;
	printf("%d.%d.%d", Galleon1, Sickle1, Knut1);
	return 0;
}
