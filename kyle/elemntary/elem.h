typedef char* CellType;
typedef struct Generations Generations;

Generations* nextGen(Generations* g);
int getNeighborsCount(Generations* g, int cell_pos);
void printStuff(Generations* g);
Generations* newGen(char* r, int w);
Generations* randInit(Generations* g);
Generations* centerInit(Generations* g);
