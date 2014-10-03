#include "Monokrom.h"
#define DrevA 'A:'
#define DrevB 'B:'



void StoreData(Spectrum Data, int k);
void FetchData(Spectrum Data);
void ShowDir(void);
void PrintScanList(void);
void SaveScanList(void);
void RetrieveScanList(void);
void ShowScanPlan(bool exit);
void WriteLogFile(void);

void ChangeScanList(void);