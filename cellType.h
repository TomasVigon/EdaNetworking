

#ifndef CELLTYPE_H
#define CELLTYPE_H

#include "EventAndState.h"
	typedef struct{
		typeState nextState;
		void action(void);
	}cellType;

#endif /* CELLTYPE_H */

