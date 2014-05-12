#ifndef GeneticAlgorithm_h__guard
#define GeneticAlgorithm_h__guard

#include "OrganismController.h"

class GeneticAlgorithm {
public:
	OrganismController* nextOrganism();
	
	void evaluated(OrganismController* organism, double fitness);
	
};


#endif