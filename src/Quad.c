#include <stdlib.h>
#include <string.h>


#include "Quad.h"


////////////////////////////////
// Constructors & destructors //
////////////////////////////////


Quad_Node *Quad_Node_new(){
	Quad_Node *quad_ptr = malloc( sizeof(Quad_Node) );

	quad_ptr->op = QUAD_OP_UNKNOWN;

	quad_ptr->arg_1_type = QUAD_ADDR_TYPE_EMPTY;
	quad_ptr->arg_2_type = QUAD_ADDR_TYPE_EMPTY;
	quad_ptr->result_type = QUAD_ADDR_TYPE_EMPTY;

	memset( &(quad_ptr->arg_1), 0, sizeof(Quad_Addr) );
	memset( &(quad_ptr->arg_2), 0, sizeof(Quad_Addr) );
	memset( &(quad_ptr->result), 0, sizeof(Quad_Addr) );

	quad_ptr->next = NULL;
	quad_ptr->previous = NULL;
}

void Quad_Node_destroy(Quad_Node *quad_ptr){
	free(quad_ptr);
}
